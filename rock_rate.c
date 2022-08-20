void rock_rate()
{
  TFile*p=new TFile("test2.root"); 
  p->ls();
  struct eventStruct{
    Float_t Position[3];
    Float_t TMS[3];
    Float_t GlobalDeathPosition[3];
    Float_t leptonMomentum[3];
};
  eventStruct myEvent;
    TTree*s;
    p->GetObject("tree",s);
    s->Print();
    s->ls();
    s->SetBranchAddress("vtx", &(myEvent.Position));
    s->SetBranchAddress("TMSBirth", &(myEvent.TMS));
    s->SetBranchAddress("GlobalDeath", &(myEvent.GlobalDeathPosition));
     s->SetBranchAddress("p3lep", &(myEvent.leptonMomentum));
    
    // new TTreeViewer(s);
    gROOT->ForceStyle();
  
    unsigned int mysize1 = s->GetEntries();


    TH2F* Hist1 = new TH2F("Hist1","Event_Vertex Y position vs Event_vertex Z position;Event_vertex Z position;Event_vertex Y position",300,-80000,2000,300,-6000,10000);
    TH1F* Hist2 = new TH1F("Hist2","muons first layer of the TMS;TMSBirth;Events",300,10000,15000);
    TH1F* Hist3 = new TH1F("Hist3","muons first layer of the TMS with forward globaldeath;TMSBirth;Events",300,10000,15000);
    TH1F* Hist4 = new TH1F("Hist4","muons first layer of the TMS with lepton momentum;Muon Momentum[GeV];Events",300,-1000,80000);
    TH1F* Hist5 = new TH1F("Hist5","muons first layer of the TMS with lepton momentum and forward globaldeath;Muon Momentum[GeV];Events",300,-1000,80000);
   //std::cout << mysize << std::endl;
  
    for (unsigned int i = 0; i < mysize1; ++i) {
      s->GetEntry(i);
      //std::cout << myEvent.PositionY << std::endl;
      Float_t z = myEvent.Position[2];
      Float_t y = myEvent.Position[1];
      Float_t Birthz=myEvent.TMS[2];
      Float_t GlobalDeath_z_position =myEvent.GlobalDeathPosition[2];
      Float_t leptonmometum_z_position =myEvent.leptonMomentum[2];      
      //cout<<z<<endl;
      if(11000<Birthz && Birthz<11400){
      Hist1->Fill(z,y);
      }
      if(z<0 && 11000<Birthz && Birthz<11400){
	Hist2->Fill(Birthz);
	  }
      if(GlobalDeath_z_position>0 && z<0 && 11000<Birthz && Birthz<11400){
	Hist3->Fill(Birthz);
      }
       if( z<0 && 11000<Birthz && Birthz<11400 && leptonmometum_z_position>0 ){
	Hist4->Fill(leptonmometum_z_position);
       }
       if(GlobalDeath_z_position>0 && z<0 && 11000<Birthz && Birthz<11400 && leptonmometum_z_position>0 ){
	Hist5->Fill(leptonmometum_z_position);
       } 
    }
  
    TGaxis::SetMaxDigits(3);
    gStyle->SetPalette(kRainBow);
    auto canvas_1 = new TCanvas("canvas1","canvas1", 2500, 2500);
    Hist1 ->SetContour(100000);
    Hist1->Draw("colz");
    //Hist1->GetYaxis()->SetRange(-60,60);
    //Hist1->GetXaxis()->SetRange(-60,60);
    
    gPad->Update();
    canvas_1->Draw();

    TGaxis::SetMaxDigits(3);
    gStyle->SetPalette(kRainBow);
    auto canvas_2 = new TCanvas("canvas2","canvas2", 2500, 2500);
    Hist2 ->SetContour(100000);
    Hist2->Draw("colz");
    gPad->Update();
    canvas_2->Draw();

    TGaxis::SetMaxDigits(3);
    gStyle->SetPalette(kRainBow);
    auto canvas_3 = new TCanvas("canvas3","canvas3", 2500, 2500);
    Hist3 ->SetContour(100000);
    Hist3->Draw("colz");
    gPad->Update();
    canvas_3->Draw();
    TGaxis::SetMaxDigits(3);
    gStyle->SetPalette(kRainBow);
    auto canvas_4 = new TCanvas("canvas4","canvas4", 2500, 2500);
    Hist4 ->SetContour(100000);
    Hist4->Draw("colz");
    gPad->Update();
    canvas_4->Draw();
    
    TGaxis::SetMaxDigits(3);
    gStyle->SetPalette(kRainBow);
    auto canvas_5 = new TCanvas("canvas5","canvas5", 2500, 2500);
    Hist5 ->SetContour(100000);
    Hist5->Draw("colz");
    gPad->Update();
    canvas_5->Draw();

    
    }
