#ifndef ZWIAZKI_H
#define ZWIAZKI_H
#include <iostream>
#include <time.h>
#include <cstdlib>
//#include <conio.h>
#include "object.h"
#include "pierwiastki.h"

using namespace std;


class Zwiazki:public Chemiczne{};

class Metan:public Zwiazki{
private:
	bool czy_toksyczny ;
	int toksycznosc ;
public:
	virtual string toString();
	int getToksycznosc();
};


class Etanol:public Zwiazki {
private:
	bool czy_toksyczny ;
	int toksycznosc ;
public:
	virtual string toString();
	int getToksycznosc();

};


class Woda : public Zwiazki {
private:
	bool czy_toksyczny ;
public:
	virtual string toString() ;
};


class DwutlenekWegla : public Zwiazki {
private:
	bool czy_toksyczny ;
public:
	virtual string toString();
	void ruch(Object***,const int,int&,int&,int,int);
};


class Glukoza : public Zwiazki {
private:
	bool czy_toksyczny = 0;
	int wartosc_odzywcza = 3;
public:
	virtual string toString() ;
	int getWartoscOdzywcza();
};
#endif
