// For the efficiency of some cut as function of some var
// Usage with ROOT5 root -l -b hltEff.cxx++

#include "TLorentzVector.h"
#include "TF1.h"

#include "hltWP.cxx"
#include "plotStuff.cxx"
#include "/home/afiqaize/root53434/macros/tdrstyle.C"

//void hltEff(std::string varName_ = "", std::string sMaskCut_ = "") {
void hltEff() {
   gROOT->Reset();
   //gROOT->SetBatch(kTRUE);

   setTDRStyle();

   // Everything to tinker with should be here
   double yMin = 0.1001, yMax = 1.0499;
   //double yMin = 0.4001, yMax = 0.9999;
   //double yMin = -0.0199, yMax = 0.0399;
   bool doSF = false, doFit = false;
   std::string lHead = "";

   std::string outPre;
   hltLabel hltLbl;
   hltLbl.fileName = "hlt";
   outPre = "xxRho";

   // which looping to use: 1 tnp, 2 cnd
   const int iLoop = 1;

   // -------------------------------------------------- //

   const int nH = 4;
   std::string const inDir = "/home/afiqaize/Downloads/EGM/dev/e_90x/wpTune_110517/skim_v1/";
   std::string const outDir = inDir + "../plot_v1/varTune_2/";

   std::pair <std::string, std::string> pairFileLeg[nH];
   pairFileLeg[0] = std::make_pair("skim_dy", "Tight16");
   pairFileLeg[1] = std::make_pair("skim_dy", "Tight17-0");
   pairFileLeg[2] = std::make_pair("skim_dy", "Tight17-1");
   pairFileLeg[3] = std::make_pair("skim_dy", "Loose17-1");

   int kColors[nH] = {kBlack, kSpring - 1, kAzure - 1, kPink - 1};

   std::vector<std::string> vCalo;
   vCalo.push_back("hor");
   vCalo.push_back("ecr");
   vCalo.push_back("hcr");

   std::vector<std::string> vVarMask;
   vVarMask.push_back("dph");
   vVarMask.push_back("hor");
   //vVarMask.push_back("ecr");
   //vVarMask.push_back("hcr");
   vVarMask.push_back("tkr");

   std::vector<std::string> vAIso;
   vAIso.push_back("hor");
   vAIso.push_back("ecr");
   vAIso.push_back("hcr");
   vAIso.push_back("tkr");
   /*
   pairFileLeg[0] = std::make_pair("skim_dy", "EA 95");
   pairFileLeg[1] = std::make_pair("skim_dy", "EA 97");
   pairFileLeg[2] = std::make_pair("skim_dy", "EA, NT 95");
   pairFileLeg[3] = std::make_pair("skim_dy", "EA, NT 97");

   int kColors[nH] = {kBlack, kAzure - 1, kSpring - 1, kPink - 1};*/

   // For Et
   //const int nBin = 17;
   //double graBins[nBin + 1] = {20., 30., 31., 32., 33., 34., 35., 37., 39., 41., 44., 47., 50., 55., 60., 70., 85., 100.};
   //hltLbl.xLabel = "E_{T} (GeV)"; // x-axis
   //hltLbl.funcTitle = "E_{T}"; // title

   // For nVtx
   const int nBin = 8;
   double graBins[nBin + 1] = {0., 3., 6., 9., 13., 17., 21., 25., 35.}; // rho
   //double graBins[nBin + 1] = {0.5, 6.5, 10.5, 14.5, 18.5, 22.5, 28.5, 42.5, 60.5}; // nVtx
   hltLbl.xLabel = "#rho (GeV)"; // x-axis
   hltLbl.funcTitle = "#rho"; // title

   // For eta
   //const int nBin = 15;
   //double graBins[nBin + 1] = {-2.5, -2.1, -1.56, -1.44, -1.0, -0.6, -0.3, -0.1, 0.1, 0.3, 0.6, 1.0, 1.44, 1.56, 2.1, 2.5};
   //hltLbl.xLabel = "#eta"; // x-axis
   //hltLbl.funcTitle = "#eta"; // title

   /*/ For uniform binning
   const int nBin = 14;
   double graBins[nBin + 1], binWd = 250.;
   for (int iBin = 0; iBin <= nBin; iBin++)
     graBins[iBin] = 0. + (iBin * binWd);

   // -------------------------------------------------- /*/

   hltLbl.yLabel = "Efficiency";
   hltLbl.sLabel = pairFileLeg[0].second + " / " + pairFileLeg[1].second;

   if (hltLbl.fileName == "hlt")
     hltLbl.varTitle = "Working Point";

   if (hltLbl.fileName == "sie")
     hltLbl.varTitle = "Cluster Shape";

   if (hltLbl.fileName == "hoe")
     hltLbl.varTitle = "Hadronic / EM";

   if (hltLbl.fileName == "ecc")
     hltLbl.varTitle = "Relative EcalIso";

   if (hltLbl.fileName == "hcc")
     hltLbl.varTitle = "Relative HcalIso";

   if (hltLbl.fileName == "eop")
     hltLbl.varTitle = "1/E - 1/P";

   if (hltLbl.fileName == "mih")
     hltLbl.varTitle = "Missing Tracker Hits";

   if (hltLbl.fileName == "des")
     hltLbl.varTitle = "Track - Seed Cluster #Delta#eta";

   if (hltLbl.fileName == "dph")
     hltLbl.varTitle = "Track - SC #Delta#phi";

   if (hltLbl.fileName == "chi")
     hltLbl.varTitle = "Track Fit #chi^{2}";

   if (hltLbl.fileName == "tkr")
     hltLbl.varTitle = "Relative TrkIso";

   if (hltLbl.fileName == "lol")
     hltLbl.varTitle = "Test";

   // -------------------------------------------------- //

   TH1::SetDefaultSumw2(true);

   TH1D *gra_tb[nH], *gra_te[nH];
   TH1D *gra_pb[nH], *gra_pe[nH];

   for (int iH = 0; iH < nH; iH++) {
     gra_tb[iH] = new TH1D(("gra_tb_" + toStr(iH)).c_str(), "", nBin, graBins);
     gra_te[iH] = new TH1D(("gra_te_" + toStr(iH)).c_str(), "", nBin, graBins);

     gra_pb[iH] = new TH1D(("gra_pb_" + toStr(iH)).c_str(), "", nBin, graBins);
     gra_pe[iH] = new TH1D(("gra_pe_" + toStr(iH)).c_str(), "", nBin, graBins);
   }

   // -------------------------------------------------- //

   // Ensure that each file is added just once
   TChain *t1 = new TChain("hltTree");
   for (int iH = 0; iH < 1; iH++)
     t1->Add((inDir + pairFileLeg[iH].first + ".root").c_str());

   const bool isMC = true;

   //hltTreeBranchAddresses(isMC, t1);

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
   double normWgt;
   t1->SetBranchAddress("normWgt", &normWgt);
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

   int mc_nPUtrue, gp_n, mc_nPUobs;
   double genWgt, gp_pt[10], gp_eta[10], gp_phi[10];

    if (isMC) {
      t1->SetBranchAddress("genWgt", &genWgt);
      t1->SetBranchAddress("gp_n", &gp_n);
      t1->SetBranchAddress("gp_pt", gp_pt);
      t1->SetBranchAddress("gp_eta", gp_eta);
      t1->SetBranchAddress("gp_phi", gp_phi);
      t1->SetBranchAddress("mc_nPUtrue", &mc_nPUtrue);
      t1->SetBranchAddress("mc_nPUobs", &mc_nPUobs);
    }

   // -------------------------------------------------- //
   // The TnP version of efficiency checker

   TLorentzVector p4Tag, p4Probe;
   double tnpWgt = 1.;
   double tnpX = 9999.;
   double cut_b = -1., cut_e = -1.;

   int nEvt0 = t1->GetEntries();

   if (iLoop == 1) { // iLoop 1
     std::cout << "nEvt0 = " << nEvt0 << std::endl;
     for (int evt0 = 0; evt0 < nEvt0; evt0++) {

       t1->GetEntry(evt0);
       if (n < 2 or type != -1) continue;

       tnpWgt = puWgt * normWgt;
       if (isMC) tnpWgt *= genWgt;

       for (int iTag = 0; iTag < n; iTag++) {

         //if (pass[iTag] != 1) continue;
         if (isMC and genMatch[iTag] != 1) continue;
         if (et[iTag] < 35. or std::abs(eta[iTag]) > etaEE) continue;

         p4Tag.SetPtEtaPhiE(et[iTag], eta[iTag], phi[iTag], e[iTag]);

         for (int iProbe = 0; iProbe < n; iProbe++) {

           if (iProbe == iTag) continue;
           if (isMC and genMatch[iProbe] != 1) continue;
           if (et[iProbe] < 35. or std::abs(eta[iProbe]) > etaEE) continue;

           p4Probe.SetPtEtaPhiE(et[iProbe], eta[iProbe], phi[iProbe], e[iProbe]);

           if ((p4Tag + p4Probe).M() < 70. or (p4Tag + p4Probe).M() > 110.) continue;

           if (!checkCand("", vNoMask, rho,
                          e[iProbe], et[iProbe], eta[iProbe], phi[iProbe],
                          sie[iProbe], hoe[iProbe], eca[iProbe], hca[iProbe], eop[iProbe],
                          chi[iProbe], mih[iProbe], des[iProbe], dph[iProbe], tks[iProbe],
                          ps2[iProbe])) continue;

           const bool passTight16 = checkCand("Tight16", vNoMask, rho,
                                              e[iProbe], et[iProbe], eta[iProbe], phi[iProbe],
                                              sie[iProbe], hoe[iProbe], eca[iProbe], hca[iProbe], eop[iProbe],
                                              chi[iProbe], mih[iProbe], des[iProbe], dph[iProbe], tks[iProbe],
                                              ps2[iProbe]);

           const bool passEye0 = checkCand("EyeBall0_etAll", vNoMask, rho,
                                           e[iProbe], et[iProbe], eta[iProbe], phi[iProbe],
                                           sie[iProbe], hoe[iProbe], eca[iProbe], hca[iProbe], eop[iProbe],
                                           chi[iProbe], mih[iProbe], des[iProbe], dph[iProbe], tks[iProbe],
                                           ps2[iProbe]);

           const bool passItTig = checkCand("IterTig_etAll", vNoMask, rho,
                                            e[iProbe], et[iProbe], eta[iProbe], phi[iProbe],
                                            sie[iProbe], hoe[iProbe], eca[iProbe], hca[iProbe], eop[iProbe],
                                            chi[iProbe], mih[iProbe], des[iProbe], dph[iProbe], tks[iProbe],
                                            ps2[iProbe]);

           const bool passItLoo = checkCand("IterLoo_etAll", vNoMask, rho,
                                            e[iProbe], et[iProbe], eta[iProbe], phi[iProbe],
                                            sie[iProbe], hoe[iProbe], eca[iProbe], hca[iProbe], eop[iProbe],
                                            chi[iProbe], mih[iProbe], des[iProbe], dph[iProbe], tks[iProbe],
                                            ps2[iProbe]);

           const bool isoEA95 = checkCand("EA17_q0p95", vNoMask, rho,
                                          e[iProbe], et[iProbe], eta[iProbe], phi[iProbe],
                                          sie[iProbe], hoe[iProbe], eca[iProbe], hca[iProbe], eop[iProbe],
                                          chi[iProbe], mih[iProbe], des[iProbe], dph[iProbe], tks[iProbe],
                                          ps2[iProbe]);

           const bool isoEA97 = checkCand("EA17_q0p97", vNoMask, rho,
                                          e[iProbe], et[iProbe], eta[iProbe], phi[iProbe],
                                          sie[iProbe], hoe[iProbe], eca[iProbe], hca[iProbe], eop[iProbe],
                                          chi[iProbe], mih[iProbe], des[iProbe], dph[iProbe], tks[iProbe],
                                          ps2[iProbe]);

           const bool isoNT95 = checkCand("EANT17_q0p95", vNoMask, rho,
                                          e[iProbe], et[iProbe], eta[iProbe], phi[iProbe],
                                          sie[iProbe], hoe[iProbe], eca[iProbe], hca[iProbe], eop[iProbe],
                                          chi[iProbe], mih[iProbe], des[iProbe], dph[iProbe], tks[iProbe],
                                          ps2[iProbe]);

           const bool isoNT97 = checkCand("EANT17_q0p97", vNoMask, rho,
                                          e[iProbe], et[iProbe], eta[iProbe], phi[iProbe],
                                          sie[iProbe], hoe[iProbe], eca[iProbe], hca[iProbe], eop[iProbe],
                                          chi[iProbe], mih[iProbe], des[iProbe], dph[iProbe], tks[iProbe],
                                          ps2[iProbe]);

           // FILL IN THE FILTER TO BE LOOKED AT HERE
           tnpX = rho /*eta[iProbe]*/;

           if (true) {
             if (true and std::abs(eta[iProbe]) < etaEB) {
               for (int iH = 0; iH < nH; iH++)
                 gra_tb[iH]->Fill(tnpX, tnpWgt);

               if (passTight16)
                 gra_pb[0]->Fill(tnpX, tnpWgt);
               if (passEye0)
                 gra_pb[1]->Fill(tnpX, tnpWgt);
               if (passItTig)
                 gra_pb[2]->Fill(tnpX, tnpWgt);
               if (passItLoo)
                 gra_pb[3]->Fill(tnpX, tnpWgt);
             }

             if (std::abs(eta[iProbe]) >= etaET) {
               for (int iH = 0; iH < nH; iH++)
                 gra_te[iH]->Fill(tnpX, tnpWgt);

               if (passTight16)
                 gra_pe[0]->Fill(tnpX, tnpWgt);
               if (passEye0)
                 gra_pe[1]->Fill(tnpX, tnpWgt);
               if (passItTig)
                 gra_pe[2]->Fill(tnpX, tnpWgt);
               if (passItLoo)
                 gra_pe[3]->Fill(tnpX, tnpWgt);
             }
           }
         } // eol probe
       } // eol tag
     } // eol evt
   } // loop flag

   // -------------------------------------------------- //
   // The all-cand version of efficiency checker

   TLorentzVector p4Cand;
   double cndWgt = 1., cndX = 9999.;

   int nEvt1 = t1->GetEntries();

   if (iLoop == 2) { // iLoop 2
     std::cout << "nEvt1 = " << nEvt1 << std::endl;
     for (int evt1 = 0; evt1 < nEvt1; evt1++) {

       t1->GetEntry(evt1);

       cndWgt = puWgt * normWgt;
       if (isMC) cndWgt *= genWgt;

       if (type != 9999) continue;

       for (int iCand = 0; iCand < n; iCand++) {

         if (et[iCand] < 25. or std::abs(eta[iCand]) > etaEE) continue;
         //if (isMC and genMatch[iCand] != 1) continue;

         if (!checkCand("", vNoMask, rho,
                        e[iCand], et[iCand], eta[iCand], phi[iCand],
                        sie[iCand], hoe[iCand], eca[iCand], hca[iCand], eop[iCand],
                        chi[iCand], mih[iCand], des[iCand], dph[iCand], tks[iCand],
                        ps2[iCand])) continue;

         // FILL IN THE FILTER TO BE LOOKED AT HERE
         cndX = (double) nVtx;

         if (std::abs(eta[iCand]) < etaEB) {
           for (int iH = 0; iH < nH; iH++)
             gra_tb[iH]->Fill(cndX, cndWgt);

           if (true)
             gra_pb[0]->Fill(cndX, cndWgt);
         }

         if (std::abs(eta[iCand]) >= etaET) {
           for (int iH = 0; iH < nH; iH++)
             gra_tb[iH]->Fill(cndX, cndWgt);

           if (true)
             gra_pe[0]->Fill(cndX, cndWgt);
         }
       } // eol cand
     } // eol evt
   } // loop flag

   // -------------------------------------------------- //

   TH1F* frameHist = new TH1F("frameHist", (hltLbl.varTitle + " Efficiency vs " + hltLbl.funcTitle).c_str(), nBin, graBins);
   axHist(frameHist, yMin, yMax, hltLbl.yLabel, 0.027, 1.05, 0.025, hltLbl.xLabel, 0.027, 1.15, 0.025);

   double l1[nBin + 1];
   TGraphAsymmErrors *eff_gb[nH], *eff_ge[nH];
   TF1 *fitEB[nH], *fitEE[nH];
   TH1D *eff_hb[nH], *eff_he[nH];
   double xb[nH], yb[nH], yeb[nH];
   double xe[nH], ye[nH], yee[nH];

   int kColor;
   for (int iH = 0; iH < nH; iH++) {
     kColor = kColors[iH];

     eff_gb[iH] = new TGraphAsymmErrors(gra_pb[iH], gra_tb[iH], "n");
     eff_ge[iH] = new TGraphAsymmErrors(gra_pe[iH], gra_te[iH], "n");

     eff_hb[iH] = new TH1D(("eff_hb_" + toStr(iH)).c_str(), "", nBin, graBins);
     eff_he[iH] = new TH1D(("eff_he_" + toStr(iH)).c_str(), "", nBin, graBins);

     styleGr(eff_gb[iH], kColor, 0, 20, 1, 2.0);
     styleGr(eff_ge[iH], kColor, 0, 20, 1, 2.0);

     xb[iH] = 0.; yb[iH] = 0.; yeb[iH] = 0;
     xe[iH] = 0.; ye[iH] = 0.; yee[iH] = 0;

     fitEB[iH] = new TF1(("fitEB_"  + toStr(iH)).c_str(), " ([0]*x + [1]) ", graBins[0], graBins[nBin]);
     fitEB[iH]->SetLineColor(kColor);
     fitEB[iH]->SetLineWidth(2.0);
     fitEB[iH]->SetParameter(0, -0.000001);
     fitEB[iH]->SetParameter(1, 0.999 ); // DY 0.85 QCD 0.007 nm1 0.999

     fitEE[iH] = new TF1(("fitEE_"  + toStr(iH)).c_str(), " ([0]*x + [1]) ", graBins[0], graBins[nBin]);
     fitEE[iH]->SetLineColor(kColor);
     fitEE[iH]->SetLineWidth(2.0);
     fitEE[iH]->SetParameter(0, -0.000001);
     fitEE[iH]->SetParameter(1, 0.99 ); // DY 0.75 QCD 0.01 nm1 0.99
   }

   for (int iBin = 0; iBin < nBin; iBin++) {
     l1[iBin] = 1.;

     for (int iH = 0; iH < nH; iH++) {
       eff_gb[iH]->GetPoint(iBin, xb[iH], yb[iH]);
       yeb[iH] = eff_gb[iH]->GetErrorY(iBin);

       eff_hb[iH]->SetBinContent(iBin + 1, yb[iH]);
       eff_hb[iH]->SetBinError(iBin + 1, yeb[iH]);

       eff_ge[iH]->GetPoint(iBin, xe[iH], ye[iH]);
       yee[iH] = eff_ge[iH]->GetErrorY(iBin);

       eff_he[iH]->SetBinContent(iBin + 1, ye[iH]);
       eff_he[iH]->SetBinError(iBin + 1, yee[iH]);
     }
   }
   l1[nBin] = 1.;

   // -------------------------------------------------- //

   TGraph *lineb = new TGraph(nBin + 1, graBins, l1);
   lineb->SetLineColor(kYellow + 1);
   lineb->SetLineWidth(2);

   TGraph *linee = new TGraph(nBin + 1, graBins, l1);
   linee->SetLineColor(kYellow + 1);
   linee->SetLineWidth(2);

   TH1D* sfb = new TH1D("", "", nBin, graBins);
   TH1D* sfe = new TH1D("", "", nBin, graBins);
   if (doSF) {
     //sfb->Divide(eff_hb[0], eff_hb[1], 1., 1., "B");
     styleHist(sfb, kBlack, 0, 2, 1, 1.0);
     axHist(sfb, 0.801, 1.199, hltLbl.sLabel, 0.061, 0.49, 0.059, hltLbl.xLabel, 0.061, 1.15, 0.059);

     //sfe->Divide(eff_he[0], eff_he[1], 1., 1., "B");
     styleHist(sfe, kBlack, 0, 2, 1, 1.0);
     axHist(sfe, 0.801, 1.199, hltLbl.sLabel, 0.061, 0.49, 0.059, hltLbl.xLabel, 0.061, 1.15, 0.059);
   }

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

   if (hltLbl.funcTitle == "#eta")
     bHead = "";

   for (int iH = 0; iH < nH; iH++) {
     bLeg->AddEntry(eff_gb[iH], (pairFileLeg[iH].second).c_str(), "lp");
     eLeg->AddEntry(eff_ge[iH], (pairFileLeg[iH].second).c_str(), "lp");
   }

   // -------------------------------------------------- //

   TCanvas *c01 = new TCanvas("c01", "c01", 200, 10, 1000, 1000);
   TCanvas *c02 = new TCanvas("c02", "c02", 200, 10, 1000, 1000);

   if (doSF) {
     txt.SetTextSize(0.035);

     styleLeg(bLeg, 2, 0, 0, 42, 0.03, lHead + bHead);
     putLeg(bLeg, 0.81, 0.95, 0.09, 0.21);

     styleLeg(eLeg, 2, 0, 0, 42, 0.03, lHead + eHead);
     putLeg(eLeg, 0.81, 0.95, 0.09, 0.21);

     c01->cd();

     TPad *pad1 = new TPad("pad1", "pad1", 0., 0.29, 1., 1.);
     pad1->SetBottomMargin(0);
     pad1->Draw();
     pad1->cd();

     frameHist->Draw();
     for (int iH = 0; iH < nH; iH++) {
       eff_gb[iH]->SetHistogram(frameHist);
       if (iH == 0) eff_gb[iH]->Draw("p");
       else eff_gb[iH]->Draw("psame");

       if (doFit) {
         std::cout << "EB " << pairFileLeg[iH].second << std::endl;
         eff_gb[iH]->Fit(("fitEB_"  + toStr(iH)).c_str(), "frem");
         std::cout << std::endl;
       }

       if (iH == 0) eff_gb[iH]->Draw("p");
       else eff_gb[iH]->Draw("psame");
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
     for (int iH = 0; iH < nH; iH++) {
       eff_gb[iH]->SetHistogram(frameHist);
       if (iH == 0) eff_ge[iH]->Draw("p");
       else eff_ge[iH]->Draw("psame");

       if (doFit) {
         std::cout << "EE " << pairFileLeg[iH].second << std::endl;
         eff_ge[iH]->Fit(("fitEE_"  + toStr(iH)).c_str(), "frem");
         std::cout << std::endl;
       }

       if (iH == 0) eff_ge[iH]->Draw("p");
       else eff_ge[iH]->Draw("psame");
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
     putLeg(bLeg, 0.57, 0.935, 0.115, 0.21);

     styleLeg(eLeg, 2, 0, 0, 42, 0.031, lHead + eHead);
     putLeg(eLeg, 0.57, 0.935, 0.115, 0.21);

     c01->cd();
     c01->SetGridy();

     frameHist->Draw();
     for (int iH = 0; iH < nH; iH++) {
       eff_gb[iH]->SetHistogram(frameHist);
       if (iH == 0) eff_gb[iH]->Draw("p");
       else eff_gb[iH]->Draw("psame");

       if (doFit) {
         std::cout << "EB " << pairFileLeg[iH].second << std::endl;
         eff_gb[iH]->Fit(("fitEB_"  + toStr(iH)).c_str(), "frem");
         std::cout << std::endl;
       }

       if (iH == 0) eff_gb[iH]->Draw("p");
       else eff_gb[iH]->Draw("psame");
     }
     //lineb->Draw("lsame");

     bLeg->Draw();
     //txt.DrawLatexNDC(0.06, 0.935, topLeft.c_str());
     //txt.DrawLatexNDC(0.728, 0.940, topRight.c_str());

     c02->cd();
     c02->SetGridy();

     frameHist->Draw();
     for (int iH = 0; iH < nH; iH++) {
       eff_gb[iH]->SetHistogram(frameHist);
       if (iH == 0) eff_ge[iH]->Draw("p");
       else eff_ge[iH]->Draw("psame");

       if (doFit) {
         std::cout << "EE " << pairFileLeg[iH].second << std::endl;
         eff_ge[iH]->Fit(("fitEE_"  + toStr(iH)).c_str(), "frem");
         std::cout << std::endl;
       }

       if (iH == 0) eff_ge[iH]->Draw("p");
       else eff_ge[iH]->Draw("psame");
     }
     //linee->Draw("lsame");

     eLeg->Draw();
     //txt.DrawLatexNDC(0.06, 0.935, topLeft.c_str());
     //txt.DrawLatexNDC(0.728, 0.940, topRight.c_str());
   }

   // -------------------------------------------------- //

   c01->cd();
   c01->SaveAs((outDir + outPre + "_" + hltLbl.fileName + "_eb.pdf").c_str());
   c01->SaveAs((outDir + outPre + "_" + hltLbl.fileName + "_eb.C").c_str());

   c02->cd();
   c02->SaveAs((outDir + outPre + "_" + hltLbl.fileName + "_ee.pdf").c_str());
   c02->SaveAs((outDir + outPre + "_" + hltLbl.fileName + "_ee.C").c_str());

   c01->Close(); c02->Close();

   gROOT->ProcessLine(".q");
   
}

void doStuff() {
  gROOT->Reset();

  /*
  std::cout << "Cluster shape:" << std::endl << std::endl;
  hltEff("sie", "sie");
  std::cout << std::endl << "### --------------------------------------------------------- ###" << std::endl << std::endl;

  std::cout << "H/E:" << std::endl << std::endl;
  hltEff("hor", "hor");
  std::cout << std::endl << "### --------------------------------------------------------- ###" << std::endl << std::endl;

  std::cout << "EcalIso:" << std::endl << std::endl;
  hltEff("ecr", "ecr");
  std::cout << std::endl << "### --------------------------------------------------------- ###" << std::endl << std::endl;

  std::cout << "HcalIso:" << std::endl << std::endl;
  hltEff("hcr", "hcr");
  std::cout << std::endl << "### --------------------------------------------------------- ###" << std::endl << std::endl;

  std::cout << "1/E - 1/P:" << std::endl << std::endl;
  hltEff("eop", "eop");
  std::cout << std::endl << "### --------------------------------------------------------- ###" << std::endl << std::endl;

  std::cout << "dEta:" << std::endl << std::endl;
  hltEff("des", "des");
  std::cout << std::endl << "### --------------------------------------------------------- ###" << std::endl << std::endl;

  std::cout << "dPhi:" << std::endl << std::endl;
  hltEff("dph", "dph");
  std::cout << std::endl << "### --------------------------------------------------------- ###" << std::endl << std::endl;

  std::cout << "TrkIso:" << std::endl << std::endl;
  hltEff("tkr", "tkr");
  std::cout << std::endl << "### --------------------------------------------------------- ###" << std::endl << std::endl;

  std::cout << "Track chi2:" << std::endl << std::endl;
  hltEff("chi", "chi");
  std::cout << std::endl << "### --------------------------------------------------------- ###" << std::endl << std::endl;
  */
  gROOT->ProcessLine(".q");
}



