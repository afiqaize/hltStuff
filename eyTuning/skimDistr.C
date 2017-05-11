// For skimming the trees created by plotDistr
// Usage: root -l skimDistr.C

#include "TFile.h"
#include "TTree.h"
#include "TMath.h"
#include "TROOT.h"

#include "hltWP.cxx"

double deltaPhi(const double phi1, const double phi2) {
  double dp = TMath::ACos( TMath::Cos(phi1 - phi2) );
  return dp;
}

double deltaR(const double eta1, const double phi1, const double eta2, const double phi2) {
  return TMath::Sqrt( TMath::Sq(eta1 - eta2) + TMath::Sq(deltaPhi(phi1, phi2)) );
}
 
void skimDistr() {
  const std::string inDir = "";
  const std::string outputFile = "skim.root";

  bool hasReco = false;
  bool isMC = false;

  TFile* outFile = new TFile((inDir + outputFile).c_str(), "recreate");
  TTree* outTree = new TTree("hltTree", "hltTree");
  outTree->SetAutoSave(500000000);

  int nRun, nEvt, nLumi, nBX, nOrb, nSto, cand, npf, hlt_n, reco_n, gp_n, nVtx, mc_nBX, mc_nPUtrue, accPath, itype;
  int passHLT[10], genMatch[10], mc_BX[100], mc_nPUobs[100], mishitspf[10], reco_mishits[10];
  double rho, puWgt, genWgt, weight, epf[10], eRawpf[10], etpf[10], etRawpf[10], etapf[10], phipf[10];
  double sieiepf[10], dphipf[10], detapf[10], detaseedpf[10], hoepf[10];
  double ecalpf[10], hcalpf[10], tkisopf[10], eoppf[10], eopseedpf[10], ps2pf[10], chi2pf[10];
  double gp_pt[10], gp_eta[10], gp_phi[10];
  double reco_e[10], reco_et[10], reco_eRaw[10], reco_etRaw[10], reco_pt[10], reco_eta[10], reco_phi[10];
  double reco_sieie[10], reco_hoe[10], reco_ecal[10], reco_dphi[10], reco_deta[10], reco_detaseed[10];
  double reco_hcal[10], reco_tkiso[10], reco_eop[10], reco_chi2[10];

  double hlt_e[10], hlt_er[10], hlt_et[10], hlt_etr[10], hlt_eta[10], hlt_phi[10], hlt_hoe[10];
  double hlt_sie[10], hlt_dph[10], hlt_det[10], hlt_des[10], hlt_eop[10], hlt_esp[10], hlt_chi[10], hlt_mih[10];
  double hlt_eca[10], hlt_hca[10], hlt_tks[10], hlt_ps2[10];
  double reco_er[10], reco_etr[10], reco_sie[10],  reco_dph[10], reco_det[10], reco_des[10];
  double reco_eca[10], reco_hca[10], reco_tks[10], reco_chi[10], reco_mih[10];

  outTree->Branch("nRun", &nRun, "nRun/I");
  outTree->Branch("nEvt", &nEvt, "nEvt/I");
  outTree->Branch("nLumi", &nLumi, "nLumi/I");
  outTree->Branch("nBX", &nBX, "nBX/I");
  outTree->Branch("nOrb", &nOrb, "nOrb/I");
  outTree->Branch("nSto", &nSto, "nSto/I");

  outTree->Branch("nVtx", &nVtx, "nVtx/I");
  outTree->Branch("rho" , &rho, "rho/D");
  outTree->Branch("puWgt", &puWgt, "puWgt/D");

  outTree->Branch("hlt_n" , &hlt_n, "hlt_n/I");
  outTree->Branch("hlt_e"   , hlt_e, "hlt_e[hlt_n]/D");
  outTree->Branch("hlt_er"   , hlt_er, "hlt_er[hlt_n]/D");
  outTree->Branch("hlt_et"   , hlt_et, "hlt_et[hlt_n]/D");
  outTree->Branch("hlt_etr"   , hlt_etr, "hlt_etr[hlt_n]/D");
  outTree->Branch("hlt_eta"  , hlt_eta, "hlt_eta[hlt_n]/D");
  outTree->Branch("hlt_phi"  , hlt_phi, "hlt_phi[hlt_n]/D");
  outTree->Branch("hlt_sie", hlt_sie, "hlt_sie[hlt_n]/D");
  outTree->Branch("hlt_eca" , hlt_eca, "hlt_eca[hlt_n]/D");
  outTree->Branch("hlt_dph" , hlt_dph, "hlt_dph[hlt_n]/D");
  outTree->Branch("hlt_det" , hlt_det, "hlt_det[hlt_n]/D");
  outTree->Branch("hlt_des" , hlt_des, "hlt_des[hlt_n]/D");
  outTree->Branch("hlt_hoe"  , hlt_hoe, "hlt_hoe[hlt_n]/D");
  outTree->Branch("hlt_hca" , hlt_hca, "hlt_hca[hlt_n]/D");
  outTree->Branch("hlt_tks", hlt_tks, "hlt_tks[hlt_n]/D");
  outTree->Branch("hlt_eop"  , hlt_eop, "hlt_eop[hlt_n]/D");
  outTree->Branch("hlt_esp"  , hlt_esp, "hlt_esp[hlt_n]/D");
  outTree->Branch("hlt_ps2"  , hlt_ps2, "hlt_ps2[hlt_n]/D");
  outTree->Branch("hlt_chi" , hlt_chi, "hlt_chi[hlt_n]/D");
  outTree->Branch("hlt_mih" , hlt_mih, "hlt_mih[hlt_n]/D");
  outTree->Branch("passHLT" , passHLT, "passHLT[hlt_n]/I");
  outTree->Branch("genMatch", &genMatch, "genMatch[hlt_n]/I");
  outTree->Branch("itype"  , &itype, "itype/I");
  outTree->Branch("weight" , &weight, "weight/D");

  if (isMC) {
    outTree->Branch("genWgt", &genWgt, "genWgt/D");
    outTree->Branch("gp_n", &gp_n, "gp_n/I");
    outTree->Branch("gp_pt", gp_pt, "gp_pt[gp_n]/D");
    outTree->Branch("gp_eta", gp_eta, "gp_eta[gp_n]/D");
    outTree->Branch("gp_phi", gp_phi, "gp_phi[gp_n]/D");
    outTree->Branch("mc_nBX", &mc_nBX, "mc_nBX/I");
    outTree->Branch("mc_BX", mc_BX, "mc_BX[nBX]/I");
    outTree->Branch("mc_nPUtrue", &mc_nPUtrue, "mc_nPUtrue/I");
    outTree->Branch("mc_nPUobs", mc_nPUobs, "mc_nPUobs[nBX]/I");
  }

  if (hasReco) {
    outTree->Branch("reco_n"   , &reco_n, "reco_n/I");
    outTree->Branch("reco_e"   , reco_e, "reco_e[reco_n]/D");
    outTree->Branch("reco_et"   , reco_et, "reco_et[reco_n]/D");
    outTree->Branch("reco_er"   , reco_er, "reco_er[reco_n]/D");
    outTree->Branch("reco_etr"   , reco_etr, "reco_etr[reco_n]/D");
    outTree->Branch("reco_pt"   , reco_pt, "reco_pt[reco_n]/D");
    outTree->Branch("reco_eta"  , reco_eta, "reco_eta[reco_n]/D");
    outTree->Branch("reco_phi"  , reco_phi, "reco_phi[reco_n]/D");
    outTree->Branch("reco_sie", reco_sie, "reco_sie[reco_n]/D");
    outTree->Branch("reco_eca" , reco_eca, "reco_eca[reco_n]/D");
    outTree->Branch("reco_dph" , reco_dph, "reco_dph[reco_n]/D");
    outTree->Branch("reco_det" , reco_det, "reco_det[reco_n]/D");
    outTree->Branch("reco_des" , reco_des, "reco_des[reco_n]/D");
    outTree->Branch("reco_hoe"  , reco_hoe, "reco_hoe[reco_n]/D");
    outTree->Branch("reco_hca" , reco_hca, "reco_hca[reco_n]/D");
    outTree->Branch("reco_tks", reco_tks, "reco_tks[reco_n]/D");
    outTree->Branch("reco_eop"  , reco_eop, "reco_eop[reco_n]/D");
    outTree->Branch("reco_chi" , reco_chi, "reco_chi[reco_n]/D");
    outTree->Branch("reco_mih" , reco_mih, "reco_mih[reco_n]/D");
  }
  
  // MC vs data: weight = xsec_mc * intLumi_dat / nEvt_mc
  const int proc = 1;
  const int type[proc] = {1};
  const float weights[proc] = {1.};
  const char* names[proc] = {"sinEle23_loo"};
    
  for (int nfiles = 0; nfiles < proc; nfiles++) {
    TFile* file = TFile::Open((inDir + names[nfiles] + ".root").c_str());
    TTree* inTree = (TTree*)file->Get("tree");

    inTree->SetBranchStatus("*"          , 0);
    inTree->SetBranchStatus("nRun"       , 1);
    inTree->SetBranchStatus("nEvt"       , 1);
    inTree->SetBranchStatus("nLumi"      , 1);
    inTree->SetBranchStatus("nBX"        , 1);
    inTree->SetBranchStatus("nOrb"       , 1);
    inTree->SetBranchStatus("nSto"       , 1);
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
    inTree->SetBranchStatus("eopseedpf"  , 1);
    inTree->SetBranchStatus("ps2pf"      , 1);
    inTree->SetBranchStatus("chi2pf"     , 1);
    inTree->SetBranchStatus("mishitspf"  , 1);

    inTree->SetBranchAddress("nRun"       , &nRun);
    inTree->SetBranchAddress("nEvt"       , &nEvt);
    inTree->SetBranchAddress("nLumi"      , &nLumi);
    inTree->SetBranchAddress("nBX"        , &nBX);
    inTree->SetBranchAddress("nOrb"       , &nOrb);
    inTree->SetBranchAddress("nSto"       , &nSto);
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
    inTree->SetBranchAddress("eopseedpf"  , eopseedpf);
    inTree->SetBranchAddress("ps2pf"      , ps2pf);
    inTree->SetBranchAddress("chi2pf"     , chi2pf);
    inTree->SetBranchAddress("mishitspf"  , mishitspf);

    if (isMC) {
      inTree->SetBranchStatus("mc_nBX"     , 1);
      inTree->SetBranchStatus("mc_BX"      , 1);
      inTree->SetBranchStatus("mc_nPUtrue" , 1);
      inTree->SetBranchStatus("mc_nPUobs"  , 1);
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
      inTree->SetBranchAddress("mc_nBX"     , &mc_nBX);
      inTree->SetBranchAddress("mc_BX"      , mc_BX);
      inTree->SetBranchAddress("mc_nPUtrue" , &mc_nPUtrue);
      inTree->SetBranchAddress("mc_nPUobs"  , mc_nPUobs);
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
    
    int entries = inTree->GetEntries();
    for (int z = 0; z < entries; z++) {
      inTree->GetEntry(z);

      if (z % 100000 == 1)
        cout << z << " / " << entries << " done..." << endl;

      // check triggering of event first
      if (accPath != 1) continue;

      itype = type[nfiles];
      weight = weights[nfiles];
      puWgt = 1.;
      cand = 0;

      for (int i = 0; i < npf; i++) {
        // Incorrect usage, only to weed out defaults
        //if (!checkCand("", -1, rho,
        //               hlt_e, hlt_et, etapf[i], hlt_phi,
        //               sieiepf[i], hoepf[i], ecalpf[i], hcalpf[i], eoppf[i],
        //               chi2pf[i], (double) mishitspf[i], detaseedpf[i], dphipf[i], tkisopf[i])) continue;

        passHLT[cand] = 0;
        genMatch[cand] = 0;

	hlt_e[cand] = epf[i];
	hlt_er[cand] = eRawpf[i];
	hlt_et[cand] = etpf[i];
	hlt_etr[cand] = etRawpf[i];
	hlt_eta[cand] = etapf[i];
	hlt_phi[cand] = phipf[i];
	hlt_sie[cand] = sieiepf[i];
	hlt_eca[cand] = ecalpf[i];
	hlt_dph[cand] = dphipf[i];
	hlt_det[cand] = detapf[i];
	hlt_des[cand] = detaseedpf[i];
	hlt_hoe[cand] = hoepf[i];
	hlt_hca[cand] = hcalpf[i];
	hlt_tks[cand] = tkisopf[i];
	hlt_eop[cand] = eoppf[i];
	hlt_esp[cand] = eopseedpf[i];
	hlt_ps2[cand] = ps2pf[i];
	hlt_chi[cand] = chi2pf[i];
        hlt_mih[cand] = (double) mishitspf[i];

        if (checkCand("WPTight16", -1, rho,
                       hlt_e[cand], hlt_et[cand], hlt_eta[cand], hlt_phi[cand],
                       hlt_sie[cand], hlt_hoe[cand], hlt_eca[cand], hlt_hca[cand], hlt_eop[cand],
                       hlt_chi[cand], hlt_mih[cand], hlt_des[cand], hlt_dph[cand], hlt_tks[cand]))
          passHLT[cand] = 1;

        if (isMC) {
          double drmax = 0.1;
          for (int j = 0; j < gp_n; j++) {

            double dr = deltaR(hlt_eta[cand], hlt_phi[cand], gp_eta[j], gp_phi[j]);
            if (dr < drmax) {
              genMatch[cand] = 1;
              break;
            }
          }
        }

        cand++;
      }

      hlt_n = cand;
      if (hlt_n < 2) continue;

      if (hasReco) {
        for (int k = 0; k < reco_n; k++) {
          reco_er[k] = reco_eRaw[k];
          reco_etr[k] = reco_etRaw[k];
          reco_sie[k] = reco_sieie[k];
          reco_eca[k] = reco_ecal[k];
          reco_dph[k] = std::abs(reco_dphi[k]);
          reco_det[k] = std::abs(reco_deta[k]);
          reco_des[k] = std::abs(reco_detaseed[k]);
          reco_eop[k] = std::abs(reco_eop[k]);
          reco_hca[k] = reco_hcal[k];
          reco_tks[k] = reco_tkiso[k];
          reco_chi[k] = reco_chi2[k];
          reco_mih[k] = (double) reco_mishits[k];
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
