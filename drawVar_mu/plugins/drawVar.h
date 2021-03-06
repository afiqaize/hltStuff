// -*- C++ -*-
// system include files
// Stolen from the drawHist for GenParticle electrons, now using pat::Muon

#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "SimDataFormats/GeneratorProducts/interface/HepMCProduct.h"
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"
#include "DataFormats/HepMCCandidate/interface/GenParticleFwd.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"

#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Muon.h"

#include "DataFormats/PatCandidates/interface/Jet.h"

#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"
#include "DataFormats/Common/interface/TriggerResults.h"

#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "DataFormats/HLTReco/interface/TriggerObject.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "TMath.h"
#include "TH2D.h"
#include "TH1D.h"
//
// class declaration
//

class drawVar : public edm::EDAnalyzer {

  public:
      explicit drawVar(const edm::ParameterSet&);
      ~drawVar();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


  private:
      virtual void beginJob();
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob();
    
      virtual bool hasWasMother(const reco::GenParticle );
      virtual bool isRecoMatchedWithTrigger(const pat::Muon, trigger::TriggerObjectCollection);
      virtual bool isRecoMatchedWithGen(const pat::Muon, edm::Handle<reco::GenParticleCollection>);

      //virtual void beginRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void endRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
      //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;

  // member data
  std::map< std::string, TH2D* > histos2D_;
  std::map< std::string, TH1D* > histos1D_;

  // some parameters
  bool doMatching;
  std::string pathName, filterName, procName;
  double ptCut, etaCut;
  HLTConfigProvider hltConfig;
  int triggerBit;
    
};

