class Mikroby
{
	protected:
		bool zdolnosc_ruchu;
		int energia;
		int minimalna_energia_do_podzialu;

	public:
		int getEnergia();
		void zbierz();
		void przerob();
		void podziel();
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
