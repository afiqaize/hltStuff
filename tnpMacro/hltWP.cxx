// A single file where WP-related stuff are defined
// Not sure if this is the best way about this, but it'll do

#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <utility>
#include <map>

#include "TFile.h"
#include "TChain.h"
#include "TTree.h"
#include "TROOT.h"
#include "TBufferFile.h"

// ------- HLT WP related methods ------- //

const double etaEBr = 1., etaEB = 1.4442, etaET = 1.566, etaEEr = 2.1, etaEE = 2.5;
const std::vector<std::string> vNoMask; // default empty vec for checkCand i.e. no cut masking


// The cut values for each WP is stored here
// The form is always varVal[i] < varThr[i]
// ID vars that is cut on is specified as 3-char string e.g. sie
// Correction terms on an ID is specified as zz_var e.g. ea_eca for EcalIso EA
// Do not specify a WP without the correction terms - it'll go wonky
double getThr(const std::string& setWP, const double& et, const double& eta, const std::string& sThr) {

  std::map<std::string, double> vThr;

  if (setWP == "Loose16") {
    if (std::abs(eta) < 1.4791) {
      vThr["sie"] = 0.011; vThr["hor"] = 0.08;
      vThr["ecr"] = 0.04 ; vThr["hcr"] = 0.06;
      vThr["eop"] = 0.012; vThr["chi"] = 999.;
      vThr["mih"] = 999. ; vThr["des"] = 0.0044;
      vThr["dph"] = 0.025; vThr["tkr"] = 0.085;

      vThr["ea_hoe"] = 0.079; vThr["ea_eca"] = 0.29; vThr["ea_hca"] = 0.2;
    }
    if (std::abs(eta) >= 1.4791) {
      vThr["sie"] = 0.031; vThr["hor"] = 0.04;
      vThr["ecr"] = 0.045; vThr["hcr"] = 0.08;
      vThr["eop"] = 0.01 ; vThr["chi"] = 4.0;
      vThr["mih"] = 2.5  ; vThr["des"] = 0.006;
      vThr["dph"] = 0.025; vThr["tkr"] = 0.07;

      vThr["ea_hoe"] = 0.25; vThr["ea_eca"] = 0.21; vThr["ea_hca"] = 0.25;
    }
  }

  else if (setWP == "Tight16") {
    if (std::abs(eta) < 1.4791) {
      vThr["sie"] = 0.0105; vThr["hor"] = 0.07;
      vThr["ecr"] = 0.032 ; vThr["hcr"] = 0.055;
      vThr["eop"] = 0.01  ; vThr["chi"] = 999.;
      vThr["mih"] = 999.  ; vThr["des"] = 0.004;
      vThr["dph"] = 0.02  ; vThr["tkr"] = 0.07;

      vThr["ea_hoe"] = 0.079; vThr["ea_eca"] = 0.29; vThr["ea_hca"] = 0.2;
    }
    if (std::abs(eta) >= 1.4791) {
      vThr["sie"] = 0.0285; vThr["hor"] = 0.035;
      vThr["ecr"] = 0.04  ; vThr["hcr"] = 0.05;
      vThr["eop"] = 0.008 ; vThr["chi"] = 3.5;
      vThr["mih"] = 1.5   ; vThr["des"] = 0.0045;
      vThr["dph"] = 0.022 ; vThr["tkr"] = 0.05;

      vThr["ea_hoe"] = 0.25; vThr["ea_eca"] = 0.21; vThr["ea_hca"] = 0.25;
    }
  }

  // true to name - look at dist, eyeball eff...
  else if (setWP == "EyeBall0_etAll") {
    if (std::abs(eta) < 1.4791) {
      vThr["sie"] = 0.011 ; vThr["hor"] = 0.025;
      vThr["ecr"] = 0.02  ; vThr["hcr"] = 0.03;
      vThr["eop"] = 0.01  ; vThr["chi"] = 999.;
      vThr["mih"] = 999.  ; vThr["des"] = 0.004;
      vThr["dph"] = 0.02  ; vThr["tkr"] = 0.045;

      if (std::abs(eta) < 1.) {
        vThr["ea_hoe"] = 0.082; vThr["ea_eca"] = 0.302; vThr["ea_hca"] = 0.213;
      }
      else {
        vThr["ea_hoe"] = 0.132; vThr["ea_eca"] = 0.250; vThr["ea_hca"] = 0.273;
      }
    }
    if (std::abs(eta) >= 1.4791) {
      vThr["sie"] = 0.029 ; vThr["hor"] = 0.02;
      vThr["ecr"] = 0.02  ; vThr["hcr"] = 0.03;
      vThr["eop"] = 0.009 ; vThr["chi"] = 6.;
      vThr["mih"] = 1.5   ; vThr["des"] = 0.005;
      vThr["dph"] = 0.02  ; vThr["tkr"] = 0.045;

      if (std::abs(eta) < 2.1) {
        vThr["ea_hoe"] = 0.306; vThr["ea_eca"] = 0.252; vThr["ea_hca"] = 0.361;
      }
      else {
        vThr["ea_hoe"] = 0.383; vThr["ea_eca"] = 0.402; vThr["ea_hca"] = 0.426;
      }
    }
  }

  // the cuts are roughly 97.5% efficient
  else if (setWP == "EA17_0_q0p95") {
    if (std::abs(eta) < 1.4791) {
      if (std::abs(eta) < 1.) {
        vThr["ea_hoe"] = 0.082; vThr["ea_eca"] = 0.302;
        vThr["ea_hca"] = 0.213; vThr["ea_tks"] = 0.075;
      }
      else {
        vThr["ea_hoe"] = 0.132; vThr["ea_eca"] = 0.250;
        vThr["ea_hca"] = 0.273; vThr["ea_tks"] = 0.128;
      }

      vThr["hor"] = 0.026; vThr["ecr"] = 0.007;
      vThr["hcr"] = 0.043; vThr["tkr"] = 0.001;
    }
    if (std::abs(eta) >= 1.4791) {
      if (std::abs(eta) < 2.1) {
        vThr["ea_hoe"] = 0.306; vThr["ea_eca"] = 0.252;
        vThr["ea_hca"] = 0.361; vThr["ea_tks"] = 0.115;
      }
      else {
        vThr["ea_hoe"] = 0.383; vThr["ea_eca"] = 0.401;
        vThr["ea_hca"] = 0.427; vThr["ea_tks"] = 0.081;
      }

      vThr["hor"] = 0.03; vThr["ecr"] = 0.002;
      vThr["hcr"] = 0.034; vThr["tkr"] = 0.001;
    }
  }

  else if (setWP == "EANT17_0_q0p95") {
    if (std::abs(eta) < 1.4791) {
      if (std::abs(eta) < 1.) {
        vThr["ea_hoe"] = 0.082; vThr["ea_eca"] = 0.302;
        vThr["ea_hca"] = 0.213; vThr["ea_tks"] = 0.075;

        vThr["nt_hoe"] = 0.651; vThr["nt_eca"] = -1.007;
        vThr["nt_hca"] = 0.771; vThr["nt_tks"] = -0.787;
      }
      else {
        vThr["ea_hoe"] = 0.132; vThr["ea_eca"] = 0.250;
        vThr["ea_hca"] = 0.273; vThr["ea_tks"] = 0.128;

        vThr["nt_hoe"] = 1.211; vThr["nt_eca"] = -0.585;
        vThr["nt_hca"] = 0.508; vThr["nt_tks"] = -1.414;
      }

      vThr["hor"] = 0.013; vThr["ecr"] = 0.027;
      vThr["hcr"] = 0.027; vThr["tkr"] = 0.022;
    }
    if (std::abs(eta) >= 1.4791) {
      if (std::abs(eta) < 2.1) {
        vThr["ea_hoe"] = 0.306; vThr["ea_eca"] = 0.252;
        vThr["ea_hca"] = 0.361; vThr["ea_tks"] = 0.115;

        vThr["nt_hoe"] = 2.092; vThr["nt_eca"] = -1.015;
        vThr["nt_hca"] = 0.471; vThr["nt_tks"] = -1.026;
      }
      else {
        vThr["ea_hoe"] = 0.383; vThr["ea_eca"] = 0.401;
        vThr["ea_hca"] = 0.427; vThr["ea_tks"] = 0.081;

        vThr["nt_hoe"] = 4.24 ; vThr["nt_eca"] = -0.997;
        vThr["nt_hca"] = -0.41; vThr["nt_tks"] = -1.226;
      }

      vThr["hor"] = 0.0135; vThr["ecr"] = 0.022;
      vThr["hcr"] = 0.029; vThr["tkr"] = 0.023;
    }
  }

  else if (setWP == "EA17_0_q0p97") {
    if (std::abs(eta) < 1.4791) {
      if (std::abs(eta) < 1.) {
        vThr["ea_hoe"] = 0.09 ; vThr["ea_eca"] = 0.323;
        vThr["ea_hca"] = 0.246; vThr["ea_tks"] = 0.032;
      }
      else {
        vThr["ea_hoe"] = 0.154; vThr["ea_eca"] = 0.288;
        vThr["ea_hca"] = 0.298; vThr["ea_tks"] = 0.13;
      }

      vThr["hor"] = 0.0225; vThr["ecr"] = 0.001;
      vThr["hcr"] = 0.03; vThr["tkr"] = 0.0175;
    }
    if (std::abs(eta) >= 1.4791) {
      if (std::abs(eta) < 2.1) {
        vThr["ea_hoe"] = 0.362; vThr["ea_eca"] = 0.269;
        vThr["ea_hca"] = 0.391; vThr["ea_tks"] = 0.13;
      }
      else {
        vThr["ea_hoe"] = 0.372; vThr["ea_eca"] = 0.424;
        vThr["ea_hca"] = 0.455; vThr["ea_tks"] = 0.039;
      }

      vThr["hor"] = 0.0265; vThr["ecr"] = 0.001;
      vThr["hcr"] = 0.021; vThr["tkr"] = 0.005;
    }
  }

  else if (setWP == "EANT17_0_q0p97") {
    if (std::abs(eta) < 1.4791) {
      if (std::abs(eta) < 1.) {
        vThr["ea_hoe"] = 0.09 ; vThr["ea_eca"] = 0.323;
        vThr["ea_hca"] = 0.246; vThr["ea_tks"] = 0.032;

        vThr["nt_hoe"] = 1.038; vThr["nt_eca"] = -0.548;
        vThr["nt_hca"] = 1.018; vThr["nt_tks"] = 0.779;
      }
      else {
        vThr["ea_hoe"] = 0.154; vThr["ea_eca"] = 0.288;
        vThr["ea_hca"] = 0.298; vThr["ea_tks"] = 0.13;

        vThr["nt_hoe"] = 1.567; vThr["nt_eca"] = -0.543;
        vThr["nt_hca"] = 0.858; vThr["nt_tks"] = -0.73;
      }

      vThr["hor"] = 0.003; vThr["ecr"] = 0.008;
      vThr["hcr"] = 0.008; vThr["tkr"] = 0.0035;
    }
    if (std::abs(eta) >= 1.4791) {
      if (std::abs(eta) < 2.1) {
        vThr["ea_hoe"] = 0.362; vThr["ea_eca"] = 0.269;
        vThr["ea_hca"] = 0.391; vThr["ea_tks"] = 0.13;

        vThr["nt_hoe"] = 2.5  ; vThr["nt_eca"] = -0.621;
        vThr["nt_hca"] = 0.831; vThr["nt_tks"] = -0.651;
      }
      else {
        vThr["ea_hoe"] = 0.372; vThr["ea_eca"] = 0.424;
        vThr["ea_hca"] = 0.455; vThr["ea_tks"] = 0.039;

        vThr["nt_hoe"] = 6.013; vThr["nt_eca"] = -0.642;
        vThr["nt_hca"] = -0.047; vThr["nt_tks"] = 0.569;
      }

      vThr["hor"] = 0.005; vThr["ecr"] = 0.006;
      vThr["hcr"] = 0.009; vThr["tkr"] = 0.0045;
    }
  }

  // cuts roughly 97.5% efficient (of _0_ EAs with wider fit range)
  else if (setWP == "EA17_1_q0p95") {
    if (std::abs(eta) < 1.4791) {
      if (std::abs(eta) < 1.) {
        vThr["ea_hoe"] = 0.089; vThr["ea_eca"] = 0.301;
        vThr["ea_hca"] = 0.237; vThr["ea_tks"] = 0.099;
      }
      else {
        vThr["ea_hoe"] = 0.146; vThr["ea_eca"] = 0.267;
        vThr["ea_hca"] = 0.299; vThr["ea_tks"] = 0.132;
      }

      vThr["hor"] = 0.026; vThr["ecr"] = 0.007;
      vThr["hcr"] = 0.043; vThr["tkr"] = 0.001;
    }
    if (std::abs(eta) >= 1.4791) {
      if (std::abs(eta) < 2.1) {
        vThr["ea_hoe"] = 0.329; vThr["ea_eca"] = 0.257;
        vThr["ea_hca"] = 0.389; vThr["ea_tks"] = 0.122;
      }
      else {
        vThr["ea_hoe"] = 0.421; vThr["ea_eca"] = 0.412;
        vThr["ea_hca"] = 0.433; vThr["ea_tks"] = 0.095;
      }

      vThr["hor"] = 0.03; vThr["ecr"] = 0.002;
      vThr["hcr"] = 0.034; vThr["tkr"] = 0.001;
    }
  }

  else if (setWP == "EANT17_1_q0p95") {
    if (std::abs(eta) < 1.4791) {
      if (std::abs(eta) < 1.) {
        vThr["ea_hoe"] = 0.089; vThr["ea_eca"] = 0.301;
        vThr["ea_hca"] = 0.237; vThr["ea_tks"] = 0.099;

        vThr["nt_hoe"] = 0.525; vThr["nt_eca"] = -0.991;
        vThr["nt_hca"] = 0.332; vThr["nt_tks"] = -1.23;
      }
      else {
        vThr["ea_hoe"] = 0.146; vThr["ea_eca"] = 0.267;
        vThr["ea_hca"] = 0.299; vThr["ea_tks"] = 0.132;

        vThr["nt_hoe"] = 0.962; vThr["nt_eca"] = -0.904;
        vThr["nt_hca"] = 0.019; vThr["nt_tks"] = -1.477;
      }

      vThr["hor"] = 0.013; vThr["ecr"] = 0.027;
      vThr["hcr"] = 0.027; vThr["tkr"] = 0.022;
    }
    if (std::abs(eta) >= 1.4791) {
      if (std::abs(eta) < 2.1) {
        vThr["ea_hoe"] = 0.329; vThr["ea_eca"] = 0.257;
        vThr["ea_hca"] = 0.389; vThr["ea_tks"] = 0.122;

        vThr["nt_hoe"] = 1.664; vThr["nt_eca"] = -1.1;
        vThr["nt_hca"] = -0.043; vThr["nt_tks"] = -1.16;
      }
      else {
        vThr["ea_hoe"] = 0.421; vThr["ea_eca"] = 0.412;
        vThr["ea_hca"] = 0.433; vThr["ea_tks"] = 0.095;

        vThr["nt_hoe"] = 3.553; vThr["nt_eca"] = -1.18;
        vThr["nt_hca"] = -0.526; vThr["nt_tks"] = -1.47;
      }

      vThr["hor"] = 0.0135; vThr["ecr"] = 0.022;
      vThr["hcr"] = 0.029; vThr["tkr"] = 0.023;
    }
  }

  else if (setWP == "EA17_1_q0p97") {
    if (std::abs(eta) < 1.4791) {
      if (std::abs(eta) < 1.) {
        vThr["ea_hoe"] = 0.098; vThr["ea_eca"] = 0.325;
        vThr["ea_hca"] = 0.259; vThr["ea_tks"] = 0.029;
      }
      else {
        vThr["ea_hoe"] = 0.159; vThr["ea_eca"] = 0.296;
        vThr["ea_hca"] = 0.328; vThr["ea_tks"] = 0.111;
      }

      vThr["hor"] = 0.0225; vThr["ecr"] = 0.001;
      vThr["hcr"] = 0.03; vThr["tkr"] = 0.0175;
    }
    if (std::abs(eta) >= 1.4791) {
      if (std::abs(eta) < 2.1) {
        vThr["ea_hoe"] = 0.353; vThr["ea_eca"] = 0.283;
        vThr["ea_hca"] = 0.414; vThr["ea_tks"] = 0.114;
      }
      else {
        vThr["ea_hoe"] = 0.423; vThr["ea_eca"] = 0.438;
        vThr["ea_hca"] = 0.456; vThr["ea_tks"] = 0.032;
      }

      vThr["hor"] = 0.0265; vThr["ecr"] = 0.001;
      vThr["hcr"] = 0.021; vThr["tkr"] = 0.005;
    }
  }

  else if (setWP == "EANT17_1_q0p97") {
    if (std::abs(eta) < 1.4791) {
      if (std::abs(eta) < 1.) {
        vThr["ea_hoe"] = 0.098; vThr["ea_eca"] = 0.325;
        vThr["ea_hca"] = 0.259; vThr["ea_tks"] = 0.029;

        vThr["nt_hoe"] = 0.887; vThr["nt_eca"] = -0.581;
        vThr["nt_hca"] = 0.786; vThr["nt_tks"] = 0.838;
      }
      else {
        vThr["ea_hoe"] = 0.159; vThr["ea_eca"] = 0.296;
        vThr["ea_hca"] = 0.328; vThr["ea_tks"] = 0.111;

        vThr["nt_hoe"] = 1.476; vThr["nt_eca"] = -0.698;
        vThr["nt_hca"] = 0.298; vThr["nt_tks"] = -0.385;
      }

      vThr["hor"] = 0.003; vThr["ecr"] = 0.008;
      vThr["hcr"] = 0.008; vThr["tkr"] = 0.0035;
    }
    if (std::abs(eta) >= 1.4791) {
      if (std::abs(eta) < 2.1) {
        vThr["ea_hoe"] = 0.353; vThr["ea_eca"] = 0.283;
        vThr["ea_hca"] = 0.414; vThr["ea_tks"] = 0.114;

        vThr["nt_hoe"] = 2.672; vThr["nt_eca"] = -0.892;
        vThr["nt_hca"] = 0.402; vThr["nt_tks"] = -0.363;
      }
      else {
        vThr["ea_hoe"] = 0.423; vThr["ea_eca"] = 0.438;
        vThr["ea_hca"] = 0.456; vThr["ea_tks"] = 0.032;

        vThr["nt_hoe"] = 5.095; vThr["nt_eca"] = -0.885;
        vThr["nt_hca"] = -0.061; vThr["nt_tks"] = 0.702;
      }

      vThr["hor"] = 0.005; vThr["ecr"] = 0.006;
      vThr["hcr"] = 0.009; vThr["tkr"] = 0.0045;
    }
  }

  // iterative optimization based on ROC area - order is best -> worst
  else if (setWP == "IterTig_etAll") {
    if (std::abs(eta) < 1.4791) {
      if (std::abs(eta) < 1.) {
        vThr["ea_hoe"] = 0.098; vThr["ea_eca"] = 0.325;
        vThr["ea_hca"] = 0.259; vThr["ea_tks"] = 0.029;

        vThr["nt_hoe"] = 0.887; vThr["nt_eca"] = -0.581;
        vThr["nt_hca"] = 0.786; vThr["nt_tks"] = 0.838;
      }
      else {
        vThr["ea_hoe"] = 0.159; vThr["ea_eca"] = 0.296;
        vThr["ea_hca"] = 0.328; vThr["ea_tks"] = 0.111;

        vThr["nt_hoe"] = 1.476; vThr["nt_eca"] = -0.698;
        vThr["nt_hca"] = 0.298; vThr["nt_tks"] = -0.385;
      }

      vThr["ps2"] = 70.; vThr["tkr"] = 0.03;
      vThr["eop"] = 0.012; vThr["sie"] = 0.011;
      vThr["dph"] = 0.02; vThr["ecr"] = 0.03;
      vThr["hor"] = 0.02; vThr["des"] = 0.004;
      vThr["hcr"] = 0.03;

      /*
      if (et < 60.) {
        vThr["dph"] = 0.021; vThr["hor"] = 0.025;
        vThr["tkr"] = 0.035; vThr["ecr"] = 0.035;
        vThr["hcr"] = 0.035;
      }
      if (et < 50.)
        vThr["dph"] = 0.025;
      if (et < 45.)
        vThr["dph"] = 0.027;
      */
    }
    if (std::abs(eta) >= 1.4791) {
      if (std::abs(eta) < 2.1) {
        vThr["ea_hoe"] = 0.353; vThr["ea_eca"] = 0.283;
        vThr["ea_hca"] = 0.414; vThr["ea_tks"] = 0.114;

        vThr["nt_hoe"] = 2.672; vThr["nt_eca"] = -0.892;
        vThr["nt_hca"] = 0.402; vThr["nt_tks"] = -0.363;
      }
      else {
        vThr["ea_hoe"] = 0.423; vThr["ea_eca"] = 0.438;
        vThr["ea_hca"] = 0.456; vThr["ea_tks"] = 0.032;

        vThr["nt_hoe"] = 5.095; vThr["nt_eca"] = -0.885;
        vThr["nt_hca"] = -0.061; vThr["nt_tks"] = 0.702;
      }

      vThr["ps2"] = 45.; vThr["sie"] = 0.0305;
      vThr["tkr"] = 0.025; vThr["eop"] = 0.011;
      vThr["dph"] = 0.023; vThr["des"] = 0.005;
      vThr["hor"] = 0.015; vThr["ecr"] = 0.025;
      vThr["hcr"] = 0.025; vThr["mih"] = 1.5;

      /*
      if (et < 60.) {
        vThr["dph"] = 0.025; vThr["hor"] = 0.02;
        vThr["tkr"] = 0.03; vThr["ecr"] = 0.03;
        vThr["hcr"] = 0.03;
      }
      if (et < 50.)
        vThr["dph"] = 0.027;
      if (et < 45.)
        vThr["dph"] = 0.029;
      */
    }
  }

  // literally nothing more than a bit of back-off a bit from IterTig
  else if (setWP == "IterLoo_etAll") {
    if (std::abs(eta) < 1.4791) {
      if (std::abs(eta) < 1.) {
        vThr["ea_hoe"] = 0.098; vThr["ea_eca"] = 0.325;
        vThr["ea_hca"] = 0.259; vThr["ea_tks"] = 0.029;

        vThr["nt_hoe"] = 0.887; vThr["nt_eca"] = -0.581;
        vThr["nt_hca"] = 0.786; vThr["nt_tks"] = 0.838;
      }
      else {
        vThr["ea_hoe"] = 0.159; vThr["ea_eca"] = 0.296;
        vThr["ea_hca"] = 0.328; vThr["ea_tks"] = 0.111;

        vThr["nt_hoe"] = 1.476; vThr["nt_eca"] = -0.698;
        vThr["nt_hca"] = 0.298; vThr["nt_tks"] = -0.385;
      }

      vThr["ps2"] = 70.; vThr["tkr"] = 0.035;
      vThr["eop"] = 0.016; vThr["sie"] = 0.011;
      vThr["dph"] = 0.025; vThr["ecr"] = 0.035;
      vThr["hor"] = 0.025; vThr["des"] = 0.004;
      vThr["hcr"] = 0.035;
    }
    if (std::abs(eta) >= 1.4791) {
      if (std::abs(eta) < 2.1) {
        vThr["ea_hoe"] = 0.353; vThr["ea_eca"] = 0.283;
        vThr["ea_hca"] = 0.414; vThr["ea_tks"] = 0.114;

        vThr["nt_hoe"] = 2.672; vThr["nt_eca"] = -0.892;
        vThr["nt_hca"] = 0.402; vThr["nt_tks"] = -0.363;
      }
      else {
        vThr["ea_hoe"] = 0.423; vThr["ea_eca"] = 0.438;
        vThr["ea_hca"] = 0.456; vThr["ea_tks"] = 0.032;

        vThr["nt_hoe"] = 5.095; vThr["nt_eca"] = -0.885;
        vThr["nt_hca"] = -0.061; vThr["nt_tks"] = 0.702;
      }

      vThr["ps2"] = 45.; vThr["sie"] = 0.031;
      vThr["tkr"] = 0.03; vThr["eop"] = 0.013;
      vThr["dph"] = 0.025; vThr["des"] = 0.0055;
      vThr["hor"] = 0.02; vThr["ecr"] = 0.03;
      vThr["hcr"] = 0.03;
    }
  }

  // WPNone with H/E cut in pixmatch
  else if (setWP == "WPNone")
    vThr["hor"] = 0.2;

  if ( vThr.count(sThr) == 1 )
    return vThr.at(sThr); // key exists; return as is
  else if (vThr.count(sThr) == 0 and sThr.compare(2, 1, "_") == 0)
    return 0.; // correction term nonexising; return 0.
  else
    return 9999.;
}



double doRhoCorrection(const double& iso, const double& et, const double& eta, const double& rho,
                       const std::string &setWP, const std::string &var) {
  const double ea_var = getThr(setWP, et, eta, "ea_" + var);
  const double nt_var = getThr(setWP, et, eta, "nt_" + var);

  return std::max( 0., iso - ((ea_var * rho) + nt_var) );
}



// Check if a candidate passes a given WP
// Ensure the actual, uncorrected quantities are sent i.e. H, not H/E, EcalIso, not the relative one...
bool checkCand(const std::string& setWP, const std::vector<std::string>& vMask, const double& rho,
               const double& ene, const double& et, const double& eta, const double& phi,
               const double& sie, const double& hoe, const double& eca, const double& hca,
               const double& eop, const double& chi, const double& mih,
               const double& des, const double& dph, const double& tks,
               const double& ps2) {
  bool candOk = true;
  std::map<std::string, double> vVal;

  // Order as HLT filtering but technically doesn't matter
  vVal["sie"] = sie;
  vVal["hor"] = doRhoCorrection(hoe, et, eta, rho, setWP, "hoe") / ene;
  vVal["ecr"] = doRhoCorrection(eca, et, eta, rho, setWP, "eca") / et;
  vVal["hcr"] = doRhoCorrection(hca, et, eta, rho, setWP, "hca") / et;
  vVal["ps2"] = ps2;
  vVal["eop"] = eop;
  vVal["chi"] = chi;
  vVal["mih"] = mih;
  vVal["des"] = des;
  vVal["dph"] = dph;
  vVal["tkr"] = doRhoCorrection(tks, et, eta, rho, setWP, "tks") / et;

  for (std::map<std::string, double>::iterator val = vVal.begin(); val != vVal.end(); val++) {
    //if (val->first == sMask) continue; // N - 1 cut masking
    if (std::find(vMask.begin(), vMask.end(), val->first) != vMask.end()) continue; // multi-cut masking
    candOk = candOk and (val->second <= getThr(setWP, et, eta, val->first));
  }

  return candOk;
}



void fillWPCutVector(const std::string &idVar, const double& et,
                     std::vector< std::pair<double, int> > &cutVC_b, std::vector< std::pair<double, int> > &cutVC_e,
                     const std::vector< std::pair<std::string, int> > &pairWPCol) {
  for (unsigned iWP = 0; iWP < pairWPCol.size(); iWP++) {
    cutVC_b.push_back(std::make_pair( getThr(pairWPCol.at(iWP).first, et, etaEB - 0.1, idVar), pairWPCol.at(iWP).second ));
    cutVC_e.push_back(std::make_pair( getThr(pairWPCol.at(iWP).first, et, etaEE - 0.1, idVar), pairWPCol.at(iWP).second ));
  }
}



// ------- hltTree related methods ------- //
/***
 * Attempt to centralize the trees
 * Working in ROOT5, but segfaults in ROOT6 (only for tnpIso?)
 * Not really sure why, to be worked on
 ***/
/*
int nRun, nLumi, nEvt, nBX, nOrb, nSto;

int type, nVtx;
double weight, puWgt, rho;

int pass[10], genMatch[10], n;

double et[10], etr[10], e[10], er[10], eta[10], phi[10];
double sie[10], ps2[10];
double hoe[10], eca[10], hca[10];
double eop[10], esp[10], chi[10], mih[10], det[10], des[10], dph[10], tks[10];

double hoc[10], ecc[10], hcc[10];

int mc_nPUtrue, gp_n, mc_nPUobs;
double genWgt, gp_pt[10], gp_eta[10], gp_phi[10];

void hltTreeBranchAddresses(const bool& isMC, TChain* t1) {

   t1->SetBranchAddress("nRun", &nRun);
   t1->SetBranchAddress("nLumi", &nLumi);
   t1->SetBranchAddress("nEvt", &nEvt);
   t1->SetBranchAddress("nBX", &nBX);
   t1->SetBranchAddress("nOrb", &nOrb);
   t1->SetBranchAddress("nSto", &nSto);

   t1->SetBranchAddress("itype", &type);
   t1->SetBranchAddress("weight", &weight);
   t1->SetBranchAddress("puWgt", &puWgt);
   t1->SetBranchAddress("nVtx", &nVtx);
   t1->SetBranchAddress("rho", &rho);

   t1->SetBranchAddress("passHLT", pass);
   t1->SetBranchAddress("genMatch", genMatch);
   t1->SetBranchAddress("hlt_n", &n);
   t1->SetBranchAddress("hlt_et", et);
   t1->SetBranchAddress("hlt_etr", etr);
   t1->SetBranchAddress("hlt_e", e);
   t1->SetBranchAddress("hlt_er", er);
   t1->SetBranchAddress("hlt_eta", eta);
   t1->SetBranchAddress("hlt_phi", phi);

   t1->SetBranchAddress("hlt_sie", sie);
   t1->SetBranchAddress("hlt_hoe", hoe);
   t1->SetBranchAddress("hlt_eca", eca);
   t1->SetBranchAddress("hlt_hca", hca);
   t1->SetBranchAddress("hlt_ps2", ps2);
   t1->SetBranchAddress("hlt_eop", eop);
   t1->SetBranchAddress("hlt_esp", esp);
   t1->SetBranchAddress("hlt_chi", chi);
   t1->SetBranchAddress("hlt_mih", mih);
   t1->SetBranchAddress("hlt_det", det);
   t1->SetBranchAddress("hlt_des", des);
   t1->SetBranchAddress("hlt_dph", dph);
   t1->SetBranchAddress("hlt_tks", tks);

   t1->SetBranchAddress("hlt_hoc", hoc);
   t1->SetBranchAddress("hlt_ecc", ecc);
   t1->SetBranchAddress("hlt_hcc", hcc);

   if (isMC) {
     t1->SetBranchAddress("genWgt", &genWgt);
     t1->SetBranchAddress("gp_n", &gp_n);
     t1->SetBranchAddress("gp_pt", gp_pt);
     t1->SetBranchAddress("gp_eta", gp_eta);
     t1->SetBranchAddress("gp_phi", gp_phi);
     t1->SetBranchAddress("mc_nPUtrue", &mc_nPUtrue);
     t1->SetBranchAddress("mc_nPUobs", &mc_nPUobs);
   }
}
*/
