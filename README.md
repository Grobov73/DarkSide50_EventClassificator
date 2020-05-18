# DarkSide50_EventClassifier

#E-mail: alexey.grobov@gmail.com

## This is a first version of Event Classifier for DarkSide-50 experiment. You should have DarkSide SLAD files to run it.

## HOW TO RUN MLP CLASSIFIER
#1) Make sure you have following python packages installed: numpy, scikit-learn, pandas
#2) Run the script in the terminal: bash run_steps_MLP.sh 1 1 1 1  
#first argument - NR_Flag, second - ER Flag, third - UAr Flag, forth - python script flag 
#NR_Flag = 1 if you want to create a txt file with NR data to train classifier
#ER_Flag = 1 if you want to create a txt file with ER data to train classifier
#CH_Flag = 1 if you want to create a txt file with cherenkov events
#SE_Flag = 1 if you want to create a txt file with single electron events
#UAr_Flag = 1 if you want to create a txt file with UAr data ready for classification
#Python_flag = 1 if you want to start the classification
# 
#For the first time you should run it as - "bash run_steps_MLP.sh 1 1 1 1 1 1", 
#but after NR and ER files are ready, you don't need to create them everytime, 
#so you can run as "bash run_steps_MLP.sh 0 0 0 0 1 1" if you've changed cuts for UAr, or number of events or veto or something else, and therefore need a new UAr (or any other) txt file 
#or "bash run_steps_MLP.sh 0 0 0 0 0 1" if you have NR, ER, UAr, SE files ready and you want to change python script or whatever
#MAKE SURE you create appropriate txt file after you did some changes in the code!
#
#NOTICE make sure that you have rootstart.h, dmbox.root and max_frac_cut_fixed_acceptance_full_stats.root files in the same folder as Analysis.C file.
# 
#NOTICE when you used Python_flag = 1 for the first time it will create random_forest_DS50.pkl file in your folder.
#This is your trained classifier ready for deployment, so you don't need to train it everytime you analize data
#But if you want to retrain your classifier on new dataset you should delete this file beforehand.
