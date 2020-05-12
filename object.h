#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>

using namespace std;

class Object{
	protected:
		bool zdolnoscRuchu;
	public:
		//virtual bool getZdolnoscRuchu()=0;
		virtual string toString()=0;
		bool getZdolnoscRuchu();
};
class Chemiczne:public Object{};
class Pierwiastek:public Chemiczne{};
class Zwiazki:public Chemiczne{};
class Mikroby:public Object
{
	protected:
		bool zdolnosc_ruchu;
		int energia;
		int minimalna_energia_do_podzialu;

	public:
//		virtual int getEnergia()=0;
//		virtual void zbierz()=0;
//		virtual void przerob()=0;
//		virtual void podziel()=0;
//		virtual void skonaj()=0;
		virtual string toString()=0;
};
#endif
