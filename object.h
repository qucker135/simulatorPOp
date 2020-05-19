#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>

using namespace std;

class Object{
protected:
	bool zdolnoscRuchu;
public:
	Object();
	bool getZdolnoscRuchu();
	virtual string toString()=0;
};

#endif
