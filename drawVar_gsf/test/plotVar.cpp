/*** plotVar.cpp
- same as plotHist but for use with the tree-based drawVar
***/

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TROOT.h"
#include "TStyle.h"

using namespace std;

void plotVar() {

  gROOT->ProcessLine(".L tdrstyle.C");
  setTDRStyle();

  // names and such
  string inDir, inFile01, inFile02, proc;

  inDir = "/home/ieeya/Downloads/HLT_Val/Part2_OpenHLT/OpenHLT/logs/run02/ttbar_skim/e_740/turnOn_phys14/";

  // specify input and output files, 01 is numerator, 02 is denominator

  proc = "tt";

  inFile01 = inDir + "out.root";
  inFile02 = inDir + "out.root";

  const Int_t nBin = 22; //25
  //Double_t ptBins[nBin + 1] = {0., 5., 10., 15., 20., 25., 30., 32., 34., 36., 38., 40., 42., 44., 46., 48., 50., 55., 60., 70., 80., 90., 110., 130., 150., 200.};
  //Double_t ptBins[nBin + 1] = {20., 25., 30., 32., 34., 36., 38., 40., 42., 44., 46., 48., 50., 55., 60., 70., 80., 90., 110., 130., 150., 200.};
  Double_t ptBins[nBin + 1] = {25., 30., 31., 32., 33., 34., 35., 36., 37.5, 40., 42.5, 45., 47.5, 50., 55., 60., 65., 75., 85., 95., 105., 125., 150.};

  // create the histograms
  TH1::SetDefaultSumw2(true);

  TH1D *inNum01 = new TH1D("inNum01", "inNum01", nBin, ptBins);
  TH1D *inDen01 = new TH1D("inDen01", "inDen01", nBin, ptBins);

  TFile *inPut01 = new TFile(inFile01.c_str());
  TFile *inPut02 = new TFile(inFile02.c_str());

  TTree *tree01 = inPut01->Get("gsfElectron");
  TTree *tree02 = inPut02->Get("gsfElectron");

  Int_t nGsf01;
  tree01->SetBranchAddress("nGsf", &nGsf01);
  Int_t nPass01;
  tree01->SetBranchAddress("nPass", &nPass01);
  Int_t nMatch01;
  tree01->SetBranchAddress("nMatch", &nMatch01);
  vector<Double_t> *ptGsf01;
  tree01->SetBranchAddress("ptGsf", &ptGsf01);
  vector<Double_t> *ptPass01;
  tree01->SetBranchAddress("ptPass", &ptPass01);
  vector<Double_t> *ptMatch01;
  tree01->SetBranchAddress("ptMatch", &ptMatch01);

  Int_t nGsf02;
  tree02->SetBranchAddress("nGsf", &nGsf02);
  Int_t nPass02;
  tree02->SetBranchAddress("nPass", &nPass02);
  Int_t nMatch02;
  tree02->SetBranchAddress("nMatch", &nMatch02);
  vector<Double_t> *ptGsf02;
  tree02->SetBranchAddress("ptGsf", &ptGsf02);
  vector<Double_t> *ptPass02;
  tree02->SetBranchAddress("ptPass", &ptPass02);
  vector<Double_t> *ptMatch02;
  tree02->SetBranchAddress("ptMatch", &ptMatch02);

  Int_t nevents01 = 0;
  nevents01 = tree01->GetEntries();

  for (Int_t nEvt01 = 0; nEvt01 < nevents01; nEvt01++) {

    tree01->GetEntry(nEvt01);

    for (Int_t nEl01 = 0; nEl01 < nMatch01; nEl01++) {

      inNum01->Fill((*ptMatch01)[nEl01]);

    }
  }

  Int_t nevents02 = 0;
  nevents02 = tree02->GetEntries();

  for (Int_t nEvt02 = 0; nEvt02 < nevents02; nEvt02++) {

    tree02->GetEntry(nEvt02);

    for (Int_t nEl02 = 0; nEl02 < nGsf02; nEl02++) {

      inDen01->Fill((*ptGsf02)[nEl02]);

    }
  }

  Double_t yMin = 0., yMax = 1.2;

  // bins etc is still manual
  TH1D *outEff01 = new TH1D("effElectron01", "Single Electron Turn On for 32 GeV Online Cut", nBin, ptBins);
  outEff01->SetXTitle("Electron p_{T} (GeV/c)");
  outEff01->SetYTitle("Efficiency");
  outEff01->SetLineColor(kAzure - 1);
  outEff01->SetLineWidth(3);

  outEff01->Divide(inNum01, inDen01, 1., 1., "B");
  outEff01->SetMinimum(yMin);
  outEff01->SetMaximum(yMax);

  TCanvas *c01 = new TCanvas("c01", "c01", 200, 10, 1600, 900);
  c01->cd();
  c01->SetGrid();

  outEff01->Draw("");

  TLatex txt;
  txt.SetTextSize(0.035);
  txt.SetTextAlign(13);
  txt.DrawLatexNDC(0.09, 0.87, "CMS Simulation Preliminary 2015");
  txt.DrawLatexNDC(0.09, 0.82, "#sqrt{s} = 13 TeV");

  c01->SaveAs((inDir + proc + "_turnOn.png").c_str());
  c01->Close();

}
