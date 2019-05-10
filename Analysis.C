/*
 
  Usage:
  $ root -b -q data_validation.C(+)

  To run in compiled mode, use the "+".
 
 */

#include "Analysis.h"
#include "Cuts.h"

// bool load_veto = false;
// TString outfile_name = "UAr_result.root";
// TFile* outfile = new TFile(outfile_name, "RECREATE");


void load_tpctree(TChain* tpc_events, TPCEvent& e, bool load_veto) {
  tpc_events->SetBranchStatus("*",0); //disable all
  
  // SLAD RunXXXXXX.root
  // events
  tpc_events->SetBranchStatus("events.run_id", 1);
  tpc_events->SetBranchAddress("run_id", &e.tpc_run_id);

  tpc_events->SetBranchStatus("events.subrun_id", 1);
  tpc_events->SetBranchAddress("subrun_id", &e.tpc_subrun_id);

  tpc_events->SetBranchStatus("events.event_id", 1);
  tpc_events->SetBranchAddress("event_id", &e.tpc_event_id);

  tpc_events->SetBranchStatus("events.tpc_digital_sum", 1);
  tpc_events->SetBranchAddress("tpc_digital_sum", &e.tpc_dig_sum);
  
  // gps
  tpc_events->SetBranchStatus("gps.gps_coarse", 1);
  tpc_events->SetBranchAddress("gps.gps_coarse", &e.tpc_gps_coarse);
  
  tpc_events->SetBranchStatus("gps.gps_fine", 1);
  tpc_events->SetBranchAddress("gps.gps_fine", &e.tpc_gps_fine);
  
  // long_lifetime
  tpc_events->SetBranchStatus("long_lifetime.lifetime",1);
  tpc_events->SetBranchAddress("long_lifetime.lifetime", &e.live_time);

  tpc_events->SetBranchStatus("long_lifetime.inhibittime",1);
  tpc_events->SetBranchAddress("long_lifetime.inhibittime", &e.inhibit_time);
  
  //logbook
  //trigger_type
  tpc_events->SetBranchStatus("trigger_type", 1);
  tpc_events->SetBranchAddress("trigger_type", &e.trigger_type);
  
  //nchannels
  tpc_events->SetBranchStatus("nchannel.nchannel", 1);
  tpc_events->SetBranchAddress("nchannel.nchannel", &e.nchannels);

  // baseline
  tpc_events->SetBranchStatus("baseline.SumChannelHasNoBaseline",1);
  tpc_events->SetBranchAddress("baseline.SumChannelHasNoBaseline", &e.baseline_not_found);

  // npulses
  tpc_events->SetBranchStatus("npulses.n_phys_pulses",1);
  tpc_events->SetBranchAddress("npulses.n_phys_pulses", &e.npulses);

  tpc_events->SetBranchStatus("npulses.has_s3",1);
  tpc_events->SetBranchAddress("npulses.has_s3", &e.has_s3);

  tpc_events->SetBranchStatus("npulses.has_s1echo",1);
  tpc_events->SetBranchAddress("npulses.has_s1echo", &e.has_s1echo);
  
  // tdrift
  tpc_events->SetBranchStatus("tdrift.tdrift", 1);
  tpc_events->SetBranchAddress("tdrift.tdrift", &e.tdrift);

  // s1
  tpc_events->SetBranchStatus("s1.total_s1", 1);
  tpc_events->SetBranchAddress("s1.total_s1", &e.total_s1);
  
  tpc_events->SetBranchStatus("s1.total_s1_corr", 1);
  tpc_events->SetBranchAddress("s1.total_s1_corr", &e.total_s1_corr);
  
  tpc_events->SetBranchStatus("s1.total_s1_top", 1);
  tpc_events->SetBranchAddress("s1.total_s1_top", &e.total_s1_top);
  
  tpc_events->SetBranchStatus("s1.total_s1_bottom", 1);
  tpc_events->SetBranchAddress("s1.total_s1_bottom", &e.total_s1_bottom);

  tpc_events->SetBranchStatus("s1.total_s1_long_us_integrals", 1);
  tpc_events->SetBranchAddress("s1.total_s1_long_us_integrals", &e.total_s1_long_us_integrals);
  
  // s1_saturation
  tpc_events->SetBranchStatus("s1_saturation.is_saturated_pulse0", 1);
  tpc_events->SetBranchAddress("s1_saturation.is_saturated_pulse0", &e.s1_saturated);

  // s1_time
  tpc_events->SetBranchStatus("s1_time.s1_start_time", 1);
  tpc_events->SetBranchAddress("s1_time.s1_start_time", &e.s1_start_time);

  // s1_f90
  tpc_events->SetBranchStatus("s1_f90.total_f90", 1);
  tpc_events->SetBranchAddress("s1_f90.total_f90", &e.total_f90);
  
  // s1_fraction
  tpc_events->SetBranchStatus("s1_fraction.s1_max_chan", 1);
  tpc_events->SetBranchAddress("s1_fraction.s1_max_chan", &e.s1_max_chan);
  
//  tpc_events->SetBranchStatus("s1_fraction.s1_max_frac", 1);
//  tpc_events->SetBranchAddress("s1_fraction.s1_max_frac", &e.s1_max_frac);

  tpc_events->SetBranchStatus("s1_fraction.s1_prompt_max_frac", 1);
  tpc_events->SetBranchAddress("s1_fraction.s1_prompt_max_frac", &e.s1_max_frac);
  
  // max_s1_frac_cut
  tpc_events->SetBranchStatus("max_s1_frac_cut.max_s1_frac_cut_threshold99", 1);
  tpc_events->SetBranchAddress("max_s1_frac_cut.max_s1_frac_cut_threshold99", &e.max_s1_frac_cut_threshold99);
  
  tpc_events->SetBranchStatus("max_s1_frac_cut.max_s1_frac_cut_exceeds99", 1);
  tpc_events->SetBranchAddress("max_s1_frac_cut.max_s1_frac_cut_exceeds99", &e.max_s1_frac_cut_exceeds99);
  
  // s2
  tpc_events->SetBranchStatus("s2.total_s2", 1);
  tpc_events->SetBranchAddress("s2.total_s2", &e.total_s2);
  
  // s2_saturation
  tpc_events->SetBranchStatus("s2_saturation.is_saturated_pulse1", 1);
  tpc_events->SetBranchAddress("s2_saturation.is_saturated_pulse1", &e.s2_saturated);


  // s2_f90
  tpc_events->SetBranchStatus("s2_f90.total_s2_f90", 1);
  tpc_events->SetBranchAddress("s2_f90.total_s2_f90", &e.total_s2_f90_fixed);


  if (load_veto) {
    // SLAD RunXXXXXX_veto.root
    tpc_events->SetBranchStatus("veto_run_id", 1);
    tpc_events->SetBranchAddress("veto_run_id", &e.veto_run_id);

    tpc_events->SetBranchStatus("veto_nclusters", 1);
    tpc_events->SetBranchAddress("veto_nclusters", &e.veto_nclusters);    

    tpc_events->SetBranchStatus("veto_event_id", 1);
    tpc_events->SetBranchAddress("veto_event_id", &e.veto_event_id);
    
    tpc_events->SetBranchStatus("veto_present", 1);
    tpc_events->SetBranchAddress("veto_present", &e.veto_present);
    
    tpc_events->SetBranchStatus("veto_lsv_total_charge", 1);
    tpc_events->SetBranchAddress("veto_lsv_total_charge", &e.veto_lsv_total_charge);
    
    tpc_events->SetBranchStatus("veto_wt_total_charge", 1);
    tpc_events->SetBranchAddress("veto_wt_total_charge", &e.veto_wt_total_charge);
  
    e.veto_roi_lsv_charge_vec = 0;
   e.veto_slider_lsv_charge_vec = 0;
    e.veto_cluster_dtprompt_vec = 0;
    e.veto_cluster_charge_vec = 0;
  
    tpc_events->SetBranchStatus("veto_roi_lsv_charge_vec", 1);
    tpc_events->SetBranchAddress("veto_roi_lsv_charge_vec", &e.veto_roi_lsv_charge_vec);
  
    tpc_events->SetBranchStatus("veto_slider_lsv_charge_vec", 1);
    tpc_events->SetBranchAddress("veto_slider_lsv_charge_vec", &e.veto_slider_lsv_charge_vec);

	
    tpc_events->SetBranchStatus("veto_cluster_dtprompt_vec", 1);
    tpc_events->SetBranchAddress("veto_cluster_dtprompt_vec", &e.veto_cluster_dtprompt_vec);
  
    tpc_events->SetBranchStatus("veto_cluster_charge_vec", 1);
    tpc_events->SetBranchAddress("veto_cluster_charge_vec", &e.veto_cluster_charge_vec);
  }
} 


void s1_to_txt(std::ofstream& s1pulse, TPCEvent& e){
        if (s1pulse.is_open()){ //Write s1 signal up to 7 usec into text file 
            s1pulse << e.tpc_run_id<< " ";
            s1pulse << e.tpc_event_id << " ";
        for(int i = 0; i<58; i++){
            s1pulse << e.total_s1_long_us_integrals[i] << " ";
        }
        s1pulse << " " << endl;
    }
    else{
        cout << "Can't open the txt file" << endl;
    }    
    }

void event_loop(TFile* outfile, TChain* tpc_events, bool load_veto, TString type = "uar", Int_t nevents=-1, TString txt_output="") {
  TH1::SetDefaultSumw2(kTRUE);
  
  TPCEvent e;
  load_tpctree(tpc_events, e, load_veto);

  Bool_t aar  = (type == "aar");
  Bool_t uar  = (type == "uar");
  Bool_t ambe = (type == "ambe" || type == "ambebg");


  //Load max_s1_frac threshold file so can apply other versions of S1 max frac cut on the fly.
  TFile* s1mf_file = new TFile("max_frac_cut_fixed_acceptance_full_stats.root");
  if(s1mf_file->IsZombie() || !s1mf_file) std::cout << "Bad S1mf_file" << std::endl;
  TH2F* h_s1mf_thresholds = (TH2F*) s1mf_file->Get("s1pmf_c95"); // Load 95%ile cut.
  
  // Load 1-sigma contours for getting NR from AmBe data
  TFile* dmbox_file = new TFile("dmbox.root");
  if(dmbox_file->IsZombie() || !dmbox_file) std::cout << "Bad dmbox_file (getting NR 99% acc from here)" << std::endl;
  TGraph* ambe_acc99 = (TGraph*) dmbox_file->Get("NRacceptances/g_acceptance_99");

  outfile->cd();
  outfile->mkdir(type);
  outfile->cd(type);
 
  TH2F*  h_s1_s2s1 = new TH2F("h_s1_s2s1", "No veto cuts, deep R", 200, 0, 1000, 250, 0, 2.5);
  h_s1_s2s1->GetXaxis()->SetTitle("S1 [PE]");
  h_s1_s2s1->GetYaxis()->SetTitle("Log_{10}(S2/S1)");
  
  TH2F* h_f90_s2s1 = new TH2F("h_f90_s2s1", "No veto cuts, deep R", 500, 0, 1, 250, 0, 2.5);
  h_f90_s2s1->GetXaxis()->SetTitle("f_{90}");
  h_f90_s2s1->GetYaxis()->SetTitle("Log_{10}(S2/S1)");
    
  TH1F* h_tdrift       = new TH1F("h_tdrift",       "; t_{drift} [#mus]", 200, 0., 400.);
  TH1F* h_tdrift_lowS1 = new TH1F("h_tdrift_lowS1", "; t_{drift} [#mus]", 200, 0., 400.);
  TH1F* h_S2f90        = new TH1F("h_S2f90",        "; S2_f90", 1000, 0., 1.);

  TString s1_filename = txt_output;
  if(type == "aar"){   s1_filename += "s1_signal_ER.txt";}
  if(type == "kr"){    s1_filename += "s1_signal_Kr.txt";}
  if(type == "ambe"){  s1_filename += "s1_signal_NR.txt";}
  if(type == "uar"){   s1_filename += "s1_signal_UAR.txt";}
  if(type == "se"){    s1_filename += "s1_signal_SE.txt";}
  if(type == "ch"){    s1_filename += "s1_signal_CH.txt";}
  
  ofstream s1pulse(s1_filename);
  
  TDirectory* MLP_output = gDirectory->mkdir("MLP");
  MLP_output->cd();
  const Int_t nmlp = 4;
  TH2F** h_MLP = new TH2F*[nmlp];
  const Int_t nbins_s1_mlp = 200, nbins_f90_mlp = 100;
  const Float_t s1_min_mlp = 0., s1_max_mlp = 1000., f90_min_mlp = 0., f90_max_mlp = 1.;
  const TString h_MLPLabels[nmlp] = {
    "MLP result, NR events","MLP result, ER events","MLP result, single electron", "MLP result, cherenkov events"
  };
  for (Int_t ihmlp=0; ihmlp<nmlp; ++ihmlp) {
    h_MLP[ihmlp] = new TH2F(Form("h_mlp_%d",ihmlp),h_MLPLabels[ihmlp].Data(),nbins_s1_mlp,s1_min_mlp,s1_max_mlp,nbins_f90_mlp,f90_min_mlp,f90_max_mlp);
    h_MLP[ihmlp]->GetXaxis()->SetTitle("S1 [PE]");
    h_MLP[ihmlp]->GetYaxis()->SetTitle("f_{90}");
  }
  
  outfile->cd(type);
  TDirectory* Slice = gDirectory->mkdir("Slices");
  Slice->cd();
  const Int_t nhslice = 26;
  TH1F* h_Slice[nhslice];
  const Int_t nbins_f90_slice = 200;
  const Float_t f90_min_bin_slice = 0., f90_max_bin_slice = 1;
  const TString h_SliceLabel[nhslice] = {
    "MLP, NR events, 0<s1[PE]<50",     "MLP, ER events, 0<s1[PE]<50",       "MLP, single events, 0<s1[PE]<50",     "MLP, cherenkov events, 0<s1[PE]<50",    
    "MLP, NR events, 50<s1[PE]<100",   "MLP, ER events, 50<s1[PE]<100",     "MLP, single events, 50<s1[PE]<100",   "MLP, cherenkov events, 50<s1[PE]<100",
    "MLP, NR events, 100<s1[PE]<200",  "MLP, ER events, 100<s1[PE]<200",    "MLP, single events, 100<s1[PE]<200",  "MLP, cherenkov events, 100<s1[PE]<200",
    "MLP, NR events, 200<s1[PE]<300",  "MLP, ER events, 200<s1[PE]<300",    "MLP, single events, 200<s1[PE]<300",  "MLP, cherenkov events, 200<s1[PE]<300",
    "MLP, NR events, 300<s1[PE]<500",  "MLP, ER events, 300<s1[PE]<500",    "MLP, single events, 300<s1[PE]<500",  "MLP, cherenkov events, 300<s1[PE]<500",
    "MLP, NR events, 500<s1[PE]<1000", "MLP, ER events, 500<s1[PE]<1000",   "MLP, single events, 500<s1[PE]<1000", "MLP, cherenkov events, 500<s1[PE]<1000",  
    "UAr data, 0<s1[PE]<50", "UAr data, 50<s1[PE]<100" 
  };
  for (Int_t ihslice=0; ihslice<nhslice; ++ihslice){
   h_Slice[ihslice] = new TH1F(Form("h_slice_%d",ihslice),h_SliceLabel[ihslice].Data(), nbins_f90_slice, f90_min_bin_slice, f90_max_bin_slice);
   h_Slice[ihslice]->GetXaxis()->SetTitle("f90");	
  }
  
  outfile->cd(type);
  TDirectory* f90_s1_dir = gDirectory->mkdir("f90_s1");
  f90_s1_dir->cd();
  const Int_t nhf90s1 = 4;
  TH2F* h_S1_f90[nhf90s1];
  const Int_t nbins_f90 = 100;
  const Int_t nbins_s1 = 200;
  const Float_t min_bin_f90 = 0.;
  const Float_t max_bin_f90 = 1.;
  const Float_t min_bin_s1 = 0.;
  const Float_t max_bin_s1 = 1000.;
  const TString h_f90_s1_label[nhf90s1] = {
      "AmBe data, NR events sample","AAr data, ER events sample",
      "Kr data, ER events sample","UAr data"
  };
  for(Int_t ihn=0; ihn<nhf90s1; ++ihn){
        h_S1_f90[ihn] = new TH2F(Form("h_f90_s1_%d",ihn),h_f90_s1_label[ihn].Data(),nbins_s1,min_bin_s1,max_bin_s1,nbins_f90,min_bin_f90,max_bin_f90);
        h_S1_f90[ihn]->GetXaxis()->SetTitle("S1 [PE]");
        h_S1_f90[ihn]->GetYaxis()->SetTitle("f_{90}");
        
  }
  TH2F* h_S1_f90_se = new TH2F("h_S1_f90_se", "Single electron events sample", nbins_s1, min_bin_s1, max_bin_s1, 150, 0., 0.15);
  h_S1_f90_se->GetXaxis()->SetTitle("S1 [PE]");
  h_S1_f90_se->GetYaxis()->SetTitle("f90");
  TH2F* h_S1_f90_ch = new TH2F("h_S1_f90_ch","Cherenkov events sample", 100, min_bin_s1, 400., 250, 0.85, 1.1);
  h_S1_f90_ch->GetXaxis()->SetTitle("S1 [PE]");
  h_S1_f90_ch->GetYaxis()->SetTitle("f90");
  
  outfile->cd(type);
  
  
  
  ifstream fin(txt_output+"UAr_MLP_output.txt");

  Int_t number=0;
  Int_t target=0;
  Int_t run_number=0;
  Int_t event_number=0;

  
  //-------------------------//
  //     MAIN EVENT LOOP     //
  //-------------------------//
     
  Int_t tpc_nevents = 0;
  
     if(nevents < 0){
        tpc_nevents = tpc_events->GetEntries();
    }
     else{
        tpc_nevents = nevents;
    }
  cout << "Total events: " << tpc_nevents << '\n';
  e.muon_dt = 999;
  int event_counter = 0;
  for (Int_t n = 0; n<tpc_nevents; n++) {
    if (!(n%1000000)) cout << "Processing event " << n << ", " << Int_t(100.*n/tpc_nevents) << "% completed" << endl;
    tpc_events->GetEntry(n);    	
    
    // Generate cuts.
    Bool_t CX_nchan           = cx_nchan(e); // CX#1
    Bool_t CX_baseline        = cx_baseline(e); // CX#2
    Bool_t CX_event_dt        = cx_event_dt(e); // CX#3
    Bool_t CX_file_io         = (aar ? cx_file_io(e) : true); // CX#4 //apply if type is aar. otherwise, don't apply
    Bool_t CX_veto_present    = ((aar || uar) && cx_veto_present(e)) || (ambe);
    Bool_t CX_veto_prompt     = (aar && cx_old_veto_prompt(e))  || (uar && cx_veto_prompt(e))    || (ambe);
    Bool_t CX_veto_delayed    = (aar && cx_old_veto_delayed(e)) || (uar && cx_veto_delayed(e))   || (ambe);
    Bool_t CX_veto_preprompt  = (aar)                           || (uar && cx_veto_preprompt(e)) || (ambe);
    Bool_t CX_veto_muon       = (aar)                           || (uar && cx_veto_muon(e))      || (ambe);
    Bool_t CX_veto_cosmogenic = (aar)                           || (uar && cx_veto_cosmogenic(e))|| (ambe);
    Bool_t CX_single_scatter  = cx_single_scatter(e); // CX#8
    Bool_t CX_fiducial        = cx_fiducial(e); // CX#15
    Bool_t CX_quality        = (CX_nchan && CX_baseline && CX_event_dt && CX_file_io /*&& CX_veto_present*/); // CX#QUALITY
    Bool_t CX_veto           = (CX_veto_present && CX_veto_prompt && CX_veto_delayed && CX_veto_preprompt && CX_veto_muon && CX_veto_cosmogenic);
    Bool_t CX_trg_time        = cx_trg_time(e); // CX#9
    Bool_t CX_s1_sat          = cx_s1_sat(e); // CX#10
    Bool_t CX_s1_mf           = cx_s1_mf(e); // CX#11
    Bool_t CX_s2_f90          = cx_s2_f90(e); // CX#12
    Bool_t CX_s2_size         = cx_s2_size(e); // CX#13
    Bool_t CX_s1_range        = cx_s1_range(e); // CX#14
    Bool_t CX_r10             = cx_r(e, 10.); // CX#18
    Bool_t CX_f90_s2s1_s1range = cx_f90_s2s1_s1range(e);
    Bool_t isNR              = (e.total_f90 > ambe_acc99->Eval(e.total_s1_corr));
    Bool_t CX_t_drift        = cx_t_drift(e);
    Bool_t CX_single_pulse   = cx_single_pulse(e);
    Bool_t CX_Good_Event = (CX_quality && CX_s1_sat && CX_trg_time);

    // Quantities
    Float_t s1               = e.total_s1_corr;
    Float_t f90              = e.total_f90;
    Float_t s2               = e.total_s2 * e.xycorr_factor;
    Float_t log10s2overs1    = (s2>0 ? TMath::Log10(s2/s1) : -999);
        
    if (CX_quality && CX_veto && CX_single_scatter && CX_trg_time
        && CX_s1_sat && CX_s1_mf && CX_s2_f90 && CX_s2_size /*&& CX_fiducial*/
        && CX_s1_range)                                                       h_tdrift       -> Fill(e.tdrift);
    if (CX_quality && CX_veto && CX_single_scatter && CX_trg_time                               
        && CX_s1_sat && CX_s1_mf && CX_s2_f90 && CX_s2_size /*&& CX_fiducial*/                  
        && CX_s1_range && s1<200.)                                            h_tdrift_lowS1 -> Fill(e.tdrift);
    if (CX_quality && CX_veto && CX_single_scatter && CX_trg_time                               
        && CX_s1_sat && CX_s1_mf/*&& CX_s2_f90*/&& CX_s2_size && CX_fiducial                    
        && CX_s1_range)                                                       h_S2f90        -> Fill(e.total_s2_f90_fixed);
    if (CX_quality /*&& CX_veto*/ && CX_single_scatter                                          
        && CX_trg_time && CX_s1_sat && CX_s1_mf && CX_s2_f90 && CX_s2_size                      
        /*&& CX_s1_range*/ && CX_fiducial && CX_r10)                          h_s1_s2s1      -> Fill(s1,log10s2overs1);	
    if (CX_quality /*&& CX_veto*/ && CX_single_scatter
        && CX_trg_time && CX_s1_sat && CX_s1_mf && CX_s2_f90 && CX_s2_size
        /*&& CX_s1_range*/ && CX_fiducial && CX_r10 && CX_f90_s2s1_s1range)   h_f90_s2s1  -> Fill(f90,log10s2overs1);
        
    if(CX_Good_Event){
    if(type == "ambe"){    
	for (unsigned i=0; i<e.veto_cluster_dtprompt_vec->size(); i++){
     if (e.veto_cluster_dtprompt_vec->at(i)>-0.05 && e.veto_cluster_dtprompt_vec->at(i)<-0.04){
	 for (unsigned j=0; j<e.veto_cluster_charge_vec->size(); j++){
     if (e.veto_cluster_charge_vec->at(j)>2400 && e.veto_cluster_charge_vec->at(j)<3600){
    
    if(isNR && f90<0.85 && f90>0.5 && CX_t_drift && CX_veto_present){
        s1_to_txt(s1pulse, e);
        h_S1_f90[0] -> Fill(s1, f90);
        event_counter++;
            }
    }}}}
    }
    
    //TODO  s2 signal, scale features, feature selector
    
    if(type == "aar"){
    if(f90<0.8 && f90>0.15 && CX_t_drift){ 
        s1_to_txt(s1pulse, e);
        h_S1_f90[1] -> Fill(s1, f90);
        event_counter++;
    }
    }
    
    if(type == "kr"){
    if(s1>220 && f90<0.45 && f90>0.14 && CX_t_drift){ 
        s1_to_txt(s1pulse, e);
        h_S1_f90[2] -> Fill(s1, f90);
        event_counter++;
    }
    }
    
    if(type == "uar"){
        s1_to_txt(s1pulse, e);
        h_S1_f90[3] -> Fill(s1, f90);
        if (s1>=0. && s1<50.){     h_Slice[24]->Fill(f90);}
        if (s1>=50. && s1<100.){   h_Slice[25]->Fill(f90);}
        event_counter++;
    }
    
    
    if(type == "se"){
        if(f90<0.15){
            s1_to_txt(s1pulse, e);
            h_S1_f90_se -> Fill(s1, f90);
            event_counter++;
        }
    }
    
    if(type == "ch"){
        if(CX_single_pulse && f90>0.85){
            s1_to_txt(s1pulse, e);
            h_S1_f90_ch -> Fill(s1, f90);
            event_counter++;
        }
    }
    
    if(type == "mlp"){
        fin >> number;                                                       //just a number from python, don't use it.
    	fin >> target ;
        fin >> run_number;
	fin >> event_number;
	if (run_number == e.tpc_run_id && event_number == e.tpc_event_id){
	if (target == 0){
            h_MLP[1]->SetMarkerColor(4);
            h_MLP[1]->SetMarkerStyle(1);
	    h_MLP[1]->Fill(s1,f90);
            if (s1>=0. && s1<50.){     h_Slice[1]->Fill(f90);}
	    if (s1>=50. && s1<100.){   h_Slice[5]->Fill(f90);}
 	    if (s1>=100. && s1<200.){  h_Slice[9]->Fill(f90);}
	    if (s1>=200. && s1<300.){  h_Slice[13]->Fill(f90);}
	    if (s1>=300. && s1<500.){  h_Slice[17]->Fill(f90);}
	    if (s1>=500. && s1<1000.){ h_Slice[21]->Fill(f90);}
        }
	
	if (target == 1){
	    h_MLP[0]->SetMarkerColor(2);
	    h_MLP[0]->SetMarkerStyle(1);
            h_MLP[0]->Fill(s1,f90);
            if (s1>=0. && s1<50.){     h_Slice[0]->Fill(f90);}
            if (s1>=50. && s1<100.){   h_Slice[4]->Fill(f90);}
            if (s1>=100. && s1<200.){  h_Slice[8]->Fill(f90);}
            if (s1>=200. && s1<300.){  h_Slice[12]->Fill(f90);}
            if (s1>=300. && s1<500.){  h_Slice[16]->Fill(f90);}
            if (s1>=500. && s1<1000.){ h_Slice[20]->Fill(f90);}
        }
        
        if (target == 2){
	    h_MLP[2]->SetMarkerColor(3);
	    h_MLP[2]->SetMarkerStyle(1);
            h_MLP[2]->Fill(s1,f90);            
            if (s1>=0. && s1<50.){     h_Slice[2]->Fill(f90);}
	    if (s1>=50. && s1<100.){   h_Slice[6]->Fill(f90);}
 	    if (s1>=100. && s1<200.){  h_Slice[10]->Fill(f90);}
	    if (s1>=200. && s1<300.){  h_Slice[14]->Fill(f90);}
	    if (s1>=300. && s1<500.){  h_Slice[18]->Fill(f90);}
	    if (s1>=500. && s1<1000.){ h_Slice[22]->Fill(f90);}
        }
        
        if (target == 3){
	    h_MLP[3]->SetMarkerColor(6);
	    h_MLP[3]->SetMarkerStyle(1);
            h_MLP[3]->Fill(s1,f90);            
            if (s1>=0. && s1<50.){     h_Slice[3]->Fill(f90);}
	    if (s1>=50. && s1<100.){   h_Slice[7]->Fill(f90);}
 	    if (s1>=100. && s1<200.){  h_Slice[11]->Fill(f90);}
	    if (s1>=200. && s1<300.){  h_Slice[15]->Fill(f90);}
	    if (s1>=300. && s1<500.){  h_Slice[19]->Fill(f90);}
	    if (s1>=500. && s1<1000.){ h_Slice[23]->Fill(f90);}
        }
        
	event_counter++;
	}

    } //mlp
    
    }// is good event

  }//loop over events
  
  TCanvas* canvas = new TCanvas("canvas","MLP",1200,600);
  
  if(type == "ambe"){
    h_S1_f90[0]->Draw("colz");
    canvas->SaveAs("ambe_sample.pdf");
  }
  if(type == "aar"){
    h_S1_f90[1]->Draw("colz");
    canvas->SaveAs("aar_sample.pdf");
  }
  if(type == "se"){
    h_S1_f90_se->Draw("colz");
    canvas->SaveAs("single_electron_sample.pdf");
  }
  if(type == "ch"){
    h_S1_f90_ch->Draw("colz");
    canvas->SaveAs("cherenkov_sample.pdf");
  }
  if(type == "uar"){
    h_S1_f90[3]->Draw("colz");
    canvas->SaveAs("uar_test.pdf");
    TPad* padHisto = (TPad*)canvas;
    padHisto->SetLogy();
    h_Slice[24]->Draw();
    canvas->SaveAs("f90_0_50.pdf");
    h_Slice[25]->Draw();
    canvas->SaveAs("f90_50_100.pdf");
  }
  if(type == "mlp"){
    TPad* padHisto = (TPad*)canvas;
    padHisto->SetLogy();
    h_Slice[3]->SetTitle("UAr data classified, 0<S1[PE]<50");
    h_Slice[3]->SetLineColor(kMagenta);
    h_Slice[3]->Draw();
    h_Slice[2]->SetLineColor(kGreen);
    h_Slice[2]->Draw("same");
    h_Slice[1]->SetLineColor(kBlue);
    h_Slice[1]->Draw("same");
    h_Slice[0]->SetLineColor(kRed);
    h_Slice[0]->Draw("same");
    auto legend = new TLegend(0.2,0.7,0.5,0.9);
//     legend->SetHeader("f_{90} distribution","C"); // option "C" allows to center the header
    legend->AddEntry(h_Slice[1],"Electron recoil","l");
    legend->AddEntry(h_Slice[0],"Nuclear recoil","l");
    legend->AddEntry(h_Slice[3],"Cherenkov event","l");
    legend->AddEntry(h_Slice[2],"Single electrons event","l");
    legend->Draw();
    canvas->SaveAs("f90_0_50_mlp.pdf");
   
    TCanvas* canvas1 = new TCanvas("canvas1","MLP1",1200,600);
    h_MLP[3]->SetTitle("UAr data classified");
    h_MLP[3]->Draw();
    h_MLP[2]->Draw("same");
    h_MLP[1]->Draw("same");
    h_MLP[0]->Draw("same");
    auto legend1 = new TLegend(0.6,0.75,0.9,0.85);
//     legend1->SetHeader("","C"); // option "C" allows to center the header
    legend1->AddEntry(h_MLP[1],"Electron recoil","pf");
    legend1->AddEntry(h_MLP[0],"Nuclear recoil","pf");
    legend1->AddEntry(h_MLP[3],"Cherenkov event","pf");
    legend1->AddEntry(h_MLP[2],"Single electrons event","pf");
    legend1->Draw();
    canvas1->SaveAs("f90_s1_mlp.pdf");
   
  }
  
  
  
  
  s1pulse.close();
  cout << "Number of events: " << event_counter << endl;  
}


TChain* load_files(TString mainfile, bool veto)
{

  // Load and friend the TTrees
  TChain* tpc_events = new TChain("events");
  tpc_events->Add(mainfile);

  if (veto) {
    TString vetofile = mainfile;
    vetofile.Remove(vetofile.Length()-5);
    vetofile += "_veto_cluster.root";
  
    TChain* veto_events = new TChain("veto");
    veto_events->Add(vetofile);
    tpc_events->AddFriend(veto_events);
  }

  return tpc_events;
}

void Analysis(TString mainfile = "/home/agr/AGR/DarkSide/UAr_70d_SLAD_v3_3_0_no12922.root", TString type = "uar", bool veto = false, Int_t nEvents = 1000000, TString txt_output_dir = "./") {
  
  gROOT->SetBatch(kTRUE);
  gROOT->Reset();
  SetMyStyle();

  TStopwatch* clock = new TStopwatch();
  clock->Start();
  bool load_veto = veto;  
  
  TString outfile_name = txt_output_dir + type;
  if(veto) outfile_name += "_veto_ON_";
  if(!veto) outfile_name += "_veto_OFF_";
//   if(nEvents>0) outfile_name += std::to_string(nEvents)+"_events_";
//   std::time_t t = std::time(0);
  outfile_name += "output.root";
  TFile* outfile = new TFile(outfile_name, "RECREATE");
  cout << "Saving output to " << outfile->GetName() << '\n';

  TChain* tpc_events = load_files(mainfile, load_veto);
  event_loop(outfile, tpc_events, load_veto, type, nEvents, txt_output_dir); //types are "ambe", "uar", "aar", "kr", "mlp", "se", "ch"

  outfile->Write();
  
  outfile->Close();
  
  cout << "Done! " << clock->RealTime() << " s." << endl;
}
