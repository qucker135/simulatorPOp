#include<iostream>
#include <time.h>
#include <fstream>
#include <stdlib.h>
#include <conio.h>

using namespace std;
class Object;
Object*** plansza;
int height=10;
int width=10;


class Object
{
	protected:
		bool zdolnoscRuchu;
	public:
	    int tempX;
	    int tempY;
	    virtual void ruch(Object*** plansza,const int N,int &tempX,int &tempY,int width,int height)=0;
		virtual bool getZdolnoscRuchu()=0;
		virtual void setZdolnoscRuchu(int a)=0;
		virtual string toString()=0;
};

class Chemiczne:public Object{};

class Mikroby:public Object
{
	protected:
		int energia;
		int minimalna_energia_do_podzialu;
		
	public:
		int getEnergia();
		void zbierz();
		void przerob();
		void podziel();
		void skonaj();	
};

class Samozywne:public Mikroby
{
		int zebrane_H2O;
		int zebrane_CO2;
		int zatrucie;
		int maxymalne_zatrucie;
/////////////////////////////////////
    protected:
		bool zdolnoscRuchu=1;
	public:
		int getH2O(){return zebrane_H2O;}
		int getCO2(){return zebrane_CO2;}
		int getZatrucie(){return zatrucie;}
		int getMaxZatrucie(){return maxymalne_zatrucie;}
		void odtruj();
		Samozywne (int h2o, int co2, int zat) //konstruktor
		{
			zebrane_H2O=h2o;
			zebrane_CO2=co2;
			zatrucie=zat;
		};
/////////////////////////////////////		
		virtual string toString(){return "S";}
	    int tempX;
	    int tempY;
	    bool getZdolnoscRuchu() {return zdolnoscRuchu;}
	    void setZdolnoscRuchu(int a) {zdolnoscRuchu=a;}
		virtual void ruch(Object*** plansza,const int N,int &tempX,int &tempY,int width,int height)
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

};

class Cudzozywne:public Mikroby
{
		int zebrana_glukoza;
		int zebrany_tlen;
		int zatrucie;
		int maxymalne_zatrucie;
/////////////////////////////////////		
	protected:
		bool zdolnoscRuchu=1;
	public:
		virtual string toString(){return "U";}
	    int tempX;
	    int tempY;
	    bool getZdolnoscRuchu() {return zdolnoscRuchu;}
	    void setZdolnoscRuchu(int a) {zdolnoscRuchu=a;}
/////////////////////////////////////
		int getGlukoza(){return zebrana_glukoza;}
		int getTlen(){return zebrany_tlen;}
		int getZatrucie(){return zatrucie;}
		int getMaxZatrucie(){return maxymalne_zatrucie;}
		void odtruj();
		Cudzozywne(int glukoza, int tlen, int zat) //konstruktor
		{
			zebrana_glukoza=glukoza;
			zebrany_tlen=tlen;
			zatrucie=zat;	
		};
/////////////////////////////////////		
		virtual void ruch(Object*** plansza,const int N,int &tempX,int &tempY,int width,int height)
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
};

class Reducenci:public Mikroby
{
		int zebrany_etanol;
		int zebrany_metan;
/////////////////////////////////////		
	protected:
		bool zdolnoscRuchu=1;
	public:
		virtual string toString(){return "R";}
	    int tempX;
	    int tempY;
	    bool getZdolnoscRuchu() {return zdolnoscRuchu;}
	    void setZdolnoscRuchu(int a) {zdolnoscRuchu=a;}
/////////////////////////////////////	    
		int getEtanol(){return zebrany_etanol;}
		int getMetan(){return zebrany_metan;}
		Reducenci(int etanol, int metan) //konstruktor
		{
			zebrany_etanol=etanol;
			zebrany_metan=metan;	
		};
/////////////////////////////////////	
		virtual void ruch(Object*** plansza,const int N,int &tempX,int &tempY,int width,int height)
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
};

main(){
    srand(time(NULL));
                        plansza = new Object**[height];
                        for(int i=0;i<height;i++){
						plansza[i] = new Object*[width];
						for(int j=0;j<width;j++){
							plansza[i][j] = NULL;
                        }
                        }
                        plansza[5][5]=new Samozywne(0,0,0);
                        //Proba uzycia konstruktora do zainicjalizowania pozycji (X,Y)
//                        plansza[5][5] = new Samozywne(5,5);
//                        cout << plansza[5][5]->tempX;
//                        getch();
                        plansza[5][5]->tempX=5;
                        plansza[5][5]->tempY=5;
                        plansza[1][2]=new Cudzozywne(0,0,0);
                        plansza[1][2]->tempX=1;
                        plansza[1][2]->tempY=2;
                        
                        plansza[3][4]=new Reducenci(0,0);
                        plansza[3][4]->tempX=1;
                        plansza[3][4]->tempY=2;

                        for (int ii=0;ii<10;ii++)
                        {
                        for(int i=0;i<height;i++){
						for(int j=0;j<width;j++){
							if(!plansza[i][j]==NULL && plansza[i][j]->getZdolnoscRuchu()==1) plansza[i][j]->ruch(plansza,4,i,j,10,10);
						}
                        }
                        for(int i=0;i<height;i++){
						for(int j=0;j<width;j++){
							if(plansza[i][j]==NULL) cout<<" .";
							else cout<<" " << plansza[i][j]->toString() ;
						}
						cout << endl;
                        }
                        for(int i=0;i<height;i++){
						for(int j=0;j<width;j++){
							if(!plansza[i][j]==NULL ) plansza[i][j]->setZdolnoscRuchu(1);
						}
                        }
                       // getch();
                        cout << endl;
                        }
}
