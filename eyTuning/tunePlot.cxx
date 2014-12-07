// Adapted from plotter code for tuning purposes
// To be used with the output of Matteo's plotDistr
// Standard notation; 1 for background 2 for signal
// Run in ROOT: .x code.cxx+

#include "iostream"
#include <iomanip>
#include <TH1.h>
#include <TCanvas.h>
#include "stdlib.h"
#include <TStyle.h>
#include <TH1D.h>
#include <TGraph.h>
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

  if (sie_cut_b <= 1.0) {
    if ((hoe_cut_b - (e_cut_b / 100.)) <= 4.0) {
      if ((eca_cut_b / et_cut_b) <= 0.21) {
        if ((hca_cut_b / et_cut_b) <= 0.11) {
          if (eop_cut_b <= 0.032) {
            if (mih_cut_b <= 99) { // CAREFUL HERE
              if (hit_cut_b > 0) {
                if (chi_cut_b <= 3.0) { // CAREFUL HERE
                  if (det_cut_b <= 0.0035) {
                    if (dph_cut_b <= 0.021) {
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

  if (sie_cut_e <= 1.0) {
    if ((hoe_cut_e - (e_cut_e / 100.)) <= 13.0) {
      if ((eca_cut_e / et_cut_e) <= 0.14) {
        if ((hca_cut_e / et_cut_e) <= 0.21) {
          if (eop_cut_e <= 0.032) {
            if (mih_cut_e <= 0) { // CAREFUL HERE
              if (hit_cut_e > 0) {
                if (chi_cut_e <= 2.8) { // CAREFUL HERE
                  if (det_cut_e <= 0.0065) {
                    if (dph_cut_e <= 0.035) {
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

}

/*void fillVars(TH1D* varHist, Float_t varVal1, Float_t varVal2, Float_t eVal, Float_t etVal) {

  // Some useless things to make ROOT shut up
  eVal = eVal;
  etVal = etVal;

  varHist->Fill(varVal1 + (eVal / 100.));

  }*/

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

void tunePlot() {

   //gStyle->SetOptStat(0);

   // Everything to tinker with should be here, other than the cuts

   Double_t cut_b = 0.05, cut_e = 0.05;

   string varName = "tki", varTitle = "TrkIso";

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

   Bool_t drawLog = true;

   Int_t xxxb_nBin = 450, xxxe_nBin = 600;
   Double_t xxxb_max = 40., xxxe_max = 55.;
   Double_t xxxb_min = -5., xxxe_min = -5.;

   Int_t sieb_nBin = 40, siee_nBin = 120;
   Double_t sieb_max = .02, siee_max = .06;
   Double_t sieb_min = 0., siee_min = 0.;

   /*/ For E
   Int_t hoeb_nBin = 120, hoee_nBin = 120;
   Double_t hoeb_max = 600., hoee_max = 600.;
   Double_t hoeb_min = 0., hoee_min = 0.;*/

   // For H
   Int_t hoeb_nBin = 225, hoee_nBin = 300;
   Double_t hoeb_max = 40., hoee_max = 55.;
   Double_t hoeb_min = -5., hoee_min = -5.;

   /*/ For H/E
   Int_t hoeb_nBin = 20, hoee_nBin = 30;
   Double_t hoeb_max = .2, hoee_max = .3;
   Double_t hoeb_min = 0., hoee_min = 0.;*/

   Int_t ecab_nBin = 120, ecae_nBin = 120;
   Double_t ecab_max = 1., ecae_max = 1.;
   Double_t ecab_min = -.2, ecae_min = -.2;

   Int_t hcab_nBin = 90, hcae_nBin = 110;
   Double_t hcab_max = .7, hcae_max = .9;
   Double_t hcab_min = -.2, hcae_min = -.2;

   Int_t eopb_nBin = 325, eope_nBin = 175;
   Double_t eopb_max = .65, eope_max = .35;
   Double_t eopb_min = 0., eope_min = 0.;

   Int_t mihb_nBin = 4, mihe_nBin = 6;
   Double_t mihb_max = 3., mihe_max = 5.;
   Double_t mihb_min = -1., mihe_min = -1.;

   Int_t chib_nBin = 100, chie_nBin = 70;
   Double_t chib_max = 10., chie_max = 7.;
   Double_t chib_min = 0., chie_min = 0.;

   Int_t hitb_nBin = 25, hite_nBin = 25;
   Double_t hitb_max = 25., hite_max = 25.;
   Double_t hitb_min = 0., hite_min = 0.;

   Int_t detb_nBin = 100, dete_nBin = 100;
   Double_t detb_max = 0.05, dete_max = 0.05;
   Double_t detb_min = 0., dete_min = 0.;

   Int_t dphb_nBin = 150, dphe_nBin = 150;
   Double_t dphb_max = 0.15, dphe_max = 0.15;
   Double_t dphb_min = 0., dphe_min = 0.;

   Int_t tkib_nBin = 100, tkie_nBin = 100;
   Double_t tkib_max = 0.5, tkie_max = 0.5;
   Double_t tkib_min = 0., tkie_min = 0.;

   string const inDir = "/home/ieeya/Downloads/HLT_Val/Part2_OpenHLT/OpenHLT/logs/run02/ttbar_skim/e_720/";

   TFile *f1 = new TFile((inDir + "qcd_cut1p0_plots.root").c_str());
   TFile *f2 = new TFile((inDir + "wev_cut1p0_plots.root").c_str());

   // -------------------------------------------------- //

   TCanvas *c01 = new TCanvas("c01", "c01", 200, 10, 1600, 900);
   TCanvas *c02 = new TCanvas("c02", "c02", 200, 10, 1600, 900);
   TCanvas *cg1 = new TCanvas("cg1", "cg1", 200, 10, 1600, 900);
   TCanvas *cg2 = new TCanvas("cg2", "cg2", 200, 10, 1600, 900);

   // -------------------------------------------------- //

   TTree *t1 = (TTree *) f1->Get("tree");

   TH1D* xxx1b = new TH1D("xxx1b", ("Barrel " + varTitle + " Distr.").c_str(), xxxb_nBin, xxxb_min, xxxb_max);
   TH1D* xxx1e = new TH1D("xxx1e", ("Endcap " + varTitle + " Distr.").c_str(), xxxe_nBin, xxxe_min, xxxe_max);
   xxx1b->SetFillColor(kRed + 1);
   xxx1b->SetLineColor(kRed + 1);
   xxx1b->SetFillStyle(3157);
   xxx1e->SetFillColor(kRed + 1);
   xxx1e->SetLineColor(kRed + 1);
   xxx1e->SetFillStyle(3157);

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

   TH1D* mih1b = new TH1D("mih1b", ("Barrel " + varTitle + " Distr.").c_str(), mihb_nBin, mihb_min, mihb_max);
   TH1D* mih1e = new TH1D("mih1e", ("Endcap " + varTitle + " Distr.").c_str(), mihe_nBin, mihe_min, mihe_max);
   mih1b->SetFillColor(kRed + 1);
   mih1b->SetLineColor(kRed + 1);
   mih1b->SetFillStyle(3157);
   mih1e->SetFillColor(kRed + 1);
   mih1e->SetLineColor(kRed + 1);
   mih1e->SetFillStyle(3157);

   TH1D* chi1b = new TH1D("chi1b", ("Barrel " + varTitle + " Distr.").c_str(), chib_nBin, chib_min, chib_max);
   TH1D* chi1e = new TH1D("chi1e", ("Endcap " + varTitle + " Distr.").c_str(), chie_nBin, chie_min, chie_max);
   chi1b->SetFillColor(kRed + 1);
   chi1b->SetLineColor(kRed + 1);
   chi1b->SetFillStyle(3157);
   chi1e->SetFillColor(kRed + 1);
   chi1e->SetLineColor(kRed + 1);
   chi1e->SetFillStyle(3157);

   TH1D* hit1b = new TH1D("hit1b", ("Barrel " + varTitle + " Distr.").c_str(), hitb_nBin, hitb_min, hitb_max);
   TH1D* hit1e = new TH1D("hit1e", ("Endcap " + varTitle + " Distr.").c_str(), hite_nBin, hite_min, hite_max);
   hit1b->SetFillColor(kRed + 1);
   hit1b->SetLineColor(kRed + 1);
   hit1b->SetFillStyle(3157);
   hit1e->SetFillColor(kRed + 1);
   hit1e->SetLineColor(kRed + 1);
   hit1e->SetFillStyle(3157);

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

           //fillVars(xxx1b, hoe1v[it1], hoe1v[it1], e1v[it1], et1v[it1]);

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

           //fillVars(xxx1e, hoe1v[it1], hoe1v[it1], e1v[it1], et1v[it1]);

         }

         else continue;

       }

       else continue;

     }
   }

   // -------------------------------------------------- //

   TTree *t2 = (TTree *) f2->Get("tree");

   TH1D* xxx2b = new TH1D("xxx2b", ("Barrel " + varTitle + " Distr.").c_str(), xxxb_nBin, xxxb_min, xxxb_max);
   TH1D* xxx2e = new TH1D("xxx2e", ("Endcap " + varTitle + " Distr.").c_str(), xxxe_nBin, xxxe_min, xxxe_max);
   xxx2b->SetFillColor(kAzure + 1);
   xxx2b->SetLineColor(kAzure + 1);
   xxx2e->SetFillColor(kAzure + 1);
   xxx2e->SetLineColor(kAzure + 1);

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

   TH1D* mih2b = new TH1D("mih2b", ("Barrel " + varTitle + " Distr.").c_str(), mihb_nBin, mihb_min, mihb_max);
   TH1D* mih2e = new TH1D("mih2e", ("Endcap " + varTitle + " Distr.").c_str(), mihe_nBin, mihe_min, mihe_max);
   mih2b->SetFillColor(kAzure + 1);
   mih2b->SetLineColor(kAzure + 1);
   mih2e->SetFillColor(kAzure + 1);
   mih2e->SetLineColor(kAzure + 1);

   TH1D* chi2b = new TH1D("chi2b", ("Barrel " + varTitle + " Distr.").c_str(), chib_nBin, chib_min, chib_max);
   TH1D* chi2e = new TH1D("chi2e", ("Endcap " + varTitle + " Distr.").c_str(), chie_nBin, chie_min, chie_max);
   chi2b->SetFillColor(kAzure + 1);
   chi2b->SetLineColor(kAzure + 1);
   chi2e->SetFillColor(kAzure + 1);
   chi2e->SetLineColor(kAzure + 1);

   TH1D* hit2b = new TH1D("hit2b", ("Barrel " + varTitle + " Distr.").c_str(), hitb_nBin, hitb_min, hitb_max);
   TH1D* hit2e = new TH1D("hit2e", ("Endcap " + varTitle + " Distr.").c_str(), hite_nBin, hite_min, hite_max);
   hit2b->SetFillColor(kAzure + 1);
   hit2b->SetLineColor(kAzure + 1);
   hit2e->SetFillColor(kAzure + 1);
   hit2e->SetLineColor(kAzure + 1);

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

           //fillVars(xxx2b, hoe2v[it2], hoe2v[it2], e2v[it2], et2v[it2]);

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

           //fillVars(xxx2e, hoe2v[it2], hoe2v[it2], e2v[it2], et2v[it2]);

         }

         else continue;

       }

       else continue;

     }
   }

   // -------------------------------------------------- //

   xxx1b->Scale(1 / xxx1b->Integral()); xxx1e->Scale(1 / xxx1e->Integral());
   xxx2b->Scale(1 / xxx2b->Integral()); xxx2e->Scale(1 / xxx2e->Integral());

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

   mih1b->Scale(1 / mih1b->Integral()); mih1e->Scale(1 / mih1e->Integral());
   mih2b->Scale(1 / mih2b->Integral()); mih2e->Scale(1 / mih2e->Integral());

   hit1b->Scale(1 / hit1b->Integral()); hit1e->Scale(1 / hit1e->Integral());
   hit2b->Scale(1 / hit2b->Integral()); hit2e->Scale(1 / hit2e->Integral());

   chi1b->Scale(1 / chi1b->Integral()); chi1e->Scale(1 / chi1e->Integral());
   chi2b->Scale(1 / chi2b->Integral()); chi2e->Scale(1 / chi2e->Integral());

   det1b->Scale(1 / det1b->Integral()); det1e->Scale(1 / det1e->Integral());
   det2b->Scale(1 / det2b->Integral()); det2e->Scale(1 / det2e->Integral());

   dph1b->Scale(1 / dph1b->Integral()); dph1e->Scale(1 / dph1e->Integral());
   dph2b->Scale(1 / dph2b->Integral()); dph2e->Scale(1 / dph2e->Integral());

   tki1b->Scale(1 / tki1b->Integral()); tki1e->Scale(1 / tki1e->Integral());
   tki2b->Scale(1 / tki2b->Integral()); tki2e->Scale(1 / tki2e->Integral());

   // -------------------------------------------------- //

   static const Int_t nStep_b = tkib_nBin + 1, nStep_e = tkie_nBin + 1;
   Double_t sStep_b = (tkib_max - tkib_min) / tkib_nBin, sStep_e = (tkie_max - tkie_min) / tkie_nBin;

   // Array size must be the same as bin + 1
   Double_t eff_xb[nStep_b], eff_y1b[nStep_b], eff_y2b[nStep_b];
   Double_t eff_xe[nStep_e], eff_y1e[nStep_e], eff_y2e[nStep_e];
   Double_t std_xb[nStep_b], std_xe[nStep_e], std_yb[nStep_b], std_ye[nStep_e];

   std::cout << "Barrel" << "\n" << "Cut" << "\t" << "Eff bkg" << "\t" << "Eff sig" << std::endl;

   for (Int_t p = 0; p < nStep_b + 1; p++) {

     eff_xb[p] = (p * sStep_b) + tkib_min;
     eff_y1b[p] = effCalc(p, tki1b);
     eff_y2b[p] = effCalc(p, tki2b);

     std_xb[p] = cut_b;
     if (p == 0) std_yb[p] = 1.05;
     else if (p == nStep_b - 1) std_yb[p] = 0.;
     else std_yb[p] = (1. - ((Double_t) (p + 1) / (Double_t) nStep_b));

     std::cout << std::setprecision(4) << std::fixed << eff_xb[p] << "\t" << std::setprecision(3) << eff_y1b[p] * 100. << "\t" << eff_y2b[p] * 100. << std::endl;

   }

   std::cout << "\n" << "Endcap" << "\n" << "Cut" << "\t" << "Eff bkg" << "\t" << "Eff sig" << std::endl;

   for (Int_t q = 0; q < nStep_e + 1; q++) {

     eff_xe[q] = (q * sStep_e) + tkie_min;
     eff_y1e[q] = effCalc(q, tki1e);
     eff_y2e[q] = effCalc(q, tki2e);

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

   string const outDir = inDir + "temp_tunePlot/";

   c01->cd();
   if (drawLog) c01->SetLogy();
   tki2b->Draw();
   tki1b->Draw("same");
   c01->SaveAs((outDir + varName + "_hist_bar.png").c_str());

   c02->cd();
   if (drawLog) c02->SetLogy();
   tki2e->Draw();
   tki1e->Draw("same");
   c02->SaveAs((outDir + varName + "_hist_end.png").c_str());

   cg1->cd();
   cg1->SetGrid();
   eff2b->Draw("AL");
   eff1b->Draw("same");
   stdb->Draw("same");
   cg1->SaveAs((outDir + varName + "_eff_bar.png").c_str());

   cg2->cd();
   cg2->SetGrid();
   eff2e->Draw("AL");
   eff1e->Draw("same");
   stde->Draw("same");
   cg2->SaveAs((outDir + varName + "_eff_end.png").c_str());

   // -------------------------------------------------- //

   c01->Close(); c02->Close();
   cg1->Close(); cg2->Close();
   
}

int main() {

  tunePlot();
  return 0;

}



