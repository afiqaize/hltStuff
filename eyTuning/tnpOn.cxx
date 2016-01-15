// Stolen from mvaPlot in 740
// For the tnp hlt vs reco electron plotting
// Nov 25 updated and streamlined
// Usage: root -l tnpOn.cxx++

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
#include "/home/ieeya/root/macros/tdrstyle.C"

using namespace std;

// Subprogram for the tuning
// One for each region

Bool_t barPass(Float_t sie_cut_b, Float_t hoe_cut_b, Float_t ecc_cut_b, Float_t hcc_cut_b, 
               Float_t eop_cut_b, Float_t chi_cut_b, Float_t mih_cut_b, 
               Float_t det_cut_b, Float_t dph_cut_b, Float_t tki_cut_b) {

  Bool_t barOk = false;

  // All barrel cuts

  if (sie_cut_b <= 0.011) {
    if (hoe_cut_b <= 0.06) {
      if (ecc_cut_b <= 0.15) {
        if (hcc_cut_b <= 0.15) {
          if (eop_cut_b <= 0.012) {
            if (dph_cut_b <= 0.02) {
              if (det_cut_b <= 0.004) {
                if (tki_cut_b <= 0.08) {
                  if (mih_cut_b <= 5.5) { // careful at these not 1.0 cuts
                    if (chi_cut_b <= 15.0)
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

Bool_t endPass(Float_t sie_cut_e, Float_t hoe_cut_e, Float_t ecc_cut_e, Float_t hcc_cut_e, 
               Float_t eop_cut_e, Float_t chi_cut_e, Float_t mih_cut_e,
               Float_t det_cut_e, Float_t dph_cut_e, Float_t tki_cut_e) {

  Bool_t endOk = false;

  // All endcap cuts

  if (sie_cut_e <= 0.032) {
    if (hoe_cut_e <= 0.065) {
      if (ecc_cut_e <= 0.15) {
        if (hcc_cut_e <= 0.16) {
          if (eop_cut_e <= 0.01) {
            if (dph_cut_e <= 1.0) {
              if (det_cut_e <= 1.0) {
                if (tki_cut_e <= 0.08) {
                  if (mih_cut_e <= 2.5) { // careful at these not 1.0 cuts
                    if (chi_cut_e <= 2.8)
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

void tnpOn() {

   gROOT->Reset();

   setTDRStyle();

   // Everything to tinker with should be here
   Double_t yMin_b = .001, yMax_b = 69999.;
   Double_t yMin_e = .001, yMax_e = 19999.;

   string varName[5], outPre;
   varName[0] = "mee";
   outPre = "dyll_";

   Bool_t drawLog = false;
   Double_t cut_b = -1., cut_e = -1.;

   // -------------------------------------------------- //

   string hisLeg = "Full Mult.", pntLeg = "HLT Tuned", pntLeg2 = "HLT Std.";

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
   varName[4] = pntLeg + " / " + hisLeg;

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
     varName[2] = "TrkIso / E_{T}";

   }

   if (varName[0] == "lol") {

     varName[1] = "Testing";
     varName[2] = "Whatever";

   }

   // -------------------------------------------------- //

   TH1::SetDefaultSumw2(true);
   TGaxis::SetMaxDigits(3);

   TH1D* mee_1b = new TH1D("mee_1b", (varName[1] + " Distribution").c_str(), meeb_nBin, meeb_min, meeb_max);
   TH1D* mee_1e = new TH1D("mee_1e", (varName[1] + " Distribution").c_str(), meee_nBin, meee_min, meee_max);
   styleHist(mee_1b, kRed + 1, 0, 20, 1, 1.5);
   styleHist(mee_1e, kRed + 1, 0, 20, 1, 1.5);

   TH1D* phi_1b = new TH1D("phi_1b", (varName[1] + " Distribution").c_str(), phib_nBin, phib_min, phib_max);
   TH1D* phi_1e = new TH1D("phi_1e", (varName[1] + " Distribution").c_str(), phie_nBin, phie_min, phie_max);
   styleHist(phi_1b, kRed + 1, 0, 20, 1, 1.5);
   styleHist(phi_1e, kRed + 1, 0, 20, 1, 1.5);

   TH1D* eet_1b = new TH1D("eet_1b", (varName[1] + " Distribution").c_str(), eetb_nBin, eetb_min, eetb_max);
   TH1D* eet_1e = new TH1D("eet_1e", (varName[1] + " Distribution").c_str(), eete_nBin, eete_min, eete_max);
   styleHist(eet_1b, kRed + 1, 0, 20, 1, 1.5);
   styleHist(eet_1e, kRed + 1, 0, 20, 1, 1.5);

   TH1D* sie_1b = new TH1D("sie_1b", (varName[1] + " Distribution").c_str(), sieb_nBin, sieb_min, sieb_max);
   TH1D* sie_1e = new TH1D("sie_1e", (varName[1] + " Distribution").c_str(), siee_nBin, siee_min, siee_max);
   styleHist(sie_1b, kRed + 1, 0, 20, 1, 1.5);
   styleHist(sie_1e, kRed + 1, 0, 20, 1, 1.5);

   TH1D* hoe_1b = new TH1D("hoe_1b", (varName[1] + " Distribution").c_str(), hoeb_nBin, hoeb_min, hoeb_max);
   TH1D* hoe_1e = new TH1D("hoe_1e", (varName[1] + " Distribution").c_str(), hoee_nBin, hoee_min, hoee_max);
   styleHist(hoe_1b, kRed + 1, 0, 20, 1, 1.5);
   styleHist(hoe_1e, kRed + 1, 0, 20, 1, 1.5);

   TH1D* eca_1b = new TH1D("eca_1b", (varName[1] + " Distribution").c_str(), ecab_nBin, ecab_min, ecab_max);
   TH1D* eca_1e = new TH1D("eca_1e", (varName[1] + " Distribution").c_str(), ecae_nBin, ecae_min, ecae_max);
   styleHist(eca_1b, kRed + 1, 0, 20, 1, 1.5);
   styleHist(eca_1e, kRed + 1, 0, 20, 1, 1.5);

   TH1D* ecc_1b = new TH1D("ecc_1b", (varName[1] + " Distribution").c_str(), eccb_nBin, eccb_min, eccb_max);
   TH1D* ecc_1e = new TH1D("ecc_1e", (varName[1] + " Distribution").c_str(), ecce_nBin, ecce_min, ecce_max);
   styleHist(ecc_1b, kRed + 1, 0, 20, 1, 1.5);
   styleHist(ecc_1e, kRed + 1, 0, 20, 1, 1.5);

   TH1D* hca_1b = new TH1D("hca_1b", (varName[1] + " Distribution").c_str(), hcab_nBin, hcab_min, hcab_max);
   TH1D* hca_1e = new TH1D("hca_1e", (varName[1] + " Distribution").c_str(), hcae_nBin, hcae_min, hcae_max);
   styleHist(hca_1b, kRed + 1, 0, 20, 1, 1.5);
   styleHist(hca_1e, kRed + 1, 0, 20, 1, 1.5);

   TH1D* hcc_1b = new TH1D("hcc_1b", (varName[1] + " Distribution").c_str(), hccb_nBin, hccb_min, hccb_max);
   TH1D* hcc_1e = new TH1D("hcc_1e", (varName[1] + " Distribution").c_str(), hcce_nBin, hcce_min, hcce_max);
   styleHist(hcc_1b, kRed + 1, 0, 20, 1, 1.5);
   styleHist(hcc_1e, kRed + 1, 0, 20, 1, 1.5);

   TH1D* eop_1b = new TH1D("eop_1b", (varName[1] + " Distribution").c_str(), eopb_nBin, eopb_min, eopb_max);
   TH1D* eop_1e = new TH1D("eop_1e", (varName[1] + " Distribution").c_str(), eope_nBin, eope_min, eope_max);
   styleHist(eop_1b, kRed + 1, 0, 20, 1, 1.5);
   styleHist(eop_1e, kRed + 1, 0, 20, 1, 1.5);

   TH1D* chi_1b = new TH1D("chi_1b", (varName[1] + " Distribution").c_str(), chib_nBin, chib_min, chib_max);
   TH1D* chi_1e = new TH1D("chi_1e", (varName[1] + " Distribution").c_str(), chie_nBin, chie_min, chie_max);
   styleHist(chi_1b, kRed + 1, 0, 20, 1, 1.5);
   styleHist(chi_1e, kRed + 1, 0, 20, 1, 1.5);

   TH1D* mih_1b = new TH1D("mih_1b", (varName[1] + " Distribution").c_str(), mihb_nBin, mihb_min, mihb_max);
   TH1D* mih_1e = new TH1D("mih_1e", (varName[1] + " Distribution").c_str(), mihe_nBin, mihe_min, mihe_max);
   styleHist(mih_1b, kRed + 1, 0, 20, 1, 1.5);
   styleHist(mih_1e, kRed + 1, 0, 20, 1, 1.5);

   TH1D* det_1b = new TH1D("det_1b", (varName[1] + " Distribution").c_str(), detb_nBin, detb_min, detb_max);
   TH1D* det_1e = new TH1D("det_1e", (varName[1] + " Distribution").c_str(), dete_nBin, dete_min, dete_max);
   styleHist(det_1b, kRed + 1, 0, 20, 1, 1.5);
   styleHist(det_1e, kRed + 1, 0, 20, 1, 1.5);

   TH1D* dph_1b = new TH1D("dph_1b", (varName[1] + " Distribution").c_str(), dphb_nBin, dphb_min, dphb_max);
   TH1D* dph_1e = new TH1D("dph_1e", (varName[1] + " Distribution").c_str(), dphe_nBin, dphe_min, dphe_max);
   styleHist(dph_1b, kRed + 1, 0, 20, 1, 1.5);
   styleHist(dph_1e, kRed + 1, 0, 20, 1, 1.5);

   TH1D* tki_1b = new TH1D("tki_1b", (varName[1] + " Distribution").c_str(), tkib_nBin, tkib_min, tkib_max);
   TH1D* tki_1e = new TH1D("tki_1e", (varName[1] + " Distribution").c_str(), tkie_nBin, tkie_min, tkie_max);
   styleHist(tki_1b, kRed + 1, 0, 20, 1, 1.5);
   styleHist(tki_1e, kRed + 1, 0, 20, 1, 1.5);

   // -------------------------------------------------- //

   TH1D* mee_2b = new TH1D("mee_2b", (varName[1] + " Distribution").c_str(), meeb_nBin, meeb_min, meeb_max);
   TH1D* mee_2e = new TH1D("mee_2e", (varName[1] + " Distribution").c_str(), meee_nBin, meee_min, meee_max);
   styleHist(mee_2b, kAzure + 1, 1001, 2, 1, 1.5);
   styleHist(mee_2e, kAzure + 1, 1001, 2, 1, 1.5);

   TH1D* phi_2b = new TH1D("phi_2b", (varName[1] + " Distribution").c_str(), phib_nBin, phib_min, phib_max);
   TH1D* phi_2e = new TH1D("phi_2e", (varName[1] + " Distribution").c_str(), phie_nBin, phie_min, phie_max);
   styleHist(phi_2b, kAzure + 1, 1001, 2, 1, 1.5);
   styleHist(phi_2e, kAzure + 1, 1001, 2, 1, 1.5);

   TH1D* eet_2b = new TH1D("eet_2b", (varName[1] + " Distribution").c_str(), eetb_nBin, eetb_min, eetb_max);
   TH1D* eet_2e = new TH1D("eet_2e", (varName[1] + " Distribution").c_str(), eete_nBin, eete_min, eete_max);
   styleHist(eet_2b, kAzure + 1, 1001, 2, 1, 1.5);
   styleHist(eet_2e, kAzure + 1, 1001, 2, 1, 1.5);

   TH1D* sie_2b = new TH1D("sie_2b", (varName[1] + " Distribution").c_str(), sieb_nBin, sieb_min, sieb_max);
   TH1D* sie_2e = new TH1D("sie_2e", (varName[1] + " Distribution").c_str(), siee_nBin, siee_min, siee_max);
   styleHist(sie_2b, kAzure + 1, 1001, 2, 1, 1.5);
   styleHist(sie_2e, kAzure + 1, 1001, 2, 1, 1.5);

   TH1D* hoe_2b = new TH1D("hoe_2b", (varName[1] + " Distribution").c_str(), hoeb_nBin, hoeb_min, hoeb_max);
   TH1D* hoe_2e = new TH1D("hoe_2e", (varName[1] + " Distribution").c_str(), hoee_nBin, hoee_min, hoee_max);
   styleHist(hoe_2b, kAzure + 1, 1001, 2, 1, 1.5);
   styleHist(hoe_2e, kAzure + 1, 1001, 2, 1, 1.5);

   TH1D* eca_2b = new TH1D("eca_2b", (varName[1] + " Distribution").c_str(), ecab_nBin, ecab_min, ecab_max);
   TH1D* eca_2e = new TH1D("eca_2e", (varName[1] + " Distribution").c_str(), ecae_nBin, ecae_min, ecae_max);
   styleHist(eca_2b, kAzure + 1, 1001, 2, 1, 1.5);
   styleHist(eca_2e, kAzure + 1, 1001, 2, 1, 1.5);

   TH1D* ecc_2b = new TH1D("ecc_2b", (varName[1] + " Distribution").c_str(), eccb_nBin, eccb_min, eccb_max);
   TH1D* ecc_2e = new TH1D("ecc_2e", (varName[1] + " Distribution").c_str(), ecce_nBin, ecce_min, ecce_max);
   styleHist(ecc_2b, kAzure + 1, 1001, 2, 1, 1.5);
   styleHist(ecc_2e, kAzure + 1, 1001, 2, 1, 1.5);

   TH1D* hca_2b = new TH1D("hca_2b", (varName[1] + " Distribution").c_str(), hcab_nBin, hcab_min, hcab_max);
   TH1D* hca_2e = new TH1D("hca_2e", (varName[1] + " Distribution").c_str(), hcae_nBin, hcae_min, hcae_max);
   styleHist(hca_2b, kAzure + 1, 1001, 2, 1, 1.5);
   styleHist(hca_2e, kAzure + 1, 1001, 2, 1, 1.5);

   TH1D* hcc_2b = new TH1D("hcc_2b", (varName[1] + " Distribution").c_str(), hccb_nBin, hccb_min, hccb_max);
   TH1D* hcc_2e = new TH1D("hcc_2e", (varName[1] + " Distribution").c_str(), hcce_nBin, hcce_min, hcce_max);
   styleHist(hcc_2b, kAzure + 1, 1001, 2, 1, 1.5);
   styleHist(hcc_2e, kAzure + 1, 1001, 2, 1, 1.5);

   TH1D* eop_2b = new TH1D("eop_2b", (varName[1] + " Distribution").c_str(), eopb_nBin, eopb_min, eopb_max);
   TH1D* eop_2e = new TH1D("eop_2e", (varName[1] + " Distribution").c_str(), eope_nBin, eope_min, eope_max);
   styleHist(eop_2b, kAzure + 1, 1001, 2, 1, 1.5);
   styleHist(eop_2e, kAzure + 1, 1001, 2, 1, 1.5);

   TH1D* chi_2b = new TH1D("chi_2b", (varName[1] + " Distribution").c_str(), chib_nBin, chib_min, chib_max);
   TH1D* chi_2e = new TH1D("chi_2e", (varName[1] + " Distribution").c_str(), chie_nBin, chie_min, chie_max);
   styleHist(chi_2b, kAzure + 1, 1001, 2, 1, 1.5);
   styleHist(chi_2e, kAzure + 1, 1001, 2, 1, 1.5);

   TH1D* mih_2b = new TH1D("mih_2b", (varName[1] + " Distribution").c_str(), mihb_nBin, mihb_min, mihb_max);
   TH1D* mih_2e = new TH1D("mih_2e", (varName[1] + " Distribution").c_str(), mihe_nBin, mihe_min, mihe_max);
   styleHist(mih_2b, kAzure + 1, 1001, 2, 1, 1.5);
   styleHist(mih_2e, kAzure + 1, 1001, 2, 1, 1.5);

   TH1D* det_2b = new TH1D("det_2b", (varName[1] + " Distribution").c_str(), detb_nBin, detb_min, detb_max);
   TH1D* det_2e = new TH1D("det_2e", (varName[1] + " Distribution").c_str(), dete_nBin, dete_min, dete_max);
   styleHist(det_2b, kAzure + 1, 1001, 2, 1, 1.5);
   styleHist(det_2e, kAzure + 1, 1001, 2, 1, 1.5);

   TH1D* dph_2b = new TH1D("dph_2b", (varName[1] + " Distribution").c_str(), dphb_nBin, dphb_min, dphb_max);
   TH1D* dph_2e = new TH1D("dph_2e", (varName[1] + " Distribution").c_str(), dphe_nBin, dphe_min, dphe_max);
   styleHist(dph_2b, kAzure + 1, 1001, 2, 1, 1.5);
   styleHist(dph_2e, kAzure + 1, 1001, 2, 1, 1.5);

   TH1D* tki_2b = new TH1D("tki_2b", (varName[1] + " Distribution").c_str(), tkib_nBin, tkib_min, tkib_max);
   TH1D* tki_2e = new TH1D("tki_2e", (varName[1] + " Distribution").c_str(), tkie_nBin, tkie_min, tkie_max);
   styleHist(tki_2b, kAzure + 1, 1001, 2, 1, 1.5);
   styleHist(tki_2e, kAzure + 1, 1001, 2, 1, 1.5);

   // -------------------------------------------------- //

   TH1D* mee_3b = new TH1D("mee_3b", (varName[1] + " Distribution").c_str(), meeb_nBin, meeb_min, meeb_max);
   TH1D* mee_3e = new TH1D("mee_3e", (varName[1] + " Distribution").c_str(), meee_nBin, meee_min, meee_max);
   styleHist(mee_3b, kYellow + 1, 0, 23, 1, 2.0);
   styleHist(mee_3e, kYellow + 1, 0, 23, 1, 2.0);

   TH1D* phi_3b = new TH1D("phi_3b", (varName[1] + " Distribution").c_str(), phib_nBin, phib_min, phib_max);
   TH1D* phi_3e = new TH1D("phi_3e", (varName[1] + " Distribution").c_str(), phie_nBin, phie_min, phie_max);
   styleHist(phi_3b, kYellow + 1, 0, 23, 1, 2.0);
   styleHist(phi_3e, kYellow + 1, 0, 23, 1, 2.0);

   TH1D* eet_3b = new TH1D("eet_3b", (varName[1] + " Distribution").c_str(), eetb_nBin, eetb_min, eetb_max);
   TH1D* eet_3e = new TH1D("eet_3e", (varName[1] + " Distribution").c_str(), eete_nBin, eete_min, eete_max);
   styleHist(eet_3b, kYellow + 1, 0, 23, 1, 2.0);
   styleHist(eet_3e, kYellow + 1, 0, 23, 1, 2.0);

   TH1D* sie_3b = new TH1D("sie_3b", (varName[1] + " Distribution").c_str(), sieb_nBin, sieb_min, sieb_max);
   TH1D* sie_3e = new TH1D("sie_3e", (varName[1] + " Distribution").c_str(), siee_nBin, siee_min, siee_max);
   styleHist(sie_3b, kYellow + 1, 0, 23, 1, 2.0);
   styleHist(sie_3e, kYellow + 1, 0, 23, 1, 2.0);

   TH1D* hoe_3b = new TH1D("hoe_3b", (varName[1] + " Distribution").c_str(), hoeb_nBin, hoeb_min, hoeb_max);
   TH1D* hoe_3e = new TH1D("hoe_3e", (varName[1] + " Distribution").c_str(), hoee_nBin, hoee_min, hoee_max);
   styleHist(hoe_3b, kYellow + 1, 0, 23, 1, 2.0);
   styleHist(hoe_3e, kYellow + 1, 0, 23, 1, 2.0);

   TH1D* eca_3b = new TH1D("eca_3b", (varName[1] + " Distribution").c_str(), ecab_nBin, ecab_min, ecab_max);
   TH1D* eca_3e = new TH1D("eca_3e", (varName[1] + " Distribution").c_str(), ecae_nBin, ecae_min, ecae_max);
   styleHist(eca_3b, kYellow + 1, 0, 23, 1, 2.0);
   styleHist(eca_3e, kYellow + 1, 0, 23, 1, 2.0);

   TH1D* ecc_3b = new TH1D("ecc_3b", (varName[1] + " Distribution").c_str(), eccb_nBin, eccb_min, eccb_max);
   TH1D* ecc_3e = new TH1D("ecc_3e", (varName[1] + " Distribution").c_str(), ecce_nBin, ecce_min, ecce_max);
   styleHist(ecc_3b, kYellow + 1, 0, 23, 1, 2.0);
   styleHist(ecc_3e, kYellow + 1, 0, 23, 1, 2.0);

   TH1D* hca_3b = new TH1D("hca_3b", (varName[1] + " Distribution").c_str(), hcab_nBin, hcab_min, hcab_max);
   TH1D* hca_3e = new TH1D("hca_3e", (varName[1] + " Distribution").c_str(), hcae_nBin, hcae_min, hcae_max);
   styleHist(hca_3b, kYellow + 1, 0, 23, 1, 2.0);
   styleHist(hca_3e, kYellow + 1, 0, 23, 1, 2.0);

   TH1D* hcc_3b = new TH1D("hcc_3b", (varName[1] + " Distribution").c_str(), hccb_nBin, hccb_min, hccb_max);
   TH1D* hcc_3e = new TH1D("hcc_3e", (varName[1] + " Distribution").c_str(), hcce_nBin, hcce_min, hcce_max);
   styleHist(hcc_3b, kYellow + 1, 0, 23, 1, 2.0);
   styleHist(hcc_3e, kYellow + 1, 0, 23, 1, 2.0);

   TH1D* eop_3b = new TH1D("eop_3b", (varName[1] + " Distribution").c_str(), eopb_nBin, eopb_min, eopb_max);
   TH1D* eop_3e = new TH1D("eop_3e", (varName[1] + " Distribution").c_str(), eope_nBin, eope_min, eope_max);
   styleHist(eop_3b, kYellow + 1, 0, 23, 1, 2.0);
   styleHist(eop_3e, kYellow + 1, 0, 23, 1, 2.0);

   TH1D* chi_3b = new TH1D("chi_3b", (varName[1] + " Distribution").c_str(), chib_nBin, chib_min, chib_max);
   TH1D* chi_3e = new TH1D("chi_3e", (varName[1] + " Distribution").c_str(), chie_nBin, chie_min, chie_max);
   styleHist(chi_3b, kYellow + 1, 0, 23, 1, 2.0);
   styleHist(chi_3e, kYellow + 1, 0, 23, 1, 2.0);

   TH1D* mih_3b = new TH1D("mih_3b", (varName[1] + " Distribution").c_str(), mihb_nBin, mihb_min, mihb_max);
   TH1D* mih_3e = new TH1D("mih_3e", (varName[1] + " Distribution").c_str(), mihe_nBin, mihe_min, mihe_max);
   styleHist(mih_3b, kYellow + 1, 0, 23, 1, 2.0);
   styleHist(mih_3e, kYellow + 1, 0, 23, 1, 2.0);

   TH1D* det_3b = new TH1D("det_3b", (varName[1] + " Distribution").c_str(), detb_nBin, detb_min, detb_max);
   TH1D* det_3e = new TH1D("det_3e", (varName[1] + " Distribution").c_str(), dete_nBin, dete_min, dete_max);
   styleHist(det_3b, kYellow + 1, 0, 23, 1, 2.0);
   styleHist(det_3e, kYellow + 1, 0, 23, 1, 2.0);

   TH1D* dph_3b = new TH1D("dph_3b", (varName[1] + " Distribution").c_str(), dphb_nBin, dphb_min, dphb_max);
   TH1D* dph_3e = new TH1D("dph_3e", (varName[1] + " Distribution").c_str(), dphe_nBin, dphe_min, dphe_max);
   styleHist(dph_3b, kYellow + 1, 0, 23, 1, 2.0);
   styleHist(dph_3e, kYellow + 1, 0, 23, 1, 2.0);

   TH1D* tki_3b = new TH1D("tki_3b", (varName[1] + " Distribution").c_str(), tkib_nBin, tkib_min, tkib_max);
   TH1D* tki_3e = new TH1D("tki_3e", (varName[1] + " Distribution").c_str(), tkie_nBin, tkie_min, tkie_max);
   styleHist(tki_3b, kYellow + 1, 0, 23, 1, 2.0);
   styleHist(tki_3e, kYellow + 1, 0, 23, 1, 2.0);

   // -------------------------------------------------- //

   string const inDir = "/home/ieeya/Downloads/HLT_Val/dev/e_80x/file/v0p4/";

   TChain *t1 = new TChain("eleDistr");
   t1->Add((inDir + "dat_p1Tune_*.root").c_str());
   t1->Add((inDir + "dat_p2Std_*.root").c_str());
   t1->Add((inDir + "dat_p3Full_*.root").c_str());
   t1->Add((inDir + "dyll_m1Tune_m2Std_m3Full.root").c_str());

   //TFile *f1 = new TFile((inDir + "xxx.root").c_str());
   //TTree *t1 = (TTree *) f1->Get("eleDistr");

   Int_t type;
   t1->SetBranchAddress("itype", &type);
   Float_t weight;
   t1->SetBranchAddress("weight", &weight);
   Float_t puWgt;
   t1->SetBranchAddress("puWgt", &puWgt);

   Int_t pass[10];
   t1->SetBranchAddress("pass_hlt", pass);
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

     for (Int_t iTag = 0; iTag < n; iTag++) {

       if (pass[iTag] != 1) continue;
       if ((et[iTag] < 25.) or (eta[iTag] > 2.5)) continue;

       p4Tag.SetPtEtaPhiE(et[iTag], eta[iTag], phi[iTag], e[iTag]);

       for (Int_t iProbe = 0; iProbe < n; iProbe++) {

         if (iProbe == iTag) continue;
         if (et[iProbe] < 15.) continue;

         p4Probe.SetPtEtaPhiE(et[iProbe], eta[iProbe], phi[iProbe], e[iProbe]);

         if ((p4Tag + p4Probe).M() < 70. or (p4Tag + p4Probe).M() > 110.) continue;

         //p4Tag.SetPtEtaPhiE(etr[iTag], eta[iTag], phi[iTag], er[iTag]);
         //p4Probe.SetPtEtaPhiE(etr[iProbe], eta[iProbe], phi[iProbe], er[iProbe]);

         if (type == -1) {

           if (fabs(eta[iProbe]) < 1.4791) {

             if(!barPass(sie[iProbe], hoe[iProbe], ecc[iProbe], hcc[iProbe], eop[iProbe],
                         chi[iProbe], mih[iProbe], det[iProbe], dph[iProbe], tki[iProbe])) continue;

             sie_1b->Fill(sie[iProbe], finWgt);
             hoe_1b->Fill(hoe[iProbe], finWgt);
             eca_1b->Fill(eca[iProbe], finWgt);
             ecc_1b->Fill(ecc[iProbe], finWgt);
             hca_1b->Fill(hca[iProbe], finWgt);
             hcc_1b->Fill(hcc[iProbe], finWgt);
             eop_1b->Fill(eop[iProbe], finWgt);
             chi_1b->Fill(chi[iProbe], finWgt);
             mih_1b->Fill(mih[iProbe], finWgt);
             det_1b->Fill(det[iProbe], finWgt);
             dph_1b->Fill(dph[iProbe], finWgt);
             tki_1b->Fill(tki[iProbe], finWgt);
 
           }

           if (fabs(eta[iProbe]) >= 1.4791) {

             if(!endPass(sie[iProbe], hoe[iProbe], ecc[iProbe], hcc[iProbe], eop[iProbe],
                         chi[iProbe], mih[iProbe], det[iProbe], dph[iProbe], tki[iProbe])) continue;

             sie_1e->Fill(sie[iProbe], finWgt);
             hoe_1e->Fill(hoe[iProbe], finWgt);
             eca_1e->Fill(eca[iProbe], finWgt);
             ecc_1e->Fill(ecc[iProbe], finWgt);
             hca_1e->Fill(hca[iProbe], finWgt);
             hcc_1e->Fill(hcc[iProbe], finWgt);
             eop_1e->Fill(eop[iProbe], finWgt);
             chi_1e->Fill(chi[iProbe], finWgt);
             mih_1e->Fill(mih[iProbe], finWgt);
             det_1e->Fill(det[iProbe], finWgt);
             dph_1e->Fill(dph[iProbe], finWgt);
             tki_1e->Fill(tki[iProbe], finWgt);

           }

           if (eta[iTag] < 1.4791 and eta[iProbe] < 1.4791)
             mee_1b->Fill((p4Tag + p4Probe).M(), finWgt);

           else
             mee_1e->Fill((p4Tag + p4Probe).M(), finWgt);

         }

         if (type == -3) {

           if (fabs(eta[iProbe]) < 1.4791) {

             if(!barPass(sie[iProbe], hoe[iProbe], ecc[iProbe], hcc[iProbe], eop[iProbe],
                         chi[iProbe], mih[iProbe], det[iProbe], dph[iProbe], tki[iProbe])) continue;

             sie_2b->Fill(sie[iProbe], finWgt);
             hoe_2b->Fill(hoe[iProbe], finWgt);
             eca_2b->Fill(eca[iProbe], finWgt);
             ecc_2b->Fill(ecc[iProbe], finWgt);
             hca_2b->Fill(hca[iProbe], finWgt);
             hcc_2b->Fill(hcc[iProbe], finWgt);
             eop_2b->Fill(eop[iProbe], finWgt);
             chi_2b->Fill(chi[iProbe], finWgt);
             mih_2b->Fill(mih[iProbe], finWgt);
             det_2b->Fill(det[iProbe], finWgt);
             dph_2b->Fill(dph[iProbe], finWgt);
             tki_2b->Fill(tki[iProbe], finWgt);

           }

           if (fabs(eta[iProbe]) >= 1.4791) {

             if(!endPass(sie[iProbe], hoe[iProbe], ecc[iProbe], hcc[iProbe], eop[iProbe],
                         chi[iProbe], mih[iProbe], det[iProbe], dph[iProbe], tki[iProbe])) continue;

             sie_2e->Fill(sie[iProbe], finWgt);
             hoe_2e->Fill(hoe[iProbe], finWgt);
             eca_2e->Fill(eca[iProbe], finWgt);
             ecc_2e->Fill(ecc[iProbe], finWgt);
             hca_2e->Fill(hca[iProbe], finWgt);
             hcc_2e->Fill(hcc[iProbe], finWgt);
             eop_2e->Fill(eop[iProbe], finWgt);
             chi_2e->Fill(chi[iProbe], finWgt);
             mih_2e->Fill(mih[iProbe], finWgt);
             det_2e->Fill(det[iProbe], finWgt);
             dph_2e->Fill(dph[iProbe], finWgt);
             tki_2e->Fill(tki[iProbe], finWgt);

           }

           if (eta[iTag] < 1.4791 and eta[iProbe] < 1.4791)
             mee_2b->Fill((p4Tag + p4Probe).M(), finWgt);

           else
             mee_2e->Fill((p4Tag + p4Probe).M(), finWgt);

         }

         if (type == -2) {

           if (fabs(eta[iProbe]) < 1.4791) {

             if(!barPass(sie[iProbe], hoe[iProbe], ecc[iProbe], hcc[iProbe], eop[iProbe],
                         chi[iProbe], mih[iProbe], det[iProbe], dph[iProbe], tki[iProbe])) continue;

             sie_3b->Fill(sie[iProbe], finWgt);
             hoe_3b->Fill(hoe[iProbe], finWgt);
             eca_3b->Fill(eca[iProbe], finWgt);
             ecc_3b->Fill(ecc[iProbe], finWgt);
             hca_3b->Fill(hca[iProbe], finWgt);
             hcc_3b->Fill(hcc[iProbe], finWgt);
             eop_3b->Fill(eop[iProbe], finWgt);
             chi_3b->Fill(chi[iProbe], finWgt);
             mih_3b->Fill(mih[iProbe], finWgt);
             det_3b->Fill(det[iProbe], finWgt);
             dph_3b->Fill(dph[iProbe], finWgt);
             tki_3b->Fill(tki[iProbe], finWgt);

           }

           if (fabs(eta[iProbe]) >= 1.4791) {

             if(!endPass(sie[iProbe], hoe[iProbe], ecc[iProbe], hcc[iProbe], eop[iProbe],
                         chi[iProbe], mih[iProbe], det[iProbe], dph[iProbe], tki[iProbe])) continue;

             sie_3e->Fill(sie[iProbe], finWgt);
             hoe_3e->Fill(hoe[iProbe], finWgt);
             eca_3e->Fill(eca[iProbe], finWgt);
             ecc_3e->Fill(ecc[iProbe], finWgt);
             hca_3e->Fill(hca[iProbe], finWgt);
             hcc_3e->Fill(hcc[iProbe], finWgt);
             eop_3e->Fill(eop[iProbe], finWgt);
             chi_3e->Fill(chi[iProbe], finWgt);
             mih_3e->Fill(mih[iProbe], finWgt);
             det_3e->Fill(det[iProbe], finWgt);
             dph_3e->Fill(dph[iProbe], finWgt);
             tki_3e->Fill(tki[iProbe], finWgt);

           }

           if (eta[iTag] < 1.4791 and eta[iProbe] < 1.4791)
             mee_3b->Fill((p4Tag + p4Probe).M(), finWgt);

           else
             mee_3e->Fill((p4Tag + p4Probe).M(), finWgt);

         }
       }
     }
   }

   //cout << det_1b->GetEntries() << " " << det_2b->GetEntries() << endl;
   //cout << det_1e->GetEntries() << " " << det_2e->GetEntries() << endl;

   // -------------------------------------------------- //

   //mee_2b->Scale(mee_1b->Integral() / mee_2b->Integral()); mee_2e->Scale(mee_1e->Integral() / mee_2e->Integral());

   static const Int_t nStep_b = meeb_nBin + 1, nStep_e = meee_nBin + 1;
   Double_t sStep_b = (meeb_max - meeb_min) / meeb_nBin, sStep_e = (meee_max - meee_min) / meee_nBin;

   Float_t l1b[nStep_b], eff_xb[nStep_b];
   Float_t l1e[nStep_e], eff_xe[nStep_e];
   Double_t std_xb[nStep_b], std_xe[nStep_e], std_yb[nStep_b], std_ye[nStep_e];

   for (Int_t bb = 0; bb < nStep_b; bb++) {

     l1b[bb] = 1.;
     eff_xb[bb] = (bb * sStep_b) + meeb_min;

     std_xb[bb] = cut_b;
     if (bb == 0) std_yb[bb] = yMax_b;
     else if (bb == nStep_b - 1) std_yb[bb] = 0.;
     else std_yb[bb] = (1. - ((Double_t) (bb + 1) / (Double_t) nStep_b));

   }

   for (Int_t ee = 0; ee < nStep_e; ee++) {

     l1e[ee] = 1.;
     eff_xe[ee] = (ee * sStep_e) + meee_min;

     std_xe[ee] = cut_e;
     if (ee == 0) std_ye[ee] = yMax_e;
     else if (ee == nStep_e - 1) std_ye[ee] = 0.;
     else std_ye[ee] = (1. - ((Double_t) (ee + 1) / (Double_t) nStep_e));

   }

   TGraph *lineb = new TGraph(meeb_nBin + 1, eff_xb, l1b);
   lineb->SetLineColor(kYellow + 1);
   lineb->SetLineWidth(2);

   TGraph *linee = new TGraph(meee_nBin + 1, eff_xe, l1e);
   linee->SetLineColor(kYellow + 1);
   linee->SetLineWidth(2);

   TH1D *sfb = new TH1D("", "", meeb_nBin, meeb_min, meeb_max);
   sfb->Divide(mee_1b, mee_2b, 1., 1., "B");
   styleHist(sfb, kBlack, 0, 2, 1, 1.0);
   axHist(sfb, 0.001, 1.999, varName[4], 0.061, 0.49, 0.059, varName[2], 0.061, 1.15, 0.059);

   TH1D *sfe = new TH1D("", "", meee_nBin, meee_min, meee_max);
   sfe->Divide(mee_1e, mee_2e, 1., 1., "B");
   styleHist(sfe, kBlack, 0, 2, 1, 1.0);
   axHist(sfe, 0.001, 1.999, varName[4], 0.061, 0.49, 0.059, varName[2], 0.061, 1.15, 0.059);

   TGraph* stdb = new TGraph(nStep_b, std_xb, std_yb);
   stdb->SetLineColor(kBlack);
   stdb->SetLineWidth(3);

   TGraph* stde = new TGraph(nStep_e, std_xe, std_ye);
   stde->SetLineColor(kBlack);
   stde->SetLineWidth(3);

   // -------------------------------------------------- //

   TLatex txt;
   txt.SetTextSize(0.035);
   txt.SetTextAlign(13);

   if (drawLog) {

     yMin_b++;
     yMin_e++;

   }

   axHist(mee_2b, yMin_b, yMax_b, varName[3], 0.027, 1.05, 0.025, varName[2], 0.027, 1.15, 0.025);
   axHist(mee_2e, yMin_e, yMax_e, varName[3], 0.027, 1.05, 0.025, varName[2], 0.027, 1.15, 0.025);

   TLegend *leg01 = new TLegend(.71, .67, .89, .85);
   leg01->SetHeader("EB Tag and EB Probe");
   //leg01->SetHeader("#left|#eta^{e}#right| < 1.479");
   leg01->AddEntry(mee_2b, (hisLeg).c_str(), "f");
   leg01->AddEntry(mee_1b, (pntLeg).c_str(), "p");
   leg01->AddEntry(mee_3b, (pntLeg2).c_str(), "l");
   leg01->SetFillColor(0);
   leg01->SetBorderSize(0);
   leg01->SetTextSize(0.03);
   leg01->SetTextFont(42);

   TLegend *leg02 = new TLegend(.71, .67, .89, .85);
   leg02->SetHeader("!(EB Tag and EB Probe)");
   //leg02->SetHeader("#left|#eta^{e}#right| > 1.479");
   leg02->AddEntry(mee_2e, (hisLeg).c_str(), "f");
   leg02->AddEntry(mee_1e, (pntLeg).c_str(), "p");
   leg02->AddEntry(mee_3e, (pntLeg2).c_str(), "l");
   leg02->SetFillColor(0);
   leg02->SetBorderSize(0);
   leg02->SetTextSize(0.03);
   leg02->SetTextFont(42);

   // -------------------------------------------------- //

   string const outDir = inDir + "plot/";

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
   mee_3b->Draw("histsame");
   stdb->Draw("same");

   leg01->Draw();
   txt.DrawLatexNDC(0.11, 0.928, "#bf{CMS} #it{Preliminary}");
   txt.DrawLatexNDC(0.783, 0.933, "2.138 fb^{-1} (13 TeV)");

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
   c01->SaveAs((outDir + outPre + varName[0] + "_bar.pdf").c_str());

   c02->cd();

   TPad *pad3 = new TPad("pad3", "pad3", 0., 0.29, 1., 1.);
   pad3->SetBottomMargin(0);
   pad3->Draw();
   pad3->cd();

   if (drawLog) pad3->SetLogy();
   mee_2e->Draw("hist");
   mee_1e->Draw("pesame");
   mee_3e->Draw("histsame");
   stde->Draw("same");

   leg02->Draw();
   txt.DrawLatexNDC(0.11, 0.928, "#bf{CMS} #it{Preliminary}");
   txt.DrawLatexNDC(0.783, 0.933, "2.138 fb^{-1} (13 TeV)");

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
   c02->SaveAs((outDir + outPre + varName[0] + "_end.pdf").c_str());

   // -------------------------------------------------- //

   c01->Close(); c02->Close();
   gROOT->ProcessLine(".q");
   
}

int main() {

  tnpOn();
  return 0;

}



