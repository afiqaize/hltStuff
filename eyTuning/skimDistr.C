// Updated version of makeDistr.C that performs some initial skimming
// Jan 14 2016: Added accPath cut to reject failing events and bugfixes
// Usage: root -l skimDistr.C
// Jun 13 2016: updated the WP methods to 2016 pre-ichep

#include "TFile.h"
#include "TTree.h"
#include "TMath.h"
#include "TROOT.h"

Bool_t checkCand(const string setWP, const Float_t eta,
                 const Float_t sie, const Float_t hoe, const Float_t ecc, const Float_t hcc, 
                 const Float_t eop, const Float_t chi, const Float_t mih, 
                 const Float_t des, const Float_t dph, const Float_t tki) {

  Bool_t candOk = true;
  Float_t varVal[10], varThr[10];

  // Order as in the method call -> HLT filtering
  varVal[0] = sie; varVal[1] = hoe;
  varVal[2] = ecc; varVal[3] = hcc;
  varVal[4] = eop; varVal[5] = chi;
  varVal[6] = mih; varVal[7] = des;
  varVal[8] = dph; varVal[9] = tki;

  if (fabs(eta) < 1.4791 && setWP == "WPLoose") {
  varThr[0] = 0.011; varThr[1] = 0.06;
  varThr[2] = 0.145; varThr[3] = 0.15;
  varThr[4] = 0.012; varThr[5] = 99.0;
  varThr[6] = 99.0 ; varThr[7] = 0.004;
  varThr[8] = 0.02 ; varThr[9] = 0.08;
  }

  else if (fabs(eta) > 1.4791 && setWP == "WPLoose") {
  varThr[0] = 0.032; varThr[1] = 0.065;
  varThr[2] = 0.135; varThr[3] = 0.13;
  varThr[4] = 0.01 ; varThr[5] = 2.8;
  varThr[6] = 2.5  ; varThr[7] = 0.007;
  varThr[8] = 0.02 ; varThr[9] = 0.08;
  }

  else if (fabs(eta) < 1.4791 && setWP == "WPTight") {
  varThr[0] = 0.011; varThr[1] = 0.05;
  varThr[2] = 0.145; varThr[3] = 0.13;
  varThr[4] = 0.01 ; varThr[5] = 99.0;
  varThr[6] = 99.0 ; varThr[7] = 0.0035;
  varThr[8] = 0.015; varThr[9] = 0.06;
  }

  else if (fabs(eta) > 1.4791 && setWP == "WPTight") {
  varThr[0] = 0.029; varThr[1] = 0.05;
  varThr[2] = 0.105; varThr[3] = 0.095;
  varThr[4] = 0.008; varThr[5] = 2.5;
  varThr[6] = 1.5  ; varThr[7] = 0.006;
  varThr[8] = 0.015; varThr[9] = 0.06;
  }

  else {
  varThr[0] = 999.; varThr[1] = 999.;
  varThr[2] = 999.; varThr[3] = 999.;
  varThr[4] = 999.; varThr[5] = 999.;
  varThr[6] = 999.; varThr[7] = 999.;
  varThr[8] = 999.; varThr[9] = 999.;
  }

  for (Int_t aa = 0; aa < 10; aa++)
    candOk = candOk and (varVal[aa] < varThr[aa]);

  return candOk;

}

Float_t deltaPhi(const Float_t phi1, const Float_t phi2) {

  Float_t dp = TMath::ACos( TMath::Cos(phi1 - phi2) );
  return dp;

}

Float_t deltaR(const Float_t eta1, const Float_t phi1, const Float_t eta2, const Float_t phi2) {

  return TMath::Sqrt( TMath::Sq(eta1 - eta2) + TMath::Sq(deltaPhi(phi1, phi2)) );

}
 
void skimDistr() {

  //const string inDir = "/home/afiqaize/Downloads/HLT_Val/dev/e_80x/conf/v11/eeAngEff_Jun13/";
  const string inDir = "/afs/cern.ch/work/a/afiqaize/egm/eeAngEff_Jun13/CMSSW_8_0_11/src/HLTTest/MyCandidates/ntup/";
  const string outputFile = "skim_m1z1ll.root";

  Bool_t hasReco = false;
  Bool_t isMC = true;

  TFile* outFile = new TFile((inDir + outputFile).c_str(), "recreate");
  TTree* outTree = new TTree("eleDistr", "eleDistr");
  outTree->SetAutoSave(500000000);

  Int_t cand, npf, hlt_n, reco_n, gp_n, nVtx, nBX, nPUtrue, nRun, nEvt, nLumi, accPath, itype; 
  Int_t passHLT[10], genMatch[10], BX[100], nPUobs[100], mishitspf[10], reco_mishits[10];
  Float_t rho, puWgt, genWgt, weight, epf[10], eRawpf[10], etpf[10], etRawpf[10], etapf[10], phipf[10];
  Float_t sieiepf[10], dphipf[10], detapf[10], detaseedpf[10], hoepf[10];
  Float_t ecalpf[10], hcalpf[10], tkisopf[10], eoppf[10], chi2pf[10];
  Float_t gp_pt[10], gp_eta[10], gp_phi[10];
  Float_t reco_e[10], reco_et[10], reco_eRaw[10], reco_etRaw[10], reco_pt[10], reco_eta[10], reco_phi[10];
  Float_t reco_sieie[10], reco_hoe[10], reco_ecal[10], reco_dphi[10], reco_deta[10], reco_detaseed[10];
  Float_t reco_hcal[10], reco_tkiso[10], reco_eop[10], reco_chi2[10];

  Float_t hlt_e[10], hlt_er[10], hlt_et[10], hlt_etr[10], hlt_eta[10], hlt_phi[10], hlt_hoe[10];
  Float_t hlt_sie[10], hlt_dph[10], hlt_det[10], hlt_des[10], hlt_eop[10], hlt_chi[10], hlt_mih[10];
  Float_t hlt_eca[10], hlt_ecc[10], hlt_ecu[10], hlt_hca[10], hlt_hcc[10], hlt_hcu[10], hlt_tki[10];
  Float_t reco_er[10], reco_etr[10], reco_sie[10],  reco_dph[10], reco_det[10], reco_des[10];
  Float_t reco_eca[10], reco_ecu[10], reco_hca[10], reco_hcu[10], reco_tki[10], reco_chi[10], reco_mih[10];

  outTree->Branch("nRun", &nRun, "nRun/I");
  outTree->Branch("nEvt", &nEvt, "nEvt/I");
  outTree->Branch("nLumi", &nLumi, "nLumi/I");

  outTree->Branch("nVtx", &nVtx, "nVtx/I");
  outTree->Branch("rho" , &rho, "rho/F");
  outTree->Branch("puWgt", &puWgt, "puWgt/F");

  outTree->Branch("hlt_n" , &hlt_n, "hlt_n/I");
  outTree->Branch("hlt_e"   , hlt_e, "hlt_e[hlt_n]/F");
  outTree->Branch("hlt_er"   , hlt_er, "hlt_er[hlt_n]/F");
  outTree->Branch("hlt_et"   , hlt_et, "hlt_et[hlt_n]/F");
  outTree->Branch("hlt_etr"   , hlt_etr, "hlt_etr[hlt_n]/F");
  outTree->Branch("hlt_eta"  , hlt_eta, "hlt_eta[hlt_n]/F");
  outTree->Branch("hlt_phi"  , hlt_phi, "hlt_phi[hlt_n]/F");
  outTree->Branch("hlt_sie", hlt_sie, "hlt_sie[hlt_n]/F");
  outTree->Branch("hlt_eca" , hlt_eca, "hlt_eca[hlt_n]/F");
  outTree->Branch("hlt_ecc" , hlt_ecc, "hlt_ecc[hlt_n]/F");
  outTree->Branch("hlt_ecu" , hlt_ecu, "hlt_ecu[hlt_n]/F");
  outTree->Branch("hlt_dph" , hlt_dph, "hlt_dph[hlt_n]/F");
  outTree->Branch("hlt_det" , hlt_det, "hlt_det[hlt_n]/F");
  outTree->Branch("hlt_des" , hlt_des, "hlt_des[hlt_n]/F");
  outTree->Branch("hlt_hoe"  , hlt_hoe, "hlt_hoe[hlt_n]/F");
  outTree->Branch("hlt_hca" , hlt_hca, "hlt_hca[hlt_n]/F");
  outTree->Branch("hlt_hcc" , hlt_hcc, "hlt_hcc[hlt_n]/F");
  outTree->Branch("hlt_hcu" , hlt_hcu, "hlt_hcu[hlt_n]/F");
  outTree->Branch("hlt_tki", hlt_tki, "hlt_tki[hlt_n]/F");
  outTree->Branch("hlt_eop"  , hlt_eop, "hlt_eop[hlt_n]/F");
  outTree->Branch("hlt_chi" , hlt_chi, "hlt_chi[hlt_n]/F");
  outTree->Branch("hlt_mih" , hlt_mih, "hlt_mih[hlt_n]/F");
  outTree->Branch("passHLT" , passHLT, "passHLT[hlt_n]/I");
  outTree->Branch("genMatch", &genMatch, "genMatch[hlt_n]/I");
  outTree->Branch("itype"  , &itype, "itype/I");
  outTree->Branch("weight" , &weight, "weight/F");

  if (isMC) {

    outTree->Branch("genWgt", &genWgt, "genWgt/F");
    outTree->Branch("gp_n", &gp_n, "gp_n/I");
    outTree->Branch("gp_pt", gp_pt, "gp_pt[gp_n]/F");
    outTree->Branch("gp_eta", gp_eta, "gp_eta[gp_n]/F");
    outTree->Branch("gp_phi", gp_phi, "gp_phi[gp_n]/F");
    outTree->Branch("nBX", &nBX, "nBX/I");
    outTree->Branch("BX", BX, "BX[nBX]/I");
    outTree->Branch("nPUtrue", &nPUtrue, "nPUtrue/I");
    outTree->Branch("nPUobs", nPUobs, "nPUobs[nBX]/I");

  }

  if (hasReco) {

    outTree->Branch("reco_n"   , &reco_n, "reco_n/I");
    outTree->Branch("reco_e"   , reco_e, "reco_e[reco_n]/F");
    outTree->Branch("reco_et"   , reco_et, "reco_et[reco_n]/F");
    outTree->Branch("reco_er"   , reco_er, "reco_er[reco_n]/F");
    outTree->Branch("reco_etr"   , reco_etr, "reco_etr[reco_n]/F");
    outTree->Branch("reco_pt"   , reco_pt, "reco_pt[reco_n]/F");
    outTree->Branch("reco_eta"  , reco_eta, "reco_eta[reco_n]/F");
    outTree->Branch("reco_phi"  , reco_phi, "reco_phi[reco_n]/F");
    outTree->Branch("reco_sie", reco_sie, "reco_sie[reco_n]/F");
    outTree->Branch("reco_eca" , reco_eca, "reco_eca[reco_n]/F");
    outTree->Branch("reco_ecu" , reco_ecu, "reco_ecu[reco_n]/F");
    outTree->Branch("reco_dph" , reco_dph, "reco_dph[reco_n]/F");
    outTree->Branch("reco_det" , reco_det, "reco_det[reco_n]/F");
    outTree->Branch("reco_des" , reco_des, "reco_des[reco_n]/F");
    outTree->Branch("reco_hoe"  , reco_hoe, "reco_hoe[reco_n]/F");
    outTree->Branch("reco_hca" , reco_hca, "reco_hca[reco_n]/F");
    outTree->Branch("reco_hcu" , reco_hcu, "reco_hcu[reco_n]/F");
    outTree->Branch("reco_tki", reco_tki, "reco_tki[reco_n]/F");
    outTree->Branch("reco_eop"  , reco_eop, "reco_eop[reco_n]/F");
    outTree->Branch("reco_chi" , reco_chi, "reco_chi[reco_n]/F");
    outTree->Branch("reco_mih" , reco_mih, "reco_mih[reco_n]/F");

  }
  
  // MC vs data: weight = xsec_mc * intLumi_dat / nEvt_mc
  const int proc = 2;
  const int type[proc] = {-1, -1};
  const float weights[proc] = {1., 1.};
  const char* names[proc] = {"z1ll-0", "z1ll-1"};
  //const int proc = 9;
  //const int type[proc] = {-2, -2, -2, -2, -2, -2, -2, -2, -2};
  //const float weights[proc] = {13.044494632, 1., 1., 0.138052392, 0.138052392, 0.080386239, 0.080386239, 0.06825985, 0.065750272};
  //const char* names[proc] = {"qcd15", "qcd30-0", "qcd30-1", "qcd50-0", "qcd50-1", "qcd80-0", "qcd80-1", "qcd120", "qcd170"};
    
  for (Int_t nfiles = 0; nfiles < proc; nfiles++) {
  
    TFile* file = TFile::Open((inDir + names[nfiles] + ".root").c_str());
    TTree* inTree = (TTree*)file->Get("tree");

    inTree->SetBranchStatus("*"          , 0);
    inTree->SetBranchStatus("nRun"       , 1);
    inTree->SetBranchStatus("nEvt"       , 1);
    inTree->SetBranchStatus("nLumi"      , 1);
    inTree->SetBranchStatus("accPath"    , 1);
    inTree->SetBranchStatus("npf"        , 1);
    inTree->SetBranchStatus("nVtx"       , 1);
    inTree->SetBranchStatus("rho"        , 1);
    //inTree->SetBranchStatus("puWgt"      , 1);
    inTree->SetBranchStatus("epf"        , 1);
    inTree->SetBranchStatus("eRawpf"     , 1);
    inTree->SetBranchStatus("etpf"       , 1);
    inTree->SetBranchStatus("etRawpf"    , 1);
    inTree->SetBranchStatus("etapf"      , 1);
    inTree->SetBranchStatus("phipf"      , 1);
    inTree->SetBranchStatus("sieiepf"    , 1);
    inTree->SetBranchStatus("ecalpf"     , 1);
    inTree->SetBranchStatus("dphipf"     , 1);
    inTree->SetBranchStatus("detapf"     , 1);
    inTree->SetBranchStatus("detaseedpf" , 1);
    inTree->SetBranchStatus("hoepf"      , 1);
    inTree->SetBranchStatus("hcalpf"     , 1);
    inTree->SetBranchStatus("tkisopf"    , 1);
    inTree->SetBranchStatus("eoppf"      , 1);
    inTree->SetBranchStatus("chi2pf"     , 1);
    inTree->SetBranchStatus("mishitspf"  , 1);

    inTree->SetBranchAddress("nRun"       , &nRun);
    inTree->SetBranchAddress("nEvt"       , &nEvt);
    inTree->SetBranchAddress("nLumi"      , &nLumi);
    inTree->SetBranchAddress("accPath"    , &accPath);
    inTree->SetBranchAddress("npf"        , &npf);
    inTree->SetBranchAddress("nVtx"       , &nVtx);
    inTree->SetBranchAddress("rho"        , &rho);
    //inTree->SetBranchAddress("puWgt"      , &puWgt);
    inTree->SetBranchAddress("epf"        , epf);
    inTree->SetBranchAddress("eRawpf"     , eRawpf);
    inTree->SetBranchAddress("etpf"       , etpf);
    inTree->SetBranchAddress("etRawpf"    , etRawpf);
    inTree->SetBranchAddress("etapf"      , etapf);
    inTree->SetBranchAddress("phipf"      , phipf);
    inTree->SetBranchAddress("sieiepf"    , sieiepf);
    inTree->SetBranchAddress("ecalpf"     , ecalpf);
    inTree->SetBranchAddress("dphipf"     , dphipf);
    inTree->SetBranchAddress("detapf"     , detapf);
    inTree->SetBranchAddress("detaseedpf" , detaseedpf);
    inTree->SetBranchAddress("hoepf"      , hoepf);
    inTree->SetBranchAddress("hcalpf"     , hcalpf);
    inTree->SetBranchAddress("tkisopf"    , tkisopf);
    inTree->SetBranchAddress("eoppf"      , eoppf);
    inTree->SetBranchAddress("chi2pf"     , chi2pf);
    inTree->SetBranchAddress("mishitspf"  , mishitspf);

    if (isMC) {

    inTree->SetBranchStatus("nBX"     , 1);
    inTree->SetBranchStatus("BX"      , 1);
    inTree->SetBranchStatus("nPUtrue" , 1);
    inTree->SetBranchStatus("nPUobs"  , 1);
    inTree->SetBranchStatus("gevt_wgt", 1);
    inTree->SetBranchStatus("gpn"     , 1);
    inTree->SetBranchStatus("gppt"    , 1);
    inTree->SetBranchStatus("gpeta"   , 1);
    inTree->SetBranchStatus("gpphi"   , 1);

    inTree->SetBranchAddress("gevt_wgt", &genWgt);
    inTree->SetBranchAddress("gpn"     , &gp_n);
    inTree->SetBranchAddress("gppt"    , gp_pt);
    inTree->SetBranchAddress("gpeta"   , gp_eta);
    inTree->SetBranchAddress("gpphi"   , gp_phi);
    inTree->SetBranchAddress("nBX"     , &nBX);
    inTree->SetBranchAddress("BX"      , BX);
    inTree->SetBranchAddress("nPUtrue" , &nPUtrue);
    inTree->SetBranchAddress("nPUobs"  , nPUobs);

    }

    if (hasReco) {

      inTree->SetBranchStatus("reco_n"        , 1);
      inTree->SetBranchStatus("reco_e"        , 1);
      inTree->SetBranchStatus("reco_et"       , 1);
      inTree->SetBranchStatus("reco_eRaw"     , 1);
      inTree->SetBranchStatus("reco_etRaw"    , 1);
      inTree->SetBranchStatus("reco_pt"       , 1);
      inTree->SetBranchStatus("reco_eta"      , 1);
      inTree->SetBranchStatus("reco_phi"      , 1);
      inTree->SetBranchStatus("reco_sieie"    , 1);
      inTree->SetBranchStatus("reco_ecal"     , 1);
      inTree->SetBranchStatus("reco_dphi"     , 1);
      inTree->SetBranchStatus("reco_deta"     , 1);
      inTree->SetBranchStatus("reco_detaseed" , 1);
      inTree->SetBranchStatus("reco_hoe"      , 1);
      inTree->SetBranchStatus("reco_hcal"     , 1);
      inTree->SetBranchStatus("reco_tkiso"    , 1);
      inTree->SetBranchStatus("reco_eop"      , 1);
      inTree->SetBranchStatus("reco_chi2"     , 1);
      inTree->SetBranchStatus("reco_mishits"  , 1);

      inTree->SetBranchAddress("reco_n"        , &reco_n);
      inTree->SetBranchAddress("reco_e"        , reco_e);
      inTree->SetBranchAddress("reco_et"       , reco_et);
      inTree->SetBranchAddress("reco_eRaw"     , reco_eRaw);
      inTree->SetBranchAddress("reco_etRaw"    , reco_etRaw);
      inTree->SetBranchAddress("reco_pt"       , reco_pt);
      inTree->SetBranchAddress("reco_eta"      , reco_eta);
      inTree->SetBranchAddress("reco_phi"      , reco_phi);
      inTree->SetBranchAddress("reco_sieie"    , reco_sieie);
      inTree->SetBranchAddress("reco_ecal"     , reco_ecal);
      inTree->SetBranchAddress("reco_dphi"     , reco_dphi);
      inTree->SetBranchAddress("reco_deta"     , reco_deta);
      inTree->SetBranchAddress("reco_detaseed" , reco_detaseed);
      inTree->SetBranchAddress("reco_hoe"      , reco_hoe);
      inTree->SetBranchAddress("reco_hcal"     , reco_hcal);
      inTree->SetBranchAddress("reco_tkiso"    , reco_tkiso);
      inTree->SetBranchAddress("reco_eop"      , reco_eop);
      inTree->SetBranchAddress("reco_chi2"     , reco_chi2);
      inTree->SetBranchAddress("reco_mishits"  , reco_mishits);

    }
    
    Int_t entries = inTree->GetEntries();
    for (Int_t z = 0; z < entries; z++) {
      inTree->GetEntry(z);

      if (z % 100000 == 1)
        cout << z << " / " << entries << " done..." << endl;

      // check triggering of event first
      //if (accPath != 1) continue;

      itype = type[nfiles];
      weight = weights[nfiles];
      puWgt = 1.;
      cand = 0;

      for (Int_t i = 0; i < npf; i++) {

        if(!checkCand("", etapf[i],
                      sieiepf[i], (hoepf[i] / epf[i]),
                      (ecalpf[i] / etpf[i]), (hcalpf[i] / etpf[i]),
                      eoppf[i], chi2pf[i], (Float_t) mishitspf[i],
                      detaseedpf[i], dphipf[i], (tkisopf[i] / etpf[i]))) continue;

        passHLT[cand] = 0;
        genMatch[cand] = 0;

        // eca is the corrected sum
	hlt_e[cand] = epf[i];
	hlt_er[cand] = eRawpf[i];
	hlt_et[cand] = etpf[i];
	hlt_etr[cand] = etRawpf[i];
	hlt_eta[cand] = etapf[i];
	hlt_phi[cand] = phipf[i];
	hlt_sie[cand] = sieiepf[i];
	hlt_eca[cand] = ecalpf[i];
	hlt_ecc[cand] = ecalpf[i] / etpf[i];
	hlt_dph[cand] = dphipf[i];
	hlt_det[cand] = detapf[i];
	hlt_des[cand] = detaseedpf[i];
	hlt_hoe[cand] = hoepf[i] / epf[i];
	hlt_hca[cand] = hcalpf[i];
	hlt_hcc[cand] = hcalpf[i] / etpf[i];
	hlt_tki[cand] = tkisopf[i] / etpf[i];
	hlt_eop[cand] = eoppf[i];
	hlt_chi[cand] = chi2pf[i];
        hlt_mih[cand] = (Float_t) mishitspf[i];

        if(checkCand("WPTight", hlt_eta[cand], hlt_sie[cand], hlt_hoe[cand], hlt_ecc[cand], hlt_hcc[cand], hlt_eop[cand], hlt_chi[cand], hlt_mih[cand], hlt_des[cand], hlt_dph[cand], hlt_tki[cand]))
          passHLT[cand] = 1;

        if (isMC) {
          Float_t drmax = 0.1;
          for (Int_t j = 0; j < gp_n; j++) {

            Float_t dr = deltaR(hlt_eta[cand], hlt_phi[cand], gp_eta[j], gp_phi[j]);
            if (dr < drmax) {
              genMatch[cand] = 1;
              break;
            }
          }
        }

        if (fabs(hlt_eta[cand]) < 1.4791) {
          // Recompute the non-corr iso
          hlt_ecu[cand] = (hlt_eca[cand] + (0.16544 * rho));
          hlt_hcu[cand] = (hlt_hca[cand] + (0.05956 * rho));
        }

        if (fabs(hlt_eta[cand]) >= 1.4791) {
          // Recompute the non-corr iso
          hlt_ecu[cand] = (hlt_eca[cand] + (0.13212 * rho));
          hlt_hcu[cand] = (hlt_hca[cand] + (0.13052 * rho));
        }

        cand++;

      }

      hlt_n = cand;
      if (hlt_n < 2) continue;

      if (hasReco) {

        for (Int_t k = 0; k < reco_n; k++) {

          reco_er[k] = reco_eRaw[k];
          reco_etr[k] = reco_etRaw[k];
          reco_sie[k] = reco_sieie[k];
          reco_eca[k] = reco_ecal[k];
          reco_ecu[k] = reco_ecal[k] / reco_et[k];
          reco_dph[k] = fabs(reco_dphi[k]);
          reco_det[k] = fabs(reco_deta[k]);
          reco_des[k] = fabs(reco_detaseed[k]);
          reco_eop[k] = fabs(reco_eop[k]);
          reco_hca[k] = reco_hcal[k];
          reco_hcu[k] = reco_hcal[k] / reco_et[k];
          reco_tki[k] = reco_tkiso[k] / reco_et[k];
          reco_chi[k] = reco_chi2[k];
          reco_mih[k] = (Float_t) reco_mishits[k];

        }
      }

      outTree->Fill();

    }
  }
  
  outFile->cd();
  outTree->Write();
  outFile->Close();

  gROOT->ProcessLine(".q");

}
