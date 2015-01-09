// Adapted from plotter code for tuning purposes
// To be used with the output of Matteo's plotDistr
// Standard notation; 1 for background 2 for signal
// Run in ROOT: .x code.cxx+
// A modification of the original tunePlot making use of weights
// For use with updated tree by Matteo's reduceOptTree
// Order of tuning now follows Variables.hh

#include <iostream>
#include <iomanip>
#include "TROOT.h"
#include "TH1.h"
#include "TCanvas.h"
#include <stdlib.h>
#include "TStyle.h"
#include "TH1D.h"
#include "TGraph.h"
#include "TFile.h"
#include <string.h>
#include "TTree.h"

using namespace std;

// Subprogram for the tuning
// One for each region

Bool_t barPass(Float_t e_cut_b, 
               Float_t sie_cut_b, Float_t hoe_cut_b, Float_t eca_cut_b, Float_t hca_cut_b, 
               Float_t eop_cut_b, Float_t chi_cut_b, 
               Float_t det_cut_b, Float_t dph_cut_b, Float_t tki_cut_b) {

  Bool_t barOk = false;

  // All barrel cuts

  if (sie_cut_b <= 1.0) {
    if ((hoe_cut_b - (e_cut_b / 100.)) <= 100.0) {
      if (eca_cut_b <= 1.0) {
        if (hca_cut_b <= 1.0) {
          if (eop_cut_b <= 1.0) {
            if (dph_cut_b <= 1.0) {
              if (det_cut_b <= 1.0) {
                if (tki_cut_b <= 1.0) {
                  if (chi_cut_b <= 10.0) // careful at chi, it's not 1
                        barOk = true;

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

Bool_t endPass(Float_t e_cut_e,
               Float_t sie_cut_e, Float_t hoe_cut_e, Float_t eca_cut_e, Float_t hca_cut_e, 
               Float_t eop_cut_e, Float_t chi_cut_e, 
               Float_t det_cut_e, Float_t dph_cut_e, Float_t tki_cut_e) {

  Bool_t endOk = false;

  // All endcap cuts

  if (sie_cut_e <= 1.0) {
    if ((hoe_cut_e - (e_cut_e / 100.)) <= 100.0) {
      if (eca_cut_e <= 1.0) {
        if (hca_cut_e <= 1.0) {
          if (eop_cut_e <= 1.0) {
            if (dph_cut_e <= 1.0) {
              if (det_cut_e <= 1.0) {
                if (tki_cut_e <= 1.0) {
                  if (chi_cut_e <= 10.0) // careful at chi, it's not 1.0
                        endOk = true;

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

  varHist->Fill(varVal /*- (0.01 * eVal)*/, weightVal);

}

// Subprogram to calculate cumulative sum
// nStep should always be nbins + 1
Double_t effCalc(Int_t nStep, TH1D* hist) {

  Double_t eff = 0.;

    for (Int_t j = nStep; j >= 0; j--) {

      Double_t k = hist->GetBinContent(j);
      eff += k;

    }

  return eff;

}

void mvaPlot() {

   gStyle->SetOptStat(0);

   // Everything to tinker with should be here, other than the cuts

   Double_t cut_b = 0., cut_e = 0.;

   string varName = "sie", varTitle = "#sigma_{i#etai#eta}";

   Bool_t drawLog = false;

   /***
       List of varTitles, varNames for easy Latexing

       #sigma_{i#etai#eta} sie
       H - 0.01E hoe
       EcalIso eca
       HcalIso hca
       1/E - 1/P eop
       #Delta#phi dph
       #Delta#eta det
       TrackIso tki
       Track #chi^{2} chi
   ***/

   Int_t sieb_nBin = 100, siee_nBin = 120;
   Double_t sieb_max = .02, siee_max = .06;
   Double_t sieb_min = 0., siee_min = 0.;

   /*/ For E
   Int_t hoeb_nBin = 120, hoee_nBin = 120;
   Double_t hoeb_max = 600., hoee_max = 600.;
   Double_t hoeb_min = 0., hoee_min = 0.;*/

   // For H
   Int_t hoeb_nBin = 125, hoee_nBin = 300;
   Double_t hoeb_max = 20., hoee_max = 55.;
   Double_t hoeb_min = -5., hoee_min = -5.;

   /*/ For H/E
   Int_t hoeb_nBin = 20, hoee_nBin = 30;
   Double_t hoeb_max = .2, hoee_max = .3;
   Double_t hoeb_min = 0., hoee_min = 0.;*/

   Int_t ecab_nBin = 120, ecae_nBin = 120;
   Double_t ecab_max = 1., ecae_max = 1.;
   Double_t ecab_min = -.2, ecae_min = -.2;

   Int_t hcab_nBin = 180, hcae_nBin = 220;
   Double_t hcab_max = .7, hcae_max = .9;
   Double_t hcab_min = -.2, hcae_min = -.2;

   Int_t eopb_nBin = 125, eope_nBin = 350;
   Double_t eopb_max = .125, eope_max = .35;
   Double_t eopb_min = 0., eope_min = 0.;

   Int_t chib_nBin = 100, chie_nBin = 60;
   Double_t chib_max = 10., chie_max = 6.;
   Double_t chib_min = 0., chie_min = 0.;

   Int_t detb_nBin = 75, dete_nBin = 60;
   Double_t detb_max = 0.015, dete_max = 0.03;
   Double_t detb_min = 0., dete_min = 0.;

   Int_t dphb_nBin = 150, dphe_nBin = 150;
   Double_t dphb_max = 0.15, dphe_max = 0.15;
   Double_t dphb_min = 0., dphe_min = 0.;

   Int_t tkib_nBin = 100, tkie_nBin = 100;
   Double_t tkib_max = 0.5, tkie_max = 0.5;
   Double_t tkib_min = 0., tkie_min = 0.;

   string const inDir = "/home/ieeya/Downloads/HLT_Val/Part2_OpenHLT/OpenHLT/logs/run02/ttbar_skim/e_72X/mvaPlot/";

   TFile *f1 = new TFile((inDir + "test.root").c_str());

   // -------------------------------------------------- //

   TCanvas *c01 = new TCanvas("c01", "c01", 200, 10, 1600, 900);
   TCanvas *c02 = new TCanvas("c02", "c02", 200, 10, 1600, 900);
   TCanvas *cg1 = new TCanvas("cg1", "cg1", 200, 10, 1600, 900);
   TCanvas *cg2 = new TCanvas("cg2", "cg2", 200, 10, 1600, 900);

   // -------------------------------------------------- //

   TTree *t1 = (TTree *) f1->Get("new_opttree");

   TH1D* sie1b = new TH1D("sie1b", ("Barrel " + varTitle + " Distr.").c_str(), sieb_nBin, sieb_min, sieb_max);
   TH1D* sie1e = new TH1D("sie1e", ("Endcap " + varTitle + " Distr.").c_str(), siee_nBin, siee_min, siee_max);
   sie1b->SetFillColor(kRed + 1);
   sie1b->SetLineColor(kRed + 1);
   sie1b->SetFillStyle(3157);
   sie1e->SetFillColor(kRed + 1);
   sie1e->SetLineColor(kRed + 1);
   sie1e->SetFillStyle(3157);

   TH1D* hoe1b = new TH1D("hoe1b", ("Barrel " + varTitle + " Distr.").c_str(), hoeb_nBin, hoeb_min, hoeb_max);
   TH1D* hoe1e = new TH1D("hoe1e", ("Endcap " + varTitle + " Distr.").c_str(), hoee_nBin, hoee_min, hoee_max);
   hoe1b->SetFillColor(kRed + 1);
   hoe1b->SetLineColor(kRed + 1);
   hoe1b->SetFillStyle(3157);
   hoe1e->SetFillColor(kRed + 1);
   hoe1e->SetLineColor(kRed + 1);
   hoe1e->SetFillStyle(3157);

   TH1D* eca1b = new TH1D("eca1b", ("Barrel " + varTitle + " Distr.").c_str(), ecab_nBin, ecab_min, ecab_max);
   TH1D* eca1e = new TH1D("eca1e", ("Endcap " + varTitle + " Distr.").c_str(), ecae_nBin, ecae_min, ecae_max);
   eca1b->SetFillColor(kRed + 1);
   eca1b->SetLineColor(kRed + 1);
   eca1b->SetFillStyle(3157);
   eca1e->SetFillColor(kRed + 1);
   eca1e->SetLineColor(kRed + 1);
   eca1e->SetFillStyle(3157);

   TH1D* hca1b = new TH1D("hca1b", ("Barrel " + varTitle + " Distr.").c_str(), hcab_nBin, hcab_min, hcab_max);
   TH1D* hca1e = new TH1D("hca1e", ("Endcap " + varTitle + " Distr.").c_str(), hcae_nBin, hcae_min, hcae_max);
   hca1b->SetFillColor(kRed + 1);
   hca1b->SetLineColor(kRed + 1);
   hca1b->SetFillStyle(3157);
   hca1e->SetFillColor(kRed + 1);
   hca1e->SetLineColor(kRed + 1);
   hca1e->SetFillStyle(3157);

   TH1D* eop1b = new TH1D("eop1b", ("Barrel " + varTitle + " Distr.").c_str(), eopb_nBin, eopb_min, eopb_max);
   TH1D* eop1e = new TH1D("eop1e", ("Endcap " + varTitle + " Distr.").c_str(), eope_nBin, eope_min, eope_max);
   eop1b->SetFillColor(kRed + 1);
   eop1b->SetLineColor(kRed + 1);
   eop1b->SetFillStyle(3157);
   eop1e->SetFillColor(kRed + 1);
   eop1e->SetLineColor(kRed + 1);
   eop1e->SetFillStyle(3157);

   TH1D* chi1b = new TH1D("chi1b", ("Barrel " + varTitle + " Distr.").c_str(), chib_nBin, chib_min, chib_max);
   TH1D* chi1e = new TH1D("chi1e", ("Endcap " + varTitle + " Distr.").c_str(), chie_nBin, chie_min, chie_max);
   chi1b->SetFillColor(kRed + 1);
   chi1b->SetLineColor(kRed + 1);
   chi1b->SetFillStyle(3157);
   chi1e->SetFillColor(kRed + 1);
   chi1e->SetLineColor(kRed + 1);
   chi1e->SetFillStyle(3157);

   TH1D* det1b = new TH1D("det1b", ("Barrel " + varTitle + " Distr.").c_str(), detb_nBin, detb_min, detb_max);
   TH1D* det1e = new TH1D("det1e", ("Endcap " + varTitle + " Distr.").c_str(), dete_nBin, dete_min, dete_max);
   det1b->SetFillColor(kRed + 1);
   det1b->SetLineColor(kRed + 1);
   det1b->SetFillStyle(3157);
   det1e->SetFillColor(kRed + 1);
   det1e->SetLineColor(kRed + 1);
   det1e->SetFillStyle(3157);

   TH1D* dph1b = new TH1D("dph1b", ("Barrel " + varTitle + " Distr.").c_str(), dphb_nBin, dphb_min, dphb_max);
   TH1D* dph1e = new TH1D("dph1e", ("Endcap " + varTitle + " Distr.").c_str(), dphe_nBin, dphe_min, dphe_max);
   dph1b->SetFillColor(kRed + 1);
   dph1b->SetLineColor(kRed + 1);
   dph1b->SetFillStyle(3157);
   dph1e->SetFillColor(kRed + 1);
   dph1e->SetLineColor(kRed + 1);
   dph1e->SetFillStyle(3157);

   TH1D* tki1b = new TH1D("tki1b", ("Barrel " + varTitle + " Distr.").c_str(), tkib_nBin, tkib_min, tkib_max);
   TH1D* tki1e = new TH1D("tki1e", ("Endcap " + varTitle + " Distr.").c_str(), tkie_nBin, tkie_min, tkie_max);
   tki1b->SetFillColor(kRed + 1);
   tki1b->SetLineColor(kRed + 1);
   tki1b->SetFillStyle(3157);
   tki1e->SetFillColor(kRed + 1);
   tki1e->SetLineColor(kRed + 1);
   tki1e->SetFillStyle(3157);

   // -------------------------------------------------- //

   TH1D* sie2b = new TH1D("sie2b", ("Barrel " + varTitle + " Distr.").c_str(), sieb_nBin, sieb_min, sieb_max);
   TH1D* sie2e = new TH1D("sie2e", ("Endcap " + varTitle + " Distr.").c_str(), siee_nBin, siee_min, siee_max);
   sie2b->SetFillColor(kAzure + 1);
   sie2b->SetLineColor(kAzure + 1);
   sie2e->SetFillColor(kAzure + 1);
   sie2e->SetLineColor(kAzure + 1);

   TH1D* hoe2b = new TH1D("hoe2b", ("Barrel " + varTitle + " Distr.").c_str(), hoeb_nBin, hoeb_min, hoeb_max);
   TH1D* hoe2e = new TH1D("hoe2e", ("Endcap " + varTitle + " Distr.").c_str(), hoee_nBin, hoee_min, hoee_max);
   hoe2b->SetFillColor(kAzure + 1);
   hoe2b->SetLineColor(kAzure + 1);
   hoe2e->SetFillColor(kAzure + 1);
   hoe2e->SetLineColor(kAzure + 1);

   TH1D* eca2b = new TH1D("eca2b", ("Barrel " + varTitle + " Distr.").c_str(), ecab_nBin, ecab_min, ecab_max);
   TH1D* eca2e = new TH1D("eca2e", ("Endcap " + varTitle + " Distr.").c_str(), ecae_nBin, ecae_min, ecae_max);
   eca2b->SetFillColor(kAzure + 1);
   eca2b->SetLineColor(kAzure + 1);
   eca2e->SetFillColor(kAzure + 1);
   eca2e->SetLineColor(kAzure + 1);

   TH1D* hca2b = new TH1D("hca2b", ("Barrel " + varTitle + " Distr.").c_str(), hcab_nBin, hcab_min, hcab_max);
   TH1D* hca2e = new TH1D("hca2e", ("Endcap " + varTitle + " Distr.").c_str(), hcae_nBin, hcae_min, hcae_max);
   hca2b->SetFillColor(kAzure + 1);
   hca2b->SetLineColor(kAzure + 1);
   hca2e->SetFillColor(kAzure + 1);
   hca2e->SetLineColor(kAzure + 1);

   TH1D* eop2b = new TH1D("eop2b", ("Barrel " + varTitle + " Distr.").c_str(), eopb_nBin, eopb_min, eopb_max);
   TH1D* eop2e = new TH1D("eop2e", ("Endcap " + varTitle + " Distr.").c_str(), eope_nBin, eope_min, eope_max);
   eop2b->SetFillColor(kAzure + 1);
   eop2b->SetLineColor(kAzure + 1);
   eop2e->SetFillColor(kAzure + 1);
   eop2e->SetLineColor(kAzure + 1);

   TH1D* chi2b = new TH1D("chi2b", ("Barrel " + varTitle + " Distr.").c_str(), chib_nBin, chib_min, chib_max);
   TH1D* chi2e = new TH1D("chi2e", ("Endcap " + varTitle + " Distr.").c_str(), chie_nBin, chie_min, chie_max);
   chi2b->SetFillColor(kAzure + 1);
   chi2b->SetLineColor(kAzure + 1);
   chi2e->SetFillColor(kAzure + 1);
   chi2e->SetLineColor(kAzure + 1);

   TH1D* det2b = new TH1D("det2b", ("Barrel " + varTitle + " Distr.").c_str(), detb_nBin, detb_min, detb_max);
   TH1D* det2e = new TH1D("det2e", ("Endcap " + varTitle + " Distr.").c_str(), dete_nBin, dete_min, dete_max);
   det2b->SetFillColor(kAzure + 1);
   det2b->SetLineColor(kAzure + 1);
   det2e->SetFillColor(kAzure + 1);
   det2e->SetLineColor(kAzure + 1);

   TH1D* dph2b = new TH1D("dph2b", ("Barrel " + varTitle + " Distr.").c_str(), dphb_nBin, dphb_min, dphb_max);
   TH1D* dph2e = new TH1D("dph2e", ("Endcap " + varTitle + " Distr.").c_str(), dphe_nBin, dphe_min, dphe_max);
   dph2b->SetFillColor(kAzure + 1);
   dph2b->SetLineColor(kAzure + 1);
   dph2e->SetFillColor(kAzure + 1);
   dph2e->SetLineColor(kAzure + 1);

   TH1D* tki2b = new TH1D("tki2b", ("Barrel " + varTitle + " Distr.").c_str(), tkib_nBin, tkib_min, tkib_max);
   TH1D* tki2e = new TH1D("tki2e", ("Endcap " + varTitle + " Distr.").c_str(), tkie_nBin, tkie_min, tkie_max);
   tki2b->SetFillColor(kAzure + 1);
   tki2b->SetLineColor(kAzure + 1);
   tki2e->SetFillColor(kAzure + 1);
   tki2e->SetLineColor(kAzure + 1);

   Int_t type;
   t1->SetBranchAddress("itype", &type);
   Float_t weight;
   t1->SetBranchAddress("weight", &weight);
   Float_t et;
   t1->SetBranchAddress("et", &et);
   Float_t e;
   t1->SetBranchAddress("e", &e);
   Float_t eta;
   t1->SetBranchAddress("eta", &eta);
   Float_t sie;
   t1->SetBranchAddress("sieie", &sie);
   Float_t hoe;
   t1->SetBranchAddress("hoe", &hoe);
   Float_t eca;
   t1->SetBranchAddress("ecal", &eca);
   Float_t hca;
   t1->SetBranchAddress("hcal", &hca);
   Float_t eop;
   t1->SetBranchAddress("eop", &eop);
   Float_t chi;
   t1->SetBranchAddress("chi2", &chi);
   Float_t det;
   t1->SetBranchAddress("deta", &det);
   Float_t dph;
   t1->SetBranchAddress("dphi", &dph);
   Float_t tki;
   t1->SetBranchAddress("tkiso", &tki);

   // -------------------------------------------------- //

   Int_t nEvt1 = t1->GetEntries();
   cout << "nEvt1 = " << nEvt1 << endl;

   for (Int_t evt1 = 0; evt1 < nEvt1; evt1++) {

     t1->GetEntry(evt1);

     if (et > 30.) {

       if (fabs(eta) < 1.4791) {

         if(!barPass(e, sie, hoe, eca, hca, eop, chi, det, dph, tki)) continue;

         if (type > 0) {

           fillHist(sie1b, sie, e, et, weight);
           fillHist(hoe1b, hoe, e, et, weight);
           fillHist(eca1b, eca, e, et, weight);
           fillHist(hca1b, hca, e, et, weight);
           fillHist(eop1b, eop, e, et, weight);
           fillHist(chi1b, chi, e, et, weight);
           fillHist(det1b, det, e, et, weight);
           fillHist(dph1b, dph, e, et, weight);
           fillHist(tki1b, tki, e, et, weight);

         }

         if (type == -1) {

           fillHist(sie2b, sie, e, et, weight);
           fillHist(hoe2b, hoe, e, et, weight);
           fillHist(eca2b, eca, e, et, weight);
           fillHist(hca2b, hca, e, et, weight);
           fillHist(eop2b, eop, e, et, weight);
           fillHist(chi2b, chi, e, et, weight);
           fillHist(det2b, det, e, et, weight);
           fillHist(dph2b, dph, e, et, weight);
           fillHist(tki2b, tki, e, et, weight);

         }

       }

       else if ((fabs(eta) >= 1.4791) && (fabs(eta) < 2.1)) {

         if(!endPass(e, sie, hoe, eca, hca, eop, chi, det, dph, tki)) continue;

         if (type > 0) {

           fillHist(sie1e, sie, e, et, weight);
           fillHist(hoe1e, hoe, e, et, weight);
           fillHist(eca1e, eca, e, et, weight);
           fillHist(hca1e, hca, e, et, weight);
           fillHist(eop1e, eop, e, et, weight);
           fillHist(chi1e, chi, e, et, weight);
           fillHist(det1e, det, e, et, weight);
           fillHist(dph1e, dph, e, et, weight);
           fillHist(tki1e, tki, e, et, weight);

         }

         if (type == -1) {

           fillHist(sie2e, sie, e, et, weight);
           fillHist(hoe2e, hoe, e, et, weight);
           fillHist(eca2e, eca, e, et, weight);
           fillHist(hca2e, hca, e, et, weight);
           fillHist(eop2e, eop, e, et, weight);
           fillHist(chi2e, chi, e, et, weight);
           fillHist(det2e, det, e, et, weight);
           fillHist(dph2e, dph, e, et, weight);
           fillHist(tki2e, tki, e, et, weight);

         }
       }

       else continue;

     }

     else continue;

   }

   // -------------------------------------------------- //

   sie1b->Scale(1 / sie1b->Integral()); sie1e->Scale(1 / sie1e->Integral());
   sie2b->Scale(1 / sie2b->Integral()); sie2e->Scale(1 / sie2e->Integral());

   hoe1b->Scale(1 / hoe1b->Integral()); hoe1e->Scale(1 / hoe1e->Integral());
   hoe2b->Scale(1 / hoe2b->Integral()); hoe2e->Scale(1 / hoe2e->Integral());

   eca1b->Scale(1 / eca1b->Integral()); eca1e->Scale(1 / eca1e->Integral());
   eca2b->Scale(1 / eca2b->Integral()); eca2e->Scale(1 / eca2e->Integral());

   hca1b->Scale(1 / hca1b->Integral()); hca1e->Scale(1 / hca1e->Integral());
   hca2b->Scale(1 / hca2b->Integral()); hca2e->Scale(1 / hca2e->Integral());

   eop1b->Scale(1 / eop1b->Integral()); eop1e->Scale(1 / eop1e->Integral());
   eop2b->Scale(1 / eop2b->Integral()); eop2e->Scale(1 / eop2e->Integral());

   chi1b->Scale(1 / chi1b->Integral()); chi1e->Scale(1 / chi1e->Integral());
   chi2b->Scale(1 / chi2b->Integral()); chi2e->Scale(1 / chi2e->Integral());

   det1b->Scale(1 / det1b->Integral()); det1e->Scale(1 / det1e->Integral());
   det2b->Scale(1 / det2b->Integral()); det2e->Scale(1 / det2e->Integral());

   dph1b->Scale(1 / dph1b->Integral()); dph1e->Scale(1 / dph1e->Integral());
   dph2b->Scale(1 / dph2b->Integral()); dph2e->Scale(1 / dph2e->Integral());

   tki1b->Scale(1 / tki1b->Integral()); tki1e->Scale(1 / tki1e->Integral());
   tki2b->Scale(1 / tki2b->Integral()); tki2e->Scale(1 / tki2e->Integral());

   // -------------------------------------------------- //

   static const Int_t nStep_b = sieb_nBin + 1, nStep_e = siee_nBin + 1;
   Double_t sStep_b = (sieb_max - sieb_min) / sieb_nBin, sStep_e = (siee_max - siee_min) / siee_nBin;

   // Array size must be the same as bin + 1
   Double_t eff_xb[nStep_b], eff_y1b[nStep_b], eff_y2b[nStep_b];
   Double_t eff_xe[nStep_e], eff_y1e[nStep_e], eff_y2e[nStep_e];
   Double_t std_xb[nStep_b], std_xe[nStep_e], std_yb[nStep_b], std_ye[nStep_e];

   std::cout << "Barrel" << "\n" << "Cut" << "\t" << "Eff bkg" << "\t" << "Eff sig" << std::endl;

   for (Int_t p = 0; p < nStep_b + 1; p++) {

     eff_xb[p] = (p * sStep_b) + sieb_min;
     eff_y1b[p] = effCalc(p, sie1b);
     eff_y2b[p] = effCalc(p, sie2b);

     std_xb[p] = cut_b;
     if (p == 0) std_yb[p] = 1.05;
     else if (p == nStep_b - 1) std_yb[p] = 0.;
     else std_yb[p] = (1. - ((Double_t) (p + 1) / (Double_t) nStep_b));

     std::cout << std::setprecision(4) << std::fixed << eff_xb[p] << "\t" << std::setprecision(3) << eff_y1b[p] * 100. << "\t" << eff_y2b[p] * 100. << std::endl;

   }

   std::cout << "\n" << "Endcap" << "\n" << "Cut" << "\t" << "Eff bkg" << "\t" << "Eff sig" << std::endl;

   for (Int_t q = 0; q < nStep_e + 1; q++) {

     eff_xe[q] = (q * sStep_e) + siee_min;
     eff_y1e[q] = effCalc(q, sie1e);
     eff_y2e[q] = effCalc(q, sie2e);

     std_xe[q] = cut_e;
     if (q == 0) std_ye[q] = 1.05;
     else if (q == nStep_e - 1) std_ye[q] = 0.;
     else std_ye[q] = (1. - ((Double_t) (q + 1)  / (Double_t) nStep_e));

     std::cout << std::setprecision(4) << std::fixed <<  eff_xe[q] << "\t" << std::setprecision(3) << eff_y1e[q] * 100. << "\t" << eff_y2e[q] * 100. << std::endl;

   }

   std::cout << std::endl;

   // -------------------------------------------------- //

   TGraph* eff1b = new TGraph(nStep_b, eff_xb, eff_y1b);
   eff1b->SetLineColor(kRed + 1);
   eff1b->SetLineWidth(3);
   eff1b->SetMinimum(0.);
   eff1b->SetMaximum(1.05);

   TGraph* eff1e = new TGraph(nStep_e, eff_xe, eff_y1e);
   eff1e->SetLineColor(kRed + 1);
   eff1e->SetLineWidth(3);
   eff1e->SetMinimum(0.);
   eff1e->SetMaximum(1.05);

   TGraph* eff2b = new TGraph(nStep_b, eff_xb, eff_y2b);
   eff2b->SetLineColor(kAzure + 1);
   eff2b->SetLineWidth(3);
   eff2b->SetMinimum(0.);
   eff2b->SetMaximum(1.05);
   eff2b->SetTitle(("Barrel " + varTitle + " Eff.").c_str());
   eff2b->GetXaxis()->SetTitle("Cut");
   eff2b->GetYaxis()->SetTitle("Efficiency");

   TGraph* eff2e = new TGraph(nStep_e, eff_xe, eff_y2e);
   eff2e->SetLineColor(kAzure + 1);
   eff2e->SetLineWidth(3);
   eff2e->SetMinimum(0.);
   eff2e->SetMaximum(1.05);
   eff2e->SetTitle(("Endcap " + varTitle + " Eff.").c_str());
   eff2e->GetXaxis()->SetTitle("Cut");
   eff2e->GetYaxis()->SetTitle("Efficiency");

   TGraph* stdb = new TGraph(nStep_b, std_xb, std_yb);
   stdb->SetLineColor(kBlack);
   stdb->SetLineWidth(3);

   TGraph* stde = new TGraph(nStep_e, std_xe, std_ye);
   stde->SetLineColor(kBlack);
   stde->SetLineWidth(3);

   // -------------------------------------------------- //

   string const outDir = inDir + "img_rankFlow/";

   c01->cd();
   if (drawLog) c01->SetLogy();
   sie2b->Draw();
   sie1b->Draw("same");
   //c01->SaveAs((outDir + varName + "_hist_bar.png").c_str());

   c02->cd();
   if (drawLog) c02->SetLogy();
   sie2e->Draw();
   sie1e->Draw("same");
   //c02->SaveAs((outDir + varName + "_hist_end.png").c_str());

   cg1->cd();
   cg1->SetGrid();
   eff2b->Draw("AL");
   eff1b->Draw("same");
   stdb->Draw("same");
   //cg1->SaveAs((outDir + varName + "_eff_bar.png").c_str());

   cg2->cd();
   cg2->SetGrid();
   eff2e->Draw("AL");
   eff1e->Draw("same");
   stde->Draw("same");
   //cg2->SaveAs((outDir + varName + "_eff_end.png").c_str());

   // -------------------------------------------------- //

   c01->Close(); c02->Close();
   cg1->Close(); cg2->Close();
   
}

int main() {

  mvaPlot();
  return 0;

}



