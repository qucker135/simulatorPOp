#include<iostream>
#include<iostream>
#include <time.h>
#include <fstream>
#include <stdlib.h>
//#include <conio.h>
#include "object.h"
#include "pierwiastki.h"
#include "zwiazki.h"
#include "mikroby.h"
using namespace std;


		 string Wodor :: toString(){return "H";}
		 void Wodor :: ruch(Object*** plansza,const int N,int &tempX,int &tempY,int width,int heigh)
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
		 }while(!plansza[tX][tY]==NULL && plansza[tX][tY]->toString()!="O");
//          if(plansza[tX][tY]->toString()=="E") Syntezuj();
//
          /*else*/{
		  plansza[tX][tY]=plansza[tempX][tempY];
		  plansza[tempX][tempY]=NULL;
		  tempX=tX;
		  tempY=tY;
		  zdolnoscRuchu=0;
          }
		 }


		 string Wegiel :: toString(){return "C";}

		 string Tlen :: toString(){return "O";}
		 void Tlen :: ruch(Object*** plansza,const int N,int &tempX,int &tempY,int width,int heigh)
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
		 }while(!plansza[tX][tY]==NULL && plansza[tX][tY]->toString()!="H" );
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


