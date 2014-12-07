// GenSkim for tt
// 19/6/2014

// system include files
#include <memory>
#include <iostream>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDFilter.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/JetReco/interface/GenJet.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "TH1.h"
#include "TTree.h"

//
// class declaration
//

using namespace std;

const int maxLepton = 2;
const int maxQuark = 6; // includes b
const int maxGenJets = 99;

class GenAnalyzer_tt : public edm::EDFilter {

	public:
		explicit GenAnalyzer_tt(const edm::ParameterSet&);
		~GenAnalyzer_tt();

		const reco::Candidate* getGeneratorFinalStateFor(const reco::Candidate*, bool=false);

		virtual bool filter(edm::Event&, const edm::EventSetup&);

	private:

		// ----------member data ---------------------------
		edm::InputTag genParticleTag_, genJetTag_;

		float jetPt[maxGenJets], jetEta[maxGenJets];
		void resetTree();
		int nEvt, nRun;
                float topPt, topEta, bPt, bEta, WPt, WEta;

		int nLep, lepId[maxLepton];
		float lepPt[maxLepton], lepEta[maxLepton], lepPhi[maxLepton];
		int nQuark, quarkId[maxQuark];
		float quarkPt[maxQuark], quarkEta[maxQuark], quarkPhi[maxQuark];

		int decayType_;
		int leptonFlavor_;
		bool doKinSel;
                double lepPtCut, lepEtaCut;
                double jetPtCut, jetEtaCut;

		typedef std::pair<int,double> OrderPair;
		struct IndexByPt {

			const bool operator() (const OrderPair& j1, const OrderPair& j2) const {return j1.second > j2.second;}

		};
};

