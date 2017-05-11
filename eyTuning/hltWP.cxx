// A single file where WP-related stuff are defined
// Also stuff relating to HLT plots
// Not sure if this is the best way about this, but it'll do

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <utility>

#include "TH1.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TStyle.h"
#include "TH1F.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TLegend.h"
#include "TGaxis.h"
#include "TLatex.h"

// ------- HLT WP related methods ------- //

const double etaEB = 1.4442, etaET = 1.566, etaEE = 2.5;



// The cut values for each WP is stored here
// The form is always varVal[i] < varThr[i]
double getThr(const std::string& setWP, const double& et, const double& eta, const int& iThr) {

  /*/ Order as in the method call -> HLT filtering
  vVal[0] = sie;
  vVal[1] = (hoe - (eaHoe * rho)) / ene;
  vVal[2] = (eca - (eaEca * rho)) / et;
  vVal[3] = (hca - (eaHca * rho)) / et;;
  vVal[4] = eop;
  vVal[5] = chi;
  vVal[6] = mih;
  vVal[7] = des;
  vVal[8] = dph;
  vVal[9] = tks / et;
  vVal[10] = eaHoe;
  vVal[11] = eaEca;
  vVal[12] = eaHca;
  */

  double vThr[13];

  if (std::abs(eta) < 1.4791 && setWP == "WPLoose16") {
    vThr[0] = 0.011; vThr[1] = 0.08;
    vThr[2] = 0.04 ; vThr[3] = 0.06;
    vThr[4] = 0.012; vThr[5] = 999.0;
    vThr[6] = 999.0; vThr[7] = 0.0044;
    vThr[8] = 0.025; vThr[9] = 0.085;

    vThr[10] = 0.079; vThr[11] = 0.29; vThr[12] = 0.2;
  }

  else if (std::abs(eta) > 1.4791 && setWP == "WPLoose16") {
    vThr[0] = 0.031; vThr[1] = 0.04;
    vThr[2] = 0.045; vThr[3] = 0.08;
    vThr[4] = 0.01 ; vThr[5] = 4.0;
    vThr[6] = 2.5  ; vThr[7] = 0.006;
    vThr[8] = 0.025; vThr[9] = 0.07;

    vThr[10] = 0.25; vThr[11] = 0.21; vThr[12] = 0.25;
  }

  else if (std::abs(eta) < 1.4791 && setWP == "WPTight16") {
    vThr[0] = 0.0105; vThr[1] = 0.07;
    vThr[2] = 0.032 ; vThr[3] = 0.055;
    vThr[4] = 0.01  ; vThr[5] = 999.0;
    vThr[6] = 999.0 ; vThr[7] = 0.004;
    vThr[8] = 0.02  ; vThr[9] = 0.07;

    vThr[10] = 0.079; vThr[11] = 0.29; vThr[12] = 0.2;
  }

  else if (std::abs(eta) > 1.4791 && setWP == "WPTight16") {
    vThr[0] = 0.0285; vThr[1] = 0.035;
    vThr[2] = 0.04  ; vThr[3] = 0.05;
    vThr[4] = 0.008 ; vThr[5] = 3.5;
    vThr[6] = 2.5   ; vThr[7] = 0.0045;
    vThr[8] = 0.022 ; vThr[9] = 0.05;

    vThr[10] = 0.25; vThr[11] = 0.21; vThr[12] = 0.25;
  }

  else {
    vThr[0] = 9999. ; vThr[1] = 9999.;
    vThr[2] = 9999. ; vThr[3] = 9999.;
    vThr[4] = 9999. ; vThr[5] = 9999.;
    vThr[6] = 9999. ; vThr[7] = 9999.;
    vThr[8] = 9999. ; vThr[9] = 9999.;

    vThr[10] = 0.; vThr[11] = 0.; vThr[12] = 0.;
  }

  return vThr[iThr];
}



// Check if a candidate passes a given WP
// Ensure the actual quantities are sent i.e. H, not H/E, EcalIso, not the relative one...
bool checkCand(const std::string &setWP, const int &iMask, const double &rho,
               const double &ene, const double &et, const double &eta, const double &phi,
               const double &sie, const double &hoe, const double &eca, const double &hca,
               const double &eop, const double &chi, const double &mih,
               const double &des, const double &dph, const double &tks) {
  bool candOk = true;
  double eaHoe, eaEca, eaHca;
  double vVal[10];

  // Order as in the method call -> HLT filtering
  vVal[0] = sie;
  vVal[1] = (hoe - (getThr(setWP, et, eta, 10) * rho)) / ene;
  vVal[2] = (eca - (getThr(setWP, et, eta, 11) * rho)) / et;
  vVal[3] = (hca - (getThr(setWP, et, eta, 12) * rho)) / et;;
  vVal[4] = eop;
  vVal[5] = chi;
  vVal[6] = mih;
  vVal[7] = des;
  vVal[8] = dph;
  vVal[9] = tks / et;

  for (int aa = 0; aa < 10; aa++) {
    if (aa == iMask) continue; // N - 1 cut masking
    candOk = candOk and (vVal[aa] < getThr(setWP, et, eta, aa));
  }

  return candOk;
}



// ------- Plotting related methods ------- //

std::string topLeft = "#bf{CMS} #it{Preliminary}", topRight = "Many fb^{-1} (13 TeV)";



std::string toStr(double inNo) { std::ostringstream outStr; outStr << inNo; return outStr.str(); }
std::string toStr(int inNo) { std::ostringstream outStr; outStr << inNo; return outStr.str(); }



void styleHist(TH1D* vHist, int useCol, int filSty, int marSty, int marSiz, double linWid) {
   vHist->SetFillColor(useCol);
   vHist->SetFillStyle(filSty);
   vHist->SetMarkerColor(useCol);
   vHist->SetMarkerStyle(marSty);
   vHist->SetMarkerSize(marSiz);
   vHist->SetLineColor(useCol);
   vHist->SetLineWidth(linWid);
}



void axHist(TH1D* vHist, double yMin, double yMax,
            std::string yTxt, double ySiz, double yOff, double yLab,
            std::string xTxt, double xSiz, double xOff, double xLab) {
   vHist->SetMinimum(yMin);
   vHist->SetMaximum(yMax);

   vHist->SetYTitle(yTxt.c_str());
   vHist->GetYaxis()->SetTitleSize(ySiz);
   vHist->GetYaxis()->SetTitleOffset(yOff);
   vHist->GetYaxis()->SetLabelSize(yLab);

   vHist->SetXTitle(xTxt.c_str());
   vHist->GetXaxis()->SetTitleSize(xSiz);
   vHist->GetXaxis()->SetTitleOffset(xOff);
   vHist->GetXaxis()->SetLabelSize(xLab);
}



void axGr(TGraph* vGr, Float_t yMin, Float_t yMax,
          string yTxt, Float_t ySiz, Float_t yOff, Float_t yLab,
          string xTxt, Float_t xSiz, Float_t xOff, Float_t xLab) {
   vGr->SetMinimum(yMin);
   vGr->SetMaximum(yMax);

   vGr->GetYaxis()->SetTitle(yTxt.c_str());
   vGr->GetYaxis()->SetTitleSize(ySiz);
   vGr->GetYaxis()->SetTitleOffset(yOff);
   vGr->GetYaxis()->SetLabelSize(yLab);

   vGr->GetXaxis()->SetTitle(xTxt.c_str());
   vGr->GetXaxis()->SetTitleSize(xSiz);
   vGr->GetXaxis()->SetTitleOffset(xOff);
   vGr->GetXaxis()->SetLabelSize(xLab);
}



void styleLeg(TLegend* vLeg, int nCol, int fColor, int borSiz, int texFon, double texSiz, std::string legHead = "") {
  vLeg->SetHeader( legHead.c_str() );
  vLeg->SetNColumns(nCol);
  vLeg->SetFillColor(fColor);
  vLeg->SetBorderSize(borSiz);
  vLeg->SetTextFont(texFon);
  vLeg->SetTextSize(texSiz);
}



void createEBEERatioPlot(std::pair <std::string, std::string>* pairFileLeg,
                         std::string vName, TH1D** h_b, TH1D** h_e, const int nH,
                         std::string fName, std::string xName,
                         std::string yName, std::string sName,
                         bool drawLog, int maxAx,
                         double yMin_b, double yMax_b,
                         double yMin_e, double yMax_e) {
  double cut_b = -9999., cut_e = -9999.;
  std::string lHead = "";

  if (yName == "") yName = "e / bin";
  if (sName == "") sName = "HLT / Offline";

  if (maxAx != -1) TGaxis::SetMaxDigits(maxAx);
  else TGaxis::SetMaxDigits(5);

  std::cout << h_b[0]->GetEntries() << " " << h_b[1]->GetEntries() << " " << h_b[2]->GetEntries() << std::endl;
  std::cout << h_e[0]->GetEntries() << " " << h_e[1]->GetEntries() << " " << h_e[2]->GetEntries() << std::endl;

  //h_b[0]->Scale( 1. / h_b[0]->Integral()); h_e[0]->Scale( 1. / h_e[0]->Integral());
  //h_b[1]->Scale( 1. / h_b[1]->Integral()); h_e[1]->Scale( 1. / h_e[1]->Integral());

  const int hb_nBin = h_b[0]->GetNbinsX(), he_nBin = h_e[0]->GetNbinsX();
  const double hb_min = h_b[0]->GetBinLowEdge(1), hb_max = h_b[0]->GetBinLowEdge(hb_nBin) + h_b[0]->GetBinWidth(hb_nBin);
  const double he_min = h_e[0]->GetBinLowEdge(1), he_max =  h_e[0]->GetBinLowEdge(he_nBin) + h_e[0]->GetBinWidth(he_nBin);

  double sStep_b = h_b[0]->GetBinWidth(1), sStep_e = h_e[0]->GetBinWidth(1);

  double l1b[hb_nBin + 1], eff_xb[hb_nBin + 1];
  double l1e[he_nBin + 1], eff_xe[he_nBin + 1];
  double std_xb[hb_nBin + 1], std_xe[he_nBin + 1], std_yb[hb_nBin + 1], std_ye[he_nBin + 1];

  for (int bb = 0; bb < hb_nBin + 1; bb++) {
    l1b[bb] = 1.;
    eff_xb[bb] = (bb * sStep_b) + hb_min;

    std_xb[bb] = cut_b;
    if (bb == 0) std_yb[bb] = yMax_b;
    else if (bb == hb_nBin) std_yb[bb] = 0.;
    else std_yb[bb] = (1. - ((double) (bb + 1) / (double) hb_nBin + 1));
  }

  for (int ee = 0; ee < he_nBin + 1; ee++) {
    l1e[ee] = 1.;
    eff_xe[ee] = (ee * sStep_e) + he_min;

    std_xe[ee] = cut_e;
    if (ee == 0) std_ye[ee] = yMax_e;
    else if (ee == he_nBin) std_ye[ee] = 0.;
    else std_ye[ee] = (1. - ((double) (ee + 1) / (double) he_nBin + 1));
  }

  TGraph *lineb = new TGraph(hb_nBin + 1, eff_xb, l1b);
  lineb->SetLineColor(kGray + 2);
  lineb->SetLineWidth(2);
  lineb->SetLineStyle(5);

  TGraph *linee = new TGraph(he_nBin + 1, eff_xe, l1e);
  linee->SetLineColor(kGray + 2);
  linee->SetLineWidth(2);
  linee->SetLineStyle(5);

  TH1D *sfb[nH], *sfe[nH];

  for (int iH = 0; iH < nH; iH++) {
    sfb[iH] = new TH1D("", "", hb_nBin, hb_min, hb_max);
    sfb[iH]->Divide(h_b[iH], h_b[0], 1., 1., "B");
    styleHist(sfb[iH], h_b[iH]->GetLineColor(), h_b[iH]->GetFillStyle(), h_b[iH]->GetMarkerStyle(), 1, 1.0);
    axHist(sfb[iH], 0.001, 1.999, sName, 0.061, 0.49, 0.059, xName, 0.077, 0.95, 0.073);

    sfe[iH] = new TH1D("", "", he_nBin, he_min, he_max);
    sfe[iH]->Divide(h_e[iH], h_e[0], 1., 1., "B");
    styleHist(sfe[iH], h_e[iH]->GetLineColor(), h_e[iH]->GetFillStyle(), h_e[iH]->GetMarkerStyle(), 1, 1.0);
    axHist(sfe[iH], 0.001, 1.999, sName, 0.061, 0.49, 0.059, xName, 0.077, 0.95, 0.073);
  }

  TGraph* stdb = new TGraph(hb_nBin + 1, std_xb, std_yb);
  stdb->SetLineColor(kBlack);
  stdb->SetLineWidth(3);

  TGraph* stde = new TGraph(he_nBin + 1, std_xe, std_ye);
  stde->SetLineColor(kBlack);
  stde->SetLineWidth(3);

  // -------------------------------------------------- //

  if (drawLog) {
    yMin_b++;
    yMin_e++;
  }

  axHist(h_b[0], yMin_b, yMax_b, yName, 0.035, 0.9, 0.031, xName, 0.037, 1.15, 0.033);
  axHist(h_e[0], yMin_e, yMax_e, yName, 0.035, 0.9, 0.031, xName, 0.037, 1.15, 0.033);

  TLatex txt;
  txt.SetTextSize(0.035);
  txt.SetTextAlign(13);

  TLegend *bLeg, *eLeg;
  bLeg = new TLegend();
  eLeg = new TLegend();

  std::string bHead, eHead;
  bHead = "#left|#eta^{e}#right| < " + toStr(etaEB);
  eHead = toStr(etaET) + " < #left|#eta^{e}#right| < " + toStr(etaEE);

  std::string sLeg;
  for (int iH = 0; iH < nH; iH++) {
    if (iH == 0) sLeg = "f";
    else sLeg = "lp";
    bLeg->AddEntry(h_b[iH], (pairFileLeg[iH].second).c_str(), sLeg.c_str());
    eLeg->AddEntry(h_e[iH], (pairFileLeg[iH].second).c_str(), sLeg.c_str());
  }

  // -------------------------------------------------- //

  TCanvas *c01 = new TCanvas("c01", "c01", 200, 10, 1000, 1000);
  TCanvas *c02 = new TCanvas("c02", "c02", 200, 10, 1000, 1000);

  txt.SetTextSize(0.035);

  styleLeg(bLeg, 3, 0, 0, 42, 0.037, lHead + bHead);
  bLeg->SetX1(0.435); bLeg->SetX2(0.895);
  bLeg->SetY1(0.675); bLeg->SetY2(0.855);

  styleLeg(eLeg, 3, 0, 0, 42, 0.037, lHead + eHead);
  eLeg->SetX1(0.435); eLeg->SetX2(0.895);
  eLeg->SetY1(0.675); eLeg->SetY2(0.855);

  c01->cd();

  TPad *pad1 = new TPad("pad1", "pad1", 0., 0.29, 1., 1.);
  pad1->SetBottomMargin(0);
  pad1->Draw();
  pad1->cd();

  if (drawLog) pad1->SetLogy();
  for (int iH = 0; iH < nH; iH++) {
    if (iH == 0) h_b[iH]->Draw("hist");
    else h_b[iH]->Draw("pesame");
  }
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

  sfb[1]->Draw("pe");
  lineb->Draw("lsame");
  for (int iH = 1; iH < nH; iH++)
    sfb[iH]->Draw("pesame");

  c02->cd();

  TPad *pad3 = new TPad("pad3", "pad3", 0., 0.29, 1., 1.);
  pad3->SetBottomMargin(0);
  pad3->Draw();
  pad3->cd();

  if (drawLog) pad3->SetLogy();
  for (int iH = 0; iH < nH; iH++) {
    if (iH == 0) h_e[iH]->Draw("hist");
    else h_e[iH]->Draw("pesame");
  }
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

  sfe[1]->Draw("pe");
  linee->Draw("lsame");
  for (int iH = 1; iH < nH; iH++)
    sfe[iH]->Draw("pesame");

  // -------------------------------------------------- //

  c01->cd();
  c01->SaveAs((fName + vName + "_eb.pdf").c_str());

  c02->cd();
  c02->SaveAs((fName + vName + "_ee.pdf").c_str());

  c01->Close(); c02->Close();
}



void createEBEEPlot(std::pair <std::string, std::string>* pairFileLeg,
                    std::string vName, TH1D** h_b, TH1D** h_e, const int nH,
                    std::string fName, std::string xName,
                    std::string yName, int maxAx,
                    double yMin_b, double yMax_b,
                    double yMin_e, double yMax_e) {
  double cut_b = -9999., cut_e = -9999.;
  std::string lHead = "";

  if (yName == "") yName = "e / bin";

  if (maxAx != -1) TGaxis::SetMaxDigits(maxAx);
  else TGaxis::SetMaxDigits(5);

  axHist(h_b[0], yMin_b, yMax_b, yName, 0.033, 0.87, 0.025, xName, 0.033, 0.87, 0.025);
  axHist(h_e[0], yMin_e, yMax_e, yName, 0.033, 0.87, 0.025, xName, 0.033, 0.87, 0.025);

  TLatex txt;
  txt.SetTextSize(0.035);
  txt.SetTextAlign(13);

  TLegend *bLeg, *eLeg;
  bLeg = new TLegend();
  eLeg = new TLegend();

  std::string bHead, eHead;
  bHead = "#left|#eta^{e}#right| < " + toStr(etaEB);
  eHead = toStr(etaET) + " < #left|#eta^{e}#right| < " + toStr(etaEE);

  std::string sLeg;
  for (int iH = 0; iH < nH; iH++) {
    sLeg = "lp";
    bLeg->AddEntry(h_b[iH], (pairFileLeg[iH].second).c_str(), sLeg.c_str());
    eLeg->AddEntry(h_e[iH], (pairFileLeg[iH].second).c_str(), sLeg.c_str());
  }

  // -------------------------------------------------- //

  TCanvas *c01 = new TCanvas("c01", "c01", 200, 10, 1000, 1000);
  TCanvas *c02 = new TCanvas("c02", "c02", 200, 10, 1000, 1000);

  txt.SetTextSize(0.035);

  styleLeg(bLeg, 3, 0, 0, 42, 0.029, lHead + bHead);
  bLeg->SetX1(0.435); bLeg->SetX2(0.935);
  bLeg->SetY1(0.675); bLeg->SetY2(0.855);

  styleLeg(eLeg, 3, 0, 0, 42, 0.029, lHead + eHead);
  eLeg->SetX1(0.435); eLeg->SetX2(0.935);
  eLeg->SetY1(0.675); eLeg->SetY2(0.855);

  c01->cd();
  for (int iH = 0; iH < nH; iH++) {
    if (iH == 0) h_b[iH]->Draw("hist e2");
    else h_b[iH]->Draw("hist e2 same");
  }

  bLeg->Draw();
  //txt.DrawLatexNDC(0.06, 0.928, topLeft.c_str());
  //txt.DrawLatexNDC(0.783, 0.933, topRight.c_str());

  c02->cd();
  for (int iH = 0; iH < nH; iH++) {
    if (iH == 0) h_e[iH]->Draw("hist e2");
    else h_e[iH]->Draw("hist e2 same");
  }

  eLeg->Draw();
  //txt.DrawLatexNDC(0.06, 0.928, topLeft.c_str());
  //txt.DrawLatexNDC(0.783, 0.933, topRight.c_str());

  // -------------------------------------------------- //

  c01->cd();
  c01->SaveAs((fName + vName + "_eb.pdf").c_str());

  c02->cd();
  c02->SaveAs((fName + vName + "_ee.pdf").c_str());

  c01->Close(); c02->Close();
}



// ------- e-ID binnings ------- //

const int meeb_nBin = 82, meee_nBin = 82;
const double meeb_max = 110.5, meee_max = 110.5;
const double meeb_min = 69.5, meee_min = 69.5;

const int etab_nBin = 54, etae_nBin = 54;
const double etab_max = 2.7, etae_max = 2.7;
const double etab_min = -2.7, etae_min = -2.7;

const int phib_nBin = 18, phie_nBin = 18;
const double phib_max = 3.142, phie_max = 3.142;
const double phib_min = -3.142, phie_min = -3.142;

const int eetb_nBin = 80, eete_nBin = 80;
const double eetb_max = 240., eete_max = 240.;
const double eetb_min = 0., eete_min = 0.;

const int sieb_nBin = 50, siee_nBin = 60;
const double sieb_max = .02, siee_max = .06;
const double sieb_min = 0., siee_min = 0.;

const int hoeb_nBin = 60, hoee_nBin = 60;
const double hoeb_max = 30., hoee_max = 30.;
const double hoeb_min = 0., hoee_min = 0.;

const int horb_nBin = 40, hore_nBin = 40;
const double horb_max = .2, hore_max = .2;
const double horb_min = 0., hore_min = 0.;

const int ecab_nBin = 60, ecae_nBin = 60;
const double ecab_max = 30., ecae_max = 30.;
const double ecab_min = 0., ecae_min = 0.;

const int ecrb_nBin = 60, ecre_nBin = 60;
const double ecrb_max = .6, ecre_max = .6;
const double ecrb_min = 0., ecre_min = 0.;

const int hcab_nBin = 60, hcae_nBin = 60;
const double hcab_max = 30., hcae_max = 30.;
const double hcab_min = 0., hcae_min = 0.;

const int hcab_nBin = 60, hcae_nBin = 60;
const double hcab_max = .6, hcae_max = .6;
const double hcab_min = 0., hcae_min = 0.;

const int eopb_nBin = 100, eope_nBin = 100;
const double eopb_max = .1, eope_max = .1;
const double eopb_min = 0., eope_min = 0.;

const int chib_nBin = 100, chie_nBin = 100;
const double chib_max = 10., chie_max = 10.;
const double chib_min = 0., chie_min = 0.;

const int mihb_nBin = 4, mihe_nBin = 6;
const double mihb_max = 3.5, mihe_max = 5.5;
const double mihb_min = -0.5, mihe_min = -0.5;

const int desb_nBin = 60, dese_nBin = 60;
const double desb_max = 0.03, dese_max = 0.03;
const double desb_min = 0., dese_min = 0.;

const int dphb_nBin = 100, dphe_nBin = 100;
const double dphb_max = 0.1, dphe_max = 0.1;
const double dphb_min = 0., dphe_min = 0.;

const int tksb_nBin = 100, tkse_nBin = 100;
const double tksb_max = 10., tkse_max = 10.;
const double tksb_min = 0., tkse_min = 0.;

const int tkrb_nBin = 100, tkre_nBin = 100;
const double tkrb_max = .5, tkre_max = .5;
const double tkrb_min = 0., tkre_min = 0.;

const int lolb_nBin = 40, lole_nBin = 40;
const double lolb_max = .2, lole_max = .2;
const double lolb_min = -.2, lole_min = -.2;
