// Stolen from mvaPlot in 740
// For the efficiency of some cut as function of some var

#include "iostream"
#include <iomanip>
#include <TH1.h>
#include <TCanvas.h>
#include <TPad.h>
#include "stdlib.h"
#include <TStyle.h>
#include <TH1D.h>
#include <TGraph.h>
#include <TGraphAsymmErrors.h>
#include <TAxis.h>
#include <TLegend.h>
#include <TFile.h>
#include <string.h>
#include <TChain.h>
#include <TTree.h>
#include <TROOT.h>
#include <TGaxis.h>
#include <TLatex.h>
#include <TBufferFile.h>
#include <TLorentzVector.h>
#include "/home/afiqaize/root53434/macros/tdrstyle.C"

using namespace std;

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

// Too many dumb lines for styling... doing it here
void styleHist(TH1F* varHist, Int_t useCol, Int_t filSty, Int_t marSty, Int_t marSiz, Float_t linWid) {

   varHist->SetFillColor(useCol);
   varHist->SetFillStyle(filSty);
   varHist->SetMarkerColor(useCol);
   varHist->SetMarkerStyle(marSty);
   varHist->SetMarkerSize(marSiz);
   varHist->SetLineColor(useCol);
   varHist->SetLineWidth(linWid);

}

void styleGr(TGraphAsymmErrors* varGr, Int_t useCol, Int_t filSty, Int_t marSty, Int_t marSiz, Float_t linWid) {

   varGr->SetFillColor(useCol);
   varGr->SetFillStyle(filSty);
   varGr->SetMarkerColor(useCol);
   varGr->SetMarkerStyle(marSty);
   varGr->SetMarkerSize(marSiz);
   varGr->SetLineColor(useCol);
   varGr->SetLineWidth(linWid);

}

void axHist(TH1F* varHist, Float_t yMin, Float_t yMax,
            string yTxt, Float_t ySiz, Float_t yOff, Float_t yLab,
            string xTxt, Float_t xSiz, Float_t xOff, Float_t xLab) {

   varHist->SetMinimum(yMin);
   varHist->SetMaximum(yMax);

   varHist->SetYTitle(yTxt.c_str());
   varHist->GetYaxis()->SetTitleSize(ySiz);
   varHist->GetYaxis()->SetTitleOffset(yOff);
   varHist->GetYaxis()->SetLabelSize(yLab);

   varHist->SetXTitle(xTxt.c_str());
   varHist->GetXaxis()->SetTitleSize(xSiz);
   varHist->GetXaxis()->SetTitleOffset(xOff);
   varHist->GetXaxis()->SetLabelSize(xLab);

}

void tnpIso() {

   gROOT->Reset();

   setTDRStyle();

   // Everything to tinker with should be here
   Double_t yMin = .921, yMax = 1.004;

   string varName[6], outPre;
   varName[0] = "lol";
   outPre = "lol_";

   Double_t cut_b = 0.015, cut_e = 0.015;

   // -------------------------------------------------- //

   string hisLeg = "huh", pntLeg = "wut";

   // For nVtx
   //const Int_t nBin = 5; // 8
   //Float_t graBins[nBin + 1] = {0., 3., 6., 9., 13., 17., 21., 25., 35.};
   //Float_t graBins[nBin + 1] = {0.5, 6.5, 10.5, 14.5, 18.5, 22.5, 28.5, 42.5, 60.5};
   //Float_t graBins[nBin + 1] = {0.5, 10.5, 20.5, 30.5, 40.5, 50.5};

   // For eta
   //const Int_t nBin = 13;
   //Float_t graBins[nBin + 1] = {-2.1, -1.56, -1.44, -1.0, -0.6, -0.3, -0.1, 0.1, 0.3, 0.6, 1.0, 1.44, 1.56, 2.1};

   const Int_t nBin = 1;
   Float_t graBins[nBin + 1] = {-0.5, 999.5};

   // -------------------------------------------------- //

   varName[2] = "yeah";
   varName[3] = "Efficiency";
   varName[4] = pntLeg + " / " + hisLeg;
   varName[5] = "ok";

   if (varName[0] == "sie")
     varName[1] = "Cluster Shape";

   if (varName[0] == "hoe")
     varName[1] = "Hadronic / EM";

   if (varName[0] == "ecc")
     varName[1] = "Relative EcalIso";

   if (varName[0] == "hcc")
     varName[1] = "Relative HcalIso";

   if (varName[0] == "eop")
     varName[1] = "1/E - 1/P";

   if (varName[0] == "mih")
     varName[1] = "Missing Tracker Hits";

   if (varName[0] == "des")
     varName[1] = "Track - Seed Cluster #Delta#eta";

   if (varName[0] == "dph")
     varName[1] = "Track - SC #Delta#phi";

   if (varName[0] == "chi")
     varName[1] = "Track Fit #chi^{2}";

   if (varName[0] == "tki")
     varName[1] = "Relative TrkIso";

   if (varName[0] == "lol")
     varName[1] = "Test";

   // -------------------------------------------------- //

   TH1::SetDefaultSumw2(true);

   TH1F* gra_t1b = new TH1F("gra_t1b", "", nBin, graBins);
   TH1F* gra_t1e = new TH1F("gra_t1e", "", nBin, graBins);

   TH1F* gra_t2b = new TH1F("gra_t2b", "", nBin, graBins);
   TH1F* gra_t2e = new TH1F("gra_t2e", "", nBin, graBins);

   TH1F* gra_p1b = new TH1F("gra_p1b", "", nBin, graBins);
   TH1F* gra_p1e = new TH1F("gra_p1e", "", nBin, graBins);

   TH1F* gra_p2b = new TH1F("gra_p2b", "", nBin, graBins);
   TH1F* gra_p2e = new TH1F("gra_p2e", "", nBin, graBins);

   // -------------------------------------------------- //

   string const inDir = "/home/afiqaize/Downloads/HLT_Val/dev/e_80x/file/v11/retune_Jun15/";

   TChain *t1 = new TChain("eleDistr");
   t1->Add((inDir + "skim_m1z1ll.root").c_str());

   Bool_t isMC = false;

   Int_t type;
   t1->SetBranchAddress("itype", &type);
   Float_t weight;
   t1->SetBranchAddress("weight", &weight);
   Float_t puWgt;
   t1->SetBranchAddress("puWgt", &puWgt);
   Int_t nVtx;
   t1->SetBranchAddress("nVtx", &nVtx);
   Float_t rho;
   t1->SetBranchAddress("rho", &rho);

   Int_t pass[10];
   t1->SetBranchAddress("passHLT", pass);
   Int_t genMatch[10];
   t1->SetBranchAddress("genMatch", genMatch);
   Int_t n;
   t1->SetBranchAddress("hlt_n", &n);
   Float_t et[10];
   t1->SetBranchAddress("hlt_et", et);
   Float_t etr[10];
   t1->SetBranchAddress("hlt_etr", etr);
   Float_t e[10];
   t1->SetBranchAddress("hlt_e", e);
   Float_t er[10];
   t1->SetBranchAddress("hlt_er", er);
   Float_t eta[10];
   t1->SetBranchAddress("hlt_eta", eta);
   Float_t phi[10];
   t1->SetBranchAddress("hlt_phi", phi);
   Float_t sie[10];
   t1->SetBranchAddress("hlt_sie", sie);
   Float_t hoe[10];
   t1->SetBranchAddress("hlt_hoe", hoe);
   Float_t eca[10];
   t1->SetBranchAddress("hlt_eca", eca);
   Float_t ecc[10];
   t1->SetBranchAddress("hlt_ecc", ecc);
   Float_t ecu[10];
   t1->SetBranchAddress("hlt_ecu", ecu);
   Float_t hca[10];
   t1->SetBranchAddress("hlt_hca", hca);
   Float_t hcc[10];
   t1->SetBranchAddress("hlt_hcc", hcc);
   Float_t hcu[10];
   t1->SetBranchAddress("hlt_hcu", hcu);
   Float_t eop[10];
   t1->SetBranchAddress("hlt_eop", eop);
   Float_t chi[10];
   t1->SetBranchAddress("hlt_chi", chi);
   Float_t mih[10];
   t1->SetBranchAddress("hlt_mih", mih);
   Float_t det[10];
   t1->SetBranchAddress("hlt_det", det);
   Float_t des[10];
   t1->SetBranchAddress("hlt_des", des);
   Float_t dph[10];
   t1->SetBranchAddress("hlt_dph", dph);
   Float_t tki[10];
   t1->SetBranchAddress("hlt_tki", tki);

   Int_t nBX, nPUtrue, gp_n;
   Int_t BX[100], nPUobs[100];
   Float_t genWgt, gp_pt[10], gp_eta[10], gp_phi[10];

    if (isMC) {

    t1->SetBranchAddress("genWgt", &genWgt);
    t1->SetBranchAddress("gp_n", &gp_n);
    t1->SetBranchAddress("gp_pt", gp_pt);
    t1->SetBranchAddress("gp_eta", gp_eta);
    t1->SetBranchAddress("gpphi", gp_phi);
    t1->SetBranchAddress("nBX", &nBX);
    t1->SetBranchAddress("BX", BX);
    t1->SetBranchAddress("nPUtrue", &nPUtrue);
    t1->SetBranchAddress("nPUobs", nPUobs);

    }

   // -------------------------------------------------- //
   // The TnP version of efficiency checker

   TLorentzVector p4Tag, p4Probe;
   Float_t finWgt = 1.;
   Float_t graY1 = 9999., graY2 = 9999.;
   Float_t graX = 9999.;

   Int_t nEvt1 = t1->GetEntries();
   cout << "nEvt1 = " << nEvt1 << endl;

   for (Int_t evt1 = 0; evt1 < nEvt1; evt1++) {

     t1->GetEntry(evt1);
     finWgt = puWgt * weight;
     if (n < 2) continue;

     for (Int_t iTag = 0; iTag < n; iTag++) {

       if (pass[iTag] != 1) continue;
       if ((et[iTag] < 25.) or (fabs(eta[iTag]) > 2.5)) continue;

       p4Tag.SetPtEtaPhiE(et[iTag], eta[iTag], phi[iTag], e[iTag]);

       for (Int_t iProbe = 0; iProbe < n; iProbe++) {

         if (iProbe == iTag) continue;
         if ((et[iProbe] < 25.) or (fabs(eta[iProbe]) > 2.5)) continue;

         p4Probe.SetPtEtaPhiE(et[iProbe], eta[iProbe], phi[iProbe], e[iProbe]);

         if ((p4Tag + p4Probe).M() < 70. or (p4Tag + p4Probe).M() > 110.) continue;

         if (!checkCand("WPTight", eta[iProbe],
                        sie[iProbe], hoe[iProbe], ecc[iProbe], hcc[iProbe], eop[iProbe],
                        chi[iProbe], mih[iProbe], des[iProbe], dph[iProbe], tki[iProbe])) continue;

         // FILL IN THE FILTER TO BE LOOKED AT HERE
         graY1 = dph[iProbe];
         graY2 = dph[iProbe];
         graX = et[iProbe];

         if (type == -1) {

           if (fabs(eta[iProbe]) < 1.444) {

             gra_t1b->Fill(graX, finWgt);

             if (graY1 < cut_b)
               gra_p1b->Fill(graX, finWgt);
 
           }

           if (fabs(eta[iProbe]) >= 1.566) {

             gra_t1e->Fill(graX, finWgt);

             if (graY1 < cut_e)
               gra_p1e->Fill(graX, finWgt);

           }
         }

         if (type == 99) {

           if (fabs(eta[iProbe]) < 1.444) {
           //if (true) {

             gra_t2b->Fill(graX, finWgt);

             if (graY2 < cut_b)
               gra_p2b->Fill(graX, finWgt);

           }

           if (fabs(eta[iProbe]) >= 1.566) {

             gra_t2e->Fill(graX, finWgt);

             if (graY2 < cut_e)
               gra_p2e->Fill(graX, finWgt);

           }
         }
       }
     }
   }

   // -------------------------------------------------- //
   /*/ The all-cand version of efficiency checker

   TLorentzVector p4Cand;
   Float_t finWgt = 1., graY = 9999., graX = 9999.;

   Int_t nEvt1 = t1->GetEntries();
   cout << "nEvt1 = " << nEvt1 << endl;

   for (Int_t evt1 = 0; evt1 < nEvt1; evt1++) {

     t1->GetEntry(evt1);
     finWgt = puWgt * weight;

     for (Int_t iCand = 0; iCand < n; iCand++) {

       if (et[iCand] < 15.) continue;

       if (!checkCand("", eta[iProbe],
                      sie[iProbe], hoe[iProbe], ecc[iProbe], hcc[iProbe], eop[iProbe],
                      chi[iProbe], mih[iProbe], des[iProbe], dph[iProbe], tki[iProbe])) continue;

       // FILL IN THE FILTER TO BE LOOKED AT HERE
       graY = sie[iCand];
       graX = (Float_t) nVtx;

       if (fabs(eta[iCand]) < 1.4791) {

         gra_t1b->Fill(graX, finWgt);

         if (graY < cut_b)
           gra_p1b->Fill(graX, finWgt);

       }

       if (fabs(eta[iCand]) >= 1.4791) {

         gra_t1e->Fill(graX, finWgt);

         if (graY < cut_e)
           gra_p1e->Fill(graX, finWgt);

       }
     }
   }

   // -------------------------------------------------- /*/

   TGraphAsymmErrors *eff_g1b = new TGraphAsymmErrors(gra_p1b, gra_t1b, "n");
   TGraphAsymmErrors *eff_g1e = new TGraphAsymmErrors(gra_p1e, gra_t1e, "n");
   styleGr(eff_g1b, kRed + 1, 0, 20, 1, 2.0);
   styleGr(eff_g1e, kRed + 1, 0, 20, 1, 2.0);

   TGraphAsymmErrors *eff_g2b = new TGraphAsymmErrors(gra_p2b, gra_t2b, "n");
   TGraphAsymmErrors *eff_g2e = new TGraphAsymmErrors(gra_p2e, gra_t2e, "n");
   styleGr(eff_g2b, kAzure + 1, 0, 2, 1, 2.0);
   styleGr(eff_g2e, kAzure + 1, 0, 2, 1, 2.0);

   TH1F* frameHist = new TH1F("frameHist", (varName[1] + " Efficiency vs " + varName[5]).c_str(), nBin, graBins);
   axHist(frameHist, yMin, yMax, varName[3], 0.027, 1.05, 0.025, varName[2], 0.027, 1.15, 0.025);

   TH1F* eff_h1b = new TH1F("", "", nBin, graBins);
   TH1F* eff_h1e = new TH1F("", "", nBin, graBins);

   TH1F* eff_h2b = new TH1F("", "", nBin, graBins);
   TH1F* eff_h2e = new TH1F("", "", nBin, graBins);

   Float_t l1[nBin + 1];

   Double_t x_1b = 0., y_1b = 0., ye_1b = 0., x_2b = 0., y_2b = 0., ye_2b = 0.;
   Double_t x_1e = 0., y_1e = 0., ye_1e = 0., x_2e = 0., y_2e = 0., ye_2e = 0.;

   for (Int_t i = 0; i < nBin; i++) {

     l1[i] = 1.;

     eff_g1b->GetPoint(i, x_1b, y_1b);
     ye_1b = eff_g1b->GetErrorY(i);
     eff_g2b->GetPoint(i, x_2b, y_2b);
     ye_2b = eff_g2b->GetErrorY(i);

     eff_h1b->SetBinContent(i+1, y_1b);
     eff_h1b->SetBinError(i+1, ye_1b);
     eff_h2b->SetBinContent(i+1, y_2b);
     eff_h2b->SetBinError(i+1, ye_2b);

     eff_g1e->GetPoint(i, x_1e, y_1e);
     ye_1e = eff_g1e->GetErrorY(i);
     eff_g2e->GetPoint(i, x_2e, y_2e);
     ye_2e = eff_g2e->GetErrorY(i);

     eff_h1e->SetBinContent(i+1, y_1e);
     eff_h1e->SetBinError(i+1, ye_1e);
     eff_h2e->SetBinContent(i+1, y_2e);
     eff_h2e->SetBinError(i+1, ye_2e);

   }

   l1[nBin] = 1.;

   //cout << "EB Pas: "  << gra_p1b->GetBinContent(1) << " \\pm " << gra_p1b->GetBinError(1) << endl;
   //cout << "EB Tot: "  << gra_t1b->GetBinContent(1) << " \\pm " << gra_t1b->GetBinError(1) << endl;
   cout << std::setprecision(4) << "EB 1 Eff: " << eff_h1b->GetBinContent(1) << " \\pm " << eff_h1b->GetBinError(1) << ", cut " << cut_b << endl;
   cout << std::setprecision(4) << "EB 2 Eff: " << eff_h2b->GetBinContent(1) << " \\pm " << eff_h2b->GetBinError(1) << ", cut " << cut_b << endl;

   //cout << endl;

   //cout << "EE Pas: "  << gra_p1e->GetBinContent(1) << " \\pm " << gra_p1e->GetBinError(1) << endl;
   //cout << "EE Tot: "  << gra_t1e->GetBinContent(1) << " \\pm " << gra_t1e->GetBinError(1) << endl;
   cout << std::setprecision(5) << "EE 1 Eff: " << eff_h1e->GetBinContent(1) << " $\\pm$ " << eff_h1e->GetBinError(1) << ", cut " << cut_e << endl;
   cout << std::setprecision(5) << "EE 2 Eff: " << eff_h2e->GetBinContent(1) << " $\\pm$ " << eff_h2e->GetBinError(1) << ", cut " << cut_e << endl;

   // -------------------------------------------------- //

   TGraph *lineb = new TGraph(nBin + 1, graBins, l1);
   lineb->SetLineColor(kYellow + 1);
   lineb->SetLineWidth(2);

   TGraph *linee = new TGraph(nBin + 1, graBins, l1);
   linee->SetLineColor(kYellow + 1);
   linee->SetLineWidth(2);

   TH1F* sfb = new TH1F("", "", nBin, graBins);
   sfb->Divide(eff_h1b, eff_h2b, 1., 1., "B");
   styleHist(sfb, kBlack, 0, 2, 1, 1.0);
   axHist(sfb, 0.801, 1.199, varName[4], 0.061, 0.49, 0.059, varName[2], 0.061, 1.15, 0.059);

   TH1F* sfe = new TH1F("", "", nBin, graBins);
   sfe->Divide(eff_h1e, eff_h2e, 1., 1., "B");
   styleHist(sfe, kBlack, 0, 2, 1, 1.0);
   axHist(sfe, 0.801, 1.199, varName[4], 0.061, 0.49, 0.059, varName[2], 0.061, 1.15, 0.059);

   TLatex txt;
   txt.SetTextSize(0.035);
   txt.SetTextAlign(13);
   string topLeft, topRight;
   topLeft = "#bf{CMS} #it{Preliminary}";
   topRight = "0.8 fb^{-1} (13 TeV)";

   TLegend *leg01 = new TLegend(.81, .05, .95, .23);
   leg01->SetHeader("#left|#eta^{e}#right| < 1.444");
   leg01->AddEntry(eff_g2b, (hisLeg).c_str(), "lp");
   leg01->AddEntry(eff_g1b, (pntLeg).c_str(), "lp");
   leg01->SetFillColor(0);
   leg01->SetBorderSize(0);
   leg01->SetTextSize(0.03);
   leg01->SetTextFont(42);

   TLegend *leg02 = new TLegend(.81, .05, .95, .23);
   leg02->SetHeader("#left|#eta^{e}#right| > 1.566");
   leg02->AddEntry(eff_g2e, (hisLeg).c_str(), "lp");
   leg02->AddEntry(eff_g1e, (pntLeg).c_str(), "lp");
   leg02->SetFillColor(0);
   leg02->SetBorderSize(0);
   leg02->SetTextSize(0.03);
   leg02->SetTextFont(42);

   // -------------------------------------------------- //

   string const outDir = inDir + "";

   TCanvas *c01 = new TCanvas("c01", "c01", 200, 10, 1000, 1000);
   TCanvas *c02 = new TCanvas("c02", "c02", 200, 10, 1000, 1000);

   c01->cd();

   TPad *pad1 = new TPad("pad1", "pad1", 0., 0.29, 1., 1.);
   pad1->SetBottomMargin(0);
   pad1->Draw();
   pad1->cd();

   eff_g2b->SetHistogram(frameHist);
   eff_g1b->SetHistogram(frameHist);
   frameHist->Draw("func");

   eff_g2b->Draw("p");
   eff_g1b->Draw("psame");
   lineb->Draw("lsame");

   leg01->Draw();
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

   c01->cd();
   c01->SaveAs((outDir + outPre + varName[0] + "_eb.pdf").c_str());

   c02->cd();

   TPad *pad3 = new TPad("pad3", "pad3", 0., 0.29, 1., 1.);
   pad3->SetBottomMargin(0);
   pad3->Draw();
   pad3->cd();

   eff_g2e->SetHistogram(frameHist);
   eff_g1e->SetHistogram(frameHist);
   frameHist->Draw("func");

   eff_g2e->Draw("p");
   eff_g1e->Draw("psame");
   linee->Draw("lsame");

   leg02->Draw();
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

   c02->cd();
   //c02->SaveAs((outDir + outPre + varName[0] + "_ee.pdf").c_str());

   // -------------------------------------------------- //

   c01->Close(); c02->Close();
   gROOT->ProcessLine(".q");
   
}

int main() {
  tnpIso();
  return 0;
}



