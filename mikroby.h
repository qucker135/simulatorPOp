#ifndef MIKROBY_H
#define MIKROBY_H
#include <iostream>
#include "object.h"

class Mikroby:public Object{
protected:
	int energia;
	const int MinEnergiaDoPodzialu;
public:
	Mikroby();
	Mikroby(int);
	int getEnergia();
	int getMinEnergia();
	virtual void zbierz(Object***,int,int,int,int,char)=0;
	virtual void przerob()=0;
	virtual void podziel(Object***,int,int,int,int,char)=0;
	void skonaj(Object***,int,int,int,int);
};

class Samozywne:public Mikroby{
	int zebrane_H2O;
	int zebrane_CO2;
	int zatrucie;
	const int MaxZatrucie;
public:
	Samozywne();
	Samozywne(int,int,int,int,int,int);
	virtual void zbierz(Object***,int,int,int,int,char);
	virtual void przerob();
	virtual void podziel(Object***,int,int,int,int,char);
	int getH2O();
	int getCO2();
	int getZatrucie();
	int getMaxZatrucie();
	void odtruj();
	virtual string toString();
};

class Cudzozywne:public Mikroby{
	int zebrana_glukoza;
	int zebrany_tlen;
	int zatrucie;
	const int MaxZatrucie;
public:
	Cudzozywne();
	Cudzozywne(int,int,int,int,int,int);
	virtual void zbierz(Object***,int,int,int,int,char);
	virtual void przerob();
	virtual void podziel(Object***,int,int,int,int,char);
	int getGlukoza();
	int getTlen();
	int getZatrucie();
	int getMaxZatrucie();
	void odtruj();
	virtual string toString();
};

class Reducenci:public Mikroby{
	int zebrany_etanol;
	int zebrany_metan;
public:
	Reducenci();
	Reducenci(int,int,int,int);
	virtual void zbierz(Object***,int,int,int,int,char);
	virtual void przerob();
	virtual void podziel(Object***,int,int,int,int,char);
	int getEtanol();
	int getMetan();
	virtual string toString();
};


#endif

