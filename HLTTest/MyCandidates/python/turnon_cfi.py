
import FWCore.ParameterSet.Config as cms

turnOn = cms.EDAnalyzer('TurnOn',
                        RootFileName = cms.string("hlt.root"),
                        IsoValElectronPF = cms.VInputTag(cms.InputTag('elPFIsoValueCharged03PFIdPFIso'),
                                                         cms.InputTag('elPFIsoValueGamma03PFIdPFIso'),
                                                         cms.InputTag('elPFIsoValueNeutral03PFIdPFIso')),
)
