#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

string Submodes[20] = {
/*1*/ "Scan - Nadir Point", 
/*2*/ "Available Sub-Modes",
/*3*/ "Deployment - Boot",
/*4*/ "Deployment - Connect Prep",
/*5*/ "Deployment - Connect",
/*6*/ "Cruise - Idle",
/*7*/ "Cruise - Radiation Idle",
/*8*/ "Cruise - Power Generation",
/*9*/ "Cruise - Heat Protection Idle",
/*10*/"Scan - Point Prep",
/*11*/"Scan - Target Point",
/*12*/"Scan - Point Exit",
/*13*/"Scan - Nadir Point",
/*14*/"Data Processing - Compute Prep",
/*15*/"Data Processing - SfM",
/*16*/"Data Processing - Neural Net",
/*17*/"Data Processing - Blob Detect",
/*18*/"Data Processing - Compute Exit",
/*19*/"Data Downlink - Data Prep",
/*20*/"Data Downlink - Data Transmit",
/*21*/"Data Downlink - Transmit Exit",
/*22*/"Safe"};

class Component{
	/*Each component contains it's name and an array of floats. Each index 
	represents the submode (1-20). 	The value itself is the coefficient that 
	represents the component's power draw per unit time.*/
	string compName;
	float submodeCoeff[20];

	/*constuctors set all the attributes if they are specified or at least 
	populates the array with 0s*/
	Component(string name, float time, int submode){
		compName = name;
		submodeCoeff[submode] = time;
	}
	Component(string name){
		compName = name;
		for(int i = 0; i < 20; i++){
			submodeCoeff[i] = 0;
		}
	}

	/*function to set the coefficient of a specific submode*/
	setSubmodeCoeff(float time, int submode){
		this.submodeCoeff[submode] = x;
	}
};

//instantiating all thhe components and giving them submode:coeff values
void populateComps(){
	ADCS = Component("ADCS Motherboard");
	SunSensors = Component("Fine Sun Sensors (x2)");
	SolarPanels = Component("Solar Panels");
	EPSMotherboard = Component("EPS Motherboard");
	Batteries = Component("40Whr 3G Batteries");
	OBCMotherboard = Component("OBC Motherboard");
	GPS = Component("GPS");
	UHFTrans = Component("UHF Transciever");
	UHFAntenna = Component("UHF Antenna System");
	SbandTrans = Component("S-band Transmitter");
	Picocam = Component("Picocam");
	Tx2 = Component("Jetson Tx2 (Max-Q)");
	Opal = Component("Opal Kelly XEM7310");
	Component Components[12] = {ADCS, SunSensors, SolarPanels, EPSMotherboard, 
		Batteries, OBCMotherboard, GPS, UHFTrans, UHFAntenna, SbandTrans, 
		Picocam, Tx2, Opal};
}

void caculateSubmodePower(float time, int submode){
	float powerDraw = 0;
	for(int i = 0; i < 12; i++){
		powerDraw += Components[i].submodeCoeff[submode] * time;
	}
	return powerDraw; 
}

int main(){
	populateComps();
	calculateSubmodePower(/*time spent in submode*/, /*submode id*/)
}