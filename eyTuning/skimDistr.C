// Updated version of makeDistr.C that performs some initial skimming
// Jan 14: Added accPath cut to reject failing events and bugfixes

#include "TFile.h"
#include "TTree.h"
#include "TMath.h"
#include "TROOT.h"

Bool_t barWPLoose(Float_t sie_cut_b, Float_t hoe_cut_b, Float_t ecc_cut_b, Float_t hcc_cut_b, 
                  Float_t eop_cut_b, Float_t chi_cut_b, Float_t mih_cut_b, 
                  Float_t det_cut_b, Float_t dph_cut_b, Float_t tki_cut_b) {

  Bool_t barOk = false;

  // All barrel cuts

  if (sie_cut_b <= 0.011) {
    if (hoe_cut_b <= 0.06) {
      if (ecc_cut_b <= 0.15) {
        if (hcc_cut_b <= 0.15) {
          if (eop_cut_b <= 0.012) {
            if (dph_cut_b <= .02) {
              if (det_cut_b <= .004) {
                if (tki_cut_b <= 0.08) {
                  if (mih_cut_b <= 99.) { // careful at these not 1.0 cuts
                    if (chi_cut_b <= 99.)
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

Bool_t endWPLoose(Float_t sie_cut_e, Float_t hoe_cut_e, Float_t ecc_cut_e, Float_t hcc_cut_e, 
                  Float_t eop_cut_e, Float_t chi_cut_e, Float_t mih_cut_e,
                  Float_t det_cut_e, Float_t dph_cut_e, Float_t tki_cut_e) {

  Bool_t endOk = false;

  // All endcap cuts

  if (sie_cut_e <= 0.032) {
    if (hoe_cut_e <= 0.065) {
      if (ecc_cut_e <= 0.15) {
        if (hcc_cut_e <= 0.16) {
          if (eop_cut_e <= 0.01) {
            if (dph_cut_e <= 99.) {
              if (det_cut_e <= 99.) {
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

Bool_t notFake(Float_t sie_cut, Float_t hoe_cut, Float_t ecc_cut, Float_t hcc_cut, 
               Float_t eop_cut, Float_t chi_cut, Float_t mih_cut, 
               Float_t det_cut, Float_t dph_cut, Float_t tki_cut) {

  Bool_t candOk = false;

  if (sie_cut <= 99.) {
    if (hoe_cut <= 99.) {
      if (ecc_cut <= 99.) {
        if (hcc_cut <= 99.) {
          if (eop_cut <= 99.) {
            if (dph_cut <= 99.) {
              if (det_cut <= 99.) {
                if (tki_cut <= 99.) {
                  if (mih_cut <= 99.) {
                    if (chi_cut <= 99.)
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

  const string inDir = "/home/ieeya/Downloads/HLT_Val/dev/e_80x/file/v0p4/";
  const string outputFile = "dyll_m3Full.root";

  Bool_t hasReco = false;

  TFile* outFile = new TFile((inDir + outputFile).c_str(), "recreate");
  TTree* outTree = new TTree("eleDistr", "eleDistr");
  outTree->SetAutoSave(500000000);

  Int_t cand, npf, hlt_n, reco_n, nVtx, nRun, nEvt, nLumi, accPath, itype; 
  Int_t pass[10], mishitspf[10], reco_mishits[10];
  Float_t rho, puWgt, weight, epf[10], eRawpf[10], etpf[10], etRawpf[10], etapf[10], phipf[10];
  Float_t sieiepf[10], dphipf[10], detapf[10], detaseedpf[10], hoepf[10];
  Float_t ecalpf[10], hcalpf[10], tkisopf[10], eoppf[10], chi2pf[10];
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
  outTree->Branch("pass_hlt" , pass, "pass_hlt[hlt_n]/I");
  outTree->Branch("itype"  , &itype, "itype/I");
  outTree->Branch("weight" , &weight, "weight/F");

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
  //const int proc = 2;
  //const int type[proc] = {3, 3};
  //const float weights[proc] = {1., 1.};
  //const char* names[proc] = {"dat_full_8.root", "dat_full_9.root"};
  //const int type[proc] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
  //const float weights[proc] = {1., 1., 1., 1., 1., 1., 1., 1., 1., 1.};
  //const char* names[proc] = {"dat_full_0.root", "dat_full_1.root", "dat_full_2.root", "dat_full_3.root", "dat_full_4.root", "dat_full_5.root", "dat_full_6.root", "dat_full_7.root", "dat_full_8.root", "dat_full_9.root"};

  const Int_t proc = 1;
  const Int_t type[proc] = {-3};
  const Float_t weights[proc] = {2.576871};
  const char* names[proc] = {"dyll_wFull.root"};

  //const int proc = 1;
  //const int type[proc] = {1};
  //const float weights[proc] = {1.};
  //const char* names[proc] = {"reco_pts2c1.root"};
    
  for (Int_t nfiles = 0; nfiles < proc; nfiles++) {
  
    TFile* file = TFile::Open((inDir + names[nfiles]).c_str());
    TTree* inTree = (TTree*)file->Get("tree");

    inTree->SetBranchStatus("*"          , 0);
    inTree->SetBranchStatus("nRun"       , 1);
    inTree->SetBranchStatus("nEvt"       , 1);
    inTree->SetBranchStatus("nLumi"      , 1);
    inTree->SetBranchStatus("accPath"    , 1);
    inTree->SetBranchStatus("npf"        , 1);
    inTree->SetBranchStatus("nVtx"       , 1);
    inTree->SetBranchStatus("rho"        , 1);
    inTree->SetBranchStatus("puWgt"      , 1);
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
    inTree->SetBranchAddress("puWgt"      , &puWgt);
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

      // check triggering of event first
      if (accPath != 1) continue;

      itype = type[nfiles];
      weight = weights[nfiles];
      //puWgt = 1.;
      cand = 0;

      for (Int_t i = 0; i < npf; i++) {

        if(!notFake(sieiepf[i], (hoepf[i] / epf[i]),
                    (ecalpf[i] / etpf[i]), (hcalpf[i] / etpf[i]),
                    eoppf[i], chi2pf[i], (Float_t) mishitspf[i],
                    detapf[i], dphipf[i], (tkisopf[i] / etpf[i]))) continue;

        pass[cand] = 0;

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

        if (fabs(hlt_eta[cand]) < 1.4791) {

          if(barWPLoose(hlt_sie[cand], hlt_hoe[cand], hlt_ecc[cand], hlt_hcc[cand], hlt_eop[cand], hlt_chi[cand], hlt_mih[cand], hlt_det[cand], hlt_dph[cand], hlt_tki[cand]))
            pass[cand] = 1;

          // Recompute the non-corr iso
          hlt_ecu[cand] = (hlt_eca[cand] + (0.16544 * rho));
          hlt_hcu[cand] = (hlt_hca[cand] + (0.05956 * rho));

        }

        else if (fabs(hlt_eta[cand]) >= 1.4791) {

          if(endWPLoose(hlt_sie[cand], hlt_hoe[cand], hlt_ecc[cand], hlt_hcc[cand], hlt_eop[cand], hlt_chi[cand], hlt_mih[cand], hlt_det[cand], hlt_dph[cand], hlt_tki[cand]))
            pass[cand] = 1;

          // Recompute the non-corr iso
          hlt_ecu[cand] = (hlt_eca[cand] + (0.13212 * rho));
          hlt_hcu[cand] = (hlt_hca[cand] + (0.13052 * rho));

        }

        cand++;

      }

      hlt_n = cand;
      if (hlt_n == 0) continue;

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

      outTree->Fill();

    }
  }
  
  outFile->cd();
  outTree->Write();
  outFile->Close();

  gROOT->ProcessLine(".q");

}
