#ifndef _METHELPER_H_
#define _METHELPER_H_

#include "ScanChain.h"

class MetHelper
{
  public:
    MetHelper(TString name_, int nHists_, string jec_version_data_, string jec_version_mc_, int type_, bool corr_ = false);
    //~MetHelper();

    void create_histograms();
    void create_raw_met_histograms();
    //void fill_met_histograms(TString currentFileName, bool isElEvt, int id1, int id2, int nJets, vector<double> weights);
    void fill_met_histograms(TString currentFileName, bool isElEvt, int id1, int id2, int nJets, vector<double> weights, vector<double> vId, vector<double> weights_up, vector<double> weights_down);
    void fill_raw_met_histograms(bool isElEvt, int id1, int id2, int nJets, vector<double> weights);

    double get_t1met() { return t1met; }
  private:
    bool mCorr; // whether to use raw or corrected pT as threshold for noisy EE jets
    TString name;
    int nHists;
    int histIdx;
    string jec_version_data;
    string jec_version_mc;
    int type;

    double t1met; // store most recently calculated t1met

    const vector<double> resolution_bins = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 220, 240, 260, 280, 300, 325, 350, 375, 400, 450, 500};
    const int nBins = 80;
    const double x_low = 0;
    const double x_high = 400;

    vector<TH1D*> hT1CMET;
    vector<TH1D*> hT1CMET_up;
    vector<TH1D*> hT1CMET_down;
    vector<TH1D*> hT1CMET_pu_up;
    vector<TH1D*> hT1CMET_pu_down;

    vector<TH1D*> hT1CMET_EE;
    vector<TH1D*> hT1CMET_EE_up;
    vector<TH1D*> hT1CMET_EE_down;

    vector<TH1D*> hT1CMET_MM;
    vector<TH1D*> hT1CMET_MM_up;
    vector<TH1D*> hT1CMET_MM_down;

    vector<TH1D*> hT1CMET_0Jets;
    vector<TH1D*> hT1CMET_0Jets_up;
    vector<TH1D*> hT1CMET_0Jets_down;

    vector<TH1D*> hT1CMET_1pJets;
    vector<TH1D*> hT1CMET_1pJets_up;
    vector<TH1D*> hT1CMET_1pJets_down;

    vector<TH1D*> hJetEta_30GeV;
    vector<TH1D*> hJetEta_50GeV;
    vector<TH1D*> hJetEta_100GeV;
    vector<TH1D*> hLeadJetPt;
    vector<TH1D*> hJetPt; 
    vector<TH1D*> hJetPt_Barrel;
    vector<TH1D*> hJetPt_EC;
    vector<TH1D*> hJetPt_Forward;

    vector<TH1D*> hJetMultiplicity;
    vector<TH2D*> hJetEtaPhi;
    vector<TH2D*> hJetEtaPhi_1Jet_qTGeq200;
    vector<TH2D*> hJetEtaPhi_1HighPtJet_qTGeq200;


    vector<TH1D*> hZMassEE;
    vector<TH1D*> hZMassMuMu;
    vector<TH1D*> hZMassEE_high_qT;
    vector<TH1D*> hZMassMuMu_high_qT;
    vector<TH1D*> hZpT;
    vector<TH1D*> hT1CMET_UPara;
    vector<TH1D*> hT1CMET_UPerp;
    vector<TH1D*> hT1CMET_UParaPlusqT;
    vector<TH1D*> hT1CMET_UPara_over_high_qT;

    vector<vector<TH1D*>> hResPara;
    vector<vector<TH1D*>> hResPerp;
    vector<vector<TH1D*>> hResponse;
    vector<vector<TH1D*>> hResponseEE;
    vector<vector<TH1D*>> hResponseMM;

    vector<vector<TH1D*>> hResponseVeryLowPU;
    vector<vector<TH1D*>> hResponseLowPU;
    vector<vector<TH1D*>> hResponseMedPU;
    vector<vector<TH1D*>> hResponseHighPU;

    vector<vector<TH1D*>> hResponseLeadJetLowEta;
    vector<vector<TH1D*>> hResponseLeadJetMedEta;
    vector<vector<TH1D*>> hResponseLeadJetHighEta;

    vector<vector<TH1D*>> hResponseLeadJetLowEta_30GeVJet;
    vector<vector<TH1D*>> hResponseLeadJetMedEta_30GeVJet;
    vector<vector<TH1D*>> hResponseLeadJetHighEta_30GeVJet;

    vector<vector<TH1D*>> hResponseLeadJetLowEta_100GeVJet;
    vector<vector<TH1D*>> hResponseLeadJetMedEta_100GeVJet;
    vector<vector<TH1D*>> hResponseLeadJetHighEta_100GeVJet;

    vector<vector<TH1D*>> hResUpPara;
    vector<vector<TH1D*>> hResUpPerp;
    vector<vector<TH1D*>> hResponseUp;
    vector<vector<TH1D*>> hResponseUpEE;
    vector<vector<TH1D*>> hResponseUpMM;

    vector<vector<TH1D*>> hResponseUpLowPU;
    vector<vector<TH1D*>> hResponseUpMedPU;
    vector<vector<TH1D*>> hResponseUpHighPU;

    vector<vector<TH1D*>> hResponseUpLeadJetLowEta;
    vector<vector<TH1D*>> hResponseUpLeadJetMedEta;
    vector<vector<TH1D*>> hResponseUpLeadJetHighEta;

    vector<vector<TH1D*>> hResDownPara;
    vector<vector<TH1D*>> hResDownPerp;
    vector<vector<TH1D*>> hResponseDown;
    vector<vector<TH1D*>> hResponseDownEE;
    vector<vector<TH1D*>> hResponseDownMM;

    vector<vector<TH1D*>> hResponseDownLowPU;
    vector<vector<TH1D*>> hResponseDownMedPU;
    vector<vector<TH1D*>> hResponseDownHighPU;

    vector<vector<TH1D*>> hResponseDownLeadJetLowEta;
    vector<vector<TH1D*>> hResponseDownLeadJetMedEta;
    vector<vector<TH1D*>> hResponseDownLeadJetHighEta;
    

    vector<TH1D*> hRawMET;
    vector<TH1D*> hRawMET_0Jets;
    vector<TH1D*> hRawMET_1pJets;

    vector<TH1D*> hRawJetPt;
    
    vector<TH1D*> hRawZpT;
    vector<TH1D*> hRaw_UPara;
    vector<TH1D*> hRaw_UPerp;
    vector<TH1D*> hRaw_UParaPlusqT;

    vector<vector<TH1D*>> hRawResPara;
    vector<vector<TH1D*>> hRawResPerp;
    vector<vector<TH1D*>> hRawResponse;
    vector<vector<TH1D*>> hRawResponseEE;
    vector<vector<TH1D*>> hRawResponseMM;
};

inline
MetHelper::MetHelper(TString name_, int nHists_, string jec_version_data_, string jec_version_mc_, int type_, bool corr_){
  name = name_;
  nHists = nHists_;
  jec_version_data = jec_version_data_;
  jec_version_mc = jec_version_mc_;
  type = type_;
  mCorr = corr_;
  t1met = -1;

  create_histograms();
}

inline
void MetHelper::create_histograms() {
  hT1CMET = create_histogram_vector("hT1CMET" + name, nBins, x_low, x_high, nHists);
  hT1CMET_up = create_histogram_vector("hT1CMET_up" + name, nBins, x_low, x_high, nHists);
  hT1CMET_down = create_histogram_vector("hT1CMET_down" + name, nBins, x_low, x_high, nHists);

  hT1CMET_pu_up = create_histogram_vector("hT1CMET_pu_up" + name, nBins, x_low, x_high, nHists);
  hT1CMET_pu_down = create_histogram_vector("hT1CMET_pu_down" + name, nBins, x_low, x_high, nHists);

  hT1CMET_0Jets = create_histogram_vector("hT1CMET_0Jets" + name, nBins, x_low, x_high, nHists);
  hT1CMET_0Jets_up = create_histogram_vector("hT1CMET_0Jets_up" + name, nBins, x_low, x_high, nHists);
  hT1CMET_0Jets_down = create_histogram_vector("hT1CMET_0Jets_down" + name, nBins, x_low, x_high, nHists);

  hT1CMET_1pJets = create_histogram_vector("hT1CMET_1pJets" + name, nBins, x_low, x_high, nHists);
  hT1CMET_1pJets_up = create_histogram_vector("hT1CMET_1pJets_up" + name, nBins, x_low, x_high, nHists);
  hT1CMET_1pJets_down = create_histogram_vector("hT1CMET_1pJets_down" + name, nBins, x_low, x_high, nHists);

  hT1CMET_EE = create_histogram_vector("hT1CMET_EE" + name, nBins, x_low, x_high, nHists);
  hT1CMET_EE_up = create_histogram_vector("hT1CMET_EE_up" + name, nBins, x_low, x_high, nHists);
  hT1CMET_EE_down = create_histogram_vector("hT1CMET_EE_down" + name, nBins, x_low, x_high, nHists);

  hT1CMET_MM = create_histogram_vector("hT1CMET_MM" + name, nBins, x_low, x_high, nHists);
  hT1CMET_MM_up = create_histogram_vector("hT1CMET_MM_up" + name, nBins, x_low, x_high, nHists);
  hT1CMET_MM_down = create_histogram_vector("hT1CMET_MM_down" + name, nBins, x_low, x_high, nHists);

  hJetEta_30GeV = create_histogram_vector("hJetEta_30GeV" + name, nBins, 0, 5, nHists);
  hJetEta_50GeV = create_histogram_vector("hJetEta_50GeV" + name, nBins, 0, 5, nHists);
  hJetEta_100GeV = create_histogram_vector("hJetEta_100GeV" + name, nBins, 0, 5, nHists);
  hLeadJetPt = create_histogram_vector("hLeadJetPt" + name, nBins, x_low, x_high, nHists);
  hJetPt = create_histogram_vector("hJetPt" + name, nBins, x_low, x_high, nHists);
  hJetPt_Barrel = create_histogram_vector("hJetPt_Barrel" + name, nBins, x_low, x_high, nHists);
  hJetPt_EC = create_histogram_vector("hJetPt_EC" + name, nBins, x_low, x_high, nHists);
  hJetPt_Forward = create_histogram_vector("hJetPt_Forward" + name, nBins, x_low, x_high, nHists);

  hJetMultiplicity = create_histogram_vector("hJetMultiplicity" + name, 11, -0.5, 10.5, nHists);
  hJetEtaPhi = create_2Dhistogram_vector("hJetEtaPhi" + name, 50, -5, 5, 50, -3.142, 3.142, nHists); 
  hJetEtaPhi_1Jet_qTGeq200 = create_2Dhistogram_vector("hJetEtaPhi_1Jet_qTGeq200" + name, 50, -5, 5, 50, -3.142, 3.142, nHists);
  hJetEtaPhi_1HighPtJet_qTGeq200 = create_2Dhistogram_vector("hJetEtaPhi_1HighPtJet_qTGeq200" + name, 50, -5, 5, 50, -3.142, 3.142, nHists);

  hZMassEE = create_histogram_vector("hZMassEE" + name, 100, 0, 200, nHists);
  hZMassMuMu = create_histogram_vector("hZMassMuMu" + name, 100, 0, 200, nHists);
  hZMassEE_high_qT = create_histogram_vector("hZMassEE_high_qT" + name, 100, 0, 200, nHists);
  hZMassMuMu_high_qT = create_histogram_vector("hZMassMuMu_high_qT" + name, 100, 0, 200, nHists);
  hZpT = create_histogram_vector("hZpT" + name, 100, 0, 400, nHists);
  hT1CMET_UPara = create_histogram_vector("hT1CMET_UPara" + name, 200, -400, 400, nHists);
  hT1CMET_UPerp = create_histogram_vector("hT1CMET_UPerp" + name, 100, -200, 200, nHists);
  hT1CMET_UParaPlusqT = create_histogram_vector("hT1CMET_UParaPlusqT" + name, 100, -200, 200, nHists);
  hT1CMET_UPara_over_high_qT = create_histogram_vector("hT1CMET_UPara_over_high_qT" + name, 100, -10, 10, nHists);

  for (int i = 0; i < resolution_bins.size(); i++) {
    hResponse.push_back(create_histogram_vector("hT1CMET_Response" + name + to_string(i), 100, -10, 10, nHists));
    hResponseEE.push_back(create_histogram_vector("hT1CMET_ResponseEE" + name + to_string(i), 100, -10, 10, nHists));
    hResponseMM.push_back(create_histogram_vector("hT1CMET_ResponseMM" + name + to_string(i), 100, -10, 10, nHists));
    hResponseVeryLowPU.push_back(create_histogram_vector("hT1CMET_ResponseVeryLowPU" + name + to_string(i), 100, -10, 10, nHists));
    hResponseLowPU.push_back(create_histogram_vector("hT1CMET_ResponseLowPU" + name + to_string(i), 100, -10, 10, nHists));
    hResponseMedPU.push_back(create_histogram_vector("hT1CMET_ResponseMedPU" + name + to_string(i), 100, -10, 10, nHists));
    hResponseHighPU.push_back(create_histogram_vector("hT1CMET_ResponseHighPU" + name + to_string(i), 100, -10, 10, nHists));
    hResponseLeadJetLowEta.push_back(create_histogram_vector("hT1CMET_ResponseLeadJetLowEta" + name + to_string(i), 100, -10, 10, nHists));
    hResponseLeadJetMedEta.push_back(create_histogram_vector("hT1CMET_ResponseLeadJetMedEta" + name + to_string(i), 100, -10, 10, nHists));
    hResponseLeadJetHighEta.push_back(create_histogram_vector("hT1CMET_ResponseLeadJetHighEta" + name + to_string(i), 100, -10, 10, nHists));

    hResponseLeadJetLowEta_30GeVJet.push_back(create_histogram_vector("hT1CMET_ResponseLeadJetLowEta_30GeVJet" + name + to_string(i), 100, -10, 10, nHists));
    hResponseLeadJetMedEta_30GeVJet.push_back(create_histogram_vector("hT1CMET_ResponseLeadJetMedEta_30GeVJet" + name + to_string(i), 100, -10, 10, nHists));
    hResponseLeadJetHighEta_30GeVJet.push_back(create_histogram_vector("hT1CMET_ResponseLeadJetHighEta_30GeVJet" + name + to_string(i), 100, -10, 10, nHists));
    hResponseLeadJetLowEta_100GeVJet.push_back(create_histogram_vector("hT1CMET_ResponseLeadJetLowEta_100GeVJet" + name + to_string(i), 100, -10, 10, nHists));
    hResponseLeadJetMedEta_100GeVJet.push_back(create_histogram_vector("hT1CMET_ResponseLeadJetMedEta_100GeVJet" + name + to_string(i), 100, -10, 10, nHists));
    hResponseLeadJetHighEta_100GeVJet.push_back(create_histogram_vector("hT1CMET_ResponseLeadJetHighEta_100GeVJet" + name + to_string(i), 100, -10, 10, nHists));


    hResPara.push_back(create_histogram_vector("hT1CMET_ResPara" + name + to_string(i), 200, -400, 400, nHists));
    hResPerp.push_back(create_histogram_vector("hT1CMET_ResPerp" + name + to_string(i), 100, -200, 200, nHists));

    hResponseUp.push_back(create_histogram_vector("hT1CMET_ResponseUp" + name + to_string(i), 100, -10, 10, nHists));
    hResponseUpEE.push_back(create_histogram_vector("hT1CMET_ResponseUpEE" + name + to_string(i), 100, -10, 10, nHists));
    hResponseUpMM.push_back(create_histogram_vector("hT1CMET_ResponseUpMM" + name + to_string(i), 100, -10, 10, nHists));
    hResponseUpLowPU.push_back(create_histogram_vector("hT1CMET_ResponseUpLowPU" + name + to_string(i), 100, -10, 10, nHists));
    hResponseUpMedPU.push_back(create_histogram_vector("hT1CMET_ResponseUpMedPU" + name + to_string(i), 100, -10, 10, nHists));
    hResponseUpHighPU.push_back(create_histogram_vector("hT1CMET_ResponseUpHighPU" + name + to_string(i), 100, -10, 10, nHists));
    hResponseUpLeadJetLowEta.push_back(create_histogram_vector("hT1CMET_ResponseUpLeadJetLowEta" + name + to_string(i), 100, -10, 10, nHists));
    hResponseUpLeadJetMedEta.push_back(create_histogram_vector("hT1CMET_ResponseUpLeadJetMedEta" + name + to_string(i), 100, -10, 10, nHists));
    hResponseUpLeadJetHighEta.push_back(create_histogram_vector("hT1CMET_ResponseUpLeadJetHighEta" + name + to_string(i), 100, -10, 10, nHists));
    hResUpPara.push_back(create_histogram_vector("hT1CMET_ResUpPara" + name + to_string(i), 200, -400, 400, nHists));
    hResUpPerp.push_back(create_histogram_vector("hT1CMET_ResUpPerp" + name + to_string(i), 100, -200, 200, nHists));

    hResponseDown.push_back(create_histogram_vector("hT1CMET_ResponseDown" + name + to_string(i), 100, -10, 10, nHists));
    hResponseDownEE.push_back(create_histogram_vector("hT1CMET_ResponseDownEE" + name + to_string(i), 100, -10, 10, nHists));
    hResponseDownMM.push_back(create_histogram_vector("hT1CMET_ResponseDownMM" + name + to_string(i), 100, -10, 10, nHists));
    hResponseDownLowPU.push_back(create_histogram_vector("hT1CMET_ResponseDownLowPU" + name + to_string(i), 100, -10, 10, nHists));
    hResponseDownMedPU.push_back(create_histogram_vector("hT1CMET_ResponseDownMedPU" + name + to_string(i), 100, -10, 10, nHists));
    hResponseDownHighPU.push_back(create_histogram_vector("hT1CMET_ResponseDownHighPU" + name + to_string(i), 100, -10, 10, nHists));
    hResponseDownLeadJetLowEta.push_back(create_histogram_vector("hT1CMET_ResponseDownLeadJetLowEta" + name + to_string(i), 100, -10, 10, nHists));
    hResponseDownLeadJetMedEta.push_back(create_histogram_vector("hT1CMET_ResponseDownLeadJetMedEta" + name + to_string(i), 100, -10, 10, nHists));
    hResponseDownLeadJetHighEta.push_back(create_histogram_vector("hT1CMET_ResponseDownLeadJetHighEta" + name + to_string(i), 100, -10, 10, nHists));
    hResDownPara.push_back(create_histogram_vector("hT1CMET_ResDownPara" + name + to_string(i), 200, -400, 400, nHists));
    hResDownPerp.push_back(create_histogram_vector("hT1CMET_ResDownPerp" + name + to_string(i), 100, -200, 200, nHists));
  
  }   
}

inline
void MetHelper::create_raw_met_histograms() {
  hRawMET = create_histogram_vector("hRawMET", nBins, x_low, x_high, nHists);
  hRawMET_0Jets = create_histogram_vector("hRawMET_0Jets", nBins, x_low, x_high, nHists);
  hRawMET_1pJets = create_histogram_vector("hRawMET_1pJets", nBins, x_low, x_high, nHists);

  hRawJetPt = create_histogram_vector("hRawJetPt", nBins, x_low, x_high, nHists);
  
  hRawZpT = create_histogram_vector("hRawZpT", 100, 0, 400, nHists);
  hRaw_UPara = create_histogram_vector("hRaw_UPara", 200, -400, 400, nHists);
  hRaw_UPerp = create_histogram_vector("hRaw_UPerp", 100, -200, 200, nHists);
  hRaw_UParaPlusqT = create_histogram_vector("hRaw_UParaPlusqT", 100, -200, 200, nHists);

  for (int i = 0; i < resolution_bins.size(); i++) {
    hRawResponse.push_back(create_histogram_vector("hRaw_Response" + to_string(i), 100, -10, 10, nHists));
    hRawResponseEE.push_back(create_histogram_vector("hRaw_ResponseEE" + to_string(i), 100, -10, 10, nHists));
    hRawResponseMM.push_back(create_histogram_vector("hRaw_ResponseMM" + to_string(i), 100, -10, 10, nHists));
    hRawResPara.push_back(create_histogram_vector("hRaw_ResPara" + to_string(i), 200, -400, 400, nHists));
    hRawResPerp.push_back(create_histogram_vector("hRaw_ResPerp" + to_string(i), 100, -200, 200, nHists));
  }
}

inline
void MetHelper::fill_raw_met_histograms(bool isElEvt, int id1, int id2, int nJets, vector<double> weights) {
  double metX = cms3.evt_pfmet_raw() * cos(cms3.evt_pfmetPhi_raw());
  double metY = cms3.evt_pfmet_raw() * sin(cms3.evt_pfmetPhi_raw());
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fRawMET(metX, metY, 0, cms3.evt_pfmet_raw());

  for(unsigned int iJet = 0; iJet < cms3.pfjets_p4().size(); iJet++){
     LorentzVector jetp4_uncorr = cms3.pfjets_p4().at(iJet)*cms3.pfjets_undoJEC().at(iJet);
     fill_histograms(hRawJetPt, jetp4_uncorr.pt(), weights);
  }

  fill_histograms(hRawMET, fRawMET.pt(), weights);
  if (nJets == 0)
    fill_histograms(hRawMET_0Jets, fRawMET.pt(), weights);
  else
    fill_histograms(hRawMET_1pJets, fRawMET.pt(), weights);

  double boson_pt, u_para, u_perp, u_para_plus_qt;
  boson_pt = boson_pT(isElEvt, id1, id2, fRawMET, u_para, u_perp, u_para_plus_qt);

  int resolution_idx = find_index(resolution_bins, boson_pt);
  fill_histograms(hZpT, boson_pt, weights);
  fill_histograms(hRaw_UPara, u_para, weights);
  fill_histograms(hRaw_UPerp, u_perp, weights);
  fill_histograms(hRaw_UParaPlusqT, u_para_plus_qt, weights);

  fill_histograms(hRawResponse[resolution_idx], -u_para/boson_pt, weights);
  if (isElEvt)      fill_histograms(hRawResponseEE[resolution_idx], -u_para/boson_pt, weights);
  else              fill_histograms(hRawResponseMM[resolution_idx], -u_para/boson_pt, weights);
  fill_histograms(hRawResPara[resolution_idx], u_para, weights);
  fill_histograms(hRawResPerp[resolution_idx], u_perp, weights);
}

inline
void MetHelper::fill_met_histograms(TString currentFileName, bool isElEvt, int id1, int id2, int nJets, vector<double> weights, vector<double> vId, vector<double> weights_up = {}, vector<double> weights_down = {}) {
  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET, fT1CMET_up, fT1CMET_down;

  double pt_jec_thresh(15), pt_thresh(15);
  vector<double> eta_exclusion_range = {0, 0};
  bool exclude_jets = false;
  if (type == 0) {

  }// standard, do nothing
  else if (type == 1) { // modified
    pt_jec_thresh = 75;
    pt_thresh = 75;
    eta_exclusion_range = {2.65, 3.139};
  }
  else if (type == 2) { // modified C 
    pt_jec_thresh = 75;
    pt_thresh = 75;
    eta_exclusion_range = {2.65, 3.139};
    exclude_jets = true;
  }
  else if (type == 3) { // modified D
    pt_thresh = 99999999999;
    eta_exclusion_range = {2.65, 3.139};
    exclude_jets = true;
  }

  else if (type == 5) { // modified C with pT thresh of 50
    pt_thresh = 50.;
    pt_jec_thresh = 50.;
    eta_exclusion_range = {2.65, 3.139};
    exclude_jets = true;
  }

  vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>>> vCorrectedJets = correctedJets(currentFileName, jec_version_data, jec_version_mc); 
  fill_histograms(hLeadJetPt, vCorrectedJets.size() > 0 ? vCorrectedJets[0].pt() : -999, weights); 
  int n_jets = 0;
  int n_high_pt_jets = 0;

  LorentzVector pl1, pl2;
  if (isElEvt) {
    pl1 = els_p4().at(id1);
    pl2 = els_p4().at(id2);
  }
  else {
    pl1 = mus_p4().at(id1);
    pl2 = mus_p4().at(id2);
  }

  for (unsigned int i = 0; i < vCorrectedJets.size(); i++) {
    if (DeltaR(pfjets_p4().at(i),pl1) < 0.4)            { continue; }
    if (DeltaR(pfjets_p4().at(i),pl2) < 0.4)            { continue; }    
    fill_histograms(hJetPt, vCorrectedJets[i].pt(), weights);
    if (abs(vCorrectedJets[i].eta()) < 1.6)
      fill_histograms(hJetPt_Barrel, vCorrectedJets[i].pt(), weights);
    else if (abs(vCorrectedJets[i].eta()) < 3.0)
      fill_histograms(hJetPt_EC, vCorrectedJets[i].pt(), weights);
    else 
      fill_histograms(hJetPt_Forward, vCorrectedJets[i].pt(), weights);

    if (vCorrectedJets[i].pt() > 30) {
      fill_histograms2D(hJetEtaPhi, vCorrectedJets[i].eta(), vCorrectedJets[i].phi(), weights);
      fill_histograms(hJetEta_30GeV, abs(vCorrectedJets[i].eta()), weights);
      n_jets++;
    }
    if (vCorrectedJets[i].pt() > 50) {
      fill_histograms(hJetEta_50GeV, abs(vCorrectedJets[i].eta()), weights);
    }
    if (vCorrectedJets[i].pt() > 100) {
      fill_histograms(hJetEta_100GeV, abs(vCorrectedJets[i].eta()), weights);
      n_high_pt_jets++;
    }
  }
  fill_histograms(hJetMultiplicity, n_jets, weights);
  
  if (type != 4) {
    fT1CMET = t1CMET_configurable(currentFileName, jec_version_data, jec_version_mc, pt_jec_thresh, eta_exclusion_range, exclude_jets, exclude_jets, pt_thresh, 0, mCorr);
    fT1CMET_up = t1CMET_configurable(currentFileName, jec_version_data, jec_version_mc, pt_jec_thresh, eta_exclusion_range, exclude_jets, exclude_jets, pt_thresh, 1, mCorr);
    fT1CMET_down = t1CMET_configurable(currentFileName, jec_version_data, jec_version_mc, pt_jec_thresh, eta_exclusion_range, exclude_jets, exclude_jets, pt_thresh, 2, mCorr);
  }
  else {
    fT1CMET.SetCoordinates(evt_mod_pfmet() * cos(evt_mod_pfmetPhi()), evt_mod_pfmet() * sin(evt_mod_pfmetPhi()), 0, evt_mod_pfmet());
    fT1CMET_up.SetCoordinates(evt_mod_pfmet_JetEnUp(), 0, 0, evt_mod_pfmet_JetEnUp());
    fT1CMET_down.SetCoordinates(evt_mod_pfmet_JetEnDown(), 0, 0, evt_mod_pfmet_JetEnDown());
  }


  

  t1met = fT1CMET.pt();
 
  double t1met_up = fT1CMET_up.pt();
  double t1met_down = fT1CMET_down.pt();

  vector<double> vMET = {t1met, t1met_up, t1met_down};

  t1met_up = *max_element(vMET.begin(), vMET.end());
  t1met_down = *min_element(vMET.begin(), vMET.end());

  ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float>> fT1CMET_temp, fT1CMET_up_temp, fT1CMET_down_temp;
  fT1CMET_temp = fT1CMET;
  fT1CMET_up_temp = fT1CMET_up;
  fT1CMET_down_temp = fT1CMET_down;

  if (fT1CMET_up_temp.pt() >= fT1CMET_temp.pt() && fT1CMET_up_temp.pt() >= fT1CMET_down_temp.pt()) 
    fT1CMET_up = fT1CMET_up_temp;
  else if (fT1CMET_temp.pt() >= fT1CMET_up_temp.pt() && fT1CMET_temp.pt() >= fT1CMET_down_temp.pt()) 
    fT1CMET_up = fT1CMET_temp;
  else if (fT1CMET_down_temp.pt() >= fT1CMET_temp.pt() && fT1CMET_down_temp.pt() >= fT1CMET_up_temp.pt()) 
    fT1CMET_up = fT1CMET_down_temp;

  if (fT1CMET_up_temp.pt() <= fT1CMET_temp.pt() && fT1CMET_up_temp.pt() <= fT1CMET_down_temp.pt()) 
    fT1CMET_down = fT1CMET_up_temp;
  else if (fT1CMET_temp.pt() <= fT1CMET_up_temp.pt() && fT1CMET_temp.pt() <= fT1CMET_down_temp.pt())
    fT1CMET_down = fT1CMET_temp;
  else if (fT1CMET_down_temp.pt() <= fT1CMET_temp.pt() && fT1CMET_down_temp.pt() <= fT1CMET_up_temp.pt())
    fT1CMET_down = fT1CMET_down_temp;

  fill_histograms(hT1CMET, fT1CMET.pt(), weights);
  fill_histograms(hT1CMET_up, t1met_up, weights);
  fill_histograms(hT1CMET_down, t1met_down, weights);

  if (weights_up.size() > 0) {
    fill_histograms(hT1CMET_pu_up, t1met, weights_up);
    fill_histograms(hT1CMET_pu_down, t1met, weights_down);
  }

  if (isElEvt) {
    fill_histograms(hT1CMET_EE, fT1CMET.pt(), weights);
    fill_histograms(hT1CMET_EE_up, t1met_up, weights);
    fill_histograms(hT1CMET_EE_down, t1met_down, weights);
  }
  else {
    fill_histograms(hT1CMET_MM, fT1CMET.pt(), weights);
    fill_histograms(hT1CMET_MM_up, t1met_up, weights);
    fill_histograms(hT1CMET_MM_down, t1met_down, weights);
  }

  if (nJets == 0) {
    fill_histograms(hT1CMET_0Jets, fT1CMET.pt(), weights);
    fill_histograms(hT1CMET_0Jets_up, t1met_up, weights);
    fill_histograms(hT1CMET_0Jets_down, t1met_down, weights);
  }
  else {
    fill_histograms(hT1CMET_1pJets, fT1CMET.pt(), weights);
    fill_histograms(hT1CMET_1pJets_up, t1met_up, weights);
    fill_histograms(hT1CMET_1pJets_down, t1met_down, weights);
  }


  // Response & Resolution
  double boson_pt, u_para, u_perp, u_para_plus_qt;
  boson_pt = boson_pT(isElEvt, id1, id2, fT1CMET, u_para, u_perp, u_para_plus_qt);

  double zpt;
  double mass = dilepMass(isElEvt, id1, id2, zpt); 

  if (isElEvt)
    fill_histograms(hZMassEE, mass, weights);
  else
    fill_histograms(hZMassMuMu, mass, weights);

  if (boson_pt >= 300) {
    if (isElEvt)
      fill_histograms(hZMassEE_high_qT, mass, weights);
    else
      fill_histograms(hZMassMuMu_high_qT, mass, weights);
  }

  if (boson_pt >= 200) {
    if (n_jets == 1) {
      for (unsigned int i = 0; i < vCorrectedJets.size(); i++) {
	if (DeltaR(pfjets_p4().at(i),pl1) < 0.4)            { continue; }
	if (DeltaR(pfjets_p4().at(i),pl2) < 0.4)            { continue; }
	if (vCorrectedJets[i].pt() < 30)		{ continue; }
	fill_histograms2D(hJetEtaPhi_1Jet_qTGeq200, vCorrectedJets[i].eta(), vCorrectedJets[i].phi(), weights);
      }
    }
    if (n_high_pt_jets == 1 && n_jets == 1) {
      for (unsigned int i = 0; i < vCorrectedJets.size(); i++) {
        if (DeltaR(pfjets_p4().at(i),pl1) < 0.4)            { continue; }
        if (DeltaR(pfjets_p4().at(i),pl2) < 0.4)            { continue; }
	if (vCorrectedJets[i].pt() < 100)		{ continue; }
        fill_histograms2D(hJetEtaPhi_1HighPtJet_qTGeq200, vCorrectedJets[i].eta(), vCorrectedJets[i].phi(), weights);
      }
    }
  }

  int resolution_idx = find_index(resolution_bins, boson_pt);
  fill_histograms(hZpT, boson_pt, weights);
  fill_histograms(hT1CMET_UPara, u_para, weights);
  fill_histograms(hT1CMET_UPerp, u_perp, weights);
  fill_histograms(hT1CMET_UParaPlusqT, u_para_plus_qt, weights);
  if (boson_pt > 300)
    fill_histograms(hT1CMET_UPara_over_high_qT, -u_para/boson_pt, weights);

  fill_histograms(hResponse[resolution_idx], -u_para/boson_pt, weights);
  if (isElEvt)      fill_histograms(hResponseEE[resolution_idx], -u_para/boson_pt, weights);
  else              fill_histograms(hResponseMM[resolution_idx], -u_para/boson_pt, weights);

  if (vId[0] < 10) fill_histograms(hResponseVeryLowPU[resolution_idx], -u_para/boson_pt, weights);
  else if (vId[0] < 25) fill_histograms(hResponseLowPU[resolution_idx], -u_para/boson_pt, weights); 
  else if (vId[0] < 35) fill_histograms(hResponseMedPU[resolution_idx], -u_para/boson_pt, weights); 
  else if (vId[0] >= 35) fill_histograms(hResponseHighPU[resolution_idx], -u_para/boson_pt, weights); 

  if (abs(vId[1]) < 1.5) fill_histograms(hResponseLeadJetLowEta[resolution_idx], -u_para/boson_pt, weights); 
  else if (abs(vId[1] < 2.5)) fill_histograms(hResponseLeadJetMedEta[resolution_idx], -u_para/boson_pt, weights);
  else if (abs(vId[1] >= 2.5)) fill_histograms(hResponseLeadJetHighEta[resolution_idx], -u_para/boson_pt, weights); 

  if (n_jets == 1) {
    if (abs(vId[1]) < 1.5) fill_histograms(hResponseLeadJetLowEta_30GeVJet[resolution_idx], -u_para/boson_pt, weights);
    else if (abs(vId[1] < 2.5)) fill_histograms(hResponseLeadJetMedEta_30GeVJet[resolution_idx], -u_para/boson_pt, weights);
    else if (abs(vId[1] >= 2.5)) fill_histograms(hResponseLeadJetHighEta_30GeVJet[resolution_idx], -u_para/boson_pt, weights);
  }
  if (n_high_pt_jets == 1 && n_jets == 1) {
    if (abs(vId[1]) < 1.5) fill_histograms(hResponseLeadJetLowEta_100GeVJet[resolution_idx], -u_para/boson_pt, weights);
    else if (abs(vId[1] < 2.5)) fill_histograms(hResponseLeadJetMedEta_100GeVJet[resolution_idx], -u_para/boson_pt, weights);
    else if (abs(vId[1] >= 2.5)) fill_histograms(hResponseLeadJetHighEta_100GeVJet[resolution_idx], -u_para/boson_pt, weights);
  }


  fill_histograms(hResPara[resolution_idx], u_para, weights);
  fill_histograms(hResPerp[resolution_idx], u_perp, weights);

  double boson_pt_up, u_para_up, u_perp_up, u_para_plus_qt_up;
  boson_pt_up = boson_pT(isElEvt, id1, id2, fT1CMET_up, u_para_up, u_perp_up, u_para_plus_qt_up);
  int resolution_idx_up = find_index(resolution_bins, boson_pt_up);
   
  fill_histograms(hResponseUp[resolution_idx_up], -u_para_up/boson_pt_up, weights);
  if (isElEvt)      fill_histograms(hResponseUpEE[resolution_idx_up], -u_para_up/boson_pt_up, weights);
  else              fill_histograms(hResponseUpMM[resolution_idx_up], -u_para_up/boson_pt_up, weights);

  if (vId[0] < 25) fill_histograms(hResponseUpLowPU[resolution_idx_up], -u_para_up/boson_pt_up, weights);
  else if (vId[0] < 35) fill_histograms(hResponseUpMedPU[resolution_idx_up], -u_para_up/boson_pt_up, weights);
  else if (vId[0] >= 35) fill_histograms(hResponseUpHighPU[resolution_idx_up], -u_para_up/boson_pt_up, weights);

  if (abs(vId[1]) < 1.5) fill_histograms(hResponseUpLeadJetLowEta[resolution_idx_up], -u_para_up/boson_pt_up, weights);
  else if (abs(vId[1] < 2.5)) fill_histograms(hResponseUpLeadJetMedEta[resolution_idx_up], -u_para_up/boson_pt_up, weights);
  else if (abs(vId[1] >= 2.5)) fill_histograms(hResponseUpLeadJetHighEta[resolution_idx_up], -u_para_up/boson_pt_up, weights);

  fill_histograms(hResUpPara[resolution_idx_up], u_para_up, weights);
  fill_histograms(hResUpPerp[resolution_idx_up], u_perp_up, weights);

  double boson_pt_down, u_para_down, u_perp_down, u_para_plus_qt_down;
  boson_pt_down = boson_pT(isElEvt, id1, id2, fT1CMET_down, u_para_down, u_perp_down, u_para_plus_qt_down);
  int resolution_idx_down = find_index(resolution_bins, boson_pt_down);

  fill_histograms(hResponseDown[resolution_idx_down], -u_para_down/boson_pt_down, weights);
  if (isElEvt)      fill_histograms(hResponseDownEE[resolution_idx_down], -u_para_down/boson_pt_down, weights);
  else              fill_histograms(hResponseDownMM[resolution_idx_down], -u_para_down/boson_pt_down, weights);

  if (vId[0] < 25) fill_histograms(hResponseDownLowPU[resolution_idx_down], -u_para_down/boson_pt_down, weights);
  else if (vId[0] < 35) fill_histograms(hResponseDownMedPU[resolution_idx_down], -u_para_down/boson_pt_down, weights);
  else if (vId[0] >= 35) fill_histograms(hResponseDownHighPU[resolution_idx_down], -u_para_down/boson_pt_down, weights);

  if (abs(vId[1]) < 1.5) fill_histograms(hResponseDownLeadJetLowEta[resolution_idx_down], -u_para_down/boson_pt_down, weights);
  else if (abs(vId[1] < 2.5)) fill_histograms(hResponseDownLeadJetMedEta[resolution_idx_down], -u_para_down/boson_pt_down, weights);
  else if (abs(vId[1] >= 2.5)) fill_histograms(hResponseDownLeadJetHighEta[resolution_idx_down], -u_para_down/boson_pt_down, weights);

  fill_histograms(hResDownPara[resolution_idx_down], u_para_down, weights);
  fill_histograms(hResDownPerp[resolution_idx_down], u_perp_down, weights);

}

#endif // _METHELPER_H_
