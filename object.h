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

#endif
