#ifndef __CPPVIS_CXX__
#define __CPPVIS_CXX__

#include "CppVIS.h"

namespace vis {

  TMatrixD FullCovarianceMatrix(const std::vector<double>& bkgin,
				const TMatrixD& matrix_fractional_covariance,
				const int num_bins_total,
				bool stat_only) {
    
    //And then define the total covariance matrix in all its glory
    TMatrixT <double> Mtotal(num_bins_total,num_bins_total);
    TMatrixT <double> Mnull(num_bins_total,num_bins_total);
    Mtotal.Zero();
    Mnull.Zero();

    bool is_fractional = true;

    //Reset matrix_systematics to fractional
    auto matrix_systematics = matrix_fractional_covariance;

    if(matrix_systematics.GetNcols() != num_bins_total) {
      return Mnull;
    }
    
    // systematics per scaled event
    for(int i =0; i<matrix_systematics.GetNcols(); i++)
      {
	for(int j =0; j<matrix_systematics.GetNrows(); j++)
	  {
	    if(is_fractional){
	      if(std::isnan(matrix_systematics(i,j)))
		matrix_systematics(i,j) = 0;
	      else
		matrix_systematics(i,j)=matrix_systematics(i,j) * bkgin.at(i) * bkgin.at(j);
	    }
	  }
      }

    // Fill stats from the back ground vector
    TMatrixT <double> Mstat(num_bins_total, num_bins_total);
    Mstat.Zero();
    int matrix_size = Mstat.GetNrows();
    for(int i=0; i<matrix_size; i++)
      Mstat(i,i) = bkgin.at(i);
    
    if(!Mstat.IsSymmetric()){
      return Mnull;
    }

    if(stat_only){
      Mtotal = Mstat;
    }else{
      Mtotal = Mstat + matrix_systematics;
    }

    if( !Mtotal.IsSymmetric()) {
      
      double tol = 1e-13;
      double biggest_deviation = 0;
      int bi = 0;
      int bj = 0;

      for(int i=0; i<Mtotal.GetNrows(); i++){
	for(int j=0; j<Mtotal.GetNcols(); j++){
	  double dev = fabs(Mtotal(i,j)-Mtotal(j,i));
	  if(dev>biggest_deviation){
	    biggest_deviation = 2*dev/(fabs(Mtotal(i,j))+fabs(Mtotal(j,i)));
	    bi = i;
	    bj = j;
	  }
	}
      }


      if(biggest_deviation >tol){
	return Mnull;
      }
    }

    return Mtotal;
  }

  std::vector<double> CollapseVector(const std::vector<double>& full_vector,
				     const int num_modes,
				     const int num_detectors,
				     const int num_bins_detector_block,
				     const int num_bins_mode_block,
				     const int num_channels,
				     const std::vector<int>& num_subchannels,
				     const std::vector<int>& num_bins) {					      
    std::vector<double> collapsed_vector;

    for(int im = 0; im < num_modes; im++){
      for(int id =0; id < num_detectors; id++){
	int edge = id*num_bins_detector_block + num_bins_mode_block*im; // This is the starting index for this detector

	for(int ic = 0; ic < num_channels; ic++){
	  int corner=edge;

	  for(int j=0; j< num_bins.at(ic); j++){

	    double tempval=0;

	    for(int sc = 0; sc < num_subchannels.at(ic); sc++){

	      //std::cout<<im<<"/"<<num_modes<<" "<<id<<"/"<<num_detectors<<" "<<ic<<"/"<<num_channels<<" "<<j<<"/"<<num_bins[ic]<<" "<<sc<<"/"<<num_subchannels[ic]<<std::endl;
	      tempval += full_vector.at(j+sc*num_bins.at(ic)+corner);
	      edge +=1;	//when your done with a channel, add on every bin you just summed
	    }
	    //we can size this vector beforehand and get rid of all push_back()
	    collapsed_vector.push_back(tempval);
	  }
	}
      }
    }
    return collapsed_vector;
  }


  TMatrixD ReplaceNan(const TMatrixT<double>& M) {
    TMatrixD ret(M.GetNrows(),M.GetNcols());
    ret.Zero();
    
    for(int row=0; row<M.GetNrows(); ++row) {
      for(int col=0; col<M.GetNcols(); ++col) {
	auto val = M[row][col];
	if (std::isinf(val)) continue;
	if (val != val) continue;
	ret[row][col] = val;
      }
    }
    
    return ret;
  }



  /**************************************************************************
   *			Collapsing code
   * ************************************************************************/


  //This is the powerhouse, takes each detector matrix filled with num_channels channels of num_subchannels[i] subchannels, and collapses it.
  void CollapseSubchannels(const TMatrixT <double> & M,
			   TMatrixT <double> & Mc,
			   const int num_channels,
			   const std::vector<int>& num_subchannels,
			   const std::vector<int>& num_bins) {

    std::vector<std::vector<TMatrixT<double>>> Summed(num_channels, std::vector<TMatrixT<double>>(num_channels) );	//Initialise a matrix of matricies, to ZERO.
    for(int ic = 0; ic < num_channels; ic++){
      for(int jc =0; jc < num_channels; jc++){
	Summed[ic][jc].ResizeTo(num_bins[jc],num_bins[ic]) ;// This is CORRECT, do not switch (ie Summed[0][1] = size (num_bins[1], num_bins[0])
	Summed[ic][jc] = 0.0;
      }
    }

    int mrow = 0.0;
    int mcol = 0.0;

    for(int ic = 0; ic < num_channels; ic++){ 	 //Loop over all rows
      for(int jc =0; jc < num_channels; jc++){ //Loop over all columns

	for(int m=0; m < num_subchannels[ic]; m++){
	  for(int n=0; n< num_subchannels[jc]; n++){ //For each big block, loop over all subchannels summing toGether
	    Summed[ic][jc] +=  M.GetSub(mrow+n*num_bins[jc] ,mrow + n*num_bins[jc]+num_bins[jc]-1, mcol + m*num_bins[ic], mcol+ m*num_bins[ic]+num_bins[ic]-1 );
	  }
	}


	mrow += num_subchannels[jc]*num_bins[jc];//As we work our way left in columns, add on that many bins
      }//end of column loop

      mrow = 0; // as we end this row, reSet row count, but jump down 1 column
      mcol += num_subchannels[ic]*num_bins[ic];
    }//end of row loop

    ///********************************* And put them back toGether! ************************//
    Mc.Zero();
    mrow = 0;
    mcol = 0;

    //Repeat again for Contracted matrix
    for(int ic = 0; ic < num_channels; ic++){
      for(int jc =0; jc < num_channels; jc++){
	Mc.SetSub(mrow,mcol,Summed[ic][jc]);
	mrow += num_bins[jc];
      }

      mrow = 0;
      mcol +=num_bins[ic];
    }

    return;
  }



  //This is the detector layer, Take a given mode and run over each detector V detector sub matrix
  void CollapseDetectors(const TMatrixT <double> & M, 
			 TMatrixT <double> & Mc,
			 const int num_detectors,			 
			 const int num_bins_detector_block,
			 const int num_bins_detector_block_compressed,
			 const int num_channels,
			 const std::vector<int>& num_subchannels,
			 const std::vector<int>& num_bins){

    Mc.Zero();
    int nrow = num_bins_detector_block;// N_e_bins*N_e_spectra+N_m_bins*N_m_spectra;
    int crow = num_bins_detector_block_compressed; //N_e_bins+N_m_bins;

    for(int m =0; m< num_detectors; m++){
      for(int n =0; n< num_detectors; n++){
	TMatrixT<double> imat(nrow,nrow);
	TMatrixT<double> imatc(crow,crow);

	imat = M.GetSub(n*nrow, n*nrow+nrow-1, m*nrow, m*nrow+nrow-1);
	CollapseSubchannels(imat,
			    imatc,
			    num_channels,
			    num_subchannels,
			    num_bins);

	Mc.SetSub(n*crow,m*crow,imatc);
      }
    }

    return;
  }

  //This is the Mode layer, Take a given full matrix and runs over each Mode V Mode sub matrix
  TMatrixT<double> CollapseModes(const TMatrixT <double> & M,
				 const int target_num_bins,
				 const int num_modes,
				 const int num_bins_mode_block,
				 const int num_bins_mode_block_compressed,
				 const int num_detectors,
				 const int num_bins_detector_block,
				 const int num_bins_detector_block_compressed,
				 const int num_channels,
				 const std::vector<int>& num_subchannels,
				 const std::vector<int>& num_bins){
    
    TMatrixT<double> Mc(target_num_bins,target_num_bins);
    Mc.Zero();

    int nrow = num_bins_mode_block;// (N_e_bins*N_e_spectra+N_m_bins*N_m_spectra)*N_dets;
    int crow=  num_bins_mode_block_compressed;// (N_e_bins+N_m_bins)*N_dets;

    for(int m =0; m< num_modes ; m++){
      for(int n =0; n< num_modes; n++){

	TMatrixT<double> imat(nrow,nrow);
	TMatrixT<double> imatc(crow,crow);

	imat = M.GetSub(n*nrow, n*nrow+nrow-1, m*nrow, m*nrow+nrow-1);

	CollapseDetectors(imat,
			  imatc,
			  num_detectors,
			  num_bins_detector_block,
			  num_bins_detector_block_compressed,
			  num_channels,
			  num_subchannels,
			  num_bins);

	Mc.SetSub(n*crow,m*crow,imatc);

      }
    }

    return Mc;
  }



}

#endif
