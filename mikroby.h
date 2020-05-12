#include <iostream>
#include <time.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

class Samozywne: public Mikroby
{
	int zebrane_H2O;
	int zebrane_CO2;
	int zatrucie;
	int maxymalne_zatrucie;

	public:
		int getH2O();
		int getCO2();
		int getZatrucie();
		int getMaxZatrucie();
		void odtruj();
//		Samozywne (int h2o, int co2, int zat);
        void ruch(Object*** plansza,const int N,int &tempX,int &tempY,int width,int height);
        string toString();
};

class Cudzozywne: public Mikroby
{
	int zebrana_glukoza;
	int zebrany_tlen;
	int zatrucie;
	int maxymalne_zatrucie;

	public:
		int getGlukoza();
		int getTlen();
		int getZatrucie();
		int getMaxZatrucie();
		void odtruj();
        void ruch(Object*** plansza,const int N,int &tempX,int &tempY,int width,int height);
        string toString();
};

class Reducenci: public Mikroby
{
	int zebrany_etanol;
	int zebrany_metan;

	public:
		int getEtanol();
		int getMetan();
		void ruch(Object*** plansza,const int N,int &tempX,int &tempY,int width,int height);
		string toString();
};
