import FWCore.ParameterSet.Config as cms

isoDump = cms.EDAnalyzer('MyCandidates',
                         RootFileName = cms.string("hlt.root"),
                         ProbeCandCollection = cms.InputTag("hltRecoEcalSuperClusterActivityCandidate"),
                         SieieMapProbeCollection = cms.InputTag("hltActivityPhotonClusterShape"),
                         HoeMapProbeCollection = cms.InputTag("hltActivityPhotonHcalForHE"),
                         IsoMapProbeCollection = cms.InputTag("hltActivityPhotonEcalIso"),
                         HcalMapProbeCollection = cms.InputTag("hltActivityPhotonHcalIso"),
                         DetaMapProbeCollection = cms.InputTag("hlt3HitElectronActivityDetaDphi:Deta"),
                         DphiMapProbeCollection = cms.InputTag("hlt3HitElectronActivityDetaDphi:Dphi"),
                         TkisoMapProbeCollection = cms.InputTag("hlt3HitElectronActivityTrackIso"),
                         TagCandCollection = cms.InputTag("hltL1SeededRecoEcalCandidate"),
                         IsoMapTagCollection = cms.InputTag("hltL1SeededPhotonEcalIso"),
                         HLTEleCollection = cms.InputTag("hltPixelMatch3HitElectronsActivity"),
)
