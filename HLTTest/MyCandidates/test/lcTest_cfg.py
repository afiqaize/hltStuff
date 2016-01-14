import FWCore.ParameterSet.Config as cms

process = cms.Process("ExREG")
process.load("Configuration.StandardSequences.Services_cff")
process.load('Configuration.Geometry.GeometryDB_cff')
process.load('Configuration/StandardSequences/MagneticField_38T_cff')
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.load("Configuration.StandardSequences.Reconstruction_cff")
process.GlobalTag.globaltag = 'START53_V7D::All'

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
    )


process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring('file:../../../crys_old.root')
                            )

process.plotDistr = cms.EDAnalyzer("plotDistr",
                                   OutputFileName = cms.string("crys_old.root"),
                                   isData = cms.bool(True),
                                   activateNewClustering = cms.bool(False),
                                   activateOldClustering = cms.bool(True),
                                   saveReco = cms.bool(True)
                                   )
process.p = cms.Path(process.plotDistr)

                                        
