import FWCore.ParameterSet.Config as cms

process = cms.Process("ExREG")
process.load("Configuration.StandardSequences.Services_cff")
process.load('Configuration.Geometry.GeometryDB_cff')
process.load('Configuration/StandardSequences/MagneticField_38T_cff')
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.load("Configuration.StandardSequences.Reconstruction_cff")
process.GlobalTag.globaltag = 'PRE_ST62_V8::All'
#START53_V10::All'

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
    )


process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring('file:../../../outputA_test.root')
                            )

process.plotDistr = cms.EDAnalyzer("checkClustering")
process.p = cms.Path(process.plotDistr)

                                        
