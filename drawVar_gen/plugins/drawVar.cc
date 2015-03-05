#include "drawVar.h"

//
drawVar::drawVar(const edm::ParameterSet& iConfig)
{

  doMatching = false;
  pathName = "";
  filterName = "";
  ptCutGen = 0.;
  etaCutGen = 9999.;
  
  doMatching = iConfig.getParameter<bool>("doMatching"); 
  pathName = iConfig.getParameter<std::string>("pathName");
  filterName = iConfig.getParameter<std::string>("filterName");
  procName = iConfig.getParameter<std::string>("procName");
  ptCutGen = iConfig.getParameter<double>("ptCutGen");
  etaCutGen = iConfig.getParameter<double>("etaCutGen");

}


drawVar::~drawVar()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
drawVar::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
    using namespace edm;
    using namespace std;

    edm::Handle<GenEventInfoProduct> genEvent;
    iEvent.getByLabel("generator", genEvent);

    edm::Handle<reco::GenParticleCollection> genParticles;
    iEvent.getByLabel( "genParticles", genParticles );

    edm::InputTag triggerResultsLabel = edm::InputTag("TriggerResults", "", procName);
    edm::Handle<edm::TriggerResults> triggerResults;
    iEvent.getByLabel(triggerResultsLabel, triggerResults);

    // open the trigger summary
    edm::InputTag triggerSummaryLabel_ = edm::InputTag("hltTriggerSummaryAOD", "", procName);
    edm::Handle<trigger::TriggerEvent> triggerSummary;
    iEvent.getByLabel(triggerSummaryLabel_, triggerSummary);
    
    // trigger objects we want to match
    edm::InputTag ElectronFilterTag = edm::InputTag(filterName, "", procName);

    trigger::TriggerObjectCollection allTriggerObjects;    
    trigger::TriggerObjectCollection ElectronsObjects;

    if (doMatching) {

      bool changedConfig = false;
      if (!hltConfig.init(iEvent.getRun(), iSetup, procName, changedConfig)) {

        cout << "Initialization of HLTConfigProvider failed!!" << endl;
        return;

      }

      if (changedConfig) {

        std::cout << "the curent menu is " << hltConfig.tableName() << std::endl;
        triggerBit = -1;

        for (size_t j = 0; j < hltConfig.triggerNames().size(); j++) {

            if (TString(hltConfig.triggerNames()[j]).Contains(pathName)) triggerBit = j;

        }

        if (triggerBit == -1) cout << "HLT path not found" << endl;
       
      }
 
      //find the index corresponding to the event
      size_t ElectronFilterIndex = (*triggerSummary).filterIndex(ElectronFilterTag);
    
      allTriggerObjects = triggerSummary->getObjects();    
    
      if (ElectronFilterIndex < (*triggerSummary).sizeFilters()) { //check if the trigger object is present

        //save the trigger objetcs corresponding to electron leg
        const trigger::Keys &keysElectrons = (*triggerSummary).filterKeys(ElectronFilterIndex);

        for (size_t j = 0; j < keysElectrons.size(); j++) {

            trigger::TriggerObject foundObject = (allTriggerObjects)[keysElectrons[j]];
            ElectronsObjects.push_back(foundObject);

        }
      }
    }

    int theNbOfGen = genParticles->size();
    for (int i=0 ; i < theNbOfGen; i++) {

      const reco::GenParticle &genElectron = (*genParticles)[i];

      if ((fabs(genElectron.pdgId())==11) && (genElectron.status()==1) && (hasWasMother(genElectron))) {

        if ((fabs(genElectron.eta()) > etaCutGen)) continue; //eta acceptance cut
        if ((genElectron.pt() < ptCutGen)) continue; //pt acceptance cut

        histos1D_[ "ptElectron_gen" ]->Fill(genElectron.pt());
        histos1D_[ "etaElectron_gen" ]->Fill(genElectron.eta());

        if (doMatching) {

          if (triggerResults->accept(triggerBit)) {

            histos1D_[ "ptElectron_pass" ]->Fill(genElectron.pt());
            histos1D_[ "etaElectron_pass" ]->Fill(genElectron.eta());

          }

          if (isMatchedWithTrigger(genElectron, ElectronsObjects)) {

            histos1D_[ "ptElectron_match" ]->Fill(genElectron.pt());
            histos1D_[ "etaElectron_match" ]->Fill(genElectron.eta());

          }
        }
      }
    }
}

// ------------ method called once each job just before starting event loop  ------------
void 
drawVar::beginJob()
{
    edm::Service< TFileService > fileService;

    float ptBins[26] = {0., 5., 10., 15., 20., 25., 30., 32., 34., 36., 38., 40., 42., 44., 46., 48., 50., 55., 60., 70., 80., 90., 110., 130., 150., 200.};
    
    histos1D_[ "ptElectron_gen" ] = fileService->make< TH1D >( "ptElectron_gen", "nb of electron", 25, ptBins);
    histos1D_[ "ptElectron_gen" ]->SetXTitle( "electron p_{T} (GeV)" );
    
    histos1D_[ "etaElectron_gen" ] = fileService->make< TH1D >( "etaElectron_gen", "nb of electron", 30, -3., 3.);
    histos1D_[ "etaElectron_gen" ]->SetXTitle( "electron #eta" );

    histos1D_[ "ptElectron_pass" ] = fileService->make< TH1D >( "ptElectron_pass", "nb of electron passing", 25, ptBins);
    histos1D_[ "ptElectron_pass" ]->SetXTitle( "electron p_{T} (GeV)" );
    
    histos1D_[ "etaElectron_pass" ] = fileService->make< TH1D >( "etaElectron_pass", "nb of electron passing", 30, -3., 3.);
    histos1D_[ "etaElectron_pass" ]->SetXTitle( "electron #eta" );

    histos1D_[ "ptElectron_match" ] = fileService->make< TH1D >( "ptElectron_match", "nb of electron matched", 25, ptBins);
    histos1D_[ "ptElectron_match" ]->SetXTitle( "electron p_{T} (GeV)" );
    
    histos1D_[ "etaElectron_match" ] = fileService->make< TH1D >( "etaElectron_match", "nb of electron passing matched", 30, -3., 3.);
    histos1D_[ "etaElectron_match" ]->SetXTitle( "electron #eta" );

}

// ------------ method called once each job just after ending the event loop  ------------
void drawVar::endJob()
{

}

bool drawVar::hasWasMother(const reco::GenParticle p)
{

    bool foundW = false;
    if (p.numberOfMothers()==0) return foundW;
    const reco::Candidate  *part = (p.mother());

    // loop on the mother particles to check if is has a W has mother
    while ((part->numberOfMothers() > 0)) {

        const reco::Candidate  *MomPart =part->mother();

        if (fabs(MomPart->pdgId()) == 24) {

            foundW = true;
            break;

        }

        part = MomPart;

    }

    return foundW;

}

bool drawVar::isMatchedWithTrigger(const reco::GenParticle p, trigger::TriggerObjectCollection triggerObjects)
{

    for (unsigned int i = 0 ; i < triggerObjects.size() ; i++) {

        float deltaR = sqrt( pow(triggerObjects[i].eta() - p.eta(), 2) + pow(acos(cos(triggerObjects[i].phi() - p.phi())), 2));
        if (deltaR < 0.1) return true;

    }

    return false;

}

// ------------ method called when starting to processes a run  ------------
/*
void 
drawVar::beginRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a run  ------------
/*
void 
drawVar::endRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when starting to processes a luminosity block  ------------
/*
void 
drawVar::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a luminosity block  ------------
/*
void 
drawVar::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
drawVar::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {

}

//define this as a plug-in
DEFINE_FWK_MODULE(drawVar);
