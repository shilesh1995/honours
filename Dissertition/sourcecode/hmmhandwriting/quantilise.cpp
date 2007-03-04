#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include "convert.h"


using namespace std;

int vector[16];
const double PI= 4.0*atan(1.0);

int main(){
	for(int i=0; i<16; i++){
		vector[i] = 0;
//		cout<<vector[i]<<endl;
	}

	double x1,y1,x2,y2 = -1;
	string xtemp, ytemp;

	string line;
	char *file = "./data/data.txt";
	
	ifstream dataFile(file);
	if(!dataFile){
		cout << "Cannot open file.\n";
		return 1;
	}else{
		while(!dataFile.eof()){
			getline(dataFile, line);
//			cout << line <<endl;
			
			//string handling
			if(line.compare("<s>")==0){
				cout<<"Stroke start\n";
			}else if(line.compare("</s>")==0){
				cout<<"Stroke end\n";
			}else{
				int commaPosition = line.find(",");
				
				if(commaPosition != string::npos){
					xtemp = line.substr(0,commaPosition);
					ytemp = line.substr(commaPosition+1);
//					cout<<xtemp<<endl;
//					cout<<ytemp<<endl;
					
					//cast string to double
					if(x1==-1){
						x1 = convertToDouble(xtemp);
						y1 = convertToDouble(ytemp);
					}else{
						x1 = x2;
						y1 = y2;
						x2 = convertToDouble(xtemp);
						y2 = convertToDouble(ytemp);
					}
					cout<<x1<<", "<<y1<<endl;
				}
			}
		}
		dataFile.close();
	}
	
	return 0;
}
