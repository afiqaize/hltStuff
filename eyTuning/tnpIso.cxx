// For the efficiency of some cut as function of some var
// Usage root -l -b tnpIso.cxx++

#include "TFile.h"
#include "TChain.h"
#include "TTree.h"
#include "TROOT.h"
#include "TBufferFile.h"
#include "TLorentzVector.h"
#include "TF1.h"

#include "hltWP.cxx"
#include "/home/afiqaize/root53434/macros/tdrstyle.C"

//void tnpIso(std::string varName_ = "", int iMaskCut_ = -1) {
void tnpIso() {

   gROOT->Reset();

   setTDRStyle();

   // Everything to tinker with should be here
   //double yMin = 0.8001, yMax = 1.0099;
   double yMin = 0.4501, yMax = 0.9999;
   //double yMin = -0.0199, yMax = 0.0399;
   bool doSF = false, doFit = false;
   std::string lHead = "Run, ";

   std::string varName[6], outPre;
   varName[0] = "hlt";
   outPre = "lolk";
   const int iMaskCut = -1;

   // which looping to use: 1 tnp, 2 cnd
   const int iLoop = 1;

   // -------------------------------------------------- //

   const int nH = 4;

   std::pair <std::string, std::string> pairFileLeg[nH];
   pairFileLeg[0] = std::make_pair("f1", "l1");
   pairFileLeg[1] = std::make_pair("f2", "l2");
   pairFileLeg[2] = std::make_pair("f3", "l3");
   pairFileLeg[3] = std::make_pair("f4", "l4");

   // For Et
   //const int nBin = 22;
   //double graBins[nBin + 1] = {20., 25., 26., 27., 28., 29., 30., 31., 32., 33., 34., 35., 37., 39., 41., 44., 47., 50., 55., 60., 70., 85., 100.};

   // For nVtx
   //const int nBin = 8;
   //double graBins[nBin + 1] = {0., 3., 6., 9., 13., 17., 21., 25., 35.}; // rho
   //double graBins[nBin + 1] = {0.5, 6.5, 10.5, 14.5, 18.5, 22.5, 28.5, 42.5, 60.5}; // nVtx
   //double graBins[nBin + 1] = {0.5, 10.5, 20.5, 30.5, 40.5, 50.5};

   // For eta
   //const int nBin = 13;
   //double graBins[nBin + 1] = {-2.1, -1.56, -1.44, -1.0, -0.6, -0.3, -0.1, 0.1, 0.3, 0.6, 1.0, 1.44, 1.56, 2.1};

   const int nBin = 1;
   double graBins[nBin + 1] = {-0.5, 999.5};

   /*/ For uniform binning
   const int nBin = 14;
   double graBins[nBin + 1], binWd = 250.;
   for (int iBin = 0; iBin <= nBin; iBin++)
     graBins[iBin] = 0. + (iBin * binWd);

   // -------------------------------------------------- /*/

   varName[2] = "nBX"; // x-axis
   varName[3] = "Efficiency";
   varName[4] = pairFileLeg[0].second + " / " + pairFileLeg[1].second;
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

   if (varName[0] == "tkr")
     varName[1] = "Relative TrkIso";

   if (varName[0] == "lol")
     varName[1] = "Test";

   // -------------------------------------------------- //

   TH1::SetDefaultSumw2(true);

   TH1D *gra_tb[nH], *gra_te[nH];
   TH1D *gra_pb[nH], *gra_pe[nH];

   for (int aH = 0; aH < nH; aH++) {
     gra_tb[aH] = new TH1D(("gra_tb_" + toStr(aH)).c_str(), "", nBin, graBins);
     gra_te[aH] = new TH1D(("gra_te_" + toStr(aH)).c_str(), "", nBin, graBins);

     gra_pb[aH] = new TH1D(("gra_pb_" + toStr(aH)).c_str(), "", nBin, graBins);
     gra_pe[aH] = new TH1D(("gra_pe_" + toStr(aH)).c_str(), "", nBin, graBins);
   }

   // -------------------------------------------------- //

   std::string const inDir = "";

   TChain *t1 = new TChain("hltTree");
   for (int iH = 1; iH < nH; iH++)
     t1->Add((inDir + pairFileLeg[iH].first + ".root").c_str());

   bool isMC = false;

   int nRun;
   t1->SetBranchAddress("nRun", &nRun);
   int nLumi;
   t1->SetBranchAddress("nLumi", &nLumi);
   int nEvt;
   t1->SetBranchAddress("nEvt", &nEvt);
   int nBX;
   t1->SetBranchAddress("nBX", &nBX);
   int nOrb;
   t1->SetBranchAddress("nOrb", &nOrb);
   int nSto;
   t1->SetBranchAddress("nSto", &nSto);

   int type;
   t1->SetBranchAddress("itype", &type);
   double weight;
   t1->SetBranchAddress("weight", &weight);
   double puWgt;
   t1->SetBranchAddress("puWgt", &puWgt);
   int nVtx;
   t1->SetBranchAddress("nVtx", &nVtx);
   double rho;
   t1->SetBranchAddress("rho", &rho);

   int pass[10];
   t1->SetBranchAddress("passHLT", pass);
   int genMatch[10];
   t1->SetBranchAddress("genMatch", genMatch);
   int n;
   t1->SetBranchAddress("hlt_n", &n);
   double et[10];
   t1->SetBranchAddress("hlt_et", et);
   double etr[10];
   t1->SetBranchAddress("hlt_etr", etr);
   double e[10];
   t1->SetBranchAddress("hlt_e", e);
   double er[10];
   t1->SetBranchAddress("hlt_er", er);
   double eta[10];
   t1->SetBranchAddress("hlt_eta", eta);
   double phi[10];
   t1->SetBranchAddress("hlt_phi", phi);
   double sie[10];
   t1->SetBranchAddress("hlt_sie", sie);
   double hoe[10];
   t1->SetBranchAddress("hlt_hoe", hoe);
   double eca[10];
   t1->SetBranchAddress("hlt_eca", eca);
   double hca[10];
   t1->SetBranchAddress("hlt_hca", hca);
   double ps2[10];
   t1->SetBranchAddress("hlt_ps2", ps2);
   double eop[10];
   t1->SetBranchAddress("hlt_eop", eop);
   double esp[10];
   t1->SetBranchAddress("hlt_esp", esp);
   double chi[10];
   t1->SetBranchAddress("hlt_chi", chi);
   double mih[10];
   t1->SetBranchAddress("hlt_mih", mih);
   double det[10];
   t1->SetBranchAddress("hlt_det", det);
   double des[10];
   t1->SetBranchAddress("hlt_des", des);
   double dph[10];
   t1->SetBranchAddress("hlt_dph", dph);
   double tks[10];
   t1->SetBranchAddress("hlt_tks", tks);

   int mc_nBX, mc_nPUtrue, gp_n;
   int mc_BX[100], mc_nPUobs[100];
   double genWgt, gp_pt[10], gp_eta[10], gp_phi[10];

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
   double tnpWgt = 1.;
   double tnpY1 = 9999., tnpY2 = 9999.;
   double tnpX = 9999.;
   double cut_b = -1., cut_e = -1.;

   int nEvt0 = t1->GetEntries();

   if (iLoop == 1) { // iLoop 1
     cout << "nEvt0 = " << nEvt0 << endl;
     for (int evt0 = 0; evt0 < nEvt0; evt0++) {

       t1->GetEntry(evt0);
       tnpWgt = puWgt * weight;
       if (n < 2 or type != 1) continue;

       for (int iTag = 0; iTag < n; iTag++) {

         if (pass[iTag] != 1) continue;
         //if (isMC and genMatch[iTag] != 1) continue;
         if (et[iTag] < 25. or std::abs(eta[iTag]) > etaEE) continue;

         p4Tag.SetPtEtaPhiE(et[iTag], eta[iTag], phi[iTag], e[iTag]);

         for (int iProbe = 0; iProbe < n; iProbe++) {

           if (iProbe == iTag) continue;
           //if (isMC and genMatch[iProbe] != 1) continue;
           if (et[iProbe] < 25. or std::abs(eta[iProbe]) > etaEE) continue;

           p4Probe.SetPtEtaPhiE(et[iProbe], eta[iProbe], phi[iProbe], e[iProbe]);

           if ((p4Tag + p4Probe).M() < 70. or (p4Tag + p4Probe).M() > 110.) continue;

           if (!checkCand("", -1, rho,
                          e[iProbe], et[iProbe], eta[iProbe], phi[iProbe],
                          sie[iProbe], hoe[iProbe], eca[iProbe], hca[iProbe], eop[iProbe],
                          chi[iProbe], mih[iProbe], des[iProbe], dph[iProbe], tks[iProbe])) continue;

           // FILL IN THE FILTER TO BE LOOKED AT HERE
           tnpY1 = ecc[iProbe];
           tnpY2 = ecn;
           tnpX = (double) nBX;

           if (type == 1) {

             if (std::abs(eta[iProbe]) < etaEB) {
               if (nRun == 276581) {
                 gra_tb[0]->Fill(tnpX, tnpWgt);

                 if (passNL)
                   gra_pb[0]->Fill(tnpX, tnpWgt);
               }
             }

             if (std::abs(eta[iProbe]) >= etaET) {
               if (nRun == 276581) {
                 gra_te[0]->Fill(tnpX, tnpWgt);

                 if (passNL)
                   gra_pe[0]->Fill(tnpX, tnpWgt);
               }
             }
           }
         } // eol probe
       } // eol tag
     } // eol evt
   } // loop flag

   // -------------------------------------------------- //
   // The all-cand version of efficiency checker

   TLorentzVector p4Cand;
   double cndWgt = 1., cndY = 9999., cndX = 9999.;

   int nEvt1 = t1->GetEntries();

   if (iLoop == 2) { // iLoop 2
     cout << "nEvt1 = " << nEvt1 << endl;
     for (int evt1 = 0; evt1 < nEvt1; evt1++) {

       t1->GetEntry(evt1);
       cndWgt = puWgt * weight;
       if (type != 9999) continue;

       for (int iCand = 0; iCand < n; iCand++) {

         if (et[iCand] < 25. or std::abs(eta[iCand]) > etaEE) continue;
         //if (isMC and genMatch[iCand] != 1) continue;

         if (!checkCand("", -1, rho,
                        e[iCand], et[iCand], eta[iCand], phi[iCand],
                        sie[iCand], hoe[iCand], eca[iCand], hca[iCand], eop[iCand],
                        chi[iCand], mih[iCand], des[iCand], dph[iCand], tks[iCand])) continue;

         // FILL IN THE FILTER TO BE LOOKED AT HERE
         cndY = chi[iCand];
         cndX = (double) nVtx;

         if (std::abs(eta[iCand]) < etaEB) {

           gra_tb[0]->Fill(cndX, cndWgt);

           if (passOL)
             gra_pb[0]->Fill(cndX, cndWgt);
         }

         if (std::abs(eta[iCand]) >= etaET) {

           gra_te[0]->Fill(cndX, cndWgt);

           if (passOL)
             gra_pe[0]->Fill(cndX, cndWgt);
         }
       } // eol cand
     } // eol evt
   } // loop flag

   // -------------------------------------------------- //

   TH1D* frameHist = new TH1D("frameHist", (varName[1] + " Efficiency vs " + varName[5]).c_str(), nBin, graBins);
   axHist(frameHist, yMin, yMax, varName[3], 0.027, 1.05, 0.025, varName[2], 0.027, 1.15, 0.025);

   double l1[nBin + 1];
   TGraphAsymmErrors *eff_gb[nH], *eff_ge[nH];
   TF1 *fitEB[nH], *fitEE[nH];
   TH1D *eff_hb[nH], *eff_he[nH];
   double xb[nH], yb[nH], yeb[nH];
   double xe[nH], ye[nH], yee[nH];

   int kColor;
   for (int bH = 0; bH < nH; bH++) {
     if (bH < 4) kColor = 401 + (16 * (bH % 2));
     if (bH < 2) kColor = 601 + (32 * bH);

     eff_gb[bH] = new TGraphAsymmErrors(gra_pb[bH], gra_tb[bH], "n");
     eff_ge[bH] = new TGraphAsymmErrors(gra_pe[bH], gra_te[bH], "n");

     eff_hb[bH] = new TH1D(("eff_hb_" + toStr(bH)).c_str(), "", nBin, graBins);
     eff_he[bH] = new TH1D(("eff_he_" + toStr(bH)).c_str(), "", nBin, graBins);

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

   for (int iBin = 0; iBin < nBin; iBin++) {
     l1[iBin] = 1.;

     for (int cH = 0; cH < nH; cH++) {
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
   cout << pairFileLeg[0].second << " EB Eff: " << eff_hb[0]->GetBinContent(1) << " $\\pm$ " << eff_hb[0]->GetBinError(1) << endl;
   cout << pairFileLeg[1].second << " EB Eff: " << eff_hb[1]->GetBinContent(1) << " $\\pm$ " << eff_hb[1]->GetBinError(1) << endl;
   cout << pairFileLeg[2].second << " EB Eff: " << eff_hb[2]->GetBinContent(1) << " $\\pm$ " << eff_hb[2]->GetBinError(1) << endl;
   cout << pairFileLeg[3].second << " EB Eff: " << eff_hb[3]->GetBinContent(1) << " $\\pm$ " << eff_hb[3]->GetBinError(1) << endl;
   //cout << "Loose Eff EB/EE: [ " << eff_hb[0]->GetBinContent(1) << " $\\pm$ " << eff_hb[0]->GetBinError(1) << ", " << eff_he[0]->GetBinContent(1) << " $\\pm$ " << eff_he[0]->GetBinError(1) << " ] " << varName[0] << endl;

   cout << endl;

   //cout << "EE Pas: "  << gra_pe[0]->GetBinContent(1) << " $\\pm$ " << gra_pe[0]->GetBinError(1) << endl;
   //cout << "EE Tot: "  << gra_te[0]->GetBinContent(1) << " $\\pm$ " << gra_te[0]->GetBinError(1) << endl;
   cout << pairFileLeg[0].second << " EE Eff: " << eff_he[0]->GetBinContent(1) << " $\\pm$ " << eff_he[0]->GetBinError(1) << endl;
   cout << pairFileLeg[1].second << " EE Eff: " << eff_he[1]->GetBinContent(1) << " $\\pm$ " << eff_he[1]->GetBinError(1) << endl;
   cout << pairFileLeg[2].second << " EE Eff: " << eff_he[2]->GetBinContent(1) << " $\\pm$ " << eff_he[2]->GetBinError(1) << endl;
   cout << pairFileLeg[3].second << " EE Eff: " << eff_he[3]->GetBinContent(1) << " $\\pm$ " << eff_he[3]->GetBinError(1) << endl;
   //cout << "Tight Eff EB/EE: [ " << eff_hb[1]->GetBinContent(1) << " $\\pm$ " << eff_hb[1]->GetBinError(1) << ", " << eff_he[1]->GetBinContent(1) << " $\\pm$ " << eff_he[1]->GetBinError(1) << " ] " << varName[0] << endl;

   // -------------------------------------------------- //

   TGraph *lineb = new TGraph(nBin + 1, graBins, l1);
   lineb->SetLineColor(kYellow + 1);
   lineb->SetLineWidth(2);

   TGraph *linee = new TGraph(nBin + 1, graBins, l1);
   linee->SetLineColor(kYellow + 1);
   linee->SetLineWidth(2);

   TH1D* sfb = new TH1D("", "", nBin, graBins);
   sfb->Divide(eff_hb[0], eff_hb[1], 1., 1., "B");
   styleHist(sfb, kBlack, 0, 2, 1, 1.0);
   axHist(sfb, 0.801, 1.199, varName[4], 0.061, 0.49, 0.059, varName[2], 0.061, 1.15, 0.059);

   TH1D* sfe = new TH1D("", "", nBin, graBins);
   sfe->Divide(eff_he[0], eff_he[1], 1., 1., "B");
   styleHist(sfe, kBlack, 0, 2, 1, 1.0);
   axHist(sfe, 0.801, 1.199, varName[4], 0.061, 0.49, 0.059, varName[2], 0.061, 1.15, 0.059);

   TLatex txt;
   txt.SetTextSize(0.035);
   txt.SetTextAlign(13);
   std::string topLeft, topRight;
   topLeft = "#bf{CMS} #it{Preliminary}";
   topRight = "Many fb^{-1} (13 TeV)";

   TLegend *bLeg, *eLeg;
   bLeg = new TLegend();
   eLeg = new TLegend();

   std::string bHead, eHead;
   bHead = "#left|#eta^{e}#right| < " + toStr(etaEB);
   eHead = "1.566 < #left|#eta^{e}#right| < " + toStr(etaEE);

   for (int dH = 0; dH < nH; dH++) {
     bLeg->AddEntry(eff_gb[dH], (pairFileLeg[dH].second).c_str(), "lp");
     eLeg->AddEntry(eff_ge[dH], (pairFileLeg[dH].second).c_str(), "lp");
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
     for (int eH = 0; eH < nH; eH++) {
       eff_gb[eH]->SetHistogram(frameHist);
       if (eH == 0) eff_gb[eH]->Draw("p");
       else eff_gb[eH]->Draw("psame");

       if (doFit) {
         cout << "EB " << pairFileLeg[eH].second << endl;
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
     for (int fH = 0; fH < nH; fH++) {
       eff_gb[fH]->SetHistogram(frameHist);
       if (fH == 0) eff_ge[fH]->Draw("p");
       else eff_ge[fH]->Draw("psame");

       if (doFit) {
         cout << "EE " << pairFileLeg[fH].second << endl;
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
     for (int gH = 0; gH < nH; gH++) {
       eff_gb[gH]->SetHistogram(frameHist);
       if (gH == 0) eff_gb[gH]->Draw("p");
       else eff_gb[gH]->Draw("psame");

       if (doFit) {
         cout << "EB " << pairFileLeg[gH].second << endl;
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
     for (int hH = 0; hH < nH; hH++) {
       eff_gb[hH]->SetHistogram(frameHist);
       if (hH == 0) eff_ge[hH]->Draw("p");
       else eff_ge[hH]->Draw("psame");

       if (doFit) {
         cout << "EE " << pairFileLeg[hH].second << endl;
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

   std::string const outDir = inDir + "plot_aug05/";

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
  tnpIso("tkr", 9);
  cout << endl << "### --------------------------------------------------------- ###" << endl << endl;

  cout << "Track chi2:" << endl << endl;
  tnpIso("chi", 5);
  cout << endl << "### --------------------------------------------------------- ###" << endl << endl;
  */
  gROOT->ProcessLine(".q");
}



