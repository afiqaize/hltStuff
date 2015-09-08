// tnpIso_v1.cxx
// Checking the efficiency of isolation cut vs nvtx

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
#include <TGraphAsymmErrors.h>
#include "/home/ieeya/root/macros/tdrstyle.C"

using namespace std;

// Subprogram for the tuning
// One for each region

Bool_t barPass(Float_t e_cut_b, 
               Float_t sie_cut_b, Float_t hoe_cut_b, Float_t eca_cut_b, Float_t hca_cut_b, 
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

Bool_t endPass(Float_t e_cut_e, 
               Float_t sie_cut_e, Float_t hoe_cut_e, Float_t eca_cut_e, Float_t hca_cut_e, 
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
void fillHist(TH1F* varHist, Float_t varVal, Float_t eVal, Float_t etVal, Float_t weightVal) {

  // Some useless things to make ROOT shut up
  eVal = eVal;
  etVal = etVal;

  varHist->Fill(varVal, weightVal);

}

void tnpIso() {

   gROOT->Reset();

   setTDRStyle();

   string varName = "hcc", varTitle = "Rel. HcalIso", yTitle = "Efficiency";

   string sigName = "MC", bkgName = "Data";
   string sigFull = "MC WP75", bkgFull = "Data WPLoose";

   // Define the WP cut point here
   Float_t cut_b = 0.15, cut_e = 0.16;

   // WPLoose
   // ecc_b 0.15, ecc_e 0.15
   // hcc_b 0.15, hcc_e 0.16

   Int_t nvtx_nBin = 20;
   Float_t nvtx_min = 0.5, nvtx_max = 40.5;

   string const inDir = "/home/ieeya/Downloads/HLT_Val/dev/e_74x/file/v7p2/";

   TFile *f1 = new TFile((inDir + "distHLT.root").c_str());
   TTree *t1 = (TTree *) f1->Get("tnpHLT");

   Int_t type;
   t1->SetBranchAddress("itype", &type);
   Float_t weight;
   t1->SetBranchAddress("weight", &weight);
   Float_t puWgt;
   t1->SetBranchAddress("puWgt", &puWgt);
   Int_t n;
   t1->SetBranchAddress("n", &n);
   Int_t nvtx;
   t1->SetBranchAddress("nvtx", &nvtx);
   Int_t pass[10];
   t1->SetBranchAddress("pass", pass);
   Float_t et[10];
   t1->SetBranchAddress("et", et);
   Float_t e[10];
   t1->SetBranchAddress("e", e);
   Float_t eta[10];
   t1->SetBranchAddress("eta", eta);
   Float_t phi[10];
   t1->SetBranchAddress("phi", phi);
   Float_t sie[10];
   t1->SetBranchAddress("sie", sie);
   Float_t hoe[10];
   t1->SetBranchAddress("hoe", hoe);
   Float_t eca[10];
   t1->SetBranchAddress("eca", eca);
   Float_t ecc[10];
   t1->SetBranchAddress("ecc", ecc);
   Float_t hca[10];
   t1->SetBranchAddress("hca", hca);
   Float_t hcc[10];
   t1->SetBranchAddress("hcc", hcc);
   Float_t eop[10];
   t1->SetBranchAddress("eop", eop);
   Float_t chi[10];
   t1->SetBranchAddress("chi", chi);
   Float_t mih[10];
   t1->SetBranchAddress("mih", mih);
   Float_t det[10];
   t1->SetBranchAddress("det", det);
   Float_t dph[10];
   t1->SetBranchAddress("dph", dph);
   Float_t tki[10];
   t1->SetBranchAddress("tki", tki);

   // -------------------------------------------------- //

   TH1F* nvtx_t1b = new TH1F("nvtx_t1b", "", nvtx_nBin, nvtx_min, nvtx_max);
   TH1F* nvtx_t1e = new TH1F("nvtx_t1e", "", nvtx_nBin, nvtx_min, nvtx_max);

   TH1F* nvtx_t2b = new TH1F("nvtx_t2b", "", nvtx_nBin, nvtx_min, nvtx_max);
   TH1F* nvtx_t2e = new TH1F("nvtx_t2e", "", nvtx_nBin, nvtx_min, nvtx_max);

   TH1F* nvtx_e1b = new TH1F("nvtx_e1b", "", nvtx_nBin, nvtx_min, nvtx_max);
   TH1F* nvtx_e1e = new TH1F("nvtx_e1e", "", nvtx_nBin, nvtx_min, nvtx_max);

   TH1F* nvtx_e2b = new TH1F("nvtx_e2b", "", nvtx_nBin, nvtx_min, nvtx_max);
   TH1F* nvtx_e2e = new TH1F("nvtx_e2e", "", nvtx_nBin, nvtx_min, nvtx_max);

   TH1F* nvtx_h1b = new TH1F("nvtx_h1b", "", nvtx_nBin, nvtx_min, nvtx_max);
   TH1F* nvtx_h1e = new TH1F("nvtx_h1e", "", nvtx_nBin, nvtx_min, nvtx_max);

   TH1F* nvtx_h2b = new TH1F("nvtx_h2b", "", nvtx_nBin, nvtx_min, nvtx_max);
   TH1F* nvtx_h2e = new TH1F("nvtx_h2e", "", nvtx_nBin, nvtx_min, nvtx_max);

   // -------------------------------------------------- //

   TLorentzVector p4Tag, p4Probe;

   Int_t nEvt1 = t1->GetEntries();
   cout << "nEvt1 = " << nEvt1 << endl;

   for (Int_t evt1 = 0; evt1 < nEvt1; evt1++) {

     t1->GetEntry(evt1);
     if (nvtx == 0) continue;

     for (Int_t iTag = 0; iTag < n; iTag++) {

       if (pass[iTag] != 1) continue;
       if (et[iTag] < 30. || fabs(eta[iTag]) > 2.1) continue;

       p4Tag.SetPtEtaPhiE(et[iTag], eta[iTag], phi[iTag], e[iTag]);

       for (Int_t iProbe = 0; iProbe < n; iProbe++) {

         if (iProbe == iTag) continue;
         if (et[iProbe] < 30. || fabs(eta[iProbe]) > 2.1) continue;

         p4Probe.SetPtEtaPhiE(et[iProbe], eta[iProbe], phi[iProbe], e[iProbe]);

         if ((p4Tag + p4Probe).M() < 70. || (p4Tag + p4Probe).M() > 110.) continue;

         if (type == 1) {

           if (fabs(eta[iProbe]) < 1.4791) {

             if(!barPass(e[iProbe], sie[iProbe], hoe[iProbe], ecc[iProbe], hcc[iProbe],
                         eop[iProbe], chi[iProbe], mih[iProbe], det[iProbe], dph[iProbe], tki[iProbe])) continue;

             fillHist(nvtx_t1b, (Float_t) nvtx, e[iProbe], et[iProbe], 1.);

             if (ecc[iProbe] < cut_b)
               fillHist(nvtx_e1b, (Float_t) nvtx, e[iProbe], et[iProbe], 1.);

             if (hcc[iProbe] < cut_b)
               fillHist(nvtx_h1b, (Float_t) nvtx, e[iProbe], et[iProbe], 1.);

           }

           if (fabs(eta[iProbe]) >= 1.4791 && (fabs(eta[iProbe]) < 2.1)) {

             if(!endPass(e[iProbe], sie[iProbe], hoe[iProbe], ecc[iProbe], hcc[iProbe],
                         eop[iProbe], chi[iProbe], mih[iProbe], det[iProbe], dph[iProbe], tki[iProbe])) continue;

             fillHist(nvtx_t1e, (Float_t) nvtx, e[iProbe], et[iProbe], 1.);

             if (ecc[iProbe] < cut_e)
               fillHist(nvtx_e1e, (Float_t) nvtx, e[iProbe], et[iProbe], 1.);

             if (hcc[iProbe] < cut_e)
               fillHist(nvtx_h1e, (Float_t) nvtx, e[iProbe], et[iProbe], 1.);

           }
         }

         if (type == -1) {

           if (fabs(eta[iProbe]) < 1.4791) {

             if(!barPass(e[iProbe], sie[iProbe], hoe[iProbe], ecc[iProbe], hcc[iProbe],
                         eop[iProbe], chi[iProbe], mih[iProbe], det[iProbe], dph[iProbe], tki[iProbe])) continue;

             fillHist(nvtx_t2b, (Float_t) nvtx, e[iProbe], et[iProbe], 1.);

             if (ecc[iProbe] < cut_b)
               fillHist(nvtx_e2b, (Float_t) nvtx, e[iProbe], et[iProbe], 1.);

             if (hcc[iProbe] < cut_b)
               fillHist(nvtx_h2b, (Float_t) nvtx, e[iProbe], et[iProbe], 1.);

           }

           if (fabs(eta[iProbe]) >= 1.4791 && (fabs(eta[iProbe]) < 2.1)) {

             if(!endPass(e[iProbe], sie[iProbe], hoe[iProbe], ecc[iProbe], hcc[iProbe],
                         eop[iProbe], chi[iProbe], mih[iProbe], det[iProbe], dph[iProbe], tki[iProbe])) continue;

             fillHist(nvtx_t2e, (Float_t) nvtx, e[iProbe], et[iProbe], 1.);

             if (ecc[iProbe] < cut_e)
               fillHist(nvtx_e2e, (Float_t) nvtx, e[iProbe], et[iProbe], 1.);

             if (hcc[iProbe] < cut_e)
               fillHist(nvtx_h2e, (Float_t) nvtx, e[iProbe], et[iProbe], 1.);

           }
         }
       }
     }
   }

   // -------------------------------------------------- //

   TGraphAsymmErrors *eccVtx_1b = new TGraphAsymmErrors(nvtx_e1b, nvtx_t1b);
   TGraphAsymmErrors *eccVtx_1e = new TGraphAsymmErrors(nvtx_e1e, nvtx_t1e);
   eccVtx_1b->SetMarkerColor(kRed + 1);
   eccVtx_1b->SetMarkerStyle(2);
   eccVtx_1b->SetMarkerSize(1);
   eccVtx_1b->SetLineColor(kRed + 1);
   eccVtx_1b->SetLineWidth(1.5);
   eccVtx_1e->SetMarkerColor(kRed + 1);
   eccVtx_1e->SetMarkerStyle(2);
   eccVtx_1e->SetMarkerSize(1);
   eccVtx_1e->SetLineColor(kRed + 1);
   eccVtx_1e->SetLineWidth(1.5);

   TGraphAsymmErrors *hccVtx_1b = new TGraphAsymmErrors(nvtx_h1b, nvtx_t1b);
   TGraphAsymmErrors *hccVtx_1e = new TGraphAsymmErrors(nvtx_h1e, nvtx_t1e);
   hccVtx_1b->SetMarkerColor(kRed + 1);
   hccVtx_1b->SetMarkerStyle(2);
   hccVtx_1b->SetMarkerSize(1);
   hccVtx_1b->SetLineColor(kRed + 1);
   hccVtx_1b->SetLineWidth(1.5);
   hccVtx_1e->SetMarkerColor(kRed + 1);
   hccVtx_1e->SetMarkerStyle(2);
   hccVtx_1e->SetMarkerSize(1);
   hccVtx_1e->SetLineColor(kRed + 1);
   hccVtx_1e->SetLineWidth(1.5);

   TGraphAsymmErrors *eccVtx_2b = new TGraphAsymmErrors(nvtx_e2b, nvtx_t2b);
   TGraphAsymmErrors *eccVtx_2e = new TGraphAsymmErrors(nvtx_e2e, nvtx_t2e);
   eccVtx_2b->SetMarkerColor(kAzure + 1);
   eccVtx_2b->SetMarkerStyle(2);
   eccVtx_2b->SetMarkerSize(1);
   eccVtx_2b->SetLineColor(kAzure + 1);
   eccVtx_2b->SetLineWidth(1.5);
   eccVtx_2e->SetMarkerColor(kAzure + 1);
   eccVtx_2e->SetMarkerStyle(2);
   eccVtx_2e->SetMarkerSize(1);
   eccVtx_2e->SetLineColor(kAzure + 1);
   eccVtx_2e->SetLineWidth(1.5);

   TGraphAsymmErrors *hccVtx_2b = new TGraphAsymmErrors(nvtx_h2b, nvtx_t2b);
   TGraphAsymmErrors *hccVtx_2e = new TGraphAsymmErrors(nvtx_h2e, nvtx_t2e);
   hccVtx_2b->SetMarkerColor(kAzure + 1);
   hccVtx_2b->SetMarkerStyle(2);
   hccVtx_2b->SetMarkerSize(1);
   hccVtx_2b->SetLineColor(kAzure + 1);
   hccVtx_2b->SetLineWidth(1.5);
   hccVtx_2e->SetMarkerColor(kAzure + 1);
   hccVtx_2e->SetMarkerStyle(2);
   hccVtx_2e->SetMarkerSize(1);
   hccVtx_2e->SetLineColor(kAzure + 1);
   hccVtx_2e->SetLineWidth(1.5);

   // -------------------------------------------------- //

   TH1F *frame_hist = new TH1F("", (varTitle + " Efficiency vs nVtx").c_str(), nvtx_nBin, nvtx_min, nvtx_max);
   frame_hist->SetLineWidth(0);
   frame_hist->SetYTitle(yTitle.c_str());
   frame_hist->GetYaxis()->SetTitleSize(0.027);
   frame_hist->GetYaxis()->SetTitleOffset(1.05);
   frame_hist->GetYaxis()->SetLabelSize(0.025);
   frame_hist->SetXTitle("nVtx");
   frame_hist->GetXaxis()->SetTitleSize(0.027);
   frame_hist->GetXaxis()->SetTitleOffset(1.15);
   frame_hist->GetXaxis()->SetLabelSize(0.025);
   frame_hist->SetAxisRange(0.01, 1.39, "y");

   TH1F *eff_1b = new TH1F("", (varTitle + " Efficiency vs nVtx").c_str(), nvtx_nBin, nvtx_min, nvtx_max);
   TH1F *eff_1e = new TH1F("", (varTitle + " Efficiency vs nVtx").c_str(), nvtx_nBin, nvtx_min, nvtx_max);

   TH1F *eff_2b = new TH1F("", (varTitle + " Efficiency vs nVtx").c_str(), nvtx_nBin, nvtx_min, nvtx_max);
   TH1F *eff_2e = new TH1F("", (varTitle + " Efficiency vs nVtx").c_str(), nvtx_nBin, nvtx_min, nvtx_max);

   Float_t l1[nvtx_nBin + 1], vtx_x[nvtx_nBin + 1];

   Double_t x_1b, y_1b, ye_1b, x_2b, y_2b, ye_2b;
   Double_t x_1e, y_1e, ye_1e, x_2e, y_2e, ye_2e;

   for (Int_t i = 0; i < nvtx_nBin; i++) {

     l1[i] = 1.;
     vtx_x[i] = nvtx_min + ( ((Float_t) i / (Float_t) nvtx_nBin) * nvtx_max);

     x_1b = 0.;
     y_1b = 0.;
     ye_1b = 0.;

     hccVtx_1b->GetPoint(i, x_1b, y_1b);
     ye_1b = hccVtx_1b->GetErrorY(i);

     eff_1b->SetBinContent(i+1, y_1b);
     eff_1b->SetBinError(i+1, ye_1b);

     x_2b = 0.;
     y_2b = 0.;
     ye_2b = 0.;

     hccVtx_2b->GetPoint(i, x_2b, y_2b);
     ye_2b = hccVtx_2b->GetErrorY(i);

     eff_2b->SetBinContent(i+1, y_2b);
     eff_2b->SetBinError(i+1, ye_2b);

     x_1e = 0.;
     y_1e = 0.;
     ye_1e = 0.;

     hccVtx_1e->GetPoint(i, x_1e, y_1e);
     ye_1e = hccVtx_1e->GetErrorY(i);

     eff_1e->SetBinContent(i+1, y_1e);
     eff_1e->SetBinError(i+1, ye_1e);

     x_2e = 0.;
     y_2e = 0.;
     ye_2e = 0.;

     hccVtx_2e->GetPoint(i, x_2e, y_2e);
     ye_2e = hccVtx_2e->GetErrorY(i);

     eff_2e->SetBinContent(i+1, y_2e);
     eff_2e->SetBinError(i+1, ye_2e);

  }

   l1[nvtx_nBin] = 1.;
   vtx_x[nvtx_nBin] = nvtx_max;

   // -------------------------------------------------- //

   TGraph *lineb = new TGraph(nvtx_nBin + 1, vtx_x, l1);
   lineb->SetLineColor(kYellow + 1);
   lineb->SetLineWidth(2);

   TGraph *linee = new TGraph(nvtx_nBin + 1, vtx_x, l1);
   linee->SetLineColor(kYellow + 1);
   linee->SetLineWidth(2);

   TH1F *sfb = new TH1F("", "", nvtx_nBin, nvtx_min, nvtx_max);
   sfb->Divide(eff_1b, eff_2b, 1., 1., "B");
   sfb->SetMarkerStyle(2);
   sfb->SetMarkerSize(1);
   sfb->SetMarkerColor(kBlack);
   sfb->SetLineColor(kBlack);
   sfb->SetLineWidth(1);
   sfb->SetAxisRange(0.51, 1.49, "y");
   sfb->SetTitle("");

   sfb->GetYaxis()->SetTitle("Data / MC");
   sfb->GetYaxis()->SetTitleSize(0.061);
   sfb->GetYaxis()->SetTitleOffset(0.49);
   sfb->GetYaxis()->SetLabelSize(0.059);
   sfb->SetXTitle("nvtx");
   sfb->GetXaxis()->SetTitleSize(0.061);
   sfb->GetXaxis()->SetTitleOffset(1.15);
   sfb->GetXaxis()->SetLabelSize(0.059);

   TH1F *sfe = new TH1F("", "", nvtx_nBin, nvtx_min, nvtx_max);
   sfe->Divide(eff_1e, eff_2e, 1., 1., "B");
   sfe->SetMarkerStyle(2);
   sfe->SetMarkerSize(1);
   sfe->SetMarkerColor(kBlack);
   sfe->SetLineColor(kBlack);
   sfe->SetLineWidth(1);
   sfe->SetAxisRange(0.51, 1.49, "y");
   sfe->SetTitle("");

   sfe->GetYaxis()->SetTitle("Data / MC");
   sfe->GetYaxis()->SetTitleSize(0.061);
   sfe->GetYaxis()->SetTitleOffset(0.49);
   sfe->GetYaxis()->SetLabelSize(0.059);
   sfe->SetXTitle("nvtx");
   sfe->GetXaxis()->SetTitleSize(0.061);
   sfe->GetXaxis()->SetTitleOffset(1.15);
   sfe->GetXaxis()->SetLabelSize(0.059);

   // -------------------------------------------------- //

   TLatex txt;
   txt.SetTextSize(0.035);
   txt.SetTextAlign(13);

   TLegend *leg01 = new TLegend(.71, .67, .89, .85);
   leg01->SetHeader("#left|#eta^{e}#right| < 1.479");
   leg01->AddEntry(hccVtx_2b, (sigFull).c_str(), "lp");
   leg01->AddEntry(hccVtx_1b, (bkgFull).c_str(), "lp");
   leg01->SetFillColor(0);
   leg01->SetBorderSize(0);
   leg01->SetTextSize(0.03);
   leg01->SetTextFont(42);

   TLegend *leg02 = new TLegend(.71, .67, .89, .85);
   leg02->SetHeader("1.479 < #left|#eta^{e}#right| < 2.1");
   leg02->AddEntry(hccVtx_2e, (sigFull).c_str(), "lp");
   leg02->AddEntry(hccVtx_1e, (bkgFull).c_str(), "lp");
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

   hccVtx_2b->SetHistogram(frame_hist);
   hccVtx_1b->SetHistogram(frame_hist);
   frame_hist->Draw("func");

   hccVtx_2b->Draw("p");
   hccVtx_1b->Draw("psame");

   leg01->Draw();
   txt.DrawLatexNDC(0.06, 0.928, "#bf{CMS} #it{Preliminary}");
   txt.DrawLatexNDC(0.79, 0.936, "40.2 pb^{-1} (13 TeV)");

   c01->cd();
   TPad *pad2 = new TPad("pad2", "pad2", 0., 0., 1., 0.29);
   pad2->SetTopMargin(0);
   pad2->SetBottomMargin(0.16);
   pad2->Draw();
   pad2->cd();

   sfb->Draw();
   lineb->Draw("lsame");
   sfb->Draw("same");

   c01->cd();
   c01->SaveAs((outDir + varName + "_effVtx_bar.pdf").c_str());

   c02->cd();

   TPad *pad3 = new TPad("pad3", "pad3", 0., 0.29, 1., 1.);
   pad3->SetBottomMargin(0);
   pad3->Draw();
   pad3->cd();

   hccVtx_2e->SetHistogram(frame_hist);
   hccVtx_1e->SetHistogram(frame_hist);
   frame_hist->Draw("func");

   hccVtx_2e->Draw("p");
   hccVtx_1e->Draw("psame");

   leg02->Draw();
   txt.DrawLatexNDC(0.06, 0.928, "#bf{CMS} #it{Preliminary}");
   txt.DrawLatexNDC(0.79, 0.936, "40.2 pb^{-1} (13 TeV)");

   c02->cd();
   TPad *pad4 = new TPad("pad4", "pad4", 0., 0., 1., 0.29);
   pad4->SetTopMargin(0);
   pad4->SetBottomMargin(0.16);
   pad4->Draw();
   pad4->cd();

   sfe->Draw();
   linee->Draw("lsame");
   sfe->Draw("same");

   c02->cd();
   c02->SaveAs((outDir + varName + "_effVtx_end.pdf").c_str());

   // -------------------------------------------------- //

   c01->Close(); c02->Close();

}

int main() {

  tnpIso();
  return 0;

}
