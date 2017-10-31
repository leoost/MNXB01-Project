#ifndef TEMPTRENDER_H
#define TEMPTRENDER_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class tempTrender {
	public:
	tempTrender(string filePath); //Construct using the specified file
	~tempTrender();//Destructor
	string temp;
	void read_temperatures(){
		ifstream file(its_filePath.c_str());
		while(getline(file,temp)){
			if (getline(file,temp,'9')){
				cout << temp << endl;
			}
		}
	}
	
	//void tempOnDay(int monthToCalculate, int dayToCalculate); //Make a histogram of the temperature on this day
	//void tempOnDay(int dateToCalculate); //Make a histogram of the temperature on this date
	//void tempPerDay(); //Make a histogram of the average temperature of each day of the year
	//void hotCold(); //Make a histogram of the hottest and coldest day of the year
	//void tempPerYear(int yearToExtrapolate); //Make a histogram of average temperature per year, then fit and extrapolate to the given year

	private:
	string its_filePath;
};

#endif
