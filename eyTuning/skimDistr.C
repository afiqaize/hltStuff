// Updated version of makeDistr.C that performs some initial skimming too

#include "TFile.h"
#include "TTree.h"
#include "TMath.h"
#include "TROOT.h"

Bool_t barWPLoose(Float_t sie_cut_b, Float_t hoe_cut_b, Float_t eca_cut_b, Float_t hca_cut_b, 
                  Float_t eop_cut_b, Float_t chi_cut_b, Float_t mih_cut_b, 
                  Float_t det_cut_b, Float_t dph_cut_b, Float_t tki_cut_b) {

  Bool_t barOk = false;

  // All barrel cuts

  if (sie_cut_b <= 0.011) {
    if (hoe_cut_b <= 0.06) {
      if (eca_cut_b <= 0.15) {
        if (hca_cut_b <= 0.15) {
          if (eop_cut_b <= 0.012) {
            if (dph_cut_b <= .02) {
              if (det_cut_b <= .004) {
                if (tki_cut_b <= 0.08) {
                  if (mih_cut_b <= 999.) { // careful at these not 1.0 cuts
                    if (chi_cut_b <= 999.)
                      barOk = true;

                  }
                }
              }
            }
          }
        }
      }
    }
  }

  return barOk;

}

Bool_t endWPLoose(Float_t sie_cut_e, Float_t hoe_cut_e, Float_t eca_cut_e, Float_t hca_cut_e, 
                  Float_t eop_cut_e, Float_t chi_cut_e, Float_t mih_cut_e,
                  Float_t det_cut_e, Float_t dph_cut_e, Float_t tki_cut_e) {

  Bool_t endOk = false;

  // All endcap cuts

  if (sie_cut_e <= 0.032) {
    if (hoe_cut_e <= 0.065) {
      if (eca_cut_e <= 0.15) {
        if (hca_cut_e <= 0.16) {
          if (eop_cut_e <= 0.01) {
            if (dph_cut_e <= 999.) {
              if (det_cut_e <= 999.) {
                if (tki_cut_e <= 0.08) {
                  if (mih_cut_e <= 2.5) { // careful at these not 1.0 cuts
                    if (chi_cut_e <= 2.8)
                      endOk = true;

                  }
                }
              }
            }
          }
        }
      }
    }
  }

  return endOk;

}

Bool_t notFake(Float_t sie_cut_b, Float_t hoe_cut_b, Float_t eca_cut_b, Float_t hca_cut_b, 
               Float_t eop_cut_b, Float_t chi_cut_b, Float_t mih_cut_b, 
               Float_t det_cut_b, Float_t dph_cut_b, Float_t tki_cut_b) {

  Bool_t candOk = false;

  if (sie_cut_b <= 999.0) {
    if (hoe_cut_b <= 999.0) {
      if (eca_cut_b <= 999.0) {
        if (hca_cut_b <= 999.0) {
          if (eop_cut_b <= 999.0) {
            if (dph_cut_b <= 999.0) {
              if (det_cut_b <= 999.0) {
                if (tki_cut_b <= 999.0) {
                  if (mih_cut_b <= 999.0) {
                    if (chi_cut_b <= 999.0)
                      candOk = true;

                  }
                }
              }
            }
          }
        }
      }
    }
  }

  return candOk;

}
 
void skimDistr() {

  const string inDir = "/home/ieeya/Downloads/HLT_Val/dev/e_74x/file/v15p1/";
  const string outputFile = "skim_dat.root";

  Bool_t hasReco = false;

  TFile* out_file = new TFile((inDir + outputFile).c_str(), "recreate");
  TTree* out_tree = new TTree("eleDistr", "eleDistr");
  out_tree->SetAutoSave(25000000);

  Int_t cand, npf, hlt_n, reco_n, nvtx, gpn, itype, pass[10], mishitspf[10], reco_mishits[10];
  Float_t rho, puWgt, weight, epf[10], eRawpf[10], etpf[10], etRawpf[10], etapf[10], phipf[10], sieiepf[10];
  Float_t ecalpf[10], dphipf[10], detapf[10], detaseedpf[10], hoepf[10], hcalpf[10];
  Float_t tkisopf[10], eoppf[10], gppt[10], gpeta[10], gpphi[10], chi2pf[10];
  Float_t reco_e[10], reco_et[10], reco_eRaw[10], reco_etRaw[10], reco_pt[10], reco_eta[10], reco_phi[10];
  Float_t reco_sieie[10], reco_hoe[10], reco_ecal[10], reco_dphi[10], reco_deta[10], reco_detaseed[10];
  Float_t reco_hcal[10], reco_tkiso[10], reco_eop[10], reco_chi2[10];


  Float_t hlt_e[10], hlt_er[10], hlt_et[10], hlt_etr[10], hlt_eta[10], hlt_phi[10], hlt_hoe[10];
  Float_t hlt_sie[10], hlt_dph[10], hlt_det[10], hlt_des[10], hlt_eop[10], hlt_chi[10], hlt_mih[10];
  Float_t hlt_eca[10], hlt_ecc[10], hlt_ecu[10], hlt_hca[10], hlt_hcc[10], hlt_hcu[10], hlt_tki[10];
  Float_t reco_er[10], reco_etr[10], reco_sie[10],  reco_dph[10], reco_det[10], reco_des[10];
  Float_t reco_eca[10], reco_ecu[10], reco_hca[10], reco_hcu[10], reco_tki[10], reco_chi[10], reco_mih[10];

  out_tree->Branch("nvtx", &nvtx, "nvtx/I");
  out_tree->Branch("rho" , &rho, "rho/F");
  out_tree->Branch("puWgt", &puWgt, "puWgt/F");

  out_tree->Branch("hlt_n" , &hlt_n, "hlt_n/I");
  out_tree->Branch("hlt_e"   , hlt_e, "hlt_e[hlt_n]/F");
  out_tree->Branch("hlt_er"   , hlt_er, "hlt_er[hlt_n]/F");
  out_tree->Branch("hlt_et"   , hlt_et, "hlt_et[hlt_n]/F");
  out_tree->Branch("hlt_etr"   , hlt_etr, "hlt_etr[hlt_n]/F");
  out_tree->Branch("hlt_eta"  , hlt_eta, "hlt_eta[hlt_n]/F");
  out_tree->Branch("hlt_phi"  , hlt_phi, "hlt_phi[hlt_n]/F");
  out_tree->Branch("hlt_sie", hlt_sie, "hlt_sie[hlt_n]/F");
  out_tree->Branch("hlt_eca" , hlt_eca, "hlt_eca[hlt_n]/F");
  out_tree->Branch("hlt_ecc" , hlt_ecc, "hlt_ecc[hlt_n]/F");
  out_tree->Branch("hlt_ecu" , hlt_ecu, "hlt_ecu[hlt_n]/F");
  out_tree->Branch("hlt_dph" , hlt_dph, "hlt_dph[hlt_n]/F");
  out_tree->Branch("hlt_det" , hlt_det, "hlt_det[hlt_n]/F");
  out_tree->Branch("hlt_des" , hlt_des, "hlt_des[hlt_n]/F");
  out_tree->Branch("hlt_hoe"  , hlt_hoe, "hlt_hoe[hlt_n]/F");
  out_tree->Branch("hlt_hca" , hlt_hca, "hlt_hca[hlt_n]/F");
  out_tree->Branch("hlt_hcc" , hlt_hcc, "hlt_hcc[hlt_n]/F");
  out_tree->Branch("hlt_hcu" , hlt_hcu, "hlt_hcu[hlt_n]/F");
  out_tree->Branch("hlt_tki", hlt_tki, "hlt_tki[hlt_n]/F");
  out_tree->Branch("hlt_eop"  , hlt_eop, "hlt_eop[hlt_n]/F");
  out_tree->Branch("hlt_chi" , hlt_chi, "hlt_chi[hlt_n]/F");
  out_tree->Branch("hlt_mih" , hlt_mih, "hlt_mih[hlt_n]/F");
  out_tree->Branch("pass_hlt" , pass, "pass_hlt[hlt_n]/I");
  out_tree->Branch("itype"  , &itype, "itype/I");
  out_tree->Branch("weight" , &weight, "weight/F");

  if (hasReco) {

    out_tree->Branch("reco_n"   , &reco_n, "reco_n/I");
    out_tree->Branch("reco_e"   , reco_e, "reco_e[reco_n]/F");
    out_tree->Branch("reco_et"   , reco_et, "reco_et[reco_n]/F");
    out_tree->Branch("reco_er"   , reco_er, "reco_er[reco_n]/F");
    out_tree->Branch("reco_etr"   , reco_etr, "reco_etr[reco_n]/F");
    out_tree->Branch("reco_pt"   , reco_pt, "reco_pt[reco_n]/F");
    out_tree->Branch("reco_eta"  , reco_eta, "reco_eta[reco_n]/F");
    out_tree->Branch("reco_phi"  , reco_phi, "reco_phi[reco_n]/F");
    out_tree->Branch("reco_sie", reco_sie, "reco_sie[reco_n]/F");
    out_tree->Branch("reco_eca" , reco_eca, "reco_eca[reco_n]/F");
    out_tree->Branch("reco_ecu" , reco_ecu, "reco_ecu[reco_n]/F");
    out_tree->Branch("reco_dph" , reco_dph, "reco_dph[reco_n]/F");
    out_tree->Branch("reco_det" , reco_det, "reco_det[reco_n]/F");
    out_tree->Branch("reco_des" , reco_des, "reco_des[reco_n]/F");
    out_tree->Branch("reco_hoe"  , reco_hoe, "reco_hoe[reco_n]/F");
    out_tree->Branch("reco_hca" , reco_hca, "reco_hca[reco_n]/F");
    out_tree->Branch("reco_hcu" , reco_hcu, "reco_hcu[reco_n]/F");
    out_tree->Branch("reco_tki", reco_tki, "reco_tki[reco_n]/F");
    out_tree->Branch("reco_eop"  , reco_eop, "reco_eop[reco_n]/F");
    out_tree->Branch("reco_chi" , reco_chi, "reco_chi[reco_n]/F");
    out_tree->Branch("reco_mih" , reco_mih, "reco_mih[reco_n]/F");

  }
  
  // MC vs data: weight = xsec_mc * intLumi_dat / nEvt_mc
  const int proc = 1;
  const int type[proc] = {1};
  const float weights[proc] = {1.};
  const char* names[proc] = {"ntup_dat_00.root"};

  //const Int_t proc = 2;
  //const Int_t type[proc] = {-1, -2};
  //const Float_t weights[proc] = {1., 1.};
  //const char* names[proc] = {"ntup_mcStd.root", "ntup_mcHFFlat.root"};

  //const int proc = 1;
  //const int type[proc] = {1};
  //const float weights[proc] = {1.};
  //const char* names[proc] = {"reco_pts2c1.root"};
    
  for (Int_t nfiles = 0; nfiles < proc; nfiles++) {
  
    TFile* file = TFile::Open((inDir + names[nfiles]).c_str());
    TTree* inputTree = (TTree*)file->Get("tree");

    inputTree->SetBranchStatus("*"          , 0);
    inputTree->SetBranchStatus("npf"        , 1);
    inputTree->SetBranchStatus("nvtx"       , 1);
    inputTree->SetBranchStatus("rho"        , 1);
    //inputTree->SetBranchStatus("puWgt"      , 1);
    inputTree->SetBranchStatus("epf"        , 1);
    inputTree->SetBranchStatus("eRawpf"     , 1);
    inputTree->SetBranchStatus("etpf"       , 1);
    inputTree->SetBranchStatus("etRawpf"    , 1);
    inputTree->SetBranchStatus("etapf"      , 1);
    inputTree->SetBranchStatus("phipf"      , 1);
    inputTree->SetBranchStatus("sieiepf"    , 1);
    inputTree->SetBranchStatus("ecalpf"     , 1);
    inputTree->SetBranchStatus("dphipf"     , 1);
    inputTree->SetBranchStatus("detapf"     , 1);
    inputTree->SetBranchStatus("detaseedpf" , 1);
    inputTree->SetBranchStatus("hoepf"      , 1);
    inputTree->SetBranchStatus("hcalpf"     , 1);
    inputTree->SetBranchStatus("tkisopf"    , 1);
    inputTree->SetBranchStatus("eoppf"      , 1);
    inputTree->SetBranchStatus("chi2pf"     , 1);
    inputTree->SetBranchStatus("mishitspf"  , 1);

    inputTree->SetBranchAddress("npf"        , &npf);
    inputTree->SetBranchAddress("nvtx"       , &nvtx);
    inputTree->SetBranchAddress("rho"        , &rho);
    //inputTree->SetBranchAddress("puWgt"      , &puWgt);
    inputTree->SetBranchAddress("epf"        , epf);
    inputTree->SetBranchAddress("eRawpf"     , eRawpf);
    inputTree->SetBranchAddress("etpf"       , etpf);
    inputTree->SetBranchAddress("etRawpf"    , etRawpf);
    inputTree->SetBranchAddress("etapf"      , etapf);
    inputTree->SetBranchAddress("phipf"      , phipf);
    inputTree->SetBranchAddress("sieiepf"    , sieiepf);
    inputTree->SetBranchAddress("ecalpf"     , ecalpf);
    inputTree->SetBranchAddress("dphipf"     , dphipf);
    inputTree->SetBranchAddress("detapf"     , detapf);
    inputTree->SetBranchAddress("detaseedpf" , detaseedpf);
    inputTree->SetBranchAddress("hoepf"      , hoepf);
    inputTree->SetBranchAddress("hcalpf"     , hcalpf);
    inputTree->SetBranchAddress("tkisopf"    , tkisopf);
    inputTree->SetBranchAddress("eoppf"      , eoppf);
    inputTree->SetBranchAddress("chi2pf"     , chi2pf);
    inputTree->SetBranchAddress("mishitspf"  , mishitspf);

    if (hasReco) {

      inputTree->SetBranchStatus("reco_n"        , 1);
      inputTree->SetBranchStatus("reco_e"        , 1);
      inputTree->SetBranchStatus("reco_et"       , 1);
      inputTree->SetBranchStatus("reco_eRaw"     , 1);
      inputTree->SetBranchStatus("reco_etRaw"    , 1);
      inputTree->SetBranchStatus("reco_pt"       , 1);
      inputTree->SetBranchStatus("reco_eta"      , 1);
      inputTree->SetBranchStatus("reco_phi"      , 1);
      inputTree->SetBranchStatus("reco_sieie"    , 1);
      inputTree->SetBranchStatus("reco_ecal"     , 1);
      inputTree->SetBranchStatus("reco_dphi"     , 1);
      inputTree->SetBranchStatus("reco_deta"     , 1);
      inputTree->SetBranchStatus("reco_detaseed" , 1);
      inputTree->SetBranchStatus("reco_hoe"      , 1);
      inputTree->SetBranchStatus("reco_hcal"     , 1);
      inputTree->SetBranchStatus("reco_tkiso"    , 1);
      inputTree->SetBranchStatus("reco_eop"      , 1);
      inputTree->SetBranchStatus("reco_chi2"     , 1);
      inputTree->SetBranchStatus("reco_mishits"  , 1);

      inputTree->SetBranchAddress("reco_n"        , &reco_n);
      inputTree->SetBranchAddress("reco_e"        , reco_e);
      inputTree->SetBranchAddress("reco_et"       , reco_et);
      inputTree->SetBranchAddress("reco_eRaw"     , reco_eRaw);
      inputTree->SetBranchAddress("reco_etRaw"    , reco_etRaw);
      inputTree->SetBranchAddress("reco_pt"       , reco_pt);
      inputTree->SetBranchAddress("reco_eta"      , reco_eta);
      inputTree->SetBranchAddress("reco_phi"      , reco_phi);
      inputTree->SetBranchAddress("reco_sieie"    , reco_sieie);
      inputTree->SetBranchAddress("reco_ecal"     , reco_ecal);
      inputTree->SetBranchAddress("reco_dphi"     , reco_dphi);
      inputTree->SetBranchAddress("reco_deta"     , reco_deta);
      inputTree->SetBranchAddress("reco_detaseed" , reco_detaseed);
      inputTree->SetBranchAddress("reco_hoe"      , reco_hoe);
      inputTree->SetBranchAddress("reco_hcal"     , reco_hcal);
      inputTree->SetBranchAddress("reco_tkiso"    , reco_tkiso);
      inputTree->SetBranchAddress("reco_eop"      , reco_eop);
      inputTree->SetBranchAddress("reco_chi2"     , reco_chi2);
      inputTree->SetBranchAddress("reco_mishits"  , reco_mishits);

    }
    
    Int_t entries = inputTree->GetEntries();
 
    for (Int_t z = 0; z < entries; z++) {
      inputTree->GetEntry(z);
   
      itype = type[nfiles];
      weight = weights[nfiles];
      puWgt = 1.;
      cand = 0;

      for (Int_t i = 0; i < npf; i++) {

        if(!notFake(sieiepf[i], (hoepf[i] / epf[i]),
                    (ecalpf[i] / etpf[i]), (hcalpf[i] / etpf[i]),
                    eoppf[i], chi2pf[i], (Float_t) mishitspf[i],
                    detapf[i], dphipf[i], (tkisopf[i] / etpf[i]))) continue;

        pass[cand] = 0;

	hlt_e[cand] = epf[i];
	hlt_er[cand] = eRawpf[i];
	hlt_et[cand] = etpf[i];
	hlt_etr[cand] = etRawpf[i];
	hlt_eta[cand] = etapf[i];
	hlt_phi[cand] = phipf[i];
	hlt_sie[cand] = sieiepf[i];
	hlt_ecc[cand] = ecalpf[i] / etpf[i];
	hlt_dph[cand] = dphipf[i];
	hlt_det[cand] = detapf[i];
	hlt_des[cand] = detaseedpf[i];
	hlt_hoe[cand] = hoepf[i] / epf[i];
	hlt_hcc[cand] = hcalpf[i] / etpf[i];
	hlt_tki[cand] = tkisopf[i] / etpf[i];
	hlt_eop[cand] = eoppf[i];
	hlt_chi[cand] = chi2pf[i];
        hlt_mih[cand] = (Float_t) mishitspf[i];

        if (fabs(hlt_eta[cand]) < 1.4791) {

          if(barWPLoose(hlt_sie[cand], hlt_hoe[cand], hlt_ecc[cand], hlt_hcc[cand], hlt_eop[cand], hlt_chi[cand], hlt_mih[cand], hlt_det[cand], hlt_dph[cand], hlt_tki[cand]))
            pass[cand] = 1;

          // Recompute the non-corr iso
          hlt_ecu[cand] = (ecalpf[i] + (0.16544 * rho)) / etpf[i];
          hlt_hcu[cand] = (hcalpf[i] + (0.05956 * rho)) / etpf[i];

        }

        else if (fabs(hlt_eta[cand]) >= 1.4791) {

          if(endWPLoose(hlt_sie[cand], hlt_hoe[cand], hlt_ecc[cand], hlt_hcc[cand], hlt_eop[cand], hlt_chi[cand], hlt_mih[cand], hlt_det[cand], hlt_dph[cand], hlt_tki[cand]))
            pass[cand] = 1;

          // Recompute the non-corr iso
          hlt_ecu[cand] = (ecalpf[i] + (0.13212 * rho)) / etpf[i];
          hlt_hcu[cand] = (hcalpf[i] + (0.13052 * rho)) / etpf[i];

        }

        hlt_eca[cand] = hlt_ecc[cand] * etpf[i];
        hlt_hca[cand] = hlt_hcc[cand] * etpf[i];

        cand++;

      }

      hlt_n = cand;

      if (hasReco) {

        for (Int_t j = 0; j < reco_n; j++) {

          reco_er[j] = reco_eRaw[j];
          reco_etr[j] = reco_etRaw[j];
          reco_sie[j] = reco_sieie[j];
          reco_eca[j] = reco_ecal[j];
          reco_ecu[j] = reco_ecal[j] / reco_et[j];
          reco_dph[j] = fabs(reco_dphi[j]);
          reco_det[j] = fabs(reco_deta[j]);
          reco_des[j] = fabs(reco_detaseed[j]);
          reco_eop[j] = fabs(reco_eop[j]);
          reco_hca[j] = reco_hcal[j];
          reco_hcu[j] = reco_hcal[j] / reco_et[j];
          reco_tki[j] = reco_tkiso[j] / reco_et[j];
          reco_chi[j] = reco_chi2[j];
          reco_mih[j] = (Float_t) reco_mishits[j];

        }
      }

      out_tree->Fill();

    }
  }
  
  out_file->cd();
  out_tree->Write();
  out_file->Close();

  gROOT->ProcessLine(".q");

}
