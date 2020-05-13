#ifndef PIERWIASTKI_H
#define PIERWIASTKI_H
#include <iostream>
#include <time.h>
#include <fstream>
#include <stdlib.h>

#include "object.h"

//#include <conio.h>
using namespace std;


class Chemiczne:public Object{};
class Pierwiastek:public Chemiczne{};

class Wodor:public Pierwiastek{
	public:
	    int zdolnoscRuchu =1;
		virtual string toString();
		 void ruch(Object***,const int,int&,int&,int,int);
};
class Wegiel:public Pierwiastek{
	public:
		virtual string toString();
};
class Tlen:public Pierwiastek{
	public:
	    int zdolnoscRuchu =1;
		virtual string toString();
		virtual void ruch(Object***,const int,int&,int&,int,int);
};
#endif
