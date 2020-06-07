#ifndef PLANSZA_H
#define PLANSZA_H
#include <iostream>
#include "object.h"
#include "pierwiastki.h"
#include "zwiazki.h"
#include "mikroby.h"

using namespace std;

class Plansza{
	enum class initSource {INIT_FROM_FILE, INIT_RANDOM};
	initSource source;
	int height;
	int width;
	Object*** plansza;
public:
	Plansza();
	~Plansza();
	void run();//runs a simulation
};

#endif
