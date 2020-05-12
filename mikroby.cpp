#include<iostream>
#include"naglowki.h"
using namespace std;

int Mikroby::getEnergia()
{
	return energia;
}
void Mikroby::zbierz()
{
	
}
void Mikroby::przerob()
{
	
}
void Mikroby::podziel()
{
	
}
void Mikroby::skonaj()
{
	
}
///////////////////////////////
int Samozywne::getH2O()
{
	return zebrane_H2O;
}
int Samozywne::getCO2()
{
	return zebrane_CO2;
}
int Samozywne::getZatrucie()
{
	return zatrucie;
}
int Samozywne::getMaxZatrucie()
{
	return maxymalne_zatrucie;
}
void Samozywne::odtruj()
{
	
}
Samozywne::Samozywne (int h2o, int co2, int zat)
{
	zebrane_H2O=h2o;
	zebrane_CO2=co2;
	zatrucie=zat;
}
virtual string Samozywne::toString()
{
	return "S";
}
bool Samozywne::getZdolnoscRuchu() 
{
	return zdolnoscRuchu;
}
void Samozywne::setZdolnoscRuchu(int a) 
{
	zdolnoscRuchu=a;
}
virtual void Samozywne::ruch(Object*** plansza,const int N,int &tempX,int &tempY,int width,int height)
		 {
		     int tX;
             int tY;
		     do
             {
                  tX=tempX;
                  tY=tempY;

		     for (int i=0;i<N;i++)
             {
                int dir = rand()%4;
                 switch (dir)
                 {
                 case 0:
                     if(tX+1<width)
                     tX++;
                        break;
                 case 1:
                     if(tY+1<height)
                     tY++;
                        break;
                 case 2:
                     if(tX-1>=0)
                     tX--;
                        break;
                 case 3:
                     if(tY-1>=0)
                     tY--;
                        break;
                 }
             }
		 }while(!plansza[tX][tY]==NULL && plansza[tX][tY]->toString()!="W" && plansza[tX][tY]->toString()!="D" );
//          if(plansza[tX][tY]->toString()=="W") {zebrane_H2O++; getH2O();}
//          else if(plansza[tX][tY]->toString()=="D") {zebrane_CO2++; getCO2();}
//			else if(plansza[tX][tY]->toString()=="M") zatrucie++;
//			else if(plansza[tX][tY]->toString()=="E") zatrucie++;
          /*else*/{
		  plansza[tX][tY]=plansza[tempX][tempY];
		  plansza[tempX][tempY]=NULL;
		  tempX=tX;
		  tempY=tY;
		  zdolnoscRuchu=0;
          }
		 }
///////////////////////////////
int Cudzozywne::getGlukoza()
{
	return zebrana_glukoza;
}
int Cudzozywne::getTlen()
{
	return zebrany_tlen;
}
int Cudzozywne::getZatrucie()
{
	return zatrucie;
}
int Cudzozywne::getMaxZatrucie()
{
	return maxymalne_zatrucie;
}
void Cudzozywne::odtruj()
{
	
}
virtual string Cudzozywne::toString()
{
	return "U";
}
bool Cudzozywne::getZdolnoscRuchu() 
{
	return zdolnoscRuchu;
}
void Cudzozywne::setZdolnoscRuchu(int a) 
{
	zdolnoscRuchu=a;
}
Cudzozywne::Cudzozywne(int glukoza, int tlen, int zat) 
{
	zebrana_glukoza=glukoza;
	zebrany_tlen=tlen;
	zatrucie=zat;	
}
virtual void Cudzozywne::ruch(Object*** plansza,const int N,int &tempX,int &tempY,int width,int height)
		 {
		     int tX;
             int tY;
		     do
             {
                  tX=tempX;
                  tY=tempY;

		     for (int i=0;i<N;i++)
             {
                int dir = rand()%4;
                 switch (dir)
                 {
                 case 0:
                     if(tX+1<width)
                     tX++;
                        break;
                 case 1:
                     if(tY+1<height)
                     tY++;
                        break;
                 case 2:
                     if(tX-1>=1)
                     tX--;
                        break;
                 case 3:
                     if(tY-1>=1)
                     tY--;
                        break;
                 }
             }
		 }while(!plansza[tX][tY]==NULL && plansza[tX][tY]->toString()!="T" && plansza[tX][tY]->toString()!="G");
//          if(plansza[tX][tY]->toString()=="T") getTlen();
//          else if(plansza[tX][tY]->toString()=="G") getGlukoza();
//			else if(plansza[tX][tY]->toString()=="M") zatrucie++;
//			else if(plansza[tX][tY]->toString()=="E") zatrucie++;
          /*else*/{
		  plansza[tX][tY]=plansza[tempX][tempY];
		  plansza[tempX][tempY]=NULL;
		  tempX=tX;
		  tempY=tY;
		  zdolnoscRuchu=0;
          }
		 }
		 
///////////////////////////////
int Reducenci::getEtanol()
{
	return zebrany_etanol;
}
int Reducenci::getMetan()
{
	return zebrany_metan;
}
virtual string Reducenci::toString()
{
	return "R";
}
bool Reducenci::getZdolnoscRuchu() 
{
	return zdolnoscRuchu;
}
void Reducenci::setZdolnoscRuchu(int a) 
{
	zdolnoscRuchu=a;
}
Reducenci::Reducenci(int etanol, int metan) 
{
	zebrany_etanol=etanol;
	zebrany_metan=metan;	
}
virtual void Reducenci::ruch(Object*** plansza,const int N,int &tempX,int &tempY,int width,int height)
		 {
		     int tX;
             int tY;
		     do
             {
                  tX=tempX;
                  tY=tempY;
		     for (int i=0;i<N;i++)
             {
                int dir = rand()%4;
                 switch (dir)
                 {
                 case 0:
                     if(tX+1<width)
                     tX++;
                        break;
                 case 1:
                     if(tX+1<height)
                     tY++;
                        break;
                 case 2:
                     if(tX-1>0)
                     tX--;
                        break;
                 case 3:
                     if(tX-1>0)
                     tY--;
                    break;
                 }
             }
		 }while(!plansza[tX][tY]==NULL && plansza[tX][tY]->toString()!="E" && plansza[tX][tY]->toString()!="M");
//          if(plansza[tX][tY]->toString()=="E") {zebrany_etanol++; getEtanol();}
//          else if(plansza[tX][tY]->toString()=="M") {zebrany_metan++; getMetan();}
          /*else*/{
		  plansza[tX][tY]=plansza[tempX][tempY];
		  plansza[tempX][tempY]=NULL;
		  tempX=tX;
		  tempY=tY;
		  zdolnoscRuchu=0;
          }
		 }
