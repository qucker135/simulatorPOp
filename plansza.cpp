#include <iostream>
#include <fstream>
#include "plansza.h"

using namespace std;

void sleep(int milliseconds){
	clock_t start = clock();
	clock_t current;
	do{
		current = clock();
	}while((double)(current-start)/CLOCKS_PER_SEC * 1000.0 < milliseconds);
}

Plansza::Plansza(){
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
			//Stan domyslny, wykorzystany w destruktorze, oznacza, ze tworzenie tablicy sie nie powiodlo
			height = -1;
			
			string filename="";
			do{
				cout<<"Podaj nazwe pliku:"<<endl;
				cin>>filename;		
			}while(filename=="");

			if(filename.length()<4 || filename.substr(filename.length()-4,4)!=".txt") filename = filename + ".txt";

			ifstream file_read(filename);
			if(!file_read.is_open()){
				cerr<<"Nie znaleziono pliku o podanej nazwie!"<<endl;
			}

			//TEST
			//cout<<filename<<endl;

			else{
				try{
					string strBfr = "";
					getline(file_read,strBfr);
					this->height = stoi(strBfr);

					getline(file_read,strBfr);
					this->width = stoi(strBfr);

					this->plansza = new Object**[height];
					for(int i=0;i<height;i++){
						plansza[i] = new Object*[width];
						for(int j=0;j<width;j++){
							plansza[i][j] = NULL;
						}
					}

					for(int i=0;i<height && !file_read.eof();i++){
						getline(file_read,strBfr);
						for(int j=0;j<width && j<strBfr.length(); j++){
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

					//TEST
					/*cout<<height<<" "<<width<<endl;
					for(int i=0;i<height;i++){
						for(int j=0;j<width;j++){
							if(plansza[i][j]==NULL) cout<<".";
							else cout<<plansza[i][j]->toString();
						}
						cout<<"\n";
					}*/
				}
				catch(...){
					cerr<<"Nieprawidlowy format pliku wejsciowego!"<<endl;	
				}
			}	

		}

		else if(source == initSource::INIT_RANDOM){
			int bfri=0;
			do{
				cout<<"Podaj wysokosc planszy: ";
				cin>>bfri;
			}while(bfri<=0||bfri>100);
			this->height = bfri;
			do{
				cout<<"Podaj szerokosc planszy: ";
				cin>>bfri;
			}while(bfri<=0||bfri>100);
			this->width = bfri;
		
				try{
					this->plansza = new Object**[height];
					for(int i=0;i<height;i++){
						plansza[i] = new Object*[width];
						for(int j=0;j<width;j++){
							plansza[i][j] = NULL;
						}
					}



					for(int i=0;i<height;i++){
						for(int j=0;j<width; j++){
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
					
					//TEST
					/*cout<<height<<" "<<width<<endl;
					for(int i=0;i<height;i++){
						for(int j=0;j<width;j++){
							if(plansza[i][j]==NULL) cout<<".";
							else cout<<plansza[i][j]->toString();
						}
						cout<<"\n";
					}*/

				}
				catch(...){
					cerr<<"Blad wewnetrzny programu!"<<endl;	
				}

		
	
		}
}

Plansza::~Plansza(){
	if(height!=-1){//Jesli tworzenie tablicy sie nie powiodlo
		for(int i=0;i<height;i++){
			for(int j=0;j<width;j++)
			{
				if(plansza[i][j]!=NULL) delete plansza[i][j];	
			}
			delete[] plansza[i];
		}
		delete[] plansza;
	}
}
