// For hlt comparisons: GT and whatever else
// Usage: root -l -b hltDist.cxx++

#include "TFile.h"
#include "TChain.h"
#include "TTree.h"
#include "TROOT.h"
#include "TBufferFile.h"
#include "TLorentzVector.h"
#include "TF1.h"

#include "hltWP.cxx"
#include "plotStuff.cxx"
#include "/home/afiqaize/root53434/macros/tdrstyle.C"

void hltDist() {

   gROOT->Reset();

   setTDRStyle();

   // Everything to tinker with should be here
   std::string vName, outPre;
   outPre = "";

   // -------------------------------------------------- //

   const int nH = 3;

   std::pair <std::string, std::string> pairFileLeg[nH];
   pairFileLeg[0] = std::make_pair("m5p2_fastBDED", "Offline");
   pairFileLeg[1] = std::make_pair("m5p2_fastBDED", "EB 15 EE 10");
   pairFileLeg[2] = std::make_pair("m5p2_fastB1E1", "EB 1 EE 1");

   TH1::SetDefaultSumw2(true);
   TH1 *eta_b[nH], *eta_e[nH], *phi_b[nH], *phi_e[nH], *eet_b[nH], *eet_e[nH];
   TH1 *sie_b[nH], *sie_e[nH], *hoe_b[nH], *hoe_e[nH];
   TH1 *eca_b[nH], *eca_e[nH], *hca_b[nH], *hca_e[nH];
   TH1 *ps2_b[nH], *ps2_e[nH];
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

     ps2_b[iH] = new TH1D(("ps2_b_" + toStr(iH)).c_str(), "PM s^{2} Distribution", mS::bin.at("ps2").nBin_eb, mS::bin.at("ps2").min_eb, mS::bin.at("ps2").max_eb);
     ps2_e[iH] = new TH1D(("ps2_e_" + toStr(iH)).c_str(), "PM s^{2} Distribution", mS::bin.at("ps2").nBin_ee, mS::bin.at("ps2").min_ee, mS::bin.at("ps2").max_ee);
     styleHist(ps2_b[iH], kColor, kFill, kMark, 1, 1.5);
     styleHist(ps2_e[iH], kColor, kFill, kMark, 1, 1.5);

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

   TChain *t1 = new TChain("hltTree");
   for (int iH = 0; iH < nH; iH++)
     t1->Add((inDir + pairFileLeg[iH].first + ".root").c_str());

   bool isMC = false;

   int nRun;
   t1->SetBranchAddress("nRun", &nRun);
   int nLumi;
   t1->SetBranchAddress("nLumi", &nLumi);
   int nEvt;
   t1->SetBranchAddress("nEvt", &nEvt);
   int nBX;
   t1->SetBranchAddress("nBX", &nBX);
   int nOrb;
   t1->SetBranchAddress("nOrb", &nOrb);
   int nSto;
   t1->SetBranchAddress("nSto", &nSto);

   int type;
   t1->SetBranchAddress("itype", &type);
   double normWgt;
   t1->SetBranchAddress("normWgt", &normWgt);
   double puWgt;
   t1->SetBranchAddress("puWgt", &puWgt);
   int nVtx;
   t1->SetBranchAddress("nVtx", &nVtx);
   double rho;
   t1->SetBranchAddress("rho", &rho);

   int pass[10];
   t1->SetBranchAddress("passHLT", pass);
   int genMatch[10];
   t1->SetBranchAddress("genMatch", genMatch);
   int n;
   t1->SetBranchAddress("hlt_n", &n);
   double et[10];
   t1->SetBranchAddress("hlt_et", et);
   double etr[10];
   t1->SetBranchAddress("hlt_etr", etr);
   double e[10];
   t1->SetBranchAddress("hlt_e", e);
   double er[10];
   t1->SetBranchAddress("hlt_er", er);
   double eta[10];
   t1->SetBranchAddress("hlt_eta", eta);
   double phi[10];
   t1->SetBranchAddress("hlt_phi", phi);
   double sie[10];
   t1->SetBranchAddress("hlt_sie", sie);
   double hoe[10];
   t1->SetBranchAddress("hlt_hoe", hoe);
   double eca[10];
   t1->SetBranchAddress("hlt_eca", eca);
   double hca[10];
   t1->SetBranchAddress("hlt_hca", hca);
   double ps2[10];
   t1->SetBranchAddress("hlt_ps2", ps2);
   double eop[10];
   t1->SetBranchAddress("hlt_eop", eop);
   double esp[10];
   t1->SetBranchAddress("hlt_esp", esp);
   double chi[10];
   t1->SetBranchAddress("hlt_chi", chi);
   double mih[10];
   t1->SetBranchAddress("hlt_mih", mih);
   double det[10];
   t1->SetBranchAddress("hlt_det", det);
   double des[10];
   t1->SetBranchAddress("hlt_des", des);
   double dph[10];
   t1->SetBranchAddress("hlt_dph", dph);
   double tks[10];
   t1->SetBranchAddress("hlt_tks", tks);

   double hoc[10];
   t1->SetBranchAddress("hlt_hoc", hoc);
   double ecc[10];
   t1->SetBranchAddress("hlt_ecc", ecc);
   double hcc[10];
   t1->SetBranchAddress("hlt_hcc", hcc);

   int mc_nPUtrue, gp_n, mc_nPUobs;
   double genWgt, gp_pt[10], gp_eta[10], gp_phi[10];

    if (isMC) {
      t1->SetBranchAddress("genWgt", &genWgt);
      t1->SetBranchAddress("gp_n", &gp_n);
      t1->SetBranchAddress("gp_pt", gp_pt);
      t1->SetBranchAddress("gp_eta", gp_eta);
      t1->SetBranchAddress("gp_phi", gp_phi);
      t1->SetBranchAddress("mc_nPUtrue", &mc_nPUtrue);
      t1->SetBranchAddress("mc_nPUobs", &mc_nPUobs);
    }

   // -------------------------------------------------- //
   // The TnP version of efficiency checker

   TLorentzVector p4Tag, p4Probe;
   double finWgt = 1.;

   int nEvt0 = t1->GetEntries();
   std::cout << "nEvt0 = " << nEvt0 << std::endl;

   for (int evt0 = 0; evt0 < nEvt0; evt0++) {

     t1->GetEntry(evt0);
     if (n < 2 or type != 1) continue;

       finWgt = puWgt * normWgt;
       if (isMC) finWgt =* genWgt;

     for (int iTag = 0; iTag < n; iTag++) {

       if (pass[iTag] != 1) continue;
       //if (isMC and genMatch[iTag] != 1) continue;
       if (et[iTag] < 25. or std::abs(eta[iTag]) > etaEE) continue;

       p4Tag.SetPtEtaPhiE(et[iTag], eta[iTag], phi[iTag], e[iTag]);

       for (int iProbe = 0; iProbe < n; iProbe++) {

         if (iProbe == iTag) continue;
         //if (isMC and genMatch[iProbe] != 1) continue;
         if (et[iProbe] < 25. or std::abs(eta[iProbe]) > etaEE) continue;

         p4Probe.SetPtEtaPhiE(et[iProbe], eta[iProbe], phi[iProbe], e[iProbe]);

         if ((p4Tag + p4Probe).M() < 70. or (p4Tag + p4Probe).M() > 110.) continue;

         if (!checkCand("", "", rho,
                        e[iProbe], et[iProbe], eta[iProbe], phi[iProbe],
                        sie[iProbe], hoe[iProbe], eca[iProbe], hca[iProbe], eop[iProbe],
                        chi[iProbe], mih[iProbe], des[iProbe], dph[iProbe], tks[iProbe],
                        ps2[iProbe])) continue;

         std::string cFile(t1->GetCurrentFile()->GetName());

         bool isFile[nH] = {false, false, false, false, false, false};
         for (int iH = 0; iH < nH; iH++)
           isFile[iH] = cFile.std::string::find(pairFileLeg[iH].first) != std::string::npos;

         for (int iH = 0; iH < nH; iH++) {
           if (isFile[iH]) {
             eta_b[iH]->Fill(eta[iProbe], finWgt);
             eta_e[iH]->Fill(eta[iProbe], finWgt);

             if (std::abs(eta[iProbe]) < etaEB) {
               eet_b[iH]->Fill(et[iProbe], finWgt);
               phi_b[iH]->Fill(phi[iProbe], finWgt);
               sie_b[iH]->Fill(sie[iProbe], finWgt);
               hoe_b[iH]->Fill(hoe[iProbe], finWgt);
               eca_b[iH]->Fill(eca[iProbe], finWgt);
               hca_b[iH]->Fill(hca[iProbe], finWgt);
               ps2_b[iH]->Fill(ps2[iProbe], finWgt);
               eop_b[iH]->Fill(eop[iProbe], finWgt);
               chi_b[iH]->Fill(chi[iProbe], finWgt);
               mih_b[iH]->Fill(mih[iProbe], finWgt);
               des_b[iH]->Fill(des[iProbe], finWgt);
               dph_b[iH]->Fill(dph[iProbe], finWgt);
               tks_b[iH]->Fill(tks[iProbe], finWgt);
             }

             if (std::abs(eta[iProbe]) >= etaET) {
               eet_e[iH]->Fill(et[iProbe], finWgt);
               phi_e[iH]->Fill(phi[iProbe], finWgt);
               sie_e[iH]->Fill(sie[iProbe], finWgt);
               hoe_e[iH]->Fill(hoe[iProbe], finWgt);
               eca_e[iH]->Fill(eca[iProbe], finWgt);
               hca_e[iH]->Fill(hca[iProbe], finWgt);
               ps2_e[iH]->Fill(ps2[iProbe], finWgt);
               eop_e[iH]->Fill(eop[iProbe], finWgt);
               chi_e[iH]->Fill(chi[iProbe], finWgt);
               mih_e[iH]->Fill(mih[iProbe], finWgt);
               des_e[iH]->Fill(des[iProbe], finWgt);
               dph_e[iH]->Fill(dph[iProbe], finWgt);
               tks_e[iH]->Fill(tks[iProbe], finWgt);
             }
           }
         }
       } // eol probe
     } // eol tag
   } // eol evt

   // -------------------------------------------------- //

   const bool doNorm = false;

   // TO BE UPDATED TO INCLUDE CUT GRAPHS - REFER TO tnpTune

   createEBEERatioPlot(pairFileLeg, "eca", eca_b, eca_e, nH, "", doNorm, -999., fName, "EcalIso (GeV)", "", "", true, -1, 1., 499999., 1., 199999.);

   /*
   createEBEERatioPlot(pairFileLeg, "eta", eta_b, eta_e, nH, "", doNorm, -999., fName, "#eta", "", "", false, -1, 0., 3499., 0., 3499.);
   createEBEERatioPlot(pairFileLeg, "eet", eet_b, eet_e, nH, "", doNorm, -999., fName, "E_{T} (GeV)", "", "", false, -1, 0., 11999., 0., 2999.);
   createEBEERatioPlot(pairFileLeg, "phi", phi_b, phi_e, nH, "", doNorm, -999., fName, "#phi", "", "", false, -1, 0., 5999., 0., 1599.);

   createEBEERatioPlot(pairFileLeg, "sie", sie_b, sie_e, nH, "", doNorm, -999., fName, "#sigma_{i#etai#eta}", "", "", false, 4, 0., 21999., 0., 3499.);
   createEBEERatioPlot(pairFileLeg, "hoe", hoe_b, hoe_e, nH, "", doNorm, -999., fName, "H/E", "", "", true, -1, 1., 69999., 1., 9999.);
   createEBEERatioPlot(pairFileLeg, "eca", eca_b, eca_e, nH, "", doNorm, -999., fName, "EcalIso (GeV)", "", "", true, -1, 1., 19999., 1., 6999.);
   createEBEERatioPlot(pairFileLeg, "hca", hca_b, hca_e, nH, "", doNorm, -999., fName, "HcalIso (GeV)", "", "", true, -1, 1., 19999., 1., 6999.);
   createEBEERatioPlot(pairFileLeg, "ps2", ps2_b, ps2_e, nH, "", doNorm, -999., fName, "PM s^{2}", "", false, -1, yMin, 19999., yMin, 6999.);

   createEBEERatioPlot(pairFileLeg, "eop", eop_b, eop_e, nH, "", doNorm, -999., fName, "1/E - 1/P", "", "", true, -1, 1., 39999., 1., 6999.);
   createEBEERatioPlot(pairFileLeg, "chi", chi_b, chi_e, nH, "", doNorm, -999., fName, "Track #chi^{2}", "", "", false, -1, 0., 4999., 0., 3499.);
   createEBEERatioPlot(pairFileLeg, "mih", mih_b, mih_e, nH, "", doNorm, -999., fName, "Missing Hits", "", "", false, -1, 0., 69999., 0., 17999.);
   createEBEERatioPlot(pairFileLeg, "des", des_b, des_e, nH, "", doNorm, -999., fName, "#Delta#eta", "", "", true, -1, 1., 29999., 1., 4999.);
   createEBEERatioPlot(pairFileLeg, "dph", dph_b, dph_e, nH, "", doNorm, -999., fName, "#Delta#phi", "", "", true, -1, 1., 19999., 1., 2999.);

   createEBEERatioPlot(pairFileLeg, "tks", tks_b, tks_e, nH, "", doNorm, -999., fName, "TrackIso (GeV)", "", "", true, -1, 1., 79999., 1., 19999.);
   */
   gROOT->ProcessLine(".q");  
}

int main() {
  hltDist();
  return 0;
}



