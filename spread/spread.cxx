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

  assert(argc == 4);

  std::string treename = argv[1];
  std::string infile   = argv[2];
  std::string outfile  = argv[3];

  TChain *tc = new TChain(treename.c_str());
  tc->Add(infile.c_str());
  
  int run;
  int subrun;
  int event;
  double reco_energy;
  double true_nu_energy;
  double true_nu_L;
  std::map<std::string, std::vector<double> >* weights = 0;
  
  tc->SetBranchAddress("run"   , &run);
  tc->SetBranchAddress("subrun", &subrun);
  tc->SetBranchAddress("event" , &event);

  tc->SetBranchAddress("reco_energy"   , &reco_energy);
  tc->SetBranchAddress("true_nu_energy", &true_nu_energy);
  tc->SetBranchAddress("true_nu_L"     , &true_nu_L);

  tc->SetBranchAddress("weights", &weights);

  tc->GetEntry(0);

  auto tfo = TFile::Open(outfile.c_str(),"RECREATE");
  tfo->cd();
  TTree* otree = new TTree(treename.c_str(),"");
  otree->Branch("run"   , &run   , "run/I");
  otree->Branch("subrun", &subrun, "subrun/I");
  otree->Branch("event" , &event , "event/I");

  otree->Branch("reco_energy"   , &reco_energy   , "reco_energy/D");
  otree->Branch("true_nu_energy", &true_nu_energy, "true_nu_energy/D");
  otree->Branch("true_nu_L"     , &true_nu_L     , "true_nu_L/D");

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
