#!/bin/bash

set -e

DataValidationNR_Flag=$1
DataValidationER_Flag=$2
CH_Flag=$3
SE_Flag=$4
UAr_MLP_run_Flag=$5
Python_flag=$6
DataValidationScript=$7
NR_input_file=$8
ER_input_file=$9
Kr_input_file=${10}
UAr_input_file=${11}
SE_input_file=${12}
CH_input_file=${13}
output_dir=${14}
Python_script_MLP=${15}
loadROOTscript=${16}
vetoMLP=${17}
nEventsMLP=${18}
AnalysisFlag=${19}
veto=${20}
train_flag=${21}
nEvents=${22}
MLPFlag="mlp"

echo loading ROOT
source "$loadROOTscript"

mkdir -p "$output_dir"

if [ "$DataValidationNR_Flag" = 1 ]; then
    echo Starting data validation script for AmBe data
    AnalysisFlag="ambe"
    veto=true
    nEvents=-1
    root -l -b -q "$DataValidationScript(\"$NR_input_file\", \"$AnalysisFlag\", $veto, $nEvents, \"$output_dir\")"
fi

if [ "$DataValidationER_Flag" = 1 ]; then
    echo Starting data validation script for AAr data
    AnalysisFlag="aar"
    veto=false
    nEvents=400000
    root -l -b -q "$DataValidationScript(\"$ER_input_file\", \"$AnalysisFlag\", $veto, $nEvents, \"$output_dir\")"
fi

if [ "$DataValidationER_Flag" = 1 ]; then
    echo Starting data validation script for Kr data
    AnalysisFlag="kr"
    veto=false
    nEvents=-1
    root -l -b -q "$DataValidationScript(\"$Kr_input_file\", \"$AnalysisFlag\", $veto, $nEvents, \"$output_dir\")"
fi

if [ "$SE_Flag" = 1 ]; then
    echo Starting data validation script for single electron data
    AnalysisFlag="se"
    veto=false
    nEvents=2500000
    root -l -b -q "$DataValidationScript(\"$SE_input_file\", \"$AnalysisFlag\", $veto, $nEvents, \"$output_dir\")"
fi

if [ "$CH_Flag" = 1 ]; then
    echo Starting data validation script for cherenkov events data
    AnalysisFlag="ch"
    veto=true
    nEvents=500000
    root -l -b -q "$DataValidationScript(\"$CH_input_file\", \"$AnalysisFlag\", $veto, $nEvents, \"$output_dir\")"
fi

if [ "$UAr_MLP_run_Flag" = 1 ]; then
    echo Starting data validation script for UAr data
    echo Creating txt file with S1 for UAr data
    AnalysisFlag="uar"
    root -l -b -q "$DataValidationScript(\"$UAr_input_file\", \"$AnalysisFlag\", $vetoMLP, $nEventsMLP, \"$output_dir\")"
fi

if [ "$Python_flag" = 1 ]; then
    echo Starting python script for MLP Classification
    if [ -e mlp_DS50.pkl ]; then
        train_flag=0
        python "$Python_script_MLP" "$output_dir"/s1_signal_NR.txt "$output_dir"/s1_signal_ER.txt "$output_dir"/s1_signal_Kr.txt "$output_dir"/s1_signal_UAR.txt "$output_dir"/s1_signal_SE.txt "$output_dir"/s1_signal_CH.txt "$output_dir" $train_flag
    else
        train_flag=1
        python "$Python_script_MLP" "$output_dir"/s1_signal_NR.txt "$output_dir"/s1_signal_ER.txt "$output_dir"/s1_signal_Kr.txt "$output_dir"/s1_signal_UAR.txt "$output_dir"/s1_signal_SE.txt "$output_dir"/s1_signal_CH.txt "$output_dir" $train_flag
    fi
fi

echo Applying mlp_DS50 results to UAr data. See MLP folder in а mlp_output.root file

root -l -b -q "$DataValidationScript(\"$UAr_input_file\", \"$MLPFlag\", $vetoMLP, $nEventsMLP, \"$output_dir\")"