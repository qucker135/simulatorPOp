#include <iostream>
#include <stdlib.h>
#include "mikroby.h"

using namespace std;

Mikroby::Mikroby():MinEnergiaDoPodzialu(rand()%250+170){
	energia = 10; //roboczo
}

Mikroby::Mikroby(int minEnergia):MinEnergiaDoPodzialu(minEnergia){}

int Mikroby::getEnergia(){return energia;}

void Mikroby::zmniejszEnergie(){energia--;}

int Mikroby::getMinEnergia(){return MinEnergiaDoPodzialu;}

void Mikroby::skonaj(Object*** plansza,int height,int width,int curX,int curY){//Object***,height,width,curX,curY
	if(curX>=0 && curX<height && curY>=0 && curY<width && plansza[curX][curY]!=NULL){
		delete plansza[curX][curY];
		plansza[curX][curY] = NULL;
	}
}

////////////////////////////////////////////////

Samozywne::Samozywne():Mikroby(),MaxZatrucie(rand()%40+50){
	zdolnoscRuchu = true;
	zebrane_H2O = 0;
	zebrane_CO2 = 0;
	zatrucie = 0;
}
Samozywne::Samozywne(int zebrane_H2O, int zebrane_CO2, int energia, int MinEnergia,int zatrucie, int maxzatrucie):Mikroby(MinEnergia),MaxZatrucie(maxzatrucie){
	zdolnoscRuchu = true;
	this->zebrane_H2O = zebrane_H2O;
	this->zebrane_CO2 = zebrane_CO2;
	this->energia = energia;
	this->zatrucie = zatrucie;
}

void Samozywne::zbierz(Object*** plansza,int height,int width,int curX,int curY,char direction){
	switch(direction){
		case 'w':
			if(curX>0 && plansza[curX-1][curY]!=NULL){
				if(plansza[curX-1][curY]->toString()=="W"){
					delete plansza[curX-1][curY];
					plansza[curX-1][curY] = NULL;
					zebrane_H2O+=5;
				}
				else if(plansza[curX-1][curY]->toString()=="D"){
					delete plansza[curX-1][curY];
					plansza[curX-1][curY] = NULL;
					zebrane_CO2+=5;
				}
				else if(plansza[curX-1][curY]->toString()=="E"){
					delete plansza[curX-1][curY];
					plansza[curX-1][curY] = NULL;
					zatrucie+=5;
				}
				else if(plansza[curX-1][curY]->toString()=="M"){
					delete plansza[curX-1][curY];
					plansza[curX-1][curY] = NULL;
					zatrucie+=10;
				}
			}
		break;
		case 'a':
			if(curY>0 && plansza[curX][curY-1]!=NULL){
				if(plansza[curX][curY-1]->toString()=="W"){
					delete plansza[curX][curY-1];
					plansza[curX][curY-1] = NULL;
					zebrane_H2O+=5;
				}
				else if(plansza[curX][curY-1]->toString()=="D"){
					delete plansza[curX][curY-1];
					plansza[curX][curY-1] = NULL;
					zebrane_CO2+=5;
				}
				else if(plansza[curX][curY-1]->toString()=="E"){
					delete plansza[curX][curY-1];
					plansza[curX][curY-1] = NULL;
					zatrucie+=5;
				}
				else if(plansza[curX][curY-1]->toString()=="M"){
					delete plansza[curX][curY-1];
					plansza[curX][curY-1] = NULL;
					zatrucie+=10;
				}
			}
		break;
		case 's':
			if(curX<height-1 && plansza[curX+1][curY]!=NULL){
				if(plansza[curX+1][curY]->toString()=="W"){
					delete plansza[curX+1][curY];
					plansza[curX+1][curY] = NULL;
					zebrane_H2O+=5;
				}
				else if(plansza[curX+1][curY]->toString()=="D"){
					delete plansza[curX+1][curY];
					plansza[curX+1][curY] = NULL;
					zebrane_CO2+=5;
				}
				else if(plansza[curX+1][curY]->toString()=="E"){
					delete plansza[curX+1][curY];
					plansza[curX+1][curY] = NULL;
					zatrucie+=5;
				}
				else if(plansza[curX+1][curY]->toString()=="M"){
					delete plansza[curX+1][curY];
					plansza[curX+1][curY] = NULL;
					zatrucie+=10;
				}
			}
		break;
		case 'd':
			if(curY<width-1 && plansza[curX][curY+1]!=NULL){
				if(plansza[curX][curY+1]->toString()=="W"){
					delete plansza[curX][curY+1];
					plansza[curX][curY+1] = NULL;
					zebrane_H2O+=5;
				}
				else if(plansza[curX][curY+1]->toString()=="D"){
					delete plansza[curX][curY+1];
					plansza[curX][curY+1] = NULL;
					zebrane_CO2+=5;
				}
				else if(plansza[curX][curY+1]->toString()=="E"){
					delete plansza[curX][curY+1];
					plansza[curX][curY+1] = NULL;
					zatrucie+=5;
				}
				else if(plansza[curX][curY+1]->toString()=="M"){
					delete plansza[curX][curY+1];
					plansza[curX][curY+1] = NULL;
					zatrucie+=10;
				}
			}
		break;
	}
}

void Samozywne::podziel(Object*** plansza,int height,int width,int curX,int curY,char direction){
	switch(direction){
		case 'w':
			if(curX>0 && plansza[curX-1][curY]==NULL){
				plansza[curX-1][curY] = new Samozywne(this->getH2O() - (this->getH2O()+1)/2,this->getCO2() - (this->getCO2()+1)/2, this->energia/2, this->MinEnergiaDoPodzialu, this->zatrucie - (this->zatrucie+1)/2, this->MaxZatrucie);
				this->zebrane_H2O = (this->zebrane_H2O+1)/2;
				this->zebrane_CO2 = (this->zebrane_CO2+1)/2;
				this->energia = (this->energia)/2;
				this->zatrucie = (this->zatrucie)/2;
			}
		break;
		case 'a':
			if(curY>0 && plansza[curX][curY-1]==NULL){
				plansza[curX][curY-1] = new Samozywne(this->getH2O() - (this->getH2O()+1)/2,this->getCO2() - (this->getCO2()+1)/2, this->energia/2, this->MinEnergiaDoPodzialu, this->zatrucie - (this->zatrucie+1)/2, this->MaxZatrucie);
				this->zebrane_H2O = (this->zebrane_H2O+1)/2;
				this->zebrane_CO2 = (this->zebrane_CO2+1)/2;
				this->energia = (this->energia)/2;
				this->zatrucie = (this->zatrucie)/2;
			}
		break;
		case 's':
			if(curX<height-1 && plansza[curX+1][curY]==NULL){
				plansza[curX+1][curY] = new Samozywne(this->getH2O() - (this->getH2O()+1)/2,this->getCO2() - (this->getCO2()+1)/2, this->energia/2, this->MinEnergiaDoPodzialu, this->zatrucie - (this->zatrucie+1)/2, this->MaxZatrucie);
				this->zebrane_H2O = (this->zebrane_H2O+1)/2;
				this->zebrane_CO2 = (this->zebrane_CO2+1)/2;
				this->energia = (this->energia)/2;
				this->zatrucie = (this->zatrucie)/2;
			}
		break;
		case 'd':
			if(curY<width-1 && plansza[curX][curY+1]==NULL){
				plansza[curX][curY+1] = new Samozywne(this->getH2O() - (this->getH2O()+1)/2,this->getCO2() - (this->getCO2()+1)/2, this->energia/2, this->MinEnergiaDoPodzialu, this->zatrucie - (this->zatrucie+1)/2, this->MaxZatrucie);
				this->zebrane_H2O = (this->zebrane_H2O+1)/2;
				this->zebrane_CO2 = (this->zebrane_CO2+1)/2;
				this->energia = (this->energia)/2;
				this->zatrucie = (this->zatrucie)/2;
			}
		break;
	}		
}

void Samozywne::przerob(){//zmienia tylko stan obiektu, nie potrzebuje argumentow
	if(zebrane_H2O>0 && zebrane_CO2>0)
	{
		zebrane_H2O--;
		zebrane_CO2--;
		energia+=20;
	}
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

Cudzozywne::Cudzozywne(int zebrana_glukoza, int zebrany_tlen, int energia, int MinEnergia,int zatrucie, int maxzatrucie):Mikroby(MinEnergia),MaxZatrucie(maxzatrucie){
	zdolnoscRuchu = true;
	this->zebrana_glukoza = zebrana_glukoza;
	this->zebrany_tlen = zebrany_tlen;
	this->energia = energia;
	this->zatrucie = zatrucie;
}

void Cudzozywne::zbierz(Object*** plansza,int height,int width,int curX,int curY,char direction){
	switch(direction){
		case 'w':
			if(curX>0 && plansza[curX-1][curY]!=NULL){
				if(plansza[curX-1][curY]->toString()=="G"){
					delete plansza[curX-1][curY];
					plansza[curX-1][curY] = NULL;
					zebrana_glukoza+=5;
				}
				else if(plansza[curX-1][curY]->toString()=="O"){
					delete plansza[curX-1][curY];
					plansza[curX-1][curY] = NULL;
					zebrany_tlen+=5;
				}
				else if(plansza[curX-1][curY]->toString()=="E"){
					delete plansza[curX-1][curY];
					plansza[curX-1][curY] = NULL;
					zatrucie+=5;
				}
				else if(plansza[curX-1][curY]->toString()=="M"){
					delete plansza[curX-1][curY];
					plansza[curX-1][curY] = NULL;
					zatrucie+=10;
				}
			}
		break;
		case 'a':
			if(curY>0 && plansza[curX][curY-1]!=NULL){
				if(plansza[curX][curY-1]->toString()=="G"){
					delete plansza[curX][curY-1];
					plansza[curX][curY-1] = NULL;
					zebrana_glukoza+=5;
				}
				else if(plansza[curX][curY-1]->toString()=="O"){
					delete plansza[curX][curY-1];
					plansza[curX][curY-1] = NULL;
					zebrany_tlen+=5;
				}
				else if(plansza[curX][curY-1]->toString()=="E"){
					delete plansza[curX][curY-1];
					plansza[curX][curY-1] = NULL;
					zatrucie+=5;
				}
				else if(plansza[curX][curY-1]->toString()=="M"){
					delete plansza[curX][curY-1];
					plansza[curX][curY-1] = NULL;
					zatrucie+=10;
				}
			}
		break;
		case 's':
			if(curX<height-1 && plansza[curX+1][curY]!=NULL){
				if(plansza[curX+1][curY]->toString()=="G"){
					delete plansza[curX+1][curY];
					plansza[curX+1][curY] = NULL;
					zebrana_glukoza+=5;
				}
				else if(plansza[curX+1][curY]->toString()=="O"){
					delete plansza[curX+1][curY];
					plansza[curX+1][curY] = NULL;
					zebrany_tlen+=5;
				}
				else if(plansza[curX+1][curY]->toString()=="E"){
					delete plansza[curX+1][curY];
					plansza[curX+1][curY] = NULL;
					zatrucie+=5;
				}
				else if(plansza[curX+1][curY]->toString()=="M"){
					delete plansza[curX+1][curY];
					plansza[curX+1][curY] = NULL;
					zatrucie+=10;
				}
			}
		break;
		case 'd':
			if(curY<width-1 && plansza[curX][curY+1]!=NULL){
				if(plansza[curX][curY+1]->toString()=="G"){
					delete plansza[curX][curY+1];
					plansza[curX][curY+1] = NULL;
					zebrana_glukoza+=5;
				}
				else if(plansza[curX][curY+1]->toString()=="O"){
					delete plansza[curX][curY+1];
					plansza[curX][curY+1] = NULL;
					zebrany_tlen+=5;
				}
				else if(plansza[curX][curY+1]->toString()=="E"){
					delete plansza[curX][curY+1];
					plansza[curX][curY+1] = NULL;
					zatrucie+=5;
				}
				else if(plansza[curX][curY+1]->toString()=="M"){
					delete plansza[curX][curY+1];
					plansza[curX][curY+1] = NULL;
					zatrucie+=10;
				}
			}
		break;
	}
}

void Cudzozywne::podziel(Object*** plansza,int height,int width,int curX,int curY,char direction){
	switch(direction){
		case 'w':
			if(curX>0 && plansza[curX-1][curY]==NULL){
				plansza[curX-1][curY] = new Cudzozywne(this->getGlukoza() - (this->getGlukoza()+1)/2,this->getTlen() - (this->getTlen()+1)/2, this->energia/2, this->MinEnergiaDoPodzialu, this->zatrucie - (this->zatrucie+1)/2, this->MaxZatrucie);
				this->zebrana_glukoza = (this->zebrana_glukoza+1)/2;
				this->zebrany_tlen = (this->zebrany_tlen+1)/2;
				this->energia = (this->energia)/2;
				this->zatrucie = (this->zatrucie)/2;
			}
		break;
		case 'a':
			if(curY>0 && plansza[curX][curY-1]==NULL){
				plansza[curX][curY-1] = new Cudzozywne(this->getGlukoza() - (this->getGlukoza()+1)/2,this->getTlen() - (this->getTlen()+1)/2, this->energia/2, this->MinEnergiaDoPodzialu, this->zatrucie - (this->zatrucie+1)/2, this->MaxZatrucie);
				this->zebrana_glukoza = (this->zebrana_glukoza+1)/2;
				this->zebrany_tlen = (this->zebrany_tlen+1)/2;
				this->energia = (this->energia)/2;
				this->zatrucie = (this->zatrucie)/2;
			}
		break;
		case 's':
			if(curX<height-1 && plansza[curX+1][curY]==NULL){
				plansza[curX+1][curY] = new Cudzozywne(this->getGlukoza() - (this->getGlukoza()+1)/2,this->getTlen() - (this->getTlen()+1)/2, this->energia/2, this->MinEnergiaDoPodzialu, this->zatrucie - (this->zatrucie+1)/2, this->MaxZatrucie);
				this->zebrana_glukoza = (this->zebrana_glukoza+1)/2;
				this->zebrany_tlen = (this->zebrany_tlen+1)/2;
				this->energia = (this->energia)/2;
				this->zatrucie = (this->zatrucie)/2;
			}
		break;
		case 'd':
			if(curY<width-1 && plansza[curX][curY+1]==NULL){
				plansza[curX][curY+1] = new Cudzozywne(this->getGlukoza() - (this->getGlukoza()+1)/2,this->getTlen() - (this->getTlen()+1)/2, this->energia/2, this->MinEnergiaDoPodzialu, this->zatrucie - (this->zatrucie+1)/2, this->MaxZatrucie);
				this->zebrana_glukoza = (this->zebrana_glukoza+1)/2;
				this->zebrany_tlen = (this->zebrany_tlen+1)/2;
				this->energia = (this->energia)/2;
				this->zatrucie = (this->zatrucie)/2;
			}
		break;
	}	
}

void Cudzozywne::przerob(){
	if(zebrana_glukoza>0 && zebrany_tlen>0)
	{
		zebrana_glukoza--;
		zebrany_tlen--;
		energia+=15;
	}
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

Reducenci::Reducenci(int zebrany_etanol, int zebrany_metan, int energia, int MinEnergia):Mikroby(MinEnergia){
	zdolnoscRuchu = true;
	this->zebrany_etanol = zebrany_etanol;
	this->zebrany_metan = zebrany_metan;
	this->energia = energia;
}

void Reducenci::zbierz(Object*** plansza,int height,int width,int curX,int curY,char direction){
	switch(direction){
		case 'w':
			if(curX>0 && plansza[curX-1][curY]!=NULL){
				if(plansza[curX-1][curY]->toString()=="E"){
					delete plansza[curX-1][curY];
					plansza[curX-1][curY] = NULL;
					zebrany_etanol+=5;
				}
				else if(plansza[curX-1][curY]->toString()=="M"){
					delete plansza[curX-1][curY];
					plansza[curX-1][curY] = NULL;
					zebrany_metan+=5;
				}
			}
		break;
		case 'a':
			if(curY>0 && plansza[curX][curY-1]!=NULL){
				if(plansza[curX][curY-1]->toString()=="E"){
					delete plansza[curX][curY-1];
					plansza[curX][curY-1] = NULL;
					zebrany_etanol+=5;
				}
				else if(plansza[curX][curY-1]->toString()=="M"){
					delete plansza[curX][curY-1];
					plansza[curX][curY-1] = NULL;
					zebrany_metan+=5;
				}
			}
		break;
		case 's':
			if(curX<height-1 && plansza[curX+1][curY]!=NULL){
				if(plansza[curX+1][curY]->toString()=="E"){
					delete plansza[curX+1][curY];
					plansza[curX+1][curY] = NULL;
					zebrany_etanol+=5;
				}
				else if(plansza[curX+1][curY]->toString()=="M"){
					delete plansza[curX+1][curY];
					plansza[curX+1][curY] = NULL;
					zebrany_metan+=5;
				}
			}
		break;
		case 'd':
			if(curY<width-1 && plansza[curX][curY+1]!=NULL){
				if(plansza[curX][curY+1]->toString()=="E"){
					delete plansza[curX][curY+1];
					plansza[curX][curY+1] = NULL;
					zebrany_etanol+=5;
				}
				else if(plansza[curX][curY+1]->toString()=="M"){
					delete plansza[curX][curY+1];
					plansza[curX][curY+1] = NULL;
					zebrany_metan+=5;
				}
			}
		break;
	}	
}

void Reducenci::podziel(Object*** plansza,int height,int width,int curX,int curY,char direction){
	switch(direction){
		case 'w':
			if(curX>0 && plansza[curX-1][curY]==NULL){
				plansza[curX-1][curY] = new Reducenci(this->getEtanol() - (this->getEtanol()+1)/2,this->getMetan() - (this->getMetan()+1)/2, this->energia/2, this->MinEnergiaDoPodzialu);
				this->zebrany_etanol = (this->zebrany_etanol+1)/2;
				this->zebrany_metan = (this->zebrany_metan+1)/2;
				this->energia = (this->energia)/2;
			}
		break;
		case 'a':
			if(curY>0 && plansza[curX][curY-1]==NULL){
				plansza[curX][curY-1] = new Reducenci(this->getEtanol() - (this->getEtanol()+1)/2,this->getMetan() - (this->getMetan()+1)/2, this->energia/2, this->MinEnergiaDoPodzialu);
				this->zebrany_etanol = (this->zebrany_etanol+1)/2;
				this->zebrany_metan = (this->zebrany_metan+1)/2;
				this->energia = (this->energia)/2;
			}
		break;
		case 's':
			if(curX<height-1 && plansza[curX+1][curY]==NULL){
				plansza[curX+1][curY] = new Reducenci(this->getEtanol() - (this->getEtanol()+1)/2,this->getMetan() - (this->getMetan()+1)/2, this->energia/2, this->MinEnergiaDoPodzialu);
				this->zebrany_etanol = (this->zebrany_etanol+1)/2;
				this->zebrany_metan = (this->zebrany_metan+1)/2;
				this->energia = (this->energia)/2;
			}
		break;
		case 'd':
			if(curY<width-1 && plansza[curX][curY+1]==NULL){
				plansza[curX][curY+1] = new Reducenci(this->getEtanol() - (this->getEtanol()+1)/2,this->getMetan() - (this->getMetan()+1)/2, this->energia/2, this->MinEnergiaDoPodzialu);
				this->zebrany_etanol = (this->zebrany_etanol+1)/2;
				this->zebrany_metan = (this->zebrany_metan+1)/2;
				this->energia = (this->energia)/2;
			}
		break;
	}	
}

void Reducenci::przerob(){
	int random = rand()%2;
	switch(random){
		case 0:
			if(zebrany_etanol>0){
				zebrany_etanol--;
				energia+=15;
			}
		break;
		case 1:
			if(zebrany_metan>0){
				zebrany_metan--;
				energia+=10;
			}
		break;
	}
}

int Reducenci::getEtanol(){return zebrany_etanol;}

int Reducenci::getMetan(){return zebrany_metan;}

string Reducenci::toString(){return "R";}
