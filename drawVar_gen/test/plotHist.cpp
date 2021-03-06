/*** plotHist.cpp
- grab 2 histograms from files, divide them and plot the resulting
- save in another file
- included a way to do two at once
***/

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include <TFile.h>
#include <TH2.h>
#include <TH1.h>

using namespace std;

void plotHist() {


  // names and such
  string inDir, inFile01, inFile02, inFile03, inFile04, outFile, numHist, denHist;

  inDir = "/home/ieeya/Downloads/HLT_Val/Part2_OpenHLT/OpenHLT/logs/run02/ttbar_skim/e_72X/turnOn_720/";

  // specify input and output files, 01 is numerator, 02 is denominator
  // same for 03, 04 etc

  inFile01 = inDir + "tchan_hlt27_wp75_kin.root";
  inFile02 = inDir + "tchan_hlt27_wp75_kin.root";

  inFile03 = inDir + "tt_kelly_l130_hlt32_wp75_kin.root";
  inFile04 = inDir + "tt_kelly_kin.root";

  //outFile = inDir + "GenWev_newFin2_er_ptEff.root";

  numHist = "drawHist/ptElectron_match";
  denHist = "drawHist/ptElectron_gen";

  TFile *inPut01 = new TFile(inFile01.c_str());
  TFile *inPut02 = new TFile(inFile02.c_str());

  TFile *inPut03 = new TFile(inFile03.c_str());
  TFile *inPut04 = new TFile(inFile04.c_str());

  //TFile *outPut = new TFile(outFile.c_str(), "recreate");

  // create the histograms
  TH1::SetDefaultSumw2(true);

  TH1D *inNum01 = dynamic_cast<TH1D *>(inPut01->Get(numHist.c_str()));
  inNum01->SetNameTitle("", "");

  TH1D *inDen01 = dynamic_cast<TH1D *>(inPut02->Get(denHist.c_str()));
  inDen01->SetNameTitle("", "");

  TH1D *inNum02 = dynamic_cast<TH1D *>(inPut03->Get(numHist.c_str()));
  inNum02->SetNameTitle("", "");

  TH1D *inDen02 = dynamic_cast<TH1D *>(inPut04->Get(denHist.c_str()));
  inDen02->SetNameTitle("", "");

  Float_t ptBins[26] = {0., 5., 10., 15., 20., 25., 30., 32., 34., 36., 38., 40., 42., 44., 46., 48., 50., 55., 60., 70., 80., 90., 110., 130., 150., 200.};

  // bins etc is still manual
  TH1D *outEff01 = new TH1D("effElectron", "Ele32_eta2p1_WP75_Gsf", 25, ptBins);
  outEff01->SetXTitle("Electron GEN p_{T} (GeV/c)");
  outEff01->SetLineColor(kAzure - 1);
  outEff01->SetLineWidth(3);

  outEff01->Divide(inNum01, inDen01, 1., 1., "B");
  outEff01->SetMinimum(0.);
  outEff01->SetMaximum(1.);

  TH1D *outEff02 = new TH1D("effElectron", "720p8 WP75 Electron eff vs p_{T}", 25, ptBins);
  outEff02->SetXTitle("Electron GEN p_{T} (GeV/c)");
  outEff02->SetLineColor(kRed + 1);
  outEff02->SetLineWidth(3);

  outEff02->Divide(inNum02, inDen02, 1., 1., "B");
  outEff02->SetMinimum(0.);
  outEff02->SetMaximum(1.);

  //outPut->cd();
  //inNum->Write("", TObject::kOverwrite);
  //inDen->Write("", TObject::kOverwrite);
  //outEff->Write("", TObject::kOverwrite);
  //outPut->Close();

  TCanvas *c01 = new TCanvas("c01", "c01", 200, 10, 1600, 900);
  c01->cd();
  c01->SetGrid();

  outEff01->Draw();
  //outEff02->Draw("same");

  TLegend *leg01 = new TLegend(.76, .75, .94, .93);
  leg01->SetHeader("L1 Seed");
  leg01->AddEntry(outEff01, "L1_SingleIsoEG30er");
  leg01->AddEntry(outEff02, "L1_SingleEG30");
  //leg01->Draw();

}
