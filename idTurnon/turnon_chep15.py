# /dev/CMSSW_7_4_0/GRun/V13 (CMSSW_7_4_0_pre7_HLT1)

import FWCore.ParameterSet.Config as cms

process = cms.Process( "TURNON" )

process.load("setup_740")

process.HLTConfigVersion = cms.PSet(
  tableName = cms.string('/dev/CMSSW_7_4_0/GRun/V13')
)

process.HLTIter4PSetTrajectoryFilterIT = cms.PSet( 
  minPt = cms.double( 0.3 ),
  minHitsMinPt = cms.int32( 3 ),
  ComponentType = cms.string( "CkfBaseTrajectoryFilter" ),
  maxLostHits = cms.int32( 0 ),
  maxNumberOfHits = cms.int32( 100 ),
  maxConsecLostHits = cms.int32( 1 ),
  minimumNumberOfHits = cms.int32( 6 ),
  nSigmaMinPt = cms.double( 5.0 ),
  chargeSignificance = cms.double( -1.0 )
)
process.HLTIter3PSetTrajectoryFilterIT = cms.PSet( 
  minPt = cms.double( 0.3 ),
  minHitsMinPt = cms.int32( 3 ),
  ComponentType = cms.string( "CkfBaseTrajectoryFilter" ),
  maxLostHits = cms.int32( 0 ),
  maxNumberOfHits = cms.int32( 100 ),
  maxConsecLostHits = cms.int32( 1 ),
  minimumNumberOfHits = cms.int32( 3 ),
  nSigmaMinPt = cms.double( 5.0 ),
  chargeSignificance = cms.double( -1.0 )
)
process.HLTIter2PSetTrajectoryFilterIT = cms.PSet( 
  minPt = cms.double( 0.3 ),
  minHitsMinPt = cms.int32( 3 ),
  ComponentType = cms.string( "CkfBaseTrajectoryFilter" ),
  maxLostHits = cms.int32( 1 ),
  maxNumberOfHits = cms.int32( 100 ),
  maxConsecLostHits = cms.int32( 1 ),
  minimumNumberOfHits = cms.int32( 3 ),
  nSigmaMinPt = cms.double( 5.0 ),
  chargeSignificance = cms.double( -1.0 )
)
process.HLTIter1PSetTrajectoryFilterIT = cms.PSet( 
  minPt = cms.double( 0.2 ),
  minHitsMinPt = cms.int32( 3 ),
  ComponentType = cms.string( "CkfBaseTrajectoryFilter" ),
  maxLostHits = cms.int32( 1 ),
  maxNumberOfHits = cms.int32( 100 ),
  maxConsecLostHits = cms.int32( 1 ),
  minimumNumberOfHits = cms.int32( 3 ),
  nSigmaMinPt = cms.double( 5.0 ),
  chargeSignificance = cms.double( -1.0 )
)
process.HLTPSetbJetRegionalTrajectoryFilter = cms.PSet( 
  minPt = cms.double( 1.0 ),
  minHitsMinPt = cms.int32( 3 ),
  ComponentType = cms.string( "CkfBaseTrajectoryFilter" ),
  maxLostHits = cms.int32( 1 ),
  maxNumberOfHits = cms.int32( 8 ),
  maxConsecLostHits = cms.int32( 1 ),
  minimumNumberOfHits = cms.int32( 5 ),
  nSigmaMinPt = cms.double( 5.0 ),
  chargeSignificance = cms.double( -1.0 )
)
process.HLTPSetTrajectoryFilterL3 = cms.PSet( 
  minPt = cms.double( 0.5 ),
  minHitsMinPt = cms.int32( 3 ),
  ComponentType = cms.string( "CkfBaseTrajectoryFilter" ),
  maxLostHits = cms.int32( 1 ),
  maxNumberOfHits = cms.int32( 1000000000 ),
  maxConsecLostHits = cms.int32( 1 ),
  minimumNumberOfHits = cms.int32( 5 ),
  nSigmaMinPt = cms.double( 5.0 ),
  chargeSignificance = cms.double( -1.0 )
)
process.HLTPSetTrajectoryFilterIT = cms.PSet( 
  minPt = cms.double( 0.3 ),
  minHitsMinPt = cms.int32( 3 ),
  ComponentType = cms.string( "CkfBaseTrajectoryFilter" ),
  maxLostHits = cms.int32( 1 ),
  maxNumberOfHits = cms.int32( 100 ),
  maxConsecLostHits = cms.int32( 1 ),
  minimumNumberOfHits = cms.int32( 3 ),
  nSigmaMinPt = cms.double( 5.0 ),
  chargeSignificance = cms.double( -1.0 )
)
process.HLTPSetTrajectoryFilterForElectrons = cms.PSet( 
  ComponentType = cms.string( "CkfBaseTrajectoryFilter" ),
  minPt = cms.double( 2.0 ),
  minHitsMinPt = cms.int32( -1 ),
  maxLostHits = cms.int32( 1 ),
  maxNumberOfHits = cms.int32( -1 ),
  maxConsecLostHits = cms.int32( 1 ),
  nSigmaMinPt = cms.double( 5.0 ),
  minimumNumberOfHits = cms.int32( 5 ),
  chargeSignificance = cms.double( -1.0 )
)
process.HLTPSetMuonCkfTrajectoryFilter = cms.PSet( 
  minPt = cms.double( 0.9 ),
  minHitsMinPt = cms.int32( 3 ),
  ComponentType = cms.string( "CkfBaseTrajectoryFilter" ),
  maxLostHits = cms.int32( 1 ),
  maxNumberOfHits = cms.int32( -1 ),
  maxConsecLostHits = cms.int32( 1 ),
  chargeSignificance = cms.double( -1.0 ),
  nSigmaMinPt = cms.double( 5.0 ),
  minimumNumberOfHits = cms.int32( 5 )
)
process.HLTPSetMuTrackJpsiTrajectoryFilter = cms.PSet( 
  minPt = cms.double( 10.0 ),
  minHitsMinPt = cms.int32( 3 ),
  ComponentType = cms.string( "CkfBaseTrajectoryFilter" ),
  maxLostHits = cms.int32( 1 ),
  maxNumberOfHits = cms.int32( 8 ),
  maxConsecLostHits = cms.int32( 1 ),
  minimumNumberOfHits = cms.int32( 5 ),
  nSigmaMinPt = cms.double( 5.0 ),
  chargeSignificance = cms.double( -1.0 )
)
process.HLTPSetMuTrackJpsiEffTrajectoryFilter = cms.PSet( 
  minPt = cms.double( 1.0 ),
  minHitsMinPt = cms.int32( 3 ),
  ComponentType = cms.string( "CkfBaseTrajectoryFilter" ),
  maxLostHits = cms.int32( 1 ),
  maxNumberOfHits = cms.int32( 9 ),
  maxConsecLostHits = cms.int32( 1 ),
  minimumNumberOfHits = cms.int32( 5 ),
  nSigmaMinPt = cms.double( 5.0 ),
  chargeSignificance = cms.double( -1.0 )
)
process.HLTPSetCkfTrajectoryFilter = cms.PSet( 
  minPt = cms.double( 0.9 ),
  minHitsMinPt = cms.int32( 3 ),
  ComponentType = cms.string( "CkfBaseTrajectoryFilter" ),
  maxLostHits = cms.int32( 1 ),
  maxNumberOfHits = cms.int32( -1 ),
  maxConsecLostHits = cms.int32( 1 ),
  minimumNumberOfHits = cms.int32( 5 ),
  nSigmaMinPt = cms.double( 5.0 ),
  chargeSignificance = cms.double( -1.0 )
)
process.HLTPSetCkf3HitTrajectoryFilter = cms.PSet( 
  minPt = cms.double( 0.9 ),
  minHitsMinPt = cms.int32( 3 ),
  ComponentType = cms.string( "CkfBaseTrajectoryFilter" ),
  maxLostHits = cms.int32( 1 ),
  maxNumberOfHits = cms.int32( -1 ),
  maxConsecLostHits = cms.int32( 1 ),
  minimumNumberOfHits = cms.int32( 3 ),
  nSigmaMinPt = cms.double( 5.0 ),
  chargeSignificance = cms.double( -1.0 )
)
process.HLTIter4PSetTrajectoryBuilderIT = cms.PSet( 
  propagatorAlong = cms.string( "PropagatorWithMaterialParabolicMf" ),
  trajectoryFilter = cms.PSet(  refToPSet_ = cms.string( "HLTIter4PSetTrajectoryFilterIT" ) ),
  maxCand = cms.int32( 1 ),
  ComponentType = cms.string( "CkfTrajectoryBuilder" ),
  propagatorOpposite = cms.string( "PropagatorWithMaterialParabolicMfOpposite" ),
  MeasurementTrackerName = cms.string( "hltIter4ESPMeasurementTracker" ),
  estimator = cms.string( "hltESPChi2ChargeMeasurementEstimator16" ),
  TTRHBuilder = cms.string( "hltESPTTRHBWithTrackAngle" ),
  updator = cms.string( "hltESPKFUpdator" ),
  alwaysUseInvalidHits = cms.bool( False ),
  intermediateCleaning = cms.bool( True ),
  lostHitPenalty = cms.double( 30.0 ),
  minNrOfHitsForRebuild = cms.untracked.int32( 4 )
)
process.HLTIter3PSetTrajectoryBuilderIT = cms.PSet( 
  propagatorAlong = cms.string( "PropagatorWithMaterialParabolicMf" ),
  trajectoryFilter = cms.PSet(  refToPSet_ = cms.string( "HLTIter3PSetTrajectoryFilterIT" ) ),
  maxCand = cms.int32( 1 ),
  ComponentType = cms.string( "CkfTrajectoryBuilder" ),
  propagatorOpposite = cms.string( "PropagatorWithMaterialParabolicMfOpposite" ),
  MeasurementTrackerName = cms.string( "hltIter3ESPMeasurementTracker" ),
  estimator = cms.string( "hltESPChi2ChargeMeasurementEstimator16" ),
  TTRHBuilder = cms.string( "hltESPTTRHBWithTrackAngle" ),
  updator = cms.string( "hltESPKFUpdator" ),
  alwaysUseInvalidHits = cms.bool( False ),
  intermediateCleaning = cms.bool( True ),
  lostHitPenalty = cms.double( 30.0 )
)
process.HLTIter2PSetTrajectoryBuilderIT = cms.PSet( 
  propagatorAlong = cms.string( "PropagatorWithMaterialParabolicMf" ),
  trajectoryFilter = cms.PSet(  refToPSet_ = cms.string( "HLTIter2PSetTrajectoryFilterIT" ) ),
  maxCand = cms.int32( 2 ),
  ComponentType = cms.string( "CkfTrajectoryBuilder" ),
  propagatorOpposite = cms.string( "PropagatorWithMaterialParabolicMfOpposite" ),
  MeasurementTrackerName = cms.string( "hltIter2ESPMeasurementTracker" ),
  estimator = cms.string( "hltESPChi2ChargeMeasurementEstimator16" ),
  TTRHBuilder = cms.string( "hltESPTTRHBWithTrackAngle" ),
  updator = cms.string( "hltESPKFUpdator" ),
  alwaysUseInvalidHits = cms.bool( False ),
  intermediateCleaning = cms.bool( True ),
  lostHitPenalty = cms.double( 30.0 )
)
process.HLTIter1PSetTrajectoryBuilderIT = cms.PSet( 
  propagatorAlong = cms.string( "PropagatorWithMaterialParabolicMf" ),
  trajectoryFilter = cms.PSet(  refToPSet_ = cms.string( "HLTIter1PSetTrajectoryFilterIT" ) ),
  maxCand = cms.int32( 2 ),
  ComponentType = cms.string( "CkfTrajectoryBuilder" ),
  propagatorOpposite = cms.string( "PropagatorWithMaterialParabolicMfOpposite" ),
  MeasurementTrackerName = cms.string( "hltIter1ESPMeasurementTracker" ),
  estimator = cms.string( "hltESPChi2ChargeMeasurementEstimator16" ),
  TTRHBuilder = cms.string( "hltESPTTRHBWithTrackAngle" ),
  updator = cms.string( "hltESPKFUpdator" ),
  alwaysUseInvalidHits = cms.bool( False ),
  intermediateCleaning = cms.bool( True ),
  lostHitPenalty = cms.double( 30.0 )
)
process.HLTPSetTrajectoryBuilderForElectrons = cms.PSet( 
  propagatorAlong = cms.string( "hltESPFwdElectronPropagator" ),
  trajectoryFilter = cms.PSet(  refToPSet_ = cms.string( "HLTPSetTrajectoryFilterForElectrons" ) ),
  maxCand = cms.int32( 5 ),
  ComponentType = cms.string( "CkfTrajectoryBuilder" ),
  propagatorOpposite = cms.string( "hltESPBwdElectronPropagator" ),
  MeasurementTrackerName = cms.string( "hltESPMeasurementTracker" ),
  estimator = cms.string( "hltESPChi2ChargeMeasurementEstimator30" ),
  TTRHBuilder = cms.string( "hltESPTTRHBWithTrackAngle" ),
  updator = cms.string( "hltESPKFUpdator" ),
  alwaysUseInvalidHits = cms.bool( True ),
  intermediateCleaning = cms.bool( False ),
  lostHitPenalty = cms.double( 90.0 )
)
process.HLTPSetMuTrackJpsiTrajectoryBuilder = cms.PSet( 
  propagatorAlong = cms.string( "PropagatorWithMaterial" ),
  trajectoryFilter = cms.PSet(  refToPSet_ = cms.string( "HLTPSetMuTrackJpsiTrajectoryFilter" ) ),
  maxCand = cms.int32( 1 ),
  ComponentType = cms.string( "CkfTrajectoryBuilder" ),
  propagatorOpposite = cms.string( "PropagatorWithMaterialOpposite" ),
  MeasurementTrackerName = cms.string( "hltESPMeasurementTracker" ),
  estimator = cms.string( "hltESPChi2ChargeMeasurementEstimator30" ),
  TTRHBuilder = cms.string( "hltESPTTRHBWithTrackAngle" ),
  updator = cms.string( "hltESPKFUpdator" ),
  alwaysUseInvalidHits = cms.bool( False ),
  intermediateCleaning = cms.bool( True ),
  lostHitPenalty = cms.double( 30.0 )
)
process.HLTPSetMuTrackJpsiEffTrajectoryBuilder = cms.PSet( 
  propagatorAlong = cms.string( "PropagatorWithMaterial" ),
  trajectoryFilter = cms.PSet(  refToPSet_ = cms.string( "HLTPSetMuTrackJpsiEffTrajectoryFilter" ) ),
  maxCand = cms.int32( 1 ),
  ComponentType = cms.string( "CkfTrajectoryBuilder" ),
  propagatorOpposite = cms.string( "PropagatorWithMaterialOpposite" ),
  MeasurementTrackerName = cms.string( "hltESPMeasurementTracker" ),
  estimator = cms.string( "hltESPChi2ChargeMeasurementEstimator30" ),
  TTRHBuilder = cms.string( "hltESPTTRHBWithTrackAngle" ),
  updator = cms.string( "hltESPKFUpdator" ),
  alwaysUseInvalidHits = cms.bool( False ),
  intermediateCleaning = cms.bool( True ),
  lostHitPenalty = cms.double( 30.0 )
)
process.HLTPSetMuonCkfTrajectoryBuilderSeedHit = cms.PSet( 
  propagatorAlong = cms.string( "PropagatorWithMaterial" ),
  trajectoryFilter = cms.PSet(  refToPSet_ = cms.string( "HLTPSetMuonCkfTrajectoryFilter" ) ),
  maxCand = cms.int32( 5 ),
  ComponentType = cms.string( "MuonCkfTrajectoryBuilder" ),
  propagatorOpposite = cms.string( "PropagatorWithMaterialOpposite" ),
  useSeedLayer = cms.bool( True ),
  deltaEta = cms.double( -1.0 ),
  deltaPhi = cms.double( -1.0 ),
  estimator = cms.string( "hltESPChi2ChargeMeasurementEstimator30" ),
  rescaleErrorIfFail = cms.double( 1.0 ),
  propagatorProximity = cms.string( "SteppingHelixPropagatorAny" ),
  updator = cms.string( "hltESPKFUpdator" ),
  alwaysUseInvalidHits = cms.bool( True ),
  TTRHBuilder = cms.string( "hltESPTTRHBWithTrackAngle" ),
  MeasurementTrackerName = cms.string( "hltESPMeasurementTracker" ),
  intermediateCleaning = cms.bool( False ),
  lostHitPenalty = cms.double( 30.0 )
)
process.HLTPSetMuonCkfTrajectoryBuilder = cms.PSet( 
  propagatorAlong = cms.string( "PropagatorWithMaterial" ),
  trajectoryFilter = cms.PSet(  refToPSet_ = cms.string( "HLTPSetMuonCkfTrajectoryFilter" ) ),
  maxCand = cms.int32( 5 ),
  ComponentType = cms.string( "MuonCkfTrajectoryBuilder" ),
  propagatorOpposite = cms.string( "PropagatorWithMaterialOpposite" ),
  useSeedLayer = cms.bool( False ),
  deltaEta = cms.double( -1.0 ),
  deltaPhi = cms.double( -1.0 ),
  estimator = cms.string( "hltESPChi2ChargeMeasurementEstimator30" ),
  rescaleErrorIfFail = cms.double( 1.0 ),
  propagatorProximity = cms.string( "SteppingHelixPropagatorAny" ),
  updator = cms.string( "hltESPKFUpdator" ),
  alwaysUseInvalidHits = cms.bool( True ),
  TTRHBuilder = cms.string( "hltESPTTRHBWithTrackAngle" ),
  MeasurementTrackerName = cms.string( "hltESPMeasurementTracker" ),
  intermediateCleaning = cms.bool( False ),
  lostHitPenalty = cms.double( 30.0 )
)
process.HLTPSetPvClusterComparer = cms.PSet( 
  track_pt_min = cms.double( 2.5 ),
  track_pt_max = cms.double( 10.0 ),
  track_chi2_max = cms.double( 9999999.0 ),
  track_prob_min = cms.double( -1.0 )
)
process.HLTIter0PSetTrajectoryBuilderIT = cms.PSet( 
  propagatorAlong = cms.string( "PropagatorWithMaterialParabolicMf" ),
  trajectoryFilter = cms.PSet(  refToPSet_ = cms.string( "HLTIter0PSetTrajectoryFilterIT" ) ),
  maxCand = cms.int32( 2 ),
  ComponentType = cms.string( "CkfTrajectoryBuilder" ),
  propagatorOpposite = cms.string( "PropagatorWithMaterialParabolicMfOpposite" ),
  estimator = cms.string( "hltESPChi2ChargeMeasurementEstimator9" ),
  TTRHBuilder = cms.string( "hltESPTTRHBWithTrackAngle" ),
  updator = cms.string( "hltESPKFUpdator" ),
  alwaysUseInvalidHits = cms.bool( False ),
  intermediateCleaning = cms.bool( True ),
  lostHitPenalty = cms.double( 30.0 )
)
process.HLTIter0PSetTrajectoryFilterIT = cms.PSet( 
  minPt = cms.double( 0.3 ),
  minHitsMinPt = cms.int32( 3 ),
  ComponentType = cms.string( "CkfBaseTrajectoryFilter" ),
  maxLostHits = cms.int32( 1 ),
  maxNumberOfHits = cms.int32( 100 ),
  maxConsecLostHits = cms.int32( 1 ),
  minimumNumberOfHits = cms.int32( 3 ),
  nSigmaMinPt = cms.double( 5.0 ),
  chargeSignificance = cms.double( -1.0 )
)
process.HLTPSetPvClusterComparerForBTag = cms.PSet( 
  track_pt_min = cms.double( 0.1 ),
  track_pt_max = cms.double( 20.0 ),
  track_chi2_max = cms.double( 20.0 ),
  track_prob_min = cms.double( -1.0 )
)
process.HLTSeedFromConsecutiveHitsTripletOnlyCreator = cms.PSet( 
  ComponentName = cms.string( "SeedFromConsecutiveHitsTripletOnlyCreator" ),
  propagator = cms.string( "PropagatorWithMaterialParabolicMf" )
)
process.HLTSeedFromConsecutiveHitsCreator = cms.PSet( 
  ComponentName = cms.string( "SeedFromConsecutiveHitsCreator" ),
  propagator = cms.string( "PropagatorWithMaterialParabolicMf" ),
  SeedMomentumForBOFF = cms.double( 5.0 ),
  OriginTransverseErrorMultiplier = cms.double( 1.0 ),
  MinOneOverPtError = cms.double( 1.0 ),
  SimpleMagneticField = cms.string( "ParabolicMf" ),
  TTRHBuilder = cms.string( "hltESPTTRHBWithTrackAngle" )
)
process.HLTIter0HighPtTkMuPSetTrajectoryBuilderIT = cms.PSet( 
  propagatorAlong = cms.string( "PropagatorWithMaterialParabolicMf" ),
  trajectoryFilter = cms.PSet(  refToPSet_ = cms.string( "HLTIter0PSetTrajectoryFilterIT" ) ),
  maxCand = cms.int32( 4 ),
  ComponentType = cms.string( "CkfTrajectoryBuilder" ),
  propagatorOpposite = cms.string( "PropagatorWithMaterialParabolicMfOpposite" ),
  estimator = cms.string( "hltESPChi2ChargeMeasurementEstimator30" ),
  TTRHBuilder = cms.string( "hltESPTTRHBWithTrackAngle" ),
  updator = cms.string( "hltESPKFUpdator" ),
  alwaysUseInvalidHits = cms.bool( True ),
  intermediateCleaning = cms.bool( True ),
  lostHitPenalty = cms.double( 30.0 )
)
process.HLTIter2HighPtTkMuPSetTrajectoryBuilderIT = cms.PSet( 
  propagatorAlong = cms.string( "PropagatorWithMaterialParabolicMf" ),
  trajectoryFilter = cms.PSet(  refToPSet_ = cms.string( "HLTIter2HighPtTkMuPSetTrajectoryFilterIT" ) ),
  maxCand = cms.int32( 2 ),
  ComponentType = cms.string( "CkfTrajectoryBuilder" ),
  propagatorOpposite = cms.string( "PropagatorWithMaterialParabolicMfOpposite" ),
  estimator = cms.string( "hltESPChi2ChargeMeasurementEstimator30" ),
  TTRHBuilder = cms.string( "hltESPTTRHBWithTrackAngle" ),
  updator = cms.string( "hltESPKFUpdator" ),
  alwaysUseInvalidHits = cms.bool( False ),
  intermediateCleaning = cms.bool( True ),
  lostHitPenalty = cms.double( 30.0 ),
  MeasurementTrackerName = cms.string( "hltIter2HighPtTkMuESPMeasurementTracker" )
)
process.HLTIter2HighPtTkMuPSetTrajectoryFilterIT = cms.PSet( 
  minPt = cms.double( 0.3 ),
  minHitsMinPt = cms.int32( 3 ),
  ComponentType = cms.string( "CkfBaseTrajectoryFilter" ),
  maxLostHits = cms.int32( 1 ),
  maxNumberOfHits = cms.int32( 100 ),
  maxConsecLostHits = cms.int32( 3 ),
  minimumNumberOfHits = cms.int32( 5 ),
  nSigmaMinPt = cms.double( 5.0 ),
  chargeSignificance = cms.double( -1.0 )
)
process.HLTPSetPvClusterComparerForIT = cms.PSet( 
  track_pt_min = cms.double( 1.0 ),
  track_pt_max = cms.double( 20.0 ),
  track_chi2_max = cms.double( 20.0 ),
  track_prob_min = cms.double( -1.0 )
)
process.streams = cms.PSet( 
  A = cms.vstring( 'InitialPD',
    'Templates' ),
  ALCAPHISYM = cms.vstring( 'AlCaPhiSym' ),
  Calibration = cms.vstring( 'TestEnablesEcalHcalDT' ),
  EcalCalibration = cms.vstring( 'EcalLaser' ),
  RPCMON = cms.vstring( 'RPCMonitor' )
)
process.datasets = cms.PSet( 
  AlCaPhiSym = cms.vstring( 'AlCa_EcalPhiSym_v1' ),
  EcalLaser = cms.vstring( 'HLT_EcalCalibration_v1' ),
  InitialPD = ( cms.vstring( 'HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v1',
    'HLT_Activity_Ecal_SC7_v1',
    'HLT_BTagMu_DiJet110_Mu5_v1',
    'HLT_BTagMu_DiJet20_Mu5_v1',
    'HLT_BTagMu_DiJet40_Mu5_v1',
    'HLT_BTagMu_DiJet70_Mu5_v1',
    'HLT_BTagMu_Jet300_Mu5_v1',
    'HLT_CaloJet500_NoJetID_v1',
    'HLT_CaloMET200_NoiseCleaned_v1',
    'HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose_BTagCSV0p7_v1',
    'HLT_CaloMHTNoPU90_PFMET90_PFMHT90_IDLoose_v1',
    'HLT_DiCentralPFJet70_PFMET120_NoiseCleaned_v1',
    'HLT_DiMu9_Ele9_CaloIdL_TrackIdL_v1',
    'HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu140_v1',
    'HLT_DiPFJet40_DEta3p5_MJJ600_PFMETNoMu80_v1',
    'HLT_DiPFJetAve100_HFJEC_v1',
    'HLT_DiPFJetAve160_HFJEC_v1',
    'HLT_DiPFJetAve220_HFJEC_v1',
    'HLT_DiPFJetAve300_HFJEC_v1',
    'HLT_DiPFJetAve30_HFJEC_v1',
    'HLT_DiPFJetAve60_HFJEC_v1',
    'HLT_DiPFJetAve80_HFJEC_v1',
    'HLT_Dimuon0_Jpsi_Muon_v1',
    'HLT_Dimuon0_Phi_Barrel_v1',
    'HLT_Dimuon0_Upsilon_Muon_v1',
    'HLT_Dimuon0er16_Jpsi_NoOS_NoVertexing_v1',
    'HLT_Dimuon0er16_Jpsi_NoVertexing_v1',
    'HLT_Dimuon10_Jpsi_Barrel_v1',
    'HLT_Dimuon13_PsiPrime_v1',
    'HLT_Dimuon13_Upsilon_v1',
    'HLT_Dimuon16_Jpsi_v1',
    'HLT_Dimuon20_Jpsi_v1',
    'HLT_Dimuon6_Jpsi_NoVertexing_v1',
    'HLT_Dimuon8_PsiPrime_Barrel_v1',
    'HLT_Dimuon8_Upsilon_Barrel_v1',
    'HLT_Diphoton30_18_R9Id85_AND_Iso50T80LCaloId24b40e_AND_HE10P0_R9Id50b80e_DoublePV_v1',
    'HLT_Diphoton30_18_R9Id85_AND_Iso50T80LCaloId24b40e_AND_HE10P0_R9Id50b80e_PV_v1',
    'HLT_Diphoton30_18_R9Id85_AND_Iso50T80LCaloId24b40e_AND_HE10P0_R9Id50b80e_Solid_Mass30_v1',
    'HLT_Diphoton44_28_R9Id85_OR_Iso50T80LCaloId24b40e_AND_HE10P1_R9Id50b80e_v1',
    'HLT_DoubleEle24_22_eta2p1_WP75_Gsf_v1',
    'HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_MW_v1',
    'HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v1',
    'HLT_DoubleEle8_CaloIdL_TrkIdVL_Mass8_PFHT300_v1',
    'HLT_DoubleIsoMu17_eta2p1_v1',
    'HLT_DoubleJet90_Double30_DoubleCSV0p5_v1',
    'HLT_DoubleJet90_Double30_TripleCSV0p5_v1',
    'HLT_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v1',
    'HLT_DoubleMu23NoFiltersNoVtxDisplaced_v1',
    'HLT_DoubleMu28NoFiltersNoVtxDisplaced_v1',
    'HLT_DoubleMu33NoFiltersNoVtx_v1',
    'HLT_DoubleMu38NoFiltersNoVtx_v1',
    'HLT_DoubleMu4_3_Bs_v1',
    'HLT_DoubleMu4_3_Jpsi_Displaced_v1',
    'HLT_DoubleMu4_JpsiTrk_Displaced_v1',
    'HLT_DoubleMu4_LowMassNonResonantTrk_Displaced_v1',
    'HLT_DoubleMu4_PsiPrimeTrk_Displaced_v1',
    'HLT_DoubleMu8_Mass8_PFHT300_v1',
    'HLT_DoublePhoton85_v1',
    'HLT_ECALHT800_v1',
    'HLT_Ele105_CaloIdVT_GsfTrkIdT_v1',
    'HLT_Ele10_CaloIdL_TrackIdVL_CentralPFJet30_BTagCSV0p5PF_v1',
    'HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30_v1',
    'HLT_Ele12_CaloIdL_TrackIdL_IsoVL_v1',
    'HLT_Ele15_IsoVVVL_BTagtop8CSV07_PFHT400_v1',
    'HLT_Ele15_IsoVVVL_PFHT400_PFMET70_v1',
    'HLT_Ele15_IsoVVVL_PFHT600_v1',
    'HLT_Ele15_PFHT300_v1',
    'HLT_Ele16_Ele12_Ele8_CaloIdL_TrackIdL_v1',
    'HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v1',
    'HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_v1',
    'HLT_Ele18_CaloIdL_TrackIdL_IsoVL_PFJet30_v1',
    'HLT_Ele20WP60_Ele8_Mass55_v1',
    'HLT_Ele22_eta2p1_WP75_Gsf_LooseIsoPFTau20_v1',
    'HLT_Ele22_eta2p1_WP75_Gsf_v1',
    'HLT_Ele23_CaloIdL_TrackIdL_IsoVL_PFJet30_v1',
    'HLT_Ele23_CaloIdL_TrackIdL_IsoVL_v1',
    'HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v1',
    'HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_v1',
    'HLT_Ele23_WP75_Gsf_v1',
    'HLT_Ele25WP60_SC4_Mass55_v1',
    'HLT_Ele25_eta2p1_WP85_Gsf_PFMET80_boostedW_v1',
    'HLT_Ele27_WP85_Gsf_v1',
    'HLT_Ele27_eta2p1_WP75_Gsf_CentralPFJet30_BTagCSV07_v1',
    'HLT_Ele27_eta2p1_WP75_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v1',
    'HLT_Ele27_eta2p1_WP75_Gsf_LooseIsoPFTau20_v1',
    'HLT_Ele27_eta2p1_WP75_Gsf_TriCentralPFJet30_v1',
    'HLT_Ele27_eta2p1_WP75_Gsf_TriCentralPFJet50_40_30_v1',
    'HLT_Ele27_eta2p1_WP75_Gsf_v1',
    'HLT_Ele27_eta2p1_WP85_Gsf_HT200_v1',
    'HLT_Ele32_eta2p1_WP75_Gsf_CentralPFJet30_BTagCSV07_v1',
    'HLT_Ele32_eta2p1_WP75_Gsf_DoubleMediumIsoPFTau40_Trk1_eta2p1_Reg_v1',
    'HLT_Ele32_eta2p1_WP75_Gsf_LooseIsoPFTau20_v1',
    'HLT_Ele32_eta2p1_WP75_Gsf_TriCentralPFJet30_v1',
    'HLT_Ele32_eta2p1_WP75_Gsf_TriCentralPFJet50_40_30_v1',
    'HLT_Ele32_eta2p1_WP75_Gsf_v1',
    'HLT_Ele33_CaloIdL_TrackIdL_IsoVL_PFJet30_v1',
    'HLT_Ele35_eta2p1_WP85_Gsf_v1',
    'HLT_Ele40_eta2p1_WP85_Gsf_v1',
    'HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v1',
    'HLT_HT200_v1',
    'HLT_HT250_v1',
    'HLT_HT300_v1',
    'HLT_HT350_DisplacedDijet40_DisplacedTrack_v1',
    'HLT_HT350_DisplacedDijet80_DisplacedTrack_v1',
    'HLT_HT350_DisplacedDijet80_Tight_DisplacedTrack_v1',
    'HLT_HT350_v1',
    'HLT_HT400_v1',
    'HLT_HT500_DisplacedDijet40_Inclusive_v1',
    'HLT_HT550_DisplacedDijet40_Inclusive_v1',
    'HLT_HT650_DisplacedDijet80_Inclusive_v1',
    'HLT_HT750_DisplacedDijet80_Inclusive_v1',
    'HLT_IsoMu16_eta2p1_CaloMET30_LooseIsoPFTau50_Trk30_eta2p1_v1',
    'HLT_IsoMu16_eta2p1_CaloMET30_v1',
    'HLT_IsoMu17_eta2p1_LooseIsoPFTau20_SingleL1_v1',
    'HLT_IsoMu17_eta2p1_LooseIsoPFTau20_v1',
    'HLT_IsoMu17_eta2p1_MediumIsoPFTau40_Trk1_eta2p1_Reg_v1',
    'HLT_IsoMu17_eta2p1_v1',
    'HLT_IsoMu20_eta2p1_CentralPFJet30_BTagCSV07_v1',
    'HLT_IsoMu20_eta2p1_TriCentralPFJet30_v1',
    'HLT_IsoMu20_eta2p1_TriCentralPFJet50_40_30_v1',
    'HLT_IsoMu20_eta2p1_v1',
    'HLT_IsoMu20_v1',
    'HLT_IsoMu24_eta2p1_CentralPFJet30_BTagCSV07_v1',
    'HLT_IsoMu24_eta2p1_LooseIsoPFTau20_v1',
    'HLT_IsoMu24_eta2p1_TriCentralPFJet30_v1',
    'HLT_IsoMu24_eta2p1_TriCentralPFJet50_40_30_v1',
    'HLT_IsoMu24_eta2p1_v1',
    'HLT_IsoMu27_v1',
    'HLT_IsoTkMu20_eta2p1_v1',
    'HLT_IsoTkMu20_v1',
    'HLT_IsoTkMu24_eta2p1_v1',
    'HLT_IsoTkMu27_v1',
    'HLT_JetE30_NoBPTX3BX_NoHalo_v1',
    'HLT_JetE30_NoBPTX_v1',
    'HLT_JetE50_NoBPTX3BX_NoHalo_v1',
    'HLT_JetE70_NoBPTX3BX_NoHalo_v1',
    'HLT_L1SingleEG5_OR_EG10_OR_EG20_v1',
    'HLT_L1SingleMuOpen_DT_v1',
    'HLT_L1SingleMuOpen_v1',
    'HLT_L1Tech_DT_GlobalOR_v1',
    'HLT_L1_TripleJet_VBF_v1',
    'HLT_L2DoubleMu23_NoVertex_v1',
    'HLT_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10_v1',
    'HLT_L2DoubleMu38_NoVertex_2Cha_Angle2p5_Mass10_v1',
    'HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo_v1',
    'HLT_L2Mu10_NoVertex_NoBPTX_v1',
    'HLT_L2Mu35_NoVertex_3Sta_NoBPTX3BX_NoHalo_v1',
    'HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX_NoHalo_v1',
    'HLT_LooseIsoPFTau50_Trk30_eta2p1_MET120_v1',
    'HLT_LooseIsoPFTau50_Trk30_eta2p1_MET80_v1',
    'HLT_LooseIsoPFTau50_Trk30_eta2p1_v1',
    'HLT_MET75_IsoTrk50_v1',
    'HLT_MET90_IsoTrk50_v1',
    'HLT_MonoCentralPFJet80_PFMETNoMu120_NoiseCleaned_PFMHTNoMu120_IDTight_v1',
    'HLT_MonoCentralPFJet80_PFMETNoMu90_NoiseCleaned_PFMHTNoMu90_IDTight_v1',
    'HLT_Mu10_CentralPFJet30_BTagCSV0p5PF_v1',
    'HLT_Mu12_Photon25_CaloIdL_L1ISO_v1',
    'HLT_Mu12_Photon25_CaloIdL_L1OR_v1',
    'HLT_Mu12_Photon25_CaloIdL_v1',
    'HLT_Mu14er_PFMET120_NoiseCleaned_v1',
    'HLT_Mu15_IsoVVVL_BTagCSV07_PFHT400_v1',
    'HLT_Mu15_IsoVVVL_PFHT400_PFMET70_v1',
    'HLT_Mu15_IsoVVVL_PFHT600_v1',
    'HLT_Mu15_PFHT300_v1',
    'HLT_Mu16_TkMu0_dEta18_Onia_v1',
    'HLT_Mu16_TkMu0_dEta18_Phi_v1',
    'HLT_Mu16_eta2p1_CaloMET30_v1',
    'HLT_Mu17_Mu8_DZ_v1',
    'HLT_Mu17_Mu8_SameSign_DPhi_v1',
    'HLT_Mu17_Mu8_SameSign_v1',
    'HLT_Mu17_Photon30_CaloIdL_L1ISO_v1',
    'HLT_Mu17_Photon35_CaloIdL_L1ISO_v1',
    'HLT_Mu17_TkMu8_DZ_v1',
    'HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v1',
    'HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v1',
    'HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_v1',
    'HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v1',
    'HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_v1',
    'HLT_Mu17_TrkIsoVVL_v1',
    'HLT_Mu20_v1',
    'HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v1',
    'HLT_Mu24_TrkIsoVVL_v1',
    'HLT_Mu24_eta2p1_v1',
    'HLT_Mu25_TkMu0_dEta18_Onia_v1',
    'HLT_Mu27_TkMu8_v1',
    'HLT_Mu27_v1',
    'HLT_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL_v1',
    'HLT_Mu30_Ele30_CaloIdL_GsfTrkIdVL_v1',
    'HLT_Mu30_TkMu11_v1',
    'HLT_Mu33NoFiltersNoVtxDisplaced_Photon33_CaloIdL_v1',
    'HLT_Mu34_TrkIsoVVL_v1',
    'HLT_Mu38NoFiltersNoVtx_Photon38_CaloIdL_v1',
    'HLT_Mu3er_PFHT140_PFMET125_NoiseCleaned_v1',
    'HLT_Mu40_TkMu11_v1',
    'HLT_Mu40_eta2p1_PFJet200_PFJet50_v1',
    'HLT_Mu42NoFiltersNoVtx_Photon42_CaloIdL_v1',
    'HLT_Mu45_eta2p1_v1',
    'HLT_Mu50_v1',
    'HLT_Mu6_PFHT200_PFMET100_NoiseCleaned_BTagCSV07_v1',
    'HLT_Mu6_PFHT200_PFMET125_NoiseCleaned_v1',
    'HLT_Mu7p5_L2Mu2_Jpsi_v1',
    'HLT_Mu7p5_L2Mu2_Upsilon_v1',
    'HLT_Mu7p5_Track2_Jpsi_v1',
    'HLT_Mu7p5_Track2_Upsilon_v1',
    'HLT_Mu7p5_Track3p5_Jpsi_v1',
    'HLT_Mu7p5_Track3p5_Upsilon_v1',
    'HLT_Mu7p5_Track7_Jpsi_v1',
    'HLT_Mu7p5_Track7_Upsilon_v1',
    'HLT_Mu8_DiEle12_CaloIdL_TrackIdL_v1',
    'HLT_Mu8_Ele8_CaloIdL_TrkIdVL_Mass8_PFHT300_v1',
    'HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v1',
    'HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_v1',
    'HLT_Mu8_TrkIsoVVL_v1',
    'HLT_PFHT200_DiPFJet90_PFAlphaT0p57_v1',
    'HLT_PFHT250_DiPFJet90_PFAlphaT0p55_v1',
    'HLT_PFHT300_DiPFJet90_PFAlphaT0p53_v1',
    'HLT_PFHT350_DiPFJet90_PFAlphaT0p52_v1',
    'HLT_PFHT350_PFMET120_NoiseCleaned_v1',
    'HLT_PFHT350_v1',
    'HLT_PFHT400_DiPFJet90_PFAlphaT0p51_v1',
    'HLT_PFHT550_4Jet_v1',
    'HLT_PFHT600_v1',
    'HLT_PFHT650_4Jet_v1',
    'HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v1',
    'HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v1',
    'HLT_PFHT650_v1',
    'HLT_PFHT750_4Jet_v1',
    'HLT_PFHT900_v1',
    'HLT_PFJet140_v1',
    'HLT_PFJet200_v1',
    'HLT_PFJet260_v1',
    'HLT_PFJet320_v1',
    'HLT_PFJet400_v1',
    'HLT_PFJet40_v1',
    'HLT_PFJet450_v1',
    'HLT_PFJet500_v1',
    'HLT_PFJet60_v1',
    'HLT_PFJet80_v1',
    'HLT_PFMET100_PFMHT100_IDLoose_v1',
    'HLT_PFMET110_PFMHT110_IDLoose_v1',
    'HLT_PFMET120_NoiseCleaned_BTagCSV07_v1',
    'HLT_PFMET120_NoiseCleaned_Mu5_v1',
    'HLT_PFMET120_PFMHT120_IDLoose_v1',
    'HLT_PFMET170_NoiseCleaned_v1',
    'HLT_PFMET90_PFMHT90_IDLoose_v1',
    'HLT_PFMETNoMu120_NoiseCleaned_PFMHTNoMu120_IDTight_v1',
    'HLT_PFMETNoMu90_NoiseCleaned_PFMHTNoMu90_IDTight_v1',
    'HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1',
    'HLT_Photon120_R9Id90_HE10_Iso40_EBOnly_VBF_v1',
    'HLT_Photon120_R9Id90_HE10_IsoM_v1',
    'HLT_Photon120_v1',
    'HLT_Photon135_PFMET100_NoiseCleaned_v1',
    'HLT_Photon165_HE10_v1',
    'HLT_Photon165_R9Id90_HE10_IsoM_v1',
    'HLT_Photon175_v1')+cms.vstring( 'HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1',
    'HLT_Photon22_R9Id90_HE10_Iso40_EBOnly_VBF_v1',
    'HLT_Photon22_R9Id90_HE10_IsoM_v1',
    'HLT_Photon22_v1',
    'HLT_Photon250_NoHE_v1',
    'HLT_Photon26_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon16_AND_HE10_R9Id65_Eta2_Mass60_v1',
    'HLT_Photon300_NoHE_v1',
    'HLT_Photon30_R9Id90_HE10_IsoM_v1',
    'HLT_Photon30_v1',
    'HLT_Photon36_R9Id85_OR_CaloId24b40e_Iso50T80L_Photon22_AND_HE10_R9Id65_Eta2_Mass15_v1',
    'HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1',
    'HLT_Photon36_R9Id90_HE10_Iso40_EBOnly_VBF_v1',
    'HLT_Photon36_R9Id90_HE10_IsoM_v1',
    'HLT_Photon36_v1',
    'HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1',
    'HLT_Photon50_R9Id90_HE10_Iso40_EBOnly_VBF_v1',
    'HLT_Photon50_R9Id90_HE10_IsoM_v1',
    'HLT_Photon50_v1',
    'HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1',
    'HLT_Photon75_R9Id90_HE10_Iso40_EBOnly_VBF_v1',
    'HLT_Photon75_R9Id90_HE10_IsoM_v1',
    'HLT_Photon75_v1',
    'HLT_Photon90_CaloIdL_PFHT500_v1',
    'HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_PFMET40_v1',
    'HLT_Photon90_R9Id90_HE10_Iso40_EBOnly_VBF_v1',
    'HLT_Photon90_R9Id90_HE10_IsoM_v1',
    'HLT_Photon90_v1',
    'HLT_Physics_v1',
    'HLT_QuadJet45_DoubleCSV0p5_v1',
    'HLT_QuadJet45_TripleCSV0p5_v1',
    'HLT_QuadMuon0_Dimuon0_Jpsi_v1',
    'HLT_QuadMuon0_Dimuon0_Upsilon_v1',
    'HLT_QuadPFJet_DoubleBTagCSV_VBF_Mqq200_v1',
    'HLT_QuadPFJet_DoubleBTagCSV_VBF_Mqq240_v1',
    'HLT_QuadPFJet_SingleBTagCSV_VBF_Mqq460_v1',
    'HLT_QuadPFJet_SingleBTagCSV_VBF_Mqq500_v1',
    'HLT_QuadPFJet_VBF_v1',
    'HLT_Random_v1',
    'HLT_Rsq0p36_v1',
    'HLT_RsqMR260_Rsq0p09_MR200_4jet_v1',
    'HLT_RsqMR260_Rsq0p09_MR200_v1',
    'HLT_RsqMR300_Rsq0p09_MR200_4jet_v1',
    'HLT_RsqMR300_Rsq0p09_MR200_v1',
    'HLT_TkMu20_v1',
    'HLT_TkMu24_eta2p1_v1',
    'HLT_TkMu27_v1',
    'HLT_TripleMu_12_10_5_v1',
    'HLT_VBF_DisplacedJet40_DisplacedTrack_v1',
    'HLT_VBF_DisplacedJet40_Hadronic_v1',
    'HLT_VBF_DisplacedJet40_TightID_DisplacedTrack_v1',
    'HLT_VBF_DisplacedJet40_TightID_Hadronic_v1',
    'HLT_ZeroBias_v1') ),
  RPCMonitor = cms.vstring( 'AlCa_RPCMuonNoHits_v1',
    'AlCa_RPCMuonNoTriggers_v1',
    'AlCa_RPCMuonNormalisation_v1' ),
  Templates = cms.vstring( 'HLT_ReducedIterativeTracking_v1' ),
  TestEnablesEcalHcalDT = cms.vstring( 'HLT_EcalCalibration_v1' )
)

process.magfield = cms.ESSource( "XMLIdealGeometryESSource",
    geomXMLFiles = cms.vstring( 'Geometry/CMSCommonData/data/normal/cmsextent.xml',
      'Geometry/CMSCommonData/data/cms.xml',
      'Geometry/CMSCommonData/data/cmsMagneticField.xml',
      'MagneticField/GeomBuilder/data/MagneticFieldVolumes_1103l.xml',
      'Geometry/CMSCommonData/data/materials.xml' ),
    rootNodeName = cms.string( "cmsMagneticField:MAGF" )
)
process.hltESSHcalSeverityLevel = cms.ESSource( "EmptyESSource",
    iovIsRunNotTime = cms.bool( True ),
    recordName = cms.string( "HcalSeverityLevelComputerRcd" ),
    firstValid = cms.vuint32( 1 )
)
process.hltESSEcalSeverityLevel = cms.ESSource( "EmptyESSource",
    iovIsRunNotTime = cms.bool( True ),
    recordName = cms.string( "EcalSeverityLevelAlgoRcd" ),
    firstValid = cms.vuint32( 1 )
)
process.hltESSBTagRecord = cms.ESSource( "EmptyESSource",
    iovIsRunNotTime = cms.bool( True ),
    recordName = cms.string( "JetTagComputerRecord" ),
    firstValid = cms.vuint32( 1 )
)
process.es_hardcode = cms.ESSource( "HcalHardcodeCalibrations",
    fromDDD = cms.untracked.bool( False ),
    toGet = cms.untracked.vstring( 'GainWidths' )
)
process.eegeom = cms.ESSource( "EmptyESSource",
    iovIsRunNotTime = cms.bool( True ),
    recordName = cms.string( "EcalMappingRcd" ),
    firstValid = cms.vuint32( 1 )
)
process.HepPDTESSource = cms.ESSource( "HepPDTESSource",
    pdtFileName = cms.FileInPath( "SimGeneral/HepPDTESSource/data/pythiaparticle.tbl" )
)
process.GlobalTag = cms.ESSource( "PoolDBESSource",
    globaltag = cms.string( "GR_H_V39" ),
    RefreshEachRun = cms.untracked.bool( True ),
    RefreshOpenIOVs = cms.untracked.bool( False ),
    toGet = cms.VPSet( 
    ),
    DBParameters = cms.PSet( 
      authenticationPath = cms.untracked.string( "." ),
      connectionRetrialTimeOut = cms.untracked.int32( 60 ),
      idleConnectionCleanupPeriod = cms.untracked.int32( 10 ),
      messageLevel = cms.untracked.int32( 0 ),
      enablePoolAutomaticCleanUp = cms.untracked.bool( False ),
      enableConnectionSharing = cms.untracked.bool( True ),
      enableReadOnlySessionOnUpdateConnection = cms.untracked.bool( False ),
      connectionTimeOut = cms.untracked.int32( 0 ),
      connectionRetrialPeriod = cms.untracked.int32( 10 )
    ),
    RefreshAlways = cms.untracked.bool( False ),
    connect = cms.string( "frontier://(proxyurl=http://localhost:3128)(serverurl=http://localhost:8000/FrontierOnProd)(serverurl=http://localhost:8000/FrontierOnProd)(retrieve-ziplevel=0)/CMS_CONDITIONS" ),
    ReconnectEachRun = cms.untracked.bool( True ),
    BlobStreamerName = cms.untracked.string( "TBufferBlobStreamingService" ),
    DumpStat = cms.untracked.bool( False )
)
process.CSCINdexerESSource = cms.ESSource( "EmptyESSource",
    iovIsRunNotTime = cms.bool( True ),
    recordName = cms.string( "CSCIndexerRecord" ),
    firstValid = cms.vuint32( 1 )
)
process.CSCChannelMapperESSource = cms.ESSource( "EmptyESSource",
    iovIsRunNotTime = cms.bool( True ),
    recordName = cms.string( "CSCChannelMapperRecord" ),
    firstValid = cms.vuint32( 1 )
)

process.hltESPDisplacedDijethltPromptTrackCountingESProducerLong = cms.ESProducer( "PromptTrackCountingESProducer",
  maxImpactParameterSig = cms.double( 999999.0 ),
  deltaR = cms.double( -1.0 ),
  minimumImpactParameter = cms.double( -1.0 ),
  maximumDecayLength = cms.double( 999999.0 ),
  impactParameterType = cms.int32( 1 ),
  trackQualityClass = cms.string( "any" ),
  deltaRmin = cms.double( 0.0 ),
  maxImpactParameter = cms.double( 0.2 ),
  useSignedImpactParameterSig = cms.bool( True ),
  maximumDistanceToJetAxis = cms.double( 999999.0 ),
  nthTrack = cms.int32( -1 )
)
process.hltESPDisplacedDijethltPromptTrackCountingESProducer = cms.ESProducer( "PromptTrackCountingESProducer",
  maxImpactParameterSig = cms.double( 999999.0 ),
  deltaR = cms.double( -1.0 ),
  minimumImpactParameter = cms.double( -1.0 ),
  maximumDecayLength = cms.double( 999999.0 ),
  impactParameterType = cms.int32( 1 ),
  trackQualityClass = cms.string( "any" ),
  deltaRmin = cms.double( 0.0 ),
  maxImpactParameter = cms.double( 0.1 ),
  useSignedImpactParameterSig = cms.bool( True ),
  maximumDistanceToJetAxis = cms.double( 999999.0 ),
  nthTrack = cms.int32( -1 )
)
process.hltESPDisplacedDijethltTrackCounting2D1st = cms.ESProducer( "TrackCountingESProducer",
  b_pT = cms.double( 0.3684 ),
  deltaR = cms.double( -1.0 ),
  minimumImpactParameter = cms.double( 0.05 ),
  a_dR = cms.double( -0.001053 ),
  min_pT = cms.double( 120.0 ),
  maximumDistanceToJetAxis = cms.double( 9999999.0 ),
  max_pT = cms.double( 500.0 ),
  impactParameterType = cms.int32( 1 ),
  trackQualityClass = cms.string( "any" ),
  useVariableJTA = cms.bool( False ),
  min_pT_dRcut = cms.double( 0.5 ),
  max_pT_trackPTcut = cms.double( 3.0 ),
  max_pT_dRcut = cms.double( 0.1 ),
  b_dR = cms.double( 0.6263 ),
  a_pT = cms.double( 0.005263 ),
  maximumDecayLength = cms.double( 999999.0 ),
  nthTrack = cms.int32( 1 ),
  useSignedImpactParameterSig = cms.bool( False )
)
process.hltESPDisplacedDijethltTrackCounting2D2ndLong = cms.ESProducer( "TrackCountingESProducer",
  b_pT = cms.double( 0.3684 ),
  deltaR = cms.double( -1.0 ),
  minimumImpactParameter = cms.double( 0.2 ),
  a_dR = cms.double( -0.001053 ),
  min_pT = cms.double( 120.0 ),
  maximumDistanceToJetAxis = cms.double( 9999999.0 ),
  max_pT = cms.double( 500.0 ),
  impactParameterType = cms.int32( 1 ),
  trackQualityClass = cms.string( "any" ),
  useVariableJTA = cms.bool( False ),
  min_pT_dRcut = cms.double( 0.5 ),
  max_pT_trackPTcut = cms.double( 3.0 ),
  max_pT_dRcut = cms.double( 0.1 ),
  b_dR = cms.double( 0.6263 ),
  a_pT = cms.double( 0.005263 ),
  maximumDecayLength = cms.double( 999999.0 ),
  nthTrack = cms.int32( 2 ),
  useSignedImpactParameterSig = cms.bool( True )
)
process.hltESPAK8CaloCorrection = cms.ESProducer( "JetCorrectionESChain",
  correctors = cms.vstring( 'hltESPAK8CaloFastJetCorrectionESProducer',
    'hltESPAK8CaloRelativeCorrectionESProducer',
    'hltESPAK8CaloAbsoluteCorrectionESProducer' ),
  appendToDataLabel = cms.string( "" )
)
process.hltESPAK8CaloFastJetCorrectionESProducer = cms.ESProducer( "L1FastjetCorrectionESProducer",
  appendToDataLabel = cms.string( "" ),
  srcRho = cms.InputTag( "hltFixedGridRhoFastjetAllCalo" ),
  algorithm = cms.string( "AK8CaloHLT" ),
  level = cms.string( "L1FastJet" )
)
process.hltESPAK8CaloRelativeCorrectionESProducer = cms.ESProducer( "LXXXCorrectionESProducer",
  appendToDataLabel = cms.string( "" ),
  algorithm = cms.string( "AK8CaloHLT" ),
  level = cms.string( "L2Relative" )
)
process.hltESPAK8CaloAbsoluteCorrectionESProducer = cms.ESProducer( "LXXXCorrectionESProducer",
  appendToDataLabel = cms.string( "" ),
  algorithm = cms.string( "AK8CaloHLT" ),
  level = cms.string( "L3Absolute" )
)
process.hltESPAK8PFCorrection = cms.ESProducer( "JetCorrectionESChain",
  correctors = cms.vstring( 'hltESPAK8PFFastJetCorrectionESProducer',
    'hltESPAK8PFRelativeCorrectionESProducer',
    'hltESPAK8PFAbsoluteCorrectionESProducer' ),
  appendToDataLabel = cms.string( "" )
)
process.hltESPAK8PFFastJetCorrectionESProducer = cms.ESProducer( "L1FastjetCorrectionESProducer",
  appendToDataLabel = cms.string( "" ),
  srcRho = cms.InputTag( "hltFixedGridRhoFastjetAll" ),
  algorithm = cms.string( "AK8PFHLT" ),
  level = cms.string( "L1FastJet" )
)
process.hltESPAK8PFRelativeCorrectionESProducer = cms.ESProducer( "LXXXCorrectionESProducer",
  appendToDataLabel = cms.string( "" ),
  algorithm = cms.string( "AK8PFHLT" ),
  level = cms.string( "L2Relative" )
)
process.hltESPAK8PFAbsoluteCorrectionESProducer = cms.ESProducer( "LXXXCorrectionESProducer",
  appendToDataLabel = cms.string( "" ),
  algorithm = cms.string( "AK8PFHLT" ),
  level = cms.string( "L3Absolute" )
)
process.hltDisplacedDijethltESPTrackCounting2D1st = cms.ESProducer( "TrackCountingESProducer",
  b_pT = cms.double( 0.3684 ),
  deltaR = cms.double( -1.0 ),
  minimumImpactParameter = cms.double( 0.05 ),
  a_dR = cms.double( -0.001053 ),
  min_pT = cms.double( 120.0 ),
  maximumDistanceToJetAxis = cms.double( 9999999.0 ),
  max_pT = cms.double( 500.0 ),
  impactParameterType = cms.int32( 1 ),
  trackQualityClass = cms.string( "any" ),
  useVariableJTA = cms.bool( False ),
  min_pT_dRcut = cms.double( 0.5 ),
  max_pT_trackPTcut = cms.double( 3.0 ),
  max_pT_dRcut = cms.double( 0.1 ),
  b_dR = cms.double( 0.6263 ),
  a_pT = cms.double( 0.005263 ),
  maximumDecayLength = cms.double( 999999.0 ),
  nthTrack = cms.int32( 1 ),
  useSignedImpactParameterSig = cms.bool( False )
)
process.hltDisplacedDijethltESPPromptTrackCountingESProducer = cms.ESProducer( "PromptTrackCountingESProducer",
  maxImpactParameterSig = cms.double( 999999.0 ),
  deltaR = cms.double( -1.0 ),
  minimumImpactParameter = cms.double( -1.0 ),
  maximumDecayLength = cms.double( 999999.0 ),
  impactParameterType = cms.int32( 1 ),
  trackQualityClass = cms.string( "any" ),
  deltaRmin = cms.double( 0.0 ),
  maxImpactParameter = cms.double( 0.1 ),
  useSignedImpactParameterSig = cms.bool( True ),
  maximumDistanceToJetAxis = cms.double( 999999.0 ),
  nthTrack = cms.int32( -1 )
)
process.hltESPAK4CaloCorrection = cms.ESProducer( "JetCorrectionESChain",
  correctors = cms.vstring( 'hltESPAK4CaloFastJetCorrectionESProducer',
    'hltESPAK4CaloRelativeCorrectionESProducer',
    'hltESPAK4CaloAbsoluteCorrectionESProducer' ),
  appendToDataLabel = cms.string( "" )
)
process.hltESPAK4PFCorrection = cms.ESProducer( "JetCorrectionESChain",
  correctors = cms.vstring( 'hltESPAK4PFFastJetCorrectionESProducer',
    'hltESPAK4PFRelativeCorrectionESProducer',
    'hltESPAK4PFAbsoluteCorrectionESProducer' ),
  appendToDataLabel = cms.string( "" )
)
process.hltESPAK4CaloFastJetCorrectionESProducer = cms.ESProducer( "L1FastjetCorrectionESProducer",
  appendToDataLabel = cms.string( "" ),
  srcRho = cms.InputTag( "hltFixedGridRhoFastjetAllCalo" ),
  algorithm = cms.string( "AK4CaloHLT" ),
  level = cms.string( "L1FastJet" )
)
process.hltESPAK4PFFastJetCorrectionESProducer = cms.ESProducer( "L1FastjetCorrectionESProducer",
  appendToDataLabel = cms.string( "" ),
  srcRho = cms.InputTag( "hltFixedGridRhoFastjetAll" ),
  algorithm = cms.string( "AK4PFHLT" ),
  level = cms.string( "L1FastJet" )
)
process.hltESPAK4PFRelativeCorrectionESProducer = cms.ESProducer( "LXXXCorrectionESProducer",
  appendToDataLabel = cms.string( "" ),
  algorithm = cms.string( "AK4PFHLT" ),
  level = cms.string( "L2Relative" )
)
process.hltESPAK4CaloRelativeCorrectionESProducer = cms.ESProducer( "LXXXCorrectionESProducer",
  appendToDataLabel = cms.string( "" ),
  algorithm = cms.string( "AK4CaloHLT" ),
  level = cms.string( "L2Relative" )
)
process.hltESPAK4CaloAbsoluteCorrectionESProducer = cms.ESProducer( "LXXXCorrectionESProducer",
  appendToDataLabel = cms.string( "" ),
  algorithm = cms.string( "AK4CaloHLT" ),
  level = cms.string( "L3Absolute" )
)
process.hltESPAK4PFAbsoluteCorrectionESProducer = cms.ESProducer( "LXXXCorrectionESProducer",
  appendToDataLabel = cms.string( "" ),
  algorithm = cms.string( "AK4PFHLT" ),
  level = cms.string( "L3Absolute" )
)
process.MaterialPropagatorParabolicMF = cms.ESProducer( "PropagatorWithMaterialESProducer",
  SimpleMagneticField = cms.string( "ParabolicMf" ),
  PropagationDirection = cms.string( "alongMomentum" ),
  ComponentName = cms.string( "PropagatorWithMaterialParabolicMf" ),
  Mass = cms.double( 0.105 ),
  ptMin = cms.double( -1.0 ),
  MaxDPhi = cms.double( 1.6 ),
  useRungeKutta = cms.bool( False )
)
process.OppositeMaterialPropagatorParabolicMF = cms.ESProducer( "PropagatorWithMaterialESProducer",
  SimpleMagneticField = cms.string( "ParabolicMf" ),
  PropagationDirection = cms.string( "oppositeToMomentum" ),
  ComponentName = cms.string( "PropagatorWithMaterialParabolicMfOpposite" ),
  Mass = cms.double( 0.105 ),
  ptMin = cms.double( -1.0 ),
  MaxDPhi = cms.double( 1.6 ),
  useRungeKutta = cms.bool( False )
)
process.ParabolicParametrizedMagneticFieldProducer = cms.ESProducer( "ParametrizedMagneticFieldProducer",
  version = cms.string( "Parabolic" ),
  parameters = cms.PSet(  BValue = cms.string( "" ) ),
  label = cms.untracked.string( "ParabolicMf" )
)
process.hltESPChi2MeasurementEstimator9 = cms.ESProducer( "Chi2MeasurementEstimatorESProducer",
  MaxChi2 = cms.double( 9.0 ),
  nSigma = cms.double( 3.0 ),
  ComponentName = cms.string( "hltESPChi2MeasurementEstimator9" )
)
process.hltESPChi2MeasurementEstimator16 = cms.ESProducer( "Chi2MeasurementEstimatorESProducer",
  MaxChi2 = cms.double( 16.0 ),
  nSigma = cms.double( 3.0 ),
  ComponentName = cms.string( "hltESPChi2MeasurementEstimator16" )
)
process.hltESPChi2MeasurementEstimator30 = cms.ESProducer( "Chi2MeasurementEstimatorESProducer",
  MaxChi2 = cms.double( 30.0 ),
  nSigma = cms.double( 3.0 ),
  ComponentName = cms.string( "hltESPChi2MeasurementEstimator30" )
)
process.hltESPChi2ChargeMeasurementEstimator30 = cms.ESProducer( "Chi2ChargeMeasurementEstimatorESProducer",
  minGoodStripCharge = cms.double( 1724.0 ),
  ComponentName = cms.string( "hltESPChi2ChargeMeasurementEstimator30" ),
  pTChargeCutThreshold = cms.double( -1.0 ),
  nSigma = cms.double( 3.0 ),
  MaxChi2 = cms.double( 30.0 )
)
process.AnyDirectionAnalyticalPropagator = cms.ESProducer( "AnalyticalPropagatorESProducer",
  MaxDPhi = cms.double( 1.6 ),
  ComponentName = cms.string( "AnyDirectionAnalyticalPropagator" ),
  PropagationDirection = cms.string( "anyDirection" )
)
process.AutoMagneticFieldESProducer = cms.ESProducer( "AutoMagneticFieldESProducer",
  label = cms.untracked.string( "" ),
  nominalCurrents = cms.untracked.vint32( -1, 0, 9558, 14416, 16819, 18268, 19262 ),
  valueOverride = cms.int32( -1 ),
  mapLabels = cms.untracked.vstring( '090322_3_8t',
    '0t',
    '071212_2t',
    '071212_3t',
    '071212_3_5t',
    '090322_3_8t',
    '071212_4t' )
)
process.CSCChannelMapperESProducer = cms.ESProducer( "CSCChannelMapperESProducer",
  AlgoName = cms.string( "CSCChannelMapperPostls1" )
)
process.CSCGeometryESModule = cms.ESProducer( "CSCGeometryESModule",
  useRealWireGeometry = cms.bool( True ),
  appendToDataLabel = cms.string( "" ),
  alignmentsLabel = cms.string( "" ),
  useGangedStripsInME1a = cms.bool( False ),
  debugV = cms.untracked.bool( False ),
  useOnlyWiresInME1a = cms.bool( False ),
  useDDD = cms.bool( False ),
  useCentreTIOffsets = cms.bool( False ),
  applyAlignment = cms.bool( True )
)
process.CSCIndexerESProducer = cms.ESProducer( "CSCIndexerESProducer",
  AlgoName = cms.string( "CSCIndexerPostls1" )
)
process.CaloGeometryBuilder = cms.ESProducer( "CaloGeometryBuilder",
  SelectedCalos = cms.vstring( 'HCAL',
    'ZDC',
    'EcalBarrel',
    'EcalEndcap',
    'EcalPreshower',
    'TOWER' )
)
process.CaloTopologyBuilder = cms.ESProducer( "CaloTopologyBuilder" )
process.CaloTowerConstituentsMapBuilder = cms.ESProducer( "CaloTowerConstituentsMapBuilder",
  appendToDataLabel = cms.string( "" ),
  MapFile = cms.untracked.string( "Geometry/CaloTopology/data/CaloTowerEEGeometric.map.gz" )
)
process.CaloTowerGeometryFromDBEP = cms.ESProducer( "CaloTowerGeometryFromDBEP",
  applyAlignment = cms.bool( False ),
  hcalTopologyConstants = cms.PSet( 
    maxDepthHE = cms.int32( 3 ),
    maxDepthHB = cms.int32( 2 ),
    mode = cms.string( "HcalTopologyMode::LHC" )
  )
)
process.CastorDbProducer = cms.ESProducer( "CastorDbProducer",
  appendToDataLabel = cms.string( "" )
)
process.ClusterShapeHitFilterESProducer = cms.ESProducer( "ClusterShapeHitFilterESProducer",
  ComponentName = cms.string( "ClusterShapeHitFilter" ),
  PixelShapeFile = cms.string( "RecoPixelVertexing/PixelLowPtUtilities/data/pixelShape.par" )
)
process.DTGeometryESModule = cms.ESProducer( "DTGeometryESModule",
  appendToDataLabel = cms.string( "" ),
  fromDDD = cms.bool( False ),
  applyAlignment = cms.bool( True ),
  alignmentsLabel = cms.string( "" )
)
process.EcalBarrelGeometryFromDBEP = cms.ESProducer( "EcalBarrelGeometryFromDBEP",
  applyAlignment = cms.bool( True )
)
process.EcalElectronicsMappingBuilder = cms.ESProducer( "EcalElectronicsMappingBuilder" )
process.EcalEndcapGeometryFromDBEP = cms.ESProducer( "EcalEndcapGeometryFromDBEP",
  applyAlignment = cms.bool( True )
)
process.EcalLaserCorrectionService = cms.ESProducer( "EcalLaserCorrectionService" )
process.EcalPreshowerGeometryFromDBEP = cms.ESProducer( "EcalPreshowerGeometryFromDBEP",
  applyAlignment = cms.bool( True )
)
process.hltESPChi2ChargeMeasurementEstimator9 = cms.ESProducer( "Chi2ChargeMeasurementEstimatorESProducer",
  minGoodStripCharge = cms.double( 1724.0 ),
  ComponentName = cms.string( "hltESPChi2ChargeMeasurementEstimator9" ),
  pTChargeCutThreshold = cms.double( 15.0 ),
  nSigma = cms.double( 3.0 ),
  MaxChi2 = cms.double( 9.0 )
)
process.hltESPChi2ChargeMeasurementEstimator16 = cms.ESProducer( "Chi2ChargeMeasurementEstimatorESProducer",
  minGoodStripCharge = cms.double( 1724.0 ),
  ComponentName = cms.string( "hltESPChi2ChargeMeasurementEstimator16" ),
  pTChargeCutThreshold = cms.double( -1.0 ),
  nSigma = cms.double( 3.0 ),
  MaxChi2 = cms.double( 16.0 )
)
process.HcalGeometryFromDBEP = cms.ESProducer( "HcalGeometryFromDBEP",
  applyAlignment = cms.bool( False ),
  hcalTopologyConstants = cms.PSet( 
    maxDepthHE = cms.int32( 3 ),
    maxDepthHB = cms.int32( 2 ),
    mode = cms.string( "HcalTopologyMode::LHC" )
  )
)
process.HcalTopologyIdealEP = cms.ESProducer( "HcalTopologyIdealEP",
  Exclude = cms.untracked.string( "" ),
  appendToDataLabel = cms.string( "" ),
  hcalTopologyConstants = cms.PSet( 
    maxDepthHE = cms.int32( 3 ),
    maxDepthHB = cms.int32( 2 ),
    mode = cms.string( "HcalTopologyMode::LHC" )
  )
)
process.MaterialPropagator = cms.ESProducer( "PropagatorWithMaterialESProducer",
  SimpleMagneticField = cms.string( "" ),
  PropagationDirection = cms.string( "alongMomentum" ),
  ComponentName = cms.string( "PropagatorWithMaterial" ),
  Mass = cms.double( 0.105 ),
  ptMin = cms.double( -1.0 ),
  MaxDPhi = cms.double( 1.6 ),
  useRungeKutta = cms.bool( False )
)
process.OppositeMaterialPropagator = cms.ESProducer( "PropagatorWithMaterialESProducer",
  SimpleMagneticField = cms.string( "" ),
  PropagationDirection = cms.string( "oppositeToMomentum" ),
  ComponentName = cms.string( "PropagatorWithMaterialOpposite" ),
  Mass = cms.double( 0.105 ),
  ptMin = cms.double( -1.0 ),
  MaxDPhi = cms.double( 1.6 ),
  useRungeKutta = cms.bool( False )
)
process.RPCGeometryESModule = cms.ESProducer( "RPCGeometryESModule",
  useDDD = cms.untracked.bool( False ),
  compatibiltyWith11 = cms.untracked.bool( True )
)
process.SiStripGainESProducer = cms.ESProducer( "SiStripGainESProducer",
  printDebug = cms.untracked.bool( False ),
  appendToDataLabel = cms.string( "" ),
  APVGain = cms.VPSet( 
    cms.PSet(  Record = cms.string( "SiStripApvGainRcd" ),
      NormalizationFactor = cms.untracked.double( 1.0 ),
      Label = cms.untracked.string( "" )
    ),
    cms.PSet(  Record = cms.string( "SiStripApvGain2Rcd" ),
      NormalizationFactor = cms.untracked.double( 1.0 ),
      Label = cms.untracked.string( "" )
    )
  ),
  AutomaticNormalization = cms.bool( False )
)
process.SiStripQualityESProducer = cms.ESProducer( "SiStripQualityESProducer",
  appendToDataLabel = cms.string( "" ),
  PrintDebugOutput = cms.bool( False ),
  ThresholdForReducedGranularity = cms.double( 0.3 ),
  UseEmptyRunInfo = cms.bool( False ),
  ReduceGranularity = cms.bool( False ),
  ListOfRecordToMerge = cms.VPSet( 
    cms.PSet(  record = cms.string( "SiStripDetVOffRcd" ),
      tag = cms.string( "" )
    ),
    cms.PSet(  record = cms.string( "SiStripDetCablingRcd" ),
      tag = cms.string( "" )
    ),
    cms.PSet(  record = cms.string( "SiStripBadChannelRcd" ),
      tag = cms.string( "" )
    ),
    cms.PSet(  record = cms.string( "SiStripBadFiberRcd" ),
      tag = cms.string( "" )
    ),
    cms.PSet(  record = cms.string( "SiStripBadModuleRcd" ),
      tag = cms.string( "" )
    )
  )
)
process.SiStripRecHitMatcherESProducer = cms.ESProducer( "SiStripRecHitMatcherESProducer",
  PreFilter = cms.bool( False ),
  ComponentName = cms.string( "StandardMatcher" ),
  NSigmaInside = cms.double( 3.0 )
)
process.SlaveField0 = cms.ESProducer( "UniformMagneticFieldESProducer",
  ZFieldInTesla = cms.double( 0.0 ),
  label = cms.untracked.string( "slave_0" )
)
process.SlaveField20 = cms.ESProducer( "ParametrizedMagneticFieldProducer",
  version = cms.string( "OAE_1103l_071212" ),
  parameters = cms.PSet(  BValue = cms.string( "2_0T" ) ),
  label = cms.untracked.string( "slave_20" )
)
process.SlaveField30 = cms.ESProducer( "ParametrizedMagneticFieldProducer",
  version = cms.string( "OAE_1103l_071212" ),
  parameters = cms.PSet(  BValue = cms.string( "3_0T" ) ),
  label = cms.untracked.string( "slave_30" )
)
process.SlaveField35 = cms.ESProducer( "ParametrizedMagneticFieldProducer",
  version = cms.string( "OAE_1103l_071212" ),
  parameters = cms.PSet(  BValue = cms.string( "3_5T" ) ),
  label = cms.untracked.string( "slave_35" )
)
process.SlaveField38 = cms.ESProducer( "ParametrizedMagneticFieldProducer",
  version = cms.string( "OAE_1103l_071212" ),
  parameters = cms.PSet(  BValue = cms.string( "3_8T" ) ),
  label = cms.untracked.string( "slave_38" )
)
process.SlaveField40 = cms.ESProducer( "ParametrizedMagneticFieldProducer",
  version = cms.string( "OAE_1103l_071212" ),
  parameters = cms.PSet(  BValue = cms.string( "4_0T" ) ),
  label = cms.untracked.string( "slave_40" )
)
process.SteppingHelixPropagatorAny = cms.ESProducer( "SteppingHelixPropagatorESProducer",
  NoErrorPropagation = cms.bool( False ),
  endcapShiftInZPos = cms.double( 0.0 ),
  PropagationDirection = cms.string( "anyDirection" ),
  useTuningForL2Speed = cms.bool( False ),
  useIsYokeFlag = cms.bool( True ),
  endcapShiftInZNeg = cms.double( 0.0 ),
  SetVBFPointer = cms.bool( False ),
  AssumeNoMaterial = cms.bool( False ),
  returnTangentPlane = cms.bool( True ),
  useInTeslaFromMagField = cms.bool( False ),
  VBFName = cms.string( "VolumeBasedMagneticField" ),
  useEndcapShiftsInZ = cms.bool( False ),
  sendLogWarning = cms.bool( False ),
  useMatVolumes = cms.bool( True ),
  debug = cms.bool( False ),
  ApplyRadX0Correction = cms.bool( True ),
  useMagVolumes = cms.bool( True ),
  ComponentName = cms.string( "SteppingHelixPropagatorAny" )
)
process.TrackerDigiGeometryESModule = cms.ESProducer( "TrackerDigiGeometryESModule",
  appendToDataLabel = cms.string( "" ),
  fromDDD = cms.bool( False ),
  trackerGeometryConstants = cms.PSet( 
    ROCS_X = cms.int32( 0 ),
    ROCS_Y = cms.int32( 0 ),
    upgradeGeometry = cms.bool( False ),
    BIG_PIX_PER_ROC_Y = cms.int32( 2 ),
    BIG_PIX_PER_ROC_X = cms.int32( 1 ),
    ROWS_PER_ROC = cms.int32( 80 ),
    COLS_PER_ROC = cms.int32( 52 )
  ),
  applyAlignment = cms.bool( True ),
  alignmentsLabel = cms.string( "" )
)
process.TrackerGeometricDetESModule = cms.ESProducer( "TrackerGeometricDetESModule",
  appendToDataLabel = cms.string( "" ),
  fromDDD = cms.bool( False )
)
process.TransientTrackBuilderESProducer = cms.ESProducer( "TransientTrackBuilderESProducer",
  ComponentName = cms.string( "TransientTrackBuilder" )
)
process.VBF0 = cms.ESProducer( "VolumeBasedMagneticFieldESProducer",
  scalingVolumes = cms.vint32(  ),
  useParametrizedTrackerField = cms.bool( True ),
  scalingFactors = cms.vdouble(  ),
  label = cms.untracked.string( "0t" ),
  version = cms.string( "grid_1103l_071212_2t" ),
  debugBuilder = cms.untracked.bool( False ),
  paramLabel = cms.string( "slave_0" ),
  geometryVersion = cms.int32( 71212 ),
  gridFiles = cms.VPSet( 
    cms.PSet(  path = cms.string( "grid.[v].bin" ),
      master = cms.int32( 1 ),
      sectors = cms.string( "0" ),
      volumes = cms.string( "1-312" )
    )
  ),
  cacheLastVolume = cms.untracked.bool( True )
)
process.VBF20 = cms.ESProducer( "VolumeBasedMagneticFieldESProducer",
  scalingVolumes = cms.vint32(  ),
  useParametrizedTrackerField = cms.bool( True ),
  scalingFactors = cms.vdouble(  ),
  label = cms.untracked.string( "071212_2t" ),
  version = cms.string( "grid_1103l_071212_2t" ),
  debugBuilder = cms.untracked.bool( False ),
  paramLabel = cms.string( "slave_20" ),
  geometryVersion = cms.int32( 71212 ),
  gridFiles = cms.VPSet( 
    cms.PSet(  path = cms.string( "grid.[v].bin" ),
      master = cms.int32( 1 ),
      sectors = cms.string( "0" ),
      volumes = cms.string( "1-312" )
    )
  ),
  cacheLastVolume = cms.untracked.bool( True )
)
process.VBF30 = cms.ESProducer( "VolumeBasedMagneticFieldESProducer",
  scalingVolumes = cms.vint32(  ),
  useParametrizedTrackerField = cms.bool( True ),
  scalingFactors = cms.vdouble(  ),
  label = cms.untracked.string( "071212_3t" ),
  version = cms.string( "grid_1103l_071212_3t" ),
  debugBuilder = cms.untracked.bool( False ),
  paramLabel = cms.string( "slave_30" ),
  geometryVersion = cms.int32( 71212 ),
  gridFiles = cms.VPSet( 
    cms.PSet(  path = cms.string( "grid.[v].bin" ),
      master = cms.int32( 1 ),
      sectors = cms.string( "0" ),
      volumes = cms.string( "1-312" )
    )
  ),
  cacheLastVolume = cms.untracked.bool( True )
)
process.VBF35 = cms.ESProducer( "VolumeBasedMagneticFieldESProducer",
  scalingVolumes = cms.vint32(  ),
  useParametrizedTrackerField = cms.bool( True ),
  scalingFactors = cms.vdouble(  ),
  label = cms.untracked.string( "071212_3_5t" ),
  version = cms.string( "grid_1103l_071212_3_5t" ),
  debugBuilder = cms.untracked.bool( False ),
  paramLabel = cms.string( "slave_35" ),
  geometryVersion = cms.int32( 71212 ),
  gridFiles = cms.VPSet( 
    cms.PSet(  path = cms.string( "grid.[v].bin" ),
      master = cms.int32( 1 ),
      sectors = cms.string( "0" ),
      volumes = cms.string( "1-312" )
    )
  ),
  cacheLastVolume = cms.untracked.bool( True )
)
process.VBF38 = cms.ESProducer( "VolumeBasedMagneticFieldESProducer",
  scalingVolumes = cms.vint32( 14100, 14200, 17600, 17800, 17900, 18100, 18300, 18400, 18600, 23100, 23300, 23400, 23600, 23800, 23900, 24100, 28600, 28800, 28900, 29100, 29300, 29400, 29600, 28609, 28809, 28909, 29109, 29309, 29409, 29609, 28610, 28810, 28910, 29110, 29310, 29410, 29610, 28611, 28811, 28911, 29111, 29311, 29411, 29611 ),
  useParametrizedTrackerField = cms.bool( True ),
  scalingFactors = cms.vdouble( 1.0, 1.0, 0.994, 1.004, 1.004, 1.005, 1.004, 1.004, 0.994, 0.965, 0.958, 0.958, 0.953, 0.958, 0.958, 0.965, 0.918, 0.924, 0.924, 0.906, 0.924, 0.924, 0.918, 0.991, 0.998, 0.998, 0.978, 0.998, 0.998, 0.991, 0.991, 0.998, 0.998, 0.978, 0.998, 0.998, 0.991, 0.991, 0.998, 0.998, 0.978, 0.998, 0.998, 0.991 ),
  label = cms.untracked.string( "090322_3_8t" ),
  version = cms.string( "grid_1103l_090322_3_8t" ),
  debugBuilder = cms.untracked.bool( False ),
  paramLabel = cms.string( "slave_38" ),
  geometryVersion = cms.int32( 71212 ),
  gridFiles = cms.VPSet( 
    cms.PSet(  path = cms.string( "grid.[v].bin" ),
      master = cms.int32( 1 ),
      sectors = cms.string( "0" ),
      volumes = cms.string( "1-312" )
    ),
    cms.PSet(  path = cms.string( "S3/grid.[v].bin" ),
      master = cms.int32( 3 ),
      sectors = cms.string( "3" ),
      volumes = cms.string( "176-186,231-241,286-296" )
    ),
    cms.PSet(  path = cms.string( "S4/grid.[v].bin" ),
      master = cms.int32( 4 ),
      sectors = cms.string( "4" ),
      volumes = cms.string( "176-186,231-241,286-296" )
    ),
    cms.PSet(  path = cms.string( "S9/grid.[v].bin" ),
      master = cms.int32( 9 ),
      sectors = cms.string( "9" ),
      volumes = cms.string( "14,15,20,21,24-27,32,33,40,41,48,49,56,57,62,63,70,71,286-296" )
    ),
    cms.PSet(  path = cms.string( "S10/grid.[v].bin" ),
      master = cms.int32( 10 ),
      sectors = cms.string( "10" ),
      volumes = cms.string( "14,15,20,21,24-27,32,33,40,41,48,49,56,57,62,63,70,71,286-296" )
    ),
    cms.PSet(  path = cms.string( "S11/grid.[v].bin" ),
      master = cms.int32( 11 ),
      sectors = cms.string( "11" ),
      volumes = cms.string( "14,15,20,21,24-27,32,33,40,41,48,49,56,57,62,63,70,71,286-296" )
    )
  ),
  cacheLastVolume = cms.untracked.bool( True )
)
process.VBF40 = cms.ESProducer( "VolumeBasedMagneticFieldESProducer",
  scalingVolumes = cms.vint32(  ),
  useParametrizedTrackerField = cms.bool( True ),
  scalingFactors = cms.vdouble(  ),
  label = cms.untracked.string( "071212_4t" ),
  version = cms.string( "grid_1103l_071212_4t" ),
  debugBuilder = cms.untracked.bool( False ),
  paramLabel = cms.string( "slave_40" ),
  geometryVersion = cms.int32( 71212 ),
  gridFiles = cms.VPSet( 
    cms.PSet(  path = cms.string( "grid.[v].bin" ),
      master = cms.int32( 1 ),
      sectors = cms.string( "0" ),
      volumes = cms.string( "1-312" )
    )
  ),
  cacheLastVolume = cms.untracked.bool( True )
)
process.ZdcGeometryFromDBEP = cms.ESProducer( "ZdcGeometryFromDBEP",
  applyAlignment = cms.bool( False )
)
process.caloDetIdAssociator = cms.ESProducer( "DetIdAssociatorESProducer",
  ComponentName = cms.string( "CaloDetIdAssociator" ),
  etaBinSize = cms.double( 0.087 ),
  nEta = cms.int32( 70 ),
  nPhi = cms.int32( 72 ),
  includeBadChambers = cms.bool( False )
)
process.cosmicsNavigationSchoolESProducer = cms.ESProducer( "NavigationSchoolESProducer",
  ComponentName = cms.string( "CosmicNavigationSchool" ),
  SimpleMagneticField = cms.string( "" )
)
process.ecalDetIdAssociator = cms.ESProducer( "DetIdAssociatorESProducer",
  ComponentName = cms.string( "EcalDetIdAssociator" ),
  etaBinSize = cms.double( 0.02 ),
  nEta = cms.int32( 300 ),
  nPhi = cms.int32( 360 ),
  includeBadChambers = cms.bool( False )
)
process.ecalSeverityLevel = cms.ESProducer( "EcalSeverityLevelESProducer",
  dbstatusMask = cms.PSet( 
    kGood = cms.vstring( 'kOk' ),
    kProblematic = cms.vstring( 'kDAC',
      'kNoLaser',
      'kNoisy',
      'kNNoisy',
      'kNNNoisy',
      'kNNNNoisy',
      'kNNNNNoisy',
      'kFixedG6',
      'kFixedG1',
      'kFixedG0' ),
    kRecovered = cms.vstring(  ),
    kTime = cms.vstring(  ),
    kWeird = cms.vstring(  ),
    kBad = cms.vstring( 'kNonRespondingIsolated',
      'kDeadVFE',
      'kDeadFE',
      'kNoDataNoTP' )
  ),
  timeThresh = cms.double( 2.0 ),
  flagMask = cms.PSet( 
    kGood = cms.vstring( 'kGood' ),
    kProblematic = cms.vstring( 'kPoorReco',
      'kPoorCalib',
      'kNoisy',
      'kSaturated' ),
    kRecovered = cms.vstring( 'kLeadingEdgeRecovered',
      'kTowerRecovered' ),
    kTime = cms.vstring( 'kOutOfTime' ),
    kWeird = cms.vstring( 'kWeird',
      'kDiWeird' ),
    kBad = cms.vstring( 'kFaultyHardware',
      'kDead',
      'kKilled' )
  )
)
process.hcalDetIdAssociator = cms.ESProducer( "DetIdAssociatorESProducer",
  ComponentName = cms.string( "HcalDetIdAssociator" ),
  etaBinSize = cms.double( 0.087 ),
  nEta = cms.int32( 70 ),
  nPhi = cms.int32( 72 ),
  includeBadChambers = cms.bool( False )
)
process.hcalRecAlgos = cms.ESProducer( "HcalRecAlgoESProducer",
  RecoveredRecHitBits = cms.vstring( 'TimingAddedBit',
    'TimingSubtractedBit' ),
  SeverityLevels = cms.VPSet( 
    cms.PSet(  RecHitFlags = cms.vstring(  ),
      ChannelStatus = cms.vstring(  ),
      Level = cms.int32( 0 )
    ),
    cms.PSet(  RecHitFlags = cms.vstring(  ),
      ChannelStatus = cms.vstring( 'HcalCellCaloTowerProb' ),
      Level = cms.int32( 1 )
    ),
    cms.PSet(  RecHitFlags = cms.vstring( 'HSCP_R1R2',
  'HSCP_FracLeader',
  'HSCP_OuterEnergy',
  'HSCP_ExpFit',
  'ADCSaturationBit',
  'HBHEIsolatedNoise',
  'AddedSimHcalNoise' ),
      ChannelStatus = cms.vstring( 'HcalCellExcludeFromHBHENoiseSummary' ),
      Level = cms.int32( 5 )
    ),
    cms.PSet(  RecHitFlags = cms.vstring( 'HBHEHpdHitMultiplicity',
  'HBHEPulseShape',
  'HOBit',
  'HFInTimeWindow',
  'ZDCBit',
  'CalibrationBit',
  'TimingErrorBit',
  'HBHETriangleNoise',
  'HBHETS4TS5Noise' ),
      ChannelStatus = cms.vstring(  ),
      Level = cms.int32( 8 )
    ),
    cms.PSet(  RecHitFlags = cms.vstring( 'HFLongShort',
  'HFPET',
  'HFS8S1Ratio',
  'HFDigiTime' ),
      ChannelStatus = cms.vstring(  ),
      Level = cms.int32( 11 )
    ),
    cms.PSet(  RecHitFlags = cms.vstring( 'HBHEFlatNoise',
  'HBHESpikeNoise' ),
      ChannelStatus = cms.vstring( 'HcalCellCaloTowerMask' ),
      Level = cms.int32( 12 )
    ),
    cms.PSet(  RecHitFlags = cms.vstring(  ),
      ChannelStatus = cms.vstring( 'HcalCellHot' ),
      Level = cms.int32( 15 )
    ),
    cms.PSet(  RecHitFlags = cms.vstring(  ),
      ChannelStatus = cms.vstring( 'HcalCellOff',
        'HcalCellDead' ),
      Level = cms.int32( 20 )
    )
  ),
  DropChannelStatusBits = cms.vstring( 'HcalCellMask',
    'HcalCellOff',
    'HcalCellDead' )
)
process.hcal_db_producer = cms.ESProducer( "HcalDbProducer" )
process.hltCombinedSecondaryVertex = cms.ESProducer( "CombinedSecondaryVertexESProducer",
  categoryVariableName = cms.string( "vertexCategory" ),
  useTrackWeights = cms.bool( True ),
  useCategories = cms.bool( True ),
  pseudoMultiplicityMin = cms.uint32( 2 ),
  correctVertexMass = cms.bool( True ),
  trackSelection = cms.PSet( 
    totalHitsMin = cms.uint32( 0 ),
    jetDeltaRMax = cms.double( 0.3 ),
    qualityClass = cms.string( "any" ),
    pixelHitsMin = cms.uint32( 0 ),
    sip3dSigMin = cms.double( -99999.9 ),
    sip3dSigMax = cms.double( 99999.9 ),
    normChi2Max = cms.double( 99999.9 ),
    maxDistToAxis = cms.double( 0.07 ),
    sip2dValMax = cms.double( 99999.9 ),
    maxDecayLen = cms.double( 5.0 ),
    ptMin = cms.double( 0.0 ),
    sip2dSigMax = cms.double( 99999.9 ),
    sip2dSigMin = cms.double( -99999.9 ),
    sip3dValMax = cms.double( 99999.9 ),
    sip2dValMin = cms.double( -99999.9 ),
    sip3dValMin = cms.double( -99999.9 )
  ),
  calibrationRecords = cms.vstring( 'CombinedSVRecoVertex',
    'CombinedSVPseudoVertex',
    'CombinedSVNoVertex' ),
  trackPairV0Filter = cms.PSet(  k0sMassWindow = cms.double( 0.03 ) ),
  charmCut = cms.double( 1.5 ),
  vertexFlip = cms.bool( False ),
  minimumTrackWeight = cms.double( 0.5 ),
  pseudoVertexV0Filter = cms.PSet(  k0sMassWindow = cms.double( 0.05 ) ),
  trackMultiplicityMin = cms.uint32( 3 ),
  trackPseudoSelection = cms.PSet( 
    totalHitsMin = cms.uint32( 0 ),
    jetDeltaRMax = cms.double( 0.3 ),
    qualityClass = cms.string( "any" ),
    pixelHitsMin = cms.uint32( 0 ),
    sip3dSigMin = cms.double( -99999.9 ),
    sip3dSigMax = cms.double( 99999.9 ),
    normChi2Max = cms.double( 99999.9 ),
    maxDistToAxis = cms.double( 0.07 ),
    sip2dValMax = cms.double( 99999.9 ),
    maxDecayLen = cms.double( 5.0 ),
    ptMin = cms.double( 0.0 ),
    sip2dSigMax = cms.double( 99999.9 ),
    sip2dSigMin = cms.double( 2.0 ),
    sip3dValMax = cms.double( 99999.9 ),
    sip2dValMin = cms.double( -99999.9 ),
    sip3dValMin = cms.double( -99999.9 )
  ),
  trackSort = cms.string( "sip2dSig" ),
  trackFlip = cms.bool( False )
)
process.hltCombinedSecondaryVertexV2 = cms.ESProducer( "CombinedSecondaryVertexESProducer",
  categoryVariableName = cms.string( "vertexCategory" ),
  useTrackWeights = cms.bool( True ),
  useCategories = cms.bool( True ),
  pseudoMultiplicityMin = cms.uint32( 2 ),
  correctVertexMass = cms.bool( True ),
  trackSelection = cms.PSet( 
    b_pT = cms.double( 0.3684 ),
    max_pT = cms.double( 500.0 ),
    useVariableJTA = cms.bool( False ),
    maxDecayLen = cms.double( 5.0 ),
    sip3dValMin = cms.double( -99999.9 ),
    max_pT_dRcut = cms.double( 0.1 ),
    a_pT = cms.double( 0.005263 ),
    totalHitsMin = cms.uint32( 0 ),
    jetDeltaRMax = cms.double( 0.3 ),
    a_dR = cms.double( -0.001053 ),
    maxDistToAxis = cms.double( 0.07 ),
    ptMin = cms.double( 0.0 ),
    qualityClass = cms.string( "any" ),
    pixelHitsMin = cms.uint32( 0 ),
    sip2dValMax = cms.double( 99999.9 ),
    max_pT_trackPTcut = cms.double( 3.0 ),
    sip2dValMin = cms.double( -99999.9 ),
    normChi2Max = cms.double( 99999.9 ),
    sip3dValMax = cms.double( 99999.9 ),
    sip3dSigMin = cms.double( -99999.9 ),
    min_pT = cms.double( 120.0 ),
    min_pT_dRcut = cms.double( 0.5 ),
    sip2dSigMax = cms.double( 99999.9 ),
    sip3dSigMax = cms.double( 99999.9 ),
    sip2dSigMin = cms.double( -99999.9 ),
    b_dR = cms.double( 0.6263 )
  ),
  calibrationRecords = cms.vstring( 'CombinedSVIVFV2RecoVertex',
    'CombinedSVIVFV2PseudoVertex',
    'CombinedSVIVFV2NoVertex' ),
  trackPairV0Filter = cms.PSet(  k0sMassWindow = cms.double( 0.03 ) ),
  charmCut = cms.double( 1.5 ),
  vertexFlip = cms.bool( False ),
  minimumTrackWeight = cms.double( 0.5 ),
  pseudoVertexV0Filter = cms.PSet(  k0sMassWindow = cms.double( 0.05 ) ),
  trackMultiplicityMin = cms.uint32( 3 ),
  trackPseudoSelection = cms.PSet( 
    b_pT = cms.double( 0.3684 ),
    max_pT = cms.double( 500.0 ),
    useVariableJTA = cms.bool( False ),
    maxDecayLen = cms.double( 5.0 ),
    sip3dValMin = cms.double( -99999.9 ),
    max_pT_dRcut = cms.double( 0.1 ),
    a_pT = cms.double( 0.005263 ),
    totalHitsMin = cms.uint32( 0 ),
    jetDeltaRMax = cms.double( 0.3 ),
    a_dR = cms.double( -0.001053 ),
    maxDistToAxis = cms.double( 0.07 ),
    ptMin = cms.double( 0.0 ),
    qualityClass = cms.string( "any" ),
    pixelHitsMin = cms.uint32( 0 ),
    sip2dValMax = cms.double( 99999.9 ),
    max_pT_trackPTcut = cms.double( 3.0 ),
    sip2dValMin = cms.double( -99999.9 ),
    normChi2Max = cms.double( 99999.9 ),
    sip3dValMax = cms.double( 99999.9 ),
    sip3dSigMin = cms.double( -99999.9 ),
    min_pT = cms.double( 120.0 ),
    min_pT_dRcut = cms.double( 0.5 ),
    sip2dSigMax = cms.double( 99999.9 ),
    sip3dSigMax = cms.double( 99999.9 ),
    sip2dSigMin = cms.double( 2.0 ),
    b_dR = cms.double( 0.6263 )
  ),
  trackSort = cms.string( "sip2dSig" ),
  trackFlip = cms.bool( False )
)
process.hltESPAnalyticalPropagator = cms.ESProducer( "AnalyticalPropagatorESProducer",
  MaxDPhi = cms.double( 1.6 ),
  ComponentName = cms.string( "hltESPAnalyticalPropagator" ),
  PropagationDirection = cms.string( "alongMomentum" )
)
process.hltESPBwdAnalyticalPropagator = cms.ESProducer( "AnalyticalPropagatorESProducer",
  MaxDPhi = cms.double( 1.6 ),
  ComponentName = cms.string( "hltESPBwdAnalyticalPropagator" ),
  PropagationDirection = cms.string( "oppositeToMomentum" )
)
process.hltESPBwdElectronPropagator = cms.ESProducer( "PropagatorWithMaterialESProducer",
  SimpleMagneticField = cms.string( "" ),
  PropagationDirection = cms.string( "oppositeToMomentum" ),
  ComponentName = cms.string( "hltESPBwdElectronPropagator" ),
  Mass = cms.double( 5.11E-4 ),
  ptMin = cms.double( -1.0 ),
  MaxDPhi = cms.double( 1.6 ),
  useRungeKutta = cms.bool( False )
)
process.hltESPCloseComponentsMerger5D = cms.ESProducer( "CloseComponentsMergerESProducer5D",
  ComponentName = cms.string( "hltESPCloseComponentsMerger5D" ),
  MaxComponents = cms.int32( 12 ),
  DistanceMeasure = cms.string( "hltESPKullbackLeiblerDistance5D" )
)
process.hltESPDummyDetLayerGeometry = cms.ESProducer( "DetLayerGeometryESProducer",
  ComponentName = cms.string( "hltESPDummyDetLayerGeometry" )
)
process.hltESPEcalTrigTowerConstituentsMapBuilder = cms.ESProducer( "EcalTrigTowerConstituentsMapBuilder",
  MapFile = cms.untracked.string( "Geometry/EcalMapping/data/EndCap_TTMap.txt" )
)
process.hltESPElectronMaterialEffects = cms.ESProducer( "GsfMaterialEffectsESProducer",
  BetheHeitlerParametrization = cms.string( "BetheHeitler_cdfmom_nC6_O5.par" ),
  EnergyLossUpdator = cms.string( "GsfBetheHeitlerUpdator" ),
  ComponentName = cms.string( "hltESPElectronMaterialEffects" ),
  MultipleScatteringUpdator = cms.string( "MultipleScatteringUpdator" ),
  Mass = cms.double( 5.11E-4 ),
  BetheHeitlerCorrection = cms.int32( 2 )
)
process.hltESPFastSteppingHelixPropagatorAny = cms.ESProducer( "SteppingHelixPropagatorESProducer",
  NoErrorPropagation = cms.bool( False ),
  endcapShiftInZPos = cms.double( 0.0 ),
  PropagationDirection = cms.string( "anyDirection" ),
  useTuningForL2Speed = cms.bool( True ),
  useIsYokeFlag = cms.bool( True ),
  endcapShiftInZNeg = cms.double( 0.0 ),
  SetVBFPointer = cms.bool( False ),
  AssumeNoMaterial = cms.bool( False ),
  returnTangentPlane = cms.bool( True ),
  useInTeslaFromMagField = cms.bool( False ),
  VBFName = cms.string( "VolumeBasedMagneticField" ),
  useEndcapShiftsInZ = cms.bool( False ),
  sendLogWarning = cms.bool( False ),
  useMatVolumes = cms.bool( True ),
  debug = cms.bool( False ),
  ApplyRadX0Correction = cms.bool( True ),
  useMagVolumes = cms.bool( True ),
  ComponentName = cms.string( "hltESPFastSteppingHelixPropagatorAny" )
)
process.hltESPFastSteppingHelixPropagatorOpposite = cms.ESProducer( "SteppingHelixPropagatorESProducer",
  NoErrorPropagation = cms.bool( False ),
  endcapShiftInZPos = cms.double( 0.0 ),
  PropagationDirection = cms.string( "oppositeToMomentum" ),
  useTuningForL2Speed = cms.bool( True ),
  useIsYokeFlag = cms.bool( True ),
  endcapShiftInZNeg = cms.double( 0.0 ),
  SetVBFPointer = cms.bool( False ),
  AssumeNoMaterial = cms.bool( False ),
  returnTangentPlane = cms.bool( True ),
  useInTeslaFromMagField = cms.bool( False ),
  VBFName = cms.string( "VolumeBasedMagneticField" ),
  useEndcapShiftsInZ = cms.bool( False ),
  sendLogWarning = cms.bool( False ),
  useMatVolumes = cms.bool( True ),
  debug = cms.bool( False ),
  ApplyRadX0Correction = cms.bool( True ),
  useMagVolumes = cms.bool( True ),
  ComponentName = cms.string( "hltESPFastSteppingHelixPropagatorOpposite" )
)
process.hltESPFittingSmootherIT = cms.ESProducer( "KFFittingSmootherESProducer",
  EstimateCut = cms.double( -1.0 ),
  LogPixelProbabilityCut = cms.double( -16.0 ),
  Fitter = cms.string( "hltESPTrajectoryFitterRK" ),
  MinNumberOfHits = cms.int32( 3 ),
  Smoother = cms.string( "hltESPTrajectorySmootherRK" ),
  BreakTrajWith2ConsecutiveMissing = cms.bool( True ),
  ComponentName = cms.string( "hltESPFittingSmootherIT" ),
  NoInvalidHitsBeginEnd = cms.bool( True ),
  RejectTracks = cms.bool( True )
)
process.hltESPFittingSmootherRK = cms.ESProducer( "KFFittingSmootherESProducer",
  EstimateCut = cms.double( -1.0 ),
  LogPixelProbabilityCut = cms.double( -16.0 ),
  Fitter = cms.string( "hltESPTrajectoryFitterRK" ),
  MinNumberOfHits = cms.int32( 5 ),
  Smoother = cms.string( "hltESPTrajectorySmootherRK" ),
  BreakTrajWith2ConsecutiveMissing = cms.bool( False ),
  ComponentName = cms.string( "hltESPFittingSmootherRK" ),
  NoInvalidHitsBeginEnd = cms.bool( False ),
  RejectTracks = cms.bool( True )
)
process.hltESPFwdElectronPropagator = cms.ESProducer( "PropagatorWithMaterialESProducer",
  SimpleMagneticField = cms.string( "" ),
  PropagationDirection = cms.string( "alongMomentum" ),
  ComponentName = cms.string( "hltESPFwdElectronPropagator" ),
  Mass = cms.double( 5.11E-4 ),
  ptMin = cms.double( -1.0 ),
  MaxDPhi = cms.double( 1.6 ),
  useRungeKutta = cms.bool( False )
)
process.hltESPGlobalDetLayerGeometry = cms.ESProducer( "GlobalDetLayerGeometryESProducer",
  ComponentName = cms.string( "hltESPGlobalDetLayerGeometry" )
)
process.hltESPGlobalTrackingGeometryESProducer = cms.ESProducer( "GlobalTrackingGeometryESProducer" )
process.hltESPGsfElectronFittingSmoother = cms.ESProducer( "KFFittingSmootherESProducer",
  EstimateCut = cms.double( -1.0 ),
  LogPixelProbabilityCut = cms.double( -16.0 ),
  Fitter = cms.string( "hltESPGsfTrajectoryFitter" ),
  MinNumberOfHits = cms.int32( 5 ),
  Smoother = cms.string( "hltESPGsfTrajectorySmoother" ),
  BreakTrajWith2ConsecutiveMissing = cms.bool( True ),
  ComponentName = cms.string( "hltESPGsfElectronFittingSmoother" ),
  NoInvalidHitsBeginEnd = cms.bool( True ),
  RejectTracks = cms.bool( True )
)
process.hltESPGsfTrajectoryFitter = cms.ESProducer( "GsfTrajectoryFitterESProducer",
  Merger = cms.string( "hltESPCloseComponentsMerger5D" ),
  ComponentName = cms.string( "hltESPGsfTrajectoryFitter" ),
  MaterialEffectsUpdator = cms.string( "hltESPElectronMaterialEffects" ),
  RecoGeometry = cms.string( "hltESPGlobalDetLayerGeometry" ),
  GeometricalPropagator = cms.string( "hltESPAnalyticalPropagator" )
)
process.hltESPGsfTrajectorySmoother = cms.ESProducer( "GsfTrajectorySmootherESProducer",
  ErrorRescaling = cms.double( 100.0 ),
  RecoGeometry = cms.string( "hltESPGlobalDetLayerGeometry" ),
  Merger = cms.string( "hltESPCloseComponentsMerger5D" ),
  ComponentName = cms.string( "hltESPGsfTrajectorySmoother" ),
  GeometricalPropagator = cms.string( "hltESPBwdAnalyticalPropagator" ),
  MaterialEffectsUpdator = cms.string( "hltESPElectronMaterialEffects" )
)
process.hltESPKFFittingSmoother = cms.ESProducer( "KFFittingSmootherESProducer",
  EstimateCut = cms.double( -1.0 ),
  LogPixelProbabilityCut = cms.double( -16.0 ),
  Fitter = cms.string( "hltESPKFTrajectoryFitter" ),
  MinNumberOfHits = cms.int32( 5 ),
  Smoother = cms.string( "hltESPKFTrajectorySmoother" ),
  BreakTrajWith2ConsecutiveMissing = cms.bool( False ),
  ComponentName = cms.string( "hltESPKFFittingSmoother" ),
  NoInvalidHitsBeginEnd = cms.bool( False ),
  RejectTracks = cms.bool( True )
)
process.hltESPKFFittingSmootherForL2Muon = cms.ESProducer( "KFFittingSmootherESProducer",
  EstimateCut = cms.double( -1.0 ),
  LogPixelProbabilityCut = cms.double( -16.0 ),
  Fitter = cms.string( "hltESPKFTrajectoryFitterForL2Muon" ),
  MinNumberOfHits = cms.int32( 5 ),
  Smoother = cms.string( "hltESPKFTrajectorySmootherForL2Muon" ),
  BreakTrajWith2ConsecutiveMissing = cms.bool( False ),
  ComponentName = cms.string( "hltESPKFFittingSmootherForL2Muon" ),
  NoInvalidHitsBeginEnd = cms.bool( False ),
  RejectTracks = cms.bool( True )
)
process.hltESPKFTrajectoryFitter = cms.ESProducer( "KFTrajectoryFitterESProducer",
  minHits = cms.int32( 3 ),
  ComponentName = cms.string( "hltESPKFTrajectoryFitter" ),
  Estimator = cms.string( "hltESPChi2MeasurementEstimator30" ),
  Updator = cms.string( "hltESPKFUpdator" ),
  Propagator = cms.string( "PropagatorWithMaterialParabolicMf" ),
  RecoGeometry = cms.string( "hltESPDummyDetLayerGeometry" )
)
process.hltESPKFTrajectoryFitterForL2Muon = cms.ESProducer( "KFTrajectoryFitterESProducer",
  minHits = cms.int32( 3 ),
  ComponentName = cms.string( "hltESPKFTrajectoryFitterForL2Muon" ),
  Estimator = cms.string( "hltESPChi2MeasurementEstimator30" ),
  Updator = cms.string( "hltESPKFUpdator" ),
  Propagator = cms.string( "hltESPFastSteppingHelixPropagatorAny" ),
  RecoGeometry = cms.string( "hltESPDummyDetLayerGeometry" )
)
process.hltESPKFTrajectorySmoother = cms.ESProducer( "KFTrajectorySmootherESProducer",
  errorRescaling = cms.double( 100.0 ),
  minHits = cms.int32( 3 ),
  ComponentName = cms.string( "hltESPKFTrajectorySmoother" ),
  Estimator = cms.string( "hltESPChi2MeasurementEstimator30" ),
  Updator = cms.string( "hltESPKFUpdator" ),
  Propagator = cms.string( "PropagatorWithMaterialParabolicMf" ),
  RecoGeometry = cms.string( "hltESPDummyDetLayerGeometry" )
)
process.hltESPKFTrajectorySmootherForL2Muon = cms.ESProducer( "KFTrajectorySmootherESProducer",
  errorRescaling = cms.double( 100.0 ),
  minHits = cms.int32( 3 ),
  ComponentName = cms.string( "hltESPKFTrajectorySmootherForL2Muon" ),
  Estimator = cms.string( "hltESPChi2MeasurementEstimator30" ),
  Updator = cms.string( "hltESPKFUpdator" ),
  Propagator = cms.string( "hltESPFastSteppingHelixPropagatorOpposite" ),
  RecoGeometry = cms.string( "hltESPDummyDetLayerGeometry" )
)
process.hltESPKFTrajectorySmootherForMuonTrackLoader = cms.ESProducer( "KFTrajectorySmootherESProducer",
  errorRescaling = cms.double( 10.0 ),
  minHits = cms.int32( 3 ),
  ComponentName = cms.string( "hltESPKFTrajectorySmootherForMuonTrackLoader" ),
  Estimator = cms.string( "hltESPChi2MeasurementEstimator30" ),
  Updator = cms.string( "hltESPKFUpdator" ),
  Propagator = cms.string( "hltESPSmartPropagatorAnyOpposite" ),
  RecoGeometry = cms.string( "hltESPDummyDetLayerGeometry" )
)
process.hltESPKFUpdator = cms.ESProducer( "KFUpdatorESProducer",
  ComponentName = cms.string( "hltESPKFUpdator" )
)
process.hltESPKullbackLeiblerDistance5D = cms.ESProducer( "DistanceBetweenComponentsESProducer5D",
  ComponentName = cms.string( "hltESPKullbackLeiblerDistance5D" ),
  DistanceMeasure = cms.string( "KullbackLeibler" )
)
process.hltESPL3MuKFTrajectoryFitter = cms.ESProducer( "KFTrajectoryFitterESProducer",
  minHits = cms.int32( 3 ),
  ComponentName = cms.string( "hltESPL3MuKFTrajectoryFitter" ),
  Estimator = cms.string( "hltESPChi2MeasurementEstimator30" ),
  Updator = cms.string( "hltESPKFUpdator" ),
  Propagator = cms.string( "hltESPSmartPropagatorAny" ),
  RecoGeometry = cms.string( "hltESPDummyDetLayerGeometry" )
)
process.hltESPMeasurementTracker = cms.ESProducer( "MeasurementTrackerESProducer",
  UseStripStripQualityDB = cms.bool( True ),
  StripCPE = cms.string( "hltESPStripCPEfromTrackAngle" ),
  UsePixelROCQualityDB = cms.bool( True ),
  DebugPixelROCQualityDB = cms.untracked.bool( False ),
  UseStripAPVFiberQualityDB = cms.bool( True ),
  badStripCuts = cms.PSet( 
    TOB = cms.PSet( 
      maxConsecutiveBad = cms.uint32( 9999 ),
      maxBad = cms.uint32( 9999 )
    ),
    TID = cms.PSet( 
      maxConsecutiveBad = cms.uint32( 9999 ),
      maxBad = cms.uint32( 9999 )
    ),
    TEC = cms.PSet( 
      maxConsecutiveBad = cms.uint32( 9999 ),
      maxBad = cms.uint32( 9999 )
    ),
    TIB = cms.PSet( 
      maxConsecutiveBad = cms.uint32( 9999 ),
      maxBad = cms.uint32( 9999 )
    )
  ),
  DebugStripModuleQualityDB = cms.untracked.bool( False ),
  ComponentName = cms.string( "hltESPMeasurementTracker" ),
  DebugPixelModuleQualityDB = cms.untracked.bool( False ),
  UsePixelModuleQualityDB = cms.bool( True ),
  DebugStripAPVFiberQualityDB = cms.untracked.bool( False ),
  HitMatcher = cms.string( "StandardMatcher" ),
  DebugStripStripQualityDB = cms.untracked.bool( False ),
  PixelCPE = cms.string( "hltESPPixelCPEGeneric" ),
  SiStripQualityLabel = cms.string( "" ),
  UseStripModuleQualityDB = cms.bool( True ),
  MaskBadAPVFibers = cms.bool( True )
)
process.hltESPMuonDetLayerGeometryESProducer = cms.ESProducer( "MuonDetLayerGeometryESProducer" )
process.hltESPMuonTransientTrackingRecHitBuilder = cms.ESProducer( "MuonTransientTrackingRecHitBuilderESProducer",
  ComponentName = cms.string( "hltESPMuonTransientTrackingRecHitBuilder" )
)
process.hltESPPixelCPEGeneric = cms.ESProducer( "PixelCPEGenericESProducer",
  useLAAlignmentOffsets = cms.bool( False ),
  DoCosmics = cms.bool( False ),
  eff_charge_cut_highX = cms.double( 1.0 ),
  eff_charge_cut_highY = cms.double( 1.0 ),
  inflate_all_errors_no_trk_angle = cms.bool( False ),
  eff_charge_cut_lowY = cms.double( 0.0 ),
  eff_charge_cut_lowX = cms.double( 0.0 ),
  UseErrorsFromTemplates = cms.bool( True ),
  TruncatePixelCharge = cms.bool( True ),
  size_cutY = cms.double( 3.0 ),
  size_cutX = cms.double( 3.0 ),
  useLAWidthFromDB = cms.bool( False ),
  inflate_errors = cms.bool( False ),
  Alpha2Order = cms.bool( True ),
  ClusterProbComputationFlag = cms.int32( 0 ),
  PixelErrorParametrization = cms.string( "NOTcmsim" ),
  EdgeClusterErrorX = cms.double( 50.0 ),
  EdgeClusterErrorY = cms.double( 85.0 ),
  LoadTemplatesFromDB = cms.bool( True ),
  ComponentName = cms.string( "hltESPPixelCPEGeneric" ),
  IrradiationBiasCorrection = cms.bool( False )
)
process.hltESPRungeKuttaTrackerPropagator = cms.ESProducer( "PropagatorWithMaterialESProducer",
  SimpleMagneticField = cms.string( "" ),
  PropagationDirection = cms.string( "alongMomentum" ),
  ComponentName = cms.string( "hltESPRungeKuttaTrackerPropagator" ),
  Mass = cms.double( 0.105 ),
  ptMin = cms.double( -1.0 ),
  MaxDPhi = cms.double( 1.6 ),
  useRungeKutta = cms.bool( True )
)
process.hltESPSmartPropagator = cms.ESProducer( "SmartPropagatorESProducer",
  Epsilon = cms.double( 5.0 ),
  TrackerPropagator = cms.string( "PropagatorWithMaterial" ),
  MuonPropagator = cms.string( "hltESPSteppingHelixPropagatorAlong" ),
  PropagationDirection = cms.string( "alongMomentum" ),
  ComponentName = cms.string( "hltESPSmartPropagator" )
)
process.hltESPSmartPropagatorAny = cms.ESProducer( "SmartPropagatorESProducer",
  Epsilon = cms.double( 5.0 ),
  TrackerPropagator = cms.string( "PropagatorWithMaterial" ),
  MuonPropagator = cms.string( "SteppingHelixPropagatorAny" ),
  PropagationDirection = cms.string( "alongMomentum" ),
  ComponentName = cms.string( "hltESPSmartPropagatorAny" )
)
process.hltESPSmartPropagatorAnyOpposite = cms.ESProducer( "SmartPropagatorESProducer",
  Epsilon = cms.double( 5.0 ),
  TrackerPropagator = cms.string( "PropagatorWithMaterialOpposite" ),
  MuonPropagator = cms.string( "SteppingHelixPropagatorAny" ),
  PropagationDirection = cms.string( "oppositeToMomentum" ),
  ComponentName = cms.string( "hltESPSmartPropagatorAnyOpposite" )
)
process.hltESPSoftLeptonByDistance = cms.ESProducer( "LeptonTaggerByDistanceESProducer",
  distance = cms.double( 0.5 )
)
process.hltESPSteppingHelixPropagatorAlong = cms.ESProducer( "SteppingHelixPropagatorESProducer",
  NoErrorPropagation = cms.bool( False ),
  endcapShiftInZPos = cms.double( 0.0 ),
  PropagationDirection = cms.string( "alongMomentum" ),
  useTuningForL2Speed = cms.bool( False ),
  useIsYokeFlag = cms.bool( True ),
  endcapShiftInZNeg = cms.double( 0.0 ),
  SetVBFPointer = cms.bool( False ),
  AssumeNoMaterial = cms.bool( False ),
  returnTangentPlane = cms.bool( True ),
  useInTeslaFromMagField = cms.bool( False ),
  VBFName = cms.string( "VolumeBasedMagneticField" ),
  useEndcapShiftsInZ = cms.bool( False ),
  sendLogWarning = cms.bool( False ),
  useMatVolumes = cms.bool( True ),
  debug = cms.bool( False ),
  ApplyRadX0Correction = cms.bool( True ),
  useMagVolumes = cms.bool( True ),
  ComponentName = cms.string( "hltESPSteppingHelixPropagatorAlong" )
)
process.hltESPSteppingHelixPropagatorOpposite = cms.ESProducer( "SteppingHelixPropagatorESProducer",
  NoErrorPropagation = cms.bool( False ),
  endcapShiftInZPos = cms.double( 0.0 ),
  PropagationDirection = cms.string( "oppositeToMomentum" ),
  useTuningForL2Speed = cms.bool( False ),
  useIsYokeFlag = cms.bool( True ),
  endcapShiftInZNeg = cms.double( 0.0 ),
  SetVBFPointer = cms.bool( False ),
  AssumeNoMaterial = cms.bool( False ),
  returnTangentPlane = cms.bool( True ),
  useInTeslaFromMagField = cms.bool( False ),
  VBFName = cms.string( "VolumeBasedMagneticField" ),
  useEndcapShiftsInZ = cms.bool( False ),
  sendLogWarning = cms.bool( False ),
  useMatVolumes = cms.bool( True ),
  debug = cms.bool( False ),
  ApplyRadX0Correction = cms.bool( True ),
  useMagVolumes = cms.bool( True ),
  ComponentName = cms.string( "hltESPSteppingHelixPropagatorOpposite" )
)
process.hltESPStripCPEfromTrackAngle = cms.ESProducer( "StripCPEESProducer",
  ComponentType = cms.string( "StripCPEfromTrackAngle" ),
  ComponentName = cms.string( "hltESPStripCPEfromTrackAngle" ),
  parameters = cms.PSet( 
    mLC_P2 = cms.double( 0.3 ),
    mLC_P1 = cms.double( 0.618 ),
    mLC_P0 = cms.double( -0.326 ),
    useLegacyError = cms.bool( False ),
    mTEC_P1 = cms.double( 0.471 ),
    mTEC_P0 = cms.double( -1.885 ),
    mTOB_P0 = cms.double( -1.026 ),
    mTOB_P1 = cms.double( 0.253 ),
    mTIB_P0 = cms.double( -0.742 ),
    mTIB_P1 = cms.double( 0.202 ),
    mTID_P0 = cms.double( -1.427 ),
    mTID_P1 = cms.double( 0.433 ),
    maxChgOneMIP = cms.double( 6000.0 )
  )
)
process.hltESPTTRHBWithTrackAngle = cms.ESProducer( "TkTransientTrackingRecHitBuilderESProducer",
  StripCPE = cms.string( "hltESPStripCPEfromTrackAngle" ),
  Matcher = cms.string( "StandardMatcher" ),
  ComputeCoarseLocalPositionFromDisk = cms.bool( False ),
  PixelCPE = cms.string( "hltESPPixelCPEGeneric" ),
  ComponentName = cms.string( "hltESPTTRHBWithTrackAngle" )
)
process.hltESPTTRHBuilderPixelOnly = cms.ESProducer( "TkTransientTrackingRecHitBuilderESProducer",
  StripCPE = cms.string( "Fake" ),
  Matcher = cms.string( "StandardMatcher" ),
  ComputeCoarseLocalPositionFromDisk = cms.bool( False ),
  PixelCPE = cms.string( "hltESPPixelCPEGeneric" ),
  ComponentName = cms.string( "hltESPTTRHBuilderPixelOnly" )
)
process.hltESPTrackerRecoGeometryESProducer = cms.ESProducer( "TrackerRecoGeometryESProducer",
  appendToDataLabel = cms.string( "" ),
  trackerGeometryLabel = cms.untracked.string( "" )
)
process.hltESPTrajectoryCleanerBySharedHits = cms.ESProducer( "TrajectoryCleanerESProducer",
  ComponentName = cms.string( "hltESPTrajectoryCleanerBySharedHits" ),
  fractionShared = cms.double( 0.5 ),
  ValidHitBonus = cms.double( 100.0 ),
  ComponentType = cms.string( "TrajectoryCleanerBySharedHits" ),
  MissingHitPenalty = cms.double( 0.0 ),
  allowSharedFirstHit = cms.bool( False )
)
process.hltESPTrajectoryFitterRK = cms.ESProducer( "KFTrajectoryFitterESProducer",
  minHits = cms.int32( 3 ),
  ComponentName = cms.string( "hltESPTrajectoryFitterRK" ),
  Estimator = cms.string( "hltESPChi2MeasurementEstimator30" ),
  Updator = cms.string( "hltESPKFUpdator" ),
  Propagator = cms.string( "hltESPRungeKuttaTrackerPropagator" ),
  RecoGeometry = cms.string( "hltESPDummyDetLayerGeometry" )
)
process.hltESPTrajectorySmootherRK = cms.ESProducer( "KFTrajectorySmootherESProducer",
  errorRescaling = cms.double( 100.0 ),
  minHits = cms.int32( 3 ),
  ComponentName = cms.string( "hltESPTrajectorySmootherRK" ),
  Estimator = cms.string( "hltESPChi2MeasurementEstimator30" ),
  Updator = cms.string( "hltESPKFUpdator" ),
  Propagator = cms.string( "hltESPRungeKuttaTrackerPropagator" ),
  RecoGeometry = cms.string( "hltESPDummyDetLayerGeometry" )
)
process.hoDetIdAssociator = cms.ESProducer( "DetIdAssociatorESProducer",
  ComponentName = cms.string( "HODetIdAssociator" ),
  etaBinSize = cms.double( 0.087 ),
  nEta = cms.int32( 30 ),
  nPhi = cms.int32( 72 ),
  includeBadChambers = cms.bool( False )
)
process.muonDetIdAssociator = cms.ESProducer( "DetIdAssociatorESProducer",
  ComponentName = cms.string( "MuonDetIdAssociator" ),
  etaBinSize = cms.double( 0.125 ),
  nEta = cms.int32( 48 ),
  nPhi = cms.int32( 48 ),
  includeBadChambers = cms.bool( False )
)
process.navigationSchoolESProducer = cms.ESProducer( "NavigationSchoolESProducer",
  ComponentName = cms.string( "SimpleNavigationSchool" ),
  SimpleMagneticField = cms.string( "ParabolicMf" )
)
process.preshowerDetIdAssociator = cms.ESProducer( "DetIdAssociatorESProducer",
  ComponentName = cms.string( "PreshowerDetIdAssociator" ),
  etaBinSize = cms.double( 0.1 ),
  nEta = cms.int32( 60 ),
  nPhi = cms.int32( 30 ),
  includeBadChambers = cms.bool( False )
)
process.siPixelQualityESProducer = cms.ESProducer( "SiPixelQualityESProducer",
  ListOfRecordToMerge = cms.VPSet( 
    cms.PSet(  record = cms.string( "SiPixelQualityFromDbRcd" ),
      tag = cms.string( "" )
    ),
    cms.PSet(  record = cms.string( "SiPixelDetVOffRcd" ),
      tag = cms.string( "" )
    )
  )
)
process.siPixelTemplateDBObjectESProducer = cms.ESProducer( "SiPixelTemplateDBObjectESProducer" )
process.siStripBackPlaneCorrectionDepESProducer = cms.ESProducer( "SiStripBackPlaneCorrectionDepESProducer",
  LatencyRecord = cms.PSet( 
    record = cms.string( "SiStripLatencyRcd" ),
    label = cms.untracked.string( "" )
  ),
  BackPlaneCorrectionDeconvMode = cms.PSet( 
    record = cms.string( "SiStripBackPlaneCorrectionRcd" ),
    label = cms.untracked.string( "deconvolution" )
  ),
  BackPlaneCorrectionPeakMode = cms.PSet( 
    record = cms.string( "SiStripBackPlaneCorrectionRcd" ),
    label = cms.untracked.string( "peak" )
  )
)
process.siStripLorentzAngleDepESProducer = cms.ESProducer( "SiStripLorentzAngleDepESProducer",
  LatencyRecord = cms.PSet( 
    record = cms.string( "SiStripLatencyRcd" ),
    label = cms.untracked.string( "" )
  ),
  LorentzAngleDeconvMode = cms.PSet( 
    record = cms.string( "SiStripLorentzAngleRcd" ),
    label = cms.untracked.string( "deconvolution" )
  ),
  LorentzAnglePeakMode = cms.PSet( 
    record = cms.string( "SiStripLorentzAngleRcd" ),
    label = cms.untracked.string( "peak" )
  )
)
process.sistripconn = cms.ESProducer( "SiStripConnectivity" )
process.trackerTopology = cms.ESProducer( "TrackerTopologyEP",
  pxb_layerMask = cms.uint32( 15 ),
  tib_str_int_extStartBit = cms.uint32( 10 ),
  tib_layerMask = cms.uint32( 7 ),
  tib_str_fw_bwStartBit = cms.uint32( 12 ),
  pxf_bladeMask = cms.uint32( 63 ),
  pxb_moduleStartBit = cms.uint32( 2 ),
  pxb_ladderStartBit = cms.uint32( 8 ),
  pxb_layerStartBit = cms.uint32( 16 ),
  tec_wheelStartBit = cms.uint32( 14 ),
  tib_str_fw_bwMask = cms.uint32( 3 ),
  tec_ringStartBit = cms.uint32( 5 ),
  tib_moduleStartBit = cms.uint32( 2 ),
  tib_sterMask = cms.uint32( 3 ),
  tid_sideStartBit = cms.uint32( 13 ),
  tid_wheelStartBit = cms.uint32( 11 ),
  tid_ringMask = cms.uint32( 3 ),
  tid_sterMask = cms.uint32( 3 ),
  tec_petal_fw_bwStartBit = cms.uint32( 12 ),
  tec_ringMask = cms.uint32( 7 ),
  tib_strMask = cms.uint32( 63 ),
  tec_sterMask = cms.uint32( 3 ),
  tec_sideStartBit = cms.uint32( 18 ),
  pxb_moduleMask = cms.uint32( 63 ),
  pxf_panelStartBit = cms.uint32( 8 ),
  tid_sideMask = cms.uint32( 3 ),
  tob_moduleMask = cms.uint32( 7 ),
  tid_ringStartBit = cms.uint32( 9 ),
  pxf_sideMask = cms.uint32( 3 ),
  appendToDataLabel = cms.string( "" ),
  pxf_diskStartBit = cms.uint32( 16 ),
  tib_str_int_extMask = cms.uint32( 3 ),
  tec_moduleMask = cms.uint32( 7 ),
  tob_sterMask = cms.uint32( 3 ),
  tob_rod_fw_bwMask = cms.uint32( 3 ),
  tob_layerStartBit = cms.uint32( 14 ),
  tec_petal_fw_bwMask = cms.uint32( 3 ),
  tib_layerStartBit = cms.uint32( 14 ),
  tec_sterStartBit = cms.uint32( 0 ),
  tid_moduleMask = cms.uint32( 31 ),
  tib_sterStartBit = cms.uint32( 0 ),
  tid_sterStartBit = cms.uint32( 0 ),
  pxf_moduleStartBit = cms.uint32( 2 ),
  pxf_diskMask = cms.uint32( 15 ),
  pxf_sideStartBit = cms.uint32( 23 ),
  tid_module_fw_bwStartBit = cms.uint32( 7 ),
  tob_layerMask = cms.uint32( 7 ),
  tid_module_fw_bwMask = cms.uint32( 3 ),
  tob_rod_fw_bwStartBit = cms.uint32( 12 ),
  tec_petalMask = cms.uint32( 15 ),
  pxb_ladderMask = cms.uint32( 255 ),
  tec_moduleStartBit = cms.uint32( 2 ),
  tec_sideMask = cms.uint32( 3 ),
  tob_rodMask = cms.uint32( 127 ),
  tib_strStartBit = cms.uint32( 4 ),
  tec_wheelMask = cms.uint32( 15 ),
  tob_rodStartBit = cms.uint32( 5 ),
  pxf_panelMask = cms.uint32( 3 ),
  tib_moduleMask = cms.uint32( 3 ),
  pxf_bladeStartBit = cms.uint32( 10 ),
  tid_wheelMask = cms.uint32( 3 ),
  tob_sterStartBit = cms.uint32( 0 ),
  tid_moduleStartBit = cms.uint32( 2 ),
  tec_petalStartBit = cms.uint32( 8 ),
  tob_moduleStartBit = cms.uint32( 2 ),
  pxf_moduleMask = cms.uint32( 63 )
)

process.FastTimerService = cms.Service( "FastTimerService",
    dqmPath = cms.untracked.string( "HLT/TimerService" ),
    dqmModuleTimeRange = cms.untracked.double( 40.0 ),
    useRealTimeClock = cms.untracked.bool( True ),
    enableTimingModules = cms.untracked.bool( True ),
    enableDQM = cms.untracked.bool( True ),
    enableDQMbyModule = cms.untracked.bool( False ),
    enableTimingExclusive = cms.untracked.bool( True ),
    skipFirstPath = cms.untracked.bool( False ),
    enableDQMbyLumiSection = cms.untracked.bool( True ),
    dqmPathTimeResolution = cms.untracked.double( 0.5 ),
    dqmPathTimeRange = cms.untracked.double( 100.0 ),
    dqmTimeRange = cms.untracked.double( 1000.0 ),
    dqmLumiSectionsRange = cms.untracked.uint32( 2500 ),
    enableDQMbyProcesses = cms.untracked.bool( True ),
    enableDQMSummary = cms.untracked.bool( True ),
    enableTimingSummary = cms.untracked.bool( True ),
    enableDQMbyPathTotal = cms.untracked.bool( True ),
    enableTimingPaths = cms.untracked.bool( True ),
    enableDQMbyPathExclusive = cms.untracked.bool( True ),
    dqmTimeResolution = cms.untracked.double( 5.0 ),
    dqmModuleTimeResolution = cms.untracked.double( 0.2 ),
    enableDQMbyPathActive = cms.untracked.bool( True ),
    enableDQMbyPathDetails = cms.untracked.bool( True ),
    enableDQMbyPathOverhead = cms.untracked.bool( False ),
    enableDQMbyPathCounters = cms.untracked.bool( True ),
    enableDQMbyModuleType = cms.untracked.bool( False )
)
process.MessageLogger = cms.Service( "MessageLogger",
    suppressInfo = cms.untracked.vstring(  ),
    debugs = cms.untracked.PSet( 
      threshold = cms.untracked.string( "INFO" ),
      placeholder = cms.untracked.bool( True ),
      suppressInfo = cms.untracked.vstring(  ),
      suppressWarning = cms.untracked.vstring(  ),
      suppressDebug = cms.untracked.vstring(  ),
      suppressError = cms.untracked.vstring(  )
    ),
    suppressDebug = cms.untracked.vstring(  ),
    cout = cms.untracked.PSet(  placeholder = cms.untracked.bool( True ) ),
    cerr_stats = cms.untracked.PSet( 
      threshold = cms.untracked.string( "WARNING" ),
      output = cms.untracked.string( "cerr" ),
      optionalPSet = cms.untracked.bool( True )
    ),
    warnings = cms.untracked.PSet( 
      threshold = cms.untracked.string( "INFO" ),
      placeholder = cms.untracked.bool( True ),
      suppressInfo = cms.untracked.vstring(  ),
      suppressWarning = cms.untracked.vstring(  ),
      suppressDebug = cms.untracked.vstring(  ),
      suppressError = cms.untracked.vstring(  )
    ),
    statistics = cms.untracked.vstring( 'cerr' ),
    cerr = cms.untracked.PSet( 
      INFO = cms.untracked.PSet(  limit = cms.untracked.int32( 0 ) ),
      noTimeStamps = cms.untracked.bool( False ),
      FwkReport = cms.untracked.PSet( 
        reportEvery = cms.untracked.int32( 1 ),
        limit = cms.untracked.int32( 0 )
      ),
      default = cms.untracked.PSet(  limit = cms.untracked.int32( 10000000 ) ),
      Root_NoDictionary = cms.untracked.PSet(  limit = cms.untracked.int32( 0 ) ),
      FwkJob = cms.untracked.PSet(  limit = cms.untracked.int32( 0 ) ),
      FwkSummary = cms.untracked.PSet( 
        reportEvery = cms.untracked.int32( 1 ),
        limit = cms.untracked.int32( 10000000 )
      ),
      threshold = cms.untracked.string( "INFO" ),
      suppressInfo = cms.untracked.vstring(  ),
      suppressWarning = cms.untracked.vstring(  ),
      suppressDebug = cms.untracked.vstring(  ),
      suppressError = cms.untracked.vstring(  )
    ),
    FrameworkJobReport = cms.untracked.PSet( 
      default = cms.untracked.PSet(  limit = cms.untracked.int32( 0 ) ),
      FwkJob = cms.untracked.PSet(  limit = cms.untracked.int32( 10000000 ) )
    ),
    suppressWarning = cms.untracked.vstring( 'hltOnlineBeamSpot',
      'hltCtf3HitL1SeededWithMaterialTracks',
      'hltL3MuonsOIState',
      'hltPixelTracksForHighMult',
      'hltHITPixelTracksHE',
      'hltHITPixelTracksHB',
      'hltCtfL1SeededWithMaterialTracks',
      'hltRegionalTracksForL3MuonIsolation',
      'hltSiPixelClusters',
      'hltActivityStartUpElectronPixelSeeds',
      'hltLightPFTracks',
      'hltPixelVertices3DbbPhi',
      'hltL3MuonsIOHit',
      'hltPixelTracks',
      'hltSiPixelDigis',
      'hltL3MuonsOIHit',
      'hltL1SeededElectronGsfTracks',
      'hltL1SeededStartUpElectronPixelSeeds',
      'hltBLifetimeRegionalCtfWithMaterialTracksbbPhiL1FastJetFastPV',
      'hltCtfActivityWithMaterialTracks' ),
    errors = cms.untracked.PSet( 
      threshold = cms.untracked.string( "INFO" ),
      placeholder = cms.untracked.bool( True ),
      suppressInfo = cms.untracked.vstring(  ),
      suppressWarning = cms.untracked.vstring(  ),
      suppressDebug = cms.untracked.vstring(  ),
      suppressError = cms.untracked.vstring(  )
    ),
    fwkJobReports = cms.untracked.vstring( 'FrameworkJobReport' ),
    debugModules = cms.untracked.vstring(  ),
    infos = cms.untracked.PSet( 
      threshold = cms.untracked.string( "INFO" ),
      Root_NoDictionary = cms.untracked.PSet(  limit = cms.untracked.int32( 0 ) ),
      placeholder = cms.untracked.bool( True ),
      suppressInfo = cms.untracked.vstring(  ),
      suppressWarning = cms.untracked.vstring(  ),
      suppressDebug = cms.untracked.vstring(  ),
      suppressError = cms.untracked.vstring(  )
    ),
    categories = cms.untracked.vstring( 'FwkJob',
      'FwkReport',
      'FwkSummary',
      'Root_NoDictionary' ),
    destinations = cms.untracked.vstring( 'warnings',
      'errors',
      'infos',
      'debugs',
      'cout',
      'cerr' ),
    threshold = cms.untracked.string( "INFO" ),
    suppressError = cms.untracked.vstring( 'hltOnlineBeamSpot',
      'hltL3MuonCandidates',
      'hltL3TkTracksFromL2OIState',
      'hltPFJetCtfWithMaterialTracks',
      'hltL3TkTracksFromL2IOHit',
      'hltL3TkTracksFromL2OIHit' )
)

process.hltGetConditions = cms.EDAnalyzer( "EventSetupRecordDataGetter",
    toGet = cms.VPSet( 
    ),
    verbose = cms.untracked.bool( False )
)
process.hltGetRaw = cms.EDAnalyzer( "HLTGetRaw",
    RawDataCollection = cms.InputTag( "rawDataCollector" )
)
process.hltBoolFalse = cms.EDFilter( "HLTBool",
    result = cms.bool( False )
)
process.hltTriggerType = cms.EDFilter( "HLTTriggerTypeFilter",
    SelectedTriggerType = cms.int32( 1 )
)
process.hltGtDigis = cms.EDProducer( "L1GlobalTriggerRawToDigi",
    DaqGtFedId = cms.untracked.int32( 813 ),
    Verbosity = cms.untracked.int32( 0 ),
    UnpackBxInEvent = cms.int32( 5 ),
    ActiveBoardsMask = cms.uint32( 0xffff ),
    DaqGtInputTag = cms.InputTag( "rawDataCollector" )
)
process.hltCaloStage1Digis = cms.EDProducer( "L1TRawToDigi",
    lenSlinkTrailer = cms.untracked.int32( 8 ),
    lenAMC13Header = cms.untracked.int32( 8 ),
    lenAMC13Trailer = cms.untracked.int32( 8 ),
    Setup = cms.string( "stage1::CaloSetup" ),
    InputLabel = cms.InputTag( "rawDataCollector" ),
    lenSlinkHeader = cms.untracked.int32( 8 ),
    FWId = cms.untracked.int32( 2 ),
    lenAMCHeader = cms.untracked.int32( 8 ),
    lenAMCTrailer = cms.untracked.int32( 0 ),
    FedId = cms.int32( 1352 )
)
process.hltCaloStage1LegacyFormatDigis = cms.EDProducer( "L1TCaloUpgradeToGCTConverter",
    InputHFCountsCollection = cms.InputTag( 'hltCaloStage1Digis','HFBitCounts' ),
    InputHFSumsCollection = cms.InputTag( 'hltCaloStage1Digis','HFRingSums' ),
    InputRlxTauCollection = cms.InputTag( 'hltCaloStage1Digis','rlxTaus' ),
    InputIsoTauCollection = cms.InputTag( 'hltCaloStage1Digis','isoTaus' ),
    InputCollection = cms.InputTag( "hltCaloStage1Digis" )
)
process.hltL1GtObjectMap = cms.EDProducer( "L1GlobalTrigger",
    TechnicalTriggersUnprescaled = cms.bool( True ),
    ProduceL1GtObjectMapRecord = cms.bool( True ),
    AlgorithmTriggersUnmasked = cms.bool( False ),
    EmulateBxInEvent = cms.int32( 1 ),
    AlgorithmTriggersUnprescaled = cms.bool( True ),
    ProduceL1GtDaqRecord = cms.bool( False ),
    ReadTechnicalTriggerRecords = cms.bool( True ),
    RecordLength = cms.vint32( 3, 0 ),
    TechnicalTriggersUnmasked = cms.bool( False ),
    ProduceL1GtEvmRecord = cms.bool( False ),
    GmtInputTag = cms.InputTag( "hltGtDigis" ),
    TechnicalTriggersVetoUnmasked = cms.bool( True ),
    AlternativeNrBxBoardEvm = cms.uint32( 0 ),
    TechnicalTriggersInputTags = cms.VInputTag( 'simBscDigis' ),
    CastorInputTag = cms.InputTag( "castorL1Digis" ),
    GctInputTag = cms.InputTag( "hltCaloStage1LegacyFormatDigis" ),
    AlternativeNrBxBoardDaq = cms.uint32( 0 ),
    WritePsbL1GtDaqRecord = cms.bool( False ),
    BstLengthBytes = cms.int32( -1 )
)
process.hltL1extraParticles = cms.EDProducer( "L1ExtraParticlesProd",
    tauJetSource = cms.InputTag( 'hltCaloStage1LegacyFormatDigis','tauJets' ),
    etHadSource = cms.InputTag( "hltCaloStage1LegacyFormatDigis" ),
    isoTauJetSource = cms.InputTag( 'hltCaloStage1LegacyFormatDigis','isoTauJets' ),
    etTotalSource = cms.InputTag( "hltCaloStage1LegacyFormatDigis" ),
    centralBxOnly = cms.bool( True ),
    centralJetSource = cms.InputTag( 'hltCaloStage1LegacyFormatDigis','cenJets' ),
    etMissSource = cms.InputTag( "hltCaloStage1LegacyFormatDigis" ),
    hfRingEtSumsSource = cms.InputTag( "hltCaloStage1LegacyFormatDigis" ),
    produceMuonParticles = cms.bool( True ),
    forwardJetSource = cms.InputTag( 'hltCaloStage1LegacyFormatDigis','forJets' ),
    ignoreHtMiss = cms.bool( False ),
    htMissSource = cms.InputTag( "hltCaloStage1LegacyFormatDigis" ),
    produceCaloParticles = cms.bool( True ),
    muonSource = cms.InputTag( "hltGtDigis" ),
    isolatedEmSource = cms.InputTag( 'hltCaloStage1LegacyFormatDigis','isoEm' ),
    nonIsolatedEmSource = cms.InputTag( 'hltCaloStage1LegacyFormatDigis','nonIsoEm' ),
    hfRingBitCountsSource = cms.InputTag( "hltCaloStage1LegacyFormatDigis" )
)
process.hltScalersRawToDigi = cms.EDProducer( "ScalersRawToDigi",
    scalersInputTag = cms.InputTag( "rawDataCollector" )
)
process.hltOnlineBeamSpot = cms.EDProducer( "BeamSpotOnlineProducer",
    maxZ = cms.double( 40.0 ),
    src = cms.InputTag( "hltScalersRawToDigi" ),
    gtEvmLabel = cms.InputTag( "" ),
    changeToCMSCoordinates = cms.bool( False ),
    setSigmaZ = cms.double( 0.0 ),
    maxRadius = cms.double( 2.0 )
)
process.hltL1sL1SingleIsoEG20er = cms.EDFilter( "HLTLevel1GTSeed",
    L1SeedsLogicalExpression = cms.string( "L1_SingleIsoEG20er" ),
    saveTags = cms.bool( True ),
    L1MuonCollectionTag = cms.InputTag( "hltL1extraParticles" ),
    L1UseL1TriggerObjectMaps = cms.bool( True ),
    L1UseAliasesForSeeding = cms.bool( True ),
    L1GtReadoutRecordTag = cms.InputTag( "hltGtDigis" ),
    L1CollectionsTag = cms.InputTag( "hltL1extraParticles" ),
    L1NrBxInEvent = cms.int32( 3 ),
    L1GtObjectMapTag = cms.InputTag( "hltL1GtObjectMap" ),
    L1TechTriggerSeeding = cms.bool( False )
)
process.hltPreEle22eta2p1WP75Gsf = cms.EDFilter( "HLTPrescaler",
    L1GtReadoutRecordTag = cms.InputTag( "hltGtDigis" ),
    offset = cms.uint32( 0 )
)
process.hltEcalDigis = cms.EDProducer( "EcalRawToDigi",
    orderedDCCIdList = cms.vint32( 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54 ),
    FedLabel = cms.InputTag( "listfeds" ),
    eventPut = cms.bool( True ),
    srpUnpacking = cms.bool( True ),
    syncCheck = cms.bool( True ),
    headerUnpacking = cms.bool( True ),
    feUnpacking = cms.bool( True ),
    orderedFedList = cms.vint32( 601, 602, 603, 604, 605, 606, 607, 608, 609, 610, 611, 612, 613, 614, 615, 616, 617, 618, 619, 620, 621, 622, 623, 624, 625, 626, 627, 628, 629, 630, 631, 632, 633, 634, 635, 636, 637, 638, 639, 640, 641, 642, 643, 644, 645, 646, 647, 648, 649, 650, 651, 652, 653, 654 ),
    tccUnpacking = cms.bool( True ),
    numbTriggerTSamples = cms.int32( 1 ),
    InputLabel = cms.InputTag( "rawDataCollector" ),
    numbXtalTSamples = cms.int32( 10 ),
    feIdCheck = cms.bool( True ),
    FEDs = cms.vint32( 601, 602, 603, 604, 605, 606, 607, 608, 609, 610, 611, 612, 613, 614, 615, 616, 617, 618, 619, 620, 621, 622, 623, 624, 625, 626, 627, 628, 629, 630, 631, 632, 633, 634, 635, 636, 637, 638, 639, 640, 641, 642, 643, 644, 645, 646, 647, 648, 649, 650, 651, 652, 653, 654 ),
    silentMode = cms.untracked.bool( True ),
    DoRegional = cms.bool( False ),
    forceToKeepFRData = cms.bool( False ),
    memUnpacking = cms.bool( True )
)
process.hltEcalPreshowerDigis = cms.EDProducer( "ESRawToDigi",
    sourceTag = cms.InputTag( "rawDataCollector" ),
    debugMode = cms.untracked.bool( False ),
    InstanceES = cms.string( "" ),
    ESdigiCollection = cms.string( "" ),
    LookupTable = cms.FileInPath( "EventFilter/ESDigiToRaw/data/ES_lookup_table.dat" )
)
process.hltEcalUncalibRecHit = cms.EDProducer( "EcalUncalibRecHitProducer",
    EEdigiCollection = cms.InputTag( 'hltEcalDigis','eeDigis' ),
    EBdigiCollection = cms.InputTag( 'hltEcalDigis','ebDigis' ),
    EEhitCollection = cms.string( "EcalUncalibRecHitsEE" ),
    EBhitCollection = cms.string( "EcalUncalibRecHitsEB" ),
    algo = cms.string( "EcalUncalibRecHitWorkerMultiFit" ),
    algoPSet = cms.PSet( 
      outOfTimeThresholdGain61pEB = cms.double( 5.0 ),
      EBtimeFitParameters = cms.vdouble( -2.015452, 3.130702, -12.3473, 41.88921, -82.83944, 91.01147, -50.35761, 11.05621 ),
      activeBXs = cms.vint32( -5, -4, -3, -2, -1, 0, 1, 2, 3, 4 ),
      amplitudeThresholdEE = cms.double( 10.0 ),
      EBtimeConstantTerm = cms.double( 0.6 ),
      EEtimeFitLimits_Lower = cms.double( 0.2 ),
      outOfTimeThresholdGain61pEE = cms.double( 1000.0 ),
      ebSpikeThreshold = cms.double( 1.042 ),
      EBtimeNconst = cms.double( 28.5 ),
      ampErrorCalculation = cms.bool( False ),
      kPoorRecoFlagEB = cms.bool( True ),
      EBtimeFitLimits_Lower = cms.double( 0.2 ),
      kPoorRecoFlagEE = cms.bool( False ),
      chi2ThreshEB_ = cms.double( 65.0 ),
      EEtimeFitParameters = cms.vdouble( -2.390548, 3.553628, -17.62341, 67.67538, -133.213, 140.7432, -75.41106, 16.20277 ),
      useLumiInfoRunHeader = cms.bool( False ),
      outOfTimeThresholdGain12mEE = cms.double( 1000.0 ),
      outOfTimeThresholdGain12mEB = cms.double( 5.0 ),
      EEtimeFitLimits_Upper = cms.double( 1.4 ),
      prefitMaxChiSqEB = cms.double( 100.0 ),
      EEamplitudeFitParameters = cms.vdouble( 1.89, 1.4 ),
      prefitMaxChiSqEE = cms.double( 10.0 ),
      EBamplitudeFitParameters = cms.vdouble( 1.138, 1.652 ),
      EBtimeFitLimits_Upper = cms.double( 1.4 ),
      timealgo = cms.string( "None" ),
      amplitudeThresholdEB = cms.double( 10.0 ),
      outOfTimeThresholdGain12pEE = cms.double( 1000.0 ),
      outOfTimeThresholdGain12pEB = cms.double( 5.0 ),
      EEtimeNconst = cms.double( 31.8 ),
      outOfTimeThresholdGain61mEB = cms.double( 5.0 ),
      outOfTimeThresholdGain61mEE = cms.double( 1000.0 ),
      EEtimeConstantTerm = cms.double( 1.0 ),
      chi2ThreshEE_ = cms.double( 50.0 ),
      doPrefitEE = cms.bool( True ),
      doPrefitEB = cms.bool( True )
    )
)
process.hltEcalDetIdToBeRecovered = cms.EDProducer( "EcalDetIdToBeRecoveredProducer",
    ebIntegrityChIdErrors = cms.InputTag( 'hltEcalDigis','EcalIntegrityChIdErrors' ),
    ebDetIdToBeRecovered = cms.string( "ebDetId" ),
    integrityTTIdErrors = cms.InputTag( 'hltEcalDigis','EcalIntegrityTTIdErrors' ),
    eeIntegrityGainErrors = cms.InputTag( 'hltEcalDigis','EcalIntegrityGainErrors' ),
    ebFEToBeRecovered = cms.string( "ebFE" ),
    ebIntegrityGainErrors = cms.InputTag( 'hltEcalDigis','EcalIntegrityGainErrors' ),
    eeDetIdToBeRecovered = cms.string( "eeDetId" ),
    eeIntegrityGainSwitchErrors = cms.InputTag( 'hltEcalDigis','EcalIntegrityGainSwitchErrors' ),
    eeIntegrityChIdErrors = cms.InputTag( 'hltEcalDigis','EcalIntegrityChIdErrors' ),
    ebIntegrityGainSwitchErrors = cms.InputTag( 'hltEcalDigis','EcalIntegrityGainSwitchErrors' ),
    ebSrFlagCollection = cms.InputTag( "hltEcalDigis" ),
    eeSrFlagCollection = cms.InputTag( "hltEcalDigis" ),
    integrityBlockSizeErrors = cms.InputTag( 'hltEcalDigis','EcalIntegrityBlockSizeErrors' ),
    eeFEToBeRecovered = cms.string( "eeFE" )
)
process.hltEcalRecHit = cms.EDProducer( "EcalRecHitProducer",
    recoverEEVFE = cms.bool( False ),
    EErechitCollection = cms.string( "EcalRecHitsEE" ),
    recoverEBIsolatedChannels = cms.bool( False ),
    recoverEBVFE = cms.bool( False ),
    laserCorrection = cms.bool( True ),
    EBLaserMIN = cms.double( 0.5 ),
    killDeadChannels = cms.bool( True ),
    dbStatusToBeExcludedEB = cms.vint32( 14, 78, 142 ),
    EEuncalibRecHitCollection = cms.InputTag( 'hltEcalUncalibRecHit','EcalUncalibRecHitsEE' ),
    EBLaserMAX = cms.double( 3.0 ),
    EELaserMIN = cms.double( 0.5 ),
    ebFEToBeRecovered = cms.InputTag( 'hltEcalDetIdToBeRecovered','ebFE' ),
    EELaserMAX = cms.double( 8.0 ),
    recoverEEIsolatedChannels = cms.bool( False ),
    eeDetIdToBeRecovered = cms.InputTag( 'hltEcalDetIdToBeRecovered','eeDetId' ),
    recoverEBFE = cms.bool( True ),
    algo = cms.string( "EcalRecHitWorkerSimple" ),
    ebDetIdToBeRecovered = cms.InputTag( 'hltEcalDetIdToBeRecovered','ebDetId' ),
    singleChannelRecoveryThreshold = cms.double( 8.0 ),
    ChannelStatusToBeExcluded = cms.vstring(  ),
    EBrechitCollection = cms.string( "EcalRecHitsEB" ),
    singleChannelRecoveryMethod = cms.string( "NeuralNetworks" ),
    recoverEEFE = cms.bool( True ),
    triggerPrimitiveDigiCollection = cms.InputTag( 'hltEcalDigis','EcalTriggerPrimitives' ),
    dbStatusToBeExcludedEE = cms.vint32( 14, 78, 142 ),
    flagsMapDBReco = cms.PSet( 
      kGood = cms.vstring( 'kOk',
        'kDAC',
        'kNoLaser',
        'kNoisy' ),
      kNeighboursRecovered = cms.vstring( 'kFixedG0',
        'kNonRespondingIsolated',
        'kDeadVFE' ),
      kDead = cms.vstring( 'kNoDataNoTP' ),
      kNoisy = cms.vstring( 'kNNoisy',
        'kFixedG6',
        'kFixedG1' ),
      kTowerRecovered = cms.vstring( 'kDeadFE' )
    ),
    EBuncalibRecHitCollection = cms.InputTag( 'hltEcalUncalibRecHit','EcalUncalibRecHitsEB' ),
    algoRecover = cms.string( "EcalRecHitWorkerRecover" ),
    eeFEToBeRecovered = cms.InputTag( 'hltEcalDetIdToBeRecovered','eeFE' ),
    cleaningConfig = cms.PSet( 
      e6e2thresh = cms.double( 0.04 ),
      tightenCrack_e6e2_double = cms.double( 3.0 ),
      e4e1Threshold_endcap = cms.double( 0.3 ),
      tightenCrack_e4e1_single = cms.double( 3.0 ),
      tightenCrack_e1_double = cms.double( 2.0 ),
      cThreshold_barrel = cms.double( 4.0 ),
      e4e1Threshold_barrel = cms.double( 0.08 ),
      tightenCrack_e1_single = cms.double( 2.0 ),
      e4e1_b_barrel = cms.double( -0.024 ),
      e4e1_a_barrel = cms.double( 0.04 ),
      ignoreOutOfTimeThresh = cms.double( 1.0E9 ),
      cThreshold_endcap = cms.double( 15.0 ),
      e4e1_b_endcap = cms.double( -0.0125 ),
      e4e1_a_endcap = cms.double( 0.02 ),
      cThreshold_double = cms.double( 10.0 )
    ),
    logWarningEtThreshold_EB_FE = cms.double( 50.0 ),
    logWarningEtThreshold_EE_FE = cms.double( 50.0 )
)
process.hltEcalPreshowerRecHit = cms.EDProducer( "ESRecHitProducer",
    ESRecoAlgo = cms.int32( 0 ),
    ESrechitCollection = cms.string( "EcalRecHitsES" ),
    algo = cms.string( "ESRecHitWorker" ),
    ESdigiCollection = cms.InputTag( "hltEcalPreshowerDigis" )
)
process.hltRechitInRegionsECAL = cms.EDProducer( "EgammaHLTRechitInRegionsProducer",
    l1LowerThr = cms.double( 5.0 ),
    doIsolated = cms.bool( True ),
    useUncalib = cms.bool( False ),
    regionEtaMargin = cms.double( 0.14 ),
    ecalhitLabels = cms.VInputTag( 'hltEcalRecHit:EcalRecHitsEB','hltEcalRecHit:EcalRecHitsEE' ),
    regionPhiMargin = cms.double( 0.4 ),
    l1TagNonIsolated = cms.InputTag( 'hltL1extraParticles','NonIsolated' ),
    l1UpperThr = cms.double( 999.0 ),
    l1LowerThrIgnoreIsolation = cms.double( 0.0 ),
    productLabels = cms.vstring( 'EcalRecHitsEB',
      'EcalRecHitsEE' ),
    l1TagIsolated = cms.InputTag( 'hltL1extraParticles','Isolated' )
)
process.hltRechitInRegionsES = cms.EDProducer( "EgammaHLTRechitInRegionsProducer",
    l1LowerThr = cms.double( 5.0 ),
    doIsolated = cms.bool( True ),
    useUncalib = cms.bool( False ),
    regionEtaMargin = cms.double( 0.14 ),
    ecalhitLabels = cms.VInputTag( 'hltEcalPreshowerRecHit:EcalRecHitsES' ),
    regionPhiMargin = cms.double( 0.4 ),
    l1TagNonIsolated = cms.InputTag( 'hltL1extraParticles','NonIsolated' ),
    l1UpperThr = cms.double( 999.0 ),
    l1LowerThrIgnoreIsolation = cms.double( 0.0 ),
    productLabels = cms.vstring( 'EcalRecHitsES' ),
    l1TagIsolated = cms.InputTag( 'hltL1extraParticles','Isolated' )
)
process.hltParticleFlowRecHitECALL1Seeded = cms.EDProducer( "PFRecHitProducer",
    producers = cms.VPSet( 
      cms.PSet(  src = cms.InputTag( 'hltRechitInRegionsECAL','EcalRecHitsEB' ),
        qualityTests = cms.VPSet( 
          cms.PSet(  threshold = cms.double( 0.08 ),
            name = cms.string( "PFRecHitQTestThreshold" )
          ),
          cms.PSet(  timingCleaning = cms.bool( True ),
            topologicalCleaning = cms.bool( True ),
            cleaningThreshold = cms.double( 2.0 ),
            skipTTRecoveredHits = cms.bool( True ),
            name = cms.string( "PFRecHitQTestECAL" )
          )
        ),
        name = cms.string( "PFEBRecHitCreator" )
      ),
      cms.PSet(  src = cms.InputTag( 'hltRechitInRegionsECAL','EcalRecHitsEE' ),
        qualityTests = cms.VPSet( 
          cms.PSet(  threshold = cms.double( 0.3 ),
            name = cms.string( "PFRecHitQTestThreshold" )
          ),
          cms.PSet(  timingCleaning = cms.bool( True ),
            topologicalCleaning = cms.bool( True ),
            cleaningThreshold = cms.double( 2.0 ),
            skipTTRecoveredHits = cms.bool( True ),
            name = cms.string( "PFRecHitQTestECAL" )
          )
        ),
        name = cms.string( "PFEERecHitCreator" )
      )
    ),
    navigator = cms.PSet( 
      barrel = cms.PSet(  ),
      endcap = cms.PSet(  ),
      name = cms.string( "PFRecHitECALNavigator" )
    )
)
process.hltParticleFlowRecHitPSL1Seeded = cms.EDProducer( "PFRecHitProducer",
    producers = cms.VPSet( 
      cms.PSet(  src = cms.InputTag( 'hltRechitInRegionsES','EcalRecHitsES' ),
        qualityTests = cms.VPSet( 
          cms.PSet(  threshold = cms.double( 7.0E-6 ),
            name = cms.string( "PFRecHitQTestThreshold" )
          )
        ),
        name = cms.string( "PFPSRecHitCreator" )
      )
    ),
    navigator = cms.PSet(  name = cms.string( "PFRecHitPreshowerNavigator" ) )
)
process.hltParticleFlowClusterPSL1Seeded = cms.EDProducer( "PFClusterProducer",
    pfClusterBuilder = cms.PSet( 
      minFracTot = cms.double( 1.0E-20 ),
      positionCalc = cms.PSet( 
        minFractionInCalc = cms.double( 1.0E-9 ),
        logWeightDenominator = cms.double( 6.0E-5 ),
        minAllowedNormalization = cms.double( 1.0E-9 ),
        posCalcNCrystals = cms.int32( -1 ),
        algoName = cms.string( "Basic2DGenericPFlowPositionCalc" )
      ),
      maxIterations = cms.uint32( 50 ),
      stoppingTolerance = cms.double( 1.0E-8 ),
      minFractionToKeep = cms.double( 1.0E-7 ),
      excludeOtherSeeds = cms.bool( True ),
      showerSigma = cms.double( 0.3 ),
      recHitEnergyNorms = cms.VPSet( 
        cms.PSet(  detector = cms.string( "PS1" ),
          recHitEnergyNorm = cms.double( 6.0E-5 )
        ),
        cms.PSet(  detector = cms.string( "PS2" ),
          recHitEnergyNorm = cms.double( 6.0E-5 )
        )
      ),
      algoName = cms.string( "Basic2DGenericPFlowClusterizer" )
    ),
    positionReCalc = cms.PSet(  ),
    initialClusteringStep = cms.PSet( 
      thresholdsByDetector = cms.VPSet( 
        cms.PSet(  gatheringThreshold = cms.double( 6.0E-5 ),
          detector = cms.string( "PS1" ),
          gatheringThresholdPt = cms.double( 0.0 )
        ),
        cms.PSet(  gatheringThreshold = cms.double( 6.0E-5 ),
          detector = cms.string( "PS2" ),
          gatheringThresholdPt = cms.double( 0.0 )
        )
      ),
      useCornerCells = cms.bool( False ),
      algoName = cms.string( "Basic2DGenericTopoClusterizer" )
    ),
    energyCorrector = cms.PSet(  ),
    recHitCleaners = cms.VPSet( 
    ),
    seedFinder = cms.PSet( 
      nNeighbours = cms.int32( 4 ),
      thresholdsByDetector = cms.VPSet( 
        cms.PSet(  seedingThreshold = cms.double( 1.2E-4 ),
          seedingThresholdPt = cms.double( 0.0 ),
          detector = cms.string( "PS1" )
        ),
        cms.PSet(  seedingThreshold = cms.double( 1.2E-4 ),
          seedingThresholdPt = cms.double( 0.0 ),
          detector = cms.string( "PS2" )
        )
      ),
      algoName = cms.string( "LocalMaximumSeedFinder" )
    ),
    recHitsSource = cms.InputTag( "hltParticleFlowRecHitPSL1Seeded" )
)
process.hltParticleFlowClusterECALUncorrectedL1Seeded = cms.EDProducer( "PFClusterProducer",
    pfClusterBuilder = cms.PSet( 
      positionCalc = cms.PSet( 
        minFractionInCalc = cms.double( 1.0E-9 ),
        logWeightDenominator = cms.double( 0.08 ),
        minAllowedNormalization = cms.double( 1.0E-9 ),
        posCalcNCrystals = cms.int32( 9 ),
        algoName = cms.string( "Basic2DGenericPFlowPositionCalc" )
      ),
      minFracTot = cms.double( 1.0E-20 ),
      positionCalcForConvergence = cms.PSet( 
        minFractionInCalc = cms.double( 0.0 ),
        W0 = cms.double( 4.2 ),
        minAllowedNormalization = cms.double( 0.0 ),
        T0_EB = cms.double( 7.4 ),
        X0 = cms.double( 0.89 ),
        T0_ES = cms.double( 1.2 ),
        T0_EE = cms.double( 3.1 ),
        algoName = cms.string( "ECAL2DPositionCalcWithDepthCorr" )
      ),
      maxIterations = cms.uint32( 50 ),
      stoppingTolerance = cms.double( 1.0E-8 ),
      minFractionToKeep = cms.double( 1.0E-7 ),
      excludeOtherSeeds = cms.bool( True ),
      showerSigma = cms.double( 1.5 ),
      recHitEnergyNorms = cms.VPSet( 
        cms.PSet(  detector = cms.string( "ECAL_BARREL" ),
          recHitEnergyNorm = cms.double( 0.08 )
        ),
        cms.PSet(  detector = cms.string( "ECAL_ENDCAP" ),
          recHitEnergyNorm = cms.double( 0.3 )
        )
      ),
      algoName = cms.string( "Basic2DGenericPFlowClusterizer" ),
      allCellsPositionCalc = cms.PSet( 
        minFractionInCalc = cms.double( 1.0E-9 ),
        logWeightDenominator = cms.double( 0.08 ),
        minAllowedNormalization = cms.double( 1.0E-9 ),
        posCalcNCrystals = cms.int32( -1 ),
        algoName = cms.string( "Basic2DGenericPFlowPositionCalc" )
      )
    ),
    positionReCalc = cms.PSet( 
      minFractionInCalc = cms.double( 0.0 ),
      W0 = cms.double( 4.2 ),
      minAllowedNormalization = cms.double( 0.0 ),
      T0_EB = cms.double( 7.4 ),
      X0 = cms.double( 0.89 ),
      T0_ES = cms.double( 1.2 ),
      T0_EE = cms.double( 3.1 ),
      algoName = cms.string( "ECAL2DPositionCalcWithDepthCorr" )
    ),
    initialClusteringStep = cms.PSet( 
      thresholdsByDetector = cms.VPSet( 
        cms.PSet(  gatheringThreshold = cms.double( 0.08 ),
          detector = cms.string( "ECAL_BARREL" ),
          gatheringThresholdPt = cms.double( 0.0 )
        ),
        cms.PSet(  gatheringThreshold = cms.double( 0.3 ),
          detector = cms.string( "ECAL_ENDCAP" ),
          gatheringThresholdPt = cms.double( 0.0 )
        )
      ),
      useCornerCells = cms.bool( True ),
      algoName = cms.string( "Basic2DGenericTopoClusterizer" )
    ),
    energyCorrector = cms.PSet(  ),
    recHitCleaners = cms.VPSet( 
      cms.PSet(  cleaningByDetector = cms.VPSet( 
  cms.PSet(  doubleSpikeS6S2 = cms.double( 0.04 ),
    fractionThresholdModifier = cms.double( 3.0 ),
    doubleSpikeThresh = cms.double( 10.0 ),
    minS4S1_b = cms.double( -0.024 ),
    singleSpikeThresh = cms.double( 4.0 ),
    detector = cms.string( "ECAL_BARREL" ),
    minS4S1_a = cms.double( 0.04 ),
    energyThresholdModifier = cms.double( 2.0 )
  ),
  cms.PSet(  doubleSpikeS6S2 = cms.double( -1.0 ),
    fractionThresholdModifier = cms.double( 3.0 ),
    doubleSpikeThresh = cms.double( 1.0E9 ),
    minS4S1_b = cms.double( -0.0125 ),
    singleSpikeThresh = cms.double( 15.0 ),
    detector = cms.string( "ECAL_ENDCAP" ),
    minS4S1_a = cms.double( 0.02 ),
    energyThresholdModifier = cms.double( 2.0 )
  )
),
        algoName = cms.string( "SpikeAndDoubleSpikeCleaner" )
      )
    ),
    seedFinder = cms.PSet( 
      nNeighbours = cms.int32( 8 ),
      thresholdsByDetector = cms.VPSet( 
        cms.PSet(  seedingThreshold = cms.double( 0.6 ),
          seedingThresholdPt = cms.double( 0.15 ),
          detector = cms.string( "ECAL_ENDCAP" )
        ),
        cms.PSet(  seedingThreshold = cms.double( 0.23 ),
          seedingThresholdPt = cms.double( 0.0 ),
          detector = cms.string( "ECAL_BARREL" )
        )
      ),
      algoName = cms.string( "LocalMaximumSeedFinder" )
    ),
    recHitsSource = cms.InputTag( "hltParticleFlowRecHitECALL1Seeded" )
)
process.hltParticleFlowClusterECALL1Seeded = cms.EDProducer( "CorrectedECALPFClusterProducer",
    inputPS = cms.InputTag( "hltParticleFlowClusterPSL1Seeded" ),
    minimumPSEnergy = cms.double( 0.0 ),
    energyCorrector = cms.PSet( 
      applyCrackCorrections = cms.bool( False ),
      algoName = cms.string( "PFClusterEMEnergyCorrector" )
    ),
    inputECAL = cms.InputTag( "hltParticleFlowClusterECALUncorrectedL1Seeded" )
)
process.hltParticleFlowSuperClusterECALL1Seeded = cms.EDProducer( "PFECALSuperClusterProducer",
    PFSuperClusterCollectionEndcap = cms.string( "hltParticleFlowSuperClusterECALEndcap" ),
    doSatelliteClusterMerge = cms.bool( False ),
    BeamSpot = cms.InputTag( "hltOnlineBeamSpot" ),
    PFBasicClusterCollectionBarrel = cms.string( "hltParticleFlowBasicClusterECALBarrel" ),
    useRegression = cms.bool( False ),
    satelliteMajorityFraction = cms.double( 0.5 ),
    thresh_PFClusterEndcap = cms.double( 4.0 ),
    ESAssociation = cms.InputTag( "hltParticleFlowClusterECALL1Seeded" ),
    PFBasicClusterCollectionPreshower = cms.string( "hltParticleFlowBasicClusterECALPreshower" ),
    use_preshower = cms.bool( True ),
    thresh_PFClusterBarrel = cms.double( 4.0 ),
    thresh_SCEt = cms.double( 4.0 ),
    etawidth_SuperClusterEndcap = cms.double( 0.04 ),
    phiwidth_SuperClusterEndcap = cms.double( 0.6 ),
    verbose = cms.untracked.bool( False ),
    useDynamicDPhiWindow = cms.bool( True ),
    PFSuperClusterCollectionBarrel = cms.string( "hltParticleFlowSuperClusterECALBarrel" ),
    regressionConfig = cms.PSet( 
      regressionKeyEE = cms.string( "pfscecal_EECorrection_offline" ),
      ecalRecHitsEE = cms.InputTag( 'hltRechitInRegionsECAL','EcalRecHitsEE' ),
      ecalRecHitsEB = cms.InputTag( 'hltRechitInRegionsECAL','EcalRecHitsEB' ),
      regressionKeyEB = cms.string( "pfscecal_EBCorrection_offline" ),
      vertexCollection = cms.InputTag( "offlinePrimaryVertices" )
    ),
    applyCrackCorrections = cms.bool( False ),
    satelliteClusterSeedThreshold = cms.double( 50.0 ),
    etawidth_SuperClusterBarrel = cms.double( 0.04 ),
    PFBasicClusterCollectionEndcap = cms.string( "hltParticleFlowBasicClusterECALEndcap" ),
    PFClusters = cms.InputTag( "hltParticleFlowClusterECALL1Seeded" ),
    thresh_PFClusterSeedBarrel = cms.double( 4.0 ),
    ClusteringType = cms.string( "Mustache" ),
    EnergyWeight = cms.string( "Raw" ),
    thresh_PFClusterSeedEndcap = cms.double( 4.0 ),
    phiwidth_SuperClusterBarrel = cms.double( 0.6 ),
    thresh_PFClusterES = cms.double( 5.0 ),
    seedThresholdIsET = cms.bool( True ),
    PFSuperClusterCollectionEndcapWithPreshower = cms.string( "hltParticleFlowSuperClusterECALEndcapWithPreshower" )
)
process.hltEgammaCandidates = cms.EDProducer( "EgammaHLTRecoEcalCandidateProducers",
    scIslandEndcapProducer = cms.InputTag( 'hltParticleFlowSuperClusterECALL1Seeded','hltParticleFlowSuperClusterECALEndcapWithPreshower' ),
    scHybridBarrelProducer = cms.InputTag( 'hltParticleFlowSuperClusterECALL1Seeded','hltParticleFlowSuperClusterECALBarrel' ),
    recoEcalCandidateCollection = cms.string( "" )
)
process.hltEGL1SingleIsoEG20erFilter = cms.EDFilter( "HLTEgammaL1MatchFilterRegional",
    doIsolated = cms.bool( False ),
    endcap_end = cms.double( 2.17 ),
    saveTags = cms.bool( False ),
    region_eta_size_ecap = cms.double( 1.0 ),
    barrel_end = cms.double( 1.4791 ),
    l1IsolatedTag = cms.InputTag( 'hltL1extraParticles','Isolated' ),
    candIsolatedTag = cms.InputTag( "hltEgammaCandidates" ),
    region_phi_size = cms.double( 1.044 ),
    region_eta_size = cms.double( 0.522 ),
    L1SeedFilterTag = cms.InputTag( "hltL1sL1SingleIsoEG20er" ),
    candNonIsolatedTag = cms.InputTag( "" ),
    l1NonIsolatedTag = cms.InputTag( 'hltL1extraParticles','NonIsolated' ),
    ncandcut = cms.int32( 1 )
)
process.hltSingleEG22EtFilter = cms.EDFilter( "HLTEgammaEtFilter",
    saveTags = cms.bool( False ),
    L1NonIsoCand = cms.InputTag( "" ),
    relaxed = cms.untracked.bool( False ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    inputTag = cms.InputTag( "hltEGL1SingleIsoEG20erFilter" ),
    etcutEB = cms.double( 22.0 ),
    etcutEE = cms.double( 22.0 ),
    ncandcut = cms.int32( 1 )
)
process.hltEgammaClusterShape = cms.EDProducer( "EgammaHLTClusterShapeProducer",
    recoEcalCandidateProducer = cms.InputTag( "hltEgammaCandidates" ),
    ecalRechitEB = cms.InputTag( 'hltRechitInRegionsECAL','EcalRecHitsEB' ),
    ecalRechitEE = cms.InputTag( 'hltRechitInRegionsECAL','EcalRecHitsEE' ),
    isIeta = cms.bool( True )
)
process.hltSingleEle22WP75ClusterShapeFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.031 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.011 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( False ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaClusterShape','sigmaIEtaIEta5x5' ),
    candTag = cms.InputTag( "hltSingleEG22EtFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltHcalDigis = cms.EDProducer( "HcalRawToDigi",
    ExpectedOrbitMessageTime = cms.untracked.int32( -1 ),
    FilterDataQuality = cms.bool( True ),
    silent = cms.untracked.bool( True ),
    HcalFirstFED = cms.untracked.int32( 700 ),
    InputLabel = cms.InputTag( "rawDataCollector" ),
    ComplainEmptyData = cms.untracked.bool( False ),
    UnpackCalib = cms.untracked.bool( True ),
    FEDs = cms.untracked.vint32(  ),
    UnpackerMode = cms.untracked.int32( 0 ),
    UnpackTTP = cms.untracked.bool( False ),
    lastSample = cms.int32( 9 ),
    UnpackZDC = cms.untracked.bool( True ),
    firstSample = cms.int32( 0 )
)
process.hltHbhereco = cms.EDProducer( "HcalHitReconstructor",
    digiTimeFromDB = cms.bool( True ),
    mcOOTCorrectionName = cms.string( "" ),
    S9S1stat = cms.PSet(  ),
    saturationParameters = cms.PSet(  maxADCvalue = cms.int32( 127 ) ),
    tsFromDB = cms.bool( True ),
    samplesToAdd = cms.int32( 4 ),
    mcOOTCorrectionCategory = cms.string( "MC" ),
    dataOOTCorrectionName = cms.string( "" ),
    puCorrMethod = cms.int32( 0 ),
    correctionPhaseNS = cms.double( 13.0 ),
    HFInWindowStat = cms.PSet(  ),
    digiLabel = cms.InputTag( "hltHcalDigis" ),
    setHSCPFlags = cms.bool( False ),
    firstAuxTS = cms.int32( 4 ),
    digistat = cms.PSet(  ),
    hfTimingTrustParameters = cms.PSet(  ),
    PETstat = cms.PSet(  ),
    setSaturationFlags = cms.bool( False ),
    setNegativeFlags = cms.bool( False ),
    useLeakCorrection = cms.bool( False ),
    setTimingTrustFlags = cms.bool( False ),
    S8S1stat = cms.PSet(  ),
    correctForPhaseContainment = cms.bool( True ),
    correctForTimeslew = cms.bool( True ),
    setNoiseFlags = cms.bool( False ),
    correctTiming = cms.bool( False ),
    setPulseShapeFlags = cms.bool( False ),
    Subdetector = cms.string( "HBHE" ),
    dataOOTCorrectionCategory = cms.string( "Data" ),
    dropZSmarkedPassed = cms.bool( True ),
    recoParamsFromDB = cms.bool( True ),
    firstSample = cms.int32( 4 ),
    setTimingShapedCutsFlags = cms.bool( False ),
    pulseJitter = cms.double( 1.0 ),
    chargeMax = cms.double( 6.0 ),
    negativeParameters = cms.PSet( 
      TS4TS5ChargeThreshold = cms.double( 70.0 ),
      Cut = cms.vdouble( -50.0, -100.0, -100.0, -100.0, -100.0, -100.0 ),
      Last = cms.int32( 6 ),
      MinimumChargeThreshold = cms.double( 20.0 ),
      Threshold = cms.vdouble( 100.0, 120.0, 160.0, 200.0, 300.0, 500.0 ),
      First = cms.int32( 4 )
    ),
    timeMin = cms.double( -15.0 ),
    ts4chi2 = cms.double( 15.0 ),
    ts345chi2 = cms.double( 100.0 ),
    applyTimeSlew = cms.bool( True ),
    applyTimeConstraint = cms.bool( True ),
    applyPulseJitter = cms.bool( False ),
    timingshapedcutsParameters = cms.PSet( 
      ignorelowest = cms.bool( True ),
      win_offset = cms.double( 0.0 ),
      ignorehighest = cms.bool( False ),
      win_gain = cms.double( 1.0 ),
      tfilterEnvelope = cms.vdouble( 4.0, 12.04, 13.0, 10.56, 23.5, 8.82, 37.0, 7.38, 56.0, 6.3, 81.0, 5.64, 114.5, 5.44, 175.5, 5.38, 350.5, 5.14 )
    ),
    ts3chi2 = cms.double( 5.0 ),
    ts4Min = cms.double( 5.0 ),
    pulseShapeParameters = cms.PSet(  ),
    noise = cms.double( 1.0 ),
    applyPedConstraint = cms.bool( True ),
    applyUnconstrainedFit = cms.bool( False ),
    ts4Max = cms.double( 500.0 ),
    meanTime = cms.double( -2.5 ),
    flagParameters = cms.PSet( 
      nominalPedestal = cms.double( 3.0 ),
      hitMultiplicityThreshold = cms.int32( 17 ),
      hitEnergyMinimum = cms.double( 1.0 ),
      pulseShapeParameterSets = cms.VPSet( 
        cms.PSet(  pulseShapeParameters = cms.vdouble( 0.0, 100.0, -50.0, 0.0, -15.0, 0.15 )        ),
        cms.PSet(  pulseShapeParameters = cms.vdouble( 100.0, 2000.0, -50.0, 0.0, -5.0, 0.05 )        ),
        cms.PSet(  pulseShapeParameters = cms.vdouble( 2000.0, 1000000.0, -50.0, 0.0, 95.0, 0.0 )        ),
        cms.PSet(  pulseShapeParameters = cms.vdouble( -1000000.0, 1000000.0, 45.0, 0.1, 1000000.0, 0.0 )        )
      )
    ),
    fitTimes = cms.int32( 1 ),
    timeMax = cms.double( 10.0 ),
    timeSigma = cms.double( 5.0 ),
    pedSigma = cms.double( 0.5 ),
    meanPed = cms.double( 0.0 ),
    hscpParameters = cms.PSet( 
      slopeMax = cms.double( -0.6 ),
      r1Max = cms.double( 1.0 ),
      r1Min = cms.double( 0.15 ),
      TimingEnergyThreshold = cms.double( 30.0 ),
      slopeMin = cms.double( -1.5 ),
      outerMin = cms.double( 0.0 ),
      outerMax = cms.double( 0.1 ),
      fracLeaderMin = cms.double( 0.4 ),
      r2Min = cms.double( 0.1 ),
      r2Max = cms.double( 0.5 ),
      fracLeaderMax = cms.double( 0.7 )
    )
)
process.hltHfreco = cms.EDProducer( "HcalHitReconstructor",
    digiTimeFromDB = cms.bool( True ),
    mcOOTCorrectionName = cms.string( "" ),
    S9S1stat = cms.PSet( 
      longETParams = cms.vdouble( 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 ),
      shortEnergyParams = cms.vdouble( 35.1773, 35.37, 35.7933, 36.4472, 37.3317, 38.4468, 39.7925, 41.3688, 43.1757, 45.2132, 47.4813, 49.98, 52.7093 ),
      flagsToSkip = cms.int32( 24 ),
      shortETParams = cms.vdouble( 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 ),
      short_optimumSlope = cms.vdouble( -99999.0, 0.0164905, 0.0238698, 0.0321383, 0.041296, 0.0513428, 0.0622789, 0.0741041, 0.0868186, 0.100422, 0.135313, 0.136289, 0.0589927 ),
      longEnergyParams = cms.vdouble( 43.5, 45.7, 48.32, 51.36, 54.82, 58.7, 63.0, 67.72, 72.86, 78.42, 84.4, 90.8, 97.62 ),
      long_optimumSlope = cms.vdouble( -99999.0, 0.0164905, 0.0238698, 0.0321383, 0.041296, 0.0513428, 0.0622789, 0.0741041, 0.0868186, 0.100422, 0.135313, 0.136289, 0.0589927 ),
      isS8S1 = cms.bool( False ),
      HcalAcceptSeverityLevel = cms.int32( 9 )
    ),
    saturationParameters = cms.PSet(  maxADCvalue = cms.int32( 127 ) ),
    tsFromDB = cms.bool( True ),
    samplesToAdd = cms.int32( 2 ),
    mcOOTCorrectionCategory = cms.string( "MC" ),
    dataOOTCorrectionName = cms.string( "" ),
    puCorrMethod = cms.int32( 0 ),
    correctionPhaseNS = cms.double( 13.0 ),
    HFInWindowStat = cms.PSet( 
      hflongEthresh = cms.double( 40.0 ),
      hflongMinWindowTime = cms.vdouble( -10.0 ),
      hfshortEthresh = cms.double( 40.0 ),
      hflongMaxWindowTime = cms.vdouble( 10.0 ),
      hfshortMaxWindowTime = cms.vdouble( 10.0 ),
      hfshortMinWindowTime = cms.vdouble( -12.0 )
    ),
    digiLabel = cms.InputTag( "hltHcalDigis" ),
    setHSCPFlags = cms.bool( False ),
    firstAuxTS = cms.int32( 1 ),
    digistat = cms.PSet( 
      HFdigiflagFirstSample = cms.int32( 1 ),
      HFdigiflagMinEthreshold = cms.double( 40.0 ),
      HFdigiflagSamplesToAdd = cms.int32( 3 ),
      HFdigiflagExpectedPeak = cms.int32( 2 ),
      HFdigiflagCoef = cms.vdouble( 0.93, -0.012667, -0.38275 )
    ),
    hfTimingTrustParameters = cms.PSet( 
      hfTimingTrustLevel2 = cms.int32( 4 ),
      hfTimingTrustLevel1 = cms.int32( 1 )
    ),
    PETstat = cms.PSet( 
      longETParams = cms.vdouble( 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 ),
      short_R_29 = cms.vdouble( 0.8 ),
      shortEnergyParams = cms.vdouble( 35.1773, 35.37, 35.7933, 36.4472, 37.3317, 38.4468, 39.7925, 41.3688, 43.1757, 45.2132, 47.4813, 49.98, 52.7093 ),
      flagsToSkip = cms.int32( 0 ),
      short_R = cms.vdouble( 0.8 ),
      shortETParams = cms.vdouble( 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 ),
      long_R_29 = cms.vdouble( 0.8 ),
      longEnergyParams = cms.vdouble( 43.5, 45.7, 48.32, 51.36, 54.82, 58.7, 63.0, 67.72, 72.86, 78.42, 84.4, 90.8, 97.62 ),
      long_R = cms.vdouble( 0.98 ),
      HcalAcceptSeverityLevel = cms.int32( 9 )
    ),
    setSaturationFlags = cms.bool( False ),
    setNegativeFlags = cms.bool( False ),
    useLeakCorrection = cms.bool( False ),
    setTimingTrustFlags = cms.bool( False ),
    S8S1stat = cms.PSet( 
      longETParams = cms.vdouble( 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 ),
      shortEnergyParams = cms.vdouble( 40.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0 ),
      flagsToSkip = cms.int32( 16 ),
      shortETParams = cms.vdouble( 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 ),
      short_optimumSlope = cms.vdouble( 0.3, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1 ),
      longEnergyParams = cms.vdouble( 40.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0 ),
      long_optimumSlope = cms.vdouble( 0.3, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1 ),
      isS8S1 = cms.bool( True ),
      HcalAcceptSeverityLevel = cms.int32( 9 )
    ),
    correctForPhaseContainment = cms.bool( False ),
    correctForTimeslew = cms.bool( False ),
    setNoiseFlags = cms.bool( True ),
    correctTiming = cms.bool( False ),
    setPulseShapeFlags = cms.bool( False ),
    Subdetector = cms.string( "HF" ),
    dataOOTCorrectionCategory = cms.string( "Data" ),
    dropZSmarkedPassed = cms.bool( True ),
    recoParamsFromDB = cms.bool( True ),
    firstSample = cms.int32( 2 ),
    setTimingShapedCutsFlags = cms.bool( False ),
    pulseJitter = cms.double( 1.0 ),
    chargeMax = cms.double( 6.0 ),
    negativeParameters = cms.PSet( 
      TS4TS5ChargeThreshold = cms.double( 70.0 ),
      Cut = cms.vdouble( -50.0, -100.0, -100.0, -100.0, -100.0, -100.0 ),
      Last = cms.int32( 6 ),
      MinimumChargeThreshold = cms.double( 20.0 ),
      Threshold = cms.vdouble( 100.0, 120.0, 160.0, 200.0, 300.0, 500.0 ),
      First = cms.int32( 4 )
    ),
    timeMin = cms.double( -15.0 ),
    ts4chi2 = cms.double( 15.0 ),
    ts345chi2 = cms.double( 100.0 ),
    applyTimeSlew = cms.bool( True ),
    applyTimeConstraint = cms.bool( True ),
    applyPulseJitter = cms.bool( False ),
    timingshapedcutsParameters = cms.PSet(  ),
    ts3chi2 = cms.double( 5.0 ),
    ts4Min = cms.double( 5.0 ),
    pulseShapeParameters = cms.PSet(  ),
    noise = cms.double( 1.0 ),
    applyPedConstraint = cms.bool( True ),
    applyUnconstrainedFit = cms.bool( False ),
    ts4Max = cms.double( 500.0 ),
    meanTime = cms.double( -2.5 ),
    flagParameters = cms.PSet(  ),
    fitTimes = cms.int32( 1 ),
    timeMax = cms.double( 10.0 ),
    timeSigma = cms.double( 5.0 ),
    pedSigma = cms.double( 0.5 ),
    meanPed = cms.double( 0.0 ),
    hscpParameters = cms.PSet(  )
)
process.hltHoreco = cms.EDProducer( "HcalHitReconstructor",
    digiTimeFromDB = cms.bool( True ),
    mcOOTCorrectionName = cms.string( "" ),
    S9S1stat = cms.PSet(  ),
    saturationParameters = cms.PSet(  maxADCvalue = cms.int32( 127 ) ),
    tsFromDB = cms.bool( True ),
    samplesToAdd = cms.int32( 4 ),
    mcOOTCorrectionCategory = cms.string( "MC" ),
    dataOOTCorrectionName = cms.string( "" ),
    puCorrMethod = cms.int32( 0 ),
    correctionPhaseNS = cms.double( 13.0 ),
    HFInWindowStat = cms.PSet(  ),
    digiLabel = cms.InputTag( "hltHcalDigis" ),
    setHSCPFlags = cms.bool( False ),
    firstAuxTS = cms.int32( 4 ),
    digistat = cms.PSet(  ),
    hfTimingTrustParameters = cms.PSet(  ),
    PETstat = cms.PSet(  ),
    setSaturationFlags = cms.bool( False ),
    setNegativeFlags = cms.bool( False ),
    useLeakCorrection = cms.bool( False ),
    setTimingTrustFlags = cms.bool( False ),
    S8S1stat = cms.PSet(  ),
    correctForPhaseContainment = cms.bool( True ),
    correctForTimeslew = cms.bool( True ),
    setNoiseFlags = cms.bool( False ),
    correctTiming = cms.bool( False ),
    setPulseShapeFlags = cms.bool( False ),
    Subdetector = cms.string( "HO" ),
    dataOOTCorrectionCategory = cms.string( "Data" ),
    dropZSmarkedPassed = cms.bool( True ),
    recoParamsFromDB = cms.bool( True ),
    firstSample = cms.int32( 4 ),
    setTimingShapedCutsFlags = cms.bool( False ),
    pulseJitter = cms.double( 1.0 ),
    chargeMax = cms.double( 6.0 ),
    negativeParameters = cms.PSet( 
      TS4TS5ChargeThreshold = cms.double( 70.0 ),
      Cut = cms.vdouble( -50.0, -100.0, -100.0, -100.0, -100.0, -100.0 ),
      Last = cms.int32( 6 ),
      MinimumChargeThreshold = cms.double( 20.0 ),
      Threshold = cms.vdouble( 100.0, 120.0, 160.0, 200.0, 300.0, 500.0 ),
      First = cms.int32( 4 )
    ),
    timeMin = cms.double( -15.0 ),
    ts4chi2 = cms.double( 15.0 ),
    ts345chi2 = cms.double( 100.0 ),
    applyTimeSlew = cms.bool( True ),
    applyTimeConstraint = cms.bool( True ),
    applyPulseJitter = cms.bool( False ),
    timingshapedcutsParameters = cms.PSet(  ),
    ts3chi2 = cms.double( 5.0 ),
    ts4Min = cms.double( 5.0 ),
    pulseShapeParameters = cms.PSet(  ),
    noise = cms.double( 1.0 ),
    applyPedConstraint = cms.bool( True ),
    applyUnconstrainedFit = cms.bool( False ),
    ts4Max = cms.double( 500.0 ),
    meanTime = cms.double( -2.5 ),
    flagParameters = cms.PSet(  ),
    fitTimes = cms.int32( 1 ),
    timeMax = cms.double( 10.0 ),
    timeSigma = cms.double( 5.0 ),
    pedSigma = cms.double( 0.5 ),
    meanPed = cms.double( 0.0 ),
    hscpParameters = cms.PSet(  )
)
process.hltTowerMakerForAll = cms.EDProducer( "CaloTowersCreator",
    EBSumThreshold = cms.double( 0.2 ),
    MomHBDepth = cms.double( 0.2 ),
    UseEtEBTreshold = cms.bool( False ),
    hfInput = cms.InputTag( "hltHfreco" ),
    AllowMissingInputs = cms.bool( False ),
    MomEEDepth = cms.double( 0.0 ),
    EESumThreshold = cms.double( 0.45 ),
    HBGrid = cms.vdouble(  ),
    HcalAcceptSeverityLevelForRejectedHit = cms.uint32( 9999 ),
    HBThreshold = cms.double( 0.7 ),
    EcalSeveritiesToBeUsedInBadTowers = cms.vstring(  ),
    UseEcalRecoveredHits = cms.bool( False ),
    MomConstrMethod = cms.int32( 1 ),
    MomHEDepth = cms.double( 0.4 ),
    HcalThreshold = cms.double( -1000.0 ),
    HF2Weights = cms.vdouble(  ),
    HOWeights = cms.vdouble(  ),
    EEGrid = cms.vdouble(  ),
    UseSymEBTreshold = cms.bool( False ),
    EEWeights = cms.vdouble(  ),
    EEWeight = cms.double( 1.0 ),
    UseHO = cms.bool( False ),
    HBWeights = cms.vdouble(  ),
    HF1Weight = cms.double( 1.0 ),
    HF2Grid = cms.vdouble(  ),
    HEDWeights = cms.vdouble(  ),
    HEDGrid = cms.vdouble(  ),
    EBWeight = cms.double( 1.0 ),
    HF1Grid = cms.vdouble(  ),
    EBWeights = cms.vdouble(  ),
    HOWeight = cms.double( 1.0E-99 ),
    HESWeight = cms.double( 1.0 ),
    HESThreshold = cms.double( 0.8 ),
    hbheInput = cms.InputTag( "hltHbhereco" ),
    HF2Weight = cms.double( 1.0 ),
    HF2Threshold = cms.double( 0.85 ),
    HcalAcceptSeverityLevel = cms.uint32( 9 ),
    EEThreshold = cms.double( 0.3 ),
    HOThresholdPlus1 = cms.double( 3.5 ),
    HOThresholdPlus2 = cms.double( 3.5 ),
    HF1Weights = cms.vdouble(  ),
    hoInput = cms.InputTag( "hltHoreco" ),
    HF1Threshold = cms.double( 0.5 ),
    HOThresholdMinus1 = cms.double( 3.5 ),
    HESGrid = cms.vdouble(  ),
    EcutTower = cms.double( -1000.0 ),
    UseRejectedRecoveredEcalHits = cms.bool( False ),
    UseEtEETreshold = cms.bool( False ),
    HESWeights = cms.vdouble(  ),
    EcalRecHitSeveritiesToBeExcluded = cms.vstring( 'kTime',
      'kWeird',
      'kBad' ),
    HEDWeight = cms.double( 1.0 ),
    UseSymEETreshold = cms.bool( False ),
    HEDThreshold = cms.double( 0.8 ),
    EBThreshold = cms.double( 0.07 ),
    UseRejectedHitsOnly = cms.bool( False ),
    UseHcalRecoveredHits = cms.bool( False ),
    HOThresholdMinus2 = cms.double( 3.5 ),
    HOThreshold0 = cms.double( 3.5 ),
    ecalInputs = cms.VInputTag( 'hltEcalRecHit:EcalRecHitsEB','hltEcalRecHit:EcalRecHitsEE' ),
    UseRejectedRecoveredHcalHits = cms.bool( False ),
    MomEBDepth = cms.double( 0.3 ),
    HBWeight = cms.double( 1.0 ),
    HOGrid = cms.vdouble(  ),
    EBGrid = cms.vdouble(  )
)
process.hltFixedGridRhoFastjetAllCaloForMuons = cms.EDProducer( "FixedGridRhoProducerFastjet",
    gridSpacing = cms.double( 0.55 ),
    maxRapidity = cms.double( 2.5 ),
    pfCandidatesTag = cms.InputTag( "hltTowerMakerForAll" )
)
process.hltEgammaHoverE = cms.EDProducer( "EgammaHLTBcHcalIsolationProducersRegional",
    caloTowerProducer = cms.InputTag( "hltTowerMakerForAll" ),
    effectiveAreaBarrel = cms.double( 0.105 ),
    outerCone = cms.double( 0.14 ),
    innerCone = cms.double( 0.0 ),
    useSingleTower = cms.bool( False ),
    rhoProducer = cms.InputTag( "hltFixedGridRhoFastjetAllCaloForMuons" ),
    depth = cms.int32( -1 ),
    doRhoCorrection = cms.bool( False ),
    effectiveAreaEndcap = cms.double( 0.17 ),
    recoEcalCandidateProducer = cms.InputTag( "hltEgammaCandidates" ),
    rhoMax = cms.double( 9.9999999E7 ),
    etMin = cms.double( 0.0 ),
    rhoScale = cms.double( 1.0 ),
    doEtSum = cms.bool( False )
)
process.hltSingleEle22WP75HcEFilter = cms.EDFilter( "HLTEgammaGenericQuadraticFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( 0.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( 0.0 ),
    thrRegularEE = cms.double( 13.0 ),
    thrOverEEE = cms.double( 0.01 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.01 ),
    thrRegularEB = cms.double( 4.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( False ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaHoverE" ),
    candTag = cms.InputTag( "hltSingleEle22WP75ClusterShapeFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEgammaEcalPFClusterIso = cms.EDProducer( "EgammaHLTEcalPFClusterIsolationProducer",
    energyEndcap = cms.double( 0.0 ),
    effectiveAreaBarrel = cms.double( 0.149 ),
    etaStripBarrel = cms.double( 0.0 ),
    rhoProducer = cms.InputTag( "hltFixedGridRhoFastjetAllCaloForMuons" ),
    pfClusterProducer = cms.InputTag( "hltParticleFlowClusterECALL1Seeded" ),
    etaStripEndcap = cms.double( 0.0 ),
    drVetoBarrel = cms.double( 0.0 ),
    drMax = cms.double( 0.3 ),
    doRhoCorrection = cms.bool( True ),
    energyBarrel = cms.double( 0.0 ),
    effectiveAreaEndcap = cms.double( 0.097 ),
    drVetoEndcap = cms.double( 0.0 ),
    recoEcalCandidateProducer = cms.InputTag( "hltEgammaCandidates" ),
    rhoMax = cms.double( 9.9999999E7 ),
    rhoScale = cms.double( 1.0 )
)
process.hltSingleEle22WP75EcalIsoFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( -1.0 ),
    thrOverEEE = cms.double( 0.14 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.21 ),
    thrRegularEB = cms.double( -1.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaEcalPFClusterIso" ),
    candTag = cms.InputTag( "hltSingleEle22WP75HcEFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltRegionalTowerForEgamma = cms.EDProducer( "EgammaHLTCaloTowerProducer",
    L1NonIsoCand = cms.InputTag( 'hltL1extraParticles','NonIsolated' ),
    EMin = cms.double( 0.8 ),
    EtMin = cms.double( 0.5 ),
    L1IsoCand = cms.InputTag( 'hltL1extraParticles','Isolated' ),
    useTowersInCone = cms.double( 0.8 ),
    towerCollection = cms.InputTag( "hltTowerMakerForAll" )
)
process.hltParticleFlowRecHitHCALForEgamma = cms.EDProducer( "PFCTRecHitProducer",
    ECAL_Compensate = cms.bool( False ),
    ECAL_Dead_Code = cms.uint32( 10 ),
    MinLongTiming_Cut = cms.double( -5.0 ),
    ECAL_Compensation = cms.double( 0.5 ),
    MaxLongTiming_Cut = cms.double( 5.0 ),
    weight_HFhad = cms.double( 1.0 ),
    ApplyPulseDPG = cms.bool( False ),
    navigator = cms.PSet(  name = cms.string( "PFRecHitCaloTowerNavigator" ) ),
    ECAL_Threshold = cms.double( 10.0 ),
    ApplyTimeDPG = cms.bool( False ),
    caloTowers = cms.InputTag( "hltRegionalTowerForEgamma" ),
    hcalRecHitsHBHE = cms.InputTag( "hltHbhereco" ),
    LongFibre_Fraction = cms.double( 0.1 ),
    MaxShortTiming_Cut = cms.double( 5.0 ),
    HcalMaxAllowedHFLongShortSev = cms.int32( 9 ),
    thresh_Barrel = cms.double( 0.4 ),
    navigation_HF = cms.bool( True ),
    HcalMaxAllowedHFInTimeWindowSev = cms.int32( 9 ),
    HF_Calib_29 = cms.double( 1.07 ),
    LongFibre_Cut = cms.double( 120.0 ),
    EM_Depth = cms.double( 22.0 ),
    weight_HFem = cms.double( 1.0 ),
    LongShortFibre_Cut = cms.double( 1.0E9 ),
    MinShortTiming_Cut = cms.double( -5.0 ),
    HCAL_Calib = cms.bool( True ),
    thresh_HF = cms.double( 0.4 ),
    HcalMaxAllowedHFDigiTimeSev = cms.int32( 9 ),
    thresh_Endcap = cms.double( 0.4 ),
    HcalMaxAllowedChannelStatusSev = cms.int32( 9 ),
    hcalRecHitsHF = cms.InputTag( "hltHfreco" ),
    ShortFibre_Cut = cms.double( 60.0 ),
    ApplyLongShortDPG = cms.bool( True ),
    HF_Calib = cms.bool( True ),
    HAD_Depth = cms.double( 47.0 ),
    ShortFibre_Fraction = cms.double( 0.01 ),
    HCAL_Calib_29 = cms.double( 1.35 )
)
process.hltParticleFlowClusterHCALForEgamma = cms.EDProducer( "PFClusterProducer",
    pfClusterBuilder = cms.PSet( 
      positionCalc = cms.PSet( 
        minFractionInCalc = cms.double( 1.0E-9 ),
        logWeightDenominator = cms.double( 0.8 ),
        minAllowedNormalization = cms.double( 1.0E-9 ),
        posCalcNCrystals = cms.int32( 5 ),
        algoName = cms.string( "Basic2DGenericPFlowPositionCalc" )
      ),
      minFracTot = cms.double( 1.0E-20 ),
      maxIterations = cms.uint32( 50 ),
      stoppingTolerance = cms.double( 1.0E-8 ),
      minFractionToKeep = cms.double( 1.0E-7 ),
      excludeOtherSeeds = cms.bool( True ),
      showerSigma = cms.double( 10.0 ),
      recHitEnergyNorms = cms.VPSet( 
        cms.PSet(  detector = cms.string( "HCAL_BARREL1" ),
          recHitEnergyNorm = cms.double( 0.8 )
        ),
        cms.PSet(  detector = cms.string( "HCAL_ENDCAP" ),
          recHitEnergyNorm = cms.double( 0.8 )
        )
      ),
      algoName = cms.string( "Basic2DGenericPFlowClusterizer" ),
      allCellsPositionCalc = cms.PSet( 
        minFractionInCalc = cms.double( 1.0E-9 ),
        logWeightDenominator = cms.double( 0.8 ),
        minAllowedNormalization = cms.double( 1.0E-9 ),
        posCalcNCrystals = cms.int32( -1 ),
        algoName = cms.string( "Basic2DGenericPFlowPositionCalc" )
      )
    ),
    positionReCalc = cms.PSet(  ),
    initialClusteringStep = cms.PSet( 
      thresholdsByDetector = cms.VPSet( 
        cms.PSet(  gatheringThreshold = cms.double( 0.8 ),
          detector = cms.string( "HCAL_BARREL1" ),
          gatheringThresholdPt = cms.double( 0.0 )
        ),
        cms.PSet(  gatheringThreshold = cms.double( 0.8 ),
          detector = cms.string( "HCAL_ENDCAP" ),
          gatheringThresholdPt = cms.double( 0.0 )
        )
      ),
      useCornerCells = cms.bool( True ),
      algoName = cms.string( "Basic2DGenericTopoClusterizer" )
    ),
    energyCorrector = cms.PSet(  ),
    recHitCleaners = cms.VPSet( 
      cms.PSet(  algoName = cms.string( "RBXAndHPDCleaner" )      )
    ),
    seedFinder = cms.PSet( 
      nNeighbours = cms.int32( 4 ),
      thresholdsByDetector = cms.VPSet( 
        cms.PSet(  seedingThreshold = cms.double( 0.8 ),
          seedingThresholdPt = cms.double( 0.0 ),
          detector = cms.string( "HCAL_BARREL1" )
        ),
        cms.PSet(  seedingThreshold = cms.double( 1.1 ),
          seedingThresholdPt = cms.double( 0.0 ),
          detector = cms.string( "HCAL_ENDCAP" )
        )
      ),
      algoName = cms.string( "LocalMaximumSeedFinder" )
    ),
    recHitsSource = cms.InputTag( "hltParticleFlowRecHitHCALForEgamma" )
)
process.hltEgammaHcalPFClusterIso = cms.EDProducer( "EgammaHLTHcalPFClusterIsolationProducer",
    energyEndcap = cms.double( 0.0 ),
    useHF = cms.bool( False ),
    effectiveAreaBarrel = cms.double( 0.06 ),
    etaStripBarrel = cms.double( 0.0 ),
    pfClusterProducerHFHAD = cms.InputTag( "hltParticleFlowClusterHFHADForEgamma" ),
    rhoProducer = cms.InputTag( "hltFixedGridRhoFastjetAllCaloForMuons" ),
    etaStripEndcap = cms.double( 0.0 ),
    drVetoBarrel = cms.double( 0.0 ),
    pfClusterProducerHCAL = cms.InputTag( "hltParticleFlowClusterHCALForEgamma" ),
    drMax = cms.double( 0.3 ),
    doRhoCorrection = cms.bool( True ),
    energyBarrel = cms.double( 0.0 ),
    effectiveAreaEndcap = cms.double( 0.089 ),
    drVetoEndcap = cms.double( 0.0 ),
    recoEcalCandidateProducer = cms.InputTag( "hltEgammaCandidates" ),
    rhoMax = cms.double( 9.9999999E7 ),
    pfClusterProducerHFEM = cms.InputTag( "hltParticleFlowClusterHFEMForEgamma" ),
    rhoScale = cms.double( 1.0 )
)
process.hltSingleEle22WP75HcalIsoFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( -1.0 ),
    thrOverEEE = cms.double( 0.21 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.11 ),
    thrRegularEB = cms.double( -1.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaHcalPFClusterIso" ),
    candTag = cms.InputTag( "hltSingleEle22WP75EcalIsoFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltSiPixelDigis = cms.EDProducer( "SiPixelRawToDigi",
    UseQualityInfo = cms.bool( False ),
    UsePilotBlade = cms.bool( False ),
    UsePhase1 = cms.bool( False ),
    InputLabel = cms.InputTag( "rawDataCollector" ),
    IncludeErrors = cms.bool( False ),
    ErrorList = cms.vint32(  ),
    Regions = cms.PSet(  ),
    Timing = cms.untracked.bool( False ),
    UserErrorList = cms.vint32(  )
)
process.hltSiPixelClusters = cms.EDProducer( "SiPixelClusterProducer",
    src = cms.InputTag( "hltSiPixelDigis" ),
    ChannelThreshold = cms.int32( 1000 ),
    maxNumberOfClusters = cms.int32( 20000 ),
    VCaltoElectronGain = cms.int32( 65 ),
    MissCalibrate = cms.untracked.bool( True ),
    SplitClusters = cms.bool( False ),
    VCaltoElectronOffset = cms.int32( -414 ),
    payloadType = cms.string( "HLT" ),
    SeedThreshold = cms.int32( 1000 ),
    ClusterThreshold = cms.double( 4000.0 )
)
process.hltSiPixelClustersCache = cms.EDProducer( "SiPixelClusterShapeCacheProducer",
    src = cms.InputTag( "hltSiPixelClusters" ),
    onDemand = cms.bool( False )
)
process.hltSiPixelRecHits = cms.EDProducer( "SiPixelRecHitConverter",
    VerboseLevel = cms.untracked.int32( 0 ),
    src = cms.InputTag( "hltSiPixelClusters" ),
    CPE = cms.string( "hltESPPixelCPEGeneric" )
)
process.hltSiStripExcludedFEDListProducer = cms.EDProducer( "SiStripExcludedFEDListProducer",
    ProductLabel = cms.InputTag( "rawDataCollector" )
)
process.hltSiStripRawToClustersFacility = cms.EDProducer( "SiStripClusterizerFromRaw",
    ProductLabel = cms.InputTag( "rawDataCollector" ),
    DoAPVEmulatorCheck = cms.bool( False ),
    Algorithms = cms.PSet( 
      SiStripFedZeroSuppressionMode = cms.uint32( 4 ),
      CommonModeNoiseSubtractionMode = cms.string( "Median" ),
      PedestalSubtractionFedMode = cms.bool( True ),
      TruncateInSuppressor = cms.bool( True ),
      doAPVRestore = cms.bool( False ),
      useCMMeanMap = cms.bool( False )
    ),
    Clusterizer = cms.PSet( 
      ChannelThreshold = cms.double( 2.0 ),
      MaxSequentialBad = cms.uint32( 1 ),
      MaxSequentialHoles = cms.uint32( 0 ),
      Algorithm = cms.string( "ThreeThresholdAlgorithm" ),
      MaxAdjacentBad = cms.uint32( 0 ),
      QualityLabel = cms.string( "" ),
      SeedThreshold = cms.double( 3.0 ),
      ClusterThreshold = cms.double( 5.0 ),
      setDetId = cms.bool( True ),
      RemoveApvShots = cms.bool( True )
    ),
    onDemand = cms.bool( True )
)
process.hltSiStripClusters = cms.EDProducer( "MeasurementTrackerEventProducer",
    inactivePixelDetectorLabels = cms.VInputTag(  ),
    stripClusterProducer = cms.string( "hltSiStripRawToClustersFacility" ),
    pixelClusterProducer = cms.string( "hltSiPixelClusters" ),
    switchOffPixelsIfEmpty = cms.bool( True ),
    inactiveStripDetectorLabels = cms.VInputTag( 'hltSiStripExcludedFEDListProducer' ),
    skipClusters = cms.InputTag( "" ),
    measurementTracker = cms.string( "hltESPMeasurementTracker" )
)
process.hltMixedLayerPairs = cms.EDProducer( "SeedingLayersEDProducer",
    layerList = cms.vstring( 'BPix1+BPix2',
      'BPix1+BPix3',
      'BPix2+BPix3',
      'BPix1+FPix1_pos',
      'BPix1+FPix1_neg',
      'BPix1+FPix2_pos',
      'BPix1+FPix2_neg',
      'BPix2+FPix1_pos',
      'BPix2+FPix1_neg',
      'BPix2+FPix2_pos',
      'BPix2+FPix2_neg',
      'FPix1_pos+FPix2_pos',
      'FPix1_neg+FPix2_neg',
      'FPix2_pos+TEC1_pos',
      'FPix2_pos+TEC2_pos',
      'TEC1_pos+TEC2_pos',
      'TEC2_pos+TEC3_pos',
      'FPix2_neg+TEC1_neg',
      'FPix2_neg+TEC2_neg',
      'TEC1_neg+TEC2_neg',
      'TEC2_neg+TEC3_neg' ),
    MTOB = cms.PSet(  ),
    TEC = cms.PSet( 
      useRingSlector = cms.bool( True ),
      TTRHBuilder = cms.string( "hltESPTTRHBWithTrackAngle" ),
      minRing = cms.int32( 1 ),
      maxRing = cms.int32( 1 )
    ),
    MTID = cms.PSet(  ),
    FPix = cms.PSet( 
      useErrorsFromParam = cms.bool( True ),
      hitErrorRPhi = cms.double( 0.0051 ),
      TTRHBuilder = cms.string( "hltESPTTRHBuilderPixelOnly" ),
      HitProducer = cms.string( "hltSiPixelRecHits" ),
      hitErrorRZ = cms.double( 0.0036 )
    ),
    MTEC = cms.PSet(  ),
    MTIB = cms.PSet(  ),
    TID = cms.PSet(  ),
    TOB = cms.PSet(  ),
    BPix = cms.PSet( 
      useErrorsFromParam = cms.bool( True ),
      hitErrorRPhi = cms.double( 0.0027 ),
      TTRHBuilder = cms.string( "hltESPTTRHBuilderPixelOnly" ),
      HitProducer = cms.string( "hltSiPixelRecHits" ),
      hitErrorRZ = cms.double( 0.006 )
    ),
    TIB = cms.PSet(  )
)
process.hltEgammaElectronPixelSeeds = cms.EDProducer( "ElectronSeedProducer",
    endcapSuperClusters = cms.InputTag( 'hltParticleFlowSuperClusterECALL1Seeded','hltParticleFlowSuperClusterECALEndcapWithPreshower' ),
    SeedConfiguration = cms.PSet( 
      searchInTIDTEC = cms.bool( True ),
      HighPtThreshold = cms.double( 35.0 ),
      r2MinF = cms.double( -0.15 ),
      OrderedHitsFactoryPSet = cms.PSet( 
        maxElement = cms.uint32( 0 ),
        ComponentName = cms.string( "StandardHitPairGenerator" ),
        useOnDemandTracker = cms.untracked.int32( 0 ),
        SeedingLayers = cms.InputTag( "hltMixedLayerPairs" )
      ),
      DeltaPhi1Low = cms.double( 0.23 ),
      DeltaPhi1High = cms.double( 0.08 ),
      ePhiMin1 = cms.double( -0.08 ),
      LowPtThreshold = cms.double( 3.0 ),
      RegionPSet = cms.PSet( 
        deltaPhiRegion = cms.double( 0.4 ),
        originHalfLength = cms.double( 15.0 ),
        useZInVertex = cms.bool( True ),
        deltaEtaRegion = cms.double( 0.1 ),
        ptMin = cms.double( 1.5 ),
        originRadius = cms.double( 0.2 ),
        VertexProducer = cms.InputTag( "dummyVertices" )
      ),
      dynamicPhiRoad = cms.bool( False ),
      ePhiMax1 = cms.double( 0.04 ),
      measurementTrackerName = cms.string( "hltESPMeasurementTracker" ),
      SizeWindowENeg = cms.double( 0.675 ),
      nSigmasDeltaZ1 = cms.double( 5.0 ),
      rMaxI = cms.double( 0.2 ),
      preFilteredSeeds = cms.bool( True ),
      r2MaxF = cms.double( 0.15 ),
      pPhiMin1 = cms.double( -0.04 ),
      initialSeeds = cms.InputTag( "noSeedsHere" ),
      pPhiMax1 = cms.double( 0.08 ),
      SCEtCut = cms.double( 3.0 ),
      z2MaxB = cms.double( 0.09 ),
      fromTrackerSeeds = cms.bool( True ),
      hcalRecHits = cms.InputTag( "hltHbhereco" ),
      z2MinB = cms.double( -0.09 ),
      rMinI = cms.double( -0.2 ),
      hOverEConeSize = cms.double( 0.0 ),
      hOverEHBMinE = cms.double( 999999.0 ),
      beamSpot = cms.InputTag( "hltOnlineBeamSpot" ),
      applyHOverECut = cms.bool( False ),
      hOverEHFMinE = cms.double( 999999.0 ),
      measurementTrackerEvent = cms.InputTag( "hltSiStripClusters" ),
      PhiMin2B = cms.double( -0.004 ),
      PhiMin2F = cms.double( -0.004 ),
      PhiMax2B = cms.double( 0.004 ),
      PhiMax2F = cms.double( 0.004 ),
      DeltaPhi2B = cms.double( 0.004 ),
      DeltaPhi2F = cms.double( 0.004 )
    ),
    barrelSuperClusters = cms.InputTag( 'hltParticleFlowSuperClusterECALL1Seeded','hltParticleFlowSuperClusterECALBarrel' )
)
process.hltSingleEle22WP75PixelMatchFilter = cms.EDFilter( "HLTElectronPixelMatchFilter",
    saveTags = cms.bool( False ),
    s2_threshold = cms.double( 0.4 ),
    npixelmatchcut = cms.double( 1.0 ),
    tanhSO10InterThres = cms.double( 1.0 ),
    pixelVeto = cms.bool( False ),
    doIsolated = cms.bool( True ),
    s_a_phi1B = cms.double( 0.0069 ),
    s_a_phi1F = cms.double( 0.0076 ),
    s_a_phi1I = cms.double( 0.0088 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    candTag = cms.InputTag( "hltSingleEle22WP75HcalIsoFilter" ),
    tanhSO10ForwardThres = cms.double( 1.0 ),
    L1IsoPixelSeedsTag = cms.InputTag( "hltEgammaElectronPixelSeeds" ),
    L1NonIsoCand = cms.InputTag( "" ),
    ncandcut = cms.int32( 1 ),
    tanhSO10BarrelThres = cms.double( 0.35 ),
    s_a_rF = cms.double( 0.04 ),
    L1NonIsoPixelSeedsTag = cms.InputTag( "" ),
    s_a_rI = cms.double( 0.027 ),
    s_a_phi2I = cms.double( 7.0E-4 ),
    useS = cms.bool( False ),
    s_a_phi2B = cms.double( 3.7E-4 ),
    s_a_zB = cms.double( 0.012 ),
    s_a_phi2F = cms.double( 0.00906 )
)
process.hltEgammaCkfTrackCandidatesForGSF = cms.EDProducer( "CkfTrackCandidateMaker",
    src = cms.InputTag( "hltEgammaElectronPixelSeeds" ),
    maxSeedsBeforeCleaning = cms.uint32( 1000 ),
    SimpleMagneticField = cms.string( "" ),
    TransientInitialStateEstimatorParameters = cms.PSet( 
      propagatorAlongTISE = cms.string( "PropagatorWithMaterial" ),
      numberMeasurementsForFit = cms.int32( 4 ),
      propagatorOppositeTISE = cms.string( "PropagatorWithMaterialOpposite" )
    ),
    TrajectoryCleaner = cms.string( "hltESPTrajectoryCleanerBySharedHits" ),
    MeasurementTrackerEvent = cms.InputTag( "hltSiStripClusters" ),
    cleanTrajectoryAfterInOut = cms.bool( True ),
    useHitsSplitting = cms.bool( True ),
    RedundantSeedCleaner = cms.string( "CachingSeedCleanerBySharedInput" ),
    doSeedingRegionRebuilding = cms.bool( True ),
    maxNSeeds = cms.uint32( 1000000 ),
    TrajectoryBuilderPSet = cms.PSet(  refToPSet_ = cms.string( "HLTPSetTrajectoryBuilderForElectrons" ) ),
    NavigationSchool = cms.string( "SimpleNavigationSchool" ),
    TrajectoryBuilder = cms.string( "" )
)
process.hltEgammaGsfTracks = cms.EDProducer( "GsfTrackProducer",
    src = cms.InputTag( "hltEgammaCkfTrackCandidatesForGSF" ),
    beamSpot = cms.InputTag( "hltOnlineBeamSpot" ),
    producer = cms.string( "" ),
    MeasurementTrackerEvent = cms.InputTag( "hltSiStripClusters" ),
    Fitter = cms.string( "hltESPGsfElectronFittingSmoother" ),
    useHitsSplitting = cms.bool( False ),
    MeasurementTracker = cms.string( "hltESPMeasurementTracker" ),
    GeometricInnerState = cms.bool( True ),
    NavigationSchool = cms.string( "SimpleNavigationSchool" ),
    TrajectoryInEvent = cms.bool( True ),
    TTRHBuilder = cms.string( "hltESPTTRHBWithTrackAngle" ),
    AlgorithmName = cms.string( "gsf" ),
    Propagator = cms.string( "hltESPFwdElectronPropagator" )
)
process.hltEgammaGsfElectrons = cms.EDProducer( "EgammaHLTPixelMatchElectronProducers",
    BSProducer = cms.InputTag( "hltOnlineBeamSpot" ),
    UseGsfTracks = cms.bool( True ),
    TrackProducer = cms.InputTag( "" ),
    GsfTrackProducer = cms.InputTag( "hltEgammaGsfTracks" )
)
process.hltEgammaGsfTrackVars = cms.EDProducer( "EgammaHLTGsfTrackVarProducer",
    recoEcalCandidateProducer = cms.InputTag( "hltEgammaCandidates" ),
    beamSpotProducer = cms.InputTag( "hltOnlineBeamSpot" ),
    upperTrackNrToRemoveCut = cms.int32( 9999 ),
    lowerTrackNrToRemoveCut = cms.int32( -1 ),
    inputCollection = cms.InputTag( "hltEgammaGsfTracks" )
)
process.hltSingleEle22WP75GsfOneOESuperMinusOneOPFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.032 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.032 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','OneOESuperMinusOneOP' ),
    candTag = cms.InputTag( "hltSingleEle22WP75PixelMatchFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltSingleEle22WP75GsfChi2Filter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 2.8 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 3.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','Chi2' ),
    candTag = cms.InputTag( "hltSingleEle22WP75GsfOneOESuperMinusOneOPFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltSingleEle22WP75GsfDetaFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.0065 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.0035 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','Deta' ),
    candTag = cms.InputTag( "hltSingleEle22WP75GsfChi2Filter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltSingleEle22WP75GsfDphiFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.035 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.021 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','Dphi' ),
    candTag = cms.InputTag( "hltSingleEle22WP75GsfDetaFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltElectronsVertex = cms.EDProducer( "VertexFromTrackProducer",
    verbose = cms.untracked.bool( False ),
    useTriggerFilterElectrons = cms.bool( False ),
    beamSpotLabel = cms.InputTag( "hltOnlineBeamSpot" ),
    isRecoCandidate = cms.bool( True ),
    trackLabel = cms.InputTag( "hltEgammaGsfElectrons" ),
    useTriggerFilterMuons = cms.bool( False ),
    useBeamSpot = cms.bool( True ),
    vertexLabel = cms.InputTag( "None" ),
    triggerFilterElectronsSrc = cms.InputTag( "None" ),
    triggerFilterMuonsSrc = cms.InputTag( "None" ),
    useVertex = cms.bool( False )
)
process.hltPixelLayerTriplets = cms.EDProducer( "SeedingLayersEDProducer",
    layerList = cms.vstring( 'BPix1+BPix2+BPix3',
      'BPix1+BPix2+FPix1_pos',
      'BPix1+BPix2+FPix1_neg',
      'BPix1+FPix1_pos+FPix2_pos',
      'BPix1+FPix1_neg+FPix2_neg' ),
    MTOB = cms.PSet(  ),
    TEC = cms.PSet(  ),
    MTID = cms.PSet(  ),
    FPix = cms.PSet( 
      useErrorsFromParam = cms.bool( True ),
      hitErrorRPhi = cms.double( 0.0051 ),
      TTRHBuilder = cms.string( "hltESPTTRHBuilderPixelOnly" ),
      HitProducer = cms.string( "hltSiPixelRecHits" ),
      hitErrorRZ = cms.double( 0.0036 )
    ),
    MTEC = cms.PSet(  ),
    MTIB = cms.PSet(  ),
    TID = cms.PSet(  ),
    TOB = cms.PSet(  ),
    BPix = cms.PSet( 
      useErrorsFromParam = cms.bool( True ),
      hitErrorRPhi = cms.double( 0.0027 ),
      TTRHBuilder = cms.string( "hltESPTTRHBuilderPixelOnly" ),
      HitProducer = cms.string( "hltSiPixelRecHits" ),
      hitErrorRZ = cms.double( 0.006 )
    ),
    TIB = cms.PSet(  )
)
process.hltPixelTracksElectrons = cms.EDProducer( "PixelTrackProducer",
    useFilterWithES = cms.bool( False ),
    FilterPSet = cms.PSet( 
      chi2 = cms.double( 1000.0 ),
      nSigmaTipMaxTolerance = cms.double( 0.0 ),
      ComponentName = cms.string( "PixelTrackFilterByKinematics" ),
      nSigmaInvPtTolerance = cms.double( 0.0 ),
      ptMin = cms.double( 0.1 ),
      tipMax = cms.double( 1.0 )
    ),
    passLabel = cms.string( "Pixel triplet primary tracks with vertex constraint" ),
    FitterPSet = cms.PSet( 
      ComponentName = cms.string( "PixelFitterByHelixProjections" ),
      TTRHBuilder = cms.string( "hltESPTTRHBuilderPixelOnly" ),
      fixImpactParameter = cms.double( 0.0 )
    ),
    RegionFactoryPSet = cms.PSet( 
      ComponentName = cms.string( "GlobalTrackingRegionWithVerticesProducer" ),
      RegionPSet = cms.PSet( 
        precise = cms.bool( True ),
        originRadius = cms.double( 0.2 ),
        ptMin = cms.double( 0.9 ),
        originHalfLength = cms.double( 0.3 ),
        beamSpot = cms.InputTag( "hltOnlineBeamSpot" ),
        useFixedError = cms.bool( True ),
        sigmaZVertex = cms.double( 3.0 ),
        fixedError = cms.double( 0.2 ),
        VertexCollection = cms.InputTag( "hltElectronsVertex" ),
        useFoundVertices = cms.bool( True ),
        nSigmaZ = cms.double( 4.0 ),
        useFakeVertices = cms.bool( True )
      )
    ),
    CleanerPSet = cms.PSet(  ComponentName = cms.string( "PixelTrackCleanerBySharedHits" ) ),
    OrderedHitsFactoryPSet = cms.PSet( 
      ComponentName = cms.string( "StandardHitTripletGenerator" ),
      GeneratorPSet = cms.PSet( 
        useBending = cms.bool( True ),
        useFixedPreFiltering = cms.bool( False ),
        maxElement = cms.uint32( 100000 ),
        phiPreFiltering = cms.double( 0.3 ),
        extraHitRPhitolerance = cms.double( 0.06 ),
        useMultScattering = cms.bool( True ),
        SeedComparitorPSet = cms.PSet( 
          ComponentName = cms.string( "LowPtClusterShapeSeedComparitor" ),
          clusterShapeCacheSrc = cms.InputTag( "hltSiPixelClustersCache" )
        ),
        extraHitRZtolerance = cms.double( 0.06 ),
        ComponentName = cms.string( "PixelTripletHLTGenerator" )
      ),
      SeedingLayers = cms.InputTag( "hltPixelLayerTriplets" )
    )
)
process.hltPixelVerticesElectrons = cms.EDProducer( "PixelVertexProducer",
    WtAverage = cms.bool( True ),
    Method2 = cms.bool( True ),
    beamSpot = cms.InputTag( "hltOnlineBeamSpot" ),
    PVcomparer = cms.PSet(  refToPSet_ = cms.string( "HLTPSetPvClusterComparer" ) ),
    Verbosity = cms.int32( 0 ),
    UseError = cms.bool( True ),
    TrackCollection = cms.InputTag( "hltPixelTracksElectrons" ),
    PtMin = cms.double( 1.0 ),
    NTrkMin = cms.int32( 2 ),
    ZOffset = cms.double( 5.0 ),
    Finder = cms.string( "DivisiveVertexFinder" ),
    ZSeparation = cms.double( 0.05 )
)
process.hltIter0ElectronsPixelSeedsFromPixelTracks = cms.EDProducer( "SeedGeneratorFromProtoTracksEDProducer",
    useEventsWithNoVertex = cms.bool( True ),
    originHalfLength = cms.double( 0.3 ),
    useProtoTrackKinematics = cms.bool( False ),
    usePV = cms.bool( True ),
    InputVertexCollection = cms.InputTag( "hltPixelVerticesElectrons" ),
    TTRHBuilder = cms.string( "hltESPTTRHBuilderPixelOnly" ),
    InputCollection = cms.InputTag( "hltPixelTracksElectrons" ),
    originRadius = cms.double( 0.1 )
)
process.hltIter0ElectronsCkfTrackCandidates = cms.EDProducer( "CkfTrackCandidateMaker",
    src = cms.InputTag( "hltIter0ElectronsPixelSeedsFromPixelTracks" ),
    maxSeedsBeforeCleaning = cms.uint32( 1000 ),
    SimpleMagneticField = cms.string( "ParabolicMf" ),
    TransientInitialStateEstimatorParameters = cms.PSet( 
      propagatorAlongTISE = cms.string( "PropagatorWithMaterialParabolicMf" ),
      numberMeasurementsForFit = cms.int32( 4 ),
      propagatorOppositeTISE = cms.string( "PropagatorWithMaterialParabolicMfOpposite" )
    ),
    TrajectoryCleaner = cms.string( "hltESPTrajectoryCleanerBySharedHits" ),
    MeasurementTrackerEvent = cms.InputTag( "hltSiStripClusters" ),
    cleanTrajectoryAfterInOut = cms.bool( False ),
    useHitsSplitting = cms.bool( False ),
    RedundantSeedCleaner = cms.string( "CachingSeedCleanerBySharedInput" ),
    doSeedingRegionRebuilding = cms.bool( False ),
    maxNSeeds = cms.uint32( 100000 ),
    TrajectoryBuilderPSet = cms.PSet(  refToPSet_ = cms.string( "HLTIter0PSetTrajectoryBuilderIT" ) ),
    NavigationSchool = cms.string( "SimpleNavigationSchool" ),
    TrajectoryBuilder = cms.string( "" )
)
process.hltIter0ElectronsCtfWithMaterialTracks = cms.EDProducer( "TrackProducer",
    src = cms.InputTag( "hltIter0ElectronsCkfTrackCandidates" ),
    SimpleMagneticField = cms.string( "ParabolicMf" ),
    clusterRemovalInfo = cms.InputTag( "" ),
    beamSpot = cms.InputTag( "hltOnlineBeamSpot" ),
    MeasurementTrackerEvent = cms.InputTag( "hltSiStripClusters" ),
    Fitter = cms.string( "hltESPFittingSmootherIT" ),
    useHitsSplitting = cms.bool( False ),
    MeasurementTracker = cms.string( "" ),
    AlgorithmName = cms.string( "hltIterX" ),
    alias = cms.untracked.string( "ctfWithMaterialTracks" ),
    NavigationSchool = cms.string( "" ),
    TrajectoryInEvent = cms.bool( True ),
    TTRHBuilder = cms.string( "hltESPTTRHBWithTrackAngle" ),
    GeometricInnerState = cms.bool( True ),
    useSimpleMF = cms.bool( True ),
    Propagator = cms.string( "hltESPRungeKuttaTrackerPropagator" )
)
process.hltIter0ElectronsTrackSelectionHighPurity = cms.EDProducer( "AnalyticalTrackSelector",
    max_d0 = cms.double( 100.0 ),
    minNumber3DLayers = cms.uint32( 0 ),
    max_lostHitFraction = cms.double( 1.0 ),
    applyAbsCutsIfNoPV = cms.bool( False ),
    qualityBit = cms.string( "highPurity" ),
    minNumberLayers = cms.uint32( 3 ),
    chi2n_par = cms.double( 0.7 ),
    useVtxError = cms.bool( False ),
    nSigmaZ = cms.double( 3.0 ),
    dz_par2 = cms.vdouble( 0.4, 4.0 ),
    applyAdaptedPVCuts = cms.bool( True ),
    min_eta = cms.double( -9999.0 ),
    dz_par1 = cms.vdouble( 0.35, 4.0 ),
    copyTrajectories = cms.untracked.bool( True ),
    vtxNumber = cms.int32( -1 ),
    max_d0NoPV = cms.double( 100.0 ),
    keepAllTracks = cms.bool( False ),
    maxNumberLostLayers = cms.uint32( 1 ),
    beamspot = cms.InputTag( "hltOnlineBeamSpot" ),
    max_relpterr = cms.double( 9999.0 ),
    copyExtras = cms.untracked.bool( True ),
    max_z0NoPV = cms.double( 100.0 ),
    vertexCut = cms.string( "tracksSize>=3" ),
    max_z0 = cms.double( 100.0 ),
    useVertices = cms.bool( True ),
    min_nhits = cms.uint32( 0 ),
    src = cms.InputTag( "hltIter0ElectronsCtfWithMaterialTracks" ),
    max_minMissHitOutOrIn = cms.int32( 99 ),
    chi2n_no1Dmod_par = cms.double( 9999.0 ),
    vertices = cms.InputTag( "hltPixelVerticesElectrons" ),
    max_eta = cms.double( 9999.0 ),
    d0_par2 = cms.vdouble( 0.4, 4.0 ),
    d0_par1 = cms.vdouble( 0.3, 4.0 ),
    res_par = cms.vdouble( 0.003, 0.001 ),
    minHitsToBypassChecks = cms.uint32( 20 )
)
process.hltIter1ElectronsClustersRefRemoval = cms.EDProducer( "TrackClusterRemover",
    minNumberOfLayersWithMeasBeforeFiltering = cms.int32( 0 ),
    maxChi2 = cms.double( 9.0 ),
    trajectories = cms.InputTag( "hltIter0ElectronsTrackSelectionHighPurity" ),
    oldClusterRemovalInfo = cms.InputTag( "" ),
    stripClusters = cms.InputTag( "hltSiStripRawToClustersFacility" ),
    overrideTrkQuals = cms.InputTag( "" ),
    pixelClusters = cms.InputTag( "hltSiPixelClusters" ),
    TrackQuality = cms.string( "highPurity" )
)
process.hltIter1ElectronsMaskedMeasurementTrackerEvent = cms.EDProducer( "MaskedMeasurementTrackerEventProducer",
    clustersToSkip = cms.InputTag( "hltIter1ElectronsClustersRefRemoval" ),
    OnDemand = cms.bool( False ),
    src = cms.InputTag( "hltSiStripClusters" )
)
process.hltIter1ElectronsPixelLayerTriplets = cms.EDProducer( "SeedingLayersEDProducer",
    layerList = cms.vstring( 'BPix1+BPix2+BPix3',
      'BPix1+BPix2+FPix1_pos',
      'BPix1+BPix2+FPix1_neg',
      'BPix1+FPix1_pos+FPix2_pos',
      'BPix1+FPix1_neg+FPix2_neg' ),
    MTOB = cms.PSet(  ),
    TEC = cms.PSet(  ),
    MTID = cms.PSet(  ),
    FPix = cms.PSet( 
      HitProducer = cms.string( "hltSiPixelRecHits" ),
      hitErrorRZ = cms.double( 0.0036 ),
      useErrorsFromParam = cms.bool( True ),
      TTRHBuilder = cms.string( "hltESPTTRHBuilderPixelOnly" ),
      skipClusters = cms.InputTag( "hltIter1ElectronsClustersRefRemoval" ),
      hitErrorRPhi = cms.double( 0.0051 )
    ),
    MTEC = cms.PSet(  ),
    MTIB = cms.PSet(  ),
    TID = cms.PSet(  ),
    TOB = cms.PSet(  ),
    BPix = cms.PSet( 
      HitProducer = cms.string( "hltSiPixelRecHits" ),
      hitErrorRZ = cms.double( 0.006 ),
      useErrorsFromParam = cms.bool( True ),
      TTRHBuilder = cms.string( "hltESPTTRHBuilderPixelOnly" ),
      skipClusters = cms.InputTag( "hltIter1ElectronsClustersRefRemoval" ),
      hitErrorRPhi = cms.double( 0.0027 )
    ),
    TIB = cms.PSet(  )
)
process.hltIter1ElectronsPixelSeeds = cms.EDProducer( "SeedGeneratorFromRegionHitsEDProducer",
    RegionFactoryPSet = cms.PSet( 
      ComponentName = cms.string( "CandidateSeededTrackingRegionsProducer" ),
      RegionPSet = cms.PSet( 
        precise = cms.bool( True ),
        originRadius = cms.double( 0.05 ),
        ptMin = cms.double( 0.5 ),
        input = cms.InputTag( "hltEgammaCandidates" ),
        maxNRegions = cms.int32( 10 ),
        beamSpot = cms.InputTag( "hltOnlineBeamSpot" ),
        vertexCollection = cms.InputTag( "hltPixelVerticesElectrons" ),
        zErrorBeamSpot = cms.double( 24.2 ),
        deltaEta = cms.double( 0.5 ),
        deltaPhi = cms.double( 0.5 ),
        nSigmaZVertex = cms.double( 3.0 ),
        nSigmaZBeamSpot = cms.double( 4.0 ),
        mode = cms.string( "VerticesFixed" ),
        maxNVertices = cms.int32( 3 ),
        zErrorVetex = cms.double( 0.2 )
      )
    ),
    SeedComparitorPSet = cms.PSet(  ComponentName = cms.string( "none" ) ),
    ClusterCheckPSet = cms.PSet( 
      PixelClusterCollectionLabel = cms.InputTag( "hltSiPixelClusters" ),
      MaxNumberOfCosmicClusters = cms.uint32( 50000 ),
      doClusterCheck = cms.bool( False ),
      ClusterCollectionLabel = cms.InputTag( "hltSiStripClusters" ),
      MaxNumberOfPixelClusters = cms.uint32( 10000 )
    ),
    OrderedHitsFactoryPSet = cms.PSet( 
      maxElement = cms.uint32( 0 ),
      ComponentName = cms.string( "StandardHitTripletGenerator" ),
      GeneratorPSet = cms.PSet( 
        useBending = cms.bool( True ),
        useFixedPreFiltering = cms.bool( False ),
        maxElement = cms.uint32( 100000 ),
        phiPreFiltering = cms.double( 0.3 ),
        extraHitRPhitolerance = cms.double( 0.032 ),
        useMultScattering = cms.bool( True ),
        ComponentName = cms.string( "PixelTripletHLTGenerator" ),
        extraHitRZtolerance = cms.double( 0.037 ),
        SeedComparitorPSet = cms.PSet(  ComponentName = cms.string( "none" ) )
      ),
      SeedingLayers = cms.InputTag( "hltIter1ElectronsPixelLayerTriplets" )
    ),
    SeedCreatorPSet = cms.PSet( 
      ComponentName = cms.string( "SeedFromConsecutiveHitsTripletOnlyCreator" ),
      propagator = cms.string( "PropagatorWithMaterialParabolicMf" ),
      SeedMomentumForBOFF = cms.double( 5.0 ),
      TTRHBuilder = cms.string( "hltESPTTRHBWithTrackAngle" )
    ),
    TTRHBuilder = cms.string( "(unused)" )
)
process.hltIter1ElectronsCkfTrackCandidates = cms.EDProducer( "CkfTrackCandidateMaker",
    src = cms.InputTag( "hltIter1ElectronsPixelSeeds" ),
    maxSeedsBeforeCleaning = cms.uint32( 1000 ),
    SimpleMagneticField = cms.string( "ParabolicMf" ),
    TransientInitialStateEstimatorParameters = cms.PSet( 
      propagatorAlongTISE = cms.string( "PropagatorWithMaterialParabolicMf" ),
      numberMeasurementsForFit = cms.int32( 4 ),
      propagatorOppositeTISE = cms.string( "PropagatorWithMaterialParabolicMfOpposite" )
    ),
    TrajectoryCleaner = cms.string( "hltESPTrajectoryCleanerBySharedHits" ),
    MeasurementTrackerEvent = cms.InputTag( "hltIter1ElectronsMaskedMeasurementTrackerEvent" ),
    cleanTrajectoryAfterInOut = cms.bool( False ),
    useHitsSplitting = cms.bool( False ),
    RedundantSeedCleaner = cms.string( "CachingSeedCleanerBySharedInput" ),
    doSeedingRegionRebuilding = cms.bool( False ),
    maxNSeeds = cms.uint32( 100000 ),
    TrajectoryBuilderPSet = cms.PSet(  refToPSet_ = cms.string( "HLTIter1PSetTrajectoryBuilderIT" ) ),
    NavigationSchool = cms.string( "SimpleNavigationSchool" ),
    TrajectoryBuilder = cms.string( "" )
)
process.hltIter1ElectronsCtfWithMaterialTracks = cms.EDProducer( "TrackProducer",
    src = cms.InputTag( "hltIter1ElectronsCkfTrackCandidates" ),
    SimpleMagneticField = cms.string( "ParabolicMf" ),
    clusterRemovalInfo = cms.InputTag( "" ),
    beamSpot = cms.InputTag( "hltOnlineBeamSpot" ),
    MeasurementTrackerEvent = cms.InputTag( "hltIter1ElectronsMaskedMeasurementTrackerEvent" ),
    Fitter = cms.string( "hltESPFittingSmootherIT" ),
    useHitsSplitting = cms.bool( False ),
    MeasurementTracker = cms.string( "" ),
    AlgorithmName = cms.string( "hltIterX" ),
    alias = cms.untracked.string( "ctfWithMaterialTracks" ),
    NavigationSchool = cms.string( "" ),
    TrajectoryInEvent = cms.bool( True ),
    TTRHBuilder = cms.string( "hltESPTTRHBWithTrackAngle" ),
    GeometricInnerState = cms.bool( True ),
    useSimpleMF = cms.bool( True ),
    Propagator = cms.string( "hltESPRungeKuttaTrackerPropagator" )
)
process.hltIter1ElectronsTrackSelectionHighPurityLoose = cms.EDProducer( "AnalyticalTrackSelector",
    max_d0 = cms.double( 100.0 ),
    minNumber3DLayers = cms.uint32( 0 ),
    max_lostHitFraction = cms.double( 1.0 ),
    applyAbsCutsIfNoPV = cms.bool( False ),
    qualityBit = cms.string( "highPurity" ),
    minNumberLayers = cms.uint32( 3 ),
    chi2n_par = cms.double( 0.7 ),
    useVtxError = cms.bool( False ),
    nSigmaZ = cms.double( 3.0 ),
    dz_par2 = cms.vdouble( 0.9, 3.0 ),
    applyAdaptedPVCuts = cms.bool( True ),
    min_eta = cms.double( -9999.0 ),
    dz_par1 = cms.vdouble( 0.8, 3.0 ),
    copyTrajectories = cms.untracked.bool( True ),
    vtxNumber = cms.int32( -1 ),
    max_d0NoPV = cms.double( 100.0 ),
    keepAllTracks = cms.bool( False ),
    maxNumberLostLayers = cms.uint32( 1 ),
    beamspot = cms.InputTag( "hltOnlineBeamSpot" ),
    max_relpterr = cms.double( 9999.0 ),
    copyExtras = cms.untracked.bool( True ),
    max_z0NoPV = cms.double( 100.0 ),
    vertexCut = cms.string( "tracksSize>=3" ),
    max_z0 = cms.double( 100.0 ),
    useVertices = cms.bool( True ),
    min_nhits = cms.uint32( 0 ),
    src = cms.InputTag( "hltIter1ElectronsCtfWithMaterialTracks" ),
    max_minMissHitOutOrIn = cms.int32( 99 ),
    chi2n_no1Dmod_par = cms.double( 9999.0 ),
    vertices = cms.InputTag( "hltPixelVerticesElectrons" ),
    max_eta = cms.double( 9999.0 ),
    d0_par2 = cms.vdouble( 0.9, 3.0 ),
    d0_par1 = cms.vdouble( 0.85, 3.0 ),
    res_par = cms.vdouble( 0.003, 0.001 ),
    minHitsToBypassChecks = cms.uint32( 20 )
)
process.hltIter1ElectronsTrackSelectionHighPurityTight = cms.EDProducer( "AnalyticalTrackSelector",
    max_d0 = cms.double( 100.0 ),
    minNumber3DLayers = cms.uint32( 0 ),
    max_lostHitFraction = cms.double( 1.0 ),
    applyAbsCutsIfNoPV = cms.bool( False ),
    qualityBit = cms.string( "highPurity" ),
    minNumberLayers = cms.uint32( 5 ),
    chi2n_par = cms.double( 0.4 ),
    useVtxError = cms.bool( False ),
    nSigmaZ = cms.double( 3.0 ),
    dz_par2 = cms.vdouble( 1.0, 4.0 ),
    applyAdaptedPVCuts = cms.bool( True ),
    min_eta = cms.double( -9999.0 ),
    dz_par1 = cms.vdouble( 1.0, 4.0 ),
    copyTrajectories = cms.untracked.bool( True ),
    vtxNumber = cms.int32( -1 ),
    max_d0NoPV = cms.double( 100.0 ),
    keepAllTracks = cms.bool( False ),
    maxNumberLostLayers = cms.uint32( 1 ),
    beamspot = cms.InputTag( "hltOnlineBeamSpot" ),
    max_relpterr = cms.double( 9999.0 ),
    copyExtras = cms.untracked.bool( True ),
    max_z0NoPV = cms.double( 100.0 ),
    vertexCut = cms.string( "tracksSize>=3" ),
    max_z0 = cms.double( 100.0 ),
    useVertices = cms.bool( True ),
    min_nhits = cms.uint32( 0 ),
    src = cms.InputTag( "hltIter1ElectronsCtfWithMaterialTracks" ),
    max_minMissHitOutOrIn = cms.int32( 99 ),
    chi2n_no1Dmod_par = cms.double( 9999.0 ),
    vertices = cms.InputTag( "hltPixelVerticesElectrons" ),
    max_eta = cms.double( 9999.0 ),
    d0_par2 = cms.vdouble( 1.0, 4.0 ),
    d0_par1 = cms.vdouble( 1.0, 4.0 ),
    res_par = cms.vdouble( 0.003, 0.001 ),
    minHitsToBypassChecks = cms.uint32( 20 )
)
process.hltIter1ElectronsTrackSelectionHighPurity = cms.EDProducer( "TrackListMerger",
    ShareFrac = cms.double( 0.19 ),
    writeOnlyTrkQuals = cms.bool( False ),
    MinPT = cms.double( 0.05 ),
    allowFirstHitShare = cms.bool( True ),
    copyExtras = cms.untracked.bool( True ),
    Epsilon = cms.double( -0.001 ),
    selectedTrackQuals = cms.VInputTag( 'hltIter1ElectronsTrackSelectionHighPurityLoose','hltIter1ElectronsTrackSelectionHighPurityTight' ),
    indivShareFrac = cms.vdouble( 1.0, 1.0 ),
    MaxNormalizedChisq = cms.double( 1000.0 ),
    copyMVA = cms.bool( False ),
    FoundHitBonus = cms.double( 5.0 ),
    setsToMerge = cms.VPSet( 
      cms.PSet(  pQual = cms.bool( False ),
        tLists = cms.vint32( 0, 1 )
      )
    ),
    MinFound = cms.int32( 3 ),
    hasSelector = cms.vint32( 0, 0 ),
    TrackProducers = cms.VInputTag( 'hltIter1ElectronsTrackSelectionHighPurityLoose','hltIter1ElectronsTrackSelectionHighPurityTight' ),
    LostHitPenalty = cms.double( 20.0 ),
    newQuality = cms.string( "confirmed" )
)
process.hltIter1MergedForElectrons = cms.EDProducer( "TrackListMerger",
    ShareFrac = cms.double( 0.19 ),
    writeOnlyTrkQuals = cms.bool( False ),
    MinPT = cms.double( 0.05 ),
    allowFirstHitShare = cms.bool( True ),
    copyExtras = cms.untracked.bool( True ),
    Epsilon = cms.double( -0.001 ),
    selectedTrackQuals = cms.VInputTag( 'hltIter0ElectronsTrackSelectionHighPurity','hltIter1ElectronsTrackSelectionHighPurity' ),
    indivShareFrac = cms.vdouble( 1.0, 1.0 ),
    MaxNormalizedChisq = cms.double( 1000.0 ),
    copyMVA = cms.bool( False ),
    FoundHitBonus = cms.double( 5.0 ),
    setsToMerge = cms.VPSet( 
      cms.PSet(  pQual = cms.bool( False ),
        tLists = cms.vint32( 0, 1 )
      )
    ),
    MinFound = cms.int32( 3 ),
    hasSelector = cms.vint32( 0, 0 ),
    TrackProducers = cms.VInputTag( 'hltIter0ElectronsTrackSelectionHighPurity','hltIter1ElectronsTrackSelectionHighPurity' ),
    LostHitPenalty = cms.double( 20.0 ),
    newQuality = cms.string( "confirmed" )
)
process.hltIter2ElectronsClustersRefRemoval = cms.EDProducer( "TrackClusterRemover",
    minNumberOfLayersWithMeasBeforeFiltering = cms.int32( 0 ),
    maxChi2 = cms.double( 16.0 ),
    trajectories = cms.InputTag( "hltIter1ElectronsTrackSelectionHighPurity" ),
    oldClusterRemovalInfo = cms.InputTag( "hltIter1ElectronsClustersRefRemoval" ),
    stripClusters = cms.InputTag( "hltSiStripRawToClustersFacility" ),
    overrideTrkQuals = cms.InputTag( "" ),
    pixelClusters = cms.InputTag( "hltSiPixelClusters" ),
    TrackQuality = cms.string( "highPurity" )
)
process.hltIter2ElectronsMaskedMeasurementTrackerEvent = cms.EDProducer( "MaskedMeasurementTrackerEventProducer",
    clustersToSkip = cms.InputTag( "hltIter2ElectronsClustersRefRemoval" ),
    OnDemand = cms.bool( False ),
    src = cms.InputTag( "hltSiStripClusters" )
)
process.hltIter2ElectronsPixelLayerPairs = cms.EDProducer( "SeedingLayersEDProducer",
    layerList = cms.vstring( 'BPix1+BPix2',
      'BPix1+BPix3',
      'BPix2+BPix3',
      'BPix1+FPix1_pos',
      'BPix1+FPix1_neg',
      'BPix1+FPix2_pos',
      'BPix1+FPix2_neg',
      'BPix2+FPix1_pos',
      'BPix2+FPix1_neg',
      'BPix2+FPix2_pos',
      'BPix2+FPix2_neg',
      'FPix1_pos+FPix2_pos',
      'FPix1_neg+FPix2_neg' ),
    MTOB = cms.PSet(  ),
    TEC = cms.PSet(  ),
    MTID = cms.PSet(  ),
    FPix = cms.PSet( 
      HitProducer = cms.string( "hltSiPixelRecHits" ),
      hitErrorRZ = cms.double( 0.0036 ),
      useErrorsFromParam = cms.bool( True ),
      TTRHBuilder = cms.string( "hltESPTTRHBuilderPixelOnly" ),
      skipClusters = cms.InputTag( "hltIter2ElectronsClustersRefRemoval" ),
      hitErrorRPhi = cms.double( 0.0051 )
    ),
    MTEC = cms.PSet(  ),
    MTIB = cms.PSet(  ),
    TID = cms.PSet(  ),
    TOB = cms.PSet(  ),
    BPix = cms.PSet( 
      HitProducer = cms.string( "hltSiPixelRecHits" ),
      hitErrorRZ = cms.double( 0.006 ),
      useErrorsFromParam = cms.bool( True ),
      TTRHBuilder = cms.string( "hltESPTTRHBuilderPixelOnly" ),
      skipClusters = cms.InputTag( "hltIter2ElectronsClustersRefRemoval" ),
      hitErrorRPhi = cms.double( 0.0027 )
    ),
    TIB = cms.PSet(  )
)
process.hltIter2ElectronsPixelSeeds = cms.EDProducer( "SeedGeneratorFromRegionHitsEDProducer",
    RegionFactoryPSet = cms.PSet( 
      ComponentName = cms.string( "CandidateSeededTrackingRegionsProducer" ),
      RegionPSet = cms.PSet( 
        precise = cms.bool( True ),
        originRadius = cms.double( 0.05 ),
        ptMin = cms.double( 1.2 ),
        deltaEta = cms.double( 0.5 ),
        deltaPhi = cms.double( 0.5 ),
        vertexCollection = cms.InputTag( "hltPixelVerticesElectrons" ),
        input = cms.InputTag( "hltEgammaCandidates" ),
        mode = cms.string( "VerticesFixed" ),
        maxNRegions = cms.int32( 10 ),
        beamSpot = cms.InputTag( "hltOnlineBeamSpot" ),
        maxNVertices = cms.int32( 3 ),
        zErrorBeamSpot = cms.double( 24.2 ),
        nSigmaZVertex = cms.double( 3.0 ),
        nSigmaZBeamSpot = cms.double( 4.0 ),
        zErrorVetex = cms.double( 0.2 )
      )
    ),
    SeedComparitorPSet = cms.PSet(  ComponentName = cms.string( "none" ) ),
    ClusterCheckPSet = cms.PSet( 
      PixelClusterCollectionLabel = cms.InputTag( "hltSiPixelClusters" ),
      MaxNumberOfCosmicClusters = cms.uint32( 50000 ),
      doClusterCheck = cms.bool( False ),
      ClusterCollectionLabel = cms.InputTag( "hltSiStripClusters" ),
      MaxNumberOfPixelClusters = cms.uint32( 10000 )
    ),
    OrderedHitsFactoryPSet = cms.PSet( 
      maxElement = cms.uint32( 0 ),
      ComponentName = cms.string( "StandardHitPairGenerator" ),
      GeneratorPSet = cms.PSet( 
        maxElement = cms.uint32( 100000 ),
        SeedComparitorPSet = cms.PSet(  ComponentName = cms.string( "none" ) )
      ),
      SeedingLayers = cms.InputTag( "hltIter2ElectronsPixelLayerPairs" )
    ),
    SeedCreatorPSet = cms.PSet( 
      ComponentName = cms.string( "SeedFromConsecutiveHitsCreator" ),
      propagator = cms.string( "PropagatorWithMaterialParabolicMf" ),
      SeedMomentumForBOFF = cms.double( 5.0 ),
      TTRHBuilder = cms.string( "hltESPTTRHBWithTrackAngle" )
    ),
    TTRHBuilder = cms.string( "(unused)" )
)
process.hltIter2ElectronsCkfTrackCandidates = cms.EDProducer( "CkfTrackCandidateMaker",
    src = cms.InputTag( "hltIter2ElectronsPixelSeeds" ),
    maxSeedsBeforeCleaning = cms.uint32( 1000 ),
    SimpleMagneticField = cms.string( "ParabolicMf" ),
    TransientInitialStateEstimatorParameters = cms.PSet( 
      propagatorAlongTISE = cms.string( "PropagatorWithMaterialParabolicMf" ),
      numberMeasurementsForFit = cms.int32( 4 ),
      propagatorOppositeTISE = cms.string( "PropagatorWithMaterialParabolicMfOpposite" )
    ),
    TrajectoryCleaner = cms.string( "hltESPTrajectoryCleanerBySharedHits" ),
    MeasurementTrackerEvent = cms.InputTag( "hltIter2ElectronsMaskedMeasurementTrackerEvent" ),
    cleanTrajectoryAfterInOut = cms.bool( False ),
    useHitsSplitting = cms.bool( False ),
    RedundantSeedCleaner = cms.string( "CachingSeedCleanerBySharedInput" ),
    doSeedingRegionRebuilding = cms.bool( False ),
    maxNSeeds = cms.uint32( 100000 ),
    TrajectoryBuilderPSet = cms.PSet(  refToPSet_ = cms.string( "HLTIter2PSetTrajectoryBuilderIT" ) ),
    NavigationSchool = cms.string( "SimpleNavigationSchool" ),
    TrajectoryBuilder = cms.string( "" )
)
process.hltIter2ElectronsCtfWithMaterialTracks = cms.EDProducer( "TrackProducer",
    src = cms.InputTag( "hltIter2ElectronsCkfTrackCandidates" ),
    SimpleMagneticField = cms.string( "ParabolicMf" ),
    clusterRemovalInfo = cms.InputTag( "" ),
    beamSpot = cms.InputTag( "hltOnlineBeamSpot" ),
    MeasurementTrackerEvent = cms.InputTag( "hltIter2ElectronsMaskedMeasurementTrackerEvent" ),
    Fitter = cms.string( "hltESPFittingSmootherIT" ),
    useHitsSplitting = cms.bool( False ),
    MeasurementTracker = cms.string( "" ),
    AlgorithmName = cms.string( "hltIterX" ),
    alias = cms.untracked.string( "ctfWithMaterialTracks" ),
    NavigationSchool = cms.string( "" ),
    TrajectoryInEvent = cms.bool( True ),
    TTRHBuilder = cms.string( "hltESPTTRHBWithTrackAngle" ),
    GeometricInnerState = cms.bool( True ),
    useSimpleMF = cms.bool( True ),
    Propagator = cms.string( "hltESPRungeKuttaTrackerPropagator" )
)
process.hltIter2ElectronsTrackSelectionHighPurity = cms.EDProducer( "AnalyticalTrackSelector",
    max_d0 = cms.double( 100.0 ),
    minNumber3DLayers = cms.uint32( 0 ),
    max_lostHitFraction = cms.double( 1.0 ),
    applyAbsCutsIfNoPV = cms.bool( False ),
    qualityBit = cms.string( "highPurity" ),
    minNumberLayers = cms.uint32( 3 ),
    chi2n_par = cms.double( 0.7 ),
    useVtxError = cms.bool( False ),
    nSigmaZ = cms.double( 3.0 ),
    dz_par2 = cms.vdouble( 0.4, 4.0 ),
    applyAdaptedPVCuts = cms.bool( True ),
    min_eta = cms.double( -9999.0 ),
    dz_par1 = cms.vdouble( 0.35, 4.0 ),
    copyTrajectories = cms.untracked.bool( True ),
    vtxNumber = cms.int32( -1 ),
    max_d0NoPV = cms.double( 100.0 ),
    keepAllTracks = cms.bool( False ),
    maxNumberLostLayers = cms.uint32( 1 ),
    beamspot = cms.InputTag( "hltOnlineBeamSpot" ),
    max_relpterr = cms.double( 9999.0 ),
    copyExtras = cms.untracked.bool( True ),
    max_z0NoPV = cms.double( 100.0 ),
    vertexCut = cms.string( "tracksSize>=3" ),
    max_z0 = cms.double( 100.0 ),
    useVertices = cms.bool( True ),
    min_nhits = cms.uint32( 0 ),
    src = cms.InputTag( "hltIter2ElectronsCtfWithMaterialTracks" ),
    max_minMissHitOutOrIn = cms.int32( 99 ),
    chi2n_no1Dmod_par = cms.double( 9999.0 ),
    vertices = cms.InputTag( "hltPixelVerticesElectrons" ),
    max_eta = cms.double( 9999.0 ),
    d0_par2 = cms.vdouble( 0.4, 4.0 ),
    d0_par1 = cms.vdouble( 0.3, 4.0 ),
    res_par = cms.vdouble( 0.003, 0.001 ),
    minHitsToBypassChecks = cms.uint32( 20 )
)
process.hltIter2MergedForElectrons = cms.EDProducer( "TrackListMerger",
    ShareFrac = cms.double( 0.19 ),
    writeOnlyTrkQuals = cms.bool( False ),
    MinPT = cms.double( 0.05 ),
    allowFirstHitShare = cms.bool( True ),
    copyExtras = cms.untracked.bool( True ),
    Epsilon = cms.double( -0.001 ),
    selectedTrackQuals = cms.VInputTag( 'hltIter1MergedForElectrons','hltIter2ElectronsTrackSelectionHighPurity' ),
    indivShareFrac = cms.vdouble( 1.0, 1.0 ),
    MaxNormalizedChisq = cms.double( 1000.0 ),
    copyMVA = cms.bool( False ),
    FoundHitBonus = cms.double( 5.0 ),
    setsToMerge = cms.VPSet( 
      cms.PSet(  pQual = cms.bool( False ),
        tLists = cms.vint32( 0, 1 )
      )
    ),
    MinFound = cms.int32( 3 ),
    hasSelector = cms.vint32( 0, 0 ),
    TrackProducers = cms.VInputTag( 'hltIter1MergedForElectrons','hltIter2ElectronsTrackSelectionHighPurity' ),
    LostHitPenalty = cms.double( 20.0 ),
    newQuality = cms.string( "confirmed" )
)
process.hltEgammaEleGsfTrackIso = cms.EDProducer( "EgammaHLTElectronTrackIsolationProducers",
    egTrkIsoStripEndcap = cms.double( 0.03 ),
    egTrkIsoVetoConeSizeBarrel = cms.double( 0.03 ),
    useGsfTrack = cms.bool( True ),
    useSCRefs = cms.bool( True ),
    trackProducer = cms.InputTag( "hltIter2MergedForElectrons" ),
    egTrkIsoStripBarrel = cms.double( 0.03 ),
    electronProducer = cms.InputTag( "hltEgammaGsfElectrons" ),
    egTrkIsoConeSize = cms.double( 0.3 ),
    egTrkIsoRSpan = cms.double( 999999.0 ),
    egTrkIsoVetoConeSizeEndcap = cms.double( 0.03 ),
    recoEcalCandidateProducer = cms.InputTag( "hltEgammaCandidates" ),
    beamSpotProducer = cms.InputTag( "hltOnlineBeamSpot" ),
    egTrkIsoPtMin = cms.double( 1.0 ),
    egTrkIsoZSpan = cms.double( 0.15 )
)
process.hltSingleEle22WP75GsfTrackIsoFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( True ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( -1.0 ),
    thrOverEEE = cms.double( 0.05 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.05 ),
    thrRegularEB = cms.double( -1.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaEleGsfTrackIso" ),
    candTag = cms.InputTag( "hltSingleEle22WP75GsfDphiFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltBoolEnd = cms.EDFilter( "HLTBool",
    result = cms.bool( True )
)
process.hltL1sL1SingleEG40ORL1SingleIsoEG30er = cms.EDFilter( "HLTLevel1GTSeed",
    L1SeedsLogicalExpression = cms.string( "L1_SingleEG40 OR L1_SingleIsoEG30er" ),
    saveTags = cms.bool( True ),
    L1MuonCollectionTag = cms.InputTag( "hltL1extraParticles" ),
    L1UseL1TriggerObjectMaps = cms.bool( True ),
    L1UseAliasesForSeeding = cms.bool( True ),
    L1GtReadoutRecordTag = cms.InputTag( "hltGtDigis" ),
    L1CollectionsTag = cms.InputTag( "hltL1extraParticles" ),
    L1NrBxInEvent = cms.int32( 3 ),
    L1GtObjectMapTag = cms.InputTag( "hltL1GtObjectMap" ),
    L1TechTriggerSeeding = cms.bool( False )
)
process.hltPreEle35eta2p1WP85Gsf = cms.EDFilter( "HLTPrescaler",
    L1GtReadoutRecordTag = cms.InputTag( "hltGtDigis" ),
    offset = cms.uint32( 0 )
)
process.hltEGL1SingleEG40ORL1SingleIsoEG30erFilter = cms.EDFilter( "HLTEgammaL1MatchFilterRegional",
    doIsolated = cms.bool( False ),
    endcap_end = cms.double( 2.65 ),
    saveTags = cms.bool( False ),
    region_eta_size_ecap = cms.double( 1.0 ),
    barrel_end = cms.double( 1.4791 ),
    l1IsolatedTag = cms.InputTag( 'hltL1extraParticles','Isolated' ),
    candIsolatedTag = cms.InputTag( "hltEgammaCandidates" ),
    region_phi_size = cms.double( 1.044 ),
    region_eta_size = cms.double( 0.522 ),
    L1SeedFilterTag = cms.InputTag( "hltL1sL1SingleEG40ORL1SingleIsoEG30er" ),
    candNonIsolatedTag = cms.InputTag( "" ),
    l1NonIsolatedTag = cms.InputTag( 'hltL1extraParticles','NonIsolated' ),
    ncandcut = cms.int32( 1 )
)
process.hltEG35EtFilter = cms.EDFilter( "HLTEgammaEtFilter",
    saveTags = cms.bool( False ),
    L1NonIsoCand = cms.InputTag( "" ),
    relaxed = cms.untracked.bool( False ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    inputTag = cms.InputTag( "hltEGL1SingleEG40ORL1SingleIsoEG30erFilter" ),
    etcutEB = cms.double( 35.0 ),
    etcutEE = cms.double( 35.0 ),
    ncandcut = cms.int32( 1 )
)
process.hltEle35WP85ClusterShapeFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.033 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.011 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( False ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaClusterShape','sigmaIEtaIEta5x5' ),
    candTag = cms.InputTag( "hltEG35EtFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle35WP85HEFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( -1.0 ),
    thrOverEEE = cms.double( 0.2 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.15 ),
    thrRegularEB = cms.double( -1.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( False ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaHoverE" ),
    candTag = cms.InputTag( "hltEle35WP85ClusterShapeFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle35WP85EcalIsoFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( -1.0 ),
    thrOverEEE = cms.double( 0.12 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.16 ),
    thrRegularEB = cms.double( -1.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaEcalPFClusterIso" ),
    candTag = cms.InputTag( "hltEle35WP85HEFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle35WP85HcalIsoFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( -1.0 ),
    thrOverEEE = cms.double( 0.3 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.2 ),
    thrRegularEB = cms.double( -1.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaHcalPFClusterIso" ),
    candTag = cms.InputTag( "hltEle35WP85EcalIsoFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle35WP85PixelMatchFilter = cms.EDFilter( "HLTElectronPixelMatchFilter",
    saveTags = cms.bool( False ),
    s2_threshold = cms.double( 0.4 ),
    npixelmatchcut = cms.double( 1.0 ),
    tanhSO10InterThres = cms.double( 1.0 ),
    pixelVeto = cms.bool( False ),
    doIsolated = cms.bool( True ),
    s_a_phi1B = cms.double( 0.0069 ),
    s_a_phi1F = cms.double( 0.0076 ),
    s_a_phi1I = cms.double( 0.0088 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    candTag = cms.InputTag( "hltEle35WP85HcalIsoFilter" ),
    tanhSO10ForwardThres = cms.double( 1.0 ),
    L1IsoPixelSeedsTag = cms.InputTag( "hltEgammaElectronPixelSeeds" ),
    L1NonIsoCand = cms.InputTag( "" ),
    ncandcut = cms.int32( 1 ),
    tanhSO10BarrelThres = cms.double( 0.35 ),
    s_a_rF = cms.double( 0.04 ),
    L1NonIsoPixelSeedsTag = cms.InputTag( "" ),
    s_a_rI = cms.double( 0.027 ),
    s_a_phi2I = cms.double( 7.0E-4 ),
    useS = cms.bool( False ),
    s_a_phi2B = cms.double( 3.7E-4 ),
    s_a_zB = cms.double( 0.012 ),
    s_a_phi2F = cms.double( 0.00906 )
)
process.hltEle35WP85GsfOneOEMinusOneOPFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.009 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.012 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','OneOESuperMinusOneOP' ),
    candTag = cms.InputTag( "hltEle35WP85PixelMatchFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle35WP85GsfMissingHitsFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 1.0 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 999.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','MissingHits' ),
    candTag = cms.InputTag( "hltEle35WP85GsfOneOEMinusOneOPFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle35WP85GsfDetaFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.01 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.005 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','Deta' ),
    candTag = cms.InputTag( "hltEle35WP85GsfMissingHitsFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle35WP85GsfDphiFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.03 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.03 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','Dphi' ),
    candTag = cms.InputTag( "hltEle35WP85GsfDetaFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle35WP85GsfTrackIsoFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( True ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( -1.0 ),
    thrOverEEE = cms.double( 0.05 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.05 ),
    thrRegularEB = cms.double( -1.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaEleGsfTrackIso" ),
    candTag = cms.InputTag( "hltEle35WP85GsfDphiFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltPreEle40eta2p1WP85Gsf = cms.EDFilter( "HLTPrescaler",
    L1GtReadoutRecordTag = cms.InputTag( "hltGtDigis" ),
    offset = cms.uint32( 0 )
)
process.hltEG40EtFilter = cms.EDFilter( "HLTEgammaEtFilter",
    saveTags = cms.bool( False ),
    L1NonIsoCand = cms.InputTag( "" ),
    relaxed = cms.untracked.bool( False ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    inputTag = cms.InputTag( "hltEGL1SingleEG40ORL1SingleIsoEG30erFilter" ),
    etcutEB = cms.double( 40.0 ),
    etcutEE = cms.double( 40.0 ),
    ncandcut = cms.int32( 1 )
)
process.hltEle40WP85ClusterShapeFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.033 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.011 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( False ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaClusterShape','sigmaIEtaIEta5x5' ),
    candTag = cms.InputTag( "hltEG40EtFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle40WP85HEFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( -1.0 ),
    thrOverEEE = cms.double( 0.2 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.15 ),
    thrRegularEB = cms.double( -1.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( False ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaHoverE" ),
    candTag = cms.InputTag( "hltEle40WP85ClusterShapeFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle40WP85EcalIsoFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( -1.0 ),
    thrOverEEE = cms.double( 0.12 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.16 ),
    thrRegularEB = cms.double( -1.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaEcalPFClusterIso" ),
    candTag = cms.InputTag( "hltEle40WP85HEFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle40WP85HcalIsoFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( -1.0 ),
    thrOverEEE = cms.double( 0.3 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.2 ),
    thrRegularEB = cms.double( -1.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaHcalPFClusterIso" ),
    candTag = cms.InputTag( "hltEle40WP85EcalIsoFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle40WP85PixelMatchFilter = cms.EDFilter( "HLTElectronPixelMatchFilter",
    saveTags = cms.bool( False ),
    s2_threshold = cms.double( 0.4 ),
    npixelmatchcut = cms.double( 1.0 ),
    tanhSO10InterThres = cms.double( 1.0 ),
    pixelVeto = cms.bool( False ),
    doIsolated = cms.bool( True ),
    s_a_phi1B = cms.double( 0.0069 ),
    s_a_phi1F = cms.double( 0.0076 ),
    s_a_phi1I = cms.double( 0.0088 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    candTag = cms.InputTag( "hltEle40WP85HcalIsoFilter" ),
    tanhSO10ForwardThres = cms.double( 1.0 ),
    L1IsoPixelSeedsTag = cms.InputTag( "hltEgammaElectronPixelSeeds" ),
    L1NonIsoCand = cms.InputTag( "" ),
    ncandcut = cms.int32( 1 ),
    tanhSO10BarrelThres = cms.double( 0.35 ),
    s_a_rF = cms.double( 0.04 ),
    L1NonIsoPixelSeedsTag = cms.InputTag( "" ),
    s_a_rI = cms.double( 0.027 ),
    s_a_phi2I = cms.double( 7.0E-4 ),
    useS = cms.bool( False ),
    s_a_phi2B = cms.double( 3.7E-4 ),
    s_a_zB = cms.double( 0.012 ),
    s_a_phi2F = cms.double( 0.00906 )
)
process.hltEle40WP85GsfOneOEMinusOneOPFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.009 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.012 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','OneOESuperMinusOneOP' ),
    candTag = cms.InputTag( "hltEle40WP85PixelMatchFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle40WP85GsfMissingHitsFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 1.0 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 999.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','MissingHits' ),
    candTag = cms.InputTag( "hltEle40WP85GsfOneOEMinusOneOPFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle40WP85GsfDetaFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.01 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.005 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','Deta' ),
    candTag = cms.InputTag( "hltEle40WP85GsfMissingHitsFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle40WP85GsfDphiFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.03 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.03 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','Dphi' ),
    candTag = cms.InputTag( "hltEle40WP85GsfDetaFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle40WP85GsfTrackIsoFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( True ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( -1.0 ),
    thrOverEEE = cms.double( 0.05 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.05 ),
    thrRegularEB = cms.double( -1.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaEleGsfTrackIso" ),
    candTag = cms.InputTag( "hltEle40WP85GsfDphiFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltL1sL1SingleEG20 = cms.EDFilter( "HLTLevel1GTSeed",
    L1SeedsLogicalExpression = cms.string( "L1_SingleEG20" ),
    saveTags = cms.bool( True ),
    L1MuonCollectionTag = cms.InputTag( "hltL1extraParticles" ),
    L1UseL1TriggerObjectMaps = cms.bool( True ),
    L1UseAliasesForSeeding = cms.bool( True ),
    L1GtReadoutRecordTag = cms.InputTag( "hltGtDigis" ),
    L1CollectionsTag = cms.InputTag( "hltL1extraParticles" ),
    L1NrBxInEvent = cms.int32( 3 ),
    L1GtObjectMapTag = cms.InputTag( "hltL1GtObjectMap" ),
    L1TechTriggerSeeding = cms.bool( False )
)
process.hltPreEle23WP75Gsf = cms.EDFilter( "HLTPrescaler",
    L1GtReadoutRecordTag = cms.InputTag( "hltGtDigis" ),
    offset = cms.uint32( 0 )
)
process.hltEGL1SingleEG20Filter = cms.EDFilter( "HLTEgammaL1MatchFilterRegional",
    doIsolated = cms.bool( False ),
    endcap_end = cms.double( 2.65 ),
    saveTags = cms.bool( False ),
    region_eta_size_ecap = cms.double( 1.0 ),
    barrel_end = cms.double( 1.4791 ),
    l1IsolatedTag = cms.InputTag( 'hltL1extraParticles','Isolated' ),
    candIsolatedTag = cms.InputTag( "hltEgammaCandidates" ),
    region_phi_size = cms.double( 1.044 ),
    region_eta_size = cms.double( 0.522 ),
    L1SeedFilterTag = cms.InputTag( "hltL1sL1SingleEG20" ),
    candNonIsolatedTag = cms.InputTag( "" ),
    l1NonIsolatedTag = cms.InputTag( 'hltL1extraParticles','NonIsolated' ),
    ncandcut = cms.int32( 1 )
)
process.hltEG23EtL1EG20Filter = cms.EDFilter( "HLTEgammaEtFilter",
    saveTags = cms.bool( False ),
    L1NonIsoCand = cms.InputTag( "" ),
    relaxed = cms.untracked.bool( False ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    inputTag = cms.InputTag( "hltEGL1SingleEG20Filter" ),
    etcutEB = cms.double( 23.0 ),
    etcutEE = cms.double( 23.0 ),
    ncandcut = cms.int32( 1 )
)
process.hltEle23WP75ClusterShapeFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( True ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.031 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.011 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( False ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaClusterShape','sigmaIEtaIEta5x5' ),
    candTag = cms.InputTag( "hltEG23EtL1EG20Filter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle23WP75HcEFilter = cms.EDFilter( "HLTEgammaGenericQuadraticFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( 0.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( True ),
    thrOverE2EB = cms.double( 0.0 ),
    thrRegularEE = cms.double( 13.0 ),
    thrOverEEE = cms.double( 0.01 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.01 ),
    thrRegularEB = cms.double( 4.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( False ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaHoverE" ),
    candTag = cms.InputTag( "hltEle23WP75ClusterShapeFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle23WP75EcalIsoFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( True ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( -1.0 ),
    thrOverEEE = cms.double( 0.14 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.21 ),
    thrRegularEB = cms.double( -1.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaEcalPFClusterIso" ),
    candTag = cms.InputTag( "hltEle23WP75HcEFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle23WP75HcalIsoFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( True ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( -1.0 ),
    thrOverEEE = cms.double( 0.21 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.11 ),
    thrRegularEB = cms.double( -1.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaHcalPFClusterIso" ),
    candTag = cms.InputTag( "hltEle23WP75EcalIsoFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle23WP75PixelMatchFilter = cms.EDFilter( "HLTElectronPixelMatchFilter",
    saveTags = cms.bool( True ),
    s2_threshold = cms.double( 0.4 ),
    npixelmatchcut = cms.double( 1.0 ),
    tanhSO10InterThres = cms.double( 1.0 ),
    pixelVeto = cms.bool( False ),
    doIsolated = cms.bool( True ),
    s_a_phi1B = cms.double( 0.0069 ),
    s_a_phi1F = cms.double( 0.0076 ),
    s_a_phi1I = cms.double( 0.0088 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    candTag = cms.InputTag( "hltEle23WP75HcalIsoFilter" ),
    tanhSO10ForwardThres = cms.double( 1.0 ),
    L1IsoPixelSeedsTag = cms.InputTag( "hltEgammaElectronPixelSeeds" ),
    L1NonIsoCand = cms.InputTag( "" ),
    ncandcut = cms.int32( 1 ),
    tanhSO10BarrelThres = cms.double( 0.35 ),
    s_a_rF = cms.double( 0.04 ),
    L1NonIsoPixelSeedsTag = cms.InputTag( "" ),
    s_a_rI = cms.double( 0.027 ),
    s_a_phi2I = cms.double( 7.0E-4 ),
    useS = cms.bool( False ),
    s_a_phi2B = cms.double( 3.7E-4 ),
    s_a_zB = cms.double( 0.012 ),
    s_a_phi2F = cms.double( 0.00906 )
)
process.hltEle23WP75GsfOneOEMinusOneOPFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( True ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.032 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.032 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','OneOESuperMinusOneOP' ),
    candTag = cms.InputTag( "hltEle23WP75PixelMatchFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle23WP75GsfChi2Filter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( True ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 2.8 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 3.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','Chi2' ),
    candTag = cms.InputTag( "hltEle23WP75GsfOneOEMinusOneOPFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle23WP75GsfDetaFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( True ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.0065 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.0035 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','Deta' ),
    candTag = cms.InputTag( "hltEle23WP75GsfChi2Filter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle23WP75GsfDphiFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( True ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.035 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.021 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','Dphi' ),
    candTag = cms.InputTag( "hltEle23WP75GsfDetaFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle23WP75GsfTrackIsoFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( True ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( -1.0 ),
    thrOverEEE = cms.double( 0.05 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.05 ),
    thrRegularEB = cms.double( -1.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaEleGsfTrackIso" ),
    candTag = cms.InputTag( "hltEle23WP75GsfDphiFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltL1sL1SingleEG25 = cms.EDFilter( "HLTLevel1GTSeed",
    L1SeedsLogicalExpression = cms.string( "L1_SingleEG25" ),
    saveTags = cms.bool( True ),
    L1MuonCollectionTag = cms.InputTag( "hltL1extraParticles" ),
    L1UseL1TriggerObjectMaps = cms.bool( True ),
    L1UseAliasesForSeeding = cms.bool( True ),
    L1GtReadoutRecordTag = cms.InputTag( "hltGtDigis" ),
    L1CollectionsTag = cms.InputTag( "hltL1extraParticles" ),
    L1NrBxInEvent = cms.int32( 3 ),
    L1GtObjectMapTag = cms.InputTag( "hltL1GtObjectMap" ),
    L1TechTriggerSeeding = cms.bool( False )
)
process.hltPreEle27WP85Gsf = cms.EDFilter( "HLTPrescaler",
    L1GtReadoutRecordTag = cms.InputTag( "hltGtDigis" ),
    offset = cms.uint32( 0 )
)
process.hltEGL1SingleEG25Filter = cms.EDFilter( "HLTEgammaL1MatchFilterRegional",
    doIsolated = cms.bool( False ),
    endcap_end = cms.double( 2.65 ),
    saveTags = cms.bool( False ),
    region_eta_size_ecap = cms.double( 1.0 ),
    barrel_end = cms.double( 1.4791 ),
    l1IsolatedTag = cms.InputTag( 'hltL1extraParticles','Isolated' ),
    candIsolatedTag = cms.InputTag( "hltEgammaCandidates" ),
    region_phi_size = cms.double( 1.044 ),
    region_eta_size = cms.double( 0.522 ),
    L1SeedFilterTag = cms.InputTag( "hltL1sL1SingleEG25" ),
    candNonIsolatedTag = cms.InputTag( "" ),
    l1NonIsolatedTag = cms.InputTag( 'hltL1extraParticles','NonIsolated' ),
    ncandcut = cms.int32( 1 )
)
process.hltL1EG25EG27EtFilter = cms.EDFilter( "HLTEgammaEtFilter",
    saveTags = cms.bool( False ),
    L1NonIsoCand = cms.InputTag( "" ),
    relaxed = cms.untracked.bool( False ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    inputTag = cms.InputTag( "hltEGL1SingleEG25Filter" ),
    etcutEB = cms.double( 27.0 ),
    etcutEE = cms.double( 27.0 ),
    ncandcut = cms.int32( 1 )
)
process.hltL1EG25Ele27WP85ClusterShapeFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.033 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.011 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( False ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaClusterShape','sigmaIEtaIEta5x5' ),
    candTag = cms.InputTag( "hltL1EG25EG27EtFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltL1EG25Ele27WP85HEFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( -1.0 ),
    thrOverEEE = cms.double( 0.2 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.15 ),
    thrRegularEB = cms.double( -1.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( False ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaHoverE" ),
    candTag = cms.InputTag( "hltL1EG25Ele27WP85ClusterShapeFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltL1EG25Ele27WP85EcalIsoFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( -1.0 ),
    thrOverEEE = cms.double( 0.12 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.16 ),
    thrRegularEB = cms.double( -1.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaEcalPFClusterIso" ),
    candTag = cms.InputTag( "hltL1EG25Ele27WP85HEFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltL1EG25Ele27WP85HcalIsoFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( -1.0 ),
    thrOverEEE = cms.double( 0.3 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.2 ),
    thrRegularEB = cms.double( -1.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaHcalPFClusterIso" ),
    candTag = cms.InputTag( "hltL1EG25Ele27WP85EcalIsoFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltL1EG25Ele27WP85PixelMatchFilter = cms.EDFilter( "HLTElectronPixelMatchFilter",
    saveTags = cms.bool( False ),
    s2_threshold = cms.double( 0.4 ),
    npixelmatchcut = cms.double( 1.0 ),
    tanhSO10InterThres = cms.double( 1.0 ),
    pixelVeto = cms.bool( False ),
    doIsolated = cms.bool( True ),
    s_a_phi1B = cms.double( 0.0069 ),
    s_a_phi1F = cms.double( 0.0076 ),
    s_a_phi1I = cms.double( 0.0088 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    candTag = cms.InputTag( "hltL1EG25Ele27WP85HcalIsoFilter" ),
    tanhSO10ForwardThres = cms.double( 1.0 ),
    L1IsoPixelSeedsTag = cms.InputTag( "hltEgammaElectronPixelSeeds" ),
    L1NonIsoCand = cms.InputTag( "" ),
    ncandcut = cms.int32( 1 ),
    tanhSO10BarrelThres = cms.double( 0.35 ),
    s_a_rF = cms.double( 0.04 ),
    L1NonIsoPixelSeedsTag = cms.InputTag( "" ),
    s_a_rI = cms.double( 0.027 ),
    s_a_phi2I = cms.double( 7.0E-4 ),
    useS = cms.bool( False ),
    s_a_phi2B = cms.double( 3.7E-4 ),
    s_a_zB = cms.double( 0.012 ),
    s_a_phi2F = cms.double( 0.00906 )
)
process.hltL1EG25Ele27WP85GsfOneOEMinusOneOPFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.009 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.012 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','OneOESuperMinusOneOP' ),
    candTag = cms.InputTag( "hltL1EG25Ele27WP85PixelMatchFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltL1EG25Ele27WP85GsfMissingHitsFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 1.0 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 999.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','MissingHits' ),
    candTag = cms.InputTag( "hltL1EG25Ele27WP85GsfOneOEMinusOneOPFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltL1EG25Ele27WP85GsfDetaFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.01 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.005 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','Deta' ),
    candTag = cms.InputTag( "hltL1EG25Ele27WP85GsfMissingHitsFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltL1EG25Ele27WP85GsfDphiFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.03 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.03 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','Dphi' ),
    candTag = cms.InputTag( "hltL1EG25Ele27WP85GsfDetaFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltL1EG25Ele27WP85GsfTrackIsoFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( True ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( -1.0 ),
    thrOverEEE = cms.double( 0.05 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.05 ),
    thrRegularEB = cms.double( -1.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaEleGsfTrackIso" ),
    candTag = cms.InputTag( "hltL1EG25Ele27WP85GsfDphiFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltL1sL1SingleIsoEG22er = cms.EDFilter( "HLTLevel1GTSeed",
    L1SeedsLogicalExpression = cms.string( "L1_SingleIsoEG22er" ),
    saveTags = cms.bool( True ),
    L1MuonCollectionTag = cms.InputTag( "hltL1extraParticles" ),
    L1UseL1TriggerObjectMaps = cms.bool( True ),
    L1UseAliasesForSeeding = cms.bool( True ),
    L1GtReadoutRecordTag = cms.InputTag( "hltGtDigis" ),
    L1CollectionsTag = cms.InputTag( "hltL1extraParticles" ),
    L1NrBxInEvent = cms.int32( 3 ),
    L1GtObjectMapTag = cms.InputTag( "hltL1GtObjectMap" ),
    L1TechTriggerSeeding = cms.bool( False )
)
process.hltPreEle27eta2p1WP75Gsf = cms.EDFilter( "HLTPrescaler",
    L1GtReadoutRecordTag = cms.InputTag( "hltGtDigis" ),
    offset = cms.uint32( 0 )
)
process.hltEGL1SingleIsoEG22erFilter = cms.EDFilter( "HLTEgammaL1MatchFilterRegional",
    doIsolated = cms.bool( False ),
    endcap_end = cms.double( 2.65 ),
    saveTags = cms.bool( False ),
    region_eta_size_ecap = cms.double( 1.0 ),
    barrel_end = cms.double( 1.4791 ),
    l1IsolatedTag = cms.InputTag( 'hltL1extraParticles','Isolated' ),
    candIsolatedTag = cms.InputTag( "hltEgammaCandidates" ),
    region_phi_size = cms.double( 1.044 ),
    region_eta_size = cms.double( 0.522 ),
    L1SeedFilterTag = cms.InputTag( "hltL1sL1SingleIsoEG22er" ),
    candNonIsolatedTag = cms.InputTag( "" ),
    l1NonIsolatedTag = cms.InputTag( 'hltL1extraParticles','NonIsolated' ),
    ncandcut = cms.int32( 1 )
)
process.hltEG27EtL1IsoEG22erFilter = cms.EDFilter( "HLTEgammaEtFilter",
    saveTags = cms.bool( False ),
    L1NonIsoCand = cms.InputTag( "" ),
    relaxed = cms.untracked.bool( False ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    inputTag = cms.InputTag( "hltEGL1SingleIsoEG22erFilter" ),
    etcutEB = cms.double( 27.0 ),
    etcutEE = cms.double( 27.0 ),
    ncandcut = cms.int32( 1 )
)
process.hltEle27WP75ClusterShapeFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.031 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.011 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( False ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaClusterShape','sigmaIEtaIEta5x5' ),
    candTag = cms.InputTag( "hltEG27EtL1IsoEG22erFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle27WP75HcEFilter = cms.EDFilter( "HLTEgammaGenericQuadraticFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( 0.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( 0.0 ),
    thrRegularEE = cms.double( 13.0 ),
    thrOverEEE = cms.double( 0.01 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.01 ),
    thrRegularEB = cms.double( 4.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( False ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaHoverE" ),
    candTag = cms.InputTag( "hltEle27WP75ClusterShapeFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle27WP75EcalIsoFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( -1.0 ),
    thrOverEEE = cms.double( 0.14 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.21 ),
    thrRegularEB = cms.double( -1.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaEcalPFClusterIso" ),
    candTag = cms.InputTag( "hltEle27WP75HcEFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle27WP75HcalIsoFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( -1.0 ),
    thrOverEEE = cms.double( 0.21 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.11 ),
    thrRegularEB = cms.double( -1.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaHcalPFClusterIso" ),
    candTag = cms.InputTag( "hltEle27WP75EcalIsoFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle27WP75PixelMatchFilter = cms.EDFilter( "HLTElectronPixelMatchFilter",
    saveTags = cms.bool( False ),
    s2_threshold = cms.double( 0.4 ),
    npixelmatchcut = cms.double( 1.0 ),
    tanhSO10InterThres = cms.double( 1.0 ),
    pixelVeto = cms.bool( False ),
    doIsolated = cms.bool( True ),
    s_a_phi1B = cms.double( 0.0069 ),
    s_a_phi1F = cms.double( 0.0076 ),
    s_a_phi1I = cms.double( 0.0088 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    candTag = cms.InputTag( "hltEle27WP75HcalIsoFilter" ),
    tanhSO10ForwardThres = cms.double( 1.0 ),
    L1IsoPixelSeedsTag = cms.InputTag( "hltEgammaElectronPixelSeeds" ),
    L1NonIsoCand = cms.InputTag( "" ),
    ncandcut = cms.int32( 1 ),
    tanhSO10BarrelThres = cms.double( 0.35 ),
    s_a_rF = cms.double( 0.04 ),
    L1NonIsoPixelSeedsTag = cms.InputTag( "" ),
    s_a_rI = cms.double( 0.027 ),
    s_a_phi2I = cms.double( 7.0E-4 ),
    useS = cms.bool( False ),
    s_a_phi2B = cms.double( 3.7E-4 ),
    s_a_zB = cms.double( 0.012 ),
    s_a_phi2F = cms.double( 0.00906 )
)
process.hltEle27WP75GsfOneOEMinusOneOPFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.032 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.032 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','OneOESuperMinusOneOP' ),
    candTag = cms.InputTag( "hltEle27WP75PixelMatchFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle27WP75GsfChi2Filter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 2.8 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 3.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','Chi2' ),
    candTag = cms.InputTag( "hltEle27WP75GsfOneOEMinusOneOPFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle27WP75GsfDetaFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.0065 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.0035 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','Deta' ),
    candTag = cms.InputTag( "hltEle27WP75GsfChi2Filter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle27WP75GsfDphiFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.035 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.021 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','Dphi' ),
    candTag = cms.InputTag( "hltEle27WP75GsfDetaFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle27WP75GsfTrackIsoFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( True ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( -1.0 ),
    thrOverEEE = cms.double( 0.05 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.05 ),
    thrRegularEB = cms.double( -1.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaEleGsfTrackIso" ),
    candTag = cms.InputTag( "hltEle27WP75GsfDphiFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltL1sL1SingleIsoEG30er = cms.EDFilter( "HLTLevel1GTSeed",
    L1SeedsLogicalExpression = cms.string( "L1_SingleIsoEG30er" ),
    saveTags = cms.bool( True ),
    L1MuonCollectionTag = cms.InputTag( "hltL1extraParticles" ),
    L1UseL1TriggerObjectMaps = cms.bool( True ),
    L1UseAliasesForSeeding = cms.bool( True ),
    L1GtReadoutRecordTag = cms.InputTag( "hltGtDigis" ),
    L1CollectionsTag = cms.InputTag( "hltL1extraParticles" ),
    L1NrBxInEvent = cms.int32( 3 ),
    L1GtObjectMapTag = cms.InputTag( "hltL1GtObjectMap" ),
    L1TechTriggerSeeding = cms.bool( False )
)
process.hltPreEle32eta2p1WP75Gsf = cms.EDFilter( "HLTPrescaler",
    L1GtReadoutRecordTag = cms.InputTag( "hltGtDigis" ),
    offset = cms.uint32( 0 )
)
process.hltEGL1SingleIsoEG30erFilter = cms.EDFilter( "HLTEgammaL1MatchFilterRegional",
    doIsolated = cms.bool( False ),
    endcap_end = cms.double( 2.65 ),
    saveTags = cms.bool( False ),
    region_eta_size_ecap = cms.double( 1.0 ),
    barrel_end = cms.double( 1.4791 ),
    l1IsolatedTag = cms.InputTag( 'hltL1extraParticles','Isolated' ),
    candIsolatedTag = cms.InputTag( "hltEgammaCandidates" ),
    region_phi_size = cms.double( 1.044 ),
    region_eta_size = cms.double( 0.522 ),
    L1SeedFilterTag = cms.InputTag( "hltL1sL1SingleIsoEG30er" ),
    candNonIsolatedTag = cms.InputTag( "" ),
    l1NonIsolatedTag = cms.InputTag( 'hltL1extraParticles','NonIsolated' ),
    ncandcut = cms.int32( 1 )
)
process.hltEG32EtFilter = cms.EDFilter( "HLTEgammaEtFilter",
    saveTags = cms.bool( False ),
    L1NonIsoCand = cms.InputTag( "" ),
    relaxed = cms.untracked.bool( False ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    inputTag = cms.InputTag( "hltEGL1SingleIsoEG30erFilter" ),
    etcutEB = cms.double( 32.0 ),
    etcutEE = cms.double( 32.0 ),
    ncandcut = cms.int32( 1 )
)
process.hltEle32WP75ClusterShapeFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.031 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.011 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( False ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaClusterShape','sigmaIEtaIEta5x5' ),
    candTag = cms.InputTag( "hltEG32EtFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle32WP75HcEFilter = cms.EDFilter( "HLTEgammaGenericQuadraticFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( 0.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( 0.0 ),
    thrRegularEE = cms.double( 13.0 ),
    thrOverEEE = cms.double( 0.01 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.01 ),
    thrRegularEB = cms.double( 4.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( False ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaHoverE" ),
    candTag = cms.InputTag( "hltEle32WP75ClusterShapeFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle32WP75EcalIsoFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( -1.0 ),
    thrOverEEE = cms.double( 0.14 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.21 ),
    thrRegularEB = cms.double( -1.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaEcalPFClusterIso" ),
    candTag = cms.InputTag( "hltEle32WP75HcEFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle32WP75HcalIsoFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( -1.0 ),
    thrOverEEE = cms.double( 0.21 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.11 ),
    thrRegularEB = cms.double( -1.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaHcalPFClusterIso" ),
    candTag = cms.InputTag( "hltEle32WP75EcalIsoFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle32WP75PixelMatchFilter = cms.EDFilter( "HLTElectronPixelMatchFilter",
    saveTags = cms.bool( False ),
    s2_threshold = cms.double( 0.4 ),
    npixelmatchcut = cms.double( 1.0 ),
    tanhSO10InterThres = cms.double( 1.0 ),
    pixelVeto = cms.bool( False ),
    doIsolated = cms.bool( True ),
    s_a_phi1B = cms.double( 0.0069 ),
    s_a_phi1F = cms.double( 0.0076 ),
    s_a_phi1I = cms.double( 0.0088 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    candTag = cms.InputTag( "hltEle32WP75HcalIsoFilter" ),
    tanhSO10ForwardThres = cms.double( 1.0 ),
    L1IsoPixelSeedsTag = cms.InputTag( "hltEgammaElectronPixelSeeds" ),
    L1NonIsoCand = cms.InputTag( "" ),
    ncandcut = cms.int32( 1 ),
    tanhSO10BarrelThres = cms.double( 0.35 ),
    s_a_rF = cms.double( 0.04 ),
    L1NonIsoPixelSeedsTag = cms.InputTag( "" ),
    s_a_rI = cms.double( 0.027 ),
    s_a_phi2I = cms.double( 7.0E-4 ),
    useS = cms.bool( False ),
    s_a_phi2B = cms.double( 3.7E-4 ),
    s_a_zB = cms.double( 0.012 ),
    s_a_phi2F = cms.double( 0.00906 )
)
process.hltEle32WP75GsfOneOEMinusOneOPFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.032 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.032 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','OneOESuperMinusOneOP' ),
    candTag = cms.InputTag( "hltEle32WP75PixelMatchFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle32WP75GsfChi2Filter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 2.8 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 3.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','Chi2' ),
    candTag = cms.InputTag( "hltEle32WP75GsfOneOEMinusOneOPFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle32WP75GsfDetaFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.0065 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.0035 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','Deta' ),
    candTag = cms.InputTag( "hltEle32WP75GsfChi2Filter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle32WP75GsfDphiFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( False ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( 0.035 ),
    thrOverEEE = cms.double( -1.0 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( -1.0 ),
    thrRegularEB = cms.double( 0.021 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( 'hltEgammaGsfTrackVars','Dphi' ),
    candTag = cms.InputTag( "hltEle32WP75GsfDetaFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltEle32WP75GsfTrackIsoFilter = cms.EDFilter( "HLTEgammaGenericFilter",
    doIsolated = cms.bool( True ),
    thrOverE2EE = cms.double( -1.0 ),
    L1NonIsoCand = cms.InputTag( "" ),
    saveTags = cms.bool( True ),
    thrOverE2EB = cms.double( -1.0 ),
    thrRegularEE = cms.double( -1.0 ),
    thrOverEEE = cms.double( 0.05 ),
    L1IsoCand = cms.InputTag( "hltEgammaCandidates" ),
    thrOverEEB = cms.double( 0.05 ),
    thrRegularEB = cms.double( -1.0 ),
    lessThan = cms.bool( True ),
    useEt = cms.bool( True ),
    ncandcut = cms.int32( 1 ),
    isoTag = cms.InputTag( "hltEgammaEleGsfTrackIso" ),
    candTag = cms.InputTag( "hltEle32WP75GsfDphiFilter" ),
    nonIsoTag = cms.InputTag( "" )
)
process.hltFEDSelector = cms.EDProducer( "EvFFEDSelector",
    inputTag = cms.InputTag( "rawDataCollector" ),
    fedList = cms.vuint32( 1023 )
)
process.hltTriggerSummaryAOD = cms.EDProducer( "TriggerSummaryProducerAOD",
    processName = cms.string( "@" )
)
process.hltTriggerSummaryRAW = cms.EDProducer( "TriggerSummaryProducerRAW",
    processName = cms.string( "@" )
)
process.hltPreAOutput = cms.EDFilter( "HLTPrescaler",
    L1GtReadoutRecordTag = cms.InputTag( "hltGtDigis" ),
    offset = cms.uint32( 0 )
)
process.hltPreRPCMONOutput = cms.EDFilter( "HLTPrescaler",
    L1GtReadoutRecordTag = cms.InputTag( "hltGtDigis" ),
    offset = cms.uint32( 0 )
)
process.hltPreAlCaEcalPhiSym = cms.EDFilter( "HLTPrescaler",
    L1GtReadoutRecordTag = cms.InputTag( "hltGtDigis" ),
    offset = cms.uint32( 0 )
)

process.HLTL1UnpackerSequence = cms.Sequence( process.hltGtDigis + process.hltCaloStage1Digis + process.hltCaloStage1LegacyFormatDigis + process.hltL1GtObjectMap + process.hltL1extraParticles )
process.HLTBeamSpot = cms.Sequence( process.hltScalersRawToDigi + process.hltOnlineBeamSpot )
process.HLTBeginSequence = cms.Sequence( process.hltTriggerType + process.HLTL1UnpackerSequence + process.HLTBeamSpot )
process.HLTDoFullUnpackingEgammaEcalSequence = cms.Sequence( process.hltEcalDigis + process.hltEcalPreshowerDigis + process.hltEcalUncalibRecHit + process.hltEcalDetIdToBeRecovered + process.hltEcalRecHit + process.hltEcalPreshowerRecHit )
process.HLTPFClusteringForEgamma = cms.Sequence( process.hltRechitInRegionsECAL + process.hltRechitInRegionsES + process.hltParticleFlowRecHitECALL1Seeded + process.hltParticleFlowRecHitPSL1Seeded + process.hltParticleFlowClusterPSL1Seeded + process.hltParticleFlowClusterECALUncorrectedL1Seeded + process.hltParticleFlowClusterECALL1Seeded + process.hltParticleFlowSuperClusterECALL1Seeded )
process.HLTDoLocalHcalWithTowerSequence = cms.Sequence( process.hltHcalDigis + process.hltHbhereco + process.hltHfreco + process.hltHoreco + process.hltTowerMakerForAll )
process.HLTFastJetForEgamma = cms.Sequence( process.hltFixedGridRhoFastjetAllCaloForMuons )
process.HLTPFHcalClusteringForEgamma = cms.Sequence( process.hltRegionalTowerForEgamma + process.hltParticleFlowRecHitHCALForEgamma + process.hltParticleFlowClusterHCALForEgamma )
process.HLTDoLocalPixelSequence = cms.Sequence( process.hltSiPixelDigis + process.hltSiPixelClusters + process.hltSiPixelClustersCache + process.hltSiPixelRecHits )
process.HLTDoLocalStripSequence = cms.Sequence( process.hltSiStripExcludedFEDListProducer + process.hltSiStripRawToClustersFacility + process.hltSiStripClusters )
process.HLTGsfElectronSequence = cms.Sequence( process.hltEgammaCkfTrackCandidatesForGSF + process.hltEgammaGsfTracks + process.hltEgammaGsfElectrons + process.hltEgammaGsfTrackVars )
process.HLTRecoPixelVertexingForElectronSequence = cms.Sequence( process.hltPixelLayerTriplets + process.hltPixelTracksElectrons + process.hltPixelVerticesElectrons )
process.HLTPixelTrackingForElectron = cms.Sequence( process.hltElectronsVertex + process.HLTDoLocalPixelSequence + process.HLTRecoPixelVertexingForElectronSequence )
process.HLTIterativeTrackingForElectronsIteration0 = cms.Sequence( process.hltIter0ElectronsPixelSeedsFromPixelTracks + process.hltIter0ElectronsCkfTrackCandidates + process.hltIter0ElectronsCtfWithMaterialTracks + process.hltIter0ElectronsTrackSelectionHighPurity )
process.HLTIterativeTrackingForElectronsIteration1 = cms.Sequence( process.hltIter1ElectronsClustersRefRemoval + process.hltIter1ElectronsMaskedMeasurementTrackerEvent + process.hltIter1ElectronsPixelLayerTriplets + process.hltIter1ElectronsPixelSeeds + process.hltIter1ElectronsCkfTrackCandidates + process.hltIter1ElectronsCtfWithMaterialTracks + process.hltIter1ElectronsTrackSelectionHighPurityLoose + process.hltIter1ElectronsTrackSelectionHighPurityTight + process.hltIter1ElectronsTrackSelectionHighPurity )
process.HLTIterativeTrackingForElectronsIteration2 = cms.Sequence( process.hltIter2ElectronsClustersRefRemoval + process.hltIter2ElectronsMaskedMeasurementTrackerEvent + process.hltIter2ElectronsPixelLayerPairs + process.hltIter2ElectronsPixelSeeds + process.hltIter2ElectronsCkfTrackCandidates + process.hltIter2ElectronsCtfWithMaterialTracks + process.hltIter2ElectronsTrackSelectionHighPurity )
process.HLTIterativeTrackingForElectronIter02 = cms.Sequence( process.HLTIterativeTrackingForElectronsIteration0 + process.HLTIterativeTrackingForElectronsIteration1 + process.hltIter1MergedForElectrons + process.HLTIterativeTrackingForElectronsIteration2 + process.hltIter2MergedForElectrons )
process.HLTTrackReconstructionForIsoElectronIter02 = cms.Sequence( process.HLTPixelTrackingForElectron + process.HLTDoLocalStripSequence + process.HLTIterativeTrackingForElectronIter02 )
process.HLTSingleEle22erWP75GsfSequence = cms.Sequence( process.HLTDoFullUnpackingEgammaEcalSequence + process.HLTPFClusteringForEgamma + process.hltEgammaCandidates + process.hltEGL1SingleIsoEG20erFilter + process.hltSingleEG22EtFilter + process.hltEgammaClusterShape + process.hltSingleEle22WP75ClusterShapeFilter + process.HLTDoLocalHcalWithTowerSequence + process.HLTFastJetForEgamma + process.hltEgammaHoverE + process.hltSingleEle22WP75HcEFilter + process.hltEgammaEcalPFClusterIso + process.hltSingleEle22WP75EcalIsoFilter + process.HLTPFHcalClusteringForEgamma + process.hltEgammaHcalPFClusterIso + process.hltSingleEle22WP75HcalIsoFilter + process.HLTDoLocalPixelSequence + process.HLTDoLocalStripSequence + process.hltMixedLayerPairs + process.hltEgammaElectronPixelSeeds + process.hltSingleEle22WP75PixelMatchFilter + process.HLTGsfElectronSequence + process.hltSingleEle22WP75GsfOneOESuperMinusOneOPFilter + process.hltSingleEle22WP75GsfChi2Filter + process.hltSingleEle22WP75GsfDetaFilter + process.hltSingleEle22WP75GsfDphiFilter + process.HLTTrackReconstructionForIsoElectronIter02 + process.hltEgammaEleGsfTrackIso + process.hltSingleEle22WP75GsfTrackIsoFilter )
process.HLTEndSequence = cms.Sequence( process.hltBoolEnd )
process.HLTEle35WP85GsfSequence = cms.Sequence( process.HLTDoFullUnpackingEgammaEcalSequence + process.HLTPFClusteringForEgamma + process.hltEgammaCandidates + process.hltEGL1SingleEG40ORL1SingleIsoEG30erFilter + process.hltEG35EtFilter + process.hltEgammaClusterShape + process.hltEle35WP85ClusterShapeFilter + process.HLTDoLocalHcalWithTowerSequence + process.HLTFastJetForEgamma + process.hltEgammaHoverE + process.hltEle35WP85HEFilter + process.hltEgammaEcalPFClusterIso + process.hltEle35WP85EcalIsoFilter + process.HLTPFHcalClusteringForEgamma + process.hltEgammaHcalPFClusterIso + process.hltEle35WP85HcalIsoFilter + process.HLTDoLocalPixelSequence + process.HLTDoLocalStripSequence + process.hltMixedLayerPairs + process.hltEgammaElectronPixelSeeds + process.hltEle35WP85PixelMatchFilter + process.HLTGsfElectronSequence + process.hltEle35WP85GsfOneOEMinusOneOPFilter + process.hltEle35WP85GsfMissingHitsFilter + process.hltEle35WP85GsfDetaFilter + process.hltEle35WP85GsfDphiFilter + process.HLTTrackReconstructionForIsoElectronIter02 + process.hltEgammaEleGsfTrackIso + process.hltEle35WP85GsfTrackIsoFilter )
process.HLTEle40WP85GsfSequence = cms.Sequence( process.HLTDoFullUnpackingEgammaEcalSequence + process.HLTPFClusteringForEgamma + process.hltEgammaCandidates + process.hltEGL1SingleEG40ORL1SingleIsoEG30erFilter + process.hltEG40EtFilter + process.hltEgammaClusterShape + process.hltEle40WP85ClusterShapeFilter + process.HLTDoLocalHcalWithTowerSequence + process.HLTFastJetForEgamma + process.hltEgammaHoverE + process.hltEle40WP85HEFilter + process.hltEgammaEcalPFClusterIso + process.hltEle40WP85EcalIsoFilter + process.HLTPFHcalClusteringForEgamma + process.hltEgammaHcalPFClusterIso + process.hltEle40WP85HcalIsoFilter + process.HLTDoLocalPixelSequence + process.HLTDoLocalStripSequence + process.hltMixedLayerPairs + process.hltEgammaElectronPixelSeeds + process.hltEle40WP85PixelMatchFilter + process.HLTGsfElectronSequence + process.hltEle40WP85GsfOneOEMinusOneOPFilter + process.hltEle40WP85GsfMissingHitsFilter + process.hltEle40WP85GsfDetaFilter + process.hltEle40WP85GsfDphiFilter + process.HLTTrackReconstructionForIsoElectronIter02 + process.hltEgammaEleGsfTrackIso + process.hltEle40WP85GsfTrackIsoFilter )
process.HLTEle23WP75GsfSequence = cms.Sequence( process.HLTDoFullUnpackingEgammaEcalSequence + process.HLTPFClusteringForEgamma + process.hltEgammaCandidates + process.hltEGL1SingleEG20Filter + process.hltEG23EtL1EG20Filter + process.hltEgammaClusterShape + process.hltEle23WP75ClusterShapeFilter + process.HLTDoLocalHcalWithTowerSequence + process.HLTFastJetForEgamma + process.hltEgammaHoverE + process.hltEle23WP75HcEFilter + process.hltEgammaEcalPFClusterIso + process.hltEle23WP75EcalIsoFilter + process.HLTPFHcalClusteringForEgamma + process.hltEgammaHcalPFClusterIso + process.hltEle23WP75HcalIsoFilter + process.HLTDoLocalPixelSequence + process.HLTDoLocalStripSequence + process.hltMixedLayerPairs + process.hltEgammaElectronPixelSeeds + process.hltEle23WP75PixelMatchFilter + process.HLTGsfElectronSequence + process.hltEle23WP75GsfOneOEMinusOneOPFilter + process.hltEle23WP75GsfChi2Filter + process.hltEle23WP75GsfDetaFilter + process.hltEle23WP75GsfDphiFilter + process.HLTTrackReconstructionForIsoElectronIter02 + process.hltEgammaEleGsfTrackIso + process.hltEle23WP75GsfTrackIsoFilter )
process.HLTEle27WP85GsfSequence = cms.Sequence( process.HLTDoFullUnpackingEgammaEcalSequence + process.HLTPFClusteringForEgamma + process.hltEgammaCandidates + process.hltEGL1SingleEG25Filter + process.hltL1EG25EG27EtFilter + process.hltEgammaClusterShape + process.hltL1EG25Ele27WP85ClusterShapeFilter + process.HLTDoLocalHcalWithTowerSequence + process.HLTFastJetForEgamma + process.hltEgammaHoverE + process.hltL1EG25Ele27WP85HEFilter + process.hltEgammaEcalPFClusterIso + process.hltL1EG25Ele27WP85EcalIsoFilter + process.HLTPFHcalClusteringForEgamma + process.hltEgammaHcalPFClusterIso + process.hltL1EG25Ele27WP85HcalIsoFilter + process.HLTDoLocalPixelSequence + process.HLTDoLocalStripSequence + process.hltMixedLayerPairs + process.hltEgammaElectronPixelSeeds + process.hltL1EG25Ele27WP85PixelMatchFilter + process.HLTGsfElectronSequence + process.hltL1EG25Ele27WP85GsfOneOEMinusOneOPFilter + process.hltL1EG25Ele27WP85GsfMissingHitsFilter + process.hltL1EG25Ele27WP85GsfDetaFilter + process.hltL1EG25Ele27WP85GsfDphiFilter + process.HLTTrackReconstructionForIsoElectronIter02 + process.hltEgammaEleGsfTrackIso + process.hltL1EG25Ele27WP85GsfTrackIsoFilter )
process.HLTEle27erWP75GsfSequence = cms.Sequence( process.HLTDoFullUnpackingEgammaEcalSequence + process.HLTPFClusteringForEgamma + process.hltEgammaCandidates + process.hltEGL1SingleIsoEG22erFilter + process.hltEG27EtL1IsoEG22erFilter + process.hltEgammaClusterShape + process.hltEle27WP75ClusterShapeFilter + process.HLTDoLocalHcalWithTowerSequence + process.HLTFastJetForEgamma + process.hltEgammaHoverE + process.hltEle27WP75HcEFilter + process.hltEgammaEcalPFClusterIso + process.hltEle27WP75EcalIsoFilter + process.HLTPFHcalClusteringForEgamma + process.hltEgammaHcalPFClusterIso + process.hltEle27WP75HcalIsoFilter + process.HLTDoLocalPixelSequence + process.HLTDoLocalStripSequence + process.hltMixedLayerPairs + process.hltEgammaElectronPixelSeeds + process.hltEle27WP75PixelMatchFilter + process.HLTGsfElectronSequence + process.hltEle27WP75GsfOneOEMinusOneOPFilter + process.hltEle27WP75GsfChi2Filter + process.hltEle27WP75GsfDetaFilter + process.hltEle27WP75GsfDphiFilter + process.HLTTrackReconstructionForIsoElectronIter02 + process.hltEgammaEleGsfTrackIso + process.hltEle27WP75GsfTrackIsoFilter )
process.HLTEle32erWP75GsfSequence = cms.Sequence( process.HLTDoFullUnpackingEgammaEcalSequence + process.HLTPFClusteringForEgamma + process.hltEgammaCandidates + process.hltEGL1SingleIsoEG30erFilter + process.hltEG32EtFilter + process.hltEgammaClusterShape + process.hltEle32WP75ClusterShapeFilter + process.HLTDoLocalHcalWithTowerSequence + process.HLTFastJetForEgamma + process.hltEgammaHoverE + process.hltEle32WP75HcEFilter + process.hltEgammaEcalPFClusterIso + process.hltEle32WP75EcalIsoFilter + process.HLTPFHcalClusteringForEgamma + process.hltEgammaHcalPFClusterIso + process.hltEle32WP75HcalIsoFilter + process.HLTDoLocalPixelSequence + process.HLTDoLocalStripSequence + process.hltMixedLayerPairs + process.hltEgammaElectronPixelSeeds + process.hltEle32WP75PixelMatchFilter + process.HLTGsfElectronSequence + process.hltEle32WP75GsfOneOEMinusOneOPFilter + process.hltEle32WP75GsfChi2Filter + process.hltEle32WP75GsfDetaFilter + process.hltEle32WP75GsfDphiFilter + process.HLTTrackReconstructionForIsoElectronIter02 + process.hltEgammaEleGsfTrackIso + process.hltEle32WP75GsfTrackIsoFilter )

process.HLTriggerFirstPath = cms.Path( process.hltGetConditions + process.hltGetRaw + process.hltBoolFalse )
process.HLT_Ele22_eta2p1_WP75_Gsf_v1 = cms.Path( process.HLTBeginSequence + process.hltL1sL1SingleIsoEG20er + process.hltPreEle22eta2p1WP75Gsf + process.HLTSingleEle22erWP75GsfSequence + process.HLTEndSequence )
process.HLT_Ele35_eta2p1_WP85_Gsf_v1 = cms.Path( process.HLTBeginSequence + process.hltL1sL1SingleEG40ORL1SingleIsoEG30er + process.hltPreEle35eta2p1WP85Gsf + process.HLTEle35WP85GsfSequence + process.HLTEndSequence )
process.HLT_Ele40_eta2p1_WP85_Gsf_v1 = cms.Path( process.HLTBeginSequence + process.hltL1sL1SingleEG40ORL1SingleIsoEG30er + process.hltPreEle40eta2p1WP85Gsf + process.HLTEle40WP85GsfSequence + process.HLTEndSequence )
process.HLT_Ele23_WP75_Gsf_v1 = cms.Path( process.HLTBeginSequence + process.hltL1sL1SingleEG20 + process.hltPreEle23WP75Gsf + process.HLTEle23WP75GsfSequence + process.HLTEndSequence )
process.HLT_Ele27_WP85_Gsf_v1 = cms.Path( process.HLTBeginSequence + process.hltL1sL1SingleEG25 + process.hltPreEle27WP85Gsf + process.HLTEle27WP85GsfSequence + process.HLTEndSequence )
process.HLT_Ele27_eta2p1_WP75_Gsf_v1 = cms.Path( process.HLTBeginSequence + process.hltL1sL1SingleIsoEG22er + process.hltPreEle27eta2p1WP75Gsf + process.HLTEle27erWP75GsfSequence + process.HLTEndSequence )
process.HLT_Ele32_eta2p1_WP75_Gsf_v1 = cms.Path( process.HLTBeginSequence + process.hltL1sL1SingleIsoEG30er + process.hltPreEle32eta2p1WP75Gsf + process.HLTEle32erWP75GsfSequence + process.HLTEndSequence )
process.HLTriggerFinalPath = cms.Path( process.hltGtDigis + process.hltScalersRawToDigi + process.hltFEDSelector + process.hltTriggerSummaryAOD + process.hltTriggerSummaryRAW )

process.source = cms.Source( "PoolSource",
    fileNames = cms.untracked.vstring(
        #'/store/mc/Phys14DR/TT_Tune4C_13TeV-pythia8-tauola/AODSIM/PU40bx25_tsg_PHYS14_25_V1-v1/00000/00EEFBA5-4B70-E411-BAEA-0025905B85D6.root'
    ),
    secondaryFileNames = cms.untracked.vstring(
        #'/store/mc/Phys14DR/TT_Tune4C_13TeV-pythia8-tauola/GEN-SIM-RAW/PU40bx25_tsg_PHYS14_25_V1-v1/00000/04B3F0CC-2070-E411-9D83-0025905A60EE.root',
        #'/store/mc/Phys14DR/TT_Tune4C_13TeV-pythia8-tauola/GEN-SIM-RAW/PU40bx25_tsg_PHYS14_25_V1-v1/00000/10C61034-2070-E411-B8F9-0025905A60A8.root',
        #'/store/mc/Phys14DR/TT_Tune4C_13TeV-pythia8-tauola/GEN-SIM-RAW/PU40bx25_tsg_PHYS14_25_V1-v1/00000/18E5BEE2-1470-E411-A96A-002618943838.root',
        #'/store/mc/Phys14DR/TT_Tune4C_13TeV-pythia8-tauola/GEN-SIM-RAW/PU40bx25_tsg_PHYS14_25_V1-v1/00000/1E21EDD9-2070-E411-B68F-003048FFCB74.root',
        #'/store/mc/Phys14DR/TT_Tune4C_13TeV-pythia8-tauola/GEN-SIM-RAW/PU40bx25_tsg_PHYS14_25_V1-v1/00000/2ACCB8C5-2070-E411-97BC-0025905A60F8.root',
        #'/store/mc/Phys14DR/TT_Tune4C_13TeV-pythia8-tauola/GEN-SIM-RAW/PU40bx25_tsg_PHYS14_25_V1-v1/00000/2AF7304A-1770-E411-B1B7-0025905B861C.root',
        #'/store/mc/Phys14DR/TT_Tune4C_13TeV-pythia8-tauola/GEN-SIM-RAW/PU40bx25_tsg_PHYS14_25_V1-v1/00000/3465BF30-2070-E411-B605-0026189438D8.root',
        #'/store/mc/Phys14DR/TT_Tune4C_13TeV-pythia8-tauola/GEN-SIM-RAW/PU40bx25_tsg_PHYS14_25_V1-v1/00000/40626C3E-1170-E411-9A83-0025905B85AA.root',
        #'/store/mc/Phys14DR/TT_Tune4C_13TeV-pythia8-tauola/GEN-SIM-RAW/PU40bx25_tsg_PHYS14_25_V1-v1/00000/4458B212-1670-E411-9E52-0025905A6110.root',
        #'/store/mc/Phys14DR/TT_Tune4C_13TeV-pythia8-tauola/GEN-SIM-RAW/PU40bx25_tsg_PHYS14_25_V1-v1/00000/48CE8BE3-1470-E411-BC8F-0025905A6092.root',
        #'/store/mc/Phys14DR/TT_Tune4C_13TeV-pythia8-tauola/GEN-SIM-RAW/PU40bx25_tsg_PHYS14_25_V1-v1/00000/5C780CCB-2070-E411-8F5C-0025905B855E.root',
        #'/store/mc/Phys14DR/TT_Tune4C_13TeV-pythia8-tauola/GEN-SIM-RAW/PU40bx25_tsg_PHYS14_25_V1-v1/00000/8C692E33-2070-E411-BDEA-0025905A6060.root',
        #'/store/mc/Phys14DR/TT_Tune4C_13TeV-pythia8-tauola/GEN-SIM-RAW/PU40bx25_tsg_PHYS14_25_V1-v1/00000/944D9BB7-1F70-E411-9960-0026189438BF.root',
        #'/store/mc/Phys14DR/TT_Tune4C_13TeV-pythia8-tauola/GEN-SIM-RAW/PU40bx25_tsg_PHYS14_25_V1-v1/00000/AAAF6033-2070-E411-826D-0025905A60AA.root',
        #'/store/mc/Phys14DR/TT_Tune4C_13TeV-pythia8-tauola/GEN-SIM-RAW/PU40bx25_tsg_PHYS14_25_V1-v1/00000/BC112899-1070-E411-800F-0025905A6110.root',
        #'/store/mc/Phys14DR/TT_Tune4C_13TeV-pythia8-tauola/GEN-SIM-RAW/PU40bx25_tsg_PHYS14_25_V1-v1/00000/CA3C5B06-0F70-E411-A963-0025905B8592.root',
        #'/store/mc/Phys14DR/TT_Tune4C_13TeV-pythia8-tauola/GEN-SIM-RAW/PU40bx25_tsg_PHYS14_25_V1-v1/00000/D0146FC2-1F70-E411-9D53-003048FFD728.root',
        #'/store/mc/Phys14DR/TT_Tune4C_13TeV-pythia8-tauola/GEN-SIM-RAW/PU40bx25_tsg_PHYS14_25_V1-v1/00000/F2FBE8C0-1170-E411-8FEE-0025905A612E.root'
    ),
    inputCommands = cms.untracked.vstring(
        'keep *'
    )
)

# customise the HLT menu for running on MC
from HLTrigger.Configuration.customizeHLTforMC import customizeHLTforMC
process = customizeHLTforMC(process)

#
# CMSSW version specific customizations
import os
cmsswVersion = os.environ['CMSSW_VERSION']
# Explicit deletions (via confdb.py):
# None for now
# Other release-dependent customisation:

from HLTrigger.Configuration.CustomConfigs import customizeHLTforCMSSW
process = customizeHLTforCMSSW(process)
#

# load 2015 Run-2 L1 Menu for 25ns (default for GRun, PIon)
from L1Trigger.Configuration.customise_overwriteL1Menu import L1Menu_Collisions2015_25ns_v2 as loadL1menu
process = loadL1menu(process)

# adapt HLT modules to the correct process name
if 'hltTrigReport' in process.__dict__:
    process.hltTrigReport.HLTriggerResults                    = cms.InputTag( 'TriggerResults', '', 'TURNON' )

if 'hltPreExpressCosmicsOutputSmart' in process.__dict__:
    process.hltPreExpressCosmicsOutputSmart.hltResults = cms.InputTag( 'TriggerResults', '', 'TURNON' )

if 'hltPreExpressOutputSmart' in process.__dict__:
    process.hltPreExpressOutputSmart.hltResults        = cms.InputTag( 'TriggerResults', '', 'TURNON' )

if 'hltPreDQMForHIOutputSmart' in process.__dict__:
    process.hltPreDQMForHIOutputSmart.hltResults       = cms.InputTag( 'TriggerResults', '', 'TURNON' )

if 'hltPreDQMForPPOutputSmart' in process.__dict__:
    process.hltPreDQMForPPOutputSmart.hltResults       = cms.InputTag( 'TriggerResults', '', 'TURNON' )

if 'hltPreHLTDQMResultsOutputSmart' in process.__dict__:
    process.hltPreHLTDQMResultsOutputSmart.hltResults  = cms.InputTag( 'TriggerResults', '', 'TURNON' )

if 'hltPreHLTDQMOutputSmart' in process.__dict__:
    process.hltPreHLTDQMOutputSmart.hltResults         = cms.InputTag( 'TriggerResults', '', 'TURNON' )

if 'hltPreHLTMONOutputSmart' in process.__dict__:
    process.hltPreHLTMONOutputSmart.hltResults         = cms.InputTag( 'TriggerResults', '', 'TURNON' )

if 'hltDQMHLTScalers' in process.__dict__:
    process.hltDQMHLTScalers.triggerResults                   = cms.InputTag( 'TriggerResults', '', 'TURNON' )
    process.hltDQMHLTScalers.processname                      = 'TURNON'

if 'hltDQML1SeedLogicScalers' in process.__dict__:
    process.hltDQML1SeedLogicScalers.processname              = 'TURNON'

# limit the number of events to be processed
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32( -1 )
)

# enable the TrigReport and TimeReport
process.options = cms.untracked.PSet(
    wantSummary = cms.untracked.bool( True )
)

# override the GlobalTag, connection string and pfnPrefix
if 'GlobalTag' in process.__dict__:
    from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag as customiseGlobalTag
    process.GlobalTag = customiseGlobalTag(process.GlobalTag, globaltag = 'PHYS14_25_V3', conditions='TrackerAlignmentExtendedError_2011Realistic_v1_mc,TrackerAlignmentErrorExtendedRcd,frontier://FrontierProd/CMS_CONDITIONS+MuonDTAPEObjectsExtended_v0_mc,DTAlignmentErrorExtendedRcd,frontier://FrontierProd/CMS_CONDITIONS+MuonCSCAPEObjectsExtended_v0_mc,CSCAlignmentErrorExtendedRcd,frontier://FrontierProd/CMS_CONDITIONS+EcalSamplesCorrelation_mc,EcalSamplesCorrelationRcd,frontier://FrontierProd/CMS_CONDITIONS+EcalPulseShapes_mc,EcalPulseShapesRcd,frontier://FrontierProd/CMS_CONDITIONS+EcalPulseCovariances_mc,EcalPulseCovariancesRcd,frontier://FrontierProd/CMS_CONDITIONS')
    process.GlobalTag.connect   = 'frontier://FrontierProd/CMS_CONDITIONS'
    process.GlobalTag.pfnPrefix = cms.untracked.string('frontier://FrontierProd/')
    for pset in process.GlobalTag.toGet.value():
        pset.connect = pset.connect.value().replace('frontier://FrontierProd/', 'frontier://FrontierProd/')
    # fix for multi-run processing
    process.GlobalTag.RefreshEachRun = cms.untracked.bool( False )
    process.GlobalTag.ReconnectEachRun = cms.untracked.bool( False )

# override the L1 menu from an Xml file
process.l1GtTriggerMenuXml = cms.ESProducer("L1GtTriggerMenuXmlProducer",
  TriggerMenuLuminosity = cms.string('startup'),
  DefXmlFile = cms.string('L1Menu_Collisions2015_25ns_v2_L1T_Scales_20141121_Imp0_0x1030.xml'),
  VmeXmlFile = cms.string('')
)
process.L1GtTriggerMenuRcdSource = cms.ESSource("EmptyESSource",
  recordName = cms.string('L1GtTriggerMenuRcd'),
  iovIsRunNotTime = cms.bool(True),
  firstValid = cms.vuint32(1)
)
process.es_prefer_l1GtParameters = cms.ESPrefer('L1GtTriggerMenuXmlProducer','l1GtTriggerMenuXml')

# customize the L1 emulator to run customiseL1EmulatorFromRaw with HLT to switchToSimStage1Digis
process.load( 'Configuration.StandardSequences.RawToDigi_cff' )
process.load( 'Configuration.StandardSequences.SimL1Emulator_cff' )
import L1Trigger.Configuration.L1Trigger_custom
#

# 2015 Run2 emulator
import L1Trigger.L1TCalorimeter.L1TCaloStage1_customForHLT
process = L1Trigger.L1TCalorimeter.L1TCaloStage1_customForHLT.customiseL1EmulatorFromRaw( process )

#
process = L1Trigger.Configuration.L1Trigger_custom.customiseResetPrescalesAndMasks( process )
# customize the HLT to use the emulated results
import HLTrigger.Configuration.customizeHLTforL1Emulator
process = HLTrigger.Configuration.customizeHLTforL1Emulator.switchToL1Emulator( process )
process = HLTrigger.Configuration.customizeHLTforL1Emulator.switchToSimStage1Digis( process )

if 'MessageLogger' in process.__dict__:
    process.MessageLogger.categories.append('TriggerSummaryProducerAOD')
    process.MessageLogger.categories.append('L1GtTrigReport')
    process.MessageLogger.categories.append('HLTrigReport')
    process.MessageLogger.categories.append('FastReport')

# for HLT
if hasattr(process, 'hltCsc2DRecHits'):
    process.hltCsc2DRecHits.wireDigiTag  = cms.InputTag("simMuonCSCDigis","MuonCSCWireDigi")
    process.hltCsc2DRecHits.stripDigiTag = cms.InputTag("simMuonCSCDigis","MuonCSCStripDigi")

# for the L1 emulator
if hasattr(process, 'cscReEmulTriggerPrimitiveDigis'):
    process.cscReEmulTriggerPrimitiveDigis.CSCComparatorDigiProducer = cms.InputTag("simMuonCSCDigis","MuonCSCComparatorDigi")
    process.cscReEmulTriggerPrimitiveDigis.CSCWireDigiProducer = cms.InputTag("simMuonCSCDigis","MuonCSCWireDigi")

### ---------------------------------------------------------------- ###
# Now put in the electron ID part

# START ELECTRON ID SECTION
#
# Set up everything that is needed to compute electron IDs and
# add the ValueMaps with ID decisions into the event data stream
#
# Load tools and function definitions

from PhysicsTools.SelectorUtils.tools.vid_id_tools import *

# Turn on VID producer
# switchOnVIDElectronIdProducer(process)

process.load("RecoEgamma.ElectronIdentification.egmGsfElectronIDs_cfi")

from PhysicsTools.SelectorUtils.centralIDRegistry import central_id_registry
process.egmGsfElectronIDSequence = cms.Sequence(process.egmGsfElectronIDs)

# Define which IDs we want to produce
# Each of these two example IDs contains all four standard
# cut-based ID working points (only two WP of the PU20bx25 are actually used here).

my_id_modules = ['RecoEgamma.ElectronIdentification.Identification.cutBasedElectronID_PHYS14_PU20bx25_V1_cff']

# Add them to the VID producer

for idmod in my_id_modules:
                setupAllVIDIdsInModule(process, idmod, setupVIDElectronSelection)

# Do not forget to add the egmGsfElectronIDSequence to the path,
# as in the example below!
#
# END ELECTRON ID SECTION
#
# Configure an example module for user analysis of electrons

process.eID = cms.EDFilter('ElectronIDFilter',
                             electrons = cms.InputTag("gedGsfElectrons"),
                             electronID = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-PHYS14-PU20bx25-V1-standalone-tight"),
                             genParticleTag = cms.InputTag("genParticles"),
                          )

process.idSkim = cms.Path(process.egmGsfElectronIDSequence * process.eID)

# Test the new filter Andrea suggested
process.trigSelector = cms.EDFilter( "TriggerResultsFilter",
    triggerConditions = cms.vstring(
        'idSkim' # logical expressions like "path1 AND path2" is possible
    ),
    hltResults = cms.InputTag( "TriggerResults",  "", "TURNON"),
    l1tResults = cms.InputTag( "" ),
    l1tIgnoreMask = cms.bool( False ),
    l1techIgnorePrescales = cms.bool( False ),
    daqPartitions = cms.uint32( 1 ),
    throw = cms.bool( True )
)

process.drawHist = cms.EDAnalyzer('drawVar',
                                   outFile = cms.string( 'out.root' ),
                                   pathName = cms.string("HLT_Ele32_eta2p1_WP75_Gsf_v1"),
                                   filterName = cms.string("hltEle32WP75GsfTrackIsoFilter"),
                                   procName = cms.string("TURNON"),
                                   doMatching = cms.bool(True),
                                   ptCut = cms.double(30.),
                                   etaCut = cms.double(2.1),
                                   electrons = cms.InputTag("gedGsfElectrons"),
)

process.outpath = cms.EndPath(process.trigSelector + process.drawHist)

process.schedule = cms.Schedule( process.idSkim, process.HLTriggerFirstPath, process.HLT_Ele32_eta2p1_WP75_Gsf_v1, process.HLTriggerFinalPath, process.outpath )
