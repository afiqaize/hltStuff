// Stolen from mvaPlot in 740
// For the tnp hlt vs reco electron plotting
// Nov 25 updated and streamlined
// Usage: root -l tnpOn.cxx++

#include "iostream"
#include <sstream>
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

Bool_t checkCand(const string setWP, const Float_t eta, const int iMask,
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
  varThr[4] = 0.012; varThr[5] = 999.0;
  varThr[6] = 999.0; varThr[7] = 0.004;
  varThr[8] = 0.02 ; varThr[9] = 0.08;
  //varThr[6] = 999.0; varThr[7] = 0.0044; // new matching
  //varThr[8] = 0.025; varThr[9] = 0.08;
  }

  else if (fabs(eta) > 1.4791 && setWP == "WPLoose") {
  varThr[0] = 0.032; varThr[1] = 0.065;
  varThr[2] = 0.135; varThr[3] = 0.13;
  varThr[4] = 0.01 ; varThr[5] = 2.8;
  varThr[6] = 2.5  ; varThr[7] = 0.007;
  varThr[8] = 0.02 ; varThr[9] = 0.08;
  //varThr[6] = 2.5  ; varThr[7] = 0.006; // new matching
  //varThr[8] = 0.025; varThr[9] = 0.08;
  }

  else if (fabs(eta) < 1.4791 && setWP == "WPTight") {
  varThr[0] = 0.011; varThr[1] = 0.05;
  varThr[2] = 0.145; varThr[3] = 0.13;
  varThr[4] = 0.01 ; varThr[5] = 999.0;
  varThr[6] = 999.0; varThr[7] = 0.0035;
  varThr[8] = 0.015; varThr[9] = 0.06;
  //varThr[6] = 999.0; varThr[7] = 0.004; // new matching
  //varThr[8] = 0.02 ; varThr[9] = 0.06;
  }

  else if (fabs(eta) > 1.4791 && setWP == "WPTight") {
  varThr[0] = 0.029; varThr[1] = 0.05;
  varThr[2] = 0.105; varThr[3] = 0.095;
  varThr[4] = 0.008; varThr[5] = 2.5;
  varThr[6] = 1.5  ; varThr[7] = 0.006;
  varThr[8] = 0.015; varThr[9] = 0.06;
  //varThr[6] = 1.5  ; varThr[7] = 0.0045; // new matching
  //varThr[8] = 0.022; varThr[9] = 0.06;
  }

  else if (fabs(eta) < 1.4791 && setWP == "NeoLoose") {
  varThr[0] = 0.011; varThr[1] = 0.08;
  varThr[2] = 0.04 ; varThr[3] = 0.06;
  varThr[4] = 0.012; varThr[5] = 999.0;
  varThr[6] = 999.0; varThr[7] = 0.0044;
  varThr[8] = 0.025; varThr[9] = 0.085;
  }

  else if (fabs(eta) > 1.4791 && setWP == "NeoLoose") {
  varThr[0] = 0.031; varThr[1] = 0.04;
  varThr[2] = 0.045; varThr[3] = 0.08;
  varThr[4] = 0.01 ; varThr[5] = 4.0;
  varThr[6] = 2.5  ; varThr[7] = 0.006;
  varThr[8] = 0.025; varThr[9] = 0.07;
  }

  else if (fabs(eta) < 1.4791 && setWP == "NeoTight") {
  varThr[0] = 0.0105; varThr[1] = 0.07;
  varThr[2] = 0.032 ; varThr[3] = 0.055;
  varThr[4] = 0.01  ; varThr[5] = 999.0;
  varThr[6] = 999.0 ; varThr[7] = 0.004;
  varThr[8] = 0.02  ; varThr[9] = 0.07;
  }

  else if (fabs(eta) > 1.4791 && setWP == "NeoTight") {
  varThr[0] = 0.0285; varThr[1] = 0.035;
  varThr[2] = 0.04  ; varThr[3] = 0.05;
  varThr[4] = 0.008 ; varThr[5] = 3.5;
  varThr[6] = 2.5   ; varThr[7] = 0.0045;
  varThr[8] = 0.022 ; varThr[9] = 0.05;
  }

  else {
  varThr[0] = 9999. ; varThr[1] = 9999.;
  varThr[2] = 9999. ; varThr[3] = 9999.;
  varThr[4] = 9999. ; varThr[5] = 9999.;
  varThr[6] = 9999. ; varThr[7] = 9999.;
  varThr[8] = 9999. ; varThr[9] = 9999.;
  }

  // Which cut to mask for N-1 shit
  if (iMask > -1 and iMask < 10)
    varThr[ iMask ] += 999.;

  for (Int_t aa = 0; aa < 10; aa++)
    candOk = candOk and (varVal[aa] < varThr[aa]);

  return candOk;
}

// Too many dumb lines for styling... doing it here
string toStr(Float_t inNo) { ostringstream outStr; outStr << inNo; return outStr.str(); }
string toStr(Int_t inNo) { ostringstream outStr; outStr << inNo; return outStr.str(); }

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

void styleLeg(TLegend* varLeg, Int_t nCol, Int_t fColor, Int_t borSiz, Int_t texFon, Float_t texSiz, string legHead = "") {
  varLeg->SetHeader( legHead.c_str() );
  varLeg->SetNColumns(nCol);
  varLeg->SetFillColor(fColor);
  varLeg->SetBorderSize(borSiz);
  varLeg->SetTextFont(texFon);
  varLeg->SetTextSize(texSiz);
}

void tnpOn() {

   gROOT->Reset();

   setTDRStyle();

   // Everything to tinker with should be here
   Double_t yMin_b = .0002, yMax_b = .9999;
   Double_t yMin_e = .0002, yMax_e = .9999;

   string varName[5], outPre, lHead;
   varName[0] = "tki";
   outPre = "lum";
   lHead = "Run 27658N, ";

   Bool_t drawLog = true;
   Double_t cut_b = -1, cut_e = -1;

   // -------------------------------------------------- //

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

   Int_t sieb_nBin = 50, siee_nBin = 60;
   Double_t sieb_max = .02, siee_max = .06;
   Double_t sieb_min = 0., siee_min = 0.;

   // For H/E
   Int_t hoeb_nBin = 40, hoee_nBin = 40;
   Double_t hoeb_max = .2, hoee_max = .2;
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

   Int_t tkib_nBin = 80, tkie_nBin = 80;
   Double_t tkib_max = 0.4, tkie_max = 0.4;
   Double_t tkib_min = 0., tkie_min = 0.;

   Int_t lolb_nBin = 40, lole_nBin = 40;
   Double_t lolb_max = .2, lole_max = .2;
   Double_t lolb_min = -.2, lole_min = -.2;

   // -------------------------------------------------- //

   const Int_t nH = 2;

   string inLeg[nH];
   inLeg[0] = "N = 1, 2";
   inLeg[1] = "N = 6, 7";

   //varName[3] = "e / bin";
   varName[3] = "a. u.";
   varName[4] = inLeg[1] + " / " + inLeg[0];

   if (varName[0] == "mee") {
     varName[1] = "Tag and Probe Mass";
     varName[2] = "m_{ee} (GeV)";
   }

   if (varName[0] == "mer") {
     varName[1] = "Tag and Probe Mass";
     varName[2] = "Raw m_{ee} (GeV)";
   }

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
   //TGaxis::SetMaxDigits(4);

   TH1D *mee_b[nH], *mee_e[nH], *phi_b[nH], *phi_e[nH], *eet_b[nH], *eet_e[nH];
   TH1D *sie_b[nH], *sie_e[nH], *hoe_b[nH], *hoe_e[nH], *ecc_b[nH], *ecc_e[nH];
   TH1D *eca_b[nH], *eca_e[nH], *hcc_b[nH], *hcc_e[nH], *hca_b[nH], *hca_e[nH];
   TH1D *eop_b[nH], *eop_e[nH], *chi_b[nH], *chi_e[nH], *mih_b[nH], *mih_e[nH];
   TH1D *des_b[nH], *des_e[nH], *dph_b[nH], *dph_e[nH], *tki_b[nH], *tki_e[nH];
   TH1D *lol_b[nH], *lol_e[nH];

   Int_t kColor, kFill, kMark;
   for (Int_t aH = 0; aH < nH; aH++) {
     if (aH == 1) kColor = kRed + 1;
     if (aH == 0) kColor = kAzure + 1;
     kFill = 1001 * abs(aH - 1); kMark = 20 + aH;

     mee_b[aH] = new TH1D(("mee_b_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), meeb_nBin, meeb_min, meeb_max);
     mee_e[aH] = new TH1D(("mee_e_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), meee_nBin, meee_min, meee_max);
     styleHist(mee_b[aH], kColor, kFill, kMark, 1, 1.5);
     styleHist(mee_e[aH], kColor, kFill, kMark, 1, 1.5);

     phi_b[aH] = new TH1D(("phi_b_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), phib_nBin, phib_min, phib_max);
     phi_e[aH] = new TH1D(("phi_e_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), phie_nBin, phie_min, phie_max);
     styleHist(phi_b[aH], kColor, kFill, kMark, 1, 1.5);
     styleHist(phi_e[aH], kColor, kFill, kMark, 1, 1.5);

     eet_b[aH] = new TH1D(("eet_b_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), eetb_nBin, eetb_min, eetb_max);
     eet_e[aH] = new TH1D(("eet_e_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), eete_nBin, eete_min, eete_max);
     styleHist(eet_b[aH], kColor, kFill, kMark, 1, 1.5);
     styleHist(eet_e[aH], kColor, kFill, kMark, 1, 1.5);

     sie_b[aH] = new TH1D(("sie_b_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), sieb_nBin, sieb_min, sieb_max);
     sie_e[aH] = new TH1D(("sie_e_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), siee_nBin, siee_min, siee_max);
     styleHist(sie_b[aH], kColor, kFill, kMark, 1, 1.5);
     styleHist(sie_e[aH], kColor, kFill, kMark, 1, 1.5);

     hoe_b[aH] = new TH1D(("hoe_b_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), hoeb_nBin, hoeb_min, hoeb_max);
     hoe_e[aH] = new TH1D(("hoe_e_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), hoee_nBin, hoee_min, hoee_max);
     styleHist(hoe_b[aH], kColor, kFill, kMark, 1, 1.5);
     styleHist(hoe_e[aH], kColor, kFill, kMark, 1, 1.5);

     ecc_b[aH] = new TH1D(("ecc_b_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), eccb_nBin, eccb_min, eccb_max);
     ecc_e[aH] = new TH1D(("ecc_e_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), ecce_nBin, ecce_min, ecce_max);
     styleHist(ecc_b[aH], kColor, kFill, kMark, 1, 1.5);
     styleHist(ecc_e[aH], kColor, kFill, kMark, 1, 1.5);

     eca_b[aH] = new TH1D(("eca_b_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), ecab_nBin, ecab_min, ecab_max);
     eca_e[aH] = new TH1D(("eca_e_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), ecae_nBin, ecae_min, ecae_max);
     styleHist(eca_b[aH], kColor, kFill, kMark, 1, 1.5);
     styleHist(eca_e[aH], kColor, kFill, kMark, 1, 1.5);

     hcc_b[aH] = new TH1D(("hcc_b_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), hccb_nBin, hccb_min, hccb_max);
     hcc_e[aH] = new TH1D(("hcc_e_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), hcce_nBin, hcce_min, hcce_max);
     styleHist(hcc_b[aH], kColor, kFill, kMark, 1, 1.5);
     styleHist(hcc_e[aH], kColor, kFill, kMark, 1, 1.5);

     hca_b[aH] = new TH1D(("hca_b_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), hcab_nBin, hcab_min, hcab_max);
     hca_e[aH] = new TH1D(("hca_e_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), hcae_nBin, hcae_min, hcae_max);
     styleHist(hca_b[aH], kColor, kFill, kMark, 1, 1.5);
     styleHist(hca_e[aH], kColor, kFill, kMark, 1, 1.5);

     eop_b[aH] = new TH1D(("eop_b_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), eopb_nBin, eopb_min, eopb_max);
     eop_e[aH] = new TH1D(("eop_e_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), eope_nBin, eope_min, eope_max);
     styleHist(eop_b[aH], kColor, kFill, kMark, 1, 1.5);
     styleHist(eop_e[aH], kColor, kFill, kMark, 1, 1.5);

     chi_b[aH] = new TH1D(("chi_b_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), chib_nBin, chib_min, chib_max);
     chi_e[aH] = new TH1D(("chi_e_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), chie_nBin, chie_min, chie_max);
     styleHist(chi_b[aH], kColor, kFill, kMark, 1, 1.5);
     styleHist(chi_e[aH], kColor, kFill, kMark, 1, 1.5);

     mih_b[aH] = new TH1D(("mih_b_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), mihb_nBin, mihb_min, mihb_max);
     mih_e[aH] = new TH1D(("mih_e_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), mihe_nBin, mihe_min, mihe_max);
     styleHist(mih_b[aH], kColor, kFill, kMark, 1, 1.5);
     styleHist(mih_e[aH], kColor, kFill, kMark, 1, 1.5);

     des_b[aH] = new TH1D(("des_b_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), desb_nBin, desb_min, desb_max);
     des_e[aH] = new TH1D(("des_e_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), dese_nBin, dese_min, dese_max);
     styleHist(des_b[aH], kColor, kFill, kMark, 1, 1.5);
     styleHist(des_e[aH], kColor, kFill, kMark, 1, 1.5);

     dph_b[aH] = new TH1D(("dph_b_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), dphb_nBin, dphb_min, dphb_max);
     dph_e[aH] = new TH1D(("dph_e_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), dphe_nBin, dphe_min, dphe_max);
     styleHist(dph_b[aH], kColor, kFill, kMark, 1, 1.5);
     styleHist(dph_e[aH], kColor, kFill, kMark, 1, 1.5);

     tki_b[aH] = new TH1D(("tki_b_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), tkib_nBin, tkib_min, tkib_max);
     tki_e[aH] = new TH1D(("tki_e_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), tkie_nBin, tkie_min, tkie_max);
     styleHist(tki_b[aH], kColor, kFill, kMark, 1, 1.5);
     styleHist(tki_e[aH], kColor, kFill, kMark, 1, 1.5);

     lol_b[aH] = new TH1D(("lol_b_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), lolb_nBin, lolb_min, lolb_max);
     lol_e[aH] = new TH1D(("lol_e_" + toStr(aH)).c_str(), (varName[1] + " Distribution").c_str(), lole_nBin, lole_min, lole_max);
     styleHist(lol_b[aH], kColor, kFill, kMark, 1, 1.5);
     styleHist(lol_e[aH], kColor, kFill, kMark, 1, 1.5);
   }

   // -------------------------------------------------- //

   string const inDir = "/home/afiqaize/Downloads/HLT_Val/dev/e_80x/file/v14/hipBull_jul21/";

   TChain *t1 = new TChain("eleDistr");
   t1->Add((inDir + "skim_p1Ele23_16d_f5085.root").c_str());

   Bool_t isMC = false;

   Int_t nRun;
   t1->SetBranchAddress("nRun", &nRun);
   Int_t nLumi;
   t1->SetBranchAddress("nLumi", &nLumi);
   Int_t nEvt;
   t1->SetBranchAddress("nEvt", &nEvt);
   Int_t nBX;
   t1->SetBranchAddress("nBX", &nBX);
   Int_t nOrb;
   t1->SetBranchAddress("nOrb", &nOrb);
   Int_t nSto;
   t1->SetBranchAddress("nSto", &nSto);

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

   Int_t mc_nBX, mc_nPUtrue, gp_n;
   Int_t mc_BX[100], mc_nPUobs[100];
   Float_t genWgt, gp_pt[10], gp_eta[10], gp_phi[10];

    if (isMC) {
      t1->SetBranchAddress("genWgt", &genWgt);
      t1->SetBranchAddress("gp_n", &gp_n);
      t1->SetBranchAddress("gp_pt", gp_pt);
      t1->SetBranchAddress("gp_eta", gp_eta);
      t1->SetBranchAddress("gpphi", gp_phi);
      t1->SetBranchAddress("mc_nBX", &mc_nBX);
      t1->SetBranchAddress("mc_BX", mc_BX);
      t1->SetBranchAddress("mc_nPUtrue", &mc_nPUtrue);
      t1->SetBranchAddress("mc_nPUobs", mc_nPUobs);
    }

   // -------------------------------------------------- //

   TLorentzVector p4Tag, p4Probe;
   Float_t finWgt = 1.;
   Float_t etaEB = 1.444, etaEE = 2.5;

   //Float_t ecn = 9999., hcn = 9999., hon = 9999.;
   //const Float_t ecc_EAb = 0.290, ecc_EAe = 0.210;
   //const Float_t hcc_EAb = 0.200, hcc_EAe = 0.250;
   //const Float_t hoe_EAb = 0.079, hoe_EAe = 0.250;

   Int_t nEvt1 = t1->GetEntries();
   cout << "nEvt1 = " << nEvt1 << endl;

   for (Int_t evt1 = 0; evt1 < nEvt1; evt1++) {

     t1->GetEntry(evt1);
     finWgt = puWgt * weight;
     if (n < 2) continue;

     for (Int_t iTag = 0; iTag < n; iTag++) {

       if (pass[iTag] != 1) continue;
       if ((et[iTag] < 25.) or (fabs(eta[iTag]) > etaEE)) continue;

       p4Tag.SetPtEtaPhiE(et[iTag], eta[iTag], phi[iTag], e[iTag]);

       for (Int_t iProbe = 0; iProbe < n; iProbe++) {

         if (iProbe == iTag) continue;
         if ((et[iProbe] < 25.) or (fabs(eta[iProbe]) > etaEE)) continue;

         p4Probe.SetPtEtaPhiE(et[iProbe], eta[iProbe], phi[iProbe], e[iProbe]);

         if ((p4Tag + p4Probe).M() < 70. or (p4Tag + p4Probe).M() > 110.) continue;

         //p4Tag.SetPtEtaPhiE(etr[iTag], eta[iTag], phi[iTag], er[iTag]);
         //p4Probe.SetPtEtaPhiE(etr[iProbe], eta[iProbe], phi[iProbe], er[iProbe]);

         if (!checkCand("", eta[iProbe], -1,
                        sie[iProbe], hoe[iProbe], ecc[iProbe], hcc[iProbe], eop[iProbe],
                        chi[iProbe], mih[iProbe], des[iProbe], dph[iProbe], tki[iProbe])) continue;

         if (nRun == 276581 or nRun == 276582) {

           if (fabs(eta[iProbe]) < etaEB) {

             sie_b[0]->Fill(sie[iProbe], finWgt);
             hoe_b[0]->Fill(hoe[iProbe], finWgt);
             eca_b[0]->Fill(eca[iProbe], finWgt);
             ecc_b[0]->Fill(ecc[iProbe], finWgt);
             hca_b[0]->Fill(hca[iProbe], finWgt);
             hcc_b[0]->Fill(hcc[iProbe], finWgt);
             eop_b[0]->Fill(eop[iProbe], finWgt);
             chi_b[0]->Fill(chi[iProbe], finWgt);
             mih_b[0]->Fill(mih[iProbe], finWgt);
             des_b[0]->Fill(des[iProbe], finWgt);
             dph_b[0]->Fill(dph[iProbe], finWgt);
             tki_b[0]->Fill(tki[iProbe], finWgt);

             lol_b[0]->Fill((ecu[iProbe] - 0.079*rho) / et[iProbe], finWgt);
 
           }

           if (fabs(eta[iProbe]) >= 1.566) {

             sie_e[0]->Fill(sie[iProbe], finWgt);
             hoe_e[0]->Fill(hoe[iProbe], finWgt);
             eca_e[0]->Fill(eca[iProbe], finWgt);
             ecc_e[0]->Fill(ecc[iProbe], finWgt);
             hca_e[0]->Fill(hca[iProbe], finWgt);
             hcc_e[0]->Fill(hcc[iProbe], finWgt);
             eop_e[0]->Fill(eop[iProbe], finWgt);
             chi_e[0]->Fill(chi[iProbe], finWgt);
             mih_e[0]->Fill(mih[iProbe], finWgt);
             des_e[0]->Fill(det[iProbe], finWgt);
             dph_e[0]->Fill(dph[iProbe], finWgt);
             tki_e[0]->Fill(tki[iProbe], finWgt);

             lol_e[0]->Fill((ecu[iProbe] - 0.044*rho) / et[iProbe], finWgt);

           }

           if (eta[iTag] < 1.444 and eta[iProbe] < 1.444)
             mee_b[0]->Fill((p4Tag + p4Probe).M(), finWgt);

           else
             mee_e[0]->Fill((p4Tag + p4Probe).M(), finWgt);

         }

         if (nRun == 276586 or nRun == 276587) {

           if (fabs(eta[iProbe]) < etaEB) {

             sie_b[1]->Fill(sie[iProbe], finWgt);
             hoe_b[1]->Fill(hoe[iProbe], finWgt);
             eca_b[1]->Fill(eca[iProbe], finWgt);
             ecc_b[1]->Fill(ecc[iProbe], finWgt);
             hca_b[1]->Fill(hca[iProbe], finWgt);
             hcc_b[1]->Fill(hcc[iProbe], finWgt);
             eop_b[1]->Fill(eop[iProbe], finWgt);
             chi_b[1]->Fill(chi[iProbe], finWgt);
             mih_b[1]->Fill(mih[iProbe], finWgt);
             des_b[1]->Fill(des[iProbe], finWgt);
             dph_b[1]->Fill(dph[iProbe], finWgt);
             tki_b[1]->Fill(tki[iProbe], finWgt);

             lol_b[1]->Fill(ecu[iProbe] - 0.079*rho, finWgt);

           }

           if (fabs(eta[iProbe]) >= 1.566) {

             sie_e[1]->Fill(sie[iProbe], finWgt);
             hoe_e[1]->Fill(hoe[iProbe], finWgt);
             eca_e[1]->Fill(eca[iProbe], finWgt);
             ecc_e[1]->Fill(ecc[iProbe], finWgt);
             hca_e[1]->Fill(hca[iProbe], finWgt);
             hcc_e[1]->Fill(hcc[iProbe], finWgt);
             eop_e[1]->Fill(eop[iProbe], finWgt);
             chi_e[1]->Fill(chi[iProbe], finWgt);
             mih_e[1]->Fill(mih[iProbe], finWgt);
             des_e[1]->Fill(det[iProbe], finWgt);
             dph_e[1]->Fill(dph[iProbe], finWgt);
             tki_e[1]->Fill(tki[iProbe], finWgt);

             lol_e[1]->Fill(ecu[iProbe] - 0.044*rho, finWgt);

           }

           if (eta[iTag] < 1.444 and eta[iProbe] < 1.444)
             mee_b[1]->Fill((p4Tag + p4Probe).M(), finWgt);

           else
             mee_e[1]->Fill((p4Tag + p4Probe).M(), finWgt);

         }
       }
     }
   }

   // -------------------------------------------------- //

   //cout << tki_b[0]->GetEntries() << " " << tki_b[1]->GetEntries() << endl;
   //cout << tki_e[0]->GetEntries() << " " << tki_e[1]->GetEntries() << endl;

   tki_b[0]->Scale( 1. / tki_b[0]->Integral()); tki_e[0]->Scale( 1. / tki_e[0]->Integral());
   tki_b[1]->Scale( 1. / tki_b[1]->Integral()); tki_e[1]->Scale( 1. / tki_e[1]->Integral());

   static const Int_t nStep_b = tkib_nBin + 1, nStep_e = tkie_nBin + 1;
   Double_t sStep_b = (tkib_max - tkib_min) / tkib_nBin, sStep_e = (tkie_max - tkie_min) / tkie_nBin;

   Float_t l1b[nStep_b], eff_xb[nStep_b];
   Float_t l1e[nStep_e], eff_xe[nStep_e];
   Double_t std_xb[nStep_b], std_xe[nStep_e], std_yb[nStep_b], std_ye[nStep_e];

   for (Int_t bb = 0; bb < nStep_b; bb++) {
     l1b[bb] = 1.;
     eff_xb[bb] = (bb * sStep_b) + tkib_min;

     std_xb[bb] = cut_b;
     if (bb == 0) std_yb[bb] = yMax_b;
     else if (bb == nStep_b - 1) std_yb[bb] = 0.;
     else std_yb[bb] = (1. - ((Double_t) (bb + 1) / (Double_t) nStep_b));
   }

   for (Int_t ee = 0; ee < nStep_e; ee++) {
     l1e[ee] = 1.;
     eff_xe[ee] = (ee * sStep_e) + tkie_min;

     std_xe[ee] = cut_e;
     if (ee == 0) std_ye[ee] = yMax_e;
     else if (ee == nStep_e - 1) std_ye[ee] = 0.;
     else std_ye[ee] = (1. - ((Double_t) (ee + 1) / (Double_t) nStep_e));
   }

   TGraph *lineb = new TGraph(tkib_nBin + 1, eff_xb, l1b);
   lineb->SetLineColor(kYellow + 1);
   lineb->SetLineWidth(2);

   TGraph *linee = new TGraph(tkie_nBin + 1, eff_xe, l1e);
   linee->SetLineColor(kYellow + 1);
   linee->SetLineWidth(2);

   TH1D *sfb = new TH1D("", "", tkib_nBin, tkib_min, tkib_max);
   sfb->Divide(tki_b[1], tki_b[0], 1., 1., "B");
   styleHist(sfb, kBlack, 0, 2, 1, 1.0);
   axHist(sfb, 0.001, 1.999, varName[4], 0.061, 0.49, 0.059, varName[2], 0.077, 0.95, 0.073);

   TH1D *sfe = new TH1D("", "", tkie_nBin, tkie_min, tkie_max);
   sfe->Divide(tki_e[1], tki_e[0], 1., 1., "B");
   styleHist(sfe, kBlack, 0, 2, 1, 1.0);
   axHist(sfe, 0.001, 1.999, varName[4], 0.061, 0.49, 0.059, varName[2], 0.077, 0.95, 0.073);

   TGraph* stdb = new TGraph(nStep_b, std_xb, std_yb);
   stdb->SetLineColor(kBlack);
   stdb->SetLineWidth(3);

   TGraph* stde = new TGraph(nStep_e, std_xe, std_ye);
   stde->SetLineColor(kBlack);
   stde->SetLineWidth(3);

   // -------------------------------------------------- //

   if (drawLog) {
     //yMin_b++;
     //yMin_e++;
   }

   axHist(tki_b[0], yMin_b, yMax_b, varName[3], 0.035, 0.9, 0.031, varName[2], 0.037, 1.15, 0.033);
   axHist(tki_e[0], yMin_e, yMax_e, varName[3], 0.035, 0.9, 0.031, varName[2], 0.037, 1.15, 0.033);

   TLatex txt;
   txt.SetTextSize(0.035);
   txt.SetTextAlign(13);
   string topLeft, topRight;
   topLeft = "#bf{CMS} #it{Preliminary}";
   topRight = "0.8 fb^{-1} (13 TeV)";

   TLegend *bLeg, *eLeg;
   bLeg = new TLegend();
   eLeg = new TLegend();

   string bHead, eHead;
   bHead = "#left|#eta^{e}#right| < " + toStr(etaEB);
   eHead = "1.566 < #left|#eta^{e}#right| < " + toStr(etaEE);

   string sLeg;
   for (Int_t bH = 0; bH < nH; bH++) {
     if (bH == 0) sLeg = "f";
     if (bH == 1) sLeg = "l";
     bLeg->AddEntry(tki_b[bH], (inLeg[bH]).c_str(), sLeg.c_str());
     eLeg->AddEntry(tki_e[bH], (inLeg[bH]).c_str(), sLeg.c_str());
   }

   // -------------------------------------------------- //

   string const outDir = inDir + "plot_aug05/";

   TCanvas *c01 = new TCanvas("c01", "c01", 200, 10, 1000, 1000);
   TCanvas *c02 = new TCanvas("c02", "c02", 200, 10, 1000, 1000);

   txt.SetTextSize(0.035);

   styleLeg(bLeg, 2, 0, 0, 42, 0.035, lHead + bHead);
   bLeg->SetX1(0.635); bLeg->SetX2(0.935);
   bLeg->SetY1(0.775); bLeg->SetY2(0.855);

   styleLeg(eLeg, 2, 0, 0, 42, 0.035, lHead + eHead);
   eLeg->SetX1(0.605); eLeg->SetX2(0.905);
   eLeg->SetY1(0.775); eLeg->SetY2(0.855);

   c01->cd();

   TPad *pad1 = new TPad("pad1", "pad1", 0., 0.29, 1., 1.);
   pad1->SetBottomMargin(0);
   pad1->Draw();
   pad1->cd();

   if (drawLog) pad1->SetLogy();
   tki_b[0]->Draw("hist");
   tki_b[1]->Draw("pesame");
   stdb->Draw("same");

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

   if (drawLog) pad3->SetLogy();
   tki_e[0]->Draw("hist");
   tki_e[1]->Draw("pesame");
   stde->Draw("same");

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

   // -------------------------------------------------- //

   c01->cd();
   c01->SaveAs((outDir + outPre + "_" + varName[0] + "_eb.pdf").c_str());

   c02->cd();
   c02->SaveAs((outDir + outPre + "_" + varName[0] + "_ee.pdf").c_str());

   c01->Close(); c02->Close();
   gROOT->ProcessLine(".q");
   
}

int main() {

  tnpOn();
  return 0;

}



