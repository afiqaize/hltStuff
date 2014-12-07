#!/bin/bash

# Testing a script to submit motherfucking batch jobs
# Usage: bsub -R "mem>20000 && swp > 25000" -q 2nd -J wp75_out_wev < lsf_batch.sh

# Declare variables and crap
outDir="/afs/cern.ch/work/a/afiqaize/hlt/Part2_OpenHLT/OpenHLT/CMSSW_7_2_1_patch2/src/HLTrigger/Configuration/test/Alt_Job/"

# Assume in the original directory
cd /afs/cern.ch/work/a/afiqaize/hlt/Part2_OpenHLT/OpenHLT/CMSSW_7_2_1_patch2/src/
eval `scramv1 runtime -sh`
cd $outDir

# Run the damn thing and copy the output
cmsRun wp75_v16_all.py >& wp75_all_qcd80.log
sleep 3

