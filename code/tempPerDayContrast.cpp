#include <iostream>
#include "tempTrender.h"

void plotComparison() {
	
	string pathToFile = "/home/courseuser/MNXB01/2017HT/Project/datasets/uppsala_tm_1722-2013.dat";
	tempTrender Upp(pathToFile);
	Upp.read_temperatures();
	Upp.tempPerDayExtended();
	
	
	TH1D* UppHist = new TH1D("Upp", "Uppsala; Day; Temperature (#circ C)",
			Upp.avgOfData.size()-1, 0, Upp.avgOfData.size());
	TLegend *leg = new TLegend(0.50,0.5,0.75, 0.3);
	
	
	for (unsigned int i = 0; i< Upp.avgOfData.size(); i++){
		UppHist->SetBinContent(i,Upp.avgOfData.at(i));
	}
	
	
	TH1D* UppWarmHist = new TH1D("Upp", "Uppsala; Day; Temperature (#circ C)",
			Upp.avgOfData.size()-1, 0, Upp.avgOfData.size());
	
	for (unsigned int i = 0; i< Upp.avgOfData.size(); i++){
		UppWarmHist->SetBinContent(i,Upp.theWarmestDays.at(i));
	}
	
	TH1D* UppColdHist = new TH1D("Upp", "Uppsala; Day; Temperature (#circ C)",
			Upp.avgOfData.size()-1, 0, Upp.avgOfData.size());
	
	for (unsigned int i = 0; i< Upp.avgOfData.size(); i++){
		UppColdHist->SetBinContent(i,Upp.theColdestDays.at(i));
	}
	
		
	TH1D* UrbanUppHist = new TH1D ("hPhi", "Uppsala Urban; Day; Temperature (#circ C)", 
			Upp.urbanAvgOfData.size() -1, 0, Upp.urbanAvgOfData.size());
			
	for(unsigned int i = 0 ; i< Upp.urbanAvgOfData.size() ; i++){
		UrbanUppHist->SetBinContent(i,Upp.urbanAvgOfData.at(i));
	}

	
	TH1D* UrbanUppWarmHist = new TH1D("Upp", "Uppsala; Day; Temperature (#circ C)",
			Upp.avgOfData.size()-1, 0, Upp.urbanAvgOfData.size());
	
	for (unsigned int i = 0; i< Upp.avgOfData.size(); i++){
		UrbanUppWarmHist->SetBinContent(i,Upp.theWarmestUrbanDays.at(i));
	}
	
	TH1D* UrbanUppColdHist = new TH1D("Upp", "Uppsala; Day; Temperature (#circ C)",
			Upp.urbanAvgOfData.size()-1, 0, Upp.urbanAvgOfData.size());
	
	for (unsigned int i = 0; i< Upp.avgOfData.size(); i++){
		UrbanUppColdHist->SetBinContent(i,Upp.theColdestUrbanDays.at(i));
	}
	
	
	leg->AddEntry(UrbanUppHist, "", "L");
	


	UppHist->SetLineColor(kMagenta);
	UppHist->SetMinimum(-35);
	UppHist->SetMaximum(30),
	UppHist->Draw();
	UppColdHist->SetLineColor(kMagenta);
	UppWarmHist->SetLineColor(kMagenta);
	UrbanUppHist->SetLineColor(kMagenta +3);
	UrbanUppColdHist->SetLineColor(kMagenta +3);
	UrbanUppWarmHist->SetLineColor(kMagenta +3);
	UrbanUppHist->Draw("SAME");
	UppColdHist->Draw("SAME");
	UppWarmHist->Draw("SAME");
	UrbanUppColdHist->Draw("SAME");
	UrbanUppWarmHist->Draw("SAME");
	
	
	
	
	
	string pathSoder = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Soderarm.csv"; //Put the path to your data file here
	tempTrender Soder(pathSoder);
	Soder.read_temperatures();
	
	
	
	Soder.tempPerDayExtended();

	TH1D* SoderHist = new TH1D("Upp", "Soderarm; Day; Temperature (#circ C)", 
			Soder.avgOfData.size()-1 , 0, Soder.avgOfData.size() );
	
	for(unsigned int i = 0 ; i< Soder.avgOfData.size() ; i++){
		SoderHist->SetBinContent(i,Soder.avgOfData.at(i));
	}
	
	
	
	TH1D* SoderWarmHist = new TH1D("Upp", "Uppsala; Day; Temperature (#circ C)",
			Soder.avgOfData.size()-1, 0, Soder.avgOfData.size());
	
	for (unsigned int i = 0; i< Soder.avgOfData.size(); i++){
		SoderWarmHist->SetBinContent(i,Soder.theWarmestDays.at(i));
	}
	
	TH1D* SoderColdHist = new TH1D("Upp", "Uppsala; Day; Temperature (#circ C)",
			Soder.avgOfData.size()-1, 0, Soder.avgOfData.size());
	
	for (unsigned int i = 0; i< Soder.avgOfData.size(); i++){
		SoderColdHist->SetBinContent(i,Soder.theColdestDays.at(i));
	}
	

	leg->AddEntry(SoderHist, "","L");
	leg->AddEntry(SoderColdHist, "","L");
	leg->AddEntry(SoderWarmHist, "","L");
	
	SoderHist->SetLineColor(kRed);
	SoderColdHist->SetLineColor(kRed);
	SoderWarmHist->SetLineColor(kRed);
	//SoderHist->SetMinimum(-15);
	//SoderHist->SetMaximum(24);
	SoderHist->Draw("SAME");
	SoderWarmHist->Draw("SAME");
	SoderColdHist->Draw("SAME");
	
	
	
	
	
	string pathLund = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Lund.csv";
	tempTrender Lund(pathLund);

	Lund.read_temperatures();

	
	
	Lund.tempPerDayExtended();
	
	TH1D* LundHist = new TH1D("hPhi", "Lund; day; Temperature (#circ C)", 
			Lund.avgOfData.size() -1, 0, Lund.avgOfData.size());
	
	for (unsigned int i = 0; i < Lund.avgOfData.size(); i++){
		LundHist->SetBinContent(i,Lund.avgOfData.at(i));
	}
	
	
	
	TH1D* LundWarmHist = new TH1D("Upp", "Uppsala; Day; Temperature (#circ C)",
			Lund.avgOfData.size()-1, 0, Lund.avgOfData.size());
	
	for (unsigned int i = 0; i< Lund.avgOfData.size(); i++){
		LundWarmHist->SetBinContent(i,Lund.theWarmestDays.at(i));
	}
	
	TH1D* LundColdHist = new TH1D("Upp", "Uppsala; Day; Temperature (#circ C)",
			Lund.avgOfData.size()-1, 0, Lund.avgOfData.size());
	
	for (unsigned int i = 0; i< Lund.avgOfData.size(); i++){
		LundColdHist->SetBinContent(i,Lund.theColdestDays.at(i));
	}
	

	
	leg->AddEntry(LundHist, "", "L");
	LundHist->SetLineColor(kBlue);
	LundHist->Draw("SAME");
	LundWarmHist->SetLineColor(kBlue);
	LundWarmHist->Draw("SAME");
	LundColdHist->SetLineColor(kBlue);
	LundColdHist->Draw("SAME");
	
	
	
	
	
	
	
	
	string pathLule = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Lulea.csv";
	tempTrender Lule(pathLule);
	Lule.read_temperatures();

	
	
	Lule.tempPerDayExtended();
	
	TH1D* LuleHist = new TH1D("hPhi", "Lulea; day; Temperature (#circ C)", 
			Lule.avgOfData.size() -1, 0, Lule.avgOfData.size());
	
	for (unsigned int i = 0; i < Lule.avgOfData.size(); i++){
		LuleHist->SetBinContent(i,Lule.avgOfData.at(i));
	}
	
	
	
	TH1D* LuleWarmHist = new TH1D("Upp", "Uppsala; Day; Temperature (#circ C)",
			Lule.avgOfData.size()-1, 0, Lule.avgOfData.size());
	
	for (unsigned int i = 0; i< Lule.avgOfData.size(); i++){
		LuleWarmHist->SetBinContent(i,Lule.theWarmestDays.at(i));
	}
	
	TH1D* LuleColdHist = new TH1D("Upp", "Uppsala; Day; Temperature (#circ C)",
			Lule.avgOfData.size()-1, 0, Lule.avgOfData.size());
	
	for (unsigned int i = 0; i< Lule.avgOfData.size(); i++){
		LuleColdHist->SetBinContent(i,Lule.theColdestDays.at(i));
	}
	

		
	leg->AddEntry(LuleHist, "", "L");
	LuleHist->SetLineColor(kCyan);
	LuleWarmHist->SetLineColor(kCyan);
	LuleColdHist->SetLineColor(kCyan);
	LuleHist->Draw("SAME");
	LuleWarmHist->Draw("SAME");
	LuleColdHist->Draw("SAME");
	
	
	
	
	string pathBoras = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Boras.csv";
	tempTrender Boras(pathBoras);
	Boras.read_temperatures();
	
	Boras.tempPerDayExtended();
	
	TH1D* BorasHist = new TH1D("hPhi", "Boras; day; Temperature (#circ C)", 
			Boras.avgOfData.size() -1, 0, Boras.avgOfData.size());
	
	for (unsigned int i = 0; i < Boras.avgOfData.size(); i++){
		BorasHist->SetBinContent(i,Boras.avgOfData.at(i));
	}
		
	
	
	TH1D* BorasWarmHist = new TH1D("Upp", "Uppsala; Day; Temperature (#circ C)",
			Boras.avgOfData.size()-1, 0, Boras.avgOfData.size());
	
	for (unsigned int i = 0; i< Boras.avgOfData.size(); i++){
		BorasWarmHist->SetBinContent(i,Boras.theWarmestDays.at(i));
	}
	
	TH1D* BorasColdHist = new TH1D("Upp", "Uppsala; Day; Temperature (#circ C)",
			Boras.avgOfData.size()-1, 0, Boras.avgOfData.size());
	
	for (unsigned int i = 0; i< Boras.avgOfData.size(); i++){
		BorasColdHist->SetBinContent(i,Boras.theColdestDays.at(i));
	}	
		
		
	leg->AddEntry(BorasHist, "", "L");
	BorasHist->SetLineColor(kGreen);
	BorasWarmHist->SetLineColor(kGreen);
	BorasColdHist->SetLineColor(kGreen);
	BorasHist->Draw("SAME");
	BorasWarmHist->Draw("SAME");
	BorasColdHist->Draw("SAME");
	
	
	
	
	string pathFalun = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Falun.csv";
	tempTrender Falun(pathFalun);
	Falun.read_temperatures();
	
	
	Falun.tempPerDayExtended();
	
	TH1D* FalunHist = new TH1D("hPhi", "Fauln; day; Temperature (#circ C)", 
			Falun.avgOfData.size() -1, 0, Falun.avgOfData.size());
	
	for (unsigned int i = 0; i < Falun.avgOfData.size(); i++){
		FalunHist->SetBinContent(i,Falun.avgOfData.at(i));
	}
		
	
	TH1D* FalunWarmHist = new TH1D("Upp", "Uppsala; Day; Temperature (#circ C)",
			Falun.avgOfData.size()-1, 0, Falun.avgOfData.size());
	
	for (unsigned int i = 0; i< Falun.avgOfData.size(); i++){
		FalunWarmHist->SetBinContent(i,Falun.theWarmestDays.at(i));
	}
	
	TH1D* FalunColdHist = new TH1D("Upp", "Uppsala; Day; Temperature (#circ C)",
			Falun.avgOfData.size()-1, 0, Falun.avgOfData.size());
	
	for (unsigned int i = 0; i< Falun.avgOfData.size(); i++){
		FalunColdHist->SetBinContent(i,Falun.theColdestDays.at(i));
	}		
		
	leg->AddEntry(FalunHist, "", "L");
	FalunHist->SetLineColor(kGreen +2);
	FalunWarmHist->SetLineColor(kGreen +2);
	FalunColdHist->SetLineColor(kGreen +2);
	FalunHist->Draw("SAME");
	FalunWarmHist->Draw("SAME");
	FalunColdHist->Draw("SAME");
	
	
	
	string pathFalster = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Falsterbo.csv";
	tempTrender Falster(pathFalster);
	Falster.read_temperatures();
	
	
	Falster.tempPerDayExtended();
	
	TH1D* FalsterHist = new TH1D("hPhi", "Falsterbo; day; Temperature (#circ C)", 
			Falster.avgOfData.size()-1 , 0, Falster.avgOfData.size());
	
	for (unsigned int i = 0; i < Falster.avgOfData.size(); i++){
		FalsterHist->SetBinContent(i,Falster.avgOfData.at(i));
	}
		
	
	TH1D* FalsterWarmHist = new TH1D("Upp", "Uppsala; Day; Temperature (#circ C)",
			Falster.avgOfData.size()-1, 0, Falster.avgOfData.size());
	
	for (unsigned int i = 0; i< Falster.avgOfData.size(); i++){
		FalsterWarmHist->SetBinContent(i,Falster.theWarmestDays.at(i));
	}
	
	TH1D* FalsterColdHist = new TH1D("Upp", "Uppsala; Day; Temperature (#circ C)",
			Falster.avgOfData.size()-1, 0, Falster.avgOfData.size());
	
	for (unsigned int i = 0; i< Falster.avgOfData.size(); i++){
		FalsterColdHist->SetBinContent(i,Falster.theColdestDays.at(i));
	}			
		
	leg->AddEntry(FalsterHist, "", "L");
	FalsterHist->SetLineColor(kGray+2);
	FalsterWarmHist->SetLineColor(kGray+2);
	FalsterColdHist->SetLineColor(kGray+2);
	FalsterHist->Draw("SAME");
	FalsterWarmHist->Draw("SAME");
	FalsterColdHist->Draw("SAME");
	
	
	
	string pathUmea = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Umea.csv";
	tempTrender Umea(pathUmea);
	Umea.read_temperatures();
	
	
	Umea.tempPerDayExtended();
	
	TH1D* UmeaHist = new TH1D("hPhi", "Umea; day; Temperature (#circ C)", 
			Umea.avgOfData.size()-1 , 0, Umea.avgOfData.size());
	
	for (unsigned int i = 0; i < Umea.avgOfData.size(); i++){
		UmeaHist->SetBinContent(i,Umea.avgOfData.at(i));
	}
	
	
	TH1D* UmeaWarmHist = new TH1D("Upp", "Uppsala; Day; Temperature (#circ C)",
			Umea.avgOfData.size()-1, 0, Umea.avgOfData.size());
	
	for (unsigned int i = 0; i< Umea.avgOfData.size(); i++){
		UmeaWarmHist->SetBinContent(i,Umea.theWarmestDays.at(i));
	}
	
	TH1D* UmeaColdHist = new TH1D("Upp", "Uppsala; Day; Temperature (#circ C)",
			Umea.avgOfData.size()-1, 0, Umea.avgOfData.size());
	
	for (unsigned int i = 0; i< Umea.avgOfData.size(); i++){
		UmeaColdHist->SetBinContent(i,Umea.theColdestDays.at(i));
	}			
		
	
	leg->AddEntry(UmeaHist, "", "L");
	UmeaHist->SetLineColor(kBlue-6);
	UmeaWarmHist->SetLineColor(kBlue-6);
	UmeaColdHist->SetLineColor(kBlue-6);
	UmeaHist->Draw("SAME");
	UmeaWarmHist->Draw("SAME");
	UmeaColdHist->Draw("SAME");
	
	
	
	
	string pathKarl = "/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-openda_Karlstad.csv";
	tempTrender Karl(pathKarl);
	Karl.read_temperatures();
	
	
	Karl.tempPerDayExtended();
	
	TH1D* KarlHist = new TH1D("hPhi", "Karlstad; day; Temperature (#circ C)", 
			Karl.avgOfData.size()-1 , 0, Karl.avgOfData.size());
	
	for (unsigned int i = 0; i < Karl.avgOfData.size(); i++){
		KarlHist->SetBinContent(i,Karl.avgOfData.at(i));
	}
	
	
	
	TH1D* KarlWarmHist = new TH1D("Upp", "Uppsala; Day; Temperature (#circ C)",
			Karl.avgOfData.size()-1, 0, Karl.avgOfData.size());
	
	for (unsigned int i = 0; i< Karl.avgOfData.size(); i++){
		KarlWarmHist->SetBinContent(i,Karl.theWarmestDays.at(i));
	}
	
	TH1D* KarlColdHist = new TH1D("Upp", "Uppsala; Day; Temperature (#circ C)",
			Karl.avgOfData.size()-1, 0, Karl.avgOfData.size());
	
	for (unsigned int i = 0; i< Karl.avgOfData.size(); i++){
		KarlColdHist->SetBinContent(i,Karl.theColdestDays.at(i));
	}			
		
	leg->AddEntry(KarlHist, "", "L");
	KarlHist->SetLineColor(kOrange +7);
	KarlWarmHist->SetLineColor(kOrange +7);
	KarlColdHist->SetLineColor(kOrange +7);
	KarlHist->Draw("SAME");
	KarlWarmHist->Draw("SAME");
	KarlColdHist->Draw("SAME");
	
	
	
	
	string pathVisby ="/home/courseuser/MNXB01/2017HT/Project/datasets/smhi-opendata_Visby.csv";
	tempTrender Visby(pathVisby);
	Visby.read_temperatures();
	
	
	Visby.tempPerDayExtended();
	
	TH1D* VisbyHist = new TH1D("hPhi", "Visby; day; Temperature (#circ C)", 
			Visby.avgOfData.size()-1 , 0, Visby.avgOfData.size());
	
	for (unsigned int i = 0; i < Visby.avgOfData.size(); i++){
		VisbyHist->SetBinContent(i,Visby.avgOfData.at(i));
	}
	
	
	
	TH1D* VisbyWarmHist = new TH1D("Upp", "Uppsala; Day; Temperature (#circ C)",
			Visby.avgOfData.size()-1, 0, Visby.avgOfData.size());
	
	for (unsigned int i = 0; i< Visby.avgOfData.size(); i++){
		VisbyWarmHist->SetBinContent(i,Visby.theWarmestDays.at(i));
	}
	
	TH1D* VisbyColdHist = new TH1D("Upp", "Uppsala; Day; Temperature (#circ C)",
			Visby.avgOfData.size()-1, 0, Visby.avgOfData.size());
	
	for (unsigned int i = 0; i< Visby.avgOfData.size(); i++){
		VisbyColdHist->SetBinContent(i,Visby.theColdestDays.at(i));
	}	
	
	leg->AddEntry(VisbyHist, "", "L");
	VisbyHist->SetLineColor(kBlack);
	VisbyWarmHist->SetLineColor(kBlack);
	VisbyColdHist->SetLineColor(kBlack);
	VisbyHist->Draw("SAME");
	VisbyColdHist->Draw("SAME");
	VisbyWarmHist->Draw("SAME");
	

	
	
	leg->AddEntry(UppWarmHist, "Highest recorded temperature");
	leg->AddEntry(UppHist, "Average of recorded temperatures");
	leg->AddEntry(UppColdHist, "Lowest recorded temperature");
	leg->Draw("SAME");
	
	
	
}
