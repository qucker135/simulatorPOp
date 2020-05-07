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


class Object{
	protected:
		bool zdolnoscRuchu;
	public:
	    int tempX;
	    int tempY;
	    virtual void ruch(Object*** plansza,const int N,int &tempX,int &tempY,int width,int heigh)=0;
		virtual bool getZdolnoscRuchu()=0;
		virtual void setZdolnoscRuchu(int a)=0;
		virtual string toString()=0;

};

class Chemiczne:public Object{};
class Mikroby:public Object{};
class Samozywne:public Mikroby{
    	protected:
		bool zdolnoscRuchu=1;
	public:
		virtual string toString(){return "S";}
	    int tempX;
	    int tempY;
	    bool getZdolnoscRuchu() {return zdolnoscRuchu;}
	    void setZdolnoscRuchu(int a) {zdolnoscRuchu=a;}


		virtual void ruch(Object*** plansza,const int N,int &tempX,int &tempY,int width,int heigh)
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
                     if(tY+1<heigh)
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
//          if(plansza[tX][tY]->toString()=="W") getH2O();
//          else if(plansza[tX][tY]->toString()=="D") getCO2();
          /*else*/{
		  plansza[tX][tY]=plansza[tempX][tempY];
		  plansza[tempX][tempY]=NULL;
		  tempX=tX;
		  tempY=tY;
		  zdolnoscRuchu=0;
          }
		 }

};
class Cudzozywne:public Mikroby{
protected:
		bool zdolnoscRuchu=1;
	public:
		virtual string toString(){return "C";}
	    int tempX;
	    int tempY;
	    bool getZdolnoscRuchu() {return zdolnoscRuchu;}
	    void setZdolnoscRuchu(int a) {zdolnoscRuchu=a;}
		virtual void ruch(Object*** plansza,const int N,int &tempX,int &tempY,int width,int heigh)
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
                     if(tX+1<width )
                     tX++;
                        break;
                 case 1:
                     if(tY+1<heigh)
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
          /*else*/{
		  plansza[tX][tY]=plansza[tempX][tempY];
		  plansza[tempX][tempY]=NULL;
		  tempX=tX;
		  tempY=tY;
		  zdolnoscRuchu=0;
          }
		 }
};
class Reducenci:public Mikroby{
protected:
		bool zdolnoscRuchu=1;
	public:
		virtual string toString(){return "R";}
	    int tempX;
	    int tempY;
	    bool getZdolnoscRuchu() {return zdolnoscRuchu;}
	    void setZdolnoscRuchu(int a) {zdolnoscRuchu=a;}
		virtual void ruch(Object*** plansza,const int N,int &tempX,int &tempY,int width,int heigh)
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
                     if(tX+1<heigh)
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
//          if(plansza[tX][tY]->toString()=="E") getEtanol();
//          else if(plansza[tX][tY]->toString()=="M") getMetan();
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
                        plansza[5][5]=new Samozywne();
                        //Proba uzycia konstruktora do zainicjalizowania pozycji (X,Y)
//                        plansza[5][5] = new Samozywne(5,5);
//                        cout << plansza[5][5]->tempX;
//                        getch();
                        plansza[5][5]->tempX=5;
                        plansza[5][5]->tempY=5;
                        plansza[1][2]=new Cudzozywne();
                        plansza[1][2]->tempX=1;
                        plansza[1][2]->tempY=2;

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
