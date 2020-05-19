#include <iostream>
#include "mikroby.h"

using namespace std;

Mikroby::Mikroby():MinEnergiaDoPodzialu(rand()%250+170){
	energia = 125; //roboczo
}

int Mikroby::getEnergia(){return energia;}

int Mikroby::getMinEnergia(){return MinEnergiaDoPodzialu;}

void Mikroby::podziel(){
;//;
}

void Mikroby::skonaj(){
;//;
}

////////////////////////////////////////////////

Samozywne::Samozywne():Mikroby(),MaxZatrucie(rand()%40+50){
	zdolnoscRuchu = true;
	zebrane_H2O = 0;
	zebrane_CO2 = 0;
	zatrucie = 0;
}

void Samozywne::zbierz(){
;//;
}

void Samozywne::przerob(){
;//;
}

int Samozywne::getH2O(){return zebrane_H2O;}

int Samozywne::getCO2(){return zebrane_CO2;}

int Samozywne::getZatrucie(){return zatrucie;}

int Samozywne::getMaxZatrucie(){return MaxZatrucie;}

void Samozywne::odtruj(){
	if(zatrucie>0) zatrucie--;
}

string Samozywne::toString(){return "S";}

//////////////////////////////////////////////////////////////

Cudzozywne::Cudzozywne():Mikroby(),MaxZatrucie(rand()%40+50){
	zdolnoscRuchu = true;
	zebrana_glukoza = 0;
	zebrany_tlen = 0;
	zatrucie = 0;
}

void Cudzozywne::zbierz(){
;//;
}

void Cudzozywne::przerob(){
;//;
}

int Cudzozywne::getGlukoza(){return zebrana_glukoza;}

int Cudzozywne::getTlen(){return zebrany_tlen;}

int Cudzozywne::getZatrucie(){return zatrucie;}

int Cudzozywne::getMaxZatrucie(){return MaxZatrucie;}

void Cudzozywne::odtruj(){
	if(zatrucie>0) zatrucie--;
}

string Cudzozywne::toString(){return "U";}

////////////////////////////////////////////////////////////////

Reducenci::Reducenci():Mikroby(){
	zdolnoscRuchu = true;
	zebrany_etanol = 0;
	zebrany_metan = 0;
}

void Reducenci::zbierz(){
;//;
}

void Reducenci::przerob(){
;//;
}

int Reducenci::getEtanol(){return zebrany_etanol;}

int Reducenci::getMetan(){return zebrany_metan;}

string Reducenci::toString(){return "R";}
