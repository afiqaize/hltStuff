// For drawing ID resolution from the TnP ntuple
// Usage: root -l -b tnpRes.cxx++

#include "TFile.h"
#include "TChain.h"
#include "TTree.h"
#include "TROOT.h"
#include "TBufferFile.h"
#include "TLorentzVector.h"

#include "hltWP.cxx"
#include "plotStuff.cxx"
#include "/home/afiqaize/root53434/macros/tdrstyle.C"

float calcRes(const float& vHlt, const float& vOff) {
  float vRes = 999999.;

  if (vHlt != 0. and vOff != 0.) vRes = (vHlt - vOff) / vOff;
  return vRes;
}

void tnpRes() {
   gROOT->Reset();

   setTDRStyle();

   // Everything to tinker with should be here
   std::string vName, outPre;
   outPre = "r";

   // -------------------------------------------------- //

   const int etaResB_nBin = 102, etaResE_nBin = 102;
   const float etaResB_max = 0.0105, etaResE_max = 0.0105;
   const float etaResB_min = -0.0105, etaResE_min = -0.0105;

   const int phiResB_nBin = 102, phiResE_nBin = 102;
   const float phiResB_max = 0.0105, phiResE_max = 0.0105;
   const float phiResB_min = -0.0105, phiResE_min = -0.0105;

   // For Et
   const int eetResB_nBin = 102, eetResE_nBin = 102;
   const float eetResB_max = 0.105, eetResE_max = 0.105;
   const float eetResB_min = -0.105, eetResE_min = -0.105;

   const int sieResB_nBin = 100, sieResE_nBin = 100;
   const float sieResB_max = 0.2, sieResE_max = 0.2;
   const float sieResB_min = -0.2, sieResE_min = -0.2;

   // For H/E
   const int hoeResB_nBin = 102, hoeResE_nBin = 102;
   const float hoeResB_max = 1.05, hoeResE_max = 1.05;
   const float hoeResB_min = -1.05, hoeResE_min = -1.05;

   const int ecaResB_nBin = 61, ecaResE_nBin = 61;
   const float ecaResB_max = 5.05, ecaResE_max = 5.05;
   const float ecaResB_min = -1.05, ecaResE_min = -1.05;

   const int hcaResB_nBin = 61, hcaResE_nBin = 61;
   const float hcaResB_max = 5.05, hcaResE_max = 5.05;
   const float hcaResB_min = -1.05, hcaResE_min = -1.05;

   const int eopResB_nBin = 122, eopResE_nBin = 122;
   const float eopResB_max = 5.05, eopResE_max = 5.05;
   const float eopResB_min = -1.05, eopResE_min = -1.05;

   const int chiResB_nBin = 82, chiResE_nBin = 82;
   const float chiResB_max = 3.05, chiResE_max = 3.05;
   const float chiResB_min = -1.05, chiResE_min = -1.05;

   const int mihResB_nBin = 5, mihResE_nBin = 5;
   const float mihResB_max = 2.5, mihResE_max = 2.5;
   const float mihResB_min = -2.5, mihResE_min = -2.5;

   const int desResB_nBin = 82, desResE_nBin = 82;
   const float desResB_max = 3.05, desResE_max = 3.05;
   const float desResB_min = -1.05, desResE_min = -1.05;

   const int dphResB_nBin = 82, dphResE_nBin = 82;
   const float dphResB_max = 3.05, dphResE_max = 3.05;
   const float dphResB_min = -1.05, dphResE_min = -1.05;

   const int tksResB_nBin = 102, tksResE_nBin = 102;
   const float tksResB_max = 1.05, tksResE_max = 1.05;
   const float tksResB_min = -1.05, tksResE_min = -1.05;

   const int lolResB_nBin = 102, lolResE_nBin = 102;
   const float lolResB_max = 1.05, lolResE_max = 1.05;
   const float lolResB_min = -1.05, lolResE_min = -1.05;

   // -------------------------------------------------- //

   const int nH = 1;

   std::pair <std::string, std::string> pairFileLeg[nH];
   pairFileLeg[0] = std::make_pair("dy_off", "DY");

   TH1::SetDefaultSumw2(true);
   TH1 *eta_b[nH], *eta_e[nH], *phi_b[nH], *phi_e[nH], *eet_b[nH], *eet_e[nH];
   TH1 *sie_b[nH], *sie_e[nH], *hoe_b[nH], *hoe_e[nH];
   TH1 *eca_b[nH], *eca_e[nH], *hca_b[nH], *hca_e[nH];
   TH1 *eop_b[nH], *eop_e[nH], *chi_b[nH], *chi_e[nH], *mih_b[nH], *mih_e[nH];
   TH1 *des_b[nH], *des_e[nH], *dph_b[nH], *dph_e[nH], *tks_b[nH], *tks_e[nH];
   TH1 *lol_b[nH], *lol_e[nH];

   int kCols[nH] = {kPink - 3};
   int kColor, kFill, kMark;
   for (int iH = 0; iH < nH; iH++) {
     kColor = kCols[iH];
     kFill = 0; kMark = 20 + iH;

     eta_b[iH] = new TH1F(("eta_ResB_" + toStr(iH)).c_str(), "#eta Resolution", etaResB_nBin, etaResB_min, etaResB_max);
     eta_e[iH] = new TH1F(("eta_ResE_" + toStr(iH)).c_str(), "#eta Resolution", etaResE_nBin, etaResE_min, etaResE_max);
     styleHist(eta_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(eta_e[iH], kColor, kFill, kMark, 1, 2.0);

     phi_b[iH] = new TH1F(("phi_ResB_" + toStr(iH)).c_str(), "#phi Resolution", phiResB_nBin, phiResB_min, phiResB_max);
     phi_e[iH] = new TH1F(("phi_ResE_" + toStr(iH)).c_str(), "#phi Resolution", phiResE_nBin, phiResE_min, phiResE_max);
     styleHist(phi_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(phi_e[iH], kColor, kFill, kMark, 1, 2.0);

     eet_b[iH] = new TH1F(("eet_ResB_" + toStr(iH)).c_str(), "E_{T} Resolution", eetResB_nBin, eetResB_min, eetResB_max);
     eet_e[iH] = new TH1F(("eet_ResE_" + toStr(iH)).c_str(), "E_{T} Resolution", eetResE_nBin, eetResE_min, eetResE_max);
     styleHist(eet_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(eet_e[iH], kColor, kFill, kMark, 1, 2.0);

     sie_b[iH] = new TH1F(("sie_ResB_" + toStr(iH)).c_str(), "Cluster Shape Resolution", sieResB_nBin, sieResB_min, sieResB_max);
     sie_e[iH] = new TH1F(("sie_ResE_" + toStr(iH)).c_str(), "Cluster Shape Resolution", sieResE_nBin, sieResE_min, sieResE_max);
     styleHist(sie_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(sie_e[iH], kColor, kFill, kMark, 1, 2.0);

     hoe_b[iH] = new TH1F(("hoe_ResB_" + toStr(iH)).c_str(), "Hadronic Leak Resolution", hoeResB_nBin, hoeResB_min, hoeResB_max);
     hoe_e[iH] = new TH1F(("hoe_ResE_" + toStr(iH)).c_str(), "Hadronic Leak Resolution", hoeResE_nBin, hoeResE_min, hoeResE_max);
     styleHist(hoe_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(hoe_e[iH], kColor, kFill, kMark, 1, 2.0);

     eca_b[iH] = new TH1F(("eca_ResB_" + toStr(iH)).c_str(), "Ecal Isolation Resolution", ecaResB_nBin, ecaResB_min, ecaResB_max);
     eca_e[iH] = new TH1F(("eca_ResE_" + toStr(iH)).c_str(), "Ecal Isolation Resolution", ecaResE_nBin, ecaResE_min, ecaResE_max);
     styleHist(eca_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(eca_e[iH], kColor, kFill, kMark, 1, 2.0);

     hca_b[iH] = new TH1F(("hca_ResB_" + toStr(iH)).c_str(), "Hcal Isolation Resolution", hcaResB_nBin, hcaResB_min, hcaResB_max);
     hca_e[iH] = new TH1F(("hca_ResE_" + toStr(iH)).c_str(), "Hcal Isolation Resolution", hcaResE_nBin, hcaResE_min, hcaResE_max);
     styleHist(hca_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(hca_e[iH], kColor, kFill, kMark, 1, 2.0);

     eop_b[iH] = new TH1F(("eop_ResB_" + toStr(iH)).c_str(), "1/E - 1/P Resolution", eopResB_nBin, eopResB_min, eopResB_max);
     eop_e[iH] = new TH1F(("eop_ResE_" + toStr(iH)).c_str(), "1/E - 1/P Resolution", eopResE_nBin, eopResE_min, eopResE_max);
     styleHist(eop_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(eop_e[iH], kColor, kFill, kMark, 1, 2.0);

     chi_b[iH] = new TH1F(("chi_ResB_" + toStr(iH)).c_str(), "Track #chi^{2} Resolution", chiResB_nBin, chiResB_min, chiResB_max);
     chi_e[iH] = new TH1F(("chi_ResE_" + toStr(iH)).c_str(), "Track #chi^{2} Resolution", chiResE_nBin, chiResE_min, chiResE_max);
     styleHist(chi_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(chi_e[iH], kColor, kFill, kMark, 1, 2.0);

     mih_b[iH] = new TH1F(("mih_ResB_" + toStr(iH)).c_str(), "Missing Hits Resolution", mihResB_nBin, mihResB_min, mihResB_max);
     mih_e[iH] = new TH1F(("mih_ResE_" + toStr(iH)).c_str(), "Missing Hits Resolution", mihResE_nBin, mihResE_min, mihResE_max);
     styleHist(mih_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(mih_e[iH], kColor, kFill, kMark, 1, 2.0);

     des_b[iH] = new TH1F(("des_ResB_" + toStr(iH)).c_str(), "Seed #Delta#eta Resolution", desResB_nBin, desResB_min, desResB_max);
     des_e[iH] = new TH1F(("des_ResE_" + toStr(iH)).c_str(), "Seed #Delta#eta Resolution", desResE_nBin, desResE_min, desResE_max);
     styleHist(des_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(des_e[iH], kColor, kFill, kMark, 1, 2.0);

     dph_b[iH] = new TH1F(("dph_ResB_" + toStr(iH)).c_str(), "SC #Delta#phi Resolution", dphResB_nBin, dphResB_min, dphResB_max);
     dph_e[iH] = new TH1F(("dph_ResE_" + toStr(iH)).c_str(), "SC #Delta#phi Resolution", dphResE_nBin, dphResE_min, dphResE_max);
     styleHist(dph_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(dph_e[iH], kColor, kFill, kMark, 1, 2.0);

     tks_b[iH] = new TH1F(("tks_ResB_" + toStr(iH)).c_str(), "Track Isolation Resolution", tksResB_nBin, tksResB_min, tksResB_max);
     tks_e[iH] = new TH1F(("tks_ResE_" + toStr(iH)).c_str(), "Track Isolation Resolution", tksResE_nBin, tksResE_min, tksResE_max);
     styleHist(tks_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(tks_e[iH], kColor, kFill, kMark, 1, 2.0);

     lol_b[iH] = new TH1F(("lol_ResB_" + toStr(iH)).c_str(), "Lolwtf Resolution", lolResB_nBin, lolResB_min, lolResB_max);
     lol_e[iH] = new TH1F(("lol_ResE_" + toStr(iH)).c_str(), "Lolwtf Resolution", lolResE_nBin, lolResE_min, lolResE_max);
     styleHist(lol_b[iH], kColor, kFill, kMark, 1, 2.0);
     styleHist(lol_e[iH], kColor, kFill, kMark, 1, 2.0);
   }

   // -------------------------------------------------- //

   std::string const inDir = "/home/afiqaize/Downloads/EGM/dev/e_90x/wpTune_110517/root/";
   std::string const fName = inDir + "../plot_v1/resHist/" + outPre + "_";

   TChain *t1 = new TChain("tnpEleTrig/fitter_tree");
   for (int iH = 0; iH < 1; iH++)
     t1->Add((inDir + pairFileLeg[iH].first + ".root").c_str());

   int nRun;
   t1->SetBranchAddress("run", &nRun);
   int nLumi;
   t1->SetBranchAddress("lumi", &nLumi);
   int nEvt;
   t1->SetBranchAddress("event", &nEvt);
   int nPV;
   t1->SetBranchAddress("event_nPV", &nPV);
   float off_rho;
   t1->SetBranchAddress("off_rho", &off_rho);
   float hlt_rho;
   t1->SetBranchAddress("hlt_rho", &hlt_rho);
   float finWgt;
   t1->SetBranchAddress("totWeight", &finWgt);

   int passTight80X;
   t1->SetBranchAddress("passTight80X", &passTight80X);
   int passHLT;
   t1->SetBranchAddress("passHLT", &passHLT);
   int passL1T;
   t1->SetBranchAddress("passL1T", &passL1T);
   int m60To120;
   t1->SetBranchAddress("pair_mass60to120", &m60To120);

   float hlt_et;
   t1->SetBranchAddress("probe_hlt_et", &hlt_et);
   float hlt_e;
   t1->SetBranchAddress("probe_hlt_e", &hlt_e);
   float hlt_eta;
   t1->SetBranchAddress("probe_hlt_eta", &hlt_eta);
   float hlt_phi;
   t1->SetBranchAddress("probe_hlt_phi", &hlt_phi);
   float hlt_sie;
   t1->SetBranchAddress("probe_hlt_sieie", &hlt_sie);
   float hlt_hoe;
   t1->SetBranchAddress("probe_hlt_hoe", &hlt_hoe);
   float hlt_eca;
   t1->SetBranchAddress("probe_hlt_ecalIso", &hlt_eca);
   float hlt_hca;
   t1->SetBranchAddress("probe_hlt_hcalIso", &hlt_hca);
   float hlt_ps2;
   t1->SetBranchAddress("probe_hlt_ps2", &hlt_ps2);
   float hlt_eop;
   t1->SetBranchAddress("probe_hlt_ooemoop", &hlt_eop);
   float hlt_chi;
   t1->SetBranchAddress("probe_hlt_chi2", &hlt_chi);
   float hlt_mih;
   t1->SetBranchAddress("probe_hlt_mHits", &hlt_mih);
   float hlt_det;
   t1->SetBranchAddress("probe_hlt_dEtaIn", &hlt_det);
   float hlt_des;
   t1->SetBranchAddress("probe_hlt_dEtaOut", &hlt_des);
   float hlt_dph;
   t1->SetBranchAddress("probe_hlt_dPhiIn", &hlt_dph);
   float hlt_tks;
   t1->SetBranchAddress("probe_hlt_trkIso", &hlt_tks);

   float sc_et;
   t1->SetBranchAddress("probe_sc_et", &sc_et);
   float sc_e;
   t1->SetBranchAddress("probe_sc_e", &sc_e);
   float sc_eta;
   t1->SetBranchAddress("probe_sc_eta", &sc_eta);
   float sc_phi;
   t1->SetBranchAddress("probe_sc_phi", &sc_phi);

   float ele_et;
   t1->SetBranchAddress("probe_ele_et", &ele_et);
   float ele_e;
   t1->SetBranchAddress("probe_ele_e", &ele_e);
   float ele_eta;
   t1->SetBranchAddress("probe_ele_eta", &ele_eta);
   float ele_phi;
   t1->SetBranchAddress("probe_ele_phi", &ele_phi);
   float ele_sie;
   t1->SetBranchAddress("probe_ele_sieie5x5", &ele_sie);
   float ele_hoe;
   t1->SetBranchAddress("probe_ele_hoe", &ele_hoe);
   float ele_eca;
   t1->SetBranchAddress("probe_ele_ecalIso", &ele_eca);
   float ele_hca;
   t1->SetBranchAddress("probe_ele_hcalIso", &ele_hca);
   float ele_eop;
   t1->SetBranchAddress("probe_ele_ooemoop", &ele_eop);
   float ele_chi;
   t1->SetBranchAddress("probe_ele_chi2", &ele_chi);
   float ele_mih;
   t1->SetBranchAddress("probe_ele_mHits", &ele_mih);
   float ele_det;
   t1->SetBranchAddress("probe_ele_dEtaIn", &ele_det);
   float ele_des;
   t1->SetBranchAddress("probe_ele_dEtaOut", &ele_des);
   float ele_dph;
   t1->SetBranchAddress("probe_ele_dPhiIn", &ele_dph);
   float ele_tks;
   t1->SetBranchAddress("probe_ele_trkIso", &ele_tks);

   // -------------------------------------------------- //

   int nEvt1 = t1->GetEntries();
   std::cout << "nEvt1 = " << nEvt1 << std::endl;

   for (int evt1 = 0; evt1 < nEvt1; evt1++) {
     t1->GetEntry(evt1);
     if (passL1T != 1) continue;
     if (m60To120 != 1) continue;
     if (std::abs(sc_eta) > etaEE) continue;

     //std::cout << sc_eta << " " << sc_phi << std::endl;

     /*
     if (!checkCand("", vNoMask, hlt_rho,
                    hlt_e, hlt_et, hlt_eta, hlt_phi,
                    hlt_sie, hlt_hoe, hlt_eca, hlt_hca, hlt_eop,
                    hlt_chi, hlt_mih, hlt_des, hlt_dph, hlt_tks,
                    tmp_ps2)) continue;
     */
     std::string cFile(t1->GetCurrentFile()->GetName());

     bool isFile[nH];
     for (int iH = 0; iH < nH; iH++)
       isFile[iH] = cFile.std::string::find(pairFileLeg[iH].first) != std::string::npos;

     for (int iH = 0; iH < nH; iH++) {
       if (true or isFile[iH]) {
         if (std::abs(sc_eta) < etaEB) {
           eta_b[iH]->Fill( calcRes(hlt_eta, sc_eta), finWgt);
           eet_b[iH]->Fill( calcRes(hlt_et, ele_et), finWgt);
           phi_b[iH]->Fill( calcRes(hlt_phi, sc_phi), finWgt);
           sie_b[iH]->Fill( calcRes(hlt_sie, ele_sie), finWgt);
           hoe_b[iH]->Fill( calcRes(hlt_hoe, ele_hoe * ele_e), finWgt);
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
           //std::cout << calcRes(hlt_eta, sc_eta) << " " << calcRes(hlt_phi, sc_phi) << std::endl;

           eta_e[iH]->Fill( calcRes(hlt_eta, sc_eta), finWgt);
           eet_e[iH]->Fill( calcRes(hlt_et, ele_et), finWgt);
           phi_e[iH]->Fill( calcRes(hlt_phi, sc_phi), finWgt);
           sie_e[iH]->Fill( calcRes(hlt_sie, ele_sie), finWgt);
           hoe_e[iH]->Fill( calcRes(hlt_hoe, ele_hoe * ele_e), finWgt);
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

   const bool doNorm = false;
   const std::string yLbl = "e / bin";
   const std::vector< std::pair<double, int> > cutVC_b, cutVC_e; // ofc here it's blank

   createEBEEPlot(pairFileLeg, "eet", eet_b, eet_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "#sigma_{E_{T}}", yLbl, false, 4, 0., 19999., 0., 4999.);
   createEBEEPlot(pairFileLeg, "eta", eta_b, eta_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "#sigma_{#eta}", yLbl, false, 4, 0., 299999., 0., 119999.);
   createEBEEPlot(pairFileLeg, "phi", phi_b, phi_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "#sigma_{#phi}", yLbl, false, 4, 0., 299999., 0., 119999.);

   createEBEEPlot(pairFileLeg, "sie", sie_b, sie_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "#sigma_{#sigma_{i#etai#eta}}", yLbl, false, 4, 0., 399999., 0., 119999.);
   createEBEEPlot(pairFileLeg, "hoe", hoe_b, hoe_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "#sigma_{H}", yLbl, false, 4, 0., 11999., 0., 3999.);
   createEBEEPlot(pairFileLeg, "eca", eca_b, eca_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "#sigma_{EcalIso}", yLbl, false, 4, 0., 199999., 0., 99999.);
   createEBEEPlot(pairFileLeg, "hca", hca_b, hca_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "#sigma_{HcalIso}", yLbl, false, 4, 0., 79999., 0., 14999.);

   createEBEEPlot(pairFileLeg, "eop", eop_b, eop_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "#sigma_{1/E - 1/P}", yLbl, false, 4, 0., 8999., 0., 3999.);
   createEBEEPlot(pairFileLeg, "des", des_b, des_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "#sigma_{#Delta#eta}", yLbl, false, 4, 0., 79999., 0., 29999.);
   createEBEEPlot(pairFileLeg, "dph", dph_b, dph_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "#sigma_{#Delta#phi}", yLbl, false, 4, 0., 59999., 0., 17999.);

   createEBEEPlot(pairFileLeg, "tks", tks_b, tks_e, nH,
                  cutVC_b, cutVC_e, "", doNorm, -999., fName, "#sigma_{TrackIso}", yLbl, false, 4, 0., 5999., 0., 1399.);

   gROOT->ProcessLine(".q");
}

int main() {
  tnpRes();
  return 0;
}



