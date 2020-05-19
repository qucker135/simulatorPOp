#include <iostream>
#include "object.h"
#include "pierwiastki.h"

using namespace std;

Wodor::Wodor(){
	zdolnoscRuchu = true; //Wodor porusza sie
}

string Wodor::toString(){return "H";}

void Wodor::syntezuj(){//jakie argumenty? Object*** plansza,height,width,curX,curY,direction
	;//;
}

Wegiel::Wegiel(){
	zdolnoscRuchu = false; //Wegiel nie porusza sie
}

string Wegiel::toString(){return "C";}

void Wegiel::syntezuj(){//jakie argumenty? Object*** plansza,height,width,curX,curY,direction
	;//;
}

Tlen::Tlen(){
	zdolnoscRuchu = true; //Tlen porusza sie
}

string Tlen::toString(){return "O";}

void Tlen::syntezuj(){//jakie argumenty? Object*** plansza,height,width,curX,curY,direction
	;//;
}
