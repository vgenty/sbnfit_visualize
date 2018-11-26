#ifndef __CPPVIS_H__
#define __CPPVIS_H__

#include <vector>
#include "TMatrixD.h"

namespace vis {
  
  TMatrixD FullCovarianceMatrix(const std::vector<double>& bkgin,
				const TMatrixD& matrix_fractional_covariance,
				const int num_bins_total,
				bool stat_only);
  
  std::vector<double> CollapseVector(const std::vector<double>& full_vector);
  
  TMatrixD ReplaceNan(const TMatrixT<double>& M);
  
  void CollapseSubchannels(const TMatrixT <double> & M,
			   TMatrixT <double> & Mc,
			   const int num_channels,
			   const std::vector<int>& num_subchannels,
			   const std::vector<int>& num_bins);


  void CollapseDetectors(const TMatrixT <double> & M, 
			 TMatrixT <double> & Mc,
			 const int num_detectors,
			 const int num_bins_detector_block,
			 const int num_bins_detector_block_compressed,
			 const int num_channels,
			 const std::vector<int>& num_subchannels,
			 const std::vector<int>& num_bins);


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
				 const std::vector<int>& num_bins);
  

}

#endif
