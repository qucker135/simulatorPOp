
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <conio.h>
#include "object.h"
#include "pierwiastki.h"
#include "zwiazki.h"
#include"mikroby.h"


//class Object {
//protected:
//	bool zdolnoscRuchu;
//public:
//	int tempX;
//	int tempY;
//	virtual void ruch(Object*** plansza, const int N, int& tempX, int& tempY, int width, int heigh)=0;
//	virtual bool getZdolnoscRuchu() = 0;
//	virtual void setZdolnoscRuchu(int a) = 0;
//	virtual string toString() = 0;
//};






     string Metan ::toString()
    {
        return "M";
    }
    int Metan ::getToksycznosc()
    {
        return toksycznosc;
    }



     string Etanol ::toString()
    {
        return "E";
    }
    int Etanol ::getToksycznosc()
    {
        return toksycznosc;
    }

     string Woda ::toString()
    {
        return "W";
    }




     string DwutlenekWegla ::toString()
    {
        return "D";
    }
     void DwutlenekWegla ::ruch(Object*** plansza,const int N,int &tempX,int &tempY,int width,int heigh)
    {
        int tX;
        int tY;
        do
        {
            tX=tempX;
            tY=tempY;

            for (int i=0; i<N; i++)
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
        }
        while(!plansza[tX][tY]==NULL );
        {
            plansza[tX][tY]=plansza[tempX][tempY];
            plansza[tempX][tempY]=NULL;
            tempX=tX;
            tempY=tY;
            zdolnoscRuchu=0;
        }
    }




     string Glukoza ::toString()
    {
        return "G";
    }
    int Glukoza ::getWartoscOdzywcza()
    {
        return wartosc_odzywcza;
    }

