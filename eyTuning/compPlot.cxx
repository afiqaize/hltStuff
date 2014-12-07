// Adapted from plotter code for plot comparing purposes
// To be used with the output of Matteo's plotDistr
// Drawn inside out, 5 4 3 2 1
// Use with ROOT: .x code.cxx+

#include "iostream"
#include <iomanip>
#include <TH1.h>
#include <TCanvas.h>
#include "stdlib.h"
#include <TStyle.h>
#include <TLegend.h>
#include <TH1D.h>
#include <TFile.h>
#include <string.h>
#include <TTree.h>

using namespace std;

// Subprogram for the tuning
// One for each region

Bool_t barPass(Float_t e_cut_b, Float_t et_cut_b, 
               Float_t sie_cut_b, Float_t hoe_cut_b, Float_t eca_cut_b, Float_t hca_cut_b, 
               Float_t eop_cut_b, Int_t mih_cut_b, Int_t hit_cut_b, Float_t chi_cut_b, 
               Float_t det_cut_b, Float_t dph_cut_b, Float_t tki_cut_b) {

  Bool_t barOk = false;

  // All barrel cuts

  if (sie_cut_b <= 0.011) {
    if ((hoe_cut_b / e_cut_b) <= 0.07) {
      if ((eca_cut_b / et_cut_b) <= 0.21) {
        if ((hca_cut_b / et_cut_b) <= 1.0) {
          if (eop_cut_b <= 1.0) {
            if (mih_cut_b <= 99) {
              if (hit_cut_b > 0) {
                if (chi_cut_b <= 99.0) { // CAREFUL HERE
                  if (det_cut_b <= 1.0) {
                    if (dph_cut_b <= 1.0) {
                      if ((tki_cut_b / et_cut_b) <= 1.0)
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
  }

  return barOk;

}

Bool_t endPass(Float_t e_cut_e, Float_t et_cut_e, 
               Float_t sie_cut_e, Float_t hoe_cut_e, Float_t eca_cut_e, Float_t hca_cut_e, 
               Float_t eop_cut_e, Int_t mih_cut_e, Int_t hit_cut_e, Float_t chi_cut_e, 
               Float_t det_cut_e, Float_t dph_cut_e, Float_t tki_cut_e) {

  Bool_t endOk = false;

  // All endcap cuts

  if (sie_cut_e <= 0.031) {
    if ((hoe_cut_e / e_cut_e) <= 0.11) {
      if ((eca_cut_e / et_cut_e) <= 0.14) {
        if ((hca_cut_e / et_cut_e) <= 1.0) {
          if (eop_cut_e <= 1.0) {
            if (mih_cut_e <= 99) {
              if (hit_cut_e > 0) {
                if (chi_cut_e <= 99.0) { // CAREFUL HERE
                  if (det_cut_e <= 1.0) {
                    if (dph_cut_e <= 1.0) {
                      if ((tki_cut_e / et_cut_e) <= 1.0)
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
  }

  return endOk;

}

// Subprogram to fill
// Play around with the arguments here
void fillHist(TH1D* varHist, Float_t varVal, Float_t eVal, Float_t etVal) {

  // Some useless things to make ROOT shut up
  eVal = eVal;
  etVal = etVal;

  varHist->Fill(varVal / etVal);
  varHist->SetLineWidth(3);

}

void compPlot() {

   //gStyle->SetOptStat(0);

   // Everything to tinker with should be here, other than the cuts

   string varName = "hca_var", varTitle = "HcalIso";

   /***
       List of varTitles, varNames for easy Latexing

       #sigma_{i#etai#eta} sie
       H/E hoe
       EcalIso eca
       HcalIso hca
       1/E - 1/P eop
       Missing Hits mih
       Valid Hits hit
       Track #chi^{2} chi
       #Delta#eta det
       #Delta#phi dph
       TrackIso tki
   ***/

   Bool_t drawLog = false;

   Int_t sieb_nBin = 20, siee_nBin = 60;
   Double_t sieb_max = .02, siee_max = .06;
   Double_t sieb_min = 0., siee_min = 0.;

   /*/ For E
   Int_t hoeb_nBin = 120, hoee_nBin = 120;
   Double_t hoeb_max = 600., hoee_max = 600.;
   Double_t hoeb_min = 0., hoee_min = 0.;*/

   // For H
   Int_t hoeb_nBin = 40, hoee_nBin = 30;
   Double_t hoeb_max = 20., hoee_max = 30.;
   Double_t hoeb_min = 0., hoee_min = 0.;

   /*/ For H/E
   Int_t hoeb_nBin = 20, hoee_nBin = 30;
   Double_t hoeb_max = .2, hoee_max = .3;
   Double_t hoeb_min = 0., hoee_min = 0.;*/ 

   Int_t ecab_nBin = 80, ecae_nBin = 80;
   Double_t ecab_max = .6, ecae_max = .6;
   Double_t ecab_min = -.2, ecae_min = -.2;

   Int_t hcab_nBin = 80, hcae_nBin = 80;
   Double_t hcab_max = .6, hcae_max = .6;
   Double_t hcab_min = -.2, hcae_min = -.2;

   Int_t eopb_nBin = 40, eope_nBin = 40;
   Double_t eopb_max = .02, eope_max = .02;
   Double_t eopb_min = 0., eope_min = 0.;

   Int_t mihb_nBin = 4, mihe_nBin = 6;
   Double_t mihb_max = 3., mihe_max = 5.;
   Double_t mihb_min = -1., mihe_min = -1.;

   Int_t chib_nBin = 70, chie_nBin = 70;
   Double_t chib_max = 7., chie_max = 7.;
   Double_t chib_min = 0., chie_min = 0.;

   Int_t hitb_nBin = 25, hite_nBin = 25;
   Double_t hitb_max = 25., hite_max = 25.;
   Double_t hitb_min = 0., hite_min = 0.;

   Int_t detb_nBin = 50, dete_nBin = 50;
   Double_t detb_max = 0.05, dete_max = 0.05;
   Double_t detb_min = 0., dete_min = 0.;

   Int_t dphb_nBin = 75, dphe_nBin = 150;
   Double_t dphb_max = 0.15, dphe_max = 0.15;
   Double_t dphb_min = 0., dphe_min = 0.;

   Int_t tkib_nBin = 50, tkie_nBin = 50;
   Double_t tkib_max = 0.5, tkie_max = 0.5;
   Double_t tkib_min = 0., tkie_min = 0.;

   string const inDir = "/home/ieeya/Downloads/HLT_Val/Part2_OpenHLT/OpenHLT/logs/run02/ttbar_skim/e_72X/prodVar/";

   TFile *f1 = new TFile((inDir + "qcdem_calo_e01_h01_plots.root").c_str());
   TFile *f2 = new TFile((inDir + "qcdem_hiso02_plots.root").c_str());
   TFile *f3 = new TFile((inDir + "qcdem_hiso03_plots.root").c_str());
   TFile *f4 = new TFile((inDir + "qcdem_hiso05_plots.root").c_str());
   TFile *f5 = new TFile((inDir + "qcdem_hiso10_plots.root").c_str());

   // -------------------------------------------------- //

   TCanvas *c01 = new TCanvas("c01", "c01", 200, 10, 1600, 900);
   TCanvas *c02 = new TCanvas("c02", "c02", 200, 10, 1600, 900);

   // -------------------------------------------------- //

   TTree *t1 = (TTree *) f1->Get("tree");

   TH1D* sie1b = new TH1D("sie1b", ("Barrel " + varTitle + " Distr.").c_str(), sieb_nBin, sieb_min, sieb_max);
   TH1D* sie1e = new TH1D("sie1e", ("Endcap " + varTitle + " Distr.").c_str(), siee_nBin, siee_min, siee_max);
   sie1b->SetMarkerColor(kRed + 1);
   sie1b->SetLineColor(kRed + 1);
   sie1e->SetMarkerColor(kRed + 1);
   sie1e->SetLineColor(kRed + 1);

   TH1D* hoe1b = new TH1D("hoe1b", ("Barrel " + varTitle + " Distr.").c_str(), hoeb_nBin, hoeb_min, hoeb_max);
   TH1D* hoe1e = new TH1D("hoe1e", ("Endcap " + varTitle + " Distr.").c_str(), hoee_nBin, hoee_min, hoee_max);
   hoe1b->SetMarkerColor(kRed + 1);
   hoe1b->SetLineColor(kRed + 1);
   hoe1e->SetMarkerColor(kRed + 1);
   hoe1e->SetLineColor(kRed + 1);

   TH1D* eca1b = new TH1D("eca1b", ("Barrel " + varTitle + " Distr.").c_str(), ecab_nBin, ecab_min, ecab_max);
   TH1D* eca1e = new TH1D("eca1e", ("Endcap " + varTitle + " Distr.").c_str(), ecae_nBin, ecae_min, ecae_max);
   eca1b->SetMarkerColor(kRed + 1);
   eca1b->SetLineColor(kRed + 1);
   eca1e->SetMarkerColor(kRed + 1);
   eca1e->SetLineColor(kRed + 1);

   TH1D* hca1b = new TH1D("hca1b", ("Barrel " + varTitle + " Distr.").c_str(), hcab_nBin, hcab_min, hcab_max);
   TH1D* hca1e = new TH1D("hca1e", ("Endcap " + varTitle + " Distr.").c_str(), hcae_nBin, hcae_min, hcae_max);
   hca1b->SetMarkerColor(kRed + 1);
   hca1b->SetLineColor(kRed + 1);
   hca1e->SetMarkerColor(kRed + 1);
   hca1e->SetLineColor(kRed + 1);

   TH1D* eop1b = new TH1D("eop1b", ("Barrel " + varTitle + " Distr.").c_str(), eopb_nBin, eopb_min, eopb_max);
   TH1D* eop1e = new TH1D("eop1e", ("Endcap " + varTitle + " Distr.").c_str(), eope_nBin, eope_min, eope_max);
   eop1b->SetMarkerColor(kRed + 1);
   eop1b->SetLineColor(kRed + 1);
   eop1e->SetMarkerColor(kRed + 1);
   eop1e->SetLineColor(kRed + 1);

   TH1D* mih1b = new TH1D("mih1b", ("Barrel " + varTitle + " Distr.").c_str(), mihb_nBin, mihb_min, mihb_max);
   TH1D* mih1e = new TH1D("mih1e", ("Endcap " + varTitle + " Distr.").c_str(), mihe_nBin, mihe_min, mihe_max);
   mih1b->SetMarkerColor(kRed + 1);
   mih1b->SetLineColor(kRed + 1);
   mih1e->SetMarkerColor(kRed + 1);
   mih1e->SetLineColor(kRed + 1);

   TH1D* chi1b = new TH1D("chi1b", ("Barrel " + varTitle + " Distr.").c_str(), chib_nBin, chib_min, chib_max);
   TH1D* chi1e = new TH1D("chi1e", ("Endcap " + varTitle + " Distr.").c_str(), chie_nBin, chie_min, chie_max);
   chi1b->SetMarkerColor(kRed + 1);
   chi1b->SetLineColor(kRed + 1);
   chi1e->SetMarkerColor(kRed + 1);
   chi1e->SetLineColor(kRed + 1);

   TH1D* hit1b = new TH1D("hit1b", ("Barrel " + varTitle + " Distr.").c_str(), hitb_nBin, hitb_min, hitb_max);
   TH1D* hit1e = new TH1D("hit1e", ("Endcap " + varTitle + " Distr.").c_str(), hite_nBin, hite_min, hite_max);
   hit1b->SetMarkerColor(kRed + 1);
   hit1b->SetLineColor(kRed + 1);
   hit1e->SetMarkerColor(kRed + 1);
   hit1e->SetLineColor(kRed + 1);

   TH1D* det1b = new TH1D("det1b", ("Barrel " + varTitle + " Distr.").c_str(), detb_nBin, detb_min, detb_max);
   TH1D* det1e = new TH1D("det1e", ("Endcap " + varTitle + " Distr.").c_str(), dete_nBin, dete_min, dete_max);
   det1b->SetMarkerColor(kRed + 1);
   det1b->SetLineColor(kRed + 1);
   det1e->SetMarkerColor(kRed + 1);
   det1e->SetLineColor(kRed + 1);

   TH1D* dph1b = new TH1D("dph1b", ("Barrel " + varTitle + " Distr.").c_str(), dphb_nBin, dphb_min, dphb_max);
   TH1D* dph1e = new TH1D("dph1e", ("Endcap " + varTitle + " Distr.").c_str(), dphe_nBin, dphe_min, dphe_max);
   dph1b->SetMarkerColor(kRed + 1);
   dph1b->SetLineColor(kRed + 1);
   dph1e->SetMarkerColor(kRed + 1);
   dph1e->SetLineColor(kRed + 1);

   TH1D* tki1b = new TH1D("tki1b", ("Barrel " + varTitle + " Distr.").c_str(), tkib_nBin, tkib_min, tkib_max);
   TH1D* tki1e = new TH1D("tki1e", ("Endcap " + varTitle + " Distr.").c_str(), tkie_nBin, tkie_min, tkie_max);
   tki1b->SetMarkerColor(kRed + 1);
   tki1b->SetLineColor(kRed + 1);
   tki1e->SetMarkerColor(kRed + 1);
   tki1e->SetLineColor(kRed + 1);

   Int_t pas1v;
   t1->SetBranchAddress("pass", &pas1v);
   Int_t npf1v;
   t1->SetBranchAddress("npf", &npf1v);
   Float_t et1v[10];
   t1->SetBranchAddress("etpf", et1v);
   Float_t e1v[10];
   t1->SetBranchAddress("epf", e1v);
   Float_t eta1v[10];
   t1->SetBranchAddress("etapf", eta1v);
   Float_t sie1v[10];
   t1->SetBranchAddress("sieiepf", sie1v);
   Float_t hoe1v[10];
   t1->SetBranchAddress("hoepf", hoe1v);
   Float_t eca1v[10];
   t1->SetBranchAddress("ecalpf", eca1v);
   Float_t hca1v[10];
   t1->SetBranchAddress("hcalpf", hca1v);
   Float_t eop1v[10];
   t1->SetBranchAddress("eoppf", eop1v);
   Int_t mih1v[10];
   t1->SetBranchAddress("mishitspf", mih1v);
   Int_t hit1v[10];
   t1->SetBranchAddress("hitspf", hit1v);
   Float_t chi1v[10];
   t1->SetBranchAddress("chi2pf", chi1v);
   Float_t det1v[10];
   t1->SetBranchAddress("detapf", det1v);
   Float_t dph1v[10];
   t1->SetBranchAddress("dphipf", dph1v);
   Float_t tki1v[10];
   t1->SetBranchAddress("tkisopf", tki1v);

   // -------------------------------------------------- //

   Int_t nEvt1 = t1->GetEntries();
   cout << "nEvt1 = " << nEvt1 << endl;

   for (Int_t evt1 = 0; evt1 < nEvt1; evt1++) {

     t1->GetEntry(evt1);

     if (pas1v != 1) continue;

     for (Int_t it1 = 0; it1 < npf1v; it1++) {

       if (et1v[it1] > 27.) {

         if (fabs(eta1v[it1]) < 1.4791) {

           if(!barPass(e1v[it1], et1v[it1], sie1v[it1], hoe1v[it1], eca1v[it1],
                       hca1v[it1], eop1v[it1], mih1v[it1], hit1v[it1],
                       chi1v[it1], det1v[it1], dph1v[it1], tki1v[it1])) continue;

           fillHist(sie1b, sie1v[it1], e1v[it1], et1v[it1]);
           fillHist(hoe1b, hoe1v[it1], e1v[it1], et1v[it1]);
           fillHist(eca1b, eca1v[it1], e1v[it1], et1v[it1]);
           fillHist(hca1b, hca1v[it1], e1v[it1], et1v[it1]);
           fillHist(eop1b, eop1v[it1], e1v[it1], et1v[it1]);
           fillHist(mih1b, Float_t (mih1v[it1]), e1v[it1], et1v[it1]);
           fillHist(hit1b, Float_t (hit1v[it1]), e1v[it1], et1v[it1]);
           fillHist(chi1b, chi1v[it1], e1v[it1], et1v[it1]);
           fillHist(det1b, det1v[it1], e1v[it1], et1v[it1]);
           fillHist(dph1b, dph1v[it1], e1v[it1], et1v[it1]);
           fillHist(tki1b, tki1v[it1], e1v[it1], et1v[it1]);

         }

         else if ((fabs(eta1v[it1]) >= 1.4791) && (fabs(eta1v[it1]) < 2.1)) {

           if(!endPass(e1v[it1], et1v[it1], sie1v[it1], hoe1v[it1], eca1v[it1],
                       hca1v[it1], eop1v[it1], mih1v[it1], hit1v[it1],
                       chi1v[it1], det1v[it1], dph1v[it1], tki1v[it1])) continue;

           fillHist(sie1e, sie1v[it1], e1v[it1], et1v[it1]);
           fillHist(hoe1e, hoe1v[it1], e1v[it1], et1v[it1]);
           fillHist(eca1e, eca1v[it1], e1v[it1], et1v[it1]);
           fillHist(hca1e, hca1v[it1], e1v[it1], et1v[it1]);
           fillHist(eop1e, eop1v[it1], e1v[it1], et1v[it1]);
           fillHist(mih1e, Float_t (mih1v[it1]), e1v[it1], et1v[it1]);
           fillHist(hit1e, Float_t (hit1v[it1]), e1v[it1], et1v[it1]);
           fillHist(chi1e, chi1v[it1], e1v[it1], et1v[it1]);
           fillHist(det1e, det1v[it1], e1v[it1], et1v[it1]);
           fillHist(dph1e, dph1v[it1], e1v[it1], et1v[it1]);
           fillHist(tki1e, tki1v[it1], e1v[it1], et1v[it1]);

         }

         else continue;

       }

       else continue;

     }
   }

   // -------------------------------------------------- //

   TTree *t2 = (TTree *) f2->Get("tree");

   TH1D* sie2b = new TH1D("sie2b", ("Barrel " + varTitle + " Distr.").c_str(), sieb_nBin, sieb_min, sieb_max);
   TH1D* sie2e = new TH1D("sie2e", ("Endcap " + varTitle + " Distr.").c_str(), siee_nBin, siee_min, siee_max);
   sie2b->SetMarkerColor(kBlue + 1);
   sie2b->SetLineColor(kBlue + 1);
   sie2e->SetMarkerColor(kBlue + 1);
   sie2e->SetLineColor(kBlue + 1);

   TH1D* hoe2b = new TH1D("hoe2b", ("Barrel " + varTitle + " Distr.").c_str(), hoeb_nBin, hoeb_min, hoeb_max);
   TH1D* hoe2e = new TH1D("hoe2e", ("Endcap " + varTitle + " Distr.").c_str(), hoee_nBin, hoee_min, hoee_max);
   hoe2b->SetMarkerColor(kBlue + 1);
   hoe2b->SetLineColor(kBlue + 1);
   hoe2e->SetMarkerColor(kBlue + 1);
   hoe2e->SetLineColor(kBlue + 1);

   TH1D* eca2b = new TH1D("eca2b", ("Barrel " + varTitle + " Distr.").c_str(), ecab_nBin, ecab_min, ecab_max);
   TH1D* eca2e = new TH1D("eca2e", ("Endcap " + varTitle + " Distr.").c_str(), ecae_nBin, ecae_min, ecae_max);
   eca2b->SetMarkerColor(kBlue + 1);
   eca2b->SetLineColor(kBlue + 1);
   eca2e->SetMarkerColor(kBlue + 1);
   eca2e->SetLineColor(kBlue + 1);

   TH1D* hca2b = new TH1D("hca2b", ("Barrel " + varTitle + " Distr.").c_str(), hcab_nBin, hcab_min, hcab_max);
   TH1D* hca2e = new TH1D("hca2e", ("Endcap " + varTitle + " Distr.").c_str(), hcae_nBin, hcae_min, hcae_max);
   hca2b->SetMarkerColor(kBlue + 1);
   hca2b->SetLineColor(kBlue + 1);
   hca2e->SetMarkerColor(kBlue + 1);
   hca2e->SetLineColor(kBlue + 1);

   TH1D* eop2b = new TH1D("eop2b", ("Barrel " + varTitle + " Distr.").c_str(), eopb_nBin, eopb_min, eopb_max);
   TH1D* eop2e = new TH1D("eop2e", ("Endcap " + varTitle + " Distr.").c_str(), eope_nBin, eope_min, eope_max);
   eop2b->SetMarkerColor(kBlue + 1);
   eop2b->SetLineColor(kBlue + 1);
   eop2e->SetMarkerColor(kBlue + 1);
   eop2e->SetLineColor(kBlue + 1);

   TH1D* mih2b = new TH1D("mih2b", ("Barrel " + varTitle + " Distr.").c_str(), mihb_nBin, mihb_min, mihb_max);
   TH1D* mih2e = new TH1D("mih2e", ("Endcap " + varTitle + " Distr.").c_str(), mihe_nBin, mihe_min, mihe_max);
   mih2b->SetMarkerColor(kBlue + 1);
   mih2b->SetLineColor(kBlue + 1);
   mih2e->SetMarkerColor(kBlue + 1);
   mih2e->SetLineColor(kBlue + 1);

   TH1D* chi2b = new TH1D("chi2b", ("Barrel " + varTitle + " Distr.").c_str(), chib_nBin, chib_min, chib_max);
   TH1D* chi2e = new TH1D("chi2e", ("Endcap " + varTitle + " Distr.").c_str(), chie_nBin, chie_min, chie_max);
   chi2b->SetMarkerColor(kBlue + 1);
   chi2b->SetLineColor(kBlue + 1);
   chi2e->SetMarkerColor(kBlue + 1);
   chi2e->SetLineColor(kBlue + 1);

   TH1D* hit2b = new TH1D("hit2b", ("Barrel " + varTitle + " Distr.").c_str(), hitb_nBin, hitb_min, hitb_max);
   TH1D* hit2e = new TH1D("hit2e", ("Endcap " + varTitle + " Distr.").c_str(), hite_nBin, hite_min, hite_max);
   hit2b->SetMarkerColor(kBlue + 1);
   hit2b->SetLineColor(kBlue + 1);
   hit2e->SetMarkerColor(kBlue + 1);
   hit2e->SetLineColor(kBlue + 1);

   TH1D* det2b = new TH1D("det2b", ("Barrel " + varTitle + " Distr.").c_str(), detb_nBin, detb_min, detb_max);
   TH1D* det2e = new TH1D("det2e", ("Endcap " + varTitle + " Distr.").c_str(), dete_nBin, dete_min, dete_max);
   det2b->SetMarkerColor(kBlue + 1);
   det2b->SetLineColor(kBlue + 1);
   det2e->SetMarkerColor(kBlue + 1);
   det2e->SetLineColor(kBlue + 1);

   TH1D* dph2b = new TH1D("dph2b", ("Barrel " + varTitle + " Distr.").c_str(), dphb_nBin, dphb_min, dphb_max);
   TH1D* dph2e = new TH1D("dph2e", ("Endcap " + varTitle + " Distr.").c_str(), dphe_nBin, dphe_min, dphe_max);
   dph2b->SetMarkerColor(kBlue + 1);
   dph2b->SetLineColor(kBlue + 1);
   dph2e->SetMarkerColor(kBlue + 1);
   dph2e->SetLineColor(kBlue + 1);

   TH1D* tki2b = new TH1D("tki2b", ("Barrel " + varTitle + " Distr.").c_str(), tkib_nBin, tkib_min, tkib_max);
   TH1D* tki2e = new TH1D("tki2e", ("Endcap " + varTitle + " Distr.").c_str(), tkie_nBin, tkie_min, tkie_max);
   tki2b->SetMarkerColor(kBlue + 1);
   tki2b->SetLineColor(kBlue + 1);
   tki2e->SetMarkerColor(kBlue + 1);
   tki2e->SetLineColor(kBlue + 1);

   Int_t pas2v;
   t2->SetBranchAddress("pass", &pas2v);
   Int_t npf2v;
   t2->SetBranchAddress("npf", &npf2v);
   Float_t et2v[10];
   t2->SetBranchAddress("etpf", et2v);
   Float_t e2v[10];
   t2->SetBranchAddress("epf", e2v);
   Float_t eta2v[10];
   t2->SetBranchAddress("etapf", eta2v);
   Float_t sie2v[10];
   t2->SetBranchAddress("sieiepf", sie2v);
   Float_t hoe2v[10];
   t2->SetBranchAddress("hoepf", hoe2v);
   Float_t eca2v[10];
   t2->SetBranchAddress("ecalpf", eca2v);
   Float_t hca2v[10];
   t2->SetBranchAddress("hcalpf", hca2v);
   Float_t eop2v[10];
   t2->SetBranchAddress("eoppf", eop2v);
   Int_t mih2v[10];
   t2->SetBranchAddress("mishitspf", mih2v);
   Int_t hit2v[10];
   t2->SetBranchAddress("hitspf", hit2v);
   Float_t chi2v[10];
   t2->SetBranchAddress("chi2pf", chi2v);
   Float_t det2v[10];
   t2->SetBranchAddress("detapf", det2v);
   Float_t dph2v[10];
   t2->SetBranchAddress("dphipf", dph2v);
   Float_t tki2v[10];
   t2->SetBranchAddress("tkisopf", tki2v);

   // -------------------------------------------------- //

   Int_t nEvt2 = t2->GetEntries();
   cout << "nEvt2 = " << nEvt2 << "\n" << endl;

   for (Int_t evt2 = 0; evt2 < nEvt2; evt2++) {

     t2->GetEntry(evt2);

     if (pas2v != 1) continue;

     for (Int_t it2 = 0; it2 < npf2v; it2++) {

       if (et2v[it2] > 27.) {

         if (fabs(eta2v[it2]) < 1.4791) {

           if(!barPass(e2v[it2], et2v[it2], sie2v[it2], hoe2v[it2], eca2v[it2],
                       hca2v[it2], eop2v[it2], mih2v[it2], hit2v[it2],
                       chi2v[it2], det2v[it2], dph2v[it2], tki2v[it2])) continue;

           fillHist(sie2b, sie2v[it2], e2v[it2], et2v[it2]);
           fillHist(hoe2b, hoe2v[it2], e2v[it2], et2v[it2]);
           fillHist(eca2b, eca2v[it2], e2v[it2], et2v[it2]);
           fillHist(hca2b, hca2v[it2], e2v[it2], et2v[it2]);
           fillHist(eop2b, eop2v[it2], e2v[it2], et2v[it2]);
           fillHist(mih2b, Float_t (mih2v[it2]), e2v[it2], et2v[it2]);
           fillHist(hit2b, Float_t (hit2v[it2]), e2v[it2], et2v[it2]);
           fillHist(chi2b, chi2v[it2], e2v[it2], et2v[it2]);
           fillHist(det2b, det2v[it2], e2v[it2], et2v[it2]);
           fillHist(dph2b, dph2v[it2], e2v[it2], et2v[it2]);
           fillHist(tki2b, tki2v[it2], e2v[it2], et2v[it2]);

         }

         else if ((fabs(eta2v[it2]) >= 1.4791) && (fabs(eta2v[it2]) < 2.1)) {

           if(!endPass(e2v[it2], et2v[it2], sie2v[it2], hoe2v[it2], eca2v[it2],
                       hca2v[it2], eop2v[it2], mih2v[it2], hit2v[it2],
                       chi2v[it2], det2v[it2], dph2v[it2], tki2v[it2])) continue;

           fillHist(sie2e, sie2v[it2], e2v[it2], et2v[it2]);
           fillHist(hoe2e, hoe2v[it2], e2v[it2], et2v[it2]);
           fillHist(eca2e, eca2v[it2], e2v[it2], et2v[it2]);
           fillHist(hca2e, hca2v[it2], e2v[it2], et2v[it2]);
           fillHist(eop2e, eop2v[it2], e2v[it2], et2v[it2]);
           fillHist(mih2e, Float_t (mih2v[it2]), e2v[it2], et2v[it2]);
           fillHist(hit2e, Float_t (hit2v[it2]), e2v[it2], et2v[it2]);
           fillHist(chi2e, chi2v[it2], e2v[it2], et2v[it2]);
           fillHist(det2e, det2v[it2], e2v[it2], et2v[it2]);
           fillHist(dph2e, dph2v[it2], e2v[it2], et2v[it2]);
           fillHist(tki2e, tki2v[it2], e2v[it2], et2v[it2]);

         }

         else continue;

       }

       else continue;

     }
   }

   // -------------------------------------------------- //

   TTree *t3 = (TTree *) f3->Get("tree");

   TH1D* sie3b = new TH1D("sie3b", ("Barrel " + varTitle + " Distr.").c_str(), sieb_nBin, sieb_min, sieb_max);
   TH1D* sie3e = new TH1D("sie3e", ("Endcap " + varTitle + " Distr.").c_str(), siee_nBin, siee_min, siee_max);
   sie3b->SetMarkerColor(kMagenta + 1);
   sie3b->SetLineColor(kMagenta + 1);
   sie3e->SetMarkerColor(kMagenta + 1);
   sie3e->SetLineColor(kMagenta + 1);

   TH1D* hoe3b = new TH1D("hoe3b", ("Barrel " + varTitle + " Distr.").c_str(), hoeb_nBin, hoeb_min, hoeb_max);
   TH1D* hoe3e = new TH1D("hoe3e", ("Endcap " + varTitle + " Distr.").c_str(), hoee_nBin, hoee_min, hoee_max);
   hoe3b->SetMarkerColor(kMagenta + 1);
   hoe3b->SetLineColor(kMagenta + 1);
   hoe3e->SetMarkerColor(kMagenta + 1);
   hoe3e->SetLineColor(kMagenta + 1);

   TH1D* eca3b = new TH1D("eca3b", ("Barrel " + varTitle + " Distr.").c_str(), ecab_nBin, ecab_min, ecab_max);
   TH1D* eca3e = new TH1D("eca3e", ("Endcap " + varTitle + " Distr.").c_str(), ecae_nBin, ecae_min, ecae_max);
   eca3b->SetMarkerColor(kMagenta + 1);
   eca3b->SetLineColor(kMagenta + 1);
   eca3e->SetMarkerColor(kMagenta + 1);
   eca3e->SetLineColor(kMagenta + 1);

   TH1D* hca3b = new TH1D("hca3b", ("Barrel " + varTitle + " Distr.").c_str(), hcab_nBin, hcab_min, hcab_max);
   TH1D* hca3e = new TH1D("hca3e", ("Endcap " + varTitle + " Distr.").c_str(), hcae_nBin, hcae_min, hcae_max);
   hca3b->SetMarkerColor(kMagenta + 1);
   hca3b->SetLineColor(kMagenta + 1);
   hca3e->SetMarkerColor(kMagenta + 1);
   hca3e->SetLineColor(kMagenta + 1);

   TH1D* eop3b = new TH1D("eop3b", ("Barrel " + varTitle + " Distr.").c_str(), eopb_nBin, eopb_min, eopb_max);
   TH1D* eop3e = new TH1D("eop3e", ("Endcap " + varTitle + " Distr.").c_str(), eope_nBin, eope_min, eope_max);
   eop3b->SetMarkerColor(kMagenta + 1);
   eop3b->SetLineColor(kMagenta + 1);
   eop3e->SetMarkerColor(kMagenta + 1);
   eop3e->SetLineColor(kMagenta + 1);

   TH1D* mih3b = new TH1D("mih3b", ("Barrel " + varTitle + " Distr.").c_str(), mihb_nBin, mihb_min, mihb_max);
   TH1D* mih3e = new TH1D("mih3e", ("Endcap " + varTitle + " Distr.").c_str(), mihe_nBin, mihe_min, mihe_max);
   mih3b->SetMarkerColor(kMagenta + 1);
   mih3b->SetLineColor(kMagenta + 1);
   mih3e->SetMarkerColor(kMagenta + 1);
   mih3e->SetLineColor(kMagenta + 1);

   TH1D* chi3b = new TH1D("chi3b", ("Barrel " + varTitle + " Distr.").c_str(), chib_nBin, chib_min, chib_max);
   TH1D* chi3e = new TH1D("chi3e", ("Endcap " + varTitle + " Distr.").c_str(), chie_nBin, chie_min, chie_max);
   chi3b->SetMarkerColor(kMagenta + 1);
   chi3b->SetLineColor(kMagenta + 1);
   chi3e->SetMarkerColor(kMagenta + 1);
   chi3e->SetLineColor(kMagenta + 1);

   TH1D* hit3b = new TH1D("hit3b", ("Barrel " + varTitle + " Distr.").c_str(), hitb_nBin, hitb_min, hitb_max);
   TH1D* hit3e = new TH1D("hit3e", ("Endcap " + varTitle + " Distr.").c_str(), hite_nBin, hite_min, hite_max);
   hit3b->SetMarkerColor(kMagenta + 1);
   hit3b->SetLineColor(kMagenta + 1);
   hit3e->SetMarkerColor(kMagenta + 1);
   hit3e->SetLineColor(kMagenta + 1);

   TH1D* det3b = new TH1D("det3b", ("Barrel " + varTitle + " Distr.").c_str(), detb_nBin, detb_min, detb_max);
   TH1D* det3e = new TH1D("det3e", ("Endcap " + varTitle + " Distr.").c_str(), dete_nBin, dete_min, dete_max);
   det3b->SetMarkerColor(kMagenta + 1);
   det3b->SetLineColor(kMagenta + 1);
   det3e->SetMarkerColor(kMagenta + 1);
   det3e->SetLineColor(kMagenta + 1);

   TH1D* dph3b = new TH1D("dph3b", ("Barrel " + varTitle + " Distr.").c_str(), dphb_nBin, dphb_min, dphb_max);
   TH1D* dph3e = new TH1D("dph3e", ("Endcap " + varTitle + " Distr.").c_str(), dphe_nBin, dphe_min, dphe_max);
   dph3b->SetMarkerColor(kMagenta + 1);
   dph3b->SetLineColor(kMagenta + 1);
   dph3e->SetMarkerColor(kMagenta + 1);
   dph3e->SetLineColor(kMagenta + 1);

   TH1D* tki3b = new TH1D("tki3b", ("Barrel " + varTitle + " Distr.").c_str(), tkib_nBin, tkib_min, tkib_max);
   TH1D* tki3e = new TH1D("tki3e", ("Endcap " + varTitle + " Distr.").c_str(), tkie_nBin, tkie_min, tkie_max);
   tki3b->SetMarkerColor(kMagenta + 1);
   tki3b->SetLineColor(kMagenta + 1);
   tki3e->SetMarkerColor(kMagenta + 1);
   tki3e->SetLineColor(kMagenta + 1);

   Int_t pas3v;
   t3->SetBranchAddress("pass", &pas3v);
   Int_t npf3v;
   t3->SetBranchAddress("npf", &npf3v);
   Float_t et3v[10];
   t3->SetBranchAddress("etpf", et3v);
   Float_t e3v[10];
   t3->SetBranchAddress("epf", e3v);
   Float_t eta3v[10];
   t3->SetBranchAddress("etapf", eta3v);
   Float_t sie3v[10];
   t3->SetBranchAddress("sieiepf", sie3v);
   Float_t hoe3v[10];
   t3->SetBranchAddress("hoepf", hoe3v);
   Float_t eca3v[10];
   t3->SetBranchAddress("ecalpf", eca3v);
   Float_t hca3v[10];
   t3->SetBranchAddress("hcalpf", hca3v);
   Float_t eop3v[10];
   t3->SetBranchAddress("eoppf", eop3v);
   Int_t mih3v[10];
   t3->SetBranchAddress("mishitspf", mih3v);
   Int_t hit3v[10];
   t3->SetBranchAddress("hitspf", hit3v);
   Float_t chi3v[10];
   t3->SetBranchAddress("chi2pf", chi3v);
   Float_t det3v[10];
   t3->SetBranchAddress("detapf", det3v);
   Float_t dph3v[10];
   t3->SetBranchAddress("dphipf", dph3v);
   Float_t tki3v[10];
   t3->SetBranchAddress("tkisopf", tki3v);

   // -------------------------------------------------- //

   Int_t nEvt3 = t3->GetEntries();
   cout << "nEvt3 = " << nEvt3 << endl;

   for (Int_t evt3 = 0; evt3 < nEvt3; evt3++) {

     t3->GetEntry(evt3);

     if (pas3v != 1) continue;

     for (Int_t it3 = 0; it3 < npf3v; it3++) {

       if (et3v[it3] > 27.) {

         if (fabs(eta3v[it3]) < 1.4791) {

           if(!barPass(e3v[it3], et3v[it3], sie3v[it3], hoe3v[it3], eca3v[it3],
                       hca3v[it3], eop3v[it3], mih3v[it3], hit3v[it3],
                       chi3v[it3], det3v[it3], dph3v[it3], tki3v[it3])) continue;

           fillHist(sie3b, sie3v[it3], e3v[it3], et3v[it3]);
           fillHist(hoe3b, hoe3v[it3], e3v[it3], et3v[it3]);
           fillHist(eca3b, eca3v[it3], e3v[it3], et3v[it3]);
           fillHist(hca3b, hca3v[it3], e3v[it3], et3v[it3]);
           fillHist(eop3b, eop3v[it3], e3v[it3], et3v[it3]);
           fillHist(mih3b, Float_t (mih3v[it3]), e3v[it3], et3v[it3]);
           fillHist(hit3b, Float_t (hit3v[it3]), e3v[it3], et3v[it3]);
           fillHist(chi3b, chi3v[it3], e3v[it3], et3v[it3]);
           fillHist(det3b, det3v[it3], e3v[it3], et3v[it3]);
           fillHist(dph3b, dph3v[it3], e3v[it3], et3v[it3]);
           fillHist(tki3b, tki3v[it3], e3v[it3], et3v[it3]);

         }

         else if ((fabs(eta3v[it3]) >= 1.4791) && (fabs(eta3v[it3]) < 2.1)) {

           if(!endPass(e3v[it3], et3v[it3], sie3v[it3], hoe3v[it3], eca3v[it3],
                       hca3v[it3], eop3v[it3], mih3v[it3], hit3v[it3],
                       chi3v[it3], det3v[it3], dph3v[it3], tki3v[it3])) continue;

           fillHist(sie3e, sie3v[it3], e3v[it3], et3v[it3]);
           fillHist(hoe3e, hoe3v[it3], e3v[it3], et3v[it3]);
           fillHist(eca3e, eca3v[it3], e3v[it3], et3v[it3]);
           fillHist(hca3e, hca3v[it3], e3v[it3], et3v[it3]);
           fillHist(eop3e, eop3v[it3], e3v[it3], et3v[it3]);
           fillHist(mih3e, Float_t (mih3v[it3]), e3v[it3], et3v[it3]);
           fillHist(hit3e, Float_t (hit3v[it3]), e3v[it3], et3v[it3]);
           fillHist(chi3e, chi3v[it3], e3v[it3], et3v[it3]);
           fillHist(det3e, det3v[it3], e3v[it3], et3v[it3]);
           fillHist(dph3e, dph3v[it3], e3v[it3], et3v[it3]);
           fillHist(tki3e, tki3v[it3], e3v[it3], et3v[it3]);

         }

         else continue;

       }

       else continue;

     }
   }

   // -------------------------------------------------- //

   TTree *t4 = (TTree *) f4->Get("tree");

   TH1D* sie4b = new TH1D("sie4b", ("Barrel " + varTitle + " Distr.").c_str(), sieb_nBin, sieb_min, sieb_max);
   TH1D* sie4e = new TH1D("sie4e", ("Endcap " + varTitle + " Distr.").c_str(), siee_nBin, siee_min, siee_max);
   sie4b->SetMarkerColor(kYellow + 1);
   sie4b->SetLineColor(kYellow + 1);
   sie4e->SetMarkerColor(kYellow + 1);
   sie4e->SetLineColor(kYellow + 1);

   TH1D* hoe4b = new TH1D("hoe4b", ("Barrel " + varTitle + " Distr.").c_str(), hoeb_nBin, hoeb_min, hoeb_max);
   TH1D* hoe4e = new TH1D("hoe4e", ("Endcap " + varTitle + " Distr.").c_str(), hoee_nBin, hoee_min, hoee_max);
   hoe4b->SetMarkerColor(kYellow + 1);
   hoe4b->SetLineColor(kYellow + 1);
   hoe4e->SetMarkerColor(kYellow + 1);
   hoe4e->SetLineColor(kYellow + 1);

   TH1D* eca4b = new TH1D("eca4b", ("Barrel " + varTitle + " Distr.").c_str(), ecab_nBin, ecab_min, ecab_max);
   TH1D* eca4e = new TH1D("eca4e", ("Endcap " + varTitle + " Distr.").c_str(), ecae_nBin, ecae_min, ecae_max);
   eca4b->SetMarkerColor(kYellow + 1);
   eca4b->SetLineColor(kYellow + 1);
   eca4e->SetMarkerColor(kYellow + 1);
   eca4e->SetLineColor(kYellow + 1);

   TH1D* hca4b = new TH1D("hca4b", ("Barrel " + varTitle + " Distr.").c_str(), hcab_nBin, hcab_min, hcab_max);
   TH1D* hca4e = new TH1D("hca4e", ("Endcap " + varTitle + " Distr.").c_str(), hcae_nBin, hcae_min, hcae_max);
   hca4b->SetMarkerColor(kYellow + 1);
   hca4b->SetLineColor(kYellow + 1);
   hca4e->SetMarkerColor(kYellow + 1);
   hca4e->SetLineColor(kYellow + 1);

   TH1D* eop4b = new TH1D("eop4b", ("Barrel " + varTitle + " Distr.").c_str(), eopb_nBin, eopb_min, eopb_max);
   TH1D* eop4e = new TH1D("eop4e", ("Endcap " + varTitle + " Distr.").c_str(), eope_nBin, eope_min, eope_max);
   eop4b->SetMarkerColor(kYellow + 1);
   eop4b->SetLineColor(kYellow + 1);
   eop4e->SetMarkerColor(kYellow + 1);
   eop4e->SetLineColor(kYellow + 1);

   TH1D* mih4b = new TH1D("mih4b", ("Barrel " + varTitle + " Distr.").c_str(), mihb_nBin, mihb_min, mihb_max);
   TH1D* mih4e = new TH1D("mih4e", ("Endcap " + varTitle + " Distr.").c_str(), mihe_nBin, mihe_min, mihe_max);
   mih4b->SetMarkerColor(kYellow + 1);
   mih4b->SetLineColor(kYellow + 1);
   mih4e->SetMarkerColor(kYellow + 1);
   mih4e->SetLineColor(kYellow + 1);

   TH1D* chi4b = new TH1D("chi4b", ("Barrel " + varTitle + " Distr.").c_str(), chib_nBin, chib_min, chib_max);
   TH1D* chi4e = new TH1D("chi4e", ("Endcap " + varTitle + " Distr.").c_str(), chie_nBin, chie_min, chie_max);
   chi4b->SetMarkerColor(kYellow + 1);
   chi4b->SetLineColor(kYellow + 1);
   chi4e->SetMarkerColor(kYellow + 1);
   chi4e->SetLineColor(kYellow + 1);

   TH1D* hit4b = new TH1D("hit4b", ("Barrel " + varTitle + " Distr.").c_str(), hitb_nBin, hitb_min, hitb_max);
   TH1D* hit4e = new TH1D("hit4e", ("Endcap " + varTitle + " Distr.").c_str(), hite_nBin, hite_min, hite_max);
   hit4b->SetMarkerColor(kYellow + 1);
   hit4b->SetLineColor(kYellow + 1);
   hit4e->SetMarkerColor(kYellow + 1);
   hit4e->SetLineColor(kYellow + 1);

   TH1D* det4b = new TH1D("det4b", ("Barrel " + varTitle + " Distr.").c_str(), detb_nBin, detb_min, detb_max);
   TH1D* det4e = new TH1D("det4e", ("Endcap " + varTitle + " Distr.").c_str(), dete_nBin, dete_min, dete_max);
   det4b->SetMarkerColor(kYellow + 1);
   det4b->SetLineColor(kYellow + 1);
   det4e->SetMarkerColor(kYellow + 1);
   det4e->SetLineColor(kYellow + 1);

   TH1D* dph4b = new TH1D("dph4b", ("Barrel " + varTitle + " Distr.").c_str(), dphb_nBin, dphb_min, dphb_max);
   TH1D* dph4e = new TH1D("dph4e", ("Endcap " + varTitle + " Distr.").c_str(), dphe_nBin, dphe_min, dphe_max);
   dph4b->SetMarkerColor(kYellow + 1);
   dph4b->SetLineColor(kYellow + 1);
   dph4e->SetMarkerColor(kYellow + 1);
   dph4e->SetLineColor(kYellow + 1);

   TH1D* tki4b = new TH1D("tki4b", ("Barrel " + varTitle + " Distr.").c_str(), tkib_nBin, tkib_min, tkib_max);
   TH1D* tki4e = new TH1D("tki4e", ("Endcap " + varTitle + " Distr.").c_str(), tkie_nBin, tkie_min, tkie_max);
   tki4b->SetMarkerColor(kYellow + 1);
   tki4b->SetLineColor(kYellow + 1);
   tki4e->SetMarkerColor(kYellow + 1);
   tki4e->SetLineColor(kYellow + 1);

   Int_t pas4v;
   t4->SetBranchAddress("pass", &pas4v);
   Int_t npf4v;
   t4->SetBranchAddress("npf", &npf4v);
   Float_t et4v[10];
   t4->SetBranchAddress("etpf", et4v);
   Float_t e4v[10];
   t4->SetBranchAddress("epf", e4v);
   Float_t eta4v[10];
   t4->SetBranchAddress("etapf", eta4v);
   Float_t sie4v[10];
   t4->SetBranchAddress("sieiepf", sie4v);
   Float_t hoe4v[10];
   t4->SetBranchAddress("hoepf", hoe4v);
   Float_t eca4v[10];
   t4->SetBranchAddress("ecalpf", eca4v);
   Float_t hca4v[10];
   t4->SetBranchAddress("hcalpf", hca4v);
   Float_t eop4v[10];
   t4->SetBranchAddress("eoppf", eop4v);
   Int_t mih4v[10];
   t4->SetBranchAddress("mishitspf", mih4v);
   Int_t hit4v[10];
   t4->SetBranchAddress("hitspf", hit4v);
   Float_t chi4v[10];
   t4->SetBranchAddress("chi2pf", chi4v);
   Float_t det4v[10];
   t4->SetBranchAddress("detapf", det4v);
   Float_t dph4v[10];
   t4->SetBranchAddress("dphipf", dph4v);
   Float_t tki4v[10];
   t4->SetBranchAddress("tkisopf", tki4v);

   // -------------------------------------------------- //

   Int_t nEvt4 = t4->GetEntries();
   cout << "nEvt4 = " << nEvt4 << "\n" << endl;

   for (Int_t evt4 = 0; evt4 < nEvt4; evt4++) {

     t4->GetEntry(evt4);

     if (pas4v != 1) continue;

     for (Int_t it4 = 0; it4 < npf4v; it4++) {

       if (et4v[it4] > 27.) {

         if (fabs(eta4v[it4]) < 1.4791) {

           if(!barPass(e4v[it4], et4v[it4], sie4v[it4], hoe4v[it4], eca4v[it4],
                       hca4v[it4], eop4v[it4], mih4v[it4], hit4v[it4],
                       chi4v[it4], det4v[it4], dph4v[it4], tki4v[it4])) continue;

           fillHist(sie4b, sie4v[it4], e4v[it4], et4v[it4]);
           fillHist(hoe4b, hoe4v[it4], e4v[it4], et4v[it4]);
           fillHist(eca4b, eca4v[it4], e4v[it4], et4v[it4]);
           fillHist(hca4b, hca4v[it4], e4v[it4], et4v[it4]);
           fillHist(eop4b, eop4v[it4], e4v[it4], et4v[it4]);
           fillHist(mih4b, Float_t (mih4v[it4]), e4v[it4], et4v[it4]);
           fillHist(hit4b, Float_t (hit4v[it4]), e4v[it4], et4v[it4]);
           fillHist(chi4b, chi4v[it4], e4v[it4], et4v[it4]);
           fillHist(det4b, det4v[it4], e4v[it4], et4v[it4]);
           fillHist(dph4b, dph4v[it4], e4v[it4], et4v[it4]);
           fillHist(tki4b, tki4v[it4], e4v[it4], et4v[it4]);

         }

         else if ((fabs(eta4v[it4]) >= 1.4791) && (fabs(eta4v[it4]) < 2.1)) {

           if(!endPass(e4v[it4], et4v[it4], sie4v[it4], hoe4v[it4], eca4v[it4],
                       hca4v[it4], eop4v[it4], mih4v[it4], hit4v[it4],
                       chi4v[it4], det4v[it4], dph4v[it4], tki4v[it4])) continue;

           fillHist(sie4e, sie4v[it4], e4v[it4], et4v[it4]);
           fillHist(hoe4e, hoe4v[it4], e4v[it4], et4v[it4]);
           fillHist(eca4e, eca4v[it4], e4v[it4], et4v[it4]);
           fillHist(hca4e, hca4v[it4], e4v[it4], et4v[it4]);
           fillHist(eop4e, eop4v[it4], e4v[it4], et4v[it4]);
           fillHist(mih4e, Float_t (mih4v[it4]), e4v[it4], et4v[it4]);
           fillHist(hit4e, Float_t (hit4v[it4]), e4v[it4], et4v[it4]);
           fillHist(chi4e, chi4v[it4], e4v[it4], et4v[it4]);
           fillHist(det4e, det4v[it4], e4v[it4], et4v[it4]);
           fillHist(dph4e, dph4v[it4], e4v[it4], et4v[it4]);
           fillHist(tki4e, tki4v[it4], e4v[it4], et4v[it4]);

         }

         else continue;

       }

       else continue;

     }
   }

   // -------------------------------------------------- //

   TTree *t5 = (TTree *) f5->Get("tree");

   TH1D* sie5b = new TH1D("sie5b", ("Barrel " + varTitle + " Distr.").c_str(), sieb_nBin, sieb_min, sieb_max);
   TH1D* sie5e = new TH1D("sie5e", ("Endcap " + varTitle + " Distr.").c_str(), siee_nBin, siee_min, siee_max);
   sie5b->SetMarkerColor(kGreen + 1);
   sie5b->SetLineColor(kGreen + 1);
   sie5e->SetMarkerColor(kGreen + 1);
   sie5e->SetLineColor(kGreen + 1);

   TH1D* hoe5b = new TH1D("hoe5b", ("Barrel " + varTitle + " Distr.").c_str(), hoeb_nBin, hoeb_min, hoeb_max);
   TH1D* hoe5e = new TH1D("hoe5e", ("Endcap " + varTitle + " Distr.").c_str(), hoee_nBin, hoee_min, hoee_max);
   hoe5b->SetMarkerColor(kGreen + 1);
   hoe5b->SetLineColor(kGreen + 1);
   hoe5e->SetMarkerColor(kGreen + 1);
   hoe5e->SetLineColor(kGreen + 1);

   TH1D* eca5b = new TH1D("eca5b", ("Barrel " + varTitle + " Distr.").c_str(), ecab_nBin, ecab_min, ecab_max);
   TH1D* eca5e = new TH1D("eca5e", ("Endcap " + varTitle + " Distr.").c_str(), ecae_nBin, ecae_min, ecae_max);
   eca5b->SetMarkerColor(kGreen + 1);
   eca5b->SetLineColor(kGreen + 1);
   eca5e->SetMarkerColor(kGreen + 1);
   eca5e->SetLineColor(kGreen + 1);

   TH1D* hca5b = new TH1D("hca5b", ("Barrel " + varTitle + " Distr.").c_str(), hcab_nBin, hcab_min, hcab_max);
   TH1D* hca5e = new TH1D("hca5e", ("Endcap " + varTitle + " Distr.").c_str(), hcae_nBin, hcae_min, hcae_max);
   hca5b->SetMarkerColor(kGreen + 1);
   hca5b->SetLineColor(kGreen + 1);
   hca5e->SetMarkerColor(kGreen + 1);
   hca5e->SetLineColor(kGreen + 1);

   TH1D* eop5b = new TH1D("eop5b", ("Barrel " + varTitle + " Distr.").c_str(), eopb_nBin, eopb_min, eopb_max);
   TH1D* eop5e = new TH1D("eop5e", ("Endcap " + varTitle + " Distr.").c_str(), eope_nBin, eope_min, eope_max);
   eop5b->SetMarkerColor(kGreen + 1);
   eop5b->SetLineColor(kGreen + 1);
   eop5e->SetMarkerColor(kGreen + 1);
   eop5e->SetLineColor(kGreen + 1);

   TH1D* mih5b = new TH1D("mih5b", ("Barrel " + varTitle + " Distr.").c_str(), mihb_nBin, mihb_min, mihb_max);
   TH1D* mih5e = new TH1D("mih5e", ("Endcap " + varTitle + " Distr.").c_str(), mihe_nBin, mihe_min, mihe_max);
   mih5b->SetMarkerColor(kGreen + 1);
   mih5b->SetLineColor(kGreen + 1);
   mih5e->SetMarkerColor(kGreen + 1);
   mih5e->SetLineColor(kGreen + 1);

   TH1D* chi5b = new TH1D("chi5b", ("Barrel " + varTitle + " Distr.").c_str(), chib_nBin, chib_min, chib_max);
   TH1D* chi5e = new TH1D("chi5e", ("Endcap " + varTitle + " Distr.").c_str(), chie_nBin, chie_min, chie_max);
   chi5b->SetMarkerColor(kGreen + 1);
   chi5b->SetLineColor(kGreen + 1);
   chi5e->SetMarkerColor(kGreen + 1);
   chi5e->SetLineColor(kGreen + 1);

   TH1D* hit5b = new TH1D("hit5b", ("Barrel " + varTitle + " Distr.").c_str(), hitb_nBin, hitb_min, hitb_max);
   TH1D* hit5e = new TH1D("hit5e", ("Endcap " + varTitle + " Distr.").c_str(), hite_nBin, hite_min, hite_max);
   hit5b->SetMarkerColor(kGreen + 1);
   hit5b->SetLineColor(kGreen + 1);
   hit5e->SetMarkerColor(kGreen + 1);
   hit5e->SetLineColor(kGreen + 1);

   TH1D* det5b = new TH1D("det5b", ("Barrel " + varTitle + " Distr.").c_str(), detb_nBin, detb_min, detb_max);
   TH1D* det5e = new TH1D("det5e", ("Endcap " + varTitle + " Distr.").c_str(), dete_nBin, dete_min, dete_max);
   det5b->SetMarkerColor(kGreen + 1);
   det5b->SetLineColor(kGreen + 1);
   det5e->SetMarkerColor(kGreen + 1);
   det5e->SetLineColor(kGreen + 1);

   TH1D* dph5b = new TH1D("dph5b", ("Barrel " + varTitle + " Distr.").c_str(), dphb_nBin, dphb_min, dphb_max);
   TH1D* dph5e = new TH1D("dph5e", ("Endcap " + varTitle + " Distr.").c_str(), dphe_nBin, dphe_min, dphe_max);
   dph5b->SetMarkerColor(kGreen + 1);
   dph5b->SetLineColor(kGreen + 1);
   dph5e->SetMarkerColor(kGreen + 1);
   dph5e->SetLineColor(kGreen + 1);

   TH1D* tki5b = new TH1D("tki5b", ("Barrel " + varTitle + " Distr.").c_str(), tkib_nBin, tkib_min, tkib_max);
   TH1D* tki5e = new TH1D("tki5e", ("Endcap " + varTitle + " Distr.").c_str(), tkie_nBin, tkie_min, tkie_max);
   tki5b->SetMarkerColor(kGreen + 1);
   tki5b->SetLineColor(kGreen + 1);
   tki5e->SetMarkerColor(kGreen + 1);
   tki5e->SetLineColor(kGreen + 1);

   Int_t pas5v;
   t5->SetBranchAddress("pass", &pas5v);
   Int_t npf5v;
   t5->SetBranchAddress("npf", &npf5v);
   Float_t et5v[10];
   t5->SetBranchAddress("etpf", et5v);
   Float_t e5v[10];
   t5->SetBranchAddress("epf", e5v);
   Float_t eta5v[10];
   t5->SetBranchAddress("etapf", eta5v);
   Float_t sie5v[10];
   t5->SetBranchAddress("sieiepf", sie5v);
   Float_t hoe5v[10];
   t5->SetBranchAddress("hoepf", hoe5v);
   Float_t eca5v[10];
   t5->SetBranchAddress("ecalpf", eca5v);
   Float_t hca5v[10];
   t5->SetBranchAddress("hcalpf", hca5v);
   Float_t eop5v[10];
   t5->SetBranchAddress("eoppf", eop5v);
   Int_t mih5v[10];
   t5->SetBranchAddress("mishitspf", mih5v);
   Int_t hit5v[10];
   t5->SetBranchAddress("hitspf", hit5v);
   Float_t chi5v[10];
   t5->SetBranchAddress("chi2pf", chi5v);
   Float_t det5v[10];
   t5->SetBranchAddress("detapf", det5v);
   Float_t dph5v[10];
   t5->SetBranchAddress("dphipf", dph5v);
   Float_t tki5v[10];
   t5->SetBranchAddress("tkisopf", tki5v);

   // -------------------------------------------------- //

   Int_t nEvt5 = t5->GetEntries();
   cout << "nEvt5 = " << nEvt5 << "\n" << endl;

   for (Int_t evt5 = 0; evt5 < nEvt5; evt5++) {

     t5->GetEntry(evt5);

     if (pas5v != 1) continue;

     for (Int_t it5 = 0; it5 < npf5v; it5++) {

       if (et5v[it5] > 27.) {

         if (fabs(eta5v[it5]) < 1.4791) {

           if(!barPass(e5v[it5], et5v[it5], sie5v[it5], hoe5v[it5], eca5v[it5],
                       hca5v[it5], eop5v[it5], mih5v[it5], hit5v[it5],
                       chi5v[it5], det5v[it5], dph5v[it5], tki5v[it5])) continue;

           fillHist(sie5b, sie5v[it5], e5v[it5], et5v[it5]);
           fillHist(hoe5b, hoe5v[it5], e5v[it5], et5v[it5]);
           fillHist(eca5b, eca5v[it5], e5v[it5], et5v[it5]);
           fillHist(hca5b, hca5v[it5], e5v[it5], et5v[it5]);
           fillHist(eop5b, eop5v[it5], e5v[it5], et5v[it5]);
           fillHist(mih5b, Float_t (mih5v[it5]), e5v[it5], et5v[it5]);
           fillHist(hit5b, Float_t (hit5v[it5]), e5v[it5], et5v[it5]);
           fillHist(chi5b, chi5v[it5], e5v[it5], et5v[it5]);
           fillHist(det5b, det5v[it5], e5v[it5], et5v[it5]);
           fillHist(dph5b, dph5v[it5], e5v[it5], et5v[it5]);
           fillHist(tki5b, tki5v[it5], e5v[it5], et5v[it5]);

         }

         else if ((fabs(eta5v[it5]) >= 1.4791) && (fabs(eta5v[it5]) < 2.1)) {

           if(!endPass(e5v[it5], et5v[it5], sie5v[it5], hoe5v[it5], eca5v[it5],
                       hca5v[it5], eop5v[it5], mih5v[it5], hit5v[it5],
                       chi5v[it5], det5v[it5], dph5v[it5], tki5v[it5])) continue;

           fillHist(sie5e, sie5v[it5], e5v[it5], et5v[it5]);
           fillHist(hoe5e, hoe5v[it5], e5v[it5], et5v[it5]);
           fillHist(eca5e, eca5v[it5], e5v[it5], et5v[it5]);
           fillHist(hca5e, hca5v[it5], e5v[it5], et5v[it5]);
           fillHist(eop5e, eop5v[it5], e5v[it5], et5v[it5]);
           fillHist(mih5e, Float_t (mih5v[it5]), e5v[it5], et5v[it5]);
           fillHist(hit5e, Float_t (hit5v[it5]), e5v[it5], et5v[it5]);
           fillHist(chi5e, chi5v[it5], e5v[it5], et5v[it5]);
           fillHist(det5e, det5v[it5], e5v[it5], et5v[it5]);
           fillHist(dph5e, dph5v[it5], e5v[it5], et5v[it5]);
           fillHist(tki5e, tki5v[it5], e5v[it5], et5v[it5]);

         }

         else continue;

       }

       else continue;

     }
   }

   // -------------------------------------------------- //

   sie1b->Scale(1 / sie1b->Integral()); sie1e->Scale(1 / sie1e->Integral());
   sie2b->Scale(1 / sie2b->Integral()); sie2e->Scale(1 / sie2e->Integral());
   sie3b->Scale(1 / sie3b->Integral()); sie3e->Scale(1 / sie3e->Integral());
   sie4b->Scale(1 / sie4b->Integral()); sie4e->Scale(1 / sie4e->Integral());
   sie5b->Scale(1 / sie5b->Integral()); sie5e->Scale(1 / sie5e->Integral());

   hoe1b->Scale(1 / hoe1b->Integral()); hoe1e->Scale(1 / hoe1e->Integral());
   hoe2b->Scale(1 / hoe2b->Integral()); hoe2e->Scale(1 / hoe2e->Integral());
   hoe3b->Scale(1 / hoe3b->Integral()); hoe3e->Scale(1 / hoe3e->Integral());
   hoe4b->Scale(1 / hoe4b->Integral()); hoe4e->Scale(1 / hoe4e->Integral());
   hoe5b->Scale(1 / hoe5b->Integral()); hoe5e->Scale(1 / hoe5e->Integral());

   eca1b->Scale(1 / eca1b->Integral()); eca1e->Scale(1 / eca1e->Integral());
   eca2b->Scale(1 / eca2b->Integral()); eca2e->Scale(1 / eca2e->Integral());
   eca3b->Scale(1 / eca3b->Integral()); eca3e->Scale(1 / eca3e->Integral());
   eca4b->Scale(1 / eca4b->Integral()); eca4e->Scale(1 / eca4e->Integral());
   eca5b->Scale(1 / eca5b->Integral()); eca5e->Scale(1 / eca5e->Integral());

   hca1b->Scale(1 / hca1b->Integral()); hca1e->Scale(1 / hca1e->Integral());
   hca2b->Scale(1 / hca2b->Integral()); hca2e->Scale(1 / hca2e->Integral());
   hca3b->Scale(1 / hca3b->Integral()); hca3e->Scale(1 / hca3e->Integral());
   hca4b->Scale(1 / hca4b->Integral()); hca4e->Scale(1 / hca4e->Integral());
   hca5b->Scale(1 / hca5b->Integral()); hca5e->Scale(1 / hca5e->Integral());

   eop1b->Scale(1 / eop1b->Integral()); eop1e->Scale(1 / eop1e->Integral());
   eop2b->Scale(1 / eop2b->Integral()); eop2e->Scale(1 / eop2e->Integral());
   eop3b->Scale(1 / eop3b->Integral()); eop3e->Scale(1 / eop3e->Integral());
   eop4b->Scale(1 / eop4b->Integral()); eop4e->Scale(1 / eop4e->Integral());
   eop5b->Scale(1 / eop5b->Integral()); eop5e->Scale(1 / eop5e->Integral());

   mih1b->Scale(1 / mih1b->Integral()); mih1e->Scale(1 / mih1e->Integral());
   mih2b->Scale(1 / mih2b->Integral()); mih2e->Scale(1 / mih2e->Integral());
   mih3b->Scale(1 / mih3b->Integral()); mih3e->Scale(1 / mih3e->Integral());
   mih4b->Scale(1 / mih4b->Integral()); mih4e->Scale(1 / mih4e->Integral());
   mih5b->Scale(1 / mih5b->Integral()); mih5e->Scale(1 / mih5e->Integral());

   hit1b->Scale(1 / hit1b->Integral()); hit1e->Scale(1 / hit1e->Integral());
   hit2b->Scale(1 / hit2b->Integral()); hit2e->Scale(1 / hit2e->Integral());
   hit3b->Scale(1 / hit3b->Integral()); hit3e->Scale(1 / hit3e->Integral());
   hit4b->Scale(1 / hit4b->Integral()); hit4e->Scale(1 / hit4e->Integral());
   hit5b->Scale(1 / hit5b->Integral()); hit5e->Scale(1 / hit5e->Integral());

   chi1b->Scale(1 / chi1b->Integral()); chi1e->Scale(1 / chi1e->Integral());
   chi2b->Scale(1 / chi2b->Integral()); chi2e->Scale(1 / chi2e->Integral());
   chi3b->Scale(1 / chi3b->Integral()); chi3e->Scale(1 / chi3e->Integral());
   chi4b->Scale(1 / chi4b->Integral()); chi4e->Scale(1 / chi4e->Integral());
   chi5b->Scale(1 / chi5b->Integral()); chi5e->Scale(1 / chi5e->Integral());

   det1b->Scale(1 / det1b->Integral()); det1e->Scale(1 / det1e->Integral());
   det2b->Scale(1 / det2b->Integral()); det2e->Scale(1 / det2e->Integral());
   det3b->Scale(1 / det3b->Integral()); det3e->Scale(1 / det3e->Integral());
   det4b->Scale(1 / det4b->Integral()); det4e->Scale(1 / det4e->Integral());
   det5b->Scale(1 / det5b->Integral()); det5e->Scale(1 / det5e->Integral());

   dph1b->Scale(1 / dph1b->Integral()); dph1e->Scale(1 / dph1e->Integral());
   dph2b->Scale(1 / dph2b->Integral()); dph2e->Scale(1 / dph2e->Integral());
   dph3b->Scale(1 / dph3b->Integral()); dph3e->Scale(1 / dph3e->Integral());
   dph4b->Scale(1 / dph4b->Integral()); dph4e->Scale(1 / dph4e->Integral());
   dph5b->Scale(1 / dph5b->Integral()); dph5e->Scale(1 / dph5e->Integral());

   tki1b->Scale(1 / tki1b->Integral()); tki1e->Scale(1 / tki1e->Integral());
   tki2b->Scale(1 / tki2b->Integral()); tki2e->Scale(1 / tki2e->Integral());
   tki3b->Scale(1 / tki3b->Integral()); tki3e->Scale(1 / tki3e->Integral());
   tki4b->Scale(1 / tki4b->Integral()); tki4e->Scale(1 / tki4e->Integral());
   tki5b->Scale(1 / tki5b->Integral()); tki5e->Scale(1 / tki5e->Integral());

   // -------------------------------------------------- //

   string const outDir = inDir + "img/";

   c01->cd();
   if (drawLog) c01->SetLogy();
   hca5b->Draw();
   hca4b->Draw("same");
   hca3b->Draw("same");
   hca2b->Draw("same");
   hca1b->Draw("same");

   TLegend *leg01 = new TLegend(.71, .70, .99, .98);
   leg01->SetHeader("Multiplier");
   leg01->AddEntry(hca1b, "1. * Thr.");
   leg01->AddEntry(hca2b, "2. * Thr.");
   leg01->AddEntry(hca3b, "3. * Thr.");
   leg01->AddEntry(hca4b, "5. * Thr.");
   leg01->AddEntry(hca5b, "10. * Thr.");
   leg01->Draw();

   c01->SaveAs((outDir + varName + "_hist_bar.png").c_str());
   c01->Close();

   c02->cd();
   if (drawLog) c02->SetLogy();
   hca5e->Draw();
   hca4e->Draw("same");
   hca3e->Draw("same");
   hca2e->Draw("same");
   hca1e->Draw("same");

   TLegend *leg02 = new TLegend(.71, .70, .99, .98);
   leg02->SetHeader("Multiplier");
   leg02->AddEntry(hca1e, "1. * Thr.");
   leg02->AddEntry(hca2e, "2. * Thr.");
   leg02->AddEntry(hca3e, "3. * Thr.");
   leg02->AddEntry(hca4e, "5. * Thr.");
   leg02->AddEntry(hca5e, "10. * Thr.");
   leg02->Draw();

   c02->SaveAs((outDir + varName + "_hist_end.png").c_str());
   c02->Close();

   // -------------------------------------------------- //
   
}

int main() {

  compPlot();
  return 0;

}



