#include <iostream>
#include <utility>
#include "object.h"

using namespace std;

Object::Object():zdolnoscRuchu(false){}

bool Object::getZdolnoscRuchu(){return zdolnoscRuchu;}

std::pair<int,int> Object::getPos(Object*** plansza,int height,int width){
	for(int h=0;h<height;h++){
		for(int w=0;w<width;w++){
			if(plansza[h][w]!=NULL && this==plansza[h][w]){
				return std::make_pair(h,w);	
			}
		}
	}
	return make_pair(-1,-1);
}
