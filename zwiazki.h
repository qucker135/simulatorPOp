#ifndef ZWIAZKI_H
#define ZWIAZKI_H
#include <iostream>
#include "object.h"

class Zwiazki:public Object{
protected:
	bool czyToksyczny;
public:
	bool getCzyToksyczny();
	virtual string toString()=0;
};

class Metan:public Zwiazki{
	int toksycznosc;
public:
	Metan();
	int getToksycznosc();
	virtual string toString();
};

class Etanol:public Zwiazki{
	int toksycznosc;
public:
	Etanol();
	int getToksycznosc();
	virtual string toString();
};

class Woda:public Zwiazki{
public:
	Woda();
	virtual string toString();
};

class Dwutlenek:public Zwiazki{
public:
	Dwutlenek();
	virtual string toString();
};

class Glukoza:public Zwiazki{
	int wartoscOdzywcza;
public:
	Glukoza();
	int getWartoscOdzywcza();
	virtual string toString();
}; 

#endif
