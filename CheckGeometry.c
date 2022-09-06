void CheckGeometry(){
  //TGeoManager::Import("nd_hall_with_lar_tms_nosand_with_tms_overlap.gdml");
  // TGeoManager *geo = gGeoManager;
  TGeoManager *geo = TGeoManager::Import("overlaponlyTMS.gdml");
  cout<<"======================== Checking Geometry is done ============================="<<endl;
  //geo->CheckGeometry();
  cout<<"===================================================================="<<endl;
  cout<<"STAGE 1: Overlaps checking by sampling within 10 microns"<<endl;
  cout<<"===================================================================="<<endl;
  geo->CheckOverlaps(0.001,"s100000");
  cout<<"===================================================================="<<endl;
  
  geo->PrintOverlaps();
  cout<<"========================       Done!       =============================\n\n\n"<<endl;
  TObjArray* overlaps=geo->GetListOfOverlaps();
	for(int i=0; i<overlaps->GetEntries(); i++){
	  TObject* overlap=overlaps->At(i);
	  cout<<"========================  Drawing Overlaps ============================="<<endl;
	  cout<<"================= Overlap messages will duplicate below ================"<<endl;
	  cout<<"=================     Overlaps are in units of cm       ================"<<endl;
	  //TCanvas* c = new TCanvas();
	  //overlap->Draw("");
	   TCanvas* d = new TCanvas();
	   overlap->Draw("ogl");
	  
	}
	/*cout<<"========================       Done!!       =============================\n\n\n"<<endl;
 cout<<"STAGE 2: Global overlap/extrusion checking within 10 microns"<<endl;
 cout<<"===================================================================="<<endl;
 geo->CheckOverlaps(0.001);*/
	//Standard checking uses points on the volume`s vertices and edges to find illegal overlaps with other volumes and is reproducible. 
	  
}
