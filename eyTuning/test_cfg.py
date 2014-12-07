import FWCore.ParameterSet.Config as cms

process = cms.Process("PLOT")
process.load("Configuration.StandardSequences.Services_cff")
process.load('Configuration.Geometry.GeometryDB_cff')
process.load('Configuration/StandardSequences/MagneticField_38T_cff')
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.load("Configuration.StandardSequences.Reconstruction_cff")
process.GlobalTag.globaltag = 'MCRUN2_72_V3A::All'

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
    )

process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32(1000)


process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring(
                                '/store/group/phys_top/triggerStudies/path_output/qcd120_cut1p0_721p2_03.root',
                                '/store/group/phys_top/triggerStudies/path_output/qcd120_cut1p0_721p2_04.root',
                            )
                        )

process.plotDistr = cms.EDAnalyzer("plotDistr",
                                   OutputFileName = cms.string("qcd120_02.root"),
                                   isData = cms.bool(False),
                                   activateNewClustering = cms.bool(True),
                                   activateOldClustering = cms.bool(False),
                                   saveReco = cms.bool(False),
                                   saveUnseeded = cms.bool(True),
                                   trgResults = cms.InputTag("TriggerResults","","NTUPLE"),
                                   trgSelection = cms.vstring("HLT_Ele27_eta2p1_Cut1p0_Gsf_v1",)
                                   )
process.p = cms.Path(process.plotDistr)

                                        
