// -*- C++ -*-
//
// Package:    MyCandidates
// Class:      MyCandidates
//
// Original Author:  Matteo Sani,40 3-A02,+41227671577,
//         Created:  Thu Feb 14 14:06:52 CET 2013
// $Id$
//
//


#include <memory>

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "DataFormats/HLTReco/interface/TriggerObject.h"
#include "DataFormats/Common/interface/TriggerResults.h"

#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectronFwd.h"

#include "DataFormats/EgammaCandidates/interface/Photon.h"
#include "DataFormats/EgammaCandidates/interface/PhotonFwd.h"

#include "DataFormats/EgammaCandidates/interface/Electron.h"
#include "DataFormats/EgammaCandidates/interface/ElectronFwd.h"
#include "DataFormats/EgammaCandidates/interface/ElectronIsolationAssociation.h"
#include "RecoEgamma/EgammaIsolationAlgos/interface/EgammaHcalIsolation.h"
#include "RecoEgamma/EgammaHLTAlgos/interface/EgammaHLTHcalIsolation.h"
#include "RecoEgamma/EgammaIsolationAlgos/interface/ElectronTkIsolation.h"
#include "RecoEgamma/EgammaIsolationAlgos/interface/EgammaRecHitIsolation.h"
#include "RecoLocalCalo/EcalRecAlgos/interface/EcalSeverityLevelAlgoRcd.h"

#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"

#include "RecoLocalCalo/HcalRecAlgos/interface/HcalSeverityLevelComputer.h"
#include "RecoLocalCalo/HcalRecAlgos/interface/HcalSeverityLevelComputerRcd.h"
#include "CondFormats/HcalObjects/interface/HcalChannelQuality.h"
#include "CondFormats/DataRecord/interface/HcalChannelQualityRcd.h"

#include "Geometry/Records/interface/CaloGeometryRecord.h"

#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/GsfTrackReco/interface/GsfTrack.h"
#include "DataFormats/TrackReco/interface/HitPattern.h"

#include "DataFormats/HLTReco/interface/TriggerTypeDefs.h"
#include "DataFormats/HLTReco/interface/TriggerEventWithRefs.h"
#include "DataFormats/RecoCandidate/interface/RecoEcalCandidate.h"
#include "DataFormats/RecoCandidate/interface/RecoEcalCandidateFwd.h"
#include "DataFormats/RecoCandidate/interface/RecoEcalCandidateIsolation.h"

#include "DataFormats/HepMCCandidate/interface/GenParticle.h"

#include "DataFormats/CaloRecHit/interface/CaloCluster.h"
#include "DataFormats/CaloRecHit/interface/CaloClusterFwd.h"
#include "DataFormats/ParticleFlowReco/interface/PFCluster.h"
#include "DataFormats/ParticleFlowReco/interface/PFClusterFwd.h"

#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/Common/interface/ValueMap.h"

#include "TLorentzVector.h"
#include "TFile.h"
#include "TTree.h"

#include <string>
#include <iostream>

class checkClustering : public edm::EDAnalyzer {
public:
  explicit checkClustering(const edm::ParameterSet&);
  ~checkClustering();
  
  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
  int findEleRef(reco::RecoEcalCandidateRef ref, edm::Handle<reco::ElectronCollection> hltEleH);
  void mcTruth(edm::Handle<reco::GenParticleCollection> genParticleH);

private:
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;
};

checkClustering::checkClustering(const edm::ParameterSet& iConfig) 
{}

checkClustering::~checkClustering() 
{}

int checkClustering::findEleRef(reco::RecoEcalCandidateRef ref, edm::Handle<reco::ElectronCollection> hltEleH) {

  int index = -1;
  for (unsigned int i=0; i<hltEleH->size(); i++) {
    reco::ElectronRef cand(hltEleH, i);
    if (cand->superCluster() == ref->superCluster()) 
      return i;
  }

  return index;
}

void checkClustering::mcTruth(edm::Handle<reco::GenParticleCollection> gpH) {
    
  for(size_t i = 0; i < gpH->size(); ++i) {
    
    const reco::GenParticleRef gp(gpH, i);
    if (gp->status() == 3 and abs(gp->pdgId()) == 11)
      std::cout << "GP: " << gp->eta() << " " << gp->phi() << " " << gp->pt() << std::endl;
  }
}

void checkClustering::analyze(const edm::Event& event, const edm::EventSetup& iSetup) {

  edm::Handle<reco::GenParticleCollection> gpH;
  event.getByLabel("genParticles", gpH);
  mcTruth(gpH);
  
  edm::Handle<std::vector<reco::RecoEcalCandidate> > cH;
  event.getByLabel( edm::InputTag("hltL1SeededRecoEcalCandidate"), cH);

  std::cout << "______________" << std::endl;
  for (unsigned int i=0; i<cH->size(); i++) {
    reco::RecoEcalCandidateRef c(cH, i);
    std::cout << "SC: "<< c->eta() << " " <<  c->phi() << " " << c->superCluster()->rawEnergy() << std::endl;
  }
  
  std::cout << "______________" << std::endl;
  event.getByLabel( edm::InputTag("hltL1SeededRecoEcalCandidatePF"), cH);
  
  for (unsigned int i=0; i<cH->size(); i++) {
    
    reco::RecoEcalCandidateRef c(cH, i);
    std::cout << "PF: " << c->eta() << " " <<  c->phi() << " " << c->superCluster()->rawEnergy() << std::endl;
  } 

  std::cout << "************" << std::endl;
  edm::Handle<reco::PFClusterCollection> ccH;
  event.getByLabel("hltParticleFlowClusterECAL", ccH);
  for (unsigned int i=0; i<ccH->size(); i++) {
    reco::PFClusterRef c(ccH, i);
    std::cout << "CCPF: " << c->eta() << " " <<  c->phi() << " " << c->energy() << std::endl;
  }
}
 
void checkClustering::beginJob() {}

void checkClustering::endJob() {}

void checkClustering::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

DEFINE_FWK_MODULE(checkClustering);
