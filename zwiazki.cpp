#include <iostream>
#include "zwiazki.h"

using namespace std;

bool Zwiazki::getCzyToksyczny(){return czyToksyczny;}

Metan::Metan(){
	zdolnoscRuchu = true;
	czyToksyczny = true;
	toksycznosc = 10; // roboczo
}

int Metan::getToksycznosc(){return toksycznosc;}

string Metan::toString(){return "M";}

Etanol::Etanol(){
	zdolnoscRuchu = false;
	czyToksyczny = true;
	toksycznosc = 20; //roboczo
}

int Etanol::getToksycznosc(){return toksycznosc;}

string Etanol::toString(){return "E";}

Woda::Woda(){
	zdolnoscRuchu = false;	
	czyToksyczny = false;
}

string Woda::toString(){return "W";}

Dwutlenek::Dwutlenek(){
	zdolnoscRuchu = false;
	czyToksyczny = false;
}

string Dwutlenek::toString(){return "D";}

Glukoza::Glukoza(){
	zdolnoscRuchu = false;
	czyToksyczny = false;
	wartoscOdzywcza = 15; //roboczo
}

string Glukoza::toString(){return "G";}
