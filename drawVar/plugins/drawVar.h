// -*- C++ -*-
// system include files
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
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;
    
      virtual bool hasWasMother(const reco::GenParticle );
      virtual bool isMatchedWithTrigger(const reco::GenParticle, trigger::TriggerObjectCollection);

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
  double ptCutGen, etaCutGen;
  HLTConfigProvider hltConfig;
  int triggerBit;
    
};

