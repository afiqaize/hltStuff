// Stolen from mvaPlot in 740
// For the tnp hlt vs reco electron plotting
// Nov 25 updated and streamlined

#include "iostream"
#include <iomanip>
#include <TH1.h>
#include <TCanvas.h>
#include <TPad.h>
#include "stdlib.h"
#include <TStyle.h>
#include <TH1D.h>
#include <TGraph.h>
#include <TGraphAsymmErrors.h>
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
/*
Bool_t notFake(Float_t sie_cut, Float_t hoe_cut, Float_t ecc_cut, Float_t hcc_cut, 
               Float_t eop_cut, Float_t chi_cut, Float_t mih_cut, 
               Float_t det_cut, Float_t dph_cut, Float_t tki_cut) {

  Bool_t candOk = false;

  if (sie_cut <= .07) {
    if (hoe_cut <= .31) {
      if (ecc_cut <= .61) {
        if (hcc_cut <= .61) {
          if (eop_cut <= .11) {
            if (dph_cut <= .11) {
              if (det_cut <= .031) {
                if (tki_cut <= .51) {
                  if (mih_cut <= 5.5) {
                    if (chi_cut <= 10.1)
                      candOk = true;

                  }
                }
              }
            }
          }
        }
      }
    }
  }

  return candOk;

}
*/
// Too many dumb lines for styling... doing it here
void styleHist(TH1F* varHist, Int_t useCol, Int_t filSty, Int_t marSty, Int_t marSiz, Float_t linWid) {

   varHist->SetFillColor(useCol);
   varHist->SetFillStyle(filSty);
   varHist->SetMarkerColor(useCol);
   varHist->SetMarkerStyle(marSty);
   varHist->SetMarkerSize(marSiz);
   varHist->SetLineColor(useCol);
   varHist->SetLineWidth(linWid);

}

void styleGr(TGraphAsymmErrors* varGr, Int_t useCol, Int_t filSty, Int_t marSty, Int_t marSiz, Float_t linWid) {

   varGr->SetFillColor(useCol);
   varGr->SetFillStyle(filSty);
   varGr->SetMarkerColor(useCol);
   varGr->SetMarkerStyle(marSty);
   varGr->SetMarkerSize(marSiz);
   varGr->SetLineColor(useCol);
   varGr->SetLineWidth(linWid);

}

void axHist(TH1F* varHist, Float_t yMin, Float_t yMax,
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

void tnpIso() {

   gROOT->Reset();

   setTDRStyle();

   // Everything to tinker with should be here
   Double_t yMin = .761, yMax = 1.049;

   string varName[5];
   varName[0] = "dph";

   Double_t cut_b = 0.02, cut_e = 0.02;

   // -------------------------------------------------- //

   string hisLeg = "MC", pntLeg = "Data";

   const Int_t nBin = 10;
   Float_t vtxBins[nBin + 1] = {0., 2., 4., 6., 8., 10., 13., 17., 21., 25., 40.};

   // -------------------------------------------------- //

   varName[2] = "nVtx";
   varName[3] = "Efficiency";
   varName[4] = pntLeg + " / " + hisLeg;

   if (varName[0] == "sie")
     varName[1] = "Cluster Shape";

   if (varName[0] == "hoe")
     varName[1] = "Hadronic / EM";

   if (varName[0] == "ecu" or varName[0] == "ecc")
     varName[1] = "Relative EcalIso";

   if (varName[0] == "hcu" or varName[0] == "hcc")
     varName[1] = "Relative HcalIso";

   if (varName[0] == "eop")
     varName[1] = "1/E - 1/P";

   if (varName[0] == "mih")
     varName[1] = "Missing Tracker Hits";

   if (varName[0] == "det" or varName[0] == "des")
     varName[1] = "Track - Supercluster #Delta#eta";

   if (varName[0] == "dph")
     varName[1] = "Track - Supercluster #Delta#phi";

   if (varName[0] == "chi")
     varName[1] = "Track Fit #chi^{2}";

   if (varName[0] == "tki")
     varName[1] = "Relative TrkIso";

   // -------------------------------------------------- //

   TH1::SetDefaultSumw2(true);

   TH1F* vtx_t1b = new TH1F("vtx_t1b", "", nBin, vtxBins);
   TH1F* vtx_t1e = new TH1F("vtx_t1e", "", nBin, vtxBins);

   TH1F* vtx_t2b = new TH1F("vtx_t2b", "", nBin, vtxBins);
   TH1F* vtx_t2e = new TH1F("vtx_t2e", "", nBin, vtxBins);

   TH1F* vtx_p1b = new TH1F("vtx_p1b", "", nBin, vtxBins);
   TH1F* vtx_p1e = new TH1F("vtx_p1e", "", nBin, vtxBins);

   TH1F* vtx_p2b = new TH1F("vtx_p2b", "", nBin, vtxBins);
   TH1F* vtx_p2e = new TH1F("vtx_p2e", "", nBin, vtxBins);

   // -------------------------------------------------- //

   string const inDir = "/home/ieeya/Downloads/HLT_Val/dev/e_74x/file/v15p1/";

   TChain *t1 = new TChain("eleDistr");
   t1->Add((inDir + "skim_p1dat_*.root").c_str());
   t1->Add((inDir + "skim_m1mcStd_m2mcHFFlat_asympDR.root").c_str());

   Int_t type;
   t1->SetBranchAddress("itype", &type);
   Float_t weight;
   t1->SetBranchAddress("weight", &weight);
   Float_t puWgt;
   t1->SetBranchAddress("puWgt", &puWgt);
   Int_t nvtx;
   t1->SetBranchAddress("nvtx", &nvtx);

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
   Float_t finWgt = 1., var = 9999.;

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

         // FILL IN THE FILTER TO BE LOOKED AT HERE
         var = dph[iProbe];

         if (type == 1) {

           if (fabs(eta[iProbe]) < 1.4791) {

             if(!barPass(sie[iProbe], hoe[iProbe], ecc[iProbe], hcc[iProbe], eop[iProbe],
                         chi[iProbe], mih[iProbe], det[iProbe], dph[iProbe], tki[iProbe])) continue;

             vtx_t1b->Fill((Float_t) nvtx, finWgt);

             if (var < cut_b)
               vtx_p1b->Fill((Float_t) nvtx, finWgt);
 
           }

           if (fabs(eta[iProbe]) >= 1.4791) {

             if(!endPass(sie[iProbe], hoe[iProbe], ecc[iProbe], hcc[iProbe], eop[iProbe],
                         chi[iProbe], mih[iProbe], det[iProbe], dph[iProbe], tki[iProbe])) continue;

             vtx_t1e->Fill((Float_t) nvtx, finWgt);

             if (var < cut_e)
               vtx_p1e->Fill((Float_t) nvtx, finWgt);

           }
         }

         if (type == -2) {

           if (fabs(eta[iProbe]) < 1.4791) {

             if(!barPass(sie[iProbe], hoe[iProbe], ecc[iProbe], hcc[iProbe], eop[iProbe],
                         chi[iProbe], mih[iProbe], det[iProbe], dph[iProbe], tki[iProbe])) continue;

             vtx_t2b->Fill((Float_t) nvtx, finWgt);

             if (var < cut_b)
               vtx_p2b->Fill((Float_t) nvtx, finWgt);


           }

           if (fabs(eta[iProbe]) >= 1.4791) {

             if(!endPass(sie[iProbe], hoe[iProbe], ecc[iProbe], hcc[iProbe], eop[iProbe],
                         chi[iProbe], mih[iProbe], det[iProbe], dph[iProbe], tki[iProbe])) continue;

             vtx_t2e->Fill((Float_t) nvtx, finWgt);

             if (var < cut_e)
               vtx_p2e->Fill((Float_t) nvtx, finWgt);

           }
         }
       }
     }
   }

   // -------------------------------------------------- //

   TGraphAsymmErrors *eff_g1b = new TGraphAsymmErrors(vtx_p1b, vtx_t1b);
   TGraphAsymmErrors *eff_g1e = new TGraphAsymmErrors(vtx_p1e, vtx_t1e);
   styleGr(eff_g1b, kRed + 1, 0, 20, 1, 2.0);
   styleGr(eff_g1e, kRed + 1, 0, 20, 1, 2.0);

   TGraphAsymmErrors *eff_g2b = new TGraphAsymmErrors(vtx_p2b, vtx_t2b);
   TGraphAsymmErrors *eff_g2e = new TGraphAsymmErrors(vtx_p2e, vtx_t2e);
   styleGr(eff_g2b, kAzure + 1, 0, 2, 1, 2.0);
   styleGr(eff_g2e, kAzure + 1, 0, 2, 1, 2.0);

   TH1F* frameHist = new TH1F("frameHist", (varName[1] + " Efficiency vs nVtx").c_str(), nBin, vtxBins);
   axHist(frameHist, yMin, yMax, varName[3], 0.027, 1.05, 0.025, varName[2], 0.027, 1.15, 0.025);

   TH1F* eff_h1b = new TH1F("", "", nBin, vtxBins);
   TH1F* eff_h1e = new TH1F("", "", nBin, vtxBins);

   TH1F* eff_h2b = new TH1F("", "", nBin, vtxBins);
   TH1F* eff_h2e = new TH1F("", "", nBin, vtxBins);

   Float_t l1[nBin + 1];

   Double_t x_1b = 0., y_1b = 0., ye_1b = 0., x_2b = 0., y_2b = 0., ye_2b = 0.;
   Double_t x_1e = 0., y_1e = 0., ye_1e = 0., x_2e = 0., y_2e = 0., ye_2e = 0.;

   for (Int_t i = 0; i < nBin; i++) {

     l1[i] = 1.;

     eff_g1b->GetPoint(i, x_1b, y_1b);
     ye_1b = eff_g1b->GetErrorY(i);
     eff_g2b->GetPoint(i, x_2b, y_2b);
     ye_2b = eff_g2b->GetErrorY(i);

     eff_h1b->SetBinContent(i+1, y_1b);
     eff_h1b->SetBinError(i+1, ye_1b);
     eff_h2b->SetBinContent(i+1, y_2b);
     eff_h2b->SetBinError(i+1, ye_2b);

     eff_g1e->GetPoint(i, x_1e, y_1e);
     ye_1e = eff_g1e->GetErrorY(i);
     eff_g2e->GetPoint(i, x_2e, y_2e);
     ye_2e = eff_g2e->GetErrorY(i);

     eff_h1e->SetBinContent(i+1, y_1e);
     eff_h1e->SetBinError(i+1, ye_1e);
     eff_h2e->SetBinContent(i+1, y_2e);
     eff_h2e->SetBinError(i+1, ye_2e);

   }

   l1[nBin] = 1.;

   // -------------------------------------------------- //

   TGraph *lineb = new TGraph(nBin + 1, vtxBins, l1);
   lineb->SetLineColor(kYellow + 1);
   lineb->SetLineWidth(2);

   TGraph *linee = new TGraph(nBin + 1, vtxBins, l1);
   linee->SetLineColor(kYellow + 1);
   linee->SetLineWidth(2);

   TH1F* sfb = new TH1F("", "", nBin, vtxBins);
   sfb->Divide(eff_h1b, eff_h2b, 1., 1., "B");
   styleHist(sfb, kBlack, 0, 2, 1, 1.0);
   axHist(sfb, 0.801, 1.199, varName[4], 0.061, 0.49, 0.059, varName[2], 0.061, 1.15, 0.059);

   TH1F* sfe = new TH1F("", "", nBin, vtxBins);
   sfe->Divide(eff_h1e, eff_h2e, 1., 1., "B");
   styleHist(sfe, kBlack, 0, 2, 1, 1.0);
   axHist(sfe, 0.801, 1.199, varName[4], 0.061, 0.49, 0.059, varName[2], 0.061, 1.15, 0.059);

   TLatex txt;
   txt.SetTextSize(0.035);
   txt.SetTextAlign(13);

   TLegend *leg01 = new TLegend(.81, .05, .95, .23);
   leg01->SetHeader("#left|#eta^{e}#right| < 1.479");
   leg01->AddEntry(eff_g2b, (hisLeg).c_str(), "lp");
   leg01->AddEntry(eff_g1b, (pntLeg).c_str(), "lp");
   leg01->SetFillColor(0);
   leg01->SetBorderSize(0);
   leg01->SetTextSize(0.03);
   leg01->SetTextFont(42);

   TLegend *leg02 = new TLegend(.81, .05, .95, .23);
   leg02->SetHeader("#left|#eta^{e}#right| > 1.479");
   leg02->AddEntry(eff_g2e, (hisLeg).c_str(), "lp");
   leg02->AddEntry(eff_g1e, (pntLeg).c_str(), "lp");
   leg02->SetFillColor(0);
   leg02->SetBorderSize(0);
   leg02->SetTextSize(0.03);
   leg02->SetTextFont(42);

   // -------------------------------------------------- //

   string const outDir = inDir + "plot_effVtx/";

   TCanvas *c01 = new TCanvas("c01", "c01", 200, 10, 1000, 1000);
   TCanvas *c02 = new TCanvas("c02", "c02", 200, 10, 1000, 1000);

   c01->cd();

   TPad *pad1 = new TPad("pad1", "pad1", 0., 0.29, 1., 1.);
   pad1->SetBottomMargin(0);
   pad1->Draw();
   pad1->cd();

   eff_g2b->SetHistogram(frameHist);
   eff_g1b->SetHistogram(frameHist);
   frameHist->Draw("func");

   eff_g2b->Draw("p");
   eff_g1b->Draw("psame");
   lineb->Draw("lsame");

   leg01->Draw();
   txt.DrawLatexNDC(0.06, 0.928, "#bf{CMS} #it{Preliminary}");
   txt.DrawLatexNDC(0.783, 0.933, "2.081 fb^{-1} (13 TeV)");

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
   c01->SaveAs((outDir + "eff_" + varName[0] + "_bar.pdf").c_str());

   c02->cd();

   TPad *pad3 = new TPad("pad3", "pad3", 0., 0.29, 1., 1.);
   pad3->SetBottomMargin(0);
   pad3->Draw();
   pad3->cd();

   eff_g2e->SetHistogram(frameHist);
   eff_g1e->SetHistogram(frameHist);
   frameHist->Draw("func");

   eff_g2e->Draw("p");
   eff_g1e->Draw("psame");
   linee->Draw("lsame");

   leg02->Draw();
   txt.DrawLatexNDC(0.06, 0.928, "#bf{CMS} #it{Preliminary}");
   txt.DrawLatexNDC(0.783, 0.933, "2.081 fb^{-1} (13 TeV)");

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
   c02->SaveAs((outDir + "eff_" + varName[0] + "_end.pdf").c_str());

   // -------------------------------------------------- //

   c01->Close(); c02->Close();
   gROOT->ProcessLine(".q");
   
}

int main() {

  tnpIso();
  return 0;

}



