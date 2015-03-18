// -*- C++ -*-
// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/Common/interface/ValueMap.h"
#include "DataFormats/Common/interface/View.h"

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

#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectronFwd.h"
#include "DataFormats/PatCandidates/interface/Electron.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "TMath.h"
#include "TFile.h"
#include "TTree.h"
#include "Math/VectorUtil.h"

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
    
      virtual bool hasWYZasMother(const reco::GenParticle );
      virtual bool isRecoMatchedWithTrigger(const edm::Ptr<reco::GsfElectron>, trigger::TriggerObjectCollection);
      virtual bool isRecoMatchedWithGen(const edm::Ptr<reco::GsfElectron>, edm::Handle<reco::GenParticleCollection>);

      //virtual void beginRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void endRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
      //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;

  // member data
  edm::EDGetTokenT<edm::View<reco::GsfElectron> > electronCollectionToken;
  TTree *tree;
  TFile *file;

  // some parameters
  bool doMatching;
  std::string outFile, pathName, filterName, procName;
  double ptCut, etaCut;
  HLTConfigProvider hltConfig;
  int triggerBit;
  Int_t nGsf, nPass, nMatch;
  std::vector<Double_t> ptGsf, ptPass, ptMatch;
  std::vector<Double_t> etaGsf, etaPass, etaMatch;
    
};

