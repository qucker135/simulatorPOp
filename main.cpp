#include <iostream>
#include <time.h>
#include <fstream>
#include <stdlib.h>
#include "object.h"
//#ifndef AUX_H
//#include "aux.h"
//#endif

using namespace std;

class Object;
class Init;

Object*** plansza;
int height=0;
int width=0;

void sleep(int milliseconds){
	clock_t start = clock();
	clock_t current;
	do{
		current = clock();
	}while((double)(current-start)/CLOCKS_PER_SEC * 1000.0 < milliseconds);
}

/*class Object{
	protected:
		bool zdolnoscRuchu;
	public:
		//virtual bool getZdolnoscRuchu()=0;
		virtual string toString()=0;
		bool getZdolnoscRuchu(){ return zdolnoscRuchu;}
};*/ 

class Chemiczne:public Object{};
class Pierwiastek:public Chemiczne{};
class Wodor:public Pierwiastek{
	public:
		virtual string toString(){return "H";}
};
class Wegiel:public Pierwiastek{
	public:
		virtual string toString(){return "C";}
};
class Tlen:public Pierwiastek{
	public:
		virtual string toString(){return "O";}
};
class Zwiazki:public Chemiczne{};
class Metan:public Zwiazki{
	public:
		virtual string toString(){return "M";}
};
class Etanol:public Zwiazki{
	public:
		virtual string toString(){return "E";}
};
class Woda:public Zwiazki{
	public:
		virtual string toString(){return "W";}
};
class Dwutlenek:public Zwiazki{
	public:
		virtual string toString(){return "D";}
};
class Glukoza:public Zwiazki{
	public:
		virtual string toString(){return "G";}
};
class Mikroby:public Object{};
class Samozywne:public Mikroby{
	public:
		virtual string toString(){return "S";}
};
class Cudzozywne:public Mikroby{
	public:
		virtual string toString(){return "U";}
};
class Reducenci:public Mikroby{
	public: 
		virtual string toString(){return "R";}
};

class Init{
	public:
	enum class initSource {INIT_FROM_FILE, INIT_RANDOM};
	static void initChoice(Object*** plansza, int& g_height, int& g_width){
		cout<<"  __  __ _ _              _           \n";
		cout<<" |  \\/  (_) |            | |          \n";
		cout<<" | \\  / |_| | ___ __ ___ | |__  _   _ \n";
		cout<<" | |\\/| | | |/ / '__/ _ \\| '_ \\| | | |\n";
		cout<<" | |  | | |   <| | | (_) | |_) | |_| |\n";
		cout<<" |_|  |_|_|_|\\_\\_|  \\___/|_.__/ \\__, |\n";
		cout<<"                                 __/ |\n";
		cout<<"                               |___/ \n";
		cout<<" v. 1.0"<<endl;
		cout<<endl;
		sleep(1000);
		
		cout<<"Wybierz opcje inicjalizacji stanu poczatkowego: "<<endl;
		cout<<"[1] - Stan poczatkowy wczytany z pliku\n";
		cout<<"[2] - Stan poczatkowy wylosowany\n";
		int bfr=0;
		do{cin>>bfr;} while(bfr!=1 && bfr!=2);
		switch(bfr){
			case 1:
				source = initSource::INIT_FROM_FILE;
			break;
			case 2:
				source = initSource::INIT_RANDOM;
			break;
		}
		
		if(source == initSource::INIT_FROM_FILE){
			string filename="";
			do{
				cout<<"Podaj nazwe pliku:"<<endl;
				cin>>filename;		
			}while(filename=="");

			if(filename.length()<4 || filename.substr(filename.length()-4,4)!=".txt") filename = filename + ".txt";

			ifstream file_read(filename);
			if(!file_read.is_open()){
				cout<<"Nie znaleziono pliku o podanej nazwie!"<<endl;
			}
			else{
				try{
					string strBfr = "";
					getline(file_read,strBfr);
					g_height = stoi(strBfr);

					getline(file_read,strBfr);
					g_width = stoi(strBfr);

					//cout<<height<<" "<<width<<endl;	

					plansza = new Object**[g_height];
					for(int i=0;i<g_height;i++){
						plansza[i] = new Object*[g_width];
						for(int j=0;j<g_width;j++){
							plansza[i][j] = NULL;
						}
					}



					for(int i=0;i<g_height && !file_read.eof();i++){
					//while(!file_read.eof()){
						getline(file_read,strBfr);
						for(int j=0;j<g_width && j<strBfr.length(); j++){
							switch(strBfr[j]){
								//Wodór - H
								//Węgiel -C
								//Tlen -- O
								//Metan - M
								//Etanol- E
								//Woda -- W
								//CO2 --- D
								//Glukoza G
								//Samoż.- S
								//Cudzoż. U
								//Reduc.  R


								case 'H':
								case 'h':
									plansza[i][j] = new Wodor();
								break;
								case 'C':
								case 'c':
									plansza[i][j] = new Wegiel();
								break;
								case 'O':
								case 'o':
									plansza[i][j] = new Tlen();
								break;
								case 'M':
								case 'm':
									plansza[i][j] = new Metan();
								break;
								case 'E':
								case 'e':
									plansza[i][j] = new Etanol();
								break;
								case 'W':
								case 'w':
									plansza[i][j] = new Woda();
								break;
								case 'D':
								case 'd':
									plansza[i][j] = new Dwutlenek();
								break;
								case 'G':
								case 'g':
									plansza[i][j] = new Glukoza();
								break;
								case 'S':
								case 's':
									plansza[i][j] = new Samozywne();
								break;
								case 'U':
								case 'u':
									plansza[i][j] = new Cudzozywne();
								break;
								case 'R':
								case 'r':
									plansza[i][j] = new Reducenci();
								break;	
							}	
						}	
					}
					//
					
					for(int i=0;i<g_height;i++){
						for(int j=0;j<g_width;j++){
							if(plansza[i][j]==NULL) cout<<".";
							else cout<<plansza[i][j]->toString();
						}
						cout<<"\n";
					}

				}
				catch(...){
					cout<<"Nieprawidlowy format pliku wejsciowego!"<<endl;	
				}

			}				
		}
		else if(source == initSource::INIT_RANDOM){
			int bfr=0;
			do{
				cout<<"Podaj wysokosc planszy: ";
				cin>>bfr;
			}while(bfr<=0||bfr>100);
			g_height = bfr;
			do{
				cout<<"Podaj szerokosc planszy: ";
				cin>>bfr;
			}while(bfr<=0||bfr>100);
			g_width = bfr;
		
				try{
					plansza = new Object**[g_height];
					for(int i=0;i<g_height;i++){
						plansza[i] = new Object*[g_width];
						for(int j=0;j<g_width;j++){
							plansza[i][j] = NULL;
						}
					}



					for(int i=0;i<g_height;i++){
					//while(!file_read.eof()){
						//getline(file_read,strBfr);
						for(int j=0;j<g_width; j++){
								//Wodór - H
								//Węgiel -C
								//Tlen -- O
								//Metan - M
								//Etanol- E
								//Woda -- W
								//CO2 --- D
								//Glukoza G
								//Samoż.- S
								//Cudzoż. U
								//Reduc.  R
							int randomness = rand()%1024;

							if(randomness>=512 && randomness<=586){//range 75
								plansza[i][j] = new Wodor();	
							}
							else if(randomness>=587 && randomness<=661){//range 75
								plansza[i][j] = new Wegiel();
							}
							else if(randomness>=662 && randomness<=736){//range 75
								plansza[i][j] = new Tlen();		
							}
							else if(randomness>=737 && randomness<=786){//range 50
								plansza[i][j] = new Metan();
							}
							else if(randomness>=787 && randomness<=836){//range 50
								plansza[i][j] = new Etanol();	
							}
							else if(randomness>=837 && randomness<=886){//range 50
								plansza[i][j] = new Woda();
							}
							else if(randomness>=887 && randomness<=936){//range 50
								plansza[i][j] = new Dwutlenek();
							}
							else if(randomness>=937 && randomness<=986){//range 50
								plansza[i][j] = new Glukoza();
							}
							else if(randomness>=987 && randomness<=1000){
								plansza[i][j] = new Reducenci();
							}
							else if(randomness>=1001 && randomness<=1012){
								plansza[i][j] = new Samozywne();
							}
							else if(randomness>=1013 && randomness<=1024){
								plansza[i][j] = new Cudzozywne();
							}
						
						}	
					}
					
					//Wypisz zawartosc planszy
					/*for(int i=0;i<g_height;i++){
						for(int j=0;j<g_width;j++){
							if(plansza[i][j]==NULL) cout<<".";
							else cout<<plansza[i][j]->toString();
						}
						cout<<"\n";
					}*/

				}
				catch(...){
					cout<<"Blad wewnetrzny programu!"<<endl;	
				}

		
		}


	}
	private:
	static initSource source;
	//static int height;
	//static int width;
};

Init::initSource Init::source;
//int Init::height;
//int Init::width;

//Wodór - H
//Węgiel -C
//Tlen -- O
//Metan - M
//Etanol- E
//Woda -- W
//CO2 --- D
//Glukoza G
//Samoż.- S
//Cudzoż. U
//Reduc.  R

class CSVWriter{
	static void write(string filename,Object*** plansza,int height,int width){
		if(filename.length()<4 || filename.substr(filename.length()-4,4)!=".csv") filename = filename + ".csv";	
		ofstream file_write(filename);
		file_write<<"Wodor,Wegiel,Tlen,Metan,Etanol,Woda,Dwutlenek,Glukoza,Samozywne,Cudzozywne,Reducenci\n";
		file_write<<"H,C,O,M,E,W,D,G,S,U,R\n";
		int H=0,C=0,O=0,M=0,E=0,W=0,D=0,G=0,S=0,U=0,R=0;	
		
		for(int i=0;i<height;i++){
			for(int j=0;j<width;j++){
				if(plansza[i][j]!=NULL){
					string type = plansza[i][j]->toString();
					switch(type[0]){
						case 'H':
							H++; break;
						case 'C':
							C++; break;
						case 'O':
							O++; break;
						case 'M':
							M++; break;
						case 'E':
							E++; break;
						case 'W':
							W++; break;
						case 'D':
							D++; break;
						case 'G':
							G++; break;
						case 'S':
							S++; break;
						case 'U':
							U++; break;
						case 'R':
							R++; break;

					}
				}
			}
		}
		file_write<<H<<","<<C<<","<<O<<","<<M<<","<<E<<","<<W<<","<<D<<","<<G<<","<<S<<","<<U<<","<<R<<"\n";
	}
};

int main(){

	srand(time(NULL));
	Init::initChoice(plansza,height,width);

	//Zakomentowane, gdyz powoduje Segmentation fault: core dumped
	/*try{
		for(int i=0;i<height;i++){
			for(int j=0;j<width;j++){
				cout<<i<<" "<<j<<endl;
				//if(plansza[i][j]!=NULL) {delete plansza[i][j];}
			}
			delete[] plansza[i];
		}
		delete[] plansza;
	}
	catch(...){
		cout<<"Holy crap"<<endl;	
	}*/

	return 0;
}
