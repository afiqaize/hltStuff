// Stolen from mvaPlot in 740
// For the tnp hlt vs reco electron plotting
// Nov 25 updated and streamlined
// Usage: root -l tnpTune.cxx++

#include "iostream"
#include <iomanip>
#include <TH1.h>
#include <TCanvas.h>
#include <TPad.h>
#include "stdlib.h"
#include <TStyle.h>
#include <TH1D.h>
#include <TGraph.h>
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
  varThr[8] = 0.015; varThr[9] = 9990.06;
  }

  else if (fabs(eta) > 1.4791 && setWP == "WPTight") {
  varThr[0] = 0.029; varThr[1] = 0.05;
  varThr[2] = 0.105; varThr[3] = 0.095;
  varThr[4] = 0.008; varThr[5] = 2.5;
  varThr[6] = 1.5  ; varThr[7] = 0.006;
  varThr[8] = 0.015; varThr[9] = 9990.06;
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
void styleHist(TH1D* varHist, Int_t useCol, Int_t filSty, Int_t marSty, Int_t marSiz, Float_t linWid) {

   varHist->SetFillColor(useCol);
   varHist->SetFillStyle(filSty);
   varHist->SetMarkerColor(useCol);
   varHist->SetMarkerStyle(marSty);
   varHist->SetMarkerSize(marSiz);
   varHist->SetLineColor(useCol);
   varHist->SetLineWidth(linWid);

}

void axHist(TH1D* varHist, Float_t yMin, Float_t yMax,
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

void styleGr(TGraph* varGr, Int_t useCol, Int_t filSty, Int_t marSty, Int_t marSiz, Float_t linWid) {

   varGr->SetFillColor(useCol);
   varGr->SetFillStyle(filSty);
   varGr->SetMarkerColor(useCol);
   varGr->SetMarkerStyle(marSty);
   varGr->SetMarkerSize(marSiz);
   varGr->SetLineColor(useCol);
   varGr->SetLineWidth(linWid);

}

void axGr(TGraph* varGr, Float_t yMin, Float_t yMax,
            string yTxt, Float_t ySiz, Float_t yOff, Float_t yLab,
            string xTxt, Float_t xSiz, Float_t xOff, Float_t xLab) {

   varGr->SetMinimum(yMin);
   varGr->SetMaximum(yMax);

   varGr->GetYaxis()->SetTitle(yTxt.c_str());
   varGr->GetYaxis()->SetTitleSize(ySiz);
   varGr->GetYaxis()->SetTitleOffset(yOff);
   varGr->GetYaxis()->SetLabelSize(yLab);

   varGr->GetXaxis()->SetTitle(xTxt.c_str());
   varGr->GetXaxis()->SetTitleSize(xSiz);
   varGr->GetXaxis()->SetTitleOffset(xOff);
   varGr->GetXaxis()->SetLabelSize(xLab);

}

Double_t effCalc(Int_t nStep, TH1D* hist) {

  Double_t eff = 0.;
  Int_t lim = 0;

  for (Int_t j = nStep; j > lim; j--)
    eff += hist->GetBinContent(j);

  return eff;

}

void tnpTune() {

   gROOT->Reset();

   setTDRStyle();

   // Everything to tinker with should be here
   Double_t yMin_b = .0001, yMax_b = .9999;
   Double_t yMin_e = .0001, yMax_e = .9999;

   string varName[5], outPre, legHead;
   varName[0] = "tki";
   outPre = "hlt_";
   legHead = "";

   Bool_t drawLog = true;
   Double_t cut_b = 0.06, cut_e = 0.06;

   // -------------------------------------------------- //

   string sigLeg = "DY", bkgLeg = "QCD";

   Int_t meeb_nBin = 82, meee_nBin = 82;
   Double_t meeb_max = 110.5, meee_max = 110.5;
   Double_t meeb_min = 69.5, meee_min = 69.5;

   Int_t phib_nBin = 12, phie_nBin = 12;
   Double_t phib_max = 3.142, phie_max = 3.142;
   Double_t phib_min = -3.142, phie_min = -3.142;

   // For Et
   Int_t eetb_nBin = 120, eete_nBin = 120;
   Double_t eetb_max = 360., eete_max = 360.;
   Double_t eetb_min = 0., eete_min = 0.;

   Int_t sieb_nBin = 100, siee_nBin = 120;
   Double_t sieb_max = .02, siee_max = .06;
   Double_t sieb_min = 0., siee_min = 0.;

   // For H/E
   Int_t hoeb_nBin = 40, hoee_nBin = 60;
   Double_t hoeb_max = .2, hoee_max = .3;
   Double_t hoeb_min = 0., hoee_min = 0.;

   Int_t ecab_nBin = 60, ecae_nBin = 60;
   Double_t ecab_max = 30., ecae_max = 30.;
   Double_t ecab_min = 0., ecae_min = 0.;

   Int_t eccb_nBin = 60, ecce_nBin = 60;
   Double_t eccb_max = .6, ecce_max = .6;
   Double_t eccb_min = 0., ecce_min = 0.;

   Int_t hcab_nBin = 60, hcae_nBin = 60;
   Double_t hcab_max = 30., hcae_max = 30.;
   Double_t hcab_min = 0., hcae_min = 0.;

   Int_t hccb_nBin = 60, hcce_nBin = 60;
   Double_t hccb_max = .6, hcce_max = .6;
   Double_t hccb_min = 0., hcce_min = 0.;

   Int_t eopb_nBin = 100, eope_nBin = 100;
   Double_t eopb_max = .1, eope_max = .1;
   Double_t eopb_min = 0., eope_min = 0.;

   Int_t chib_nBin = 150, chie_nBin = 150;
   Double_t chib_max = 30., chie_max = 30.;
   Double_t chib_min = 0., chie_min = 0.;

   Int_t mihb_nBin = 4, mihe_nBin = 6;
   Double_t mihb_max = 3.5, mihe_max = 5.5;
   Double_t mihb_min = -0.5, mihe_min = -0.5;

   Int_t desb_nBin = 60, dese_nBin = 60;
   Double_t desb_max = 0.03, dese_max = 0.03;
   Double_t desb_min = 0., dese_min = 0.;

   Int_t dphb_nBin = 100, dphe_nBin = 100;
   Double_t dphb_max = 0.1, dphe_max = 0.1;
   Double_t dphb_min = 0., dphe_min = 0.;

   Int_t tkib_nBin = 100, tkie_nBin = 100;
   Double_t tkib_max = 0.5, tkie_max = 0.5;
   Double_t tkib_min = 0., tkie_min = 0.;

   // -------------------------------------------------- //

   //varName[3] = "Evt / bin";
   varName[3] = "a. u.";

   if (varName[0] == "sie") {

     varName[1] = "Cluster Shape";
     varName[2] = "#sigma_{i#etai#eta}";

   }

   if (varName[0] == "hoe") {

     varName[1] = "Hadronic / EM";
     varName[2] = "H/E";

   }

   if (varName[0] == "ecu" or varName[0] == "eca") {

     varName[1] = "EcalIso";
     varName[2] = "EcalIso (GeV)";

   }

   if (varName[0] == "ecc") {

     varName[1] = "Relative EcalIso";
     varName[2] = "EcalIso / E_{T}";

   }

   if (varName[0] == "hcu" or varName[0] == "hca") {

     varName[1] = "HcalIso";
     varName[2] = "HcalIso (GeV)";

   }

   if (varName[0] == "hcc") {

     varName[1] = "Relative HcalIso";
     varName[2] = "HcalIso / E_{T}";

   }

   if (varName[0] == "eop") {

     varName[1] = "1/E - 1/P";
     varName[2] = "1/E - 1/P (GeV^{-1})";

   }

   if (varName[0] == "mih") {

     varName[1] = "Missing Tracker Hits";
     varName[2] = "Missing Hits";

   }

   if (varName[0] == "des") {

     varName[1] = "Track - Seed Cluster #Delta#eta";
     varName[2] = "#Delta#eta_{seed}";

   }

   if (varName[0] == "det") {

     varName[1] = "Track - SC #Delta#eta";
     varName[2] = "#Delta#eta";

   }

   if (varName[0] == "dph") {

     varName[1] = "Track - SC #Delta#phi";
     varName[2] = "#Delta#phi";

   }

   if (varName[0] == "chi") {

     varName[1] = "Track Fit #chi^{2}";
     varName[2] = "Fit #chi^{2}";

   }

   if (varName[0] == "tki") {

     varName[1] = "Relative TrkIso";
     varName[2] = "TrkIso / E_{T}";

   }

   if (varName[0] == "lol") {

     varName[1] = "Testing";
     varName[2] = "Whatever";

   }

   // -------------------------------------------------- //

   TH1::SetDefaultSumw2(true);
   //TGaxis::SetMaxDigits(3););

   TH1D* eet_1b = new TH1D("eet_1b", (varName[1] + " Distribution").c_str(), eetb_nBin, eetb_min, eetb_max);
   TH1D* eet_1e = new TH1D("eet_1e", (varName[1] + " Distribution").c_str(), eete_nBin, eete_min, eete_max);
   styleHist(eet_1b, kRed + 1, 0, 20, 1, 2.0);
   styleHist(eet_1e, kRed + 1, 0, 20, 1, 2.0);

   TH1D* sie_1b = new TH1D("sie_1b", (varName[1] + " Distribution").c_str(), sieb_nBin, sieb_min, sieb_max);
   TH1D* sie_1e = new TH1D("sie_1e", (varName[1] + " Distribution").c_str(), siee_nBin, siee_min, siee_max);
   styleHist(sie_1b, kRed + 1, 0, 20, 1, 2.0);
   styleHist(sie_1e, kRed + 1, 0, 20, 1, 2.0);

   TH1D* hoe_1b = new TH1D("hoe_1b", (varName[1] + " Distribution").c_str(), hoeb_nBin, hoeb_min, hoeb_max);
   TH1D* hoe_1e = new TH1D("hoe_1e", (varName[1] + " Distribution").c_str(), hoee_nBin, hoee_min, hoee_max);
   styleHist(hoe_1b, kRed + 1, 0, 20, 1, 2.0);
   styleHist(hoe_1e, kRed + 1, 0, 20, 1, 2.0);

   TH1D* eca_1b = new TH1D("eca_1b", (varName[1] + " Distribution").c_str(), ecab_nBin, ecab_min, ecab_max);
   TH1D* eca_1e = new TH1D("eca_1e", (varName[1] + " Distribution").c_str(), ecae_nBin, ecae_min, ecae_max);
   styleHist(eca_1b, kRed + 1, 0, 20, 1, 2.0);
   styleHist(eca_1e, kRed + 1, 0, 20, 1, 2.0);

   TH1D* ecc_1b = new TH1D("ecc_1b", (varName[1] + " Distribution").c_str(), eccb_nBin, eccb_min, eccb_max);
   TH1D* ecc_1e = new TH1D("ecc_1e", (varName[1] + " Distribution").c_str(), ecce_nBin, ecce_min, ecce_max);
   styleHist(ecc_1b, kRed + 1, 0, 20, 1, 2.0);
   styleHist(ecc_1e, kRed + 1, 0, 20, 1, 2.0);

   TH1D* hca_1b = new TH1D("hca_1b", (varName[1] + " Distribution").c_str(), hcab_nBin, hcab_min, hcab_max);
   TH1D* hca_1e = new TH1D("hca_1e", (varName[1] + " Distribution").c_str(), hcae_nBin, hcae_min, hcae_max);
   styleHist(hca_1b, kRed + 1, 0, 20, 1, 2.0);
   styleHist(hca_1e, kRed + 1, 0, 20, 1, 2.0);

   TH1D* hcc_1b = new TH1D("hcc_1b", (varName[1] + " Distribution").c_str(), hccb_nBin, hccb_min, hccb_max);
   TH1D* hcc_1e = new TH1D("hcc_1e", (varName[1] + " Distribution").c_str(), hcce_nBin, hcce_min, hcce_max);
   styleHist(hcc_1b, kRed + 1, 0, 20, 1, 2.0);
   styleHist(hcc_1e, kRed + 1, 0, 20, 1, 2.0);

   TH1D* eop_1b = new TH1D("eop_1b", (varName[1] + " Distribution").c_str(), eopb_nBin, eopb_min, eopb_max);
   TH1D* eop_1e = new TH1D("eop_1e", (varName[1] + " Distribution").c_str(), eope_nBin, eope_min, eope_max);
   styleHist(eop_1b, kRed + 1, 0, 20, 1, 2.0);
   styleHist(eop_1e, kRed + 1, 0, 20, 1, 2.0);

   TH1D* chi_1b = new TH1D("chi_1b", (varName[1] + " Distribution").c_str(), chib_nBin, chib_min, chib_max);
   TH1D* chi_1e = new TH1D("chi_1e", (varName[1] + " Distribution").c_str(), chie_nBin, chie_min, chie_max);
   styleHist(chi_1b, kRed + 1, 0, 20, 1, 2.0);
   styleHist(chi_1e, kRed + 1, 0, 20, 1, 2.0);

   TH1D* mih_1b = new TH1D("mih_1b", (varName[1] + " Distribution").c_str(), mihb_nBin, mihb_min, mihb_max);
   TH1D* mih_1e = new TH1D("mih_1e", (varName[1] + " Distribution").c_str(), mihe_nBin, mihe_min, mihe_max);
   styleHist(mih_1b, kRed + 1, 0, 20, 1, 2.0);
   styleHist(mih_1e, kRed + 1, 0, 20, 1, 2.0);

   TH1D* des_1b = new TH1D("des_1b", (varName[1] + " Distribution").c_str(), desb_nBin, desb_min, desb_max);
   TH1D* des_1e = new TH1D("des_1e", (varName[1] + " Distribution").c_str(), dese_nBin, dese_min, dese_max);
   styleHist(des_1b, kRed + 1, 0, 20, 1, 2.0);
   styleHist(des_1e, kRed + 1, 0, 20, 1, 2.0);

   TH1D* dph_1b = new TH1D("dph_1b", (varName[1] + " Distribution").c_str(), dphb_nBin, dphb_min, dphb_max);
   TH1D* dph_1e = new TH1D("dph_1e", (varName[1] + " Distribution").c_str(), dphe_nBin, dphe_min, dphe_max);
   styleHist(dph_1b, kRed + 1, 0, 20, 1, 2.0);
   styleHist(dph_1e, kRed + 1, 0, 20, 1, 2.0);

   TH1D* tki_1b = new TH1D("tki_1b", (varName[1] + " Distribution").c_str(), tkib_nBin, tkib_min, tkib_max);
   TH1D* tki_1e = new TH1D("tki_1e", (varName[1] + " Distribution").c_str(), tkie_nBin, tkie_min, tkie_max);
   styleHist(tki_1b, kRed + 1, 0, 20, 1, 2.0);
   styleHist(tki_1e, kRed + 1, 0, 20, 1, 2.0);

   // -------------------------------------------------- //

   TH1D* eet_2b = new TH1D("eet_2b", (varName[1] + " Distribution").c_str(), eetb_nBin, eetb_min, eetb_max);
   TH1D* eet_2e = new TH1D("eet_2e", (varName[1] + " Distribution").c_str(), eete_nBin, eete_min, eete_max);
   styleHist(eet_2b, kAzure + 1, 1001, 2, 1, 2.0);
   styleHist(eet_2e, kAzure + 1, 1001, 2, 1, 2.0);

   TH1D* sie_2b = new TH1D("sie_2b", (varName[1] + " Distribution").c_str(), sieb_nBin, sieb_min, sieb_max);
   TH1D* sie_2e = new TH1D("sie_2e", (varName[1] + " Distribution").c_str(), siee_nBin, siee_min, siee_max);
   styleHist(sie_2b, kAzure + 1, 1001, 2, 1, 2.0);
   styleHist(sie_2e, kAzure + 1, 1001, 2, 1, 2.0);

   TH1D* hoe_2b = new TH1D("hoe_2b", (varName[1] + " Distribution").c_str(), hoeb_nBin, hoeb_min, hoeb_max);
   TH1D* hoe_2e = new TH1D("hoe_2e", (varName[1] + " Distribution").c_str(), hoee_nBin, hoee_min, hoee_max);
   styleHist(hoe_2b, kAzure + 1, 1001, 2, 1, 2.0);
   styleHist(hoe_2e, kAzure + 1, 1001, 2, 1, 2.0);

   TH1D* eca_2b = new TH1D("eca_2b", (varName[1] + " Distribution").c_str(), ecab_nBin, ecab_min, ecab_max);
   TH1D* eca_2e = new TH1D("eca_2e", (varName[1] + " Distribution").c_str(), ecae_nBin, ecae_min, ecae_max);
   styleHist(eca_2b, kAzure + 1, 1001, 2, 1, 2.0);
   styleHist(eca_2e, kAzure + 1, 1001, 2, 1, 2.0);

   TH1D* ecc_2b = new TH1D("ecc_2b", (varName[1] + " Distribution").c_str(), eccb_nBin, eccb_min, eccb_max);
   TH1D* ecc_2e = new TH1D("ecc_2e", (varName[1] + " Distribution").c_str(), ecce_nBin, ecce_min, ecce_max);
   styleHist(ecc_2b, kAzure + 1, 1001, 2, 1, 2.0);
   styleHist(ecc_2e, kAzure + 1, 1001, 2, 1, 2.0);

   TH1D* hca_2b = new TH1D("hca_2b", (varName[1] + " Distribution").c_str(), hcab_nBin, hcab_min, hcab_max);
   TH1D* hca_2e = new TH1D("hca_2e", (varName[1] + " Distribution").c_str(), hcae_nBin, hcae_min, hcae_max);
   styleHist(hca_2b, kAzure + 1, 1001, 2, 1, 2.0);
   styleHist(hca_2e, kAzure + 1, 1001, 2, 1, 2.0);

   TH1D* hcc_2b = new TH1D("hcc_2b", (varName[1] + " Distribution").c_str(), hccb_nBin, hccb_min, hccb_max);
   TH1D* hcc_2e = new TH1D("hcc_2e", (varName[1] + " Distribution").c_str(), hcce_nBin, hcce_min, hcce_max);
   styleHist(hcc_2b, kAzure + 1, 1001, 2, 1, 2.0);
   styleHist(hcc_2e, kAzure + 1, 1001, 2, 1, 2.0);

   TH1D* eop_2b = new TH1D("eop_2b", (varName[1] + " Distribution").c_str(), eopb_nBin, eopb_min, eopb_max);
   TH1D* eop_2e = new TH1D("eop_2e", (varName[1] + " Distribution").c_str(), eope_nBin, eope_min, eope_max);
   styleHist(eop_2b, kAzure + 1, 1001, 2, 1, 2.0);
   styleHist(eop_2e, kAzure + 1, 1001, 2, 1, 2.0);

   TH1D* chi_2b = new TH1D("chi_2b", (varName[1] + " Distribution").c_str(), chib_nBin, chib_min, chib_max);
   TH1D* chi_2e = new TH1D("chi_2e", (varName[1] + " Distribution").c_str(), chie_nBin, chie_min, chie_max);
   styleHist(chi_2b, kAzure + 1, 1001, 2, 1, 2.0);
   styleHist(chi_2e, kAzure + 1, 1001, 2, 1, 2.0);

   TH1D* mih_2b = new TH1D("mih_2b", (varName[1] + " Distribution").c_str(), mihb_nBin, mihb_min, mihb_max);
   TH1D* mih_2e = new TH1D("mih_2e", (varName[1] + " Distribution").c_str(), mihe_nBin, mihe_min, mihe_max);
   styleHist(mih_2b, kAzure + 1, 1001, 2, 1, 2.0);
   styleHist(mih_2e, kAzure + 1, 1001, 2, 1, 2.0);

   TH1D* des_2b = new TH1D("des_2b", (varName[1] + " Distribution").c_str(), desb_nBin, desb_min, desb_max);
   TH1D* des_2e = new TH1D("des_2e", (varName[1] + " Distribution").c_str(), dese_nBin, dese_min, dese_max);
   styleHist(des_2b, kAzure + 1, 1001, 2, 1, 2.0);
   styleHist(des_2e, kAzure + 1, 1001, 2, 1, 2.0);

   TH1D* dph_2b = new TH1D("dph_2b", (varName[1] + " Distribution").c_str(), dphb_nBin, dphb_min, dphb_max);
   TH1D* dph_2e = new TH1D("dph_2e", (varName[1] + " Distribution").c_str(), dphe_nBin, dphe_min, dphe_max);
   styleHist(dph_2b, kAzure + 1, 1001, 2, 1, 2.0);
   styleHist(dph_2e, kAzure + 1, 1001, 2, 1, 2.0);

   TH1D* tki_2b = new TH1D("tki_2b", (varName[1] + " Distribution").c_str(), tkib_nBin, tkib_min, tkib_max);
   TH1D* tki_2e = new TH1D("tki_2e", (varName[1] + " Distribution").c_str(), tkie_nBin, tkie_min, tkie_max);
   styleHist(tki_2b, kAzure + 1, 1001, 2, 1, 2.0);
   styleHist(tki_2e, kAzure + 1, 1001, 2, 1, 2.0);

   // -------------------------------------------------- //

   string const inDir = "/home/afiqaize/Downloads/HLT_Val/dev/e_80x/file/v11/retune_Jun15/";

   TChain *t1 = new TChain("eleDistr");
   t1->Add((inDir + "skim_m1z1ll.root").c_str());
   t1->Add((inDir + "skim_m2qcd.root").c_str());

   Bool_t isMC = false;

   Int_t nRun;
   t1->SetBranchAddress("nRun", &nRun);
   Int_t nEvt;
   t1->SetBranchAddress("nEvt", &nEvt);
   Int_t nLumi;
   t1->SetBranchAddress("nLumi", &nLumi);

   Int_t type;
   t1->SetBranchAddress("itype", &type);
   Float_t weight;
   t1->SetBranchAddress("weight", &weight);
   Float_t puWgt;
   t1->SetBranchAddress("puWgt", &puWgt);
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
   Float_t hca[10];
   t1->SetBranchAddress("hlt_hca", hca);
   Float_t hcc[10];
   t1->SetBranchAddress("hlt_hcc", hcc);
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

   // -------------------------------------------------- //

   TLorentzVector p4Tag, p4Probe;
   Float_t finWgt = 1.;

   Int_t nEvt1 = t1->GetEntries();
   cout << "nEvt1 = " << nEvt1 << endl;

   for (Int_t evt1 = 0; evt1 < nEvt1; evt1++) {

     t1->GetEntry(evt1);
     finWgt = puWgt * weight;

     // Loop for QCD-like things considering all cands
     if (type == -2) {

       for (Int_t iCand = 0; iCand < n; iCand++) {

         if (et[iCand] < 20. or fabs(eta[iCand] > 2.5)) continue;

         if (!checkCand("WPTight", eta[iCand],
                        sie[iCand], hoe[iCand], ecc[iCand], hcc[iCand], eop[iCand],
                        chi[iCand], mih[iCand], des[iCand], dph[iCand], tki[iCand])) continue;

         if (fabs(eta[iCand]) < 1.444) {

           sie_1b->Fill(sie[iCand], finWgt);
           hoe_1b->Fill(hoe[iCand], finWgt);
           eca_1b->Fill(eca[iCand], finWgt);
           ecc_1b->Fill(ecc[iCand], finWgt);
           hca_1b->Fill(hca[iCand], finWgt);
           hcc_1b->Fill(hcc[iCand], finWgt);
           eop_1b->Fill(eop[iCand], finWgt);
           chi_1b->Fill(chi[iCand], finWgt);
           mih_1b->Fill(mih[iCand], finWgt);
           des_1b->Fill(des[iCand], finWgt);
           dph_1b->Fill(dph[iCand], finWgt);
           tki_1b->Fill(tki[iCand], finWgt);
 
         }

         if (fabs(eta[iCand]) >= 1.566) {

           sie_1e->Fill(sie[iCand], finWgt);
           hoe_1e->Fill(hoe[iCand], finWgt);
           eca_1e->Fill(eca[iCand], finWgt);
           ecc_1e->Fill(ecc[iCand], finWgt);
           hca_1e->Fill(hca[iCand], finWgt);
           hcc_1e->Fill(hcc[iCand], finWgt);
           eop_1e->Fill(eop[iCand], finWgt);
           chi_1e->Fill(chi[iCand], finWgt);
           mih_1e->Fill(mih[iCand], finWgt);
           des_1e->Fill(des[iCand], finWgt);
           dph_1e->Fill(dph[iCand], finWgt);
           tki_1e->Fill(tki[iCand], finWgt);

         }
       }
     }

     // Loop TnP-style so that the object is likely an electron
     if (type == -1) {

       for (Int_t iTag = 0; iTag < n; iTag++) {

         if (pass[iTag] != 1) continue;
         if (isMC and genMatch[iTag] != 1) continue;
         if ((et[iTag] < 25.) or (eta[iTag] > 2.5)) continue;

         p4Tag.SetPtEtaPhiE(et[iTag], eta[iTag], phi[iTag], e[iTag]);

         for (Int_t iProbe = 0; iProbe < n; iProbe++) {

           if (iProbe == iTag) continue;
           if (isMC and genMatch[iProbe] != 1) continue;
           if (et[iProbe] < 20. or fabs(eta[iProbe] > 2.5)) continue;

           p4Probe.SetPtEtaPhiE(et[iProbe], eta[iProbe], phi[iProbe], e[iProbe]);

           if ((p4Tag + p4Probe).M() < 70. or (p4Tag + p4Probe).M() > 110.) continue;

           if (!checkCand("WPTight", eta[iProbe],
                          sie[iProbe], hoe[iProbe], ecc[iProbe], hcc[iProbe], eop[iProbe],
                          chi[iProbe], mih[iProbe], des[iProbe], dph[iProbe], tki[iProbe])) continue;

           if (fabs(eta[iProbe]) < 1.444) {

             sie_2b->Fill(sie[iProbe], finWgt);
             hoe_2b->Fill(hoe[iProbe], finWgt);
             eca_2b->Fill(eca[iProbe], finWgt);
             ecc_2b->Fill(ecc[iProbe], finWgt);
             hca_2b->Fill(hca[iProbe], finWgt);
             hcc_2b->Fill(hcc[iProbe], finWgt);
             eop_2b->Fill(eop[iProbe], finWgt);
             chi_2b->Fill(chi[iProbe], finWgt);
             mih_2b->Fill(mih[iProbe], finWgt);
             des_2b->Fill(des[iProbe], finWgt);
             dph_2b->Fill(dph[iProbe], finWgt);
             tki_2b->Fill(tki[iProbe], finWgt);

           }

           if (fabs(eta[iProbe]) >= 1.566) {

             sie_2e->Fill(sie[iProbe], finWgt);
             hoe_2e->Fill(hoe[iProbe], finWgt);
             eca_2e->Fill(eca[iProbe], finWgt);
             ecc_2e->Fill(ecc[iProbe], finWgt);
             hca_2e->Fill(hca[iProbe], finWgt);
             hcc_2e->Fill(hcc[iProbe], finWgt);
             eop_2e->Fill(eop[iProbe], finWgt);
             chi_2e->Fill(chi[iProbe], finWgt);
             mih_2e->Fill(mih[iProbe], finWgt);
             des_2e->Fill(des[iProbe], finWgt);
             dph_2e->Fill(dph[iProbe], finWgt);
             tki_2e->Fill(tki[iProbe], finWgt);

           }
         }
       }
     }
   }

   // -------------------------------------------------- //

   //cout << tki_1b->GetEntries() << " " << tki_3b->GetEntries() << endl;
   //cout << tki_1e->GetEntries() << " " << tki_3e->GetEntries() << endl;

   tki_1b->Scale( 1. / tki_1b->Integral()); tki_1e->Scale( 1. / tki_1e->Integral());
   tki_2b->Scale( 1. / tki_2b->Integral()); tki_2e->Scale( 1. / tki_2e->Integral());

   static const Int_t nStep_b = tkib_nBin + 1, nStep_e = tkie_nBin + 1;
   Double_t sStep_b = (tkib_max - tkib_min) / tkib_nBin, sStep_e = (tkie_max - tkie_min) / tkie_nBin;

   // Array size must be the same as bin + 1
   Double_t eff_xb[nStep_b], eff_y1b[nStep_b], eff_y2b[nStep_b];
   Double_t eff_xe[nStep_e], eff_y1e[nStep_e], eff_y2e[nStep_e];
   Double_t std_xb[nStep_b], std_xe[nStep_e], std_yb[nStep_b], std_ye[nStep_e];
   Double_t sig_b = 0., bkg_b = 0., sig_e = 0., bkg_e = 0.;

   //std::cout << "Barrel" << "\n" << "Cut" << "\t" << "Eff bkg" << "\t" << "Eff sig" << std::endl;

   for (Int_t p = 0; p < nStep_b; p++) {

     eff_xb[p] = (p * sStep_b) + tkib_min;
     eff_y1b[p] = effCalc(p, tki_1b);
     eff_y2b[p] = effCalc(p, tki_2b);

     if (fabs(eff_xb[p] - cut_b) < sStep_b / 2.) {
       sig_b = eff_y2b[p];
       bkg_b = eff_y1b[p];
     }

     std_xb[p] = cut_b;
     if (p == 0) std_yb[p] = 10.;
     else if (p == nStep_b - 1) std_yb[p] = 0.;
     else std_yb[p] = (1. - ((Double_t) (p + 1) / (Double_t) nStep_b));

     //if (eff_y2b[p] <= 1.)
     //  std::cout << std::setprecision(4) << std::fixed << eff_xb[p] << "\t" << std::setprecision(3) << eff_y1b[p] * 100. << "\t" << eff_y2b[p] * 100. << std::endl;

   }

   //std::cout << "\n" << "Endcap" << "\n" << "Cut" << "\t" << "Eff bkg" << "\t" << "Eff sig" << std::endl;

   for (Int_t q = 0; q < nStep_e; q++) {

     eff_xe[q] = (q * sStep_e) + tkie_min;
     eff_y1e[q] = effCalc(q, tki_1e);
     eff_y2e[q] = effCalc(q, tki_2e);

     if (fabs(eff_xe[q] - cut_e) < sStep_e / 2.) {
       sig_e = eff_y2e[q];
       bkg_e = eff_y1e[q];
     }

     std_xe[q] = cut_e;
     if (q == 0) std_ye[q] = 10.;
     else if (q == nStep_e - 1) std_ye[q] = 0.;
     else std_ye[q] = (1. - ((Double_t) (q + 1)  / (Double_t) nStep_e));

     //if (eff_y2e[q] <= 1.)
     //  std::cout << std::setprecision(4) << std::fixed <<  eff_xe[q] << "\t" << std::setprecision(3) << eff_y1e[q] * 100. << "\t" << eff_y2e[q] * 100. << std::endl;

   }

   //std::cout << std::endl;

   // -------------------------------------------------- //;

   TGraph* eff_1b = new TGraph(nStep_b, eff_xb, eff_y1b);
   TGraph* eff_1e = new TGraph(nStep_e, eff_xe, eff_y1e);
   styleGr(eff_1b, kRed + 1, 0, 0, 0, 3.0);
   styleGr(eff_1e, kRed + 1, 0, 0, 0, 3.0);

   TGraph* eff_2b = new TGraph(nStep_b, eff_xb, eff_y2b);
   eff_2b->SetTitle((varName[1] + " EB Efficiency").c_str());
   styleGr(eff_2b, kAzure + 1, 0, 0, 0, 3.0);
   axGr(eff_2b, 0., 1.049, "Efficiency", 0.027, 0.95, 0.025, varName[2], 0.027, 1.15, 0.025);
   eff_2b->GetXaxis()->SetLimits(tkib_min, tkib_max);

   TGraph* eff_2e = new TGraph(nStep_e, eff_xe, eff_y2e);
   eff_2e->SetTitle((varName[1] + " EE Efficiency").c_str());
   styleGr(eff_2e, kAzure + 1, 0, 0, 0, 3.0);
   axGr(eff_2e, 0., 1.049, "Efficiency", 0.027, 0.95, 0.025, varName[2], 0.027, 1.15, 0.025);
   eff_2e->GetXaxis()->SetLimits(tkie_min, tkie_max);

   TGraph* stdb = new TGraph(nStep_b, std_xb, std_yb);
   stdb->SetLineColor(kBlack);
   stdb->SetLineWidth(3);

   TGraph* stde = new TGraph(nStep_e, std_xe, std_ye);
   stde->SetLineColor(kBlack);
   stde->SetLineWidth(3);

   TGraph* pntWPb = new TGraph();
   pntWPb->SetPoint(0, bkg_b, sig_b);
   pntWPb->SetMarkerStyle(29);
   pntWPb->SetMarkerSize(3);
   pntWPb->SetMarkerColor(kAzure - 1);

   TGraph* pntWPe = new TGraph();
   pntWPe->SetPoint(0, bkg_e, sig_e);
   pntWPe->SetMarkerStyle(29);
   pntWPe->SetMarkerSize(3);
   pntWPe->SetMarkerColor(kAzure - 1);

   TGraph* rocb = new TGraph(nStep_b, eff_y1b, eff_y2b);
   rocb->SetTitle((varName[1] + " EB Efficiency").c_str());
   styleGr(rocb, kRed, 0, 0, 0, 3.0);
   axGr(rocb, 0., 1.099, (sigLeg + " Efficiency").c_str(), 0.027, 1.05, 0.025, (bkgLeg + " Efficiency").c_str(), 0.027, 1.15, 0.025);
   rocb->GetXaxis()->SetLimits(0., 1.);

   TGraph* roce = new TGraph(nStep_b, eff_y1e, eff_y2e);
   roce->SetTitle((varName[1] + " EE Efficiency").c_str());
   styleGr(roce, kRed, 0, 0, 0, 3.0);
   axGr(roce, 0., 1.099, (sigLeg + " Efficiency").c_str(), 0.027, 1.05, 0.025, (bkgLeg + " Efficiency").c_str(), 0.027, 1.15, 0.025);
   roce->GetXaxis()->SetLimits(0., 1.);

   // -------------------------------------------------- //

   if (drawLog) {
     yMin_b = yMin_b / 5.;
     yMin_e = yMin_e / 5.;
   }

   axHist(tki_2b, yMin_b, yMax_b, varName[3], 0.027, 1.05, 0.025, varName[2], 0.027, 1.15, 0.025);
   axHist(tki_2e, yMin_e, yMax_e, varName[3], 0.027, 1.05, 0.025, varName[2], 0.027, 1.15, 0.025);

   TLatex txt;
   txt.SetTextSize(0.035);
   txt.SetTextAlign(13);
   string topLeft, topRight;
   topLeft = "#bf{CMS} #it{Simulation Preliminary}";
   topRight = "(13 TeV)";

   TLegend *leg01 = new TLegend(.69, .67, .87, .85);
   leg01->SetHeader((legHead + "#left|#eta^{e}#right| < 1.444").c_str());
   leg01->AddEntry(tki_2b, (sigLeg).c_str(), "l");
   leg01->AddEntry(tki_1b, (bkgLeg).c_str(), "l");
   leg01->SetFillColor(0);
   leg01->SetBorderSize(0);
   leg01->SetTextSize(0.03);
   leg01->SetTextFont(42);

   TLegend *leg02 = new TLegend(.69, .67, .87, .85);
   leg02->SetHeader((legHead + "1.566 < #left|#eta^{e}#right| < 2.5").c_str());
   leg02->AddEntry(tki_2e, (sigLeg).c_str(), "l");
   leg02->AddEntry(tki_1e, (bkgLeg).c_str(), "l");
   leg02->SetFillColor(0);
   leg02->SetBorderSize(0);
   leg02->SetTextSize(0.03);
   leg02->SetTextFont(42);

   // -------------------------------------------------- //

   string const outDir = inDir + "/opt_v0/plot/";

   TCanvas *cv1 = new TCanvas("cv1", "cv1", 200, 10, 1000, 1000);
   TCanvas *cv2 = new TCanvas("cv2", "cv2", 200, 10, 1000, 1000);
   TCanvas *ce1 = new TCanvas("ce1", "ce1", 200, 10, 1000, 1000);
   TCanvas *ce2 = new TCanvas("ce2", "ce2", 200, 10, 1000, 1000);
   TCanvas *cr1 = new TCanvas("cr1", "cr1", 200, 10, 1000, 1000);
   TCanvas *cr2 = new TCanvas("cr2", "cr2", 200, 10, 1000, 1000);

   cv1->cd();

   if (drawLog) cv1->SetLogy();
   tki_2b->Draw("hist");
   tki_1b->Draw("histsame");
   stdb->Draw("same");

   leg01->Draw();
   //txt.DrawLatexNDC(0.06, 0.928, topLeft.c_str());
   //txt.DrawLatexNDC(0.763, 0.933, topRight.c_str());
   //txt.DrawLatexNDC(0.06, 0.935, topLeft.c_str());
   //txt.DrawLatexNDC(0.728, 0.940, topRight.c_str());
   cv1->SaveAs((outDir + outPre + varName[0] + "_var_eb.pdf").c_str());

   cv2->cd();

   if (drawLog) cv2->SetLogy();
   tki_2e->Draw("hist");
   tki_1e->Draw("histsame");
   stde->Draw("same");

   leg02->Draw();
   //txt.DrawLatexNDC(0.06, 0.928, topLeft.c_str());
   //txt.DrawLatexNDC(0.763, 0.933, topRight.c_str());
   //txt.DrawLatexNDC(0.06, 0.935, topLeft.c_str());
   //txt.DrawLatexNDC(0.728, 0.940, topRight.c_str());
   cv2->SaveAs((outDir + outPre + varName[0] + "_var_ee.pdf").c_str());

   ce1->cd();
   ce1->SetGrid();
   eff_2b->Draw("AL");
   eff_1b->Draw("same");
   stdb->Draw("same");
   //txt.DrawLatexNDC(0.06, 0.928, topLeft.c_str());
   //txt.DrawLatexNDC(0.763, 0.933, topRight.c_str());
   //txt.DrawLatexNDC(0.06, 0.935, topLeft.c_str());
   //txt.DrawLatexNDC(0.728, 0.940, topRight.c_str());
   ce1->SaveAs((outDir + outPre + varName[0] + "_eff_eb.pdf").c_str());

   ce2->cd();
   ce2->SetGrid();
   eff_2e->Draw("AL");
   eff_1e->Draw("same");
   stde->Draw("same");
   //txt.DrawLatexNDC(0.06, 0.928, topLeft.c_str());
   //txt.DrawLatexNDC(0.763, 0.933, topRight.c_str());
   //txt.DrawLatexNDC(0.06, 0.935, topLeft.c_str());
   //txt.DrawLatexNDC(0.728, 0.940, topRight.c_str());
   ce2->SaveAs((outDir + outPre + varName[0] + "_eff_ee.pdf").c_str());

   cr1->cd();
   cr1->SetGrid();
   rocb->Draw("AL");
   pntWPb->Draw("psame");
   //txt.DrawLatexNDC(0.06, 0.928, topLeft.c_str());
   //txt.DrawLatexNDC(0.763, 0.933, topRight.c_str());
   //txt.DrawLatexNDC(0.06, 0.935, topLeft.c_str());
   //txt.DrawLatexNDC(0.728, 0.940, topRight.c_str());
   //cr1->SaveAs((outDir + outPre + varName[0] + "_roc_eb.pdf").c_str());

   cr2->cd();
   cr2->SetGrid();
   roce->Draw("AL");
   pntWPe->Draw("psame");
   //txt.DrawLatexNDC(0.06, 0.928, topLeft.c_str());
   //txt.DrawLatexNDC(0.763, 0.933, topRight.c_str());
   //txt.DrawLatexNDC(0.06, 0.935, topLeft.c_str());
   //txt.DrawLatexNDC(0.728, 0.940, topRight.c_str());
   //cr2->SaveAs((outDir + outPre + varName[0] + "_roc_ee.pdf").c_str());

   // -------------------------------------------------- //

   cv1->Close(); cv2->Close();
   ce1->Close(); ce2->Close();
   cr1->Close(); cr2->Close();
   gROOT->ProcessLine(".q");
   
}

int main() {
  tnpTune();
  return 0;
}



