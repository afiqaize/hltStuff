// Stolen from mvaPlot in 740
// For the efficiency of some cut as function of some var

#include "iostream"
#include <sstream>
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
#include <TF1.h>
#include "/home/afiqaize/root53434/macros/tdrstyle.C"

using namespace std;

Bool_t checkCand(const string setWP, const Float_t eta, const int iMask,
                 const Float_t sie, const Float_t hoe, const Float_t ecc, const Float_t hcc, 
                 const Float_t eop, const Float_t chi, const Float_t mih, 
                 const Float_t des, const Float_t dph, const Float_t tki) {
  Bool_t candOk = true;
  Float_t varVal[10], varThr[10];

  // Order as in the method call -> HLT filtering
  varVal[0] = sie; varVal[1] = hoe;
  varVal[2] = ecc; varVal[3] = hcc;
  varVal[4] = eop; varVal[5] = chi;
  varVal[6] = mih; varVal[7] = des;
  varVal[8] = dph; varVal[9] = tki;

  if (fabs(eta) < 1.4791 && setWP == "WPLoose") {
  varThr[0] = 0.011; varThr[1] = 0.06;
  varThr[2] = 0.145; varThr[3] = 0.15;
  varThr[4] = 0.012; varThr[5] = 999.0;
  varThr[6] = 999.0; varThr[7] = 0.004;
  varThr[8] = 0.02 ; varThr[9] = 0.08;
  //varThr[6] = 999.0; varThr[7] = 0.0044; // new matching
  //varThr[8] = 0.025; varThr[9] = 0.08;
  }

  else if (fabs(eta) > 1.4791 && setWP == "WPLoose") {
  varThr[0] = 0.032; varThr[1] = 0.065;
  varThr[2] = 0.135; varThr[3] = 0.13;
  varThr[4] = 0.01 ; varThr[5] = 2.8;
  varThr[6] = 2.5  ; varThr[7] = 999.007;
  varThr[8] = 999.02 ; varThr[9] = 0.08;
  //varThr[6] = 2.5  ; varThr[7] = 0.006; // new matching
  //varThr[8] = 0.025; varThr[9] = 0.08;
  }

  else if (fabs(eta) < 1.4791 && setWP == "WPTight") {
  varThr[0] = 0.011; varThr[1] = 0.05;
  varThr[2] = 0.145; varThr[3] = 0.13;
  varThr[4] = 0.01 ; varThr[5] = 999.0;
  varThr[6] = 999.0; varThr[7] = 0.0035;
  varThr[8] = 0.015; varThr[9] = 0.06;
  //varThr[6] = 999.0; varThr[7] = 0.004; // new matching
  //varThr[8] = 0.02 ; varThr[9] = 0.06;
  }

  else if (fabs(eta) > 1.4791 && setWP == "WPTight") {
  varThr[0] = 0.029; varThr[1] = 0.05;
  varThr[2] = 0.105; varThr[3] = 0.095;
  varThr[4] = 0.008; varThr[5] = 2.5;
  varThr[6] = 1.5  ; varThr[7] = 999.006;
  varThr[8] = 999.015; varThr[9] = 0.06;
  //varThr[6] = 1.5  ; varThr[7] = 0.0045; // new matching
  //varThr[8] = 0.022; varThr[9] = 0.06;
  }

  else if (fabs(eta) < 1.4791 && setWP == "NeoLoose") {
  varThr[0] = 0.011; varThr[1] = 0.08;
  varThr[2] = 0.04 ; varThr[3] = 0.06;
  varThr[4] = 0.012; varThr[5] = 999.0;
  varThr[6] = 999.0; varThr[7] = 0.0044;
  varThr[8] = 0.025; varThr[9] = 0.085;
  }

  else if (fabs(eta) > 1.4791 && setWP == "NeoLoose") {
  varThr[0] = 0.031; varThr[1] = 0.04;
  varThr[2] = 0.045; varThr[3] = 0.08;
  varThr[4] = 0.01 ; varThr[5] = 4.0;
  varThr[6] = 2.5  ; varThr[7] = 0.006;
  varThr[8] = 0.025; varThr[9] = 0.07;
  }

  else if (fabs(eta) < 1.4791 && setWP == "NeoTight") {
  varThr[0] = 0.0105; varThr[1] = 0.07;
  varThr[2] = 0.032 ; varThr[3] = 0.055;
  varThr[4] = 0.01  ; varThr[5] = 999.0;
  varThr[6] = 999.0 ; varThr[7] = 0.004;
  varThr[8] = 0.02  ; varThr[9] = 0.07;
  }

  else if (fabs(eta) > 1.4791 && setWP == "NeoTight") {
  varThr[0] = 0.0285; varThr[1] = 0.035;
  varThr[2] = 0.04  ; varThr[3] = 0.05;
  varThr[4] = 0.008 ; varThr[5] = 3.5;
  varThr[6] = 2.5   ; varThr[7] = 0.0045;
  varThr[8] = 0.022 ; varThr[9] = 0.05;
  }

  else {
  varThr[0] = 9999. ; varThr[1] = 9999.;
  varThr[2] = 9999. ; varThr[3] = 9999.;
  varThr[4] = 9999. ; varThr[5] = 9999.;
  varThr[6] = 9999. ; varThr[7] = 9999.;
  varThr[8] = 9999. ; varThr[9] = 9999.;
  }

  // Which cut to mask for N-1 shit
  if (iMask > -1 and iMask < 10)
    varThr[ iMask ] += 999.;

  for (Int_t aa = 0; aa < 10; aa++)
    candOk = candOk and (varVal[aa] < varThr[aa]);

  return candOk;
}

// Too many dumb lines for styling... doing it here
string toStr(Float_t inNo) { ostringstream outStr; outStr << inNo; return outStr.str(); }
string toStr(Int_t inNo) { ostringstream outStr; outStr << inNo; return outStr.str(); }

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

void styleLeg(TLegend* varLeg, Int_t nCol, Int_t fColor, Int_t borSiz, Int_t texFon, Float_t texSiz, string legHead = "") {
  varLeg->SetHeader( legHead.c_str() );
  varLeg->SetNColumns(nCol);
  varLeg->SetFillColor(fColor);
  varLeg->SetBorderSize(borSiz);
  varLeg->SetTextFont(texFon);
  varLeg->SetTextSize(texSiz);
}

//void tnpIso(string varName_ = "", Int_t iMaskCut_ = -1) {
void tnpIso() {

   gROOT->Reset();

   setTDRStyle();

   // Everything to tinker with should be here
   //Double_t yMin = 0.8001, yMax = 1.0099;
   Double_t yMin = 0.4501, yMax = 0.9999;
   //Double_t yMin = -0.0199, yMax = 0.0399;
   Bool_t doSF = false, doFit = false;
   string lHead = "Run, ";

   string varName[6], outPre;
   varName[0] = "hlt";
   outPre = "lolk";
   const Int_t iMaskCut = -1;

   // which looping to use: 1 tnp, 2 cnd
   const Int_t iLoop = 1;

   // -------------------------------------------------- //

   const Int_t nH = 4;

   string inLeg[nH];
   inLeg[0] = "276581";
   inLeg[1] = "276582";
   inLeg[2] = "276586";
   inLeg[3] = "276587";

   // For Et
   //const Int_t nBin = 22;
   //Float_t graBins[nBin + 1] = {20., 25., 26., 27., 28., 29., 30., 31., 32., 33., 34., 35., 37., 39., 41., 44., 47., 50., 55., 60., 70., 85., 100.};

   // For nVtx
   //const Int_t nBin = 8;
   //Float_t graBins[nBin + 1] = {0., 3., 6., 9., 13., 17., 21., 25., 35.}; // rho
   //Float_t graBins[nBin + 1] = {0.5, 6.5, 10.5, 14.5, 18.5, 22.5, 28.5, 42.5, 60.5}; // nVtx
   //Float_t graBins[nBin + 1] = {0.5, 10.5, 20.5, 30.5, 40.5, 50.5};

   // For eta
   //const Int_t nBin = 13;
   //Float_t graBins[nBin + 1] = {-2.1, -1.56, -1.44, -1.0, -0.6, -0.3, -0.1, 0.1, 0.3, 0.6, 1.0, 1.44, 1.56, 2.1};

   const Int_t nBin = 1;
   Float_t graBins[nBin + 1] = {-0.5, 999.5};

   /*/ For uniform binning
   const Int_t nBin = 14;
   Float_t graBins[nBin + 1], binWd = 250.;
   for (Int_t iBin = 0; iBin <= nBin; iBin++)
     graBins[iBin] = 0. + (iBin * binWd);

   // -------------------------------------------------- /*/

   varName[2] = "nBX"; // x-axis
   varName[3] = "Efficiency";
   varName[4] = inLeg[0] + " / " + inLeg[1];
   varName[5] = "nBX"; // title

   if (varName[0] == "hlt")
     varName[1] = "Working Point";

   if (varName[0] == "sie")
     varName[1] = "Cluster Shape";

   if (varName[0] == "hoe")
     varName[1] = "Hadronic / EM";

   if (varName[0] == "ecc")
     varName[1] = "Relative EcalIso";

   if (varName[0] == "hcc")
     varName[1] = "Relative HcalIso";

   if (varName[0] == "eop")
     varName[1] = "1/E - 1/P";

   if (varName[0] == "mih")
     varName[1] = "Missing Tracker Hits";

   if (varName[0] == "des")
     varName[1] = "Track - Seed Cluster #Delta#eta";

   if (varName[0] == "dph")
     varName[1] = "Track - SC #Delta#phi";

   if (varName[0] == "chi")
     varName[1] = "Track Fit #chi^{2}";

   if (varName[0] == "tki")
     varName[1] = "Relative TrkIso";

   if (varName[0] == "lol")
     varName[1] = "Test";

   // -------------------------------------------------- //

   TH1::SetDefaultSumw2(true);

   TH1F *gra_tb[nH], *gra_te[nH];
   TH1F *gra_pb[nH], *gra_pe[nH];

   for (Int_t aH = 0; aH < nH; aH++) {
     gra_tb[aH] = new TH1F(("gra_tb_" + toStr(aH)).c_str(), "", nBin, graBins);
     gra_te[aH] = new TH1F(("gra_te_" + toStr(aH)).c_str(), "", nBin, graBins);

     gra_pb[aH] = new TH1F(("gra_pb_" + toStr(aH)).c_str(), "", nBin, graBins);
     gra_pe[aH] = new TH1F(("gra_pe_" + toStr(aH)).c_str(), "", nBin, graBins);
   }

   // -------------------------------------------------- //

   string const inDir = "/home/afiqaize/Downloads/HLT_Val/dev/e_80x/file/v14/hipBull_jul21/";

   TChain *t1 = new TChain("eleDistr");
   t1->Add((inDir + "skim_p1Ele23_16d_f5085.root").c_str());

   Bool_t isMC = false;

   Int_t nRun;
   t1->SetBranchAddress("nRun", &nRun);
   Int_t nLumi;
   t1->SetBranchAddress("nLumi", &nLumi);
   Int_t nEvt;
   t1->SetBranchAddress("nEvt", &nEvt);
   Int_t nBX;
   t1->SetBranchAddress("nBX", &nBX);
   Int_t nOrb;
   t1->SetBranchAddress("nOrb", &nOrb);
   Int_t nSto;
   t1->SetBranchAddress("nSto", &nSto);

   Int_t type;
   t1->SetBranchAddress("itype", &type);
   Float_t weight;
   t1->SetBranchAddress("weight", &weight);
   Float_t puWgt;
   t1->SetBranchAddress("puWgt", &puWgt);
   Int_t nVtx;
   t1->SetBranchAddress("nVtx", &nVtx);
   Float_t rho;
   t1->SetBranchAddress("rho", &rho);

   Int_t pass[10];
   t1->SetBranchAddress("passHLT", pass);
   Int_t genMatch[10];
   t1->SetBranchAddress("genMatch", genMatch);
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
   Float_t ecu[10];
   t1->SetBranchAddress("hlt_ecu", ecu);
   Float_t hca[10];
   t1->SetBranchAddress("hlt_hca", hca);
   Float_t hcc[10];
   t1->SetBranchAddress("hlt_hcc", hcc);
   Float_t hcu[10];
   t1->SetBranchAddress("hlt_hcu", hcu);
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

   Int_t mc_nBX, mc_nPUtrue, gp_n;
   Int_t mc_BX[100], mc_nPUobs[100];
   Float_t genWgt, gp_pt[10], gp_eta[10], gp_phi[10];

    if (isMC) {
      t1->SetBranchAddress("genWgt", &genWgt);
      t1->SetBranchAddress("gp_n", &gp_n);
      t1->SetBranchAddress("gp_pt", gp_pt);
      t1->SetBranchAddress("gp_eta", gp_eta);
      t1->SetBranchAddress("gpphi", gp_phi);
      t1->SetBranchAddress("mc_nBX", &mc_nBX);
      t1->SetBranchAddress("mc_BX", mc_BX);
      t1->SetBranchAddress("mc_nPUtrue", &mc_nPUtrue);
      t1->SetBranchAddress("mc_nPUobs", mc_nPUobs);
    }

   // -------------------------------------------------- //
   // The TnP version of efficiency checker

   TLorentzVector p4Tag, p4Probe;
   Float_t tnpWgt = 1.;
   Float_t tnpY1 = 9999., tnpY2 = 9999.;
   Float_t tnpX = 9999.;
   Bool_t passOL = false, passOT = false;
   Bool_t passNL = false, passNT = false;
   Float_t cut_b = -1., cut_e = -1.;
   Float_t etaEB = 1.444, etaEE = 2.5;

   Float_t ecn = 9999., hcn = 9999., hon = 9999.;
   const Float_t ecc_EAb = 0.290, ecc_EAe = 0.210;
   const Float_t hcc_EAb = 0.200, hcc_EAe = 0.250;
   const Float_t hoe_EAb = 0.079, hoe_EAe = 0.250;

   Int_t nEvt0 = t1->GetEntries();

   if (iLoop == 1) { // iLoop 1
     cout << "nEvt0 = " << nEvt0 << endl;
     for (Int_t evt0 = 0; evt0 < nEvt0; evt0++) {

       t1->GetEntry(evt0);
       tnpWgt = puWgt * weight;
       if (n < 2 or type != 1) continue;

       for (Int_t iTag = 0; iTag < n; iTag++) {

         if (pass[iTag] != 1) continue;
         //if (isMC and genMatch[iTag] != 1) continue;
         if (et[iTag] < 25. or fabs(eta[iTag]) > etaEE) continue;

         p4Tag.SetPtEtaPhiE(et[iTag], eta[iTag], phi[iTag], e[iTag]);

         for (Int_t iProbe = 0; iProbe < n; iProbe++) {

           if (iProbe == iTag) continue;
           //if (isMC and genMatch[iProbe] != 1) continue;
           if (et[iProbe] < 25. or fabs(eta[iProbe]) > etaEE) continue;

           p4Probe.SetPtEtaPhiE(et[iProbe], eta[iProbe], phi[iProbe], e[iProbe]);

           if ((p4Tag + p4Probe).M() < 70. or (p4Tag + p4Probe).M() > 110.) continue;

           if (!checkCand("", eta[iProbe], -1,
                          sie[iProbe], hoe[iProbe], ecc[iProbe], hcc[iProbe], eop[iProbe],
                          chi[iProbe], mih[iProbe], des[iProbe], dph[iProbe], tki[iProbe])) continue;

           if (fabs(eta[iProbe]) < 1.4791) {
             ecn = (ecu[iProbe] - (ecc_EAb * rho)) / et[iProbe];
             hcn = (hcu[iProbe] - (hcc_EAb * rho)) / et[iProbe];
             hon = hoe[iProbe] - (hoe_EAb * rho / e[iProbe]);
           }

           if (fabs(eta[iProbe]) >= 1.4791) {
             ecn = (ecu[iProbe] - (ecc_EAe * rho)) / et[iProbe];
             hcn = (hcu[iProbe] - (hcc_EAe * rho)) / et[iProbe];
             hon = hoe[iProbe] - (hoe_EAe * rho / e[iProbe]);
           }

           passOL = checkCand("WPLoose", eta[iProbe], -1,
                              sie[iProbe], hoe[iProbe], ecc[iProbe], hcc[iProbe], eop[iProbe],
                              chi[iProbe], mih[iProbe], des[iProbe], dph[iProbe], tki[iProbe]);

           passOT = checkCand("WPTight", eta[iProbe], -1,
                              sie[iProbe], hoe[iProbe], ecc[iProbe], hcc[iProbe], eop[iProbe],
                              chi[iProbe], mih[iProbe], des[iProbe], dph[iProbe], tki[iProbe]);

           passNL = checkCand("NeoLoose", eta[iProbe], -1,
                              sie[iProbe], hon, ecn, hcn, eop[iProbe],
                              chi[iProbe], mih[iProbe], des[iProbe], dph[iProbe], tki[iProbe]);

           passNT = checkCand("NeoTight", eta[iProbe], -1,
                              sie[iProbe], hon, ecn, hcn, eop[iProbe],
                              chi[iProbe], mih[iProbe], des[iProbe], dph[iProbe], tki[iProbe]);

           // FILL IN THE FILTER TO BE LOOKED AT HERE
           tnpY1 = ecc[iProbe];
           tnpY2 = ecn;
           tnpX = (Float_t) nBX;

           if (type == 1) {

             if (fabs(eta[iProbe]) < etaEB) {
               if (nRun == 276581) {
                 gra_tb[0]->Fill(tnpX, tnpWgt);

                 if (passNL)
                   gra_pb[0]->Fill(tnpX, tnpWgt);
               }

               if (nRun == 276582) {
                 gra_tb[1]->Fill(tnpX, tnpWgt);

                 if (passNL)
                   gra_pb[1]->Fill(tnpX, tnpWgt);
               }

               if (nRun == 276586) {
                 gra_tb[2]->Fill(tnpX, tnpWgt);

                 if (passNL)
                   gra_pb[2]->Fill(tnpX, tnpWgt);
               }

               if (nRun == 276587) {
                 gra_tb[3]->Fill(tnpX, tnpWgt);

                 if (passNL)
                   gra_pb[3]->Fill(tnpX, tnpWgt);
               }
             }

             if (fabs(eta[iProbe]) >= 1.566) {
               if (nRun == 276581) {
                 gra_te[0]->Fill(tnpX, tnpWgt);

                 if (passNL)
                   gra_pe[0]->Fill(tnpX, tnpWgt);
               }

               if (nRun == 276582) {
                 gra_te[1]->Fill(tnpX, tnpWgt);

                 if (passNL)
                   gra_pe[1]->Fill(tnpX, tnpWgt);
               }

               if (nRun == 276586) {
                 gra_te[2]->Fill(tnpX, tnpWgt);

                 if (passNL)
                   gra_pe[2]->Fill(tnpX, tnpWgt);
               }

               if (nRun == 276587) {
                 gra_te[3]->Fill(tnpX, tnpWgt);

                 if (passNL)
                   gra_pe[3]->Fill(tnpX, tnpWgt);
               }
             }
           }
           /*
           if (type == 9999) {

             if (fabs(eta[iProbe]) < 1.444) {

               gra_tb[1]->Fill(tnpX, tnpWgt);

               if (tnpY2b < cut_e)
                 gra_pb[1]->Fill(tnpX, tnpWgt);

             }

             if (fabs(eta[iProbe]) >= 1.566) {

               gra_te[1]->Fill(tnpX, tnpWgt);

               if (tnpY2e < cut_e)
                 gra_pe[1]->Fill(tnpX, tnpWgt);

             }
           }*/
         } // eol probe
       } // eol tag
     } // eol evt
   } // loop flag

   // -------------------------------------------------- //
   // The all-cand version of efficiency checker

   TLorentzVector p4Cand;
   Float_t cndWgt = 1., cndY = 9999., cndX = 9999.;

   Int_t nEvt1 = t1->GetEntries();

   if (iLoop == 2) { // iLoop 2
     cout << "nEvt1 = " << nEvt1 << endl;
     for (Int_t evt1 = 0; evt1 < nEvt1; evt1++) {

       t1->GetEntry(evt1);
       cndWgt = puWgt * weight;
       if (type != 9999) continue;

       for (Int_t iCand = 0; iCand < n; iCand++) {

         if (et[iCand] < 25. or fabs(eta[iCand]) > etaEE) continue;
         //if (isMC and genMatch[iCand] != 1) continue;

         if (!checkCand("", eta[iCand], -1,
                        sie[iCand], hoe[iCand], ecc[iCand], hcc[iCand], eop[iCand],
                        chi[iCand], mih[iCand], des[iCand], dph[iCand], tki[iCand])) continue;

         if (fabs(eta[iCand]) < 1.4791) {
           ecn = (ecu[iCand] - (ecc_EAb * rho)) / et[iCand];
           hcn = (hcu[iCand] - (hcc_EAb * rho)) / et[iCand];
           hon = hoe[iCand] - (hoe_EAb * rho / e[iCand]);
         }

         if (fabs(eta[iCand]) >= 1.4791) {
           ecn = (ecu[iCand] - (ecc_EAe * rho)) / et[iCand];
           hcn = (hcu[iCand] - (hcc_EAe * rho)) / et[iCand];
           hon = hoe[iCand] - (hoe_EAe * rho / e[iCand]);
         }

         passOL = checkCand("WPLoose", eta[iCand], -1,
                            sie[iCand], hoe[iCand], ecc[iCand], hcc[iCand], eop[iCand],
                            chi[iCand], mih[iCand], des[iCand], dph[iCand], tki[iCand]);

         passOT = checkCand("WPTight", eta[iCand], -1,
                            sie[iCand], hoe[iCand], ecc[iCand], hcc[iCand], eop[iCand],
                            chi[iCand], mih[iCand], des[iCand], dph[iCand], tki[iCand]);

         passNL = checkCand("NeoLoose", eta[iCand], -1,
                            sie[iCand], hon, ecn, hcn, eop[iCand],
                            chi[iCand], mih[iCand], des[iCand], dph[iCand], tki[iCand]);

         passNT = checkCand("NeoTight", eta[iCand], -1,
                            sie[iCand], hon, ecn, hcn, eop[iCand],
                            chi[iCand], mih[iCand], des[iCand], dph[iCand], tki[iCand]);

         // FILL IN THE FILTER TO BE LOOKED AT HERE
         cndY = chi[iCand];
         cndX = (Float_t) nVtx;

         if (fabs(eta[iCand]) < etaEB) {

           gra_tb[0]->Fill(cndX, cndWgt);

           if (passOL)
             gra_pb[0]->Fill(cndX, cndWgt);

         }

         if (fabs(eta[iCand]) >= 1.566) {

           gra_te[0]->Fill(cndX, cndWgt);

           if (passOL)
             gra_pe[0]->Fill(cndX, cndWgt);

         }
       } // eol cand
     } // eol evt
   } // loop flag

   // -------------------------------------------------- //

   TH1F* frameHist = new TH1F("frameHist", (varName[1] + " Efficiency vs " + varName[5]).c_str(), nBin, graBins);
   axHist(frameHist, yMin, yMax, varName[3], 0.027, 1.05, 0.025, varName[2], 0.027, 1.15, 0.025);

   Float_t l1[nBin + 1];
   TGraphAsymmErrors *eff_gb[nH], *eff_ge[nH];
   TF1 *fitEB[nH], *fitEE[nH];
   TH1F *eff_hb[nH], *eff_he[nH];
   Double_t xb[nH], yb[nH], yeb[nH];
   Double_t xe[nH], ye[nH], yee[nH];

   Int_t kColor;
   for (Int_t bH = 0; bH < nH; bH++) {
     if (bH < 4) kColor = 401 + (16 * (bH % 2));
     if (bH < 2) kColor = 601 + (32 * bH);

     eff_gb[bH] = new TGraphAsymmErrors(gra_pb[bH], gra_tb[bH], "n");
     eff_ge[bH] = new TGraphAsymmErrors(gra_pe[bH], gra_te[bH], "n");

     eff_hb[bH] = new TH1F(("eff_hb_" + toStr(bH)).c_str(), "", nBin, graBins);
     eff_he[bH] = new TH1F(("eff_he_" + toStr(bH)).c_str(), "", nBin, graBins);

     styleGr(eff_gb[bH], kColor, 0, 20, 1, 2.0);
     styleGr(eff_ge[bH], kColor, 0, 20, 1, 2.0);

     xb[bH] = 0.; yb[bH] = 0.; yeb[bH] = 0;
     xe[bH] = 0.; ye[bH] = 0.; yee[bH] = 0;

     fitEB[bH] = new TF1(("fitEB_"  + toStr(bH)).c_str(), " ([0]*x + [1]) ", graBins[0], graBins[nBin]);
     fitEB[bH]->SetLineColor(kColor);
     fitEB[bH]->SetLineWidth(2.0);
     fitEB[bH]->SetParameter(0, -0.000001);
     fitEB[bH]->SetParameter(1, 0.999 ); // DY 0.85 QCD 0.007 nm1 0.999

     fitEE[bH] = new TF1(("fitEE_"  + toStr(bH)).c_str(), " ([0]*x + [1]) ", graBins[0], graBins[nBin]);
     fitEE[bH]->SetLineColor(kColor);
     fitEE[bH]->SetLineWidth(2.0);
     fitEE[bH]->SetParameter(0, -0.000001);
     fitEE[bH]->SetParameter(1, 0.99 ); // DY 0.75 QCD 0.01 nm1 0.99

   }

   for (Int_t iBin = 0; iBin < nBin; iBin++) {

     l1[iBin] = 1.;

     for (Int_t cH = 0; cH < nH; cH++) {

     eff_gb[cH]->GetPoint(iBin, xb[cH], yb[cH]);
     yeb[cH] = eff_gb[cH]->GetErrorY(iBin);

     eff_hb[cH]->SetBinContent(iBin + 1, yb[cH]);
     eff_hb[cH]->SetBinError(iBin + 1, yeb[cH]);

     eff_ge[cH]->GetPoint(iBin, xe[cH], ye[cH]);
     yee[cH] = eff_ge[cH]->GetErrorY(iBin);

     eff_he[cH]->SetBinContent(iBin + 1, ye[cH]);
     eff_he[cH]->SetBinError(iBin + 1, yee[cH]);

     }
   }

   l1[nBin] = 1.;

   // printouts for checking int. eff.
   //cout << "EB Pas: "  << gra_pb[0]->GetBinContent(1) << " $\\pm$ " << gra_pb[0]->GetBinError(1) << endl;
   //cout << "EB Tot: "  << gra_tb[0]->GetBinContent(1) << " $\\pm$ " << gra_tb[0]->GetBinError(1) << endl;
   cout << inLeg[0] << " EB Eff: " << eff_hb[0]->GetBinContent(1) << " $\\pm$ " << eff_hb[0]->GetBinError(1) << endl;
   cout << inLeg[1] << " EB Eff: " << eff_hb[1]->GetBinContent(1) << " $\\pm$ " << eff_hb[1]->GetBinError(1) << endl;
   cout << inLeg[2] << " EB Eff: " << eff_hb[2]->GetBinContent(1) << " $\\pm$ " << eff_hb[2]->GetBinError(1) << endl;
   cout << inLeg[3] << " EB Eff: " << eff_hb[3]->GetBinContent(1) << " $\\pm$ " << eff_hb[3]->GetBinError(1) << endl;
   //cout << "Loose Eff EB/EE: [ " << eff_hb[0]->GetBinContent(1) << " $\\pm$ " << eff_hb[0]->GetBinError(1) << ", " << eff_he[0]->GetBinContent(1) << " $\\pm$ " << eff_he[0]->GetBinError(1) << " ] " << varName[0] << endl;

   cout << endl;

   //cout << "EE Pas: "  << gra_pe[0]->GetBinContent(1) << " $\\pm$ " << gra_pe[0]->GetBinError(1) << endl;
   //cout << "EE Tot: "  << gra_te[0]->GetBinContent(1) << " $\\pm$ " << gra_te[0]->GetBinError(1) << endl;
   cout << inLeg[0] << " EE Eff: " << eff_he[0]->GetBinContent(1) << " $\\pm$ " << eff_he[0]->GetBinError(1) << endl;
   cout << inLeg[1] << " EE Eff: " << eff_he[1]->GetBinContent(1) << " $\\pm$ " << eff_he[1]->GetBinError(1) << endl;
   cout << inLeg[2] << " EE Eff: " << eff_he[2]->GetBinContent(1) << " $\\pm$ " << eff_he[2]->GetBinError(1) << endl;
   cout << inLeg[3] << " EE Eff: " << eff_he[3]->GetBinContent(1) << " $\\pm$ " << eff_he[3]->GetBinError(1) << endl;
   //cout << "Tight Eff EB/EE: [ " << eff_hb[1]->GetBinContent(1) << " $\\pm$ " << eff_hb[1]->GetBinError(1) << ", " << eff_he[1]->GetBinContent(1) << " $\\pm$ " << eff_he[1]->GetBinError(1) << " ] " << varName[0] << endl;

   // -------------------------------------------------- //

   TGraph *lineb = new TGraph(nBin + 1, graBins, l1);
   lineb->SetLineColor(kYellow + 1);
   lineb->SetLineWidth(2);

   TGraph *linee = new TGraph(nBin + 1, graBins, l1);
   linee->SetLineColor(kYellow + 1);
   linee->SetLineWidth(2);

   TH1F* sfb = new TH1F("", "", nBin, graBins);
   sfb->Divide(eff_hb[0], eff_hb[1], 1., 1., "B");
   styleHist(sfb, kBlack, 0, 2, 1, 1.0);
   axHist(sfb, 0.801, 1.199, varName[4], 0.061, 0.49, 0.059, varName[2], 0.061, 1.15, 0.059);

   TH1F* sfe = new TH1F("", "", nBin, graBins);
   sfe->Divide(eff_he[0], eff_he[1], 1., 1., "B");
   styleHist(sfe, kBlack, 0, 2, 1, 1.0);
   axHist(sfe, 0.801, 1.199, varName[4], 0.061, 0.49, 0.059, varName[2], 0.061, 1.15, 0.059);

   TLatex txt;
   txt.SetTextSize(0.035);
   txt.SetTextAlign(13);
   string topLeft, topRight;
   topLeft = "#bf{CMS} #it{Preliminary}";
   topRight = "0.8 fb^{-1} (13 TeV)";

   TLegend *bLeg, *eLeg;
   bLeg = new TLegend();
   eLeg = new TLegend();

   string bHead, eHead;
   bHead = "#left|#eta^{e}#right| < " + toStr(etaEB);
   eHead = "1.566 < #left|#eta^{e}#right| < " + toStr(etaEE);

   for (Int_t dH = 0; dH < nH; dH++) {
     bLeg->AddEntry(eff_gb[dH], (inLeg[dH]).c_str(), "lp");
     eLeg->AddEntry(eff_ge[dH], (inLeg[dH]).c_str(), "lp");
   }

   // -------------------------------------------------- //

   TCanvas *c01 = new TCanvas("c01", "c01", 200, 10, 1000, 1000);
   TCanvas *c02 = new TCanvas("c02", "c02", 200, 10, 1000, 1000);

   if (doSF) {

     txt.SetTextSize(0.035);

     styleLeg(bLeg, 2, 0, 0, 42, 0.03, lHead + bHead);
     bLeg->SetX1(0.81); bLeg->SetX2(0.95);
     bLeg->SetY1(0.05); bLeg->SetY2(0.23);

     styleLeg(eLeg, 2, 0, 0, 42, 0.03, lHead + eHead);
     eLeg->SetX1(0.81); eLeg->SetX2(0.95);
     eLeg->SetY1(0.05); eLeg->SetY2(0.23);

     c01->cd();

     TPad *pad1 = new TPad("pad1", "pad1", 0., 0.29, 1., 1.);
     pad1->SetBottomMargin(0);
     pad1->Draw();
     pad1->cd();

     frameHist->Draw();
     for (Int_t eH = 0; eH < nH; eH++) {
       eff_gb[eH]->SetHistogram(frameHist);
       if (eH == 0) eff_gb[eH]->Draw("p");
       else eff_gb[eH]->Draw("psame");

       if (doFit) {
         cout << "EB " << inLeg[eH] << endl;
         eff_gb[eH]->Fit(("fitEB_"  + toStr(eH)).c_str(), "frem");
         cout << endl;
       }

       if (eH == 0) eff_gb[eH]->Draw("p");
       else eff_gb[eH]->Draw("psame");
     }

     lineb->Draw("lsame");

     bLeg->Draw();
     //txt.DrawLatexNDC(0.06, 0.928, topLeft.c_str());
     //txt.DrawLatexNDC(0.783, 0.933, topRight.c_str());

     c01->cd();
     TPad *pad2 = new TPad("pad2", "pad2", 0., 0., 1., 0.29);
     pad2->SetTopMargin(0);
     pad2->SetBottomMargin(0.16);
     pad2->Draw();
     pad2->cd();

     sfb->Draw("");
     lineb->Draw("lsame");
     sfb->Draw("same");

     c02->cd();

     TPad *pad3 = new TPad("pad3", "pad3", 0., 0.29, 1., 1.);
     pad3->SetBottomMargin(0);
     pad3->Draw();
     pad3->cd();

     frameHist->Draw();
     for (Int_t fH = 0; fH < nH; fH++) {
       eff_gb[fH]->SetHistogram(frameHist);
       if (fH == 0) eff_ge[fH]->Draw("p");
       else eff_ge[fH]->Draw("psame");

       if (doFit) {
         cout << "EE " << inLeg[fH] << endl;
         eff_ge[fH]->Fit(("fitEE_"  + toStr(fH)).c_str(), "frem");
         cout << endl;
       }

       if (fH == 0) eff_ge[fH]->Draw("p");
       else eff_ge[fH]->Draw("psame");
     }
     linee->Draw("lsame");

     eLeg->Draw();
     //txt.DrawLatexNDC(0.06, 0.928, topLeft.c_str());
     //txt.DrawLatexNDC(0.783, 0.933, topRight.c_str());

     c02->cd();
     TPad *pad4 = new TPad("pad4", "pad4", 0., 0., 1., 0.29);
     pad4->SetTopMargin(0);
     pad4->SetBottomMargin(0.16);
     pad4->Draw();
     pad4->cd();

     sfe->Draw("");
     linee->Draw("lsame");
     sfe->Draw("same");

   }

   else {

     txt.SetTextSize(0.033);

     styleLeg(bLeg, 2, 0, 0, 42, 0.031, lHead + bHead);
     //styleLeg(bLeg, 2, 0, 0, 42, 0.031, lHead);
     bLeg->SetX1(0.57); bLeg->SetX2(0.935);
     bLeg->SetY1(0.105); bLeg->SetY2(0.205);

     styleLeg(eLeg, 2, 0, 0, 42, 0.031, lHead + eHead);
     eLeg->SetX1(0.57); eLeg->SetX2(0.935);
     eLeg->SetY1(0.105); eLeg->SetY2(0.205);

     c01->cd();
     c01->SetGridy();

     frameHist->Draw();
     for (Int_t gH = 0; gH < nH; gH++) {
       eff_gb[gH]->SetHistogram(frameHist);
       if (gH == 0) eff_gb[gH]->Draw("p");
       else eff_gb[gH]->Draw("psame");

       if (doFit) {
         cout << "EB " << inLeg[gH] << endl;
         eff_gb[gH]->Fit(("fitEB_"  + toStr(gH)).c_str(), "frem");
         cout << endl;
       }

       if (gH == 0) eff_gb[gH]->Draw("p");
       else eff_gb[gH]->Draw("psame");
     }
     //lineb->Draw("lsame");

     bLeg->Draw();
     //txt.DrawLatexNDC(0.06, 0.935, topLeft.c_str());
     //txt.DrawLatexNDC(0.728, 0.940, topRight.c_str());

     c02->cd();
     c02->SetGridy();

     frameHist->Draw();
     for (Int_t hH = 0; hH < nH; hH++) {
       eff_gb[hH]->SetHistogram(frameHist);
       if (hH == 0) eff_ge[hH]->Draw("p");
       else eff_ge[hH]->Draw("psame");

       if (doFit) {
         cout << "EE " << inLeg[hH] << endl;
         eff_ge[hH]->Fit(("fitEE_"  + toStr(hH)).c_str(), "frem");
         cout << endl;
       }

       if (hH == 0) eff_ge[hH]->Draw("p");
       else eff_ge[hH]->Draw("psame");
     }
     //linee->Draw("lsame");

     eLeg->Draw();
     //txt.DrawLatexNDC(0.06, 0.935, topLeft.c_str());
     //txt.DrawLatexNDC(0.728, 0.940, topRight.c_str());

   }

   // -------------------------------------------------- //

   string const outDir = inDir + "plot_aug05/";

   c01->cd();
   //c01->SaveAs((outDir + outPre + "_" + varName[0] + "_eb.pdf").c_str());

   c02->cd();
   //c02->SaveAs((outDir + outPre + "_" + varName[0] + "_ee.pdf").c_str());

   c01->Close(); c02->Close();

   gROOT->ProcessLine(".q");
   
}

void doStuff() {
  gROOT->Reset();

  /*
  cout << "Cluster shape:" << endl << endl;
  tnpIso("sie", 0);
  cout << endl << "### --------------------------------------------------------- ###" << endl << endl;

  cout << "H/E:" << endl << endl;
  tnpIso("hoe", 1);
  cout << endl << "### --------------------------------------------------------- ###" << endl << endl;

  cout << "EcalIso:" << endl << endl;
  tnpIso("ecc", 2);
  cout << endl << "### --------------------------------------------------------- ###" << endl << endl;

  cout << "HcalIso:" << endl << endl;
  tnpIso("hcc", 3);
  cout << endl << "### --------------------------------------------------------- ###" << endl << endl;

  cout << "1/E - 1/P:" << endl << endl;
  tnpIso("eop", 4);
  cout << endl << "### --------------------------------------------------------- ###" << endl << endl;

  cout << "dEta:" << endl << endl;
  tnpIso("des", 7);
  cout << endl << "### --------------------------------------------------------- ###" << endl << endl;

  cout << "dPhi:" << endl << endl;
  tnpIso("dph", 8);
  cout << endl << "### --------------------------------------------------------- ###" << endl << endl;

  cout << "TrkIso:" << endl << endl;
  tnpIso("tki", 9);
  cout << endl << "### --------------------------------------------------------- ###" << endl << endl;

  cout << "Track chi2:" << endl << endl;
  tnpIso("chi", 5);
  cout << endl << "### --------------------------------------------------------- ###" << endl << endl;
  */
  gROOT->ProcessLine(".q");
}



