#include <iostream>

#include <vector>
#include <map>

#include "TFile.h"
#include "TTree.h"
#include "TChain.h"

#include <sstream>
#include <cassert>
#include <iterator>

int main(int argc, const char** argv) {

  assert(argc == 3);

  std::string infile   = argv[1];
  std::string outfile  = argv[2];

  std::string key = "events";
  
  TChain *tc = new TChain(key.c_str());
  tc->Add(infile.c_str());
  
  int id;
  int pdg;
  double ereco;
  std::map<std::string, std::vector<double> >* weights = 0;
  
  tc->SetBranchAddress("id"     , &id);
  tc->SetBranchAddress("pdg"    , &pdg);
  tc->SetBranchAddress("ereco"  , &ereco);
  tc->SetBranchAddress("weights", &weights);

  tc->GetEntry(0);

  auto tfo = TFile::Open(outfile.c_str(),"RECREATE");
  tfo->cd();
  TTree* otree = new TTree("events","");
  otree->Branch("id"    , &id   , "id/I");
  otree->Branch("pdg"   , &pdg  , "pdg/I");
  otree->Branch("ereco" , &ereco, "ereco/D");

  std::stringstream ss;
  std::vector<std::vector<double> > data_v(weights->size());
  std::map<std::string, std::vector<double>>::iterator iter = weights->begin();
  for(; iter != weights->end(); ++iter) { 
    auto idx = std::distance(weights->begin(),iter);
    data_v[idx] = (*iter).second;

    // store vector
    otree->Branch((*iter).first.c_str(),&data_v[idx]);

    // store double arrays
    // ss.str("");
    // ss << (*iter).first.c_str() << "[" << data_v[idx].size() << "]/D";
    // otree->Branch((*iter).first.c_str(),data_v[idx].data(),ss.str().c_str());
  }
  
  for(size_t entry=0; entry < (size_t)tc->GetEntries(); ++entry) {
    if ((int)entry%(int)1e3==0) std::cout << "@entry=" << entry << std::endl;
    tc->GetEntry(entry);
    iter = weights->begin();
    for(size_t ix=0; ix<data_v.size(); ++ix) {
      data_v[ix] = (*iter).second;
      iter++;
    }
    otree->Fill();
  }
  
  otree->Write();
  
  tfo->Close();

  return 0;
}
