#ifndef __STROKE__
#define __STROKE__

#include <iostream>
#include "State.h"

namespace rh = redhat;
using namespace std;

namespace redhat{
	class Stroke{
	public:
		rh::State state[3];
		int featureNum; //used to count the number of features and then used to find the transition probability
		int trainingTimes; //used to count the number of training times and then used to find the transition probability
		
		Stroke();
		~Stroke();
		void setState(int i, rh::State ob);
		rh::State getState(int i);
		int getAverageNumOfFeatures();
		void display();
	};
	
	Stroke::Stroke(){
//		for(int i=0; i<3; i++){
//			state[i] = new State();
//		}
		featureNum=0;
		trainingTimes=0;
	}
	
	Stroke::~Stroke(){
//		delete [] state;	
	}
	
	void Stroke::setState(int i, rh::State ob){
		state[i] = ob;
	}
	
	rh::State Stroke::getState(int i){
		return state[i];
	}
		
	int Stroke::getAverageNumOfFeatures(){
		return featureNum/trainingTimes;
	}
	
	void Stroke::display(){
		for(int i=0; i<3; i++){
			state[i].display();	
		}	
	}
}

#endif