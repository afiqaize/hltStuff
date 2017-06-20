// For drawing ID distributions from the TnP ntuple
// Usage: root -l -b tnpDist.cxx++

#include "TFile.h"
#include "TChain.h"
#include "TTree.h"
#include "TROOT.h"
#include "TBufferFile.h"
#include "TLorentzVector.h"

#include "hltWP.cxx"
#include "plotStuff.cxx"
#include "/home/afiqaize/root53434/macros/tdrstyle.C"

void tnpDist() {
   gROOT->Reset();

   setTDRStyle();

   // Everything to tinker with should be here
   std::string vName, outPre;
   outPre = "v_m5p2";

   // -------------------------------------------------- //

   const int nH = 7;

   std::pair <std::string, std::string> pairFileLeg[nH];
   pairFileLeg[0] = std::make_pair("m5p2_fastBDED", "Offline");
   pairFileLeg[1] = std::make_pair("m5p2_fastBDED", "EB 15 EE 10");
   pairFileLeg[2] = std::make_pair("m5p2_fastB1E1", "EB 1 EE 1");
   pairFileLeg[3] = std::make_pair("m5p2_fastB2E2", "EB 2 EE 2");
   pairFileLeg[4] = std::make_pair("m5p2_fastB5E5", "EB 5 EE 5");
   pairFileLeg[5] = std::make_pair("m5p2_fastB7E7", "EB 7 EE 7");
   pairFileLeg[6] = std::make_pair("m5p2_full", "No prefit");

   TH1::SetDefaultSumw2(true);
   TH1 *eta_b[nH], *eta_e[nH], *phi_b[nH], *phi_e[nH], *eet_b[nH], *eet_e[nH];
   TH1 *sie_b[nH], *sie_e[nH], *hoe_b[nH], *hoe_e[nH];
   TH1 *eca_b[nH], *eca_e[nH], *hca_b[nH], *hca_e[nH];
   TH1 *eop_b[nH], *eop_e[nH], *chi_b[nH], *chi_e[nH], *mih_b[nH], *mih_e[nH];
   TH1 *des_b[nH], *des_e[nH], *dph_b[nH], *dph_e[nH], *tks_b[nH], *tks_e[nH];
   TH1 *lol_b[nH], *lol_e[nH];

   int kCols[nH] = {kAzure + 1, kBlack, kSpring - 3, kAzure - 3, kOrange - 3, kPink - 3, kViolet - 3};
   int kColor, kFill, kMark;
   for (int iH = 0; iH < nH; iH++) {
     kColor = kCols[iH];
     kFill = 1001 * abs(iH - 1); kMark = 20 + iH;

     eta_b[iH] = new TH1D(("eta_b_" + toStr(iH)).c_str(), "#eta Distribution", mS::bin.at("eta").nBin_eb, mS::bin.at("eta").min_eb, mS::bin.at("eta").max_eb);
     eta_e[iH] = new TH1D(("eta_e_" + toStr(iH)).c_str(), "#eta Distribution", mS::bin.at("eta").nBin_ee, mS::bin.at("eta").min_ee, mS::bin.at("eta").max_ee);
     styleHist(eta_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(eta_e[iH], kColor, kFill, kMark, 1, 1.5);

     phi_b[iH] = new TH1D(("phi_b_" + toStr(iH)).c_str(), "#phi Distribution", mS::bin.at("phi").nBin_eb, mS::bin.at("phi").min_eb, mS::bin.at("phi").max_eb);
     phi_e[iH] = new TH1D(("phi_e_" + toStr(iH)).c_str(), "#phi Distribution", mS::bin.at("phi").nBin_ee, mS::bin.at("phi").min_ee, mS::bin.at("phi").max_ee);
     styleHist(phi_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(phi_e[iH], kColor, kFill, kMark, 1, 1.5);

     eet_b[iH] = new TH1D(("eet_b_" + toStr(iH)).c_str(), "E_{T} Distribution", mS::bin.at("eet").nBin_eb, mS::bin.at("eet").min_eb, mS::bin.at("eet").max_eb);
     eet_e[iH] = new TH1D(("eet_e_" + toStr(iH)).c_str(), "E_{T} Distribution", mS::bin.at("eet").nBin_ee, mS::bin.at("eet").min_ee, mS::bin.at("eet").max_ee);
     styleHist(eet_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(eet_e[iH], kColor, kFill, kMark, 1, 1.5);

     sie_b[iH] = new TH1D(("sie_b_" + toStr(iH)).c_str(), "Cluster Shape Distribution", mS::bin.at("sie").nBin_eb, mS::bin.at("sie").min_eb, mS::bin.at("sie").max_eb);
     sie_e[iH] = new TH1D(("sie_e_" + toStr(iH)).c_str(), "Cluster Shape Distribution", mS::bin.at("sie").nBin_ee, mS::bin.at("sie").min_ee, mS::bin.at("sie").max_ee);
     styleHist(sie_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(sie_e[iH], kColor, kFill, kMark, 1, 1.5);

     hoe_b[iH] = new TH1D(("hoe_b_" + toStr(iH)).c_str(), "Hadronic / EM Distribution", mS::bin.at("hoe").nBin_eb, mS::bin.at("hoe").min_eb, mS::bin.at("hoe").max_eb);
     hoe_e[iH] = new TH1D(("hoe_e_" + toStr(iH)).c_str(), "Hadronic / EM Distribution", mS::bin.at("hoe").nBin_ee, mS::bin.at("hoe").min_ee, mS::bin.at("hoe").max_ee);
     styleHist(hoe_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(hoe_e[iH], kColor, kFill, kMark, 1, 1.5);

     eca_b[iH] = new TH1D(("eca_b_" + toStr(iH)).c_str(), "Ecal Isolation Distribution", mS::bin.at("eca").nBin_eb, mS::bin.at("eca").min_eb, mS::bin.at("eca").max_eb);
     eca_e[iH] = new TH1D(("eca_e_" + toStr(iH)).c_str(), "Ecal Isolation Distribution", mS::bin.at("eca").nBin_ee, mS::bin.at("eca").min_ee, mS::bin.at("eca").max_ee);
     styleHist(eca_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(eca_e[iH], kColor, kFill, kMark, 1, 1.5);

     hca_b[iH] = new TH1D(("hca_b_" + toStr(iH)).c_str(), "Hcal Isolation Distribution", mS::bin.at("hca").nBin_eb, mS::bin.at("hca").min_eb, mS::bin.at("hca").max_eb);
     hca_e[iH] = new TH1D(("hca_e_" + toStr(iH)).c_str(), "Hcal Isolation Distribution", mS::bin.at("hca").nBin_ee, mS::bin.at("hca").min_ee, mS::bin.at("hca").max_ee);
     styleHist(hca_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(hca_e[iH], kColor, kFill, kMark, 1, 1.5);

     eop_b[iH] = new TH1D(("eop_b_" + toStr(iH)).c_str(), "1/E - 1/P Distribution", mS::bin.at("eop").nBin_eb, mS::bin.at("eop").min_eb, mS::bin.at("eop").max_eb);
     eop_e[iH] = new TH1D(("eop_e_" + toStr(iH)).c_str(), "1/E - 1/P Distribution", mS::bin.at("eop").nBin_ee, mS::bin.at("eop").min_ee, mS::bin.at("eop").max_ee);
     styleHist(eop_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(eop_e[iH], kColor, kFill, kMark, 1, 1.5);

     chi_b[iH] = new TH1D(("chi_b_" + toStr(iH)).c_str(), "Track #chi^{2} Distribution", mS::bin.at("chi").nBin_eb, mS::bin.at("chi").min_eb, mS::bin.at("chi").max_eb);
     chi_e[iH] = new TH1D(("chi_e_" + toStr(iH)).c_str(), "Track #chi^{2} Distribution", mS::bin.at("chi").nBin_ee, mS::bin.at("chi").min_ee, mS::bin.at("chi").max_ee);
     styleHist(chi_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(chi_e[iH], kColor, kFill, kMark, 1, 1.5);

     mih_b[iH] = new TH1D(("mih_b_" + toStr(iH)).c_str(), "Missing Hits Distribution", mS::bin.at("mih").nBin_eb, mS::bin.at("mih").min_eb, mS::bin.at("mih").max_eb);
     mih_e[iH] = new TH1D(("mih_e_" + toStr(iH)).c_str(), "Missing Hits Distribution", mS::bin.at("mih").nBin_ee, mS::bin.at("mih").min_ee, mS::bin.at("mih").max_ee);
     styleHist(mih_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(mih_e[iH], kColor, kFill, kMark, 1, 1.5);

     des_b[iH] = new TH1D(("des_b_" + toStr(iH)).c_str(), "Seed #Delta#eta Distribution", mS::bin.at("des").nBin_eb, mS::bin.at("des").min_eb, mS::bin.at("des").max_eb);
     des_e[iH] = new TH1D(("des_e_" + toStr(iH)).c_str(), "Seed #Delta#eta Distribution", mS::bin.at("des").nBin_ee, mS::bin.at("des").min_ee, mS::bin.at("des").max_ee);
     styleHist(des_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(des_e[iH], kColor, kFill, kMark, 1, 1.5);

     dph_b[iH] = new TH1D(("dph_b_" + toStr(iH)).c_str(), "SC #Delta#phi Distribution", mS::bin.at("dph").nBin_eb, mS::bin.at("dph").min_eb, mS::bin.at("dph").max_eb);
     dph_e[iH] = new TH1D(("dph_e_" + toStr(iH)).c_str(), "SC #Delta#phi Distribution", mS::bin.at("dph").nBin_ee, mS::bin.at("dph").min_ee, mS::bin.at("dph").max_ee);
     styleHist(dph_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(dph_e[iH], kColor, kFill, kMark, 1, 1.5);

     tks_b[iH] = new TH1D(("tks_b_" + toStr(iH)).c_str(), "Track Isolation Distribution", mS::bin.at("tks").nBin_eb, mS::bin.at("tks").min_eb, mS::bin.at("tks").max_eb);
     tks_e[iH] = new TH1D(("tks_e_" + toStr(iH)).c_str(), "Track Isolation Distribution", mS::bin.at("tks").nBin_ee, mS::bin.at("tks").min_ee, mS::bin.at("tks").max_ee);
     styleHist(tks_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(tks_e[iH], kColor, kFill, kMark, 1, 1.5);

     lol_b[iH] = new TH1D(("lol_b_" + toStr(iH)).c_str(), "Lolwtf Distribution", mS::bin.at("lol").nBin_eb, mS::bin.at("lol").min_eb, mS::bin.at("lol").max_eb);
     lol_e[iH] = new TH1D(("lol_e_" + toStr(iH)).c_str(), "Lolwtf Distribution", mS::bin.at("lol").nBin_ee, mS::bin.at("lol").min_ee, mS::bin.at("lol").max_ee);
     styleHist(lol_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(lol_e[iH], kColor, kFill, kMark, 1, 1.5);
   }

   // -------------------------------------------------- //

   std::string const inDir = "/home/afiqaize/Downloads/HLT/dev/e_90x/ecalIso_160317/root/";
   std::string const fName = inDir + "../plot/" + outPre + "_";

   TChain *t1 = new TChain("tnpEleTrig/fitter_tree");
   for (int iH = 1; iH < nH; iH++)
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

   int nEnt = t1->GetEntries();
   std::cout << "nEnt = " << nEnt << std::endl;

   for (int ent = 0; ent < nEnt; ent++) {

     t1->GetEntry(ent);
     if (!passL1T) continue;
     if (!m60To120) continue;
     if (std::abs(sc_eta) > etaEE) continue;

     //if (!checkCand("", "", rho,
     //               hlt_e, hlt_et, hlt_eta, hlt_phi,
     //               hlt_sie, hlt_hoe, hlt_eca, hlt_hca, hlt_eop,
     //               hlt_chi, hlt_mih, hlt_des, hlt_dph, hlt_tks,
     //               hlt_ps2)) continue;

     std::string cFile(t1->GetCurrentFile()->GetName());

     bool isFile[nH] = {false, false, false, false, false, false};
     for (int iH = 1; iH < nH; iH++)
       isFile[iH] = cFile.std::string::find(pairFileLeg[iH].first) != std::string::npos;

     if (isFile[1]) {
       eta_b[0]->Fill(sc_eta, finWgt);
       eta_e[0]->Fill(sc_eta, finWgt);
     }

     for (int iH = 1; iH < nH; iH++) {
       if (isFile[iH]) {
         eta_b[iH]->Fill(hlt_eta, finWgt);
         eta_e[iH]->Fill(hlt_eta, finWgt);
       }
     }

     if (std::abs(sc_eta) < etaEB) {

       if (isFile[1]) {
         eet_b[0]->Fill(ele_et, finWgt);
         phi_b[0]->Fill(sc_phi, finWgt);
         sie_b[0]->Fill(ele_sie, finWgt);
         hoe_b[0]->Fill(ele_hoe, finWgt);
         eca_b[0]->Fill(ele_eca, finWgt);
         hca_b[0]->Fill(ele_hca, finWgt);
         eop_b[0]->Fill(std::abs(ele_eop), finWgt);
         chi_b[0]->Fill(ele_chi, finWgt);
         mih_b[0]->Fill(ele_mih, finWgt);
         des_b[0]->Fill(std::abs(ele_des), finWgt);
         dph_b[0]->Fill(std::abs(ele_dph), finWgt);
         tks_b[0]->Fill(ele_tks, finWgt);
       }

       for (int iH = 1; iH < nH; iH++) {
         if (isFile[iH]) {
           eet_b[iH]->Fill(hlt_et, finWgt);
           phi_b[iH]->Fill(hlt_phi, finWgt);
           sie_b[iH]->Fill(hlt_sie, finWgt);
           hoe_b[iH]->Fill(hlt_hoe, finWgt);
           eca_b[iH]->Fill(hlt_eca, finWgt);
           hca_b[iH]->Fill(hlt_hca, finWgt);
           eop_b[iH]->Fill(hlt_eop, finWgt);
           chi_b[iH]->Fill(hlt_chi, finWgt);
           mih_b[iH]->Fill(hlt_mih, finWgt);
           des_b[iH]->Fill(hlt_des, finWgt);
           dph_b[iH]->Fill(hlt_dph, finWgt);
           tks_b[iH]->Fill(hlt_tks, finWgt);
         }
       }
     }

     if (std::abs(sc_eta) >= etaET) {

       if (isFile[1]) {
         eet_e[0]->Fill(ele_et, finWgt);
         phi_e[0]->Fill(sc_phi, finWgt);
         sie_e[0]->Fill(ele_sie, finWgt);
         hoe_e[0]->Fill(ele_hoe, finWgt);
         eca_e[0]->Fill(ele_eca, finWgt);
         hca_e[0]->Fill(ele_hca, finWgt);
         eop_e[0]->Fill(std::abs(ele_eop), finWgt);
         chi_e[0]->Fill(ele_chi, finWgt);
         mih_e[0]->Fill(ele_mih, finWgt);
         des_e[0]->Fill(std::abs(ele_des), finWgt);
         dph_e[0]->Fill(std::abs(ele_dph), finWgt);
         tks_e[0]->Fill(ele_tks, finWgt);
       }

       for (int iH = 1; iH < nH; iH++) {
         if (isFile[iH]) {
           eet_e[iH]->Fill(hlt_et, finWgt);
           phi_e[iH]->Fill(hlt_phi, finWgt);
           sie_e[iH]->Fill(hlt_sie, finWgt);
           hoe_e[iH]->Fill(hlt_hoe, finWgt);
           eca_e[iH]->Fill(hlt_eca, finWgt);
           hca_e[iH]->Fill(hlt_hca, finWgt);
           eop_e[iH]->Fill(hlt_eop, finWgt);
           chi_e[iH]->Fill(hlt_chi, finWgt);
           mih_e[iH]->Fill(hlt_mih, finWgt);
           des_e[iH]->Fill(hlt_des, finWgt);
           dph_e[iH]->Fill(hlt_dph, finWgt);
           tks_e[iH]->Fill(hlt_tks, finWgt);
         }
       }
     }
   }

   // -------------------------------------------------- //

   // TO BE UPDATED TO INCLUDE CUT GRAPHS - REFER TO tnpTune

   createEBEERatioPlot(pairFileLeg, "eca", eca_b, eca_e, nH, fName, "EcalIso (GeV)", "", "", true, -1, 0., 499999., 0., 199999.);

   /*
   createEBEERatioPlot(pairFileLeg, "eta", eta_b, eta_e, nH, fName, "#eta", "", "", false, -1, 0., 3499., 0., 3499.);
   createEBEERatioPlot(pairFileLeg, "eet", eet_b, eet_e, nH, fName, "E_{T} (GeV)", "", "", false, -1, 0., 11999., 0., 2999.);
   createEBEERatioPlot(pairFileLeg, "phi", phi_b, phi_e, nH, fName, "#phi", "", "", false, -1, 0., 5999., 0., 1599.);

   createEBEERatioPlot(pairFileLeg, "sie", sie_b, sie_e, nH, fName, "#sigma_{i#etai#eta}", "", "", false, 4, 0., 21999., 0., 3499.);
   createEBEERatioPlot(pairFileLeg, "hoe", hoe_b, hoe_e, nH, fName, "H/E", "", "", true, -1, 0., 69999., 0., 9999.);
   createEBEERatioPlot(pairFileLeg, "eca", eca_b, eca_e, nH, fName, "EcalIso (GeV)", "", "", true, -1, 0., 19999., 0., 6999.);

   createEBEERatioPlot(pairFileLeg, "eop", eop_b, eop_e, nH, fName, "1/E - 1/P", "", "", true, -1, 0., 39999., 0., 6999.);
   createEBEERatioPlot(pairFileLeg, "chi", chi_b, chi_e, nH, fName, "Track #chi^{2}", "", "", false, -1, 0., 4999., 0., 3499.);
   createEBEERatioPlot(pairFileLeg, "mih", mih_b, mih_e, nH, fName, "Missing Hits", "", "", false, -1, 0., 69999., 0., 17999.);
   createEBEERatioPlot(pairFileLeg, "des", des_b, des_e, nH, fName, "#Delta#eta", "", "", true, -1, 0., 29999., 0., 4999.);
   createEBEERatioPlot(pairFileLeg, "dph", dph_b, dph_e, nH, fName, "#Delta#phi", "", "", true, -1, 0., 19999., 0., 2999.);

   createEBEERatioPlot(pairFileLeg, "tks", tks_b, tks_e, nH, fName, "TrackIso (GeV)", "", "", true, -1, 0., 79999., 0., 19999.);
   */
   gROOT->ProcessLine(".q");
}

int main() {
  tnpDist();
  return 0;
}



