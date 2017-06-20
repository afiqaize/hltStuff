// Specialized from hltEff: for integrated efficiencies
// Usage with ROOT5 root -l -b hltRat.cxx++

#include "TLorentzVector.h"
#include "TF1.h"

#include "hltWP.cxx"
#include "plotStuff.cxx"
#include "/home/afiqaize/root53434/macros/tdrstyle.C"

//void tnpIso(std::string varName_ = "", std::string sMaskCut_ = "") {
void hltRat() {

   gROOT->Reset();
   //gROOT->SetBatch(kTRUE);

   setTDRStyle();

   const int nH = 4;
   std::string const inDir = "/home/afiqaize/Downloads/EGM/dev/e_90x/wpTune_110517/skim_v1/";

   // which looping to use: 1 tnp, 2 cnd
   const int iLoop = 2;
   const bool checkGen = false;

   std::pair <std::string, std::string> pairFileLeg[nH];
   //pairFileLeg[0] = std::make_pair("skim_dy", "DY Tight16");
   //pairFileLeg[1] = std::make_pair("skim_dy", "DY Tight17-0");
   //pairFileLeg[2] = std::make_pair("skim_dy", "DY Tight17-1");
   //pairFileLeg[3] = std::make_pair("skim_dy", "DY Loose17-1");
   pairFileLeg[0] = std::make_pair("skim_qcd_in", "QCD Tight16");
   pairFileLeg[1] = std::make_pair("skim_qcd_in", "QCD Tight17-0");
   pairFileLeg[2] = std::make_pair("skim_qcd_in", "QCD Tight17-1");
   pairFileLeg[3] = std::make_pair("skim_qcd_in", "QCD Loose17-1");
   //pairFileLeg[0] = std::make_pair("skim_wev_tt", "tt Tight16");
   //pairFileLeg[1] = std::make_pair("skim_wev_tt", "tt Tight17-0");
   //pairFileLeg[2] = std::make_pair("skim_wev_tt", "tt Tight17-1");
   //pairFileLeg[3] = std::make_pair("skim_wev_tt", "tt Loose17-1");

   const int nBin = 1;
   double graBins[nBin + 1] = {-999999., 999999.};

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

   //hltTreeBranchAddresses(isMC, t1);

   const bool isMC = true;

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
           //if (et[iProbe] > 60.) continue;

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

           const bool passEyeBall = checkCand("EyeBall0_etAll", vNoMask, rho,
                                              e[iProbe], et[iProbe], eta[iProbe], phi[iProbe],
                                              sie[iProbe], hoe[iProbe], eca[iProbe], hca[iProbe], eop[iProbe],
                                              chi[iProbe], mih[iProbe], des[iProbe], dph[iProbe], tks[iProbe],
                                              ps2[iProbe]);

           const bool passIterTig = checkCand("IterTig_etAll", vNoMask, rho,
                                              e[iProbe], et[iProbe], eta[iProbe], phi[iProbe],
                                              sie[iProbe], hoe[iProbe], eca[iProbe], hca[iProbe], eop[iProbe],
                                              chi[iProbe], mih[iProbe], des[iProbe], dph[iProbe], tks[iProbe],
                                              ps2[iProbe]);

           const bool passIterLoo = checkCand("IterLoo_etAll", vNoMask, rho,
                                              e[iProbe], et[iProbe], eta[iProbe], phi[iProbe],
                                              sie[iProbe], hoe[iProbe], eca[iProbe], hca[iProbe], eop[iProbe],
                                              chi[iProbe], mih[iProbe], des[iProbe], dph[iProbe], tks[iProbe],
                                              ps2[iProbe]);

           // FILL IN THE FILTER TO BE LOOKED AT HERE
           tnpX = et[iProbe];

           if (true) {
             if (std::abs(eta[iProbe]) < etaEB) {
               for (int iH = 0; iH < nH; iH++)
                 gra_tb[iH]->Fill(tnpX, tnpWgt);

               if (passTight16)
                 gra_pb[0]->Fill(tnpX, tnpWgt);
               if (passEyeBall)
                 gra_pb[1]->Fill(tnpX, tnpWgt);
               if (passIterTig)
                 gra_pb[2]->Fill(tnpX, tnpWgt);
               if (passIterLoo)
                 gra_pb[3]->Fill(tnpX, tnpWgt);
             }

             if (std::abs(eta[iProbe]) >= etaET) {
               for (int iH = 0; iH < nH; iH++)
                 gra_te[iH]->Fill(tnpX, tnpWgt);

               if (passTight16)
                 gra_pe[0]->Fill(tnpX, tnpWgt);
               if (passEyeBall)
                 gra_pe[1]->Fill(tnpX, tnpWgt);
               if (passIterTig)
                 gra_pe[2]->Fill(tnpX, tnpWgt);
               if (passIterLoo)
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

       //if (type != -4) continue; // 05 06 2017: qcd in > 0, em > 10, wev -3, tt -4

       for (int iCand = 0; iCand < n; iCand++) {

         if (et[iCand] < 35. or std::abs(eta[iCand]) > etaEE) continue;
         if (isMC and checkGen and genMatch[iCand] != 1) continue;
         //if (et[iCand] > 60.) continue;

         if (!checkCand("", vNoMask, rho,
                        e[iCand], et[iCand], eta[iCand], phi[iCand],
                        sie[iCand], hoe[iCand], eca[iCand], hca[iCand], eop[iCand],
                        chi[iCand], mih[iCand], des[iCand], dph[iCand], tks[iCand],
                        ps2[iCand])) continue;

         const bool passTight16 = checkCand("Tight16", vNoMask, rho,
                                            e[iCand], et[iCand], eta[iCand], phi[iCand],
                                            sie[iCand], hoe[iCand], eca[iCand], hca[iCand], eop[iCand],
                                            chi[iCand], mih[iCand], des[iCand], dph[iCand], tks[iCand],
                                            ps2[iCand]);

         const bool passEyeBall = checkCand("EyeBall0_etAll", vNoMask, rho,
                                            e[iCand], et[iCand], eta[iCand], phi[iCand],
                                            sie[iCand], hoe[iCand], eca[iCand], hca[iCand], eop[iCand],
                                            chi[iCand], mih[iCand], des[iCand], dph[iCand], tks[iCand],
                                            ps2[iCand]);

         const bool passIterTig = checkCand("IterTig_etAll", vNoMask, rho,
                                            e[iCand], et[iCand], eta[iCand], phi[iCand],
                                            sie[iCand], hoe[iCand], eca[iCand], hca[iCand], eop[iCand],
                                            chi[iCand], mih[iCand], des[iCand], dph[iCand], tks[iCand],
                                            ps2[iCand]);

         const bool passIterLoo = checkCand("IterLoo_etAll", vNoMask, rho,
                                            e[iCand], et[iCand], eta[iCand], phi[iCand],
                                            sie[iCand], hoe[iCand], eca[iCand], hca[iCand], eop[iCand],
                                            chi[iCand], mih[iCand], des[iCand], dph[iCand], tks[iCand],
                                            ps2[iCand]);

         // FILL IN THE FILTER TO BE LOOKED AT HERE
         cndX = et[iCand];

         if (std::abs(eta[iCand]) < etaEB) {
           for (int iH = 0; iH < nH; iH++)
             gra_tb[iH]->Fill(cndX, cndWgt);

           if (passTight16)
             gra_pb[0]->Fill(cndX, cndWgt);
           if (passEyeBall)
             gra_pb[1]->Fill(cndX, cndWgt);
           if (passIterTig)
             gra_pb[2]->Fill(cndX, cndWgt);
           if (passIterLoo)
             gra_pb[3]->Fill(cndX, cndWgt);
         }

         if (std::abs(eta[iCand]) >= etaET) {
           for (int iH = 0; iH < nH; iH++)
             gra_te[iH]->Fill(cndX, cndWgt);

           if (passTight16)
             gra_pe[0]->Fill(cndX, cndWgt);
           if (passEyeBall)
             gra_pe[1]->Fill(cndX, cndWgt);
           if (passIterTig)
             gra_pe[2]->Fill(cndX, cndWgt);
           if (passIterLoo)
             gra_pe[3]->Fill(cndX, cndWgt);
         }
       } // eol cand
     } // eol evt
   } // loop flag

   // -------------------------------------------------- //

   TGraphAsymmErrors *eff_gb[nH], *eff_ge[nH];
   TH1D *eff_hb[nH], *eff_he[nH];
   double xb[nH], yb[nH], yeb[nH];
   double xe[nH], ye[nH], yee[nH];

   int kColor;
   for (int iH = 0; iH < nH; iH++) {
     eff_gb[iH] = new TGraphAsymmErrors(gra_pb[iH], gra_tb[iH], "n");
     eff_ge[iH] = new TGraphAsymmErrors(gra_pe[iH], gra_te[iH], "n");

     eff_hb[iH] = new TH1D(("eff_hb_" + toStr(iH)).c_str(), "", nBin, graBins);
     eff_he[iH] = new TH1D(("eff_he_" + toStr(iH)).c_str(), "", nBin, graBins);

     xb[iH] = 0.; yb[iH] = 0.; yeb[iH] = 0;
     xe[iH] = 0.; ye[iH] = 0.; yee[iH] = 0;
   }

   for (int iBin = 0; iBin < nBin; iBin++) {
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

   // printouts
   for (int iH = 0; iH < nH; iH++) {
     std::cout << std::setprecision(5) << pairFileLeg[iH].second << " Eff [EB, EE]: [ " 
               << eff_hb[iH]->GetBinContent(1) << " $\\pm$ " << eff_hb[iH]->GetBinError(1) << ", " 
               << eff_he[iH]->GetBinContent(1) << " $\\pm$ " << eff_he[iH]->GetBinError(1) << " ]" << std::endl;
   }

   gROOT->ProcessLine(".q");
}

void doStuff() {
  gROOT->Reset();

  gROOT->ProcessLine(".q");
}



