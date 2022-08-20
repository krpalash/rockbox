void rock_box(std::string filename){
  TFile * k = new TFile(filename.c_str());
  k->ls();
  TH2D* Hist1 = new TH2D("Hist1","Neutrino energy vs X position ;Vertex x in detector coord system[m];Incoming_Neutrino_Energy",200,-10,10,800,0,80);
  TH2D* Hist2 = new TH2D("Hist2","Neutrino energy vs Y position ;Vertex Y in detector coord system[m];Incoming_Neutrino_Energy",350,-10,25,800,0,80);
  TH2D* Hist3 = new TH2D("Hist3","Neutrino energy vs Z position ;Vertex Z in detector coord system[m];Incoming_Neutrino_Energy",2500,-200,50,800,0,80);
  struct energy_position{
    Double_t Neutrino_energyY;
    Double_t PositionX;
    Double_t PositionY;
    Double_t PositionZ;
  };
   energy_position myEvent;
  TTree*s;
  k->GetObject("gst;3",s);
  s->Print();
  s->SetBranchAddress("vtxx", &(myEvent.PositionX));
  s->SetBranchAddress("vtxy", &(myEvent.PositionY));
  s->SetBranchAddress("vtxz", &(myEvent.PositionZ));
  s->SetBranchAddress("Ev", &(myEvent.Neutrino_energyY));
  s->ls();
  //s->Scan("vtxx:Ev");
  gROOT->ForceStyle();
  unsigned int mysize1 = s->GetEntries();
  
  for (unsigned int i = 0; i < mysize1; ++i) {
  s->GetEntry(i);
  //std::cout << myEvent.PositionY << std::endl;
    Double_t x1 = myEvent.PositionX;
    Double_t y1 = myEvent.PositionY;
    Double_t z1 = myEvent.PositionZ;
    Double_t y = myEvent.Neutrino_energyY;
    //std::cout<< y1 << "y value\n";
    Hist1->Fill(x1,y);
    Hist2->Fill(y1,y);
    Hist3->Fill(z1,y);
     // s->Draw("Ev:vtxz","","colz");
    }
  
  TGaxis::SetMaxDigits(3);
  gStyle->SetPalette(kRainBow);
  auto canvas_1 = new TCanvas("canvas1","canvas1", 2500, 2500);
  Hist1 ->SetContour(100000);
  Hist1->Draw("colz");
  gPad->Update();
  canvas_1->Draw();
  canvas_1->Print("graph1.pdf");
  TGaxis::SetMaxDigits(3);
  gStyle->SetPalette(kRainBow);
  auto canvas_2 = new TCanvas("canvas2","canvas2",2500,2500);
  Hist2->SetContour(100000);
  Hist2->Draw("colz");
  gPad->Update();
  canvas_2->Draw();
  canvas_2->Print("graph2.pdf");
  TGaxis::SetMaxDigits(3);
  gStyle->SetPalette(kRainBow);
  auto canvas_3 = new TCanvas("canvas3","canvas3",2500,2500);
  Hist3->SetContour(100000);
  Hist3->Draw("colz");
  gPad->Update();
  canvas_3->Draw();
  canvas_3->Print("graph3.pdf");
  
  
}
  
