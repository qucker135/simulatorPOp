#ifndef PIERWIASTKI_H
#define PIERWIASTKI_H
#include <iostream>
#include "object.h"

class Pierwiastki:public Object{
public:
	virtual string toString()=0;
	virtual void syntezuj()=0;
};

class Wodor:public Pierwiastki{
public:
	virtual string toString();
	virtual void syntezuj();
	Wodor();
};
class Wegiel:public Pierwiastki{
public:
	virtual string toString();
	virtual void syntezuj();
	Wegiel();
};
class Tlen:public Pierwiastki{
public:
	virtual string toString();
	virtual void syntezuj();
	Tlen();
};



#endif
