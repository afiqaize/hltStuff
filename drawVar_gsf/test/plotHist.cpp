/*** plotHist.cpp
- grab 2 histograms from files, divide them and plot the resulting
- save in another file
- included a way to do two at once
***/

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "TFile.h"
#include "TH2.h"
#include "TH1.h"
#include "TROOT.h"
#include "TStyle.h"

using namespace std;

void plotHist() {

  gROOT->ProcessLine(".L tdrstyle.C");
  setTDRStyle();

  // names and such
  string inDir, inFile01, inFile02, inFile03, inFile04, outFile, numHist, denHist, proc;

  inDir = "/home/ieeya/Downloads/HLT_Val/Part2_OpenHLT/OpenHLT/logs/run02/ttbar_skim/e_740/turnOn_phys14/drawVar_v1/";

  // specify input and output files, 01 is numerator, 02 is denominator
  // same for 03, 04 etc

  proc = "dye";

  inFile01 = inDir + "dye_tID.root";
  inFile02 = inDir + "dye_eID.root";

  inFile03 = inDir + "wev_tID.root";
  inFile04 = inDir + "wev_eID.root";

  numHist = "drawHist/ptElectron_match";
  denHist = "drawHist/ptElectron_gsf";

  TFile *inPut01 = new TFile(inFile01.c_str());
  TFile *inPut02 = new TFile(inFile02.c_str());

  TFile *inPut03 = new TFile(inFile03.c_str());
  TFile *inPut04 = new TFile(inFile04.c_str());

  const Int_t nBin = 25; //25
  //Double_t ptBins[nBin + 1] = {0., 5., 10., 15., 20., 25., 30., 32., 34., 36., 38., 40., 42., 44., 46., 48., 50., 55., 60., 70., 80., 90., 110., 130., 150., 200.};
  Double_t ptBins[nBin + 1] = {0., 5., 10., 15., 20., 25., 30., 32., 34., 36., 38., 40., 42., 44., 46., 48., 50., 55., 60., 70., 80., 90., 110., 130., 150., 200.};
  //Double_t ptBins[nBin + 1] = {20., 25., 30., 31., 32., 33., 34., 35., 36., 37., 38., 39., 40., 41., 42., 43., 44., 45., 46., 47., 48., 49., 50., 52., 54., 56., 58., 60., 62., 64., 66., 68., 70., 75., 80., 85., 90., 95., 100., 110., 120., 130., 140., 150., 175., 200.};

  // create the histograms
  TH1::SetDefaultSumw2(true);

  TH1D *inNum01 = dynamic_cast<TH1D *>(inPut01->Get(numHist.c_str()));
  //TH1D *reNum01 = (TH1D*) inNum01->Rebin(nBin, "reNum01", ptBins);

  TH1D *inDen01 = dynamic_cast<TH1D *>(inPut02->Get(denHist.c_str()));
  //TH1D *reDen01 = (TH1D*) inDen01->Rebin(nBin, "reDen01", ptBins);

  TH1D *inNum02 = dynamic_cast<TH1D *>(inPut03->Get(numHist.c_str()));
  //TH1D *reNum02 = (TH1D*) inNum02->Rebin(nBin, "reNum02", ptBins);

  TH1D *inDen02 = dynamic_cast<TH1D *>(inPut04->Get(denHist.c_str()));
  //TH1D *reDen02 = (TH1D*) inDen01->Rebin(nBin, "reDen02", ptBins);

  Double_t yMin = 0., yMax = 1.13;

  // bins etc is still manual
  TH1D *outEff01 = new TH1D("effElectron01", "Single Electron Turn On for 32 GeV Online Cut", nBin, ptBins);
  outEff01->SetXTitle("Electron p_{T} (GeV/c)");
  outEff01->SetYTitle("Efficiency");
  outEff01->SetLineColor(kAzure - 1);
  outEff01->SetLineWidth(3);

  outEff01->Divide(inNum01, inDen01, 1., 1., "B");
  outEff01->SetMinimum(yMin);
  outEff01->SetMaximum(yMax);

  TH1D *outEff02 = new TH1D("effElectron02", "720p8 WP75 Electron eff vs p_{T}", nBin, ptBins);
  outEff02->SetXTitle("Electron p_{T} (GeV/c)");
  outEff02->SetYTitle("Efficiency");
  outEff02->SetLineColor(kRed + 1);
  outEff02->SetLineWidth(3);

  //outEff02->Divide(reNum02, reDen02, 1., 1., "B");
  outEff02->SetMinimum(yMin);
  outEff02->SetMaximum(yMax);

  TCanvas *c01 = new TCanvas("c01", "c01", 200, 10, 1000, 1000);
  c01->cd();
  c01->SetGrid();

  outEff01->Draw("CL");
  //outEff02->Draw("same");

  TLatex txt;
  txt.SetTextSize(0.03);
  txt.SetTextAlign(13);
  txt.DrawLatexNDC(0.1, 0.87, "#bf{CMS}");
  txt.DrawLatexNDC(0.1, 0.84, "#it{Simulation Preliminary}");
  txt.DrawLatexNDC(0.808, 0.927, "2015, 13 TeV");

  TLegend *leg01 = new TLegend(.76, .75, .94, .93);
  leg01->SetHeader("L1 Seed");
  leg01->AddEntry(outEff01, "L1_SingleIsoEG30er");
  leg01->AddEntry(outEff02, "L1_SingleEG30");
  //leg01->Draw();

  c01->SaveAs((inDir + proc + "_turnOn.pdf").c_str());
  c01->Close();

}
