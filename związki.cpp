
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <conio.h>


using namespace std;

class Object {
protected:
	bool zdolnoscRuchu;
public:
	int tempX;
	int tempY;
	virtual void ruch(Object*** plansza, const int N, int& tempX, int& tempY, int width, int heigh)=0;
	virtual bool getZdolnoscRuchu() = 0;
	virtual void setZdolnoscRuchu(int a) = 0;
	virtual string toString() = 0;
};

class Chemiczne : public Object {
protected:
	bool zdolnoscRuchu = 0;
};

class Zwiazki : public Chemiczne {
protected:
	bool czy_toksyczny;
public:
	bool getCzyToksyczny() {
		return czy_toksyczny;
	}
};

class Metan : public Zwiazki {
private:
	bool czy_toksyczny = 1;
	int toksycznosc = 1;//zalozmy, ze toksycznosc bedzie wynosila 1

public:
	virtual string toString() { return "M"; }
	int getToksycznosc() {
		return toksycznosc;
	}
};


class Etanol : public Zwiazki {
private:
	bool czy_toksyczny = 1;
	int toksycznosc = 2;//zalozmy, ze toksycznosc bedzie wynosila 2
public:
	virtual string toString() { return "E"; }
	int getToksycznosc() {
		return toksycznosc;
	}
};


class Woda : public Zwiazki {
private:
	bool czy_toksyczny = 0;
public:
	virtual string toString() { return "W"; }
};


class DwutlenekWegla : public Zwiazki {
private:
	bool czy_toksyczny = 0;
public:
	virtual string toString() { return "D"; }
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
		 }while(!plansza[tX][tY]==NULL );
          {
		  plansza[tX][tY]=plansza[tempX][tempY];
		  plansza[tempX][tempY]=NULL;
		  tempX=tX;
		  tempY=tY;
		  zdolnoscRuchu=0;
          }
		 }
};


class Glukoza : public Zwiazki {
private:
	bool czy_toksyczny = 0;
	int wartosc_odzywcza = 3;//zalozmy, ze wartosc odzywcza bedzie wynosila 3
public:
	virtual string toString() { return "G"; }
	int getWartoscOdzywcza() {
		return wartosc_odzywcza;
	}
};
