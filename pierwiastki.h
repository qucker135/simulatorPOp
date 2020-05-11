#include<iostream>
#include<iostream>
#include <time.h>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

class Object{
	//protected:
	//	bool zdolnoscRuchu;
	public:
		//virtual bool getZdolnoscRuchu()=0;
		virtual string toString()=0;
};

class Chemiczne:public Object{};
class Pierwiastek:public Chemiczne{};
class Wodor:public Pierwiastek{
	public:
		virtual string toString(){return "H";}
		virtual void ruch(Object***,const int,int,int,int,int);
};
class Wegiel:public Pierwiastek{
	public:
		virtual string toString();
};
class Tlen:public Pierwiastek{
	public:
		virtual string toString();
		virtual void ruch(Object***,const int,int,int,int,int);
};

