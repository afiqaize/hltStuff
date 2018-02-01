// A single file where stuff relating to plots are defined
// HLT only for now, but will include analysis too
// Not sure if this is the best way about this, but it'll do

#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <utility>

#include "TH1.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TStyle.h"
#include "TH1D.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TLegend.h"
#include "TGaxis.h"
#include "TLatex.h"
#include "TGraphAsymmErrors.h"

// ------- Utility methods ------- //

std::string topLeft = "#bf{CMS} #it{Really Cool Stuff}", topRight = "Many fb^{-1} (13 TeV)";



bool replace(std::string &str, const std::string &from, const std::string &to) {
  size_t start_pos = str.find(from);
  if (start_pos == std::string::npos)
    return false;
  str.replace(start_pos, from.length(), to);
  return true;
}


// ------- Styling methods ------- //

std::string toStr(double inNo) { std::ostringstream outStr; outStr << inNo; return outStr.str(); }
std::string toStr(int inNo) { std::ostringstream outStr; outStr << inNo; return outStr.str(); }



void styleHist(TH1* vHist, int useCol, int filSty, int marSty, int marSiz, double linWid) {
   vHist->SetFillColor(useCol);
   vHist->SetFillStyle(filSty);
   vHist->SetMarkerColor(useCol);
   vHist->SetMarkerStyle(marSty);
   vHist->SetMarkerSize(marSiz);
   vHist->SetLineColor(useCol);
   vHist->SetLineWidth(linWid);
}



void styleGr(TGraph* vGr, int useCol, int filSty, int marSty, int marSiz, double linWid) {
  vGr->SetFillColor(useCol);
  vGr->SetFillStyle(filSty);
  vGr->SetMarkerColor(useCol);
  vGr->SetMarkerStyle(marSty);
  vGr->SetMarkerSize(marSiz);
  vGr->SetLineColor(useCol);
  vGr->SetLineWidth(linWid);
}



void axHist(TH1* vHist, double yMin, double yMax,
            std::string yTxt, double ySiz, double yOff, double yLab,
            std::string xTxt, double xSiz, double xOff, double xLab) {

  if (yMin != -999.)
    vHist->SetMinimum(yMin);

  if (yMax != -999.)
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



void axGr(TGraph* vGr, double yMin, double yMax,
          std::string yTxt, double ySiz, double yOff, double yLab,
          std::string xTxt, double xSiz, double xOff, double xLab) {
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



void putLeg(TLegend* vLeg, double x1, double x2, double y1, double y2) {
  vLeg->SetX1(x1); vLeg->SetX2(x2);
  vLeg->SetY1(y1); vLeg->SetY2(y2);
}



// ------- Drawing methods ------- //

double sumAtBin(int iBin, TH1* hist) {
  double eff = 0.;
  int lim = 0;

  for (int j = iBin; j > lim; j--)
    eff += hist->GetBinContent(j);

  return eff;
}



void makeVertCutGraph(TH1** hCut, TGraph** gCut,
                      std::vector< std::pair<double, int> > cutValCol,
                      double yMin, double yMax) {
  const int h_nBin = hCut[0]->GetNbinsX();
  const double h_min = hCut[0]->GetBinLowEdge(1), h_max = hCut[0]->GetBinLowEdge(h_nBin) + hCut[0]->GetBinWidth(h_nBin);
  const double sStep = hCut[0]->GetBinWidth(1);

  for (unsigned iC = 0; iC < cutValCol.size(); iC++) {
    std::vector<double> xCut, yCut;

    for (int nC = 0; nC < h_nBin + 1; nC++) {
      xCut.push_back(cutValCol.at(iC).first);
      if (nC == 0) yCut.push_back(yMax * 2.);
      else if (nC == h_nBin) yCut.push_back(yMin / 2.);
      else yCut.push_back( (1. - ((double) (nC + 1) / (double) h_nBin + 1)) );
    }

    gCut[iC] = new TGraph(h_nBin + 1, xCut.data(), yCut.data());
    gCut[iC]->SetLineColor(cutValCol.at(iC).second);
    gCut[iC]->SetLineWidth(3);

    xCut.clear(); yCut.clear();
  }
}



void createEBEERatioPlot(std::pair <std::string, std::string>* pairFileLeg,
                         std::string vName, TH1** h_b, TH1** h_e, const int nH,
                         std::vector< std::pair<double, int> > cutValCol_b, std::vector< std::pair<double, int> > cutValCol_e,
                         std::string lHead, bool doNorm, double normScale,
                         std::string fName, std::string xName,
                         std::string yName, std::string sName,
                         bool drawLog, int maxAx,
                         double yMin_b = 0., double yMax_b = 99999.,
                         double yMin_e = 0., double yMax_e = 99999.,
                         double sMin_b = 0., double sMax_b = 99999.,
                         double sMin_e = 0., double sMax_e = 99999.) {
  const std::string hName(h_b[0]->GetName());

  for (int iH = 0; iH < nH; iH++) {
    // assign -999. as unit area normalization
    if (doNorm && normScale == -999.) {
      h_b[iH]->Scale( 1. / std::abs(h_b[iH]->Integral()) );
      h_e[iH]->Scale( 1. / std::abs(h_e[iH]->Integral()) );
    }
    else if (doNorm && normScale != -999.) {
      h_b[iH]->Scale( normScale );
      h_e[iH]->Scale( normScale );
    }
  }

  if (yName == "") yName = "e / bin";
  if (sName == "") sName = "HLT / Offline";

  if (maxAx != -1) TGaxis::SetMaxDigits(maxAx);
  else TGaxis::SetMaxDigits(5);

  //std::cout << h_b[0]->GetEntries() << " " << h_b[1]->GetEntries() << " " << h_b[2]->GetEntries() << std::endl;
  //std::cout << h_e[0]->GetEntries() << " " << h_e[1]->GetEntries() << " " << h_e[2]->GetEntries() << std::endl;

  const int hb_nBin = h_b[0]->GetNbinsX(), he_nBin = h_e[0]->GetNbinsX();
  const double hb_min = h_b[0]->GetBinLowEdge(1), hb_max = h_b[0]->GetBinLowEdge(hb_nBin) + h_b[0]->GetBinWidth(hb_nBin);
  const double he_min = h_e[0]->GetBinLowEdge(1), he_max =  h_e[0]->GetBinLowEdge(he_nBin) + h_e[0]->GetBinWidth(he_nBin);

  double sStep_b = h_b[0]->GetBinWidth(1), sStep_e = h_e[0]->GetBinWidth(1);

  double l1b[hb_nBin + 1], var_xb[hb_nBin + 1];
  double l1e[he_nBin + 1], var_xe[he_nBin + 1];

  for (int bb = 0; bb < hb_nBin + 1; bb++) {
    l1b[bb] = 1.;
    var_xb[bb] = (bb * sStep_b) + hb_min;
  }
  for (int ee = 0; ee < he_nBin + 1; ee++) {
    l1e[ee] = 1.;
    var_xe[ee] = (ee * sStep_e) + he_min;
  }

  TGraph *lineb = new TGraph(hb_nBin + 1, var_xb, l1b);
  lineb->SetLineColor(kGray + 2);
  lineb->SetLineWidth(2);
  lineb->SetLineStyle(5);

  TGraph *linee = new TGraph(he_nBin + 1, var_xe, l1e);
  linee->SetLineColor(kGray + 2);
  linee->SetLineWidth(2);
  linee->SetLineStyle(5);

  TH1D *sfb[nH], *sfe[nH];
  for (int iH = 0; iH < nH; iH++) {
    sfb[iH] = (TH1D*) h_b[0]->Clone();
    sfb[iH]->Reset();
    sfb[iH]->Divide(h_b[iH], h_b[0], 1., 1., "B");
    styleHist(sfb[iH], h_b[iH]->GetLineColor(), h_b[iH]->GetFillStyle(), h_b[iH]->GetMarkerStyle(), 1, 1.0);
    axHist(sfb[iH], sMin_b, sMax_b, sName, 0.061, 0.49, 0.059, xName, 0.077, 0.95, 0.073);

    sfe[iH] = (TH1D*) h_e[0]->Clone();
    sfe[iH]->Reset();
    sfe[iH]->Divide(h_e[iH], h_e[0], 1., 1., "B");
    styleHist(sfe[iH], h_e[iH]->GetLineColor(), h_e[iH]->GetFillStyle(), h_e[iH]->GetMarkerStyle(), 1, 1.0);
    axHist(sfe[iH], sMin_e, sMax_e, sName, 0.061, 0.49, 0.059, xName, 0.077, 0.95, 0.073);
  }

  // -------------------------------------------------- //

  axHist(h_b[0], yMin_b, yMax_b, yName, 0.035, 0.9, 0.031, xName, 0.037, 1.15, 0.033);
  axHist(h_e[0], yMin_e, yMax_e, yName, 0.035, 0.9, 0.031, xName, 0.037, 1.15, 0.033);

  TLatex txt;
  txt.SetTextSize(0.035);
  txt.SetTextAlign(13);

  TLegend *bLeg, *eLeg;
  bLeg = new TLegend();
  eLeg = new TLegend();

  std::string bHead, eHead;
  if (hName.find("eta_") == std::string::npos) {
    bHead = "#left|#eta^{e}#right| < " + toStr(etaEB);
    eHead = toStr(etaET) + " < #left|#eta^{e}#right| < " + toStr(etaEE);
  }

  std::string sLeg;
  for (int iH = 0; iH < nH; iH++) {
    if (iH == 0) sLeg = "f";
    else sLeg = "lp";
    bLeg->AddEntry(h_b[iH], (pairFileLeg[iH].second).c_str(), sLeg.c_str());
    eLeg->AddEntry(h_e[iH], (pairFileLeg[iH].second).c_str(), sLeg.c_str());
  }

  // -------------------------------------------------- //

  const int nCut_b = cutValCol_b.size();
  TGraph *gCut_b[nCut_b];
  if (nCut_b > 0)
    makeVertCutGraph(h_b, gCut_b, cutValCol_b, yMin_b, yMax_b);

  const int nCut_e = cutValCol_e.size();
  TGraph *gCut_e[nCut_e];
  if (nCut_e > 0)
    makeVertCutGraph(h_e, gCut_e, cutValCol_e, yMin_e, yMax_e);

  // -------------------------------------------------- //

  TCanvas *c01 = new TCanvas("c01", "c01", 200, 10, 1000, 1000);
  TCanvas *c02 = new TCanvas("c02", "c02", 200, 10, 1000, 1000);

  txt.SetTextSize(0.035);

  styleLeg(bLeg, 3, 0, 0, 42, 0.037, lHead + bHead);
  putLeg(bLeg, 0.435, 0.895, 0.675, 0.855);

  styleLeg(eLeg, 3, 0, 0, 42, 0.037, lHead + eHead);
  putLeg(eLeg, 0.435, 0.895, 0.675, 0.855);

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
  for (int iC = 0; iC < nCut_b; iC++)
    gCut_b[iC]->Draw("same");

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
  for (int iC = 0; iC < nCut_e; iC++)
    gCut_e[iC]->Draw("same");

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
  c01->SaveAs((fName + vName + "_hist_eb.pdf").c_str());
  c01->SaveAs((fName + vName + "_hist_eb.C").c_str());

  c02->cd();
  c02->SaveAs((fName + vName + "_hist_ee.pdf").c_str());
  c02->SaveAs((fName + vName + "_hist_ee.C").c_str());

  c01->Close(); c02->Close();
}



void createEBEEPlot(std::pair <std::string, std::string>* pairFileLeg,
                    std::string vName, TH1** h_b, TH1** h_e, const int nH,
                    std::vector< std::pair<double, int> > cutValCol_b, std::vector< std::pair<double, int> > cutValCol_e,
                    std::string lHead, bool doNorm, double normScale,
                    std::string fName, std::string xName,
                    std::string yName,
                    bool drawLog, int maxAx,
                    double yMin_b, double yMax_b,
                    double yMin_e, double yMax_e) {
  const std::string hName(h_b[0]->GetName());

  for (int iH = 0; iH < nH; iH++) {
    // assign -999. as unit area normalization
    if (doNorm && normScale == -999.) {
      h_b[iH]->Scale( 1. / std::abs(h_b[iH]->Integral()) );
      h_e[iH]->Scale( 1. / std::abs(h_e[iH]->Integral()) );
    }
    else if (doNorm && normScale != -999.) {
      h_b[iH]->Scale( normScale );
      h_e[iH]->Scale( normScale );
    }
  }

  if (yName == "") yName = "e / bin";

  if (maxAx != -1) TGaxis::SetMaxDigits(maxAx);
  else TGaxis::SetMaxDigits(5);

  axHist(h_b[0], yMin_b, yMax_b, yName, 0.033, 0.87, 0.025, xName, 0.033, 0.87, 0.025);
  axHist(h_e[0], yMin_e, yMax_e, yName, 0.033, 0.87, 0.025, xName, 0.033, 0.87, 0.025);

  TLatex txt;
  txt.SetTextSize(0.035);
  txt.SetTextAlign(13);

  std::string bHead =  "", eHead = "";
  if (hName.find("eta_") == std::string::npos) {
    bHead = "#left|#eta^{SC}#right| < " + toStr(etaEB);
    eHead = toStr(etaET) + " < #left|#eta^{SC}#right| < " + toStr(etaEE);
  }

  TLegend *bLeg, *eLeg;
  bLeg = new TLegend();
  eLeg = new TLegend();

  std::string sLeg;
  for (int iH = 0; iH < nH; iH++) {
    sLeg = "lp";
    bLeg->AddEntry(h_b[iH], (pairFileLeg[iH].second).c_str(), sLeg.c_str());
    eLeg->AddEntry(h_e[iH], (pairFileLeg[iH].second).c_str(), sLeg.c_str());
  }

  // -------------------------------------------------- //

  const int nCut_b = cutValCol_b.size();
  TGraph *gCut_b[nCut_b];
  if (nCut_b > 0)
    makeVertCutGraph(h_b, gCut_b, cutValCol_b, yMin_b, yMax_b);

  const int nCut_e = cutValCol_e.size();
  TGraph *gCut_e[nCut_e];
  if (nCut_e > 0)
    makeVertCutGraph(h_e, gCut_e, cutValCol_e, yMin_e, yMax_e);

  // -------------------------------------------------- //

  TCanvas *c01 = new TCanvas("c01", "c01", 200, 10, 1000, 1000);
  TCanvas *c02 = new TCanvas("c02", "c02", 200, 10, 1000, 1000);

  styleLeg(bLeg, 1, 0, 0, 42, 0.033, lHead + bHead);
  putLeg(bLeg, 0.635, 0.955, 0.695, 0.875);

  styleLeg(eLeg, 1, 0, 0, 42, 0.033, lHead + eHead);
  putLeg(eLeg, 0.635, 0.955, 0.695, 0.875);

  c01->cd();
  if (drawLog) c01->SetLogy();
  for (int iH = 0; iH < nH; iH++) {
    if (iH == 0) h_b[iH]->Draw("hist e2");
    else h_b[iH]->Draw("hist e2 same");
  }
  for (int iC = 0; iC < nCut_b; iC++)
    gCut_b[iC]->Draw("same");

  bLeg->Draw();
  //txt.DrawLatexNDC(0.06, 0.928, topLeft.c_str());
  //txt.DrawLatexNDC(0.783, 0.933, topRight.c_str());

  c02->cd();
  if (drawLog) c02->SetLogy();
  for (int iH = 0; iH < nH; iH++) {
    if (iH == 0) h_e[iH]->Draw("hist e2");
    else h_e[iH]->Draw("hist e2 same");
  }
  for (int iC = 0; iC < nCut_e; iC++)
    gCut_e[iC]->Draw("same");

  eLeg->Draw();
  //txt.DrawLatexNDC(0.06, 0.928, topLeft.c_str());
  //txt.DrawLatexNDC(0.783, 0.933, topRight.c_str());

  // -------------------------------------------------- //

  c01->cd();
  c01->SaveAs((fName + vName + "_hist_eb.pdf").c_str());
  c01->SaveAs((fName + vName + "_hist_eb.C").c_str());

  c02->cd();
  c02->SaveAs((fName + vName + "_hist_ee.pdf").c_str());
  c02->SaveAs((fName + vName + "_hist_ee.C").c_str());

  c01->Close(); c02->Close();
}



void createEBEEEffPlot(std::pair <std::string, std::string>* pairFileLeg,
                       std::string vName, TH1** h_b, TH1** h_e, const int nH,
                       std::vector< std::pair<double, int> > cutValCol_b, std::vector< std::pair<double, int> > cutValCol_e,
                       std::string lHead, bool doNorm, double normScale,
                       std::string fName, std::string xName,
                       std::string yName,
                       bool drawLog, int maxAx,
                       double yMin_b, double yMax_b,
                       double yMin_e, double yMax_e) {
  const std::string hName(h_b[0]->GetName());

  for (int iH = 0; iH < nH; iH++) {
    // assign -999. as unit area normalization
    if (doNorm && normScale == -999.) {
      h_b[iH]->Scale( 1. / std::abs(h_b[iH]->Integral()) );
      h_e[iH]->Scale( 1. / std::abs(h_e[iH]->Integral()) );
    }
    else if (doNorm && normScale != -999.) {
      h_b[iH]->Scale( normScale );
      h_e[iH]->Scale( normScale );
    }
  }

  if (yName == "") yName = "#epsilon / bin";

  if (maxAx != -1) TGaxis::SetMaxDigits(maxAx);
  else TGaxis::SetMaxDigits(5);

  const int hb_nBin = h_b[0]->GetNbinsX(), he_nBin = h_e[0]->GetNbinsX();
  const double hb_min = h_b[0]->GetBinLowEdge(1), hb_max = h_b[0]->GetBinLowEdge(hb_nBin) + h_b[0]->GetBinWidth(hb_nBin);
  const double he_min = h_e[0]->GetBinLowEdge(1), he_max =  h_e[0]->GetBinLowEdge(he_nBin) + h_e[0]->GetBinWidth(he_nBin);

  double sStep_b = h_b[0]->GetBinWidth(1), sStep_e = h_e[0]->GetBinWidth(1);

  double rej_yb[nH][hb_nBin + 1], eff_yb[nH][hb_nBin + 1], var_xb[hb_nBin + 1];
  double rej_ye[nH][he_nBin + 1], eff_ye[nH][he_nBin + 1], var_xe[he_nBin + 1];

  for (int bb = 0; bb < hb_nBin + 1; bb++) {
    var_xb[bb] = (bb * sStep_b) + hb_min;

    for (int iH = 0; iH < nH; iH++) {
      eff_yb[iH][bb] = sumAtBin(bb, h_b[iH]);
      rej_yb[iH][bb] = 1. - eff_yb[iH][bb];

      //if (iH == 0) std::cout << "EB eff " << h_b[0]->GetName() << " x " << var_xb[bb] << " eff " << eff_yb[iH][bb] << std::endl;
    }
  }
  for (int ee = 0; ee < he_nBin + 1; ee++) {
    var_xe[ee] = (ee * sStep_e) + he_min;

    for (int iH = 0; iH < nH; iH++) {
      eff_ye[iH][ee] = sumAtBin(ee, h_e[iH]);
      rej_ye[iH][ee] = 1. - eff_ye[iH][ee];

      //if (iH == 0) std::cout << "EB eff " << h_e[0]->GetName() << " x " << var_xe[ee] << " eff " << eff_ye[iH][ee] << std::endl;
    }
  }

  TGraph *gEff_b[nH], *gEff_e[nH];
  for (int iH = 0; iH < nH; iH++) {
    gEff_b[iH] = new TGraph(hb_nBin, var_xb, eff_yb[iH]);
    styleGr(gEff_b[iH], h_b[iH]->GetLineColor(), 0, 0, 0, 3.0);

    gEff_e[iH] = new TGraph(he_nBin, var_xe, eff_ye[iH]);
    styleGr(gEff_e[iH], h_e[iH]->GetLineColor(), 0, 0, 0, 3.0);
  }

  std::string hEff(h_b[0]->GetTitle());
  replace(hEff, "Distribution", "Efficiency Profile");

  gEff_b[0]->SetTitle(hEff.c_str());
  gEff_b[0]->GetXaxis()->SetLimits(hb_min, hb_max);
  axGr(gEff_b[0], yMin_b, yMax_b, yName, 0.033, 0.87, 0.025, xName, 0.033, 0.87, 0.025);

  gEff_e[0]->SetTitle(hEff.c_str());
  gEff_e[0]->GetXaxis()->SetLimits(he_min, he_max);
  axGr(gEff_e[0], yMin_e, yMax_e, yName, 0.033, 0.87, 0.025, xName, 0.033, 0.87, 0.025);

  TLatex txt;
  txt.SetTextSize(0.035);
  txt.SetTextAlign(13);

  std::string bHead =  "", eHead = "";
  if (hName.find("eta_") == std::string::npos) {
    bHead = "#left|#eta^{e}#right| < " + toStr(etaEB);
    eHead = toStr(etaET) + " < #left|#eta^{e}#right| < " + toStr(etaEE);
  }

  TLegend *bLeg, *eLeg;
  bLeg = new TLegend();
  eLeg = new TLegend();

  std::string sLeg;
  for (int iH = 0; iH < nH; iH++) {
    sLeg = "l";
    bLeg->AddEntry(gEff_b[iH], (pairFileLeg[iH].second).c_str(), sLeg.c_str());
    eLeg->AddEntry(gEff_e[iH], (pairFileLeg[iH].second).c_str(), sLeg.c_str());
  }

  // -------------------------------------------------- //

  const int nCut_b = cutValCol_b.size();
  TGraph *gCut_b[nCut_b];
  if (nCut_b > 0)
    makeVertCutGraph(h_b, gCut_b, cutValCol_b, yMin_b, yMax_b);

  const int nCut_e = cutValCol_e.size();
  TGraph *gCut_e[nCut_e];
  if (nCut_e > 0)
    makeVertCutGraph(h_e, gCut_e, cutValCol_e, yMin_e, yMax_e);

  // -------------------------------------------------- //

  TCanvas *c01 = new TCanvas("c01", "c01", 200, 10, 1000, 1000);
  TCanvas *c02 = new TCanvas("c02", "c02", 200, 10, 1000, 1000);

  styleLeg(bLeg, 3, 0, 0, 42, 0.033, lHead + bHead);
  putLeg(bLeg, 0.635, 0.955, 0.135, 0.315);

  styleLeg(eLeg, 3, 0, 0, 42, 0.033, lHead + eHead);
  putLeg(eLeg, 0.635, 0.955, 0.135, 0.315);

  c01->cd();
  if (drawLog) c01->SetLogy();
  for (int iH = 0; iH < nH; iH++) {
    if (iH == 0) gEff_b[iH]->Draw("al");
    else gEff_b[iH]->Draw("same");
  }
  for (int iC = 0; iC < nCut_b; iC++)
    gCut_b[iC]->Draw("same");

  bLeg->Draw();
  //txt.DrawLatexNDC(0.06, 0.928, topLeft.c_str());
  //txt.DrawLatexNDC(0.783, 0.933, topRight.c_str());

  c02->cd();
  if (drawLog) c02->SetLogy();
  for (int iH = 0; iH < nH; iH++) {
    if (iH == 0) gEff_e[iH]->Draw("al");
    else gEff_e[iH]->Draw("same");
  }
  for (int iC = 0; iC < nCut_e; iC++)
    gCut_e[iC]->Draw("same");

  eLeg->Draw();
  //txt.DrawLatexNDC(0.06, 0.928, topLeft.c_str());
  //txt.DrawLatexNDC(0.783, 0.933, topRight.c_str());

  // -------------------------------------------------- //

  c01->cd();
  c01->SaveAs((fName + vName + "_gEff_eb.pdf").c_str());
  c01->SaveAs((fName + vName + "_gEff_eb.C").c_str());

  c02->cd();
  c02->SaveAs((fName + vName + "_gEff_ee.pdf").c_str());
  c02->SaveAs((fName + vName + "_gEff_ee.C").c_str());

  c01->Close(); c02->Close();

  // -------------------------------------------------- //
  if (nH < 2) return; // ROCs relevant only for comparing 2 samples
  std::cout << std::endl;

  std::string hRoc(h_b[0]->GetTitle());
  replace(hRoc, "Distribution", "RO Curve");

  TGraph *gRoc_b = new TGraph(hb_nBin, eff_yb[0], rej_yb[1]);
  styleGr(gRoc_b, kRed, 0, 0, 0, 3.0);
  axGr(gRoc_b, 0., 1.049, (pairFileLeg[1].second + " rejection").c_str(), 0.033, 0.85, 0.025, (pairFileLeg[0].second + " efficiency").c_str(), 0.033, 1.07, 0.025);
  gRoc_b->GetXaxis()->SetLimits(0., 1.019);
  gRoc_b->SetTitle(hRoc.c_str());
  std::cout << "EB " << h_b[0]->GetName() << " integral: " << gRoc_b->Integral() << std::endl;

  TGraph *gRoc_e = new TGraph(he_nBin, eff_ye[0], rej_ye[1]);
  styleGr(gRoc_e, kRed, 0, 0, 0, 3.0);
  axGr(gRoc_e, 0., 1.049, (pairFileLeg[1].second + " rejection").c_str(), 0.033, 0.85, 0.025, (pairFileLeg[0].second + " efficiency").c_str(), 0.033, 1.07, 0.025);
  gRoc_e->GetXaxis()->SetLimits(0., 1.019);
  gRoc_e->SetTitle(hRoc.c_str());
  std::cout << "EE " << h_e[0]->GetName() << " integral: " << gRoc_e->Integral() << std::endl;

  TLatex lab;
  lab.SetTextSize(0.039);
  lab.SetTextAlign(13);
  lab.SetTextFont(42);

  TCanvas *c03 = new TCanvas("c03", "c03", 200, 10, 1000, 1000);
  TCanvas *c04 = new TCanvas("c04", "c04", 200, 10, 1000, 1000);

  c03->cd();
  c03->SetGrid();
  gRoc_b->Draw("AL");
  lab.DrawLatexNDC(0.6, 0.855, ("#bf{" + bHead + "}").c_str());
  //txt.DrawLatexNDC(0.06, 0.928, topLeft.c_str());
  //txt.DrawLatexNDC(0.783, 0.933, topRight.c_str());

  c04->cd();
  c04->SetGrid();
  gRoc_e->Draw("AL");
  lab.DrawLatexNDC(0.6, 0.855, ("#bf{" + eHead + "}").c_str());
  //txt.DrawLatexNDC(0.06, 0.928, topLeft.c_str());
  //txt.DrawLatexNDC(0.783, 0.933, topRight.c_str());

  c03->cd();
  c03->SaveAs((fName + vName + "_gRoc_eb.pdf").c_str());
  c03->SaveAs((fName + vName + "_gRoc_eb.C").c_str());

  c04->cd();
  c04->SaveAs((fName + vName + "_gRoc_ee.pdf").c_str());
  c04->SaveAs((fName + vName + "_gRoc_ee.C").c_str());

  c03->Close(); c04->Close();
}



void createPlot(std::pair <std::string, std::string>* pairFileLeg,
                std::string vName, TH1** hist, const int nH, const std::vector<int> v_ignoreHist,
                std::string lHead, bool doNorm, double normScale,
                std::string fName, std::string xName,
                std::string yName,
                bool drawLog, int maxAx, int lCol,
                double yMin, double yMax) {
  const std::string hName(hist[0]->GetName());

  for (int iH = 0; iH < nH; iH++) {
    // assign -999. as unit area normalization
    // if index of histogram is in v_ignoreHist then we skip
    if (std::find(v_ignoreHist.begin(), v_ignoreHist.end(), iH) != v_ignoreHist.end()) continue;

    if (doNorm && normScale == -999.)
      hist[iH]->Scale( 1. / std::abs(hist[iH]->Integral()) );
    else if (doNorm && normScale != -999.)
      hist[iH]->Scale( normScale );
  }

  if (yName == "") yName = "e / bin";

  if (maxAx != -1) TGaxis::SetMaxDigits(maxAx);
  else TGaxis::SetMaxDigits(5);

  axHist(hist[0], yMin, yMax, yName, 0.033, 0.87, 0.025, xName, 0.033, 0.87, 0.025);

  TLatex txt;
  txt.SetTextSize(0.035);
  txt.SetTextAlign(13);

  TLegend *aLeg;
  aLeg = new TLegend();

  std::string sLeg;
  for (int iH = 0; iH < nH; iH++) {
    sLeg = "lp";
    aLeg->AddEntry(hist[iH], (pairFileLeg[iH].second).c_str(), sLeg.c_str());
  }

  // -------------------------------------------------- //

  TCanvas *c01 = new TCanvas("c01", "c01", 200, 10, 1000, 1000);

  styleLeg(aLeg, lCol, 0, 0, 42, 0.029, lHead);
  putLeg(aLeg, 0.535, 0.955, 0.695, 0.875);

  c01->cd();
  if (drawLog) c01->SetLogy();
  for (int iH = 0; iH < nH; iH++) {
    if (iH == 0) hist[iH]->Draw("hist e2");
    else hist[iH]->Draw("hist e2 same");
  }

  aLeg->Draw();
  txt.DrawLatexNDC(0.06, 0.928, topLeft.c_str());
  txt.DrawLatexNDC(0.703, 0.933, topRight.c_str());

  // -------------------------------------------------- //

  c01->cd();
  c01->SaveAs((fName + vName + "_hist.pdf").c_str());
  c01->SaveAs((fName + vName + "_hist.C").c_str());

  c01->Close();
}



// ------- Struct for plots, bins... ------- //
struct hltLabel {
  std::string fileName;
  std::string varTitle; // what variable is being considered
  std::string xLabel; // x-axis
  std::string yLabel; // y-axis
  std::string sLabel; // ratio plot y-axis
  std::string funcTitle; // varTitle as a function of this

  // constructor
  hltLabel() : fileName(), varTitle(), xLabel(), yLabel(), sLabel(), funcTitle() {};
  hltLabel(std::string fName, std::string vTitle, std::string xLbl, std::string yLbl, std::string sLbl, std::string fTitle):
    fileName(fName), varTitle(vTitle), xLabel(xLbl), yLabel(yLbl), sLabel(sLbl), funcTitle(fTitle) {};
};

struct hltBin {
  int nBin_eb, nBin_ee;
  double min_eb, min_ee;
  double max_eb, max_ee;

  // constructor
  hltBin() : nBin_eb(1), min_eb(-999999.), max_eb(999999.), nBin_ee(1), min_ee(-999999.), max_ee(999999.) {};
  hltBin(int ebBin, double ebMin, double ebMax, int eeBin, double eeMin, double eeMax):
    nBin_eb(ebBin), min_eb(ebMin), max_eb(ebMax), nBin_ee(eeBin), min_ee(eeMin), max_ee(eeMax) {};
};

// How hard can a default lookup table be? Sheesh...
// mS for mapSingleton
struct mS{
  static const std::map<std::string, hltBin> m_hltBin() {
    std::map<std::string, hltBin> m;
    m.insert( std::make_pair( "mee", hltBin(82, 69.5, 110.5, 82, 69.5, 110.5) ));
    m.insert( std::make_pair( "eta", hltBin(54, -2.7, 2.7, 54, -2.7, 2.7) ));
    m.insert( std::make_pair( "phi", hltBin(18, -3.142, 3.142, 18, -3.142, 3.142) ));
    m.insert( std::make_pair( "eet", hltBin(80, 0., 240., 80, 0., 240.) ));

    m.insert( std::make_pair( "sie", hltBin(50, 0., 0.02, 60, 0., 0.06) ));

    m.insert( std::make_pair( "hoe", hltBin(60, 0., 30., 60, 0., 30.) ));
    m.insert( std::make_pair( "hor", hltBin(40, 0., 0.2, 40, 0., 0.2) ));

    m.insert( std::make_pair( "eca", hltBin(60, 0., 30., 60, 0., 30.) ));
    m.insert( std::make_pair( "ecr", hltBin(60, 0., 0.6, 60, 0., 0.6) ));

    m.insert( std::make_pair( "hca", hltBin(60, 0., 30., 60, 0., 30.) ));
    m.insert( std::make_pair( "hcr", hltBin(60, 0., 0.6, 60, 0., 0.6) ));

    m.insert( std::make_pair( "ps2", hltBin(100, 0., 200., 100, 0., 200.) ));

    m.insert( std::make_pair( "eop", hltBin(100, 0., 0.1, 100, 0., 0.1) ));

    m.insert( std::make_pair( "chi", hltBin(100, 0., 10., 100, 0., 10.) ));

    m.insert( std::make_pair( "mih", hltBin(4, -0.5, 3.5, 6, -0.5, 5.5) ));

    m.insert( std::make_pair( "des", hltBin(60, 0., 0.03, 60, 0., 0.03) ));

    m.insert( std::make_pair( "dph", hltBin(100, 0., 0.1, 100, 0., 0.1) ));

    m.insert( std::make_pair( "tks", hltBin(100, 0., 10., 100, 0., 10.) ));
    m.insert( std::make_pair( "tkr", hltBin(100, 0., 0.5, 100, 0., 0.5) ));

    m.insert( std::make_pair( "lol", hltBin(40, -0.2, 0.2, 40, -0.2, 0.2) ));
    return m;
  }
};
const std::map<std::string, hltBin> mBin = mS::m_hltBin();


