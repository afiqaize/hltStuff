// Stolen from mvaPlot in 740
// For the tnp hlt vs reco electron plotting

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
#include <TTree.h>
#include <TROOT.h>
#include <TLatex.h>
#include <TBufferFile.h>
#include <TLorentzVector.h>
#include "/home/ieeya/root/macros/tdrstyle.C"

using namespace std;

// Subprogram for the tuning
// One for each region

Bool_t barPass(Float_t sie_cut_b, Float_t hoe_cut_b, Float_t eca_cut_b, Float_t hca_cut_b, 
               Float_t eop_cut_b, Float_t chi_cut_b, Float_t mih_cut_b, 
               Float_t det_cut_b, Float_t dph_cut_b, Float_t tki_cut_b) {

  Bool_t barOk = false;

  // All barrel cuts

  if (sie_cut_b <= 1.0) {
    if (hoe_cut_b <= 999.0) {
      if (eca_cut_b <= 1.0) {
        if (hca_cut_b <= 1.0) {
          if (eop_cut_b <= 1.0) {
            if (dph_cut_b <= 1.0) {
              if (det_cut_b <= 1.0) {
                if (tki_cut_b <= 1.0) {
                  if (mih_cut_b <= 999.0) { // careful at these not 1.0 cuts
                    if (chi_cut_b <= 999.0)
                      barOk = true;

                  }
                }
              }
            }
          }
        }
      }
    }
  }

  return barOk;

}

Bool_t endPass(Float_t sie_cut_e, Float_t hoe_cut_e, Float_t eca_cut_e, Float_t hca_cut_e, 
               Float_t eop_cut_e, Float_t chi_cut_e, Float_t mih_cut_e,
               Float_t det_cut_e, Float_t dph_cut_e, Float_t tki_cut_e) {

  Bool_t endOk = false;

  // All endcap cuts

  if (sie_cut_e <= 1.0) {
    if (hoe_cut_e <= 999.0) {
      if (eca_cut_e <= 1.0) {
        if (hca_cut_e <= 1.0) {
          if (eop_cut_e <= 1.0) {
            if (dph_cut_e <= 1.0) {
              if (det_cut_e <= 1.0) {
                if (tki_cut_e <= 1.0) {
                  if (mih_cut_e <= 999.0) { // careful at these not 1.0 cuts
                    if (chi_cut_e <= 999.0)
                      endOk = true;

                  }
                }
              }
            }
          }
        }
      }
    }
  }

  return endOk;

}

// Subprogram to fill
// Play around with the arguments here
void fillHist(TH1D* varHist, Float_t varVal, Float_t eVal, Float_t etVal, Float_t weightVal) {

  // Some useless things to make ROOT shut up
  eVal = eVal;
  etVal = etVal;

  varHist->Fill(varVal, weightVal);

}

void tnpOff() {

   gROOT->Reset();

   setTDRStyle();

   // Everything to tinker with should be here
   Double_t yMin_b = .001, yMax_b = 1399.;
   Double_t yMin_e = .001, yMax_e = 299.;

   string varName[4];
   varName[0] = "lol";

   Bool_t drawLog = false;

   // -------------------------------------------------- //

   string hisLeg = "RECO", pntLeg = "HLT";

   Int_t meeb_nBin = 82, meee_nBin = 82;
   Double_t meeb_max = 110.5, meee_max = 110.5;
   Double_t meeb_min = 69.5, meee_min = 69.5;

   Int_t phib_nBin = 12, phie_nBin = 12;
   Double_t phib_max = 3.142, phie_max = 3.142;
   Double_t phib_min = -3.142, phie_min = -3.142;

   // For Et
   Int_t eetb_nBin = 120, eete_nBin = 120;
   Double_t eetb_max = 600., eete_max = 600.;
   Double_t eetb_min = 0., eete_min = 0.;

   Int_t sieb_nBin = 50, siee_nBin = 60;
   Double_t sieb_max = .02, siee_max = .06;
   Double_t sieb_min = 0., siee_min = 0.;

   // For H/E
   Int_t hoeb_nBin = 40, hoee_nBin = 60;
   Double_t hoeb_max = .2, hoee_max = .3;
   Double_t hoeb_min = 0., hoee_min = 0.;

   Int_t eccb_nBin = 60, ecce_nBin = 60;
   Double_t eccb_max = .6, ecce_max = .6;
   Double_t eccb_min = 0., ecce_min = 0.;

   Int_t hccb_nBin = 60, hcce_nBin = 60;
   Double_t hccb_max = .6, hcce_max = .6;
   Double_t hccb_min = 0., hcce_min = 0.;

   Int_t eopb_nBin = 100, eope_nBin = 100;
   Double_t eopb_max = .1, eope_max = .1;
   Double_t eopb_min = 0., eope_min = 0.;

   Int_t chib_nBin = 100, chie_nBin = 100;
   Double_t chib_max = 10., chie_max = 10.;
   Double_t chib_min = 0., chie_min = 0.;

   Int_t mihb_nBin = 4, mihe_nBin = 6;
   Double_t mihb_max = 3.5, mihe_max = 5.5;
   Double_t mihb_min = -0.5, mihe_min = -0.5;

   Int_t detb_nBin = 60, dete_nBin = 60;
   Double_t detb_max = 0.03, dete_max = 0.03;
   Double_t detb_min = 0., dete_min = 0.;

   Int_t dphb_nBin = 100, dphe_nBin = 100;
   Double_t dphb_max = 0.1, dphe_max = 0.1;
   Double_t dphb_min = 0., dphe_min = 0.;

   Int_t tkib_nBin = 100, tkie_nBin = 100;
   Double_t tkib_max = 0.5, tkie_max = 0.5;
   Double_t tkib_min = 0., tkie_min = 0.;

   // -------------------------------------------------- //

   varName[3] = "Evt / bin";

   if (varName[0] == "mee") {

     varName[1] = "Tag and Probe Mass";
     varName[2] = "m_{ee} (GeV)";

   }

   if (varName[0] == "sie") {

     varName[1] = "Cluster Shape";
     varName[2] = "#sigma_{i#etai#eta}";

   }

   if (varName[0] == "hoe") {

     varName[1] = "Hadronic / EM";
     varName[2] = "H/E";

   }

   if (varName[0] == "eca" or varName[0] == "ecc") {

     varName[1] = "Relative EcalIso";
     varName[2] = "EcalIso / p_{T}";

   }

   if (varName[0] == "hca" or varName[0] == "hcc") {

     varName[1] = "Relative HcalIso";
     varName[2] = "HcalIso / p_{T}";

   }

   if (varName[0] == "eop") {

     varName[1] = "1/E - 1/P";
     varName[2] = "1/E - 1/P (GeV^{-1})";

   }

   if (varName[0] == "mih") {

     varName[1] = "Missing Tracker Hits";
     varName[2] = "Missing Hits";

   }

   if (varName[0] == "det" or varName[0] == "des") {

     varName[1] = "Track - Supercluster #Delta#eta";
     varName[2] = "#Delta#eta";

   }

   if (varName[0] == "dph") {

     varName[1] = "Track - Supercluster #Delta#phi";
     varName[2] = "#Delta#phi";

   }

   if (varName[0] == "chi") {

     varName[1] = "Track Fit #chi^{2}";
     varName[2] = "Fit #chi^{2}";

   }

   if (varName[0] == "tki") {

     varName[1] = "Relative TrkIso";
     varName[2] = "TrkIso / p_{T}";

   }

   if (varName[0] == "lol") {

     varName[1] = "Testing";
     varName[2] = "Whatever";

   }

   // -------------------------------------------------- //

   TH1::SetDefaultSumw2(true);

   TH1D* mee_1b = new TH1D("mee_1b", (varName[1] + " Distribution").c_str(), meeb_nBin, meeb_min, meeb_max);
   TH1D* mee_1e = new TH1D("mee_1e", (varName[1] + " Distribution").c_str(), meee_nBin, meee_min, meee_max);
   mee_1b->SetMarkerColor(kRed + 1);
   mee_1b->SetMarkerStyle(20);
   mee_1b->SetMarkerSize(1);
   mee_1b->SetLineColor(kRed + 1);
   mee_1b->SetLineWidth(1.5);
   mee_1e->SetMarkerColor(kRed + 1);
   mee_1e->SetMarkerStyle(20);
   mee_1e->SetMarkerSize(1);
   mee_1e->SetLineColor(kRed + 1);
   mee_1e->SetLineWidth(1.5);

   TH1D* phi_1b = new TH1D("phi_1b", (varName[1] + " Distribution").c_str(), phib_nBin, phib_min, phib_max);
   TH1D* phi_1e = new TH1D("phi_1e", (varName[1] + " Distribution").c_str(), phie_nBin, phie_min, phie_max);
   phi_1b->SetMarkerColor(kRed + 1);
   phi_1b->SetMarkerStyle(20);
   phi_1b->SetMarkerSize(1);
   phi_1b->SetLineColor(kRed + 1);
   phi_1b->SetLineWidth(1.5);
   phi_1e->SetMarkerColor(kRed + 1);
   phi_1e->SetMarkerStyle(20);
   phi_1e->SetMarkerSize(1);
   phi_1e->SetLineColor(kRed + 1);
   phi_1e->SetLineWidth(1.5);

   TH1D* eet_1b = new TH1D("eet_1b", (varName[1] + " Distribution").c_str(), eetb_nBin, eetb_min, eetb_max);
   TH1D* eet_1e = new TH1D("eet_1e", (varName[1] + " Distribution").c_str(), eete_nBin, eete_min, eete_max);
   eet_1b->SetMarkerColor(kRed + 1);
   eet_1b->SetMarkerStyle(20);
   eet_1b->SetMarkerSize(1);
   eet_1b->SetLineColor(kRed + 1);
   eet_1b->SetLineWidth(1.5);
   eet_1e->SetMarkerColor(kRed + 1);
   eet_1e->SetMarkerStyle(20);
   eet_1e->SetMarkerSize(1);
   eet_1e->SetLineColor(kRed + 1);
   eet_1e->SetLineWidth(1.5);

   TH1D* sie_1b = new TH1D("sie_1b", (varName[1] + " Distribution").c_str(), sieb_nBin, sieb_min, sieb_max);
   TH1D* sie_1e = new TH1D("sie_1e", (varName[1] + " Distribution").c_str(), siee_nBin, siee_min, siee_max);
   sie_1b->SetMarkerColor(kRed + 1);
   sie_1b->SetMarkerStyle(20);
   sie_1b->SetMarkerSize(1);
   sie_1b->SetLineColor(kRed + 1);
   sie_1b->SetLineWidth(1.5);
   sie_1e->SetMarkerColor(kRed + 1);
   sie_1e->SetMarkerStyle(20);
   sie_1e->SetMarkerSize(1);
   sie_1e->SetLineColor(kRed + 1);
   sie_1e->SetLineWidth(1.5);

   TH1D* hoe_1b = new TH1D("hoe_1b", (varName[1] + " Distribution").c_str(), hoeb_nBin, hoeb_min, hoeb_max);
   TH1D* hoe_1e = new TH1D("hoe_1e", (varName[1] + " Distribution").c_str(), hoee_nBin, hoee_min, hoee_max);
   hoe_1b->SetMarkerColor(kRed + 1);
   hoe_1b->SetMarkerStyle(20);
   hoe_1b->SetMarkerSize(1);
   hoe_1b->SetLineColor(kRed + 1);
   hoe_1b->SetLineWidth(1.5);
   hoe_1e->SetMarkerColor(kRed + 1);
   hoe_1e->SetMarkerStyle(20);
   hoe_1e->SetMarkerSize(1);
   hoe_1e->SetLineColor(kRed + 1);
   hoe_1e->SetLineWidth(1.5);

   TH1D* ecc_1b = new TH1D("ecc_1b", (varName[1] + " Distribution").c_str(), eccb_nBin, eccb_min, eccb_max);
   TH1D* ecc_1e = new TH1D("ecc_1e", (varName[1] + " Distribution").c_str(), ecce_nBin, ecce_min, ecce_max);
   ecc_1b->SetMarkerColor(kRed + 1);
   ecc_1b->SetMarkerStyle(20);
   ecc_1b->SetMarkerSize(1);
   ecc_1b->SetLineColor(kRed + 1);
   ecc_1b->SetLineWidth(1.5);
   ecc_1e->SetMarkerColor(kRed + 1);
   ecc_1e->SetMarkerStyle(20);
   ecc_1e->SetMarkerSize(1);
   ecc_1e->SetLineColor(kRed + 1);
   ecc_1e->SetLineWidth(1.5);

   TH1D* hcc_1b = new TH1D("hcc_1b", (varName[1] + " Distribution").c_str(), hccb_nBin, hccb_min, hccb_max);
   TH1D* hcc_1e = new TH1D("hcc_1e", (varName[1] + " Distribution").c_str(), hcce_nBin, hcce_min, hcce_max);
   hcc_1b->SetMarkerColor(kRed + 1);
   hcc_1b->SetMarkerStyle(20);
   hcc_1b->SetMarkerSize(1);
   hcc_1b->SetLineColor(kRed + 1);
   hcc_1b->SetLineWidth(1.5);
   hcc_1e->SetMarkerColor(kRed + 1);
   hcc_1e->SetMarkerStyle(20);
   hcc_1e->SetMarkerSize(1);
   hcc_1e->SetLineColor(kRed + 1);
   hcc_1e->SetLineWidth(1.5);

   TH1D* eop_1b = new TH1D("eop_1b", (varName[1] + " Distribution").c_str(), eopb_nBin, eopb_min, eopb_max);
   TH1D* eop_1e = new TH1D("eop_1e", (varName[1] + " Distribution").c_str(), eope_nBin, eope_min, eope_max);
   eop_1b->SetMarkerColor(kRed + 1);
   eop_1b->SetMarkerStyle(20);
   eop_1b->SetMarkerSize(1);
   eop_1b->SetLineColor(kRed + 1);
   eop_1b->SetLineWidth(1.5);
   eop_1b->Sumw2();
   eop_1e->SetMarkerColor(kRed + 1);
   eop_1e->SetMarkerStyle(20);
   eop_1e->SetMarkerSize(1);
   eop_1e->SetLineColor(kRed + 1);
   eop_1e->SetLineWidth(1.5);
   eop_1e->Sumw2();

   TH1D* chi_1b = new TH1D("chi_1b", (varName[1] + " Distribution").c_str(), chib_nBin, chib_min, chib_max);
   TH1D* chi_1e = new TH1D("chi_1e", (varName[1] + " Distribution").c_str(), chie_nBin, chie_min, chie_max);
   chi_1b->SetMarkerColor(kRed + 1);
   chi_1b->SetMarkerStyle(20);
   chi_1b->SetMarkerSize(1);
   chi_1b->SetLineColor(kRed + 1);
   chi_1b->SetLineWidth(1.5);
   chi_1e->SetMarkerColor(kRed + 1);
   chi_1e->SetMarkerStyle(20);
   chi_1e->SetMarkerSize(1);
   chi_1e->SetLineColor(kRed + 1);
   chi_1e->SetLineWidth(1.5);

   TH1D* mih_1b = new TH1D("mih_1b", (varName[1] + " Distribution").c_str(), mihb_nBin, mihb_min, mihb_max);
   TH1D* mih_1e = new TH1D("mih_1e", (varName[1] + " Distribution").c_str(), mihe_nBin, mihe_min, mihe_max);
   mih_1b->SetMarkerColor(kRed + 1);
   mih_1b->SetMarkerStyle(20);
   mih_1b->SetMarkerSize(1);
   mih_1b->SetLineColor(kRed + 1);
   mih_1b->SetLineWidth(1.5);
   mih_1e->SetMarkerColor(kRed + 1);
   mih_1e->SetMarkerStyle(20);
   mih_1e->SetMarkerSize(1);
   mih_1e->SetLineColor(kRed + 1);
   mih_1e->SetLineWidth(1.5);

   TH1D* det_1b = new TH1D("det_1b", (varName[1] + " Distribution").c_str(), detb_nBin, detb_min, detb_max);
   TH1D* det_1e = new TH1D("det_1e", (varName[1] + " Distribution").c_str(), dete_nBin, dete_min, dete_max);
   det_1b->SetMarkerColor(kRed + 1);
   det_1b->SetMarkerStyle(20);
   det_1b->SetMarkerSize(1);
   det_1b->SetLineColor(kRed + 1);
   det_1b->SetLineWidth(1.5);
   det_1e->SetMarkerColor(kRed + 1);
   det_1e->SetMarkerStyle(20);
   det_1e->SetMarkerSize(1);
   det_1e->SetLineColor(kRed + 1);
   det_1e->SetLineWidth(1.5);

   TH1D* dph_1b = new TH1D("dph_1b", (varName[1] + " Distribution").c_str(), dphb_nBin, dphb_min, dphb_max);
   TH1D* dph_1e = new TH1D("dph_1e", (varName[1] + " Distribution").c_str(), dphe_nBin, dphe_min, dphe_max);
   dph_1b->SetMarkerColor(kRed + 1);
   dph_1b->SetMarkerStyle(20);
   dph_1b->SetMarkerSize(1);
   dph_1b->SetLineColor(kRed + 1);
   dph_1b->SetLineWidth(1.5);
   dph_1e->SetMarkerColor(kRed + 1);
   dph_1e->SetMarkerStyle(20);
   dph_1e->SetMarkerSize(1);
   dph_1e->SetLineColor(kRed + 1);
   dph_1e->SetLineWidth(1.5);

   TH1D* tki_1b = new TH1D("tki_1b", (varName[1] + " Distribution").c_str(), tkib_nBin, tkib_min, tkib_max);
   TH1D* tki_1e = new TH1D("tki_1e", (varName[1] + " Distribution").c_str(), tkie_nBin, tkie_min, tkie_max);
   tki_1b->SetMarkerColor(kRed + 1);
   tki_1b->SetMarkerStyle(20);
   tki_1b->SetMarkerSize(1);
   tki_1b->SetLineColor(kRed + 1);
   tki_1b->SetLineWidth(1.5);
   tki_1e->SetMarkerColor(kRed + 1);
   tki_1e->SetMarkerStyle(20);
   tki_1e->SetMarkerSize(1);
   tki_1e->SetLineColor(kRed + 1);
   tki_1e->SetLineWidth(1.5);

   // -------------------------------------------------- //

   TH1D* mee_2b = new TH1D("mee_2b", (varName[1] + " Distribution").c_str(), meeb_nBin, meeb_min, meeb_max);
   TH1D* mee_2e = new TH1D("mee_2e", (varName[1] + " Distribution").c_str(), meee_nBin, meee_min, meee_max);
   mee_2b->SetFillColor(kAzure + 1);
   mee_2b->SetMarkerColor(kAzure + 1);
   mee_2b->SetMarkerStyle(2);
   mee_2b->SetMarkerSize(1);
   mee_2b->SetLineColor(kAzure + 1);
   mee_2b->SetLineWidth(1.5);
   mee_2e->SetFillColor(kAzure + 1);
   mee_2e->SetMarkerColor(kAzure + 1);
   mee_2e->SetMarkerStyle(2);
   mee_2e->SetMarkerSize(1);
   mee_2e->SetLineColor(kAzure + 1);
   mee_2e->SetLineWidth(1.5);

   TH1D* phi_2b = new TH1D("phi_2b", (varName[1] + " Distribution").c_str(), phib_nBin, phib_min, phib_max);
   TH1D* phi_2e = new TH1D("phi_2e", (varName[1] + " Distribution").c_str(), phie_nBin, phie_min, phie_max);
   phi_2b->SetFillColor(kAzure + 1);
   phi_2b->SetMarkerColor(kAzure + 1);
   phi_2b->SetMarkerStyle(2);
   phi_2b->SetMarkerSize(1);
   phi_2b->SetLineColor(kAzure + 1);
   phi_2b->SetLineWidth(1.5);
   phi_2e->SetFillColor(kAzure + 1);
   phi_2e->SetMarkerColor(kAzure + 1);
   phi_2e->SetMarkerStyle(2);
   phi_2e->SetMarkerSize(1);
   phi_2e->SetLineColor(kAzure + 1);
   phi_2e->SetLineWidth(1.5);

   TH1D* eet_2b = new TH1D("eet_2b", (varName[1] + " Distribution").c_str(), eetb_nBin, eetb_min, eetb_max);
   TH1D* eet_2e = new TH1D("eet_2e", (varName[1] + " Distribution").c_str(), eete_nBin, eete_min, eete_max);
   eet_2b->SetFillColor(kAzure + 1);
   eet_2b->SetMarkerColor(kAzure + 1);
   eet_2b->SetMarkerStyle(2);
   eet_2b->SetMarkerSize(1);
   eet_2b->SetLineColor(kAzure + 1);
   eet_2b->SetLineWidth(1.5);
   eet_2e->SetFillColor(kAzure + 1);
   eet_2e->SetMarkerColor(kAzure + 1);
   eet_2e->SetMarkerStyle(2);
   eet_2e->SetMarkerSize(1);
   eet_2e->SetLineColor(kAzure + 1);
   eet_2e->SetLineWidth(1.5);

   TH1D* sie_2b = new TH1D("sie_2b", (varName[1] + " Distribution").c_str(), sieb_nBin, sieb_min, sieb_max);
   TH1D* sie_2e = new TH1D("sie_2e", (varName[1] + " Distribution").c_str(), siee_nBin, siee_min, siee_max);
   sie_2b->SetFillColor(kAzure + 1);
   sie_2b->SetMarkerColor(kAzure + 1);
   sie_2b->SetMarkerStyle(2);
   sie_2b->SetMarkerSize(1);
   sie_2b->SetLineColor(kAzure + 1);
   sie_2b->SetLineWidth(1.5);
   sie_2e->SetFillColor(kAzure + 1);
   sie_2e->SetMarkerColor(kAzure + 1);
   sie_2e->SetMarkerStyle(2);
   sie_2e->SetMarkerSize(1);
   sie_2e->SetLineColor(kAzure + 1);
   sie_2e->SetLineWidth(1.5);

   TH1D* hoe_2b = new TH1D("hoe_2b", (varName[1] + " Distribution").c_str(), hoeb_nBin, hoeb_min, hoeb_max);
   TH1D* hoe_2e = new TH1D("hoe_2e", (varName[1] + " Distribution").c_str(), hoee_nBin, hoee_min, hoee_max);
   hoe_2b->SetFillColor(kAzure + 1);
   hoe_2b->SetMarkerColor(kAzure + 1);
   hoe_2b->SetMarkerStyle(2);
   hoe_2b->SetMarkerSize(1);
   hoe_2b->SetLineColor(kAzure + 1);
   hoe_2b->SetLineWidth(1.5);
   hoe_2e->SetFillColor(kAzure + 1);
   hoe_2e->SetMarkerColor(kAzure + 1);
   hoe_2e->SetMarkerStyle(2);
   hoe_2e->SetMarkerSize(1);
   hoe_2e->SetLineColor(kAzure + 1);
   hoe_2e->SetLineWidth(1.5);

   TH1D* ecc_2b = new TH1D("ecc_2b", (varName[1] + " Distribution").c_str(), eccb_nBin, eccb_min, eccb_max);
   TH1D* ecc_2e = new TH1D("ecc_2e", (varName[1] + " Distribution").c_str(), ecce_nBin, ecce_min, ecce_max);
   ecc_2b->SetFillColor(kAzure + 1);
   ecc_2b->SetMarkerColor(kAzure + 1);
   ecc_2b->SetMarkerStyle(2);
   ecc_2b->SetMarkerSize(1);
   ecc_2b->SetLineColor(kAzure + 1);
   ecc_2b->SetLineWidth(1.5);
   ecc_2e->SetFillColor(kAzure + 1);
   ecc_2e->SetMarkerColor(kAzure + 1);
   ecc_2e->SetMarkerStyle(2);
   ecc_2e->SetMarkerSize(1);
   ecc_2e->SetLineColor(kAzure + 1);
   ecc_2e->SetLineWidth(1.5);

   TH1D* hcc_2b = new TH1D("hcc_2b", (varName[1] + " Distribution").c_str(), hccb_nBin, hccb_min, hccb_max);
   TH1D* hcc_2e = new TH1D("hcc_2e", (varName[1] + " Distribution").c_str(), hcce_nBin, hcce_min, hcce_max);
   hcc_2b->SetFillColor(kAzure + 1);
   hcc_2b->SetMarkerColor(kAzure + 1);
   hcc_2b->SetMarkerStyle(2);
   hcc_2b->SetMarkerSize(1);
   hcc_2b->SetLineColor(kAzure + 1);
   hcc_2b->SetLineWidth(1.5);
   hcc_2e->SetFillColor(kAzure + 1);
   hcc_2e->SetMarkerColor(kAzure + 1);
   hcc_2e->SetMarkerStyle(2);
   hcc_2e->SetMarkerSize(1);
   hcc_2e->SetLineColor(kAzure + 1);
   hcc_2e->SetLineWidth(1.5);

   TH1D* eop_2b = new TH1D("eop_2b", (varName[1] + " Distribution").c_str(), eopb_nBin, eopb_min, eopb_max);
   TH1D* eop_2e = new TH1D("eop_2e", (varName[1] + " Distribution").c_str(), eope_nBin, eope_min, eope_max);
   eop_2b->SetFillColor(kAzure + 1);
   eop_2b->SetMarkerColor(kAzure + 1);
   eop_2b->SetMarkerStyle(2);
   eop_2b->SetMarkerSize(1);
   eop_2b->SetLineColor(kAzure + 1);
   eop_2b->SetLineWidth(1.5);
   eop_2e->SetFillColor(kAzure + 1);
   eop_2e->SetMarkerColor(kAzure + 1);
   eop_2e->SetMarkerStyle(2);
   eop_2e->SetMarkerSize(1);
   eop_2e->SetLineColor(kAzure + 1);
   eop_2e->SetLineWidth(1.5);

   TH1D* chi_2b = new TH1D("chi_2b", (varName[1] + " Distribution").c_str(), chib_nBin, chib_min, chib_max);
   TH1D* chi_2e = new TH1D("chi_2e", (varName[1] + " Distribution").c_str(), chie_nBin, chie_min, chie_max);
   chi_2b->SetFillColor(kAzure + 1);
   chi_2b->SetMarkerColor(kAzure + 1);
   chi_2b->SetMarkerStyle(2);
   chi_2b->SetMarkerSize(1);
   chi_2b->SetLineColor(kAzure + 1);
   chi_2b->SetLineWidth(1.5);
   chi_2e->SetFillColor(kAzure + 1);
   chi_2e->SetMarkerColor(kAzure + 1);
   chi_2e->SetMarkerStyle(2);
   chi_2e->SetMarkerSize(1);
   chi_2e->SetLineColor(kAzure + 1);
   chi_2e->SetLineWidth(1.5);

   TH1D* mih_2b = new TH1D("mih_2b", (varName[1] + " Distribution").c_str(), mihb_nBin, mihb_min, mihb_max);
   TH1D* mih_2e = new TH1D("mih_2e", (varName[1] + " Distribution").c_str(), mihe_nBin, mihe_min, mihe_max);
   mih_2b->SetFillColor(kAzure + 1);
   mih_2b->SetMarkerColor(kAzure + 1);
   mih_2b->SetMarkerStyle(2);
   mih_2b->SetMarkerSize(1);
   mih_2b->SetLineColor(kAzure + 1);
   mih_2b->SetLineWidth(1.5);
   mih_2e->SetFillColor(kAzure + 1);
   mih_2e->SetMarkerColor(kAzure + 1);
   mih_2e->SetMarkerStyle(2);
   mih_2e->SetMarkerSize(1);
   mih_2e->SetLineColor(kAzure + 1);
   mih_2e->SetLineWidth(1.5);

   TH1D* det_2b = new TH1D("det_2b", (varName[1] + " Distribution").c_str(), detb_nBin, detb_min, detb_max);
   TH1D* det_2e = new TH1D("det_2e", (varName[1] + " Distribution").c_str(), dete_nBin, dete_min, dete_max);
   det_2b->SetFillColor(kAzure + 1);
   det_2b->SetMarkerColor(kAzure + 1);
   det_2b->SetMarkerStyle(2);
   det_2b->SetMarkerSize(1);
   det_2b->SetLineColor(kAzure + 1);
   det_2b->SetLineWidth(1.5);
   det_2e->SetFillColor(kAzure + 1);
   det_2e->SetMarkerColor(kAzure + 1);
   det_2e->SetMarkerStyle(2);
   det_2e->SetMarkerSize(1);
   det_2e->SetLineColor(kAzure + 1);
   det_2e->SetLineWidth(1.5);

   TH1D* dph_2b = new TH1D("dph_2b", (varName[1] + " Distribution").c_str(), dphb_nBin, dphb_min, dphb_max);
   TH1D* dph_2e = new TH1D("dph_2e", (varName[1] + " Distribution").c_str(), dphe_nBin, dphe_min, dphe_max);
   dph_2b->SetFillColor(kAzure + 1);
   dph_2b->SetMarkerColor(kAzure + 1);
   dph_2b->SetMarkerStyle(2);
   dph_2b->SetMarkerSize(1);
   dph_2b->SetLineColor(kAzure + 1);
   dph_2b->SetLineWidth(1.5);
   dph_2e->SetFillColor(kAzure + 1);
   dph_2e->SetMarkerColor(kAzure + 1);
   dph_2e->SetMarkerStyle(2);
   dph_2e->SetMarkerSize(1);
   dph_2e->SetLineColor(kAzure + 1);
   dph_2e->SetLineWidth(1.5);

   TH1D* tki_2b = new TH1D("tki_2b", (varName[1] + " Distribution").c_str(), tkib_nBin, tkib_min, tkib_max);
   TH1D* tki_2e = new TH1D("tki_2e", (varName[1] + " Distribution").c_str(), tkie_nBin, tkie_min, tkie_max);
   tki_2b->SetFillColor(kAzure + 1);
   tki_2b->SetMarkerColor(kAzure + 1);
   tki_2b->SetMarkerStyle(2);
   tki_2b->SetMarkerSize(1);
   tki_2b->SetLineColor(kAzure + 1);
   tki_2b->SetLineWidth(1.5);
   tki_2e->SetFillColor(kAzure + 1);
   tki_2e->SetMarkerColor(kAzure + 1);
   tki_2e->SetMarkerStyle(2);
   tki_2e->SetMarkerSize(1);
   tki_2e->SetLineColor(kAzure + 1);
   tki_2e->SetLineWidth(1.5);

   // -------------------------------------------------- //

   string const inDir = "/home/ieeya/Downloads/HLT_Val/dev/e_74x/file/v8p1/";

   TFile *f1 = new TFile((inDir + "distWigt.root").c_str());
   TTree *t1 = (TTree *) f1->Get("eleDistr");

   Int_t type;
   t1->SetBranchAddress("itype", &type);
   Float_t weight;
   t1->SetBranchAddress("weight", &weight);
   //Float_t puWgt;
   //t1->SetBranchAddress("puWgt", &puWgt);

   Int_t pass[10];
   t1->SetBranchAddress("pass_hlt", pass);
   Int_t hlt_n;
   t1->SetBranchAddress("hlt_n", &hlt_n);
   Float_t hlt_et[10];
   t1->SetBranchAddress("hlt_et", hlt_et);
   Float_t hlt_e[10];
   t1->SetBranchAddress("hlt_e", hlt_e);
   Float_t hlt_eta[10];
   t1->SetBranchAddress("hlt_eta", hlt_eta);
   Float_t hlt_phi[10];
   t1->SetBranchAddress("hlt_phi", hlt_phi);
   Float_t hlt_sie[10];
   t1->SetBranchAddress("hlt_sie", hlt_sie);
   Float_t hlt_hoe[10];
   t1->SetBranchAddress("hlt_hoe", hlt_hoe);
   Float_t hlt_eca[10];
   t1->SetBranchAddress("hlt_eca", hlt_eca);
   Float_t hlt_ecc[10];
   t1->SetBranchAddress("hlt_ecc", hlt_ecc);
   Float_t hlt_hca[10];
   t1->SetBranchAddress("hlt_hca", hlt_hca);
   Float_t hlt_hcc[10];
   t1->SetBranchAddress("hlt_hcc", hlt_hcc);
   Float_t hlt_eop[10];
   t1->SetBranchAddress("hlt_eop", hlt_eop);
   Float_t hlt_chi[10];
   t1->SetBranchAddress("hlt_chi", hlt_chi);
   Float_t hlt_mih[10];
   t1->SetBranchAddress("hlt_mih", hlt_mih);
   Float_t hlt_det[10];
   t1->SetBranchAddress("hlt_det", hlt_det);
   //Float_t hlt_des[10];
   //t1->SetBranchAddress("hlt_des", hlt_des);
   Float_t hlt_dph[10];
   t1->SetBranchAddress("hlt_dph", hlt_dph);
   Float_t hlt_tki[10];
   t1->SetBranchAddress("hlt_tki", hlt_tki);

   Int_t reco_n;
   t1->SetBranchAddress("reco_n", &reco_n);
   Float_t reco_et[10];
   t1->SetBranchAddress("reco_et", reco_et);
   Float_t reco_e[10];
   t1->SetBranchAddress("reco_e", reco_e);
   Float_t reco_pt[10];
   t1->SetBranchAddress("reco_pt", reco_pt);
   Float_t reco_eta[10];
   t1->SetBranchAddress("reco_eta", reco_eta);
   Float_t reco_phi[10];
   t1->SetBranchAddress("reco_phi", reco_phi);
   Float_t reco_sie[10];
   t1->SetBranchAddress("reco_sie", reco_sie);
   Float_t reco_hoe[10];
   t1->SetBranchAddress("reco_hoe", reco_hoe);
   Float_t reco_eca[10];
   t1->SetBranchAddress("reco_eca", reco_eca);
   Float_t reco_hca[10];
   t1->SetBranchAddress("reco_hca", reco_hca);
   Float_t reco_eop[10];
   t1->SetBranchAddress("reco_eop", reco_eop);
   Float_t reco_chi[10];
   t1->SetBranchAddress("reco_chi", reco_chi);
   Float_t reco_mih[10];
   t1->SetBranchAddress("reco_mih", reco_mih);
   Float_t reco_det[10];
   t1->SetBranchAddress("reco_det", reco_det);
   //Float_t reco_des[10];
   //t1->SetBranchAddress("reco_des", reco_des);
   Float_t reco_dph[10];
   t1->SetBranchAddress("reco_dph", reco_dph);
   Float_t reco_tki[10];
   t1->SetBranchAddress("reco_tki", reco_tki);

   // -------------------------------------------------- //

   TLorentzVector p4hTag, p4rTag, p4hProbe, p4rProbe;

   Int_t nEvt1 = t1->GetEntries();
   cout << "nEvt1 = " << nEvt1 << endl;

   for (Int_t evt1 = 0; evt1 < nEvt1; evt1++) {

     t1->GetEntry(evt1);

     for (Int_t hltTag = 0; hltTag < hlt_n; hltTag++) {

       if (pass[hltTag] != 1) continue;

       p4hTag.SetPtEtaPhiE(hlt_et[hltTag], hlt_eta[hltTag], hlt_phi[hltTag], hlt_e[hltTag]);

       Int_t recoTag = -1;
       for (Int_t aa = 0; aa < reco_n; aa++) {

         p4rTag.SetPtEtaPhiE(reco_et[aa], reco_eta[aa], reco_phi[aa], reco_e[aa]);

         if (p4hTag.DeltaR(p4rTag) < 0.2) {

           recoTag = aa;
           break;

         }
       }

       if (recoTag == -1) continue;
       if (reco_et[recoTag] < 30. or fabs(reco_eta[recoTag]) > 2.1) continue;

       for (Int_t hltProbe = 0; hltProbe < hlt_n; hltProbe++) {

         if (hltProbe == hltTag) continue;

         p4hProbe.SetPtEtaPhiE(hlt_et[hltProbe], hlt_eta[hltProbe], hlt_phi[hltProbe], hlt_e[hltProbe]);

         Int_t recoProbe = -1;
         for (Int_t bb = 0; bb < reco_n; bb++) {

           p4rProbe.SetPtEtaPhiE(reco_et[bb], reco_eta[bb], reco_phi[bb], reco_e[bb]);

           if (p4hProbe.DeltaR(p4rProbe) < 0.2) {

             recoProbe = bb;
             break;

           }
         }

         if (recoProbe == -1 or recoProbe == recoTag) continue;
         if (reco_et[recoProbe] < 20.) continue;

         if ((p4rTag + p4rProbe).M() < 70. or (p4rTag + p4rProbe).M() > 110.) continue;

         if (fabs(reco_eta[recoProbe]) < 1.4791) {

           if(!barPass(hlt_sie[hltProbe], hlt_hoe[hltProbe], hlt_ecc[hltProbe],
                       hlt_hcc[hltProbe], hlt_eop[hltProbe], hlt_chi[hltProbe],
                       hlt_mih[hltProbe], hlt_det[hltProbe], hlt_dph[hltProbe],
                       hlt_tki[hltProbe])) continue;

           fillHist(sie_1b, hlt_sie[hltProbe], hlt_e[hltProbe], hlt_et[hltProbe], 1.);
           fillHist(hoe_1b, hlt_hoe[hltProbe], hlt_e[hltProbe], hlt_et[hltProbe], 1.);
           fillHist(ecc_1b, hlt_eca[hltProbe], hlt_e[hltProbe], hlt_et[hltProbe], 1.);
           fillHist(hcc_1b, hlt_hca[hltProbe], hlt_e[hltProbe], hlt_et[hltProbe], 1.);
           fillHist(eop_1b, hlt_eop[hltProbe], hlt_e[hltProbe], hlt_et[hltProbe], 1.);
           fillHist(chi_1b, hlt_chi[hltProbe], hlt_e[hltProbe], hlt_et[hltProbe], 1.);
           fillHist(mih_1b, hlt_mih[hltProbe], hlt_e[hltProbe], hlt_et[hltProbe], 1.);
           fillHist(det_1b, hlt_det[hltProbe], hlt_e[hltProbe], hlt_et[hltProbe], 1.);
           fillHist(dph_1b, hlt_dph[hltProbe], hlt_e[hltProbe], hlt_et[hltProbe], 1.);
           fillHist(tki_1b, hlt_tki[hltProbe], hlt_e[hltProbe], hlt_et[hltProbe], 1.);

           fillHist(sie_2b, reco_sie[recoProbe], reco_e[recoProbe], reco_et[recoProbe], 1.);
           fillHist(hoe_2b, reco_hoe[recoProbe], reco_e[recoProbe], reco_et[recoProbe], 1.);
           fillHist(ecc_2b, reco_eca[recoProbe], reco_e[recoProbe], reco_et[recoProbe], 1.);
           fillHist(hcc_2b, reco_hca[recoProbe], reco_e[recoProbe], reco_et[recoProbe], 1.);
           fillHist(eop_2b, reco_eop[recoProbe], reco_e[recoProbe], reco_et[recoProbe], 1.);
           fillHist(chi_2b, reco_chi[recoProbe], reco_e[recoProbe], reco_et[recoProbe], 1.);
           fillHist(mih_2b, reco_mih[recoProbe], reco_e[recoProbe], reco_et[recoProbe], 1.);
           fillHist(det_2b, reco_det[recoProbe], reco_e[recoProbe], reco_et[recoProbe], 1.);
           fillHist(dph_2b, reco_dph[recoProbe], reco_e[recoProbe], reco_et[recoProbe], 1.);
           fillHist(tki_2b, reco_tki[recoProbe], reco_e[recoProbe], reco_et[recoProbe], 1.);

         }

         if (fabs(reco_eta[recoProbe]) >= 1.4791) {

           if(!endPass(hlt_sie[hltProbe], hlt_hoe[hltProbe], hlt_ecc[hltProbe],
                       hlt_hcc[hltProbe], hlt_eop[hltProbe], hlt_chi[hltProbe],
                       hlt_mih[hltProbe], hlt_det[hltProbe], hlt_dph[hltProbe],
                       hlt_tki[hltProbe])) continue;

           fillHist(sie_1e, hlt_sie[hltProbe], hlt_e[hltProbe], hlt_et[hltProbe], 1.);
           fillHist(hoe_1e, hlt_hoe[hltProbe], hlt_e[hltProbe], hlt_et[hltProbe], 1.);
           fillHist(ecc_1e, hlt_eca[hltProbe], hlt_e[hltProbe], hlt_et[hltProbe], 1.);
           fillHist(hcc_1e, hlt_hca[hltProbe], hlt_e[hltProbe], hlt_et[hltProbe], 1.);
           fillHist(eop_1e, hlt_eop[hltProbe], hlt_e[hltProbe], hlt_et[hltProbe], 1.);
           fillHist(chi_1e, hlt_chi[hltProbe], hlt_e[hltProbe], hlt_et[hltProbe], 1.);
           fillHist(mih_1e, hlt_mih[hltProbe], hlt_e[hltProbe], hlt_et[hltProbe], 1.);
           fillHist(det_1e, hlt_det[hltProbe], hlt_e[hltProbe], hlt_et[hltProbe], 1.);
           fillHist(dph_1e, hlt_dph[hltProbe], hlt_e[hltProbe], hlt_et[hltProbe], 1.);
           fillHist(tki_1e, hlt_tki[hltProbe], hlt_e[hltProbe], hlt_et[hltProbe], 1.);

           fillHist(sie_2e, reco_sie[recoProbe], reco_e[recoProbe], reco_et[recoProbe], 1.);
           fillHist(hoe_2e, reco_hoe[recoProbe], reco_e[recoProbe], reco_et[recoProbe], 1.);
           fillHist(ecc_2e, reco_eca[recoProbe], reco_e[recoProbe], reco_et[recoProbe], 1.);
           fillHist(hcc_2e, reco_hca[recoProbe], reco_e[recoProbe], reco_et[recoProbe], 1.);
           fillHist(eop_2e, reco_eop[recoProbe], reco_e[recoProbe], reco_et[recoProbe], 1.);
           fillHist(chi_2e, reco_chi[recoProbe], reco_e[recoProbe], reco_et[recoProbe], 1.);
           fillHist(mih_2e, reco_mih[recoProbe], reco_e[recoProbe], reco_et[recoProbe], 1.);
           fillHist(det_2e, reco_det[recoProbe], reco_e[recoProbe], reco_et[recoProbe], 1.);
           fillHist(dph_2e, reco_dph[recoProbe], reco_e[recoProbe], reco_et[recoProbe], 1.);
           fillHist(tki_2e, reco_tki[recoProbe], reco_e[recoProbe], reco_et[recoProbe], 1.);

         }

         if (reco_eta[recoTag] < 1.4791 and reco_eta[recoProbe] < 1.4791) {

           fillHist(mee_1b, (p4hTag + p4hProbe).M(), hlt_e[hltProbe], hlt_et[hltProbe], 1.);
           fillHist(mee_2b, (p4rTag + p4rProbe).M(), reco_e[recoProbe], reco_et[recoProbe], 1.);

         }

         else {

           fillHist(mee_1e, (p4hTag + p4hProbe).M(), hlt_e[hltProbe], hlt_et[hltProbe], 1.);
           fillHist(mee_2e, (p4rTag + p4rProbe).M(), reco_e[recoProbe], reco_et[recoProbe], 1.);

         }
       }
     }
   }

   //cout << det_1b->GetEntries() << " " << det_2b->GetEntries() << endl;
   //cout << det_1e->GetEntries() << " " << det_2e->GetEntries() << endl;

   // -------------------------------------------------- //

   static const Int_t nStep_b = meeb_nBin + 1, nStep_e = meee_nBin + 1;
   Double_t sStep_b = (meeb_max - meeb_min) / meeb_nBin, sStep_e = (meee_max - meee_min) / meee_nBin;

   Float_t l1b[nStep_b], eff_xb[nStep_b];
   Float_t l1e[nStep_e], eff_xe[nStep_e];

   for (Int_t bb = 0; bb < nStep_b; bb++) {

     l1b[bb] = 1.;
     eff_xb[bb] = (bb * sStep_b) + meeb_min;

   }

   for (Int_t ee = 0; ee < nStep_e; ee++) {

     l1e[ee] = 1.;
     eff_xe[ee] = (ee * sStep_e) + meee_min;

   }

   TGraph *lineb = new TGraph(meeb_nBin + 1, eff_xb, l1b);
   lineb->SetLineColor(kYellow + 1);
   lineb->SetLineWidth(2);

   TGraph *linee = new TGraph(meee_nBin + 1, eff_xe, l1e);
   linee->SetLineColor(kYellow + 1);
   linee->SetLineWidth(2);

   TH1D *sfb = new TH1D("", "", meeb_nBin, meeb_min, meeb_max);
   sfb->Divide(mee_1b, mee_2b, 1., 1., "B");
   sfb->SetMarkerStyle(2);
   sfb->SetMarkerSize(1);
   sfb->SetMarkerColor(kBlack);
   sfb->SetLineColor(kBlack);
   sfb->SetLineWidth(1);
   sfb->SetAxisRange(0.01, 1.99, "y");
   sfb->SetTitle("");

   sfb->GetYaxis()->SetTitle("HLT / RECO");
   sfb->GetYaxis()->SetTitleSize(0.061);
   sfb->GetYaxis()->SetTitleOffset(0.49);
   sfb->GetYaxis()->SetLabelSize(0.059);
   sfb->SetXTitle(varName[2].c_str());
   sfb->GetXaxis()->SetTitleSize(0.061);
   sfb->GetXaxis()->SetTitleOffset(1.15);
   sfb->GetXaxis()->SetLabelSize(0.059);

   TH1D *sfe = new TH1D("", "", meee_nBin, meee_min, meee_max);
   sfe->Divide(mee_1e, mee_2e, 1., 1., "B");
   sfe->SetMarkerStyle(2);
   sfe->SetMarkerSize(1);
   sfe->SetMarkerColor(kBlack);
   sfe->SetLineColor(kBlack);
   sfe->SetLineWidth(1);
   sfe->SetAxisRange(0.01, 1.99, "y");
   sfe->SetTitle("");

   sfe->GetYaxis()->SetTitle("HLT / RECO");
   sfe->GetYaxis()->SetTitleSize(0.061);
   sfe->GetYaxis()->SetTitleOffset(0.49);
   sfe->GetYaxis()->SetLabelSize(0.059);
   sfe->SetXTitle(varName[2].c_str());
   sfe->GetXaxis()->SetTitleSize(0.061);
   sfe->GetXaxis()->SetTitleOffset(1.15);
   sfe->GetXaxis()->SetLabelSize(0.059);

   // -------------------------------------------------- //

   TLatex txt;
   txt.SetTextSize(0.035);
   txt.SetTextAlign(13);

   if (drawLog) {

     yMin_b++;
     yMin_e++;

   }

   mee_2b->SetMinimum(yMin_b);
   mee_2b->SetMaximum(yMax_b);
   mee_2e->SetMinimum(yMin_e);
   mee_2e->SetMaximum(yMax_e);

   mee_2b->SetYTitle(varName[3].c_str());
   mee_2b->GetYaxis()->SetTitleSize(0.027);
   mee_2b->GetYaxis()->SetTitleOffset(1.05);
   mee_2b->GetYaxis()->SetLabelSize(0.025);
   mee_2b->SetXTitle(varName[2].c_str());
   mee_2b->GetXaxis()->SetTitleSize(0.027);
   mee_2b->GetXaxis()->SetTitleOffset(1.15);
   mee_2b->GetXaxis()->SetLabelSize(0.025);

   mee_2e->SetYTitle(varName[3].c_str());
   mee_2e->GetYaxis()->SetTitleSize(0.027);
   mee_2e->GetYaxis()->SetTitleOffset(1.05);
   mee_2e->GetYaxis()->SetLabelSize(0.025);
   mee_2e->SetXTitle(varName[2].c_str());
   mee_2e->GetXaxis()->SetTitleSize(0.027);
   mee_2e->GetXaxis()->SetTitleOffset(1.15);
   mee_2e->GetXaxis()->SetLabelSize(0.025);

   TLegend *leg01 = new TLegend(.71, .67, .89, .85);
   leg01->SetHeader("EB Tag and EB Probe");
   //leg01->SetHeader("#left|#eta^{e}#right| < 1.479");
   leg01->AddEntry(mee_2b, (hisLeg).c_str(), "f");
   leg01->AddEntry(mee_1b, (pntLeg).c_str(), "p");
   leg01->SetFillColor(0);
   leg01->SetBorderSize(0);
   leg01->SetTextSize(0.03);
   leg01->SetTextFont(42);

   TLegend *leg02 = new TLegend(.71, .67, .89, .85);
   leg02->SetHeader("!(EB Tag and EB Probe)");
   //leg02->SetHeader("#left|#eta^{e}#right| > 1.479");
   leg02->AddEntry(mee_2e, (hisLeg).c_str(), "f");
   leg02->AddEntry(mee_1e, (pntLeg).c_str(), "p");
   leg02->SetFillColor(0);
   leg02->SetBorderSize(0);
   leg02->SetTextSize(0.03);
   leg02->SetTextFont(42);

   // -------------------------------------------------- //

   string const outDir = inDir;

   TCanvas *c01 = new TCanvas("c01", "c01", 200, 10, 1000, 1000);
   TCanvas *c02 = new TCanvas("c02", "c02", 200, 10, 1000, 1000);

   c01->cd();

   TPad *pad1 = new TPad("pad1", "pad1", 0., 0.29, 1., 1.);
   pad1->SetBottomMargin(0);
   pad1->Draw();
   pad1->cd();

   if (drawLog) pad1->SetLogy();
   mee_2b->Draw("hist");
   mee_1b->Draw("pesame");

   leg01->Draw();
   txt.DrawLatexNDC(0.06, 0.928, "#bf{CMS} #it{Preliminary}");
   txt.DrawLatexNDC(0.79, 0.936, "40.2 pb^{-1} (13 TeV)");

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
   c01->SaveAs((outDir + "wigt_" + varName[0] + "_hist_bar.pdf").c_str());

   c02->cd();

   TPad *pad3 = new TPad("pad3", "pad3", 0., 0.29, 1., 1.);
   pad3->SetBottomMargin(0);
   pad3->Draw();
   pad3->cd();

   if (drawLog) pad3->SetLogy();
   mee_2e->Draw("hist");
   mee_1e->Draw("pesame");

   leg02->Draw();
   txt.DrawLatexNDC(0.06, 0.928, "#bf{CMS} #it{Preliminary}");
   txt.DrawLatexNDC(0.79, 0.936, "40.2 pb^{-1} (13 TeV)");

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
   c02->SaveAs((outDir + "wigt_" + varName[0] + "_hist_end.pdf").c_str());

   // -------------------------------------------------- //

   c01->Close(); c02->Close();
   
}

int main() {

  tnpOff();
  return 0;

}



