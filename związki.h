
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <conio.h>


using namespace std;
class Object;
Object*** plansza;
//int height = 0, width = 0;

class Object {
protected:
	bool zdolnoscRuchu;
public:
	int tempX;
	int tempY;
	virtual void ruch(Object*** plansza, const int N, int& tempX, int& tempY, int width, int heigh);
	virtual bool getZdolnoscRuchu() ;
	virtual void setZdolnoscRuchu(int a) ;
	virtual string toString();
};

class Chemiczne : public Object {
protected:
	bool zdolnoscRuchu ;
};

class Zwiazki : public Chemiczne {
protected:
	bool czy_toksyczny;
public:
	bool getCzyToksyczny();
};

class Metan : public Zwiazki {
private:
	bool czy_toksyczny ;
	int toksycznosc ;

public:
	virtual string toString();
	int getToksycznosc()
};


class Etanol : public Zwiazki {
private:
	bool czy_toksyczny ;
	int toksycznosc ;
public:
	virtual string toString();
	int getToksycznosc()
	}
};


class Woda : public Zwiazki {
private:
	bool czy_toksyczny ;
public:
	virtual string toString() ;
};


class DwutlenekWegla : public Zwiazki {
private:
	bool czy_toksyczny ;
public:
	virtual string toString();
};


class Glukoza : public Zwiazki {
private:
	bool czy_toksyczny = 0;
	int wartosc_odzywcza = 3;
public:
	virtual string toString() ;
	int getWartoscOdzywcza();
};
