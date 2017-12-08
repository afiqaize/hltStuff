// A macro that takes a TH2 and saves as pdf
// Usage with args: root -l "th2Draw.cpp++("'run'", "'var'")" etc
// Shell var acceptable

#include "/home/afiqaize/Downloads/cmsTools/hltStuff/tnpMacro/hltWP.cxx"
#include "/home/afiqaize/Downloads/cmsTools/hltStuff/tnpMacro/plotStuff.cxx"
#include "/home/afiqaize/root53434/macros/tdrstyle.C"

#include "TH2.h"

void setHH2Style() {
  gStyle->SetPalette();
  gStyle->SetOptStat(0);

  TGaxis::SetMaxDigits(3);

  /*gStyle->SetPadTopMargin(0.1);
  gStyle->SetPadBottomMargin(0.15);
  gStyle->SetPadLeftMargin(-0.3);
  gStyle->SetPadRightMargin(0.1);*/
}

void th2Draw(const std::string& run = "v3_3pp", const std::string& var = "passHLT",
             const std::string& typ = "et_eta", const std::string& sam = "d") {
  setHH2Style();

  const std::string inDir = "/home/afiqaize/Downloads/EGM/dev/e_92x/perfEOY_081117/eff_2DVars/";
  TCanvas *c00 = new TCanvas("c00", "c00", 200, 10, 1000, 1000);

  std::string xTxt = "", yTxt = "", fName = "";
  if (typ == "et_eta") {
    //xTxt = "e E_{T} (GeV)";
    //yTxt = "SC #eta";
    fName = "et_eta";
  }
  if (typ == "eta_phi") {
    //xTxt = "SC #eta";
    //yTxt = "SC #phi";
    fName = "eta_phi";
  }

  TFile *inPut = TFile::Open((inDir + run + "/" +  typ + "/" + var + "/eff2D.root").c_str());

  TH2 *th2 = (TH2*) inPut->Get((sam + "2c_eff").c_str());
  axHist((TH1*) th2, th2->GetMinimum(0.), -999., yTxt, 0.037, 1.19, 0.033, xTxt, 0.037, 1.19, 0.033);
  th2->GetZaxis()->SetLabelSize(0.019);

  //gStyle->SetStatX(0.89);
  //gStyle->SetStatY(0.30);
  //gStyle->SetStatW(0.21);
  //gStyle->SetStatH(0.11);

  c00->cd();
  th2->Draw("colz");
  //c00->SaveAs( (inDir + "../plot/test/" + sam + "_" + run + "_" + var + "_" + fName + ".pdf").c_str() );
  c00->SaveAs( (inDir + "../plot/test/test1.png").c_str() );
  c00->Close();

  gROOT->ProcessLine(".q");
}
