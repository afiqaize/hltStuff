// For drawing ID resolution from the TnP ntuple
// Usage: root -l -b tnpRes.cxx++

#include "TFile.h"
#include "TChain.h"
#include "TTree.h"
#include "TROOT.h"
#include "TBufferFile.h"
#include "TLorentzVector.h"

#include "hltWP.cxx"
#include "/home/afiqaize/root53434/macros/tdrstyle.C"

double calcRes(double vHlt, double vOff) {
  double vRes = 999999.;

  if (vHlt != 0. and vOff != 0.) vRes = (vHlt - vOff) / vOff;
  return vRes;
}

void tnpRes() {
   gROOT->Reset();

   setTDRStyle();

   // Everything to tinker with should be here
   std::string vName, outPre;
   outPre = "r_m5p2";

   // -------------------------------------------------- //

   const int etaResB_nBin = 100, etaResE_nBin = 100;
   const double etaResB_max = 0.01, etaResE_max = 0.01;
   const double etaResB_min = -0.01, etaResE_min = -0.01;

   const int phiResB_nBin = 100, phiResE_nBin = 100;
   const double phiResB_max = 0.01, phiResE_max = 0.01;
   const double phiResB_min = -0.01, phiResE_min = -0.01;

   // For Et
   const int eetResB_nBin = 100, eetResE_nBin = 100;
   const double eetResB_max = 0.5, eetResE_max = 0.5;
   const double eetResB_min = -0.5, eetResE_min = -0.5;

   const int sieResB_nBin = 100, sieResE_nBin = 100;
   const double sieResB_max = 0.2, sieResE_max = 0.2;
   const double sieResB_min = -0.2, sieResE_min = -0.2;

   // For H/E
   const int hoeResB_nBin = 100, hoeResE_nBin = 100;
   const double hoeResB_max = 1.0, hoeResE_max = 1.0;
   const double hoeResB_min = -1.0, hoeResE_min = -1.0;

   const int ecaResB_nBin = 120, ecaResE_nBin = 120;
   const double ecaResB_max = 5.0, ecaResE_max = 5.0;
   const double ecaResB_min = -1.0, ecaResE_min = -1.0;

   const int hcaResB_nBin = 120, hcaResE_nBin = 120;
   const double hcaResB_max = 5.0, hcaResE_max = 5.0;
   const double hcaResB_min = -1.0, hcaResE_min = -1.0;

   const int eopResB_nBin = 120, eopResE_nBin = 120;
   const double eopResB_max = 5.0, eopResE_max = 5.0;
   const double eopResB_min = -1.0, eopResE_min = -1.0;

   const int chiResB_nBin = 100, chiResE_nBin = 100;
   const double chiResB_max = 3.0, chiResE_max = 3.0;
   const double chiResB_min = -1.0, chiResE_min = -1.0;

   const int mihResB_nBin = 5, mihResE_nBin = 5;
   const double mihResB_max = 2.5, mihResE_max = 2.5;
   const double mihResB_min = -2.5, mihResE_min = -2.5;

   const int desResB_nBin = 100, desResE_nBin = 100;
   const double desResB_max = 3.0, desResE_max = 3.0;
   const double desResB_min = -1.0, desResE_min = -1.0;

   const int dphResB_nBin = 100, dphResE_nBin = 100;
   const double dphResB_max = 3.0, dphResE_max = 3.0;
   const double dphResB_min = -1.0, dphResE_min = -1.0;

   const int tksResB_nBin = 100, tksResE_nBin = 100;
   const double tksResB_max = 1.0, tksResE_max = 1.0;
   const double tksResB_min = -1.0, tksResE_min = -1.0;

   const int lolResB_nBin = 100, lolResE_nBin = 100;
   const double lolResB_max = 1.0, lolResE_max = 1.0;
   const double lolResB_min = -1.0, lolResE_min = -1.0;

   // -------------------------------------------------- //

   const int nH = 6;

   std::pair <std::string, std::string> pairFileLeg[nH];
   pairFileLeg[0] = std::make_pair("m5p2_fastBDED", "EB 15 EE 10");
   pairFileLeg[1] = std::make_pair("m5p2_fastB1E1", "EB 1 EE 1");
   pairFileLeg[2] = std::make_pair("m5p2_fastB2E2", "EB 2 EE 2");
   pairFileLeg[3] = std::make_pair("m5p2_fastB5E5", "EB 5 EE 5");
   pairFileLeg[4] = std::make_pair("m5p2_fastB7E7", "EB 7 EE 7");
   pairFileLeg[5] = std::make_pair("m5p2_full", "No prefit");

   TH1::SetDefaultSumw2(true);
   TH1D *eta_b[nH], *eta_e[nH], *phi_b[nH], *phi_e[nH], *eet_b[nH], *eet_e[nH];
   TH1D *sie_b[nH], *sie_e[nH], *hoe_b[nH], *hoe_e[nH];
   TH1D *eca_b[nH], *eca_e[nH], *hca_b[nH], *hca_e[nH];
   TH1D *eop_b[nH], *eop_e[nH], *chi_b[nH], *chi_e[nH], *mih_b[nH], *mih_e[nH];
   TH1D *des_b[nH], *des_e[nH], *dph_b[nH], *dph_e[nH], *tks_b[nH], *tks_e[nH];
   TH1D *lol_b[nH], *lol_e[nH];

   int kCols[nH] = {kBlack, kSpring - 3, kAzure - 3, kOrange - 3, kPink - 3, kViolet - 3};
   int kColor, kFill, kMark;
   for (int iH = 0; iH < nH; iH++) {
     kColor = kCols[iH];
     kFill = 0; kMark = 20 + iH;

     eta_b[iH] = new TH1D(("eta_ResB_" + toStr(iH)).c_str(), "#eta Resolution", etaResB_nBin, etaResB_min, etaResB_max);
     eta_e[iH] = new TH1D(("eta_ResE_" + toStr(iH)).c_str(), "#eta Resolution", etaResE_nBin, etaResE_min, etaResE_max);
     styleHist(eta_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(eta_e[iH], kColor, kFill, kMark, 1, 2.0);

     phi_b[iH] = new TH1D(("phi_ResB_" + toStr(iH)).c_str(), "#phi Resolution", phiResB_nBin, phiResB_min, phiResB_max);
     phi_e[iH] = new TH1D(("phi_ResE_" + toStr(iH)).c_str(), "#phi Resolution", phiResE_nBin, phiResE_min, phiResE_max);
     styleHist(phi_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(phi_e[iH], kColor, kFill, kMark, 1, 2.0);

     eet_b[iH] = new TH1D(("eet_ResB_" + toStr(iH)).c_str(), "E_{T} Resolution", eetResB_nBin, eetResB_min, eetResB_max);
     eet_e[iH] = new TH1D(("eet_ResE_" + toStr(iH)).c_str(), "E_{T} Resolution", eetResE_nBin, eetResE_min, eetResE_max);
     styleHist(eet_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(eet_e[iH], kColor, kFill, kMark, 1, 2.0);

     siResE_b[iH] = new TH1D(("siResE_ResB_" + toStr(iH)).c_str(), "Cluster Shape Resolution", sieResB_nBin, sieResB_min, sieResB_max);
     siResE_e[iH] = new TH1D(("siResE_ResE_" + toStr(iH)).c_str(), "Cluster Shape Resolution", sieResE_nBin, sieResE_min, sieResE_max);
     styleHist(siResE_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(siResE_e[iH], kColor, kFill, kMark, 1, 2.0);

     hoResE_b[iH] = new TH1D(("hoResE_ResB_" + toStr(iH)).c_str(), "Hadronic / EM Resolution", hoeResB_nBin, hoeResB_min, hoeResB_max);
     hoResE_e[iH] = new TH1D(("hoResE_ResE_" + toStr(iH)).c_str(), "Hadronic / EM Resolution", hoeResE_nBin, hoeResE_min, hoeResE_max);
     styleHist(hoResE_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(hoResE_e[iH], kColor, kFill, kMark, 1, 2.0);

     eca_b[iH] = new TH1D(("eca_ResB_" + toStr(iH)).c_str(), "Ecal Isolation Resolution", ecaResB_nBin, ecaResB_min, ecaResB_max);
     eca_e[iH] = new TH1D(("eca_ResE_" + toStr(iH)).c_str(), "Ecal Isolation Resolution", ecaResE_nBin, ecaResE_min, ecaResE_max);
     styleHist(eca_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(eca_e[iH], kColor, kFill, kMark, 1, 2.0);

     hca_b[iH] = new TH1D(("hca_ResB_" + toStr(iH)).c_str(), "Hcal Isolation Resolution", hcaResB_nBin, hcaResB_min, hcaResB_max);
     hca_e[iH] = new TH1D(("hca_ResE_" + toStr(iH)).c_str(), "Hcal Isolation Resolution", hcaResE_nBin, hcaResE_min, hcaResE_max);
     styleHist(hca_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(hca_e[iH], kColor, kFill, kMark, 1, 2.0);

     eop_b[iH] = new TH1D(("eop_ResB_" + toStr(iH)).c_str(), "1/E - 1/P Resolution", eopResB_nBin, eopResB_min, eopResB_max);
     eop_e[iH] = new TH1D(("eop_ResE_" + toStr(iH)).c_str(), "1/E - 1/P Resolution", eopResE_nBin, eopResE_min, eopResE_max);
     styleHist(eop_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(eop_e[iH], kColor, kFill, kMark, 1, 2.0);

     chi_b[iH] = new TH1D(("chi_ResB_" + toStr(iH)).c_str(), "Track #chi^{2} Resolution", chiResB_nBin, chiResB_min, chiResB_max);
     chi_e[iH] = new TH1D(("chi_ResE_" + toStr(iH)).c_str(), "Track #chi^{2} Resolution", chiResE_nBin, chiResE_min, chiResE_max);
     styleHist(chi_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(chi_e[iH], kColor, kFill, kMark, 1, 2.0);

     mih_b[iH] = new TH1D(("mih_ResB_" + toStr(iH)).c_str(), "Missing Hits Resolution", mihResB_nBin, mihResB_min, mihResB_max);
     mih_e[iH] = new TH1D(("mih_ResE_" + toStr(iH)).c_str(), "Missing Hits Resolution", mihResE_nBin, mihResE_min, mihResE_max);
     styleHist(mih_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(mih_e[iH], kColor, kFill, kMark, 1, 2.0);

     des_b[iH] = new TH1D(("des_ResB_" + toStr(iH)).c_str(), "Seed #Delta#eta Resolution", desResB_nBin, desResB_min, desResB_max);
     des_e[iH] = new TH1D(("des_ResE_" + toStr(iH)).c_str(), "Seed #Delta#eta Resolution", desResE_nBin, desResE_min, desResE_max);
     styleHist(des_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(des_e[iH], kColor, kFill, kMark, 1, 2.0);

     dph_b[iH] = new TH1D(("dph_ResB_" + toStr(iH)).c_str(), "SC #Delta#phi Resolution", dphResB_nBin, dphResB_min, dphResB_max);
     dph_e[iH] = new TH1D(("dph_ResE_" + toStr(iH)).c_str(), "SC #Delta#phi Resolution", dphResE_nBin, dphResE_min, dphResE_max);
     styleHist(dph_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(dph_e[iH], kColor, kFill, kMark, 1, 2.0);

     tks_b[iH] = new TH1D(("tks_ResB_" + toStr(iH)).c_str(), "Track Isolation Resolution", tksResB_nBin, tksResB_min, tksResB_max);
     tks_e[iH] = new TH1D(("tks_ResE_" + toStr(iH)).c_str(), "Track Isolation Resolution", tksResE_nBin, tksResE_min, tksResE_max);
     styleHist(tks_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(tks_e[iH], kColor, kFill, kMark, 1, 2.0);

     lol_b[iH] = new TH1D(("lol_ResB_" + toStr(iH)).c_str(), "Lolwtf Resolution", lolResB_nBin, lolResB_min, lolResB_max);
     lol_e[iH] = new TH1D(("lol_ResE_" + toStr(iH)).c_str(), "Lolwtf Resolution", lolResE_nBin, lolResE_min, lolResE_max);
     styleHist(lol_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(lol_e[iH], kColor, kFill, kMark, 1, 2.0);
   }

   // -------------------------------------------------- //


   std::string const inDir = "/home/afiqaize/Downloads/HLT/dev/e_90x/ecalIso_160317/root/";
   std::string const fName = inDir + "../plot/" + outPre + "_";

   TChain *t1 = new TChain("tnpEleTrig/fitter_tree");
   for (int iH = 0; iH < nH; iH++)
     t1->Add((inDir + pairFileLeg[iH].first + ".root").c_str());

   int nRun;
   t1->SetBranchAddress("run", &nRun);
   int nLumi;
   t1->SetBranchAddress("lumi", &nLumi);
   int nEvt;
   t1->SetBranchAddress("event", &nEvt);
   int nPV;
   t1->SetBranchAddress("event_nPV", &nPV);
   double rho;
   t1->SetBranchAddress("hlt_rho", &rho);

   int passTight;
   t1->SetBranchAddress("passTight80X", &passTight);
   int passHLT;
   t1->SetBranchAddress("passHLT", &passHLT);
   int passL1T;
   t1->SetBranchAddress("passL1T", &passL1T);
   int m60To120;
   t1->SetBranchAddress("pair_mass60to120", &m60To120);

   double hlt_et;
   t1->SetBranchAddress("probe_hlt_et", &hlt_et);
   double hlt_e;
   t1->SetBranchAddress("probe_hlt_e", &hlt_e);
   double hlt_eta;
   t1->SetBranchAddress("probe_hlt_eta", &hlt_eta);
   double hlt_phi;
   t1->SetBranchAddress("probe_hlt_phi", &hlt_phi);
   double hlt_sie;
   t1->SetBranchAddress("probe_hlt_sieie", &hlt_sie);
   double hlt_hoe;
   t1->SetBranchAddress("probe_hlt_hoe", &hlt_hoe);
   double hlt_eca;
   t1->SetBranchAddress("probe_hlt_ecalIso", &hlt_eca);
   double hlt_hca;
   t1->SetBranchAddress("probe_hlt_hcalIso", &hlt_hca);
   double hlt_eop;
   t1->SetBranchAddress("probe_hlt_ooemoop", &hlt_eop);
   double hlt_chi;
   t1->SetBranchAddress("probe_hlt_chi2", &hlt_chi);
   double hlt_mih;
   t1->SetBranchAddress("probe_hlt_mHits", &hlt_mih);
   double hlt_det;
   t1->SetBranchAddress("probe_hlt_dEtaIn", &hlt_det);
   double hlt_des;
   t1->SetBranchAddress("probe_hlt_dEtaOut", &hlt_des);
   double hlt_dph;
   t1->SetBranchAddress("probe_hlt_dPhiIn", &hlt_dph);
   double hlt_tks;
   t1->SetBranchAddress("probe_hlt_trkIso", &hlt_tks);

   double sc_et;
   t1->SetBranchAddress("probe_sc_et", &sc_et);
   double sc_e;
   t1->SetBranchAddress("probe_sc_e", &sc_e);
   double sc_eta;
   t1->SetBranchAddress("probe_sc_eta", &sc_eta);
   double sc_phi;
   t1->SetBranchAddress("probe_sc_phi", &sc_phi);

   double ele_et;
   t1->SetBranchAddress("probe_ele_et", &ele_et);
   double ele_e;
   t1->SetBranchAddress("probe_ele_e", &ele_e);
   double ele_eta;
   t1->SetBranchAddress("probe_ele_eta", &ele_eta);
   double ele_phi;
   t1->SetBranchAddress("probe_ele_phi", &ele_phi);
   double ele_sie;
   t1->SetBranchAddress("probe_ele_sieie5x5", &ele_sie);
   double ele_hoe;
   t1->SetBranchAddress("probe_ele_hoe", &ele_hoe);
   double ele_eca;
   t1->SetBranchAddress("probe_ele_ecalIso", &ele_eca);
   double ele_hca;
   t1->SetBranchAddress("probe_ele_hcalIso", &ele_hca);
   double ele_eop;
   t1->SetBranchAddress("probe_ele_ooemoop", &ele_eop);
   double ele_chi;
   t1->SetBranchAddress("probe_ele_chi2", &ele_chi);
   double ele_mih;
   t1->SetBranchAddress("probe_ele_mHits", &ele_mih);
   double ele_det;
   t1->SetBranchAddress("probe_ele_dEtaIn", &ele_det);
   double ele_des;
   t1->SetBranchAddress("probe_ele_dEtaOut", &ele_des);
   double ele_dph;
   t1->SetBranchAddress("probe_ele_dPhiIn", &ele_dph);
   double ele_tks;
   t1->SetBranchAddress("probe_ele_trkIso", &ele_tks);

   // -------------------------------------------------- //

   double finWgt = 1.;

   int nEvt1 = t1->GetEntries();
   std::cout << "nEvt1 = " << nEvt1 << std::endl;

   for (int evt1 = 0; evt1 < nEvt1; evt1++) {

     t1->GetEntry(evt1);
     if (!passL1T) continue;
     if (!m60To120) continue;
     if (std::abs(sc_eta) > etaEE) continue;

     //if (!checkCand("", -1, rho,
     //               hlt_e, hlt_et, hlt_eta, hlt_phi,
     //               hlt_sie, hlt_hoe, hlt_eca, hlt_hca, hlt_eop,
     //               hlt_chi, hlt_mih, hlt_des, hlt_dph, hlt_tks)) continue;

     std::string cFile(t1->GetCurrentFile()->GetName());

     bool isFile[nH];
     for (int iH = 0; iH < nH; iH++)
       isFile[iH] = cFile.std::string::find(pairFileLeg[iH].first) != std::string::npos;

     for (int iH = 0; iH < nH; iH++) {
       if (isFile[iH]) {
         if (std::abs(sc_eta) < etaEB) {
           eta_b[iH]->Fill( calcRes(hlt_eta, sc_eta), finWgt);
           eet_b[iH]->Fill( calcRes(hlt_et, ele_et), finWgt);
           phi_b[iH]->Fill( calcRes(hlt_phi, sc_phi), finWgt);
           sie_b[iH]->Fill( calcRes(hlt_sie, ele_sie), finWgt);
           hoe_b[iH]->Fill( calcRes(hlt_hoe, ele_hoe), finWgt);
           eca_b[iH]->Fill( calcRes(hlt_eca, ele_eca), finWgt);
           hca_b[iH]->Fill( calcRes(hlt_hca, ele_hca), finWgt);
           eop_b[iH]->Fill( calcRes(hlt_eop, std::abs(ele_eop)), finWgt);
           chi_b[iH]->Fill( calcRes(hlt_chi, ele_chi), finWgt);
           mih_b[iH]->Fill( hlt_mih - ele_mih, finWgt);
           des_b[iH]->Fill( calcRes(hlt_des, std::abs(ele_des)), finWgt);
           dph_b[iH]->Fill( calcRes(hlt_dph, std::abs(ele_dph)), finWgt);
           tks_b[iH]->Fill( calcRes(hlt_tks, ele_tks), finWgt);
         }

         if (std::abs(sc_eta) >= etaET) {
           eta_e[iH]->Fill( calcRes(hlt_eta, sc_eta), finWgt);
           eet_e[iH]->Fill( calcRes(hlt_et, ele_et), finWgt);
           phi_e[iH]->Fill( calcRes(hlt_phi, sc_phi), finWgt);
           sie_e[iH]->Fill( calcRes(hlt_sie, ele_sie), finWgt);
           hoe_e[iH]->Fill( calcRes(hlt_hoe, ele_hoe), finWgt);
           eca_e[iH]->Fill( calcRes(hlt_eca, ele_eca), finWgt);
           hca_e[iH]->Fill( calcRes(hlt_hca, ele_hca), finWgt);
           eop_e[iH]->Fill( calcRes(hlt_eop, std::abs(ele_eop)), finWgt);
           chi_e[iH]->Fill( calcRes(hlt_chi, ele_chi), finWgt);
           mih_e[iH]->Fill( hlt_mih - ele_mih, finWgt);
           des_e[iH]->Fill( calcRes(hlt_des, std::abs(ele_des)), finWgt);
           dph_e[iH]->Fill( calcRes(hlt_dph, std::abs(ele_dph)), finWgt);
           tks_e[iH]->Fill( calcRes(hlt_tks, ele_tks), finWgt);
         }
       }
     }
   }

   // -------------------------------------------------- //

   createEBEEPlot(pairFileLeg, "eca", eca_b, eca_e, nH, fName, "#sigma_{EcalIso}", "", 3, 0., 699999., 0., 299999.);

   /*
   createEBEEPlot(pairFileLeg, "eta", eta_b, eta_e, nH, fName, "#sigma_{#eta}", "", 4, 0., 15999., 0., 5999.);
   createEBEEPlot(pairFileLeg, "eet", eet_b, eet_e, nH, fName, "#sigma_{E_{T}}", "", 3, 0., 13999., 0., 2199.);
   createEBEEPlot(pairFileLeg, "phi", phi_b, phi_e, nH, fName, "#sigma_{#phi}", "", 4, 0., 13999., 0., 3499.);

   createEBEEPlot(pairFileLeg, "sie", sie_b, sie_e, nH, fName, "#sigma_{#sigma_{i#etai#eta}}", "", 3, 0., 15999., 0., 2999.);
   createEBEEPlot(pairFileLeg, "hoe", hoe_b, hoe_e, nH, fName, "#sigma_{H/E}", "", 3, 0., 6999., 0., 2199.);
   createEBEEPlot(pairFileLeg, "eca", eca_b, eca_e, nH, fName, "#sigma_{EcalIso}", "", -1, 0., 3999., 0., 1399.);

   createEBEEPlot(pairFileLeg, "eop", eop_b, eop_e, nH, fName, "#sigma_{1/E - 1/P}", "", 3, 0., 1799., 0., 999.);
   createEBEEPlot(pairFileLeg, "chi", chi_b, chi_e, nH, fName, "#sigma_{Track #chi^{2}}", "", -1, 0., 6999., 0., 2999.);
   createEBEEPlot(pairFileLeg, "mih", mih_b, mih_e, nH, fName, "#Delta N_{Missing Hits}", "", 4, 0., 59999., 0., 13999.);
   createEBEEPlot(pairFileLeg, "des", des_b, des_e, nH, fName, "#sigma_{#Delta#eta}", "", 3, 0., 5999., 0., 999.);
   createEBEEPlot(pairFileLeg, "dph", dph_b, dph_e, nH, fName, "#sigma_{#Delta#phi}", "", -1, 0., 5999., 0., 1199.);

   createEBEEPlot(pairFileLeg, "tks", tks_b, tks_e, nH, fName, "#sigma_{TrackIso}", "", 3, 0., 1999., 0., 349.);
   */
   gROOT->ProcessLine(".q");
}

int main() {
  tnpRes();
  return 0;
}



