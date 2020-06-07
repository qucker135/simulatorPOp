#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <utility>

using namespace std;

class Object{
protected:
	bool zdolnoscRuchu;
public:
	Object();
	bool getZdolnoscRuchu();
	virtual string toString()=0;
	std::pair<int,int> getPos(Object***,int,int);		
};

#endif
