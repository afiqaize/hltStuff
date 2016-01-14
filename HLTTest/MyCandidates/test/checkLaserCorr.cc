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

#include "RecoLocalCalo/HcalRecAlgos/interface/HcalSeverityLevelComputer.h"
#include "RecoLocalCalo/HcalRecAlgos/interface/HcalSeverityLevelComputerRcd.h"
#include "CondFormats/HcalObjects/interface/HcalChannelQuality.h"
#include "CondFormats/DataRecord/interface/HcalChannelQualityRcd.h"

#include "DataFormats/EcalDetId/interface/EcalSubdetector.h"
#include "RecoEcal/EgammaCoreTools/interface/ClusterShapeAlgo.h"
#include "RecoCaloTools/Navigation/interface/CaloNavigator.h"
#include "Geometry/EcalAlgo/interface/EcalBarrelGeometry.h"
#include "Geometry/CaloTopology/interface/EcalBarrelTopology.h"
#include "Geometry/CaloTopology/interface/EcalEndcapTopology.h"
#include "Geometry/CaloTopology/interface/EcalPreshowerTopology.h"

#include "Geometry/Records/interface/CaloGeometryRecord.h"
#include "CalibCalorimetry/EcalLaserCorrection/interface/EcalLaserDbService.h"
#include "CalibCalorimetry/EcalLaserCorrection/interface/EcalLaserDbRecord.h"

#include "DataFormats/EcalDetId/interface/EBDetId.h"
#include "DataFormats/EcalDetId/interface/EEDetId.h"
 
#include "Geometry/CaloGeometry/interface/CaloCellGeometry.h"
#include "DataFormats/Math/interface/Point3D.h"
#include "DataFormats/Math/interface/Vector3D.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/Common/interface/ValueMap.h"

#include "TLorentzVector.h"
#include "TFile.h"
#include "TTree.h"

#include <string>
#include <iostream>

class checkLaserCorr : public edm::EDAnalyzer {
public:
  explicit checkLaserCorr(const edm::ParameterSet&);
  ~checkLaserCorr();
  
  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

private:
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;
};

checkLaserCorr::checkLaserCorr(const edm::ParameterSet& iConfig) 
{}

checkLaserCorr::~checkLaserCorr() 
{}

void checkLaserCorr::analyze(const edm::Event& event, const edm::EventSetup& iSetup) {

  edm::ESHandle<CaloGeometry> geometry;
  iSetup.get<CaloGeometryRecord>().get(geometry);
 
 // Laser corrections
  edm::ESHandle<EcalLaserDbService> pLaser;
  iSetup.get<EcalLaserDbRecord>().get(pLaser); 

  const CaloSubdetectorGeometry* EB = geometry->getSubdetectorGeometry(DetId::Ecal, EcalBarrel);
  const CaloSubdetectorGeometry* EE = geometry->getSubdetectorGeometry(DetId::Ecal, EcalEndcap);

  const std::vector<DetId>& myEBDetids = EB->getValidDetIds();
  const std::vector<DetId>& myEEDetids = EE->getValidDetIds();

  std::cout << "BARREL" << std::endl;
  for (unsigned int i=0; i<myEBDetids.size(); i++) {
    
    float lasercalib = 1;
    lasercalib = pLaser->getLaserCorrection(myEBDetids[i], event.time());
    std::cout << ((EBDetId)myEBDetids[i]).ieta() << " " <<  ((EBDetId)myEBDetids[i]).iphi() << " " << ((EBDetId)myEBDetids[i]).zside() << " " <<  1/lasercalib << std::endl; 
    ///const CaloCellGeometry* this_cell = EB->getGeometry(myEBDetids[i]);
    //iff (this_cell) {
    //  GlobalPoint posi = this_cell->getPosition();
    //  std::cout << myEBDetids[i].rawId() << " / "  << posi.x() << " " << posi.y() << " " << posi.z() << " " << 1/lasercalib << std::endl;
    //}
  }
  std::cout << "ENDCAP" << std::endl;
  for (unsigned int i=0; i<myEEDetids.size(); i++) {
    //const CaloCellGeometry* this_cell = EE->getGeometry(myEEDetids[i]);
    
    float lasercalib = 1;
    lasercalib = pLaser->getLaserCorrection(myEEDetids[i], event.time());
    std::cout << ((EEDetId)myEEDetids[i]).ix() << " " <<  ((EEDetId)myEEDetids[i]).iy() << " " <<  ((EEDetId)myEEDetids[i]).zside() << " " <<  1/lasercalib << std::endl; 
    //if (this_cell) {
    //  GlobalPoint posi = this_cell->getPosition();
      //std::cout << myEEDetids[i].rawId() << " / " << posi.x() << " " << posi.y() << " " << posi.z() << " " << 1/lasercalib << std::endl;
    //}
  }
  std::cout << event.run() << std::endl;
} 
 
void checkLaserCorr::beginJob() 
{}

void checkLaserCorr::endJob() 
{}

void checkLaserCorr::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

DEFINE_FWK_MODULE(checkLaserCorr);
