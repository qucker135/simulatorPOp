#include <iostream>
#include <fstream>
#include <time.h>
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

void Plansza::run(){//w sumie nie musi argumentow, bo wszystko ma jako wlasne atrybuty
	char** dirs = new char* [height];
	for(int i=0; i<height; i++){
		dirs[i] = new char[width];	
	}


	fstream file_write;	
	file_write.open("output.csv", ios::out | ios::app);
	file_write<<"Wodor,Wegiel,Tlen,Metan,Etanol,Woda,Dwutlenek,Glukoza,Samozywne,Cudzozywne,Reducenci\n";
	file_write<<"H,C,O,M,E,W,D,G,S,U,R\n";
	file_write.close();

	

	double perc = 0.5;//czesc planszy zajeta przez obiekty
	do{

		

		//Sprawdzenie licznosci planszy, i wylosowanie kierunkow
		int covered = 0;//liczba niepustych pol planszy
		for(int i=0;i<height;i++){
			for(int j=0;j<width;j++){
				if(plansza[i][j]!=NULL){
					covered++;
				
					int random = rand()%4;
					switch(random){
						case 0:
							dirs[i][j] = 'w';
						break;
						case 1:
							dirs[i][j] = 'a';
						break;
						case 2:
							dirs[i][j] = 's';
						break;
						case 3:
							dirs[i][j] = 'd';
						break;
					} 
				}
				else dirs[i][j] = '.';
			}
		}

		//z tego miejsca nastepowac beda interakcje
		for(int i=0;i<height;i++){
			for(int j=0;j<width;j++){
				if(plansza[i][j]!=NULL && plansza[i][j]->getZdolnoscRuchu()){
					//rozne typy interakcji
					
					//syntezowanie(pierwiaski)
					if(plansza[i][j]->toString() == "H" || plansza[i][j]->toString() == "O"){
						try{
						((Pierwiastki*)plansza[i][j])->syntezuj(plansza,height,width,plansza[i][j]->getPos(plansza,height,width).first,plansza[i][j]->getPos(plansza,height,width).second,dirs[i][j]);	
						}
						catch(...){;}
					}

					//zbieranie(mikroby)
					if(plansza[i][j]->toString() == "S" || plansza[i][j]->toString() == "U" || plansza[i][j]->toString() == "R"){
						try{
						((Mikroby*)plansza[i][j])->zbierz(plansza,height,width,plansza[i][j]->getPos(plansza,height,width).first,plansza[i][j]->getPos(plansza,height,width).second,dirs[i][j]);	
						}
						catch(...){;}

					}

					//przerabianie materialu
					if(plansza[i][j]->toString() == "S" || plansza[i][j]->toString() == "U" || plansza[i][j]->toString() == "R"){
						try{
						((Mikroby*)plansza[i][j])->przerob();	
						}
						catch(...){;}

					}

					//podzial(mikroby)
					if(plansza[i][j]->toString() == "S" || plansza[i][j]->toString() == "U" || plansza[i][j]->toString() == "R"){
						int random = rand()%100;
						if(random==7){//mala szansa na podzial
							try{
							((Mikroby*)plansza[i][j])->podziel(plansza,height,width,plansza[i][j]->getPos(plansza,height,width).first,plansza[i][j]->getPos(plansza,height,width).second,dirs[i][j]);	
							}
							catch(...){;}
						}

					}

					

					//skonaj(mikroby)
					if(plansza[i][j]!=NULL && (plansza[i][j]->toString() == "S" || plansza[i][j]->toString() == "U" || plansza[i][j]->toString() == "R")){
						if(((Mikroby*)plansza[i][j])->getEnergia()<=0){
							try{
							((Mikroby*)plansza[i][j])->skonaj(plansza,height,width,plansza[i][j]->getPos(plansza,height,width).first,plansza[i][j]->getPos(plansza,height,width).second);	
							}
							catch(...){;}		
						}
						else if(plansza[i][j]->toString()=="S"){
							if(((Samozywne*)plansza[i][j])->getZatrucie() > ((Samozywne*)plansza[i][j])->getMaxZatrucie()){
								try{
								((Mikroby*)plansza[i][j])->skonaj(plansza,height,width,plansza[i][j]->getPos(plansza,height,width).first,plansza[i][j]->getPos(plansza,height,width).second);	
								}
								catch(...){;}
							}
						}
						else if(plansza[i][j]->toString()=="U"){
							if(((Cudzozywne*)plansza[i][j])->getZatrucie() > ((Cudzozywne*)plansza[i][j])->getMaxZatrucie()){
								try{
								((Mikroby*)plansza[i][j])->skonaj(plansza,height,width,plansza[i][j]->getPos(plansza,height,width).first,plansza[i][j]->getPos(plansza,height,width).second);	
								}
								catch(...){;}
							}
						}
					}

					
					//przemieszczanie + warunki na wyczerpywanie sie energii mikrobow
					if(i>0 && dirs[i][j] == 'w' && plansza[i-1][j] == NULL)
					{
						if(plansza[i][j]!=NULL && (plansza[i][j]->toString()=="S" || plansza[i][j]->toString()=="U" || plansza[i][j]->toString()=="R")){
							((Mikroby*)plansza[i][j])->zmniejszEnergie();	
							if(plansza[i][j]->toString()=="S"){
								((Samozywne*)plansza[i][j])->odtruj();		
							}
							else if(plansza[i][j]->toString()=="U"){
								((Cudzozywne*)plansza[i][j])->odtruj();		
							}	
						}
						plansza[i-1][j] = plansza[i][j];
						plansza[i][j] = NULL;
						
					}
					else if(j>0 && dirs[i][j] == 'a' && plansza[i][j-1] == NULL)
					{
						if(plansza[i][j]!=NULL && (plansza[i][j]->toString()=="S" || plansza[i][j]->toString()=="U" || plansza[i][j]->toString()=="R")){
							((Mikroby*)plansza[i][j])->zmniejszEnergie();
							if(plansza[i][j]->toString()=="S"){
								((Samozywne*)plansza[i][j])->odtruj();		
							}
							else if(plansza[i][j]->toString()=="U"){
								((Cudzozywne*)plansza[i][j])->odtruj();		
							}
						}
						plansza[i][j-1] = plansza[i][j];
						plansza[i][j] = NULL;
					}
					else if(i<height-1 && dirs[i][j] == 's' && plansza[i+1][j] == NULL)
					{
						if(plansza[i][j]!=NULL && (plansza[i][j]->toString()=="S" || plansza[i][j]->toString()=="U" || plansza[i][j]->toString()=="R")){
							((Mikroby*)plansza[i][j])->zmniejszEnergie();
							if(plansza[i][j]->toString()=="S"){
								((Samozywne*)plansza[i][j])->odtruj();		
							}
							else if(plansza[i][j]->toString()=="U"){
								((Cudzozywne*)plansza[i][j])->odtruj();		
							}
						}
						plansza[i+1][j] = plansza[i][j];
						plansza[i][j] = NULL;
					}
					else if(j<width-1 && dirs[i][j] == 'd' && plansza[i][j+1] == NULL)
					{
						if(plansza[i][j]!=NULL && (plansza[i][j]->toString()=="S" || plansza[i][j]->toString()=="U" || plansza[i][j]->toString()=="R")){
							((Mikroby*)plansza[i][j])->zmniejszEnergie();
							if(plansza[i][j]->toString()=="S"){
								((Samozywne*)plansza[i][j])->odtruj();		
							}
							else if(plansza[i][j]->toString()=="U"){
								((Cudzozywne*)plansza[i][j])->odtruj();		
							}
						}
						plansza[i][j+1] = plansza[i][j];
						plansza[i][j] = NULL;
					}
					
					

				}

			}
		}

		perc = (double)covered/(double)(height*width);
		
		//TEST
		cout<<perc<<endl;
		for(int i=0;i<height;i++){
			for(int j=0;j<width;j++){
				if(plansza[i][j] == NULL) cout<<".";
				else cout<<plansza[i][j]->toString();
			}
			cout<<"\n";
		}
		cout<<"\n";

		//zapis do pliku csv
		file_write.open("output.csv", ios::out | ios::app);
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
		//H=0;C=0;O=0;M=0;E=0;W=0;D=0;G=0;S=0;U=0;R=0;
		file_write.close();


		sleep(1000);

		

	}while(perc>0.2 && perc<0.8);

	cout<<"Gestosc materii spadla ponizej 0.2 lub wzrosla powyzej 0.8, KONIEC"<<endl;

	for(int i=0; i<height; i++){
		delete[] dirs[i];
	}
	delete[] dirs;
}
