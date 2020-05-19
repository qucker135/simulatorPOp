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
	int getEnergia();
	int getMinEnergia();
	virtual void zbierz()=0;
	virtual void przerob()=0;
	void podziel();
	void skonaj();
};

class Samozywne:public Mikroby{
	int zebrane_H2O;
	int zebrane_CO2;
	int zatrucie;
	const int MaxZatrucie;
public:
	Samozywne();
	virtual void zbierz();
	virtual void przerob();
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
	virtual void zbierz();
	virtual void przerob();
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
	virtual void zbierz();
	virtual void przerob();
	int getEtanol();
	int getMetan();
	virtual string toString();
};


#endif

