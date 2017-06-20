// Stolen from hltEff; quick hack for the tnp efficiencies
// For the efficiency of some cut as function of some var

#include "hltWP.cxx"
#include "plotStuff.cxx"
#include "/home/afiqaize/root53434/macros/tdrstyle.C"

void tnpEff() {
   gROOT->Reset();

   setTDRStyle();

   // Everything to tinker with should be here
   //float yMin = 0.7001, yMax = 1.0499;
   float yMin = 0.7001, yMax = 1.0099;
   bool doSF = false, doFit = false;
   std::string lHead = "";

   hltLabel hltLbl;
   std::string outPre;
   hltLbl.fileName = "hlt";
   outPre = "npv";

   // -------------------------------------------------- //

   const int nH = 4;

   std::string const inDir = "/home/afiqaize/Downloads/EGM/dev/e_90x/wpTune_110517/root/";
   std::string const outDir = inDir + "../plot_v1/offEff_2/";
   std::pair <std::string, std::string> pairFileLeg[nH];

   pairFileLeg[0] = std::make_pair("dy_off", "Tight16");
   pairFileLeg[1] = std::make_pair("dy_off", "Tight17-0");
   pairFileLeg[2] = std::make_pair("dy_off", "Tight17-1");
   pairFileLeg[3] = std::make_pair("dy_off", "Loose17-1");

   int kColors[nH] = {kBlack, kSpring - 1, kAzure - 1, kPink - 1};

   // For Et
   //const int nBin = 20;
   //float graBins[nBin + 1] = {10., 20., 25., 30., 32., 34., 36., 38., 40., 43., 46., 49., 52., 57., 62., 67., 75., 85., 100., 150., 250.};
   //hltLbl.xLabel = "E_{T} (GeV)"; // x-axis
   //hltLbl.funcTitle = "E_{T}"; // title

   // For nVtx
   const int nBin = 8;
   //float graBins[nBin + 1] = {0.5, 5.5, 10.5, 15.5, 20.5, 25.5, 30.5, 35.5, 40.5, 45.5, 50.5, 55.5, 60.5, 65.5};
   float graBins[nBin + 1] = {0.5, 12.5, 20.5, 25.5, 30.5, 35.5, 42.5, 50.5, 65.5};
   hltLbl.xLabel = "N_{vtx}"; // x-axis
   hltLbl.funcTitle = "N_{vtx}"; // title

   // For rho
   //const int nBin = 8;
   //float graBins[nBin + 1] = {0., 3., 6., 9., 13., 17., 21., 25., 35.}; // rho
   //hltLbl.xLabel = "#rho (GeV)"; // x-axis
   //hltLbl.funcTitle = "#rho"; // title

   // For eta
   //const int nBin = 15;
   //float graBins[nBin + 1] = {-2.5, -2.17, -1.566, -1.4442, -1.0, -0.6, -0.3, -0.1, 0.1, 0.3, 0.6, 1.0, 1.4442, 1.566, 2.17, 2.5};
   //hltLbl.xLabel = "#eta"; // x-axis
   //hltLbl.funcTitle = "#eta"; // title

   /*/ For uniform binning
   const int nBin = 14;
   float graBins[nBin + 1], binWd = 250.;
   for (int iBin = 0; iBin <= nBin; iBin++)
     graBins[iBin] = 0. + (iBin * binWd);

   // -------------------------------------------------- /*/

   hltLbl.yLabel = "Efficiency";
   hltLbl.sLabel = pairFileLeg[0].second + " / " + pairFileLeg[1].second;

   if (hltLbl.fileName == "hlt")
     hltLbl.varTitle = "Working Point";

   if (hltLbl.fileName == "sie")
     hltLbl.varTitle = "Cluster Shape";

   if (hltLbl.fileName == "hoe")
     hltLbl.varTitle = "Hadronic / EM";

   if (hltLbl.fileName == "ecc")
     hltLbl.varTitle = "Relative EcalIso";

   if (hltLbl.fileName == "hcc")
     hltLbl.varTitle = "Relative HcalIso";

   if (hltLbl.fileName == "eop")
     hltLbl.varTitle = "1/E - 1/P";

   if (hltLbl.fileName == "mih")
     hltLbl.varTitle = "Missing Tracker Hits";

   if (hltLbl.fileName == "des")
     hltLbl.varTitle = "Track - Seed Cluster #Delta#eta";

   if (hltLbl.fileName == "dph")
     hltLbl.varTitle = "Track - SC #Delta#phi";

   if (hltLbl.fileName == "chi")
     hltLbl.varTitle = "Track Fit #chi^{2}";

   if (hltLbl.fileName == "tki")
     hltLbl.varTitle = "Relative TrkIso";

   if (hltLbl.fileName == "lol")
     hltLbl.varTitle = "Test";

   // -------------------------------------------------- //

   TH1::SetDefaultSumw2(true);

   TH1F *gra_tb[nH], *gra_te[nH];
   TH1F *gra_pb[nH], *gra_pe[nH];

   for (int iH = 0; iH < nH; iH++) {
     gra_tb[iH] = new TH1F(("gra_tb_" + toStr(iH)).c_str(), "", nBin, graBins);
     gra_te[iH] = new TH1F(("gra_te_" + toStr(iH)).c_str(), "", nBin, graBins);

     gra_pb[iH] = new TH1F(("gra_pb_" + toStr(iH)).c_str(), "", nBin, graBins);
     gra_pe[iH] = new TH1F(("gra_pe_" + toStr(iH)).c_str(), "", nBin, graBins);
   }

   // -------------------------------------------------- //

   // Ensure that each file is added just once
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
   t1->SetBranchAddress("event_rho", &off_rho);
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
   float sc_absEta;
   t1->SetBranchAddress("probe_sc_abseta", &sc_absEta);
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

   float graX = 9999.;

   int nEvt1 = t1->GetEntries();
   cout << "nEvt1 = " << nEvt1 << endl;

   for (int evt1 = 0; evt1 < nEvt1; evt1++) {
     t1->GetEntry(evt1);

     if (sc_et < 35. or std::abs(sc_eta) > 2.5) continue;
     if (passTight80X != 1) continue;
     if (m60To120 != 1) continue;
     if (passL1T != 1) continue;

     if (!checkCand("", vNoMask, hlt_rho,
                   hlt_e, hlt_et, hlt_eta, hlt_phi,
                   hlt_sie, hlt_hoe, hlt_eca, hlt_hca, hlt_eop,
                   hlt_chi, hlt_mih, hlt_des, hlt_dph, hlt_tks,
                   hlt_ps2)) continue;

     const bool passTight16 = checkCand("Tight16", vNoMask, hlt_rho,
                                        hlt_e, hlt_et, hlt_eta, hlt_phi,
                                        hlt_sie, hlt_hoe, hlt_eca, hlt_hca, hlt_eop,
                                        hlt_chi, hlt_mih, hlt_des, hlt_dph, hlt_tks,
                                        hlt_ps2);

     const bool passEye0 = checkCand("EyeBall0_etAll", vNoMask, hlt_rho,
                                     hlt_e, hlt_et, hlt_eta, hlt_phi,
                                     hlt_sie, hlt_hoe, hlt_eca, hlt_hca, hlt_eop,
                                     hlt_chi, hlt_mih, hlt_des, hlt_dph, hlt_tks,
                                     hlt_ps2);

     const bool passItTig = checkCand("IterTig_etAll", vNoMask, hlt_rho,
                                      hlt_e, hlt_et, hlt_eta, hlt_phi,
                                      hlt_sie, hlt_hoe, hlt_eca, hlt_hca, hlt_eop,
                                      hlt_chi, hlt_mih, hlt_des, hlt_dph, hlt_tks,
                                      hlt_ps2);

     const bool passItLoo = checkCand("IterLoo_etAll", vNoMask, hlt_rho,
                                      hlt_e, hlt_et, hlt_eta, hlt_phi,
                                      hlt_sie, hlt_hoe, hlt_eca, hlt_hca, hlt_eop,
                                      hlt_chi, hlt_mih, hlt_des, hlt_dph, hlt_tks,
                                      hlt_ps2);

     // FILL IN THE FILTER TO BE LOOKED AT HERE
     graX = nPV;

     if (true and std::abs(sc_eta) < etaEB) {
       for (int iH = 0; iH < nH; iH++)
         gra_tb[iH]->Fill(graX, finWgt);

       if (passTight16)
         gra_pb[0]->Fill(graX, finWgt);
       if (passEye0)
         gra_pb[1]->Fill(graX, finWgt);
       if (passItTig)
         gra_pb[2]->Fill(graX, finWgt);
       if (passItLoo)
         gra_pb[3]->Fill(graX, finWgt);
     }

     if (std::abs(sc_eta) >= etaET) {
       for (int iH = 0; iH < nH; iH++)
         gra_te[iH]->Fill(graX, finWgt);

       if (passTight16)
         gra_pe[0]->Fill(graX, finWgt);
       if (passEye0)
         gra_pe[1]->Fill(graX, finWgt);
       if (passItTig)
         gra_pe[2]->Fill(graX, finWgt);
       if (passItLoo)
         gra_pe[3]->Fill(graX, finWgt);
     }
   }

   /*/ -------------------------------------------------- //

   for (int iH = 0; iH < nH; iH++)
     fillEff(inDir + pairFileLeg[iH].first, gra_tb[iH], gra_pb[iH], gra_te[iH], gra_pe[iH]);

   // -------------------------------------------------- /*/

   TH1F* frameHist = new TH1F("frameHist", (hltLbl.varTitle + " Efficiency vs " + hltLbl.funcTitle).c_str(), nBin, graBins);
   axHist(frameHist, yMin, yMax, hltLbl.yLabel, 0.027, 1.05, 0.025, hltLbl.xLabel, 0.027, 1.15, 0.025);

   float l1[nBin + 1];
   TGraphAsymmErrors *eff_gb[nH], *eff_ge[nH];
   TH1D *eff_hb[nH], *eff_he[nH];
   double xb[nH], yb[nH], yeb[nH];
   double xe[nH], ye[nH], yee[nH];

   int kColor;
   for (int iH = 0; iH < nH; iH++) {
     kColor = kColors[iH];

     eff_gb[iH] = new TGraphAsymmErrors(gra_pb[iH], gra_tb[iH], "n");
     eff_ge[iH] = new TGraphAsymmErrors(gra_pe[iH], gra_te[iH], "n");

     eff_hb[iH] = new TH1D(("eff_hb_" + toStr(iH)).c_str(), "", nBin, graBins);
     eff_he[iH] = new TH1D(("eff_he_" + toStr(iH)).c_str(), "", nBin, graBins);

     styleGr(eff_gb[iH], kColor, 0, 20, 1, 2.0);
     styleGr(eff_ge[iH], kColor, 0, 20, 1, 2.0);

     xb[iH] = 0.; yb[iH] = 0.; yeb[iH] = 0;
     xe[iH] = 0.; ye[iH] = 0.; yee[iH] = 0;
   }

   for (int iBin = 0; iBin < nBin; iBin++) {
     l1[iBin] = 1.;

     for (int iH = 0; iH < nH; iH++) {
       eff_gb[iH]->GetPoint(iBin, xb[iH], yb[iH]);
       yeb[iH] = eff_gb[iH]->GetErrorY(iBin);

       eff_hb[iH]->SetBinContent(iBin + 1, yb[iH]);
       eff_hb[iH]->SetBinError(iBin + 1, yeb[iH]);

       eff_ge[iH]->GetPoint(iBin, xe[iH], ye[iH]);
       yee[iH] = eff_ge[iH]->GetErrorY(iBin);

       eff_he[iH]->SetBinContent(iBin + 1, ye[iH]);
       eff_he[iH]->SetBinError(iBin + 1, yee[iH]);
     }
   }
   l1[nBin] = 1.;

   // -------------------------------------------------- //

   TGraph *lineb = new TGraph(nBin + 1, graBins, l1);
   lineb->SetLineColor(kYellow + 1);
   lineb->SetLineWidth(2);

   TGraph *linee = new TGraph(nBin + 1, graBins, l1);
   linee->SetLineColor(kYellow + 1);
   linee->SetLineWidth(2);

   TH1D* sfb = new TH1D("", "", nBin, graBins);
   TH1D* sfe = new TH1D("", "", nBin, graBins);
   if (doSF) {
     //sfb->Divide(eff_hb[0], eff_hb[1], 1., 1., "B");
     styleHist(sfb, kBlack, 0, 2, 1, 1.0);
     axHist(sfb, 0.801, 1.199, hltLbl.sLabel, 0.061, 0.49, 0.059, hltLbl.xLabel, 0.061, 1.15, 0.059);

     //sfe->Divide(eff_he[0], eff_he[1], 1., 1., "B");
     styleHist(sfe, kBlack, 0, 2, 1, 1.0);
     axHist(sfe, 0.801, 1.199, hltLbl.sLabel, 0.061, 0.49, 0.059, hltLbl.xLabel, 0.061, 1.15, 0.059);
   }

   TLatex txt;
   txt.SetTextSize(0.035);
   txt.SetTextAlign(13);
   std::string topLeft, topRight;
   topLeft = "#bf{CMS} #it{Preliminary}";
   topRight = "Many fb^{-1} (13 TeV)";

   TLegend *bLeg, *eLeg;
   bLeg = new TLegend();
   eLeg = new TLegend();

   std::string bHead, eHead;
   bHead = "#left|#eta^{e}#right| < " + toStr(etaEB);
   eHead = "1.566 < #left|#eta^{e}#right| < " + toStr(etaEE);

   if (hltLbl.funcTitle == "#eta")
     bHead = "";

   for (int iH = 0; iH < nH; iH++) {
     bLeg->AddEntry(eff_gb[iH], (pairFileLeg[iH].second).c_str(), "lp");
     eLeg->AddEntry(eff_ge[iH], (pairFileLeg[iH].second).c_str(), "lp");
   }

   // -------------------------------------------------- //

   TCanvas *c01 = new TCanvas("c01", "c01", 200, 10, 1000, 1000);
   TCanvas *c02 = new TCanvas("c02", "c02", 200, 10, 1000, 1000);

   if (doSF) {
     txt.SetTextSize(0.035);

     styleLeg(bLeg, 2, 0, 0, 42, 0.03, lHead + bHead);
     putLeg(bLeg, 0.57, 0.95, 0.09, 0.23);

     styleLeg(eLeg, 2, 0, 0, 42, 0.03, lHead + eHead);
     putLeg(eLeg, 0.57, 0.95, 0.09, 0.23);

     c01->cd();

     TPad *pad1 = new TPad("pad1", "pad1", 0., 0.29, 1., 1.);
     pad1->SetBottomMargin(0);
     pad1->Draw();
     pad1->cd();

     frameHist->Draw();
     for (int iH = 0; iH < nH; iH++) {
       eff_gb[iH]->SetHistogram(frameHist);
       if (iH == 0) eff_gb[iH]->Draw("p");
       else eff_gb[iH]->Draw("psame");

       if (iH == 0) eff_gb[iH]->Draw("p");
       else eff_gb[iH]->Draw("psame");
     }

     lineb->Draw("lsame");

     bLeg->Draw();
     //txt.DrawLatexNDC(0.06, 0.928, topLeft.c_str());
     //txt.DrawLatexNDC(0.783, 0.933, topRight.c_str());

     c01->cd();
     TPad *pad2 = new TPad("pad2", "pad2", 0., 0., 1., 0.29);
     pad2->SetTopMargin(0);
     pad2->SetBottomMargin(0.16);
     pad2->Draw();
     pad2->cd();

     sfb->Draw("");
     lineb->Draw("lsame");
     sfb->Draw("same");

     c02->cd();

     TPad *pad3 = new TPad("pad3", "pad3", 0., 0.29, 1., 1.);
     pad3->SetBottomMargin(0);
     pad3->Draw();
     pad3->cd();

     frameHist->Draw();
     for (int iH = 0; iH < nH; iH++) {
       eff_gb[iH]->SetHistogram(frameHist);
       if (iH == 0) eff_ge[iH]->Draw("p");
       else eff_ge[iH]->Draw("psame");

       if (iH == 0) eff_ge[iH]->Draw("p");
       else eff_ge[iH]->Draw("psame");
     }
     linee->Draw("lsame");

     eLeg->Draw();
     //txt.DrawLatexNDC(0.06, 0.928, topLeft.c_str());
     //txt.DrawLatexNDC(0.783, 0.933, topRight.c_str());

     c02->cd();
     TPad *pad4 = new TPad("pad4", "pad4", 0., 0., 1., 0.29);
     pad4->SetTopMargin(0);
     pad4->SetBottomMargin(0.16);
     pad4->Draw();
     pad4->cd();

     sfe->Draw("");
     linee->Draw("lsame");
     sfe->Draw("same");
   }

   else {
     txt.SetTextSize(0.033);

     styleLeg(bLeg, 2, 0, 0, 42, 0.031, lHead + bHead);
     putLeg(bLeg, 0.57, 0.935, 0.115, 0.21);

     styleLeg(eLeg, 2, 0, 0, 42, 0.031, lHead + eHead);
     putLeg(eLeg, 0.57, 0.935, 0.115, 0.21);

     c01->cd();
     c01->SetGridy();

     frameHist->Draw();
     for (int iH = 0; iH < nH; iH++) {
       eff_gb[iH]->SetHistogram(frameHist);
       if (iH == 0) eff_gb[iH]->Draw("p");
       else eff_gb[iH]->Draw("psame");

       if (iH == 0) eff_gb[iH]->Draw("p");
       else eff_gb[iH]->Draw("psame");
     }
     //lineb->Draw("lsame");

     bLeg->Draw();
     //txt.DrawLatexNDC(0.06, 0.935, topLeft.c_str());
     //txt.DrawLatexNDC(0.728, 0.940, topRight.c_str());

     c02->cd();
     c02->SetGridy();

     frameHist->Draw();
     for (int iH = 0; iH < nH; iH++) {
       eff_gb[iH]->SetHistogram(frameHist);
       if (iH == 0) eff_ge[iH]->Draw("p");
       else eff_ge[iH]->Draw("psame");

       if (iH == 0) eff_ge[iH]->Draw("p");
       else eff_ge[iH]->Draw("psame");
     }
     //linee->Draw("lsame");

     eLeg->Draw();
     //txt.DrawLatexNDC(0.06, 0.935, topLeft.c_str());
     //txt.DrawLatexNDC(0.728, 0.940, topRight.c_str());
   }

   // -------------------------------------------------- //

   c01->cd();
   c01->SaveAs((outDir + outPre + "_" + hltLbl.fileName + "_eb.pdf").c_str());
   c01->SaveAs((outDir + outPre + "_" + hltLbl.fileName + "_eb.C").c_str());

   c02->cd();
   c02->SaveAs((outDir + outPre + "_" + hltLbl.fileName + "_ee.pdf").c_str());
   c02->SaveAs((outDir + outPre + "_" + hltLbl.fileName + "_ee.C").c_str());

   c01->Close(); c02->Close();

   gROOT->ProcessLine(".q");
}

int main() {
  tnpEff();
  return 0;
}
