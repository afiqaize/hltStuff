import FWCore.ParameterSet.Config as cms

process = cms.Process("ExREG")
process.load("Configuration.StandardSequences.Services_cff")
process.load('Configuration.Geometry.GeometryDB_cff')
process.load('Configuration/StandardSequences/MagneticField_38T_cff')
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.load("Configuration.StandardSequences.Reconstruction_cff")
process.GlobalTag.globaltag = 'FT_R_53_V21::All'
#process.GlobalTag.connect   = 'frontier://FrontierProd/CMS_COND_31X_GLOBALTAG'
#process.GlobalTag.pfnPrefix = cms.untracked.string('frontier://FrontierProd/')
##process.GlobalTag.pfnPrefix = cms.untracked.string('frontier://FrontierArc/')
from Configuration.AlCa.GlobalTag import GlobalTag as customiseGlobalTag
process.GlobalTag = customiseGlobalTag(process.GlobalTag, globaltag = 'FT_R_53_V21::All')
#process.GlobalTag = customiseGlobalTag(process.GlobalTag, globaltag = 'GR_H_V32::All')
    
#process.GlobalTag.globaltag = 'GR_H_V32::All'

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring('/store/data/Run2012A/DoubleElectron/RAW-RECO/ZElectron-22Jan2013-v1/20000/9AC4BF5F-AE67-E211-9BBC-0026189437FA.root')
                            #fileNames = cms.untracked.vstring('/store/data/Run2012D/DoubleElectron/RAW-RECO/ZElectron-22Jan2013-v1/10000/F8910EF8-A58F-E211-BC68-00259059642E.root'),
                            )

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1)
    )


#process.source = cms.Source("EmptySource")

process.checkLC = cms.EDAnalyzer("checkLaserCorr")
process.p = cms.Path(process.checkLC)

                                        
