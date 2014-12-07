#!/bin/bash

# OpenHLT producer file maker script
# Works for both MC and data, just point it to the right sources

# Some definitions
inFile01="/store/group/phys_top/triggerStudies/skims/Wev_newL1for72X.root"
inFile02="/store/group/phys_top/triggerStudies/skims/run207884_newL1for72X.root"

mainCode01="ey_allNewL1_mc.py"
mainCode02="ey_allNewL1_data.py"

outName01="Wev_newL1for72X_prod"
outName02="run207884_newL1for72X_prod"

# Misc stuff
open01="prod_"

python openHLT.py -p -i $inFile01 -o $outName01".root" -t $mainCode01 -n 100
sleep 3
mv openhlt_go.py $open01$mainCode01
sleep 3
cmsRun $open01$mainCode01 >& $outName01".log"
sleep 3
#eos cp $outName01".root" /eos/cms/store/group/phys_top/triggerStudies/prod_files/ && sleep 3
sleep 3
rm $outName01".root"
sleep 3

#python openHLT.py -p -i $inFile02 -o $outName02".root" -t $mainCode02 -n -1
#sleep 3
#mv openhlt_go.py $open01$mainCode02
#sleep 3
#cmsRun $open01$mainCode02 >& $outName02".log"
#sleep 3
#eos cp $outName02".root" /eos/cms/store/group/phys_top/triggerStudies/prod_files/ && sleep 3
#sleep 3
#rm $outName02".root"
