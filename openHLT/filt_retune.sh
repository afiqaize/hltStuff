#!/bin/bash

# Run 02 data Sep 23 new L1

# This script is used to automize the variation of the parameters within the trigger and run them
# Written for the rate studies of electron ID work

# Some definitions
inFile="/store/group/phys_top/triggerStudies/prod_files/Wev_newL1for72X_prod.root"

mainCode01="ey_endNewL1_mc.py"
newCode01="ey_endCutL1_mc.py"

mainCode02="ey_barNewL1_mc.py"
newCode02="ey_barCutL1_mc.py"

# Prescale etc still needs manual adjustment
# Properly add the filters to the configs at each stage
path01="HLT_Ele27_Cut1p0_NewFilt_Gsf_eta2p1_v1"
path02="HLT_Ele27_WP85_Gsf_eta2p1_v1"

# Var Endcap
python path_maker.py -i $mainCode01 -o $newCode01 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEE = cms.double( -1.0 )" -r SieEnd00
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEE = cms.double( 0.012 )" -r SieEnd12
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEE = cms.double( 0.014 )" -r SieEnd14
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEE = cms.double( 0.016 )" -r SieEnd16
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEE = cms.double( 0.018 )" -r SieEnd18
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEE = cms.double( 0.020 )" -r SieEnd20
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEE = cms.double( 0.022 )" -r SieEnd22
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEE = cms.double( 0.024 )" -r SieEnd24
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEE = cms.double( 0.026 )" -r SieEnd26
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEE = cms.double( 0.028 )" -r SieEnd28
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEE = cms.double( 0.030 )" -r SieEnd30
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEE = cms.double( 0.031 )" -r SieEnd31
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEE = cms.double( 0.032 )" -r SieEnd32
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEE = cms.double( 0.033 )" -r SieEnd33
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEE = cms.double( 0.034 )" -r SieEnd34
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEE = cms.double( 0.035 )" -r SieEnd35
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEE = cms.double( 0.036 )" -r SieEnd36
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEE = cms.double( 0.038 )" -r SieEnd38
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEE = cms.double( 0.040 )" -r SieEnd40
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEE = cms.double( 0.042 )" -r SieEnd42
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEE = cms.double( 0.044 )" -r SieEnd44
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEE = cms.double( 0.046 )" -r SieEnd46
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEE = cms.double( 0.048 )" -r SieEnd48
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEE = cms.double( 0.050 )" -r SieEnd50
sleep 3

###  -----------------------------------------------------------------------------  ###

python path_maker.py -i $newCode01 -o $newCode01 -p $path02 -c "hltPreEle27WP85Gsfeta2p1.offset = cms.uint32(0)" "hltEle27WP85ClusterShapeFilter.thrRegularEE = cms.double( -1.0 )" -r SieEnd00
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27WP85Gsfeta2p1.offset = cms.uint32(0)" "hltEle27WP85ClusterShapeFilter.thrRegularEE = cms.double( 0.012 )" -r SieEnd12
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27WP85Gsfeta2p1.offset = cms.uint32(0)" "hltEle27WP85ClusterShapeFilter.thrRegularEE = cms.double( 0.014 )" -r SieEnd14
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27WP85Gsfeta2p1.offset = cms.uint32(0)" "hltEle27WP85ClusterShapeFilter.thrRegularEE = cms.double( 0.016 )" -r SieEnd16
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27WP85Gsfeta2p1.offset = cms.uint32(0)" "hltEle27WP85ClusterShapeFilter.thrRegularEE = cms.double( 0.018 )" -r SieEnd18
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27WP85Gsfeta2p1.offset = cms.uint32(0)" "hltEle27WP85ClusterShapeFilter.thrRegularEE = cms.double( 0.020 )" -r SieEnd20
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27WP85Gsfeta2p1.offset = cms.uint32(0)" "hltEle27WP85ClusterShapeFilter.thrRegularEE = cms.double( 0.022 )" -r SieEnd22
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27WP85Gsfeta2p1.offset = cms.uint32(0)" "hltEle27WP85ClusterShapeFilter.thrRegularEE = cms.double( 0.024 )" -r SieEnd24
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27WP85Gsfeta2p1.offset = cms.uint32(0)" "hltEle27WP85ClusterShapeFilter.thrRegularEE = cms.double( 0.026 )" -r SieEnd26
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27WP85Gsfeta2p1.offset = cms.uint32(0)" "hltEle27WP85ClusterShapeFilter.thrRegularEE = cms.double( 0.028 )" -r SieEnd28
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27WP85Gsfeta2p1.offset = cms.uint32(0)" "hltEle27WP85ClusterShapeFilter.thrRegularEE = cms.double( 0.030 )" -r SieEnd30
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27WP85Gsfeta2p1.offset = cms.uint32(0)" "hltEle27WP85ClusterShapeFilter.thrRegularEE = cms.double( 0.031 )" -r SieEnd31
sleep 3
python path_maker.py -i $newCode01 -o $newCode01 -p $path01 -c "hltPreEle27WP85Gsfeta2p1.offset = cms.uint32(0)" "hltEle27WP85ClusterShapeFilter.thrRegularEE = cms.double( 0.032 )" -r SieEnd32
sleep 3

python openHLT.py -i $inFile -o end_newL1_mc.root -t $newCode01 -n "-1"
sleep 3
#echo 'from SLHCUpgradeSimulations.Configuration.postLS1Customs import *' >> openhlt_go.py
#echo 'process = customise_HLT( process )' >> openhlt_go.py
mv openhlt_go.py "filt_"$newCode01
sleep 3
cmsRun "filt_"$newCode01 >& mc_end01_sigie.log
sleep 3
rm end_newL1_mc.root
sleep 3

echo " "
echo '###  -----------------------------------------------------------------------------  ###'
echo " "
sleep 3

# Var Barrel
python path_maker.py -i $mainCode02 -o $newCode02 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEB = cms.double( -1.0 )" -r SieBar00
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEB = cms.double( 0.001 )" -r SieBar01
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEB = cms.double( 0.002 )" -r SieBar02
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEB = cms.double( 0.003 )" -r SieBar03
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEB = cms.double( 0.004 )" -r SieBar04
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEB = cms.double( 0.005 )" -r SieBar05
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEB = cms.double( 0.006 )" -r SieBar06
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEB = cms.double( 0.007 )" -r SieBar07
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEB = cms.double( 0.008 )" -r SieBar08
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEB = cms.double( 0.009 )" -r SieBar09
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEB = cms.double( 0.010 )" -r SieBar10
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEB = cms.double( 0.011 )" -r SieBar11
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEB = cms.double( 0.012 )" -r SieBar12
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEB = cms.double( 0.013 )" -r SieBar13
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEB = cms.double( 0.014 )" -r SieBar14
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEB = cms.double( 0.015 )" -r SieBar15
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEB = cms.double( 0.016 )" -r SieBar16
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEB = cms.double( 0.017 )" -r SieBar17
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEB = cms.double( 0.018 )" -r SieBar18
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27Cut1p0NewFiltGsfeta2p1.offset = cms.uint32(0)" "hltEle27Cut1p0ClusterShapeFilter.thrRegularEB = cms.double( 0.019 )" -r SieBar19
sleep 3

###  -----------------------------------------------------------------------------  ###

python path_maker.py -i $newCode02 -o $newCode02 -p $path02 -c "hltPreEle27WP85Gsfeta2p1.offset = cms.uint32(0)" "hltEle27WP85ClusterShapeFilter.thrRegularEB = cms.double( -1.0 )" -r SieBar00
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27WP85Gsfeta2p1.offset = cms.uint32(0)" "hltEle27WP85ClusterShapeFilter.thrRegularEB = cms.double( 0.001 )" -r SieBar01
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27WP85Gsfeta2p1.offset = cms.uint32(0)" "hltEle27WP85ClusterShapeFilter.thrRegularEB = cms.double( 0.002 )" -r SieBar02
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27WP85Gsfeta2p1.offset = cms.uint32(0)" "hltEle27WP85ClusterShapeFilter.thrRegularEB = cms.double( 0.003 )" -r SieBar03
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27WP85Gsfeta2p1.offset = cms.uint32(0)" "hltEle27WP85ClusterShapeFilter.thrRegularEB = cms.double( 0.004 )" -r SieBar04
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27WP85Gsfeta2p1.offset = cms.uint32(0)" "hltEle27WP85ClusterShapeFilter.thrRegularEB = cms.double( 0.005 )" -r SieBar05
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27WP85Gsfeta2p1.offset = cms.uint32(0)" "hltEle27WP85ClusterShapeFilter.thrRegularEB = cms.double( 0.006 )" -r SieBar06
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27WP85Gsfeta2p1.offset = cms.uint32(0)" "hltEle27WP85ClusterShapeFilter.thrRegularEB = cms.double( 0.007 )" -r SieBar07
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27WP85Gsfeta2p1.offset = cms.uint32(0)" "hltEle27WP85ClusterShapeFilter.thrRegularEB = cms.double( 0.008 )" -r SieBar08
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27WP85Gsfeta2p1.offset = cms.uint32(0)" "hltEle27WP85ClusterShapeFilter.thrRegularEB = cms.double( 0.009 )" -r SieBar09
sleep 3
python path_maker.py -i $newCode02 -o $newCode02 -p $path01 -c "hltPreEle27WP85Gsfeta2p1.offset = cms.uint32(0)" "hltEle27WP85ClusterShapeFilter.thrRegularEB = cms.double( 0.010 )" -r SieBar10
sleep 3

python openHLT.py -i $inFile -o bar_newL1_mc.root -t $newCode02 -n "-1"
sleep 3
#echo 'from SLHCUpgradeSimulations.Configuration.postLS1Customs import *' >> openhlt_go.py
#echo 'process = customise_HLT( process )' >> openhlt_go.py
mv openhlt_go.py "filt_"$newCode02
sleep 3
cmsRun "filt_"$newCode02 >& mc_bar01_sigie.log
sleep 3
rm bar_newL1_mc.root
sleep 3

echo " "
echo '###  -----------------------------------------------------------------------------  ###'
echo " "
sleep 3
