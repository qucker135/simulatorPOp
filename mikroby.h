#include<iostream>

using namespace std;

class Mikroby
{
protected:
    bool zdolnosc_ruchu;
    int energia;
    int min_energia_podzialu;
    int energia_p;
    int polee;
    int pozywienie;
    int trucizna;
    int zebrane_H20;
    int zebrane_CO2;
    int zebrana_glukoza;
    int zebrany_tlen;
    int zebrany_etanol;
    int zebrany_metanol;
    int organizm;
public:
    Mikroby(int energia, int energia_p, int min_energia_podzialu);
    ~Mikroby();
    int get_energia(int polee);
    void zbierz(int pozywienie, int trucizna);
    void przerob();
    void podziel(int x);
    void skonaj();
};

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

};

class Reducenci: public Mikroby
{
	int zebrany_etanol;
	int zebrany_metan;

	public:
		int getEtanol();
		int getMetan();
};


void nieZnika(int x, int y);
