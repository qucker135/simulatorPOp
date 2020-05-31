#include <iostream>
#include "object.h"
#include "zwiazki.h"
#include "pierwiastki.h"

using namespace std;

Wodor::Wodor(){
	zdolnoscRuchu = true; //Wodor porusza sie
}

string Wodor::toString(){return "H";}

void Wodor::syntezuj(Object*** plansza,int height,int width,int curX,int curY,char direction){
	switch(direction){
		case 'w':
			if(curX-1>=0){
				if(plansza[curX-1][curY]!=NULL && plansza[curX-1][curY]->toString()=="C"){
					delete plansza[curX-1][curY];
					plansza[curX-1][curY] = NULL;
					delete plansza[curX][curY];
					plansza[curX][curY];
					plansza[curX][curY] = new Metan();
				}
				else if(plansza[curX-1][curY]!=NULL && plansza[curX-1][curY]->toString()=="O"){
					delete plansza[curX-1][curY];
					plansza[curX-1][curY] = NULL;
					delete plansza[curX][curY];
					plansza[curX][curY];
					plansza[curX][curY] = new Woda();	
				}
			}
		break;
		case 'a':
			if(curY-1>=0){
				if(plansza[curX][curY-1]!=NULL && plansza[curX][curY-1]->toString()=="C"){
					delete plansza[curX][curY-1];
					plansza[curX][curY-1] = NULL;
					delete plansza[curX][curY];
					plansza[curX][curY];
					plansza[curX][curY] = new Metan();
				}
				if(plansza[curX][curY-1]!=NULL && plansza[curX][curY-1]->toString()=="O"){
					delete plansza[curX][curY-1];
					plansza[curX][curY-1] = NULL;
					delete plansza[curX][curY];
					plansza[curX][curY];
					plansza[curX][curY] = new Woda();
				}
			}

		break;
		case 's':
			if(curX+1<height){
				if(plansza[curX+1][curY]!=NULL && plansza[curX+1][curY]->toString()=="C"){
					delete plansza[curX+1][curY];
					plansza[curX+1][curY] = NULL;
					delete plansza[curX][curY];
					plansza[curX][curY];
					plansza[curX][curY] = new Metan();
				}
				if(plansza[curX+1][curY]!=NULL && plansza[curX+1][curY]->toString()=="O"){
					delete plansza[curX+1][curY];
					plansza[curX+1][curY] = NULL;
					delete plansza[curX][curY];
					plansza[curX][curY];
					plansza[curX][curY] = new Woda();
				}
			}
		break;
		case 'd':
			if(curY+1<width){
				if(plansza[curX][curY+1]!=NULL && plansza[curX][curY+1]->toString()=="C"){
					delete plansza[curX][curY+1];
					plansza[curX][curY+1] = NULL;
					delete plansza[curX][curY];
					plansza[curX][curY];
					plansza[curX][curY] = new Metan();
				}
				if(plansza[curX][curY+1]!=NULL && plansza[curX][curY+1]->toString()=="O"){
					delete plansza[curX][curY+1];
					plansza[curX][curY+1] = NULL;
					delete plansza[curX][curY];
					plansza[curX][curY];
					plansza[curX][curY] = new Woda();
				}
			}
		break;
	}
}

Wegiel::Wegiel(){
	zdolnoscRuchu = false; //Wegiel nie porusza sie
}

string Wegiel::toString(){return "C";}

void Wegiel::syntezuj(Object***,int,int,int,int,char){//jakie argumenty? Object*** plansza,height,width,curX,curY,direction
	;//;
}

Tlen::Tlen(){
	zdolnoscRuchu = true; //Tlen porusza sie
}

string Tlen::toString(){return "O";}

void Tlen::syntezuj(Object*** plansza,int height,int width,int curX,int curY,char direction){//jakie argumenty? Object*** plansza,height,width,curX,curY,direction
	switch(direction){
		case 'w':
			if(curX-1>=0){
				if(plansza[curX-1][curY]!=NULL && plansza[curX-1][curY]->toString()=="C"){
					delete plansza[curX-1][curY];
					plansza[curX-1][curY] = NULL;
					delete plansza[curX][curY];
					plansza[curX][curY];
					plansza[curX][curY] = new Dwutlenek();
				}
				else if(plansza[curX-1][curY]!=NULL && plansza[curX-1][curY]->toString()=="H"){
					delete plansza[curX-1][curY];
					plansza[curX-1][curY] = NULL;
					delete plansza[curX][curY];
					plansza[curX][curY];
					plansza[curX][curY] = new Woda();	
				}
			}
		break;
		case 'a':
			if(curY-1>=0){
				if(plansza[curX][curY-1]!=NULL && plansza[curX][curY-1]->toString()=="C"){
					delete plansza[curX][curY-1];
					plansza[curX][curY-1] = NULL;
					delete plansza[curX][curY];
					plansza[curX][curY];
					plansza[curX][curY] = new Dwutlenek();
				}
				if(plansza[curX][curY-1]!=NULL && plansza[curX][curY-1]->toString()=="H"){
					delete plansza[curX][curY-1];
					plansza[curX][curY-1] = NULL;
					delete plansza[curX][curY];
					plansza[curX][curY];
					plansza[curX][curY] = new Woda();
				}
			}

		break;
		case 's':
			if(curX+1<height){
				if(plansza[curX+1][curY]!=NULL && plansza[curX+1][curY]->toString()=="C"){
					delete plansza[curX+1][curY];
					plansza[curX+1][curY] = NULL;
					delete plansza[curX][curY];
					plansza[curX][curY];
					plansza[curX][curY] = new Dwutlenek();
				}
				if(plansza[curX+1][curY]!=NULL && plansza[curX+1][curY]->toString()=="H"){
					delete plansza[curX+1][curY];
					plansza[curX+1][curY] = NULL;
					delete plansza[curX][curY];
					plansza[curX][curY];
					plansza[curX][curY] = new Woda();
				}
			}
		break;
		case 'd':
			if(curY+1<width){
				if(plansza[curX][curY+1]!=NULL && plansza[curX][curY+1]->toString()=="C"){
					delete plansza[curX][curY+1];
					plansza[curX][curY+1] = NULL;
					delete plansza[curX][curY];
					plansza[curX][curY];
					plansza[curX][curY] = new Dwutlenek();
				}
				if(plansza[curX][curY+1]!=NULL && plansza[curX][curY+1]->toString()=="H"){
					delete plansza[curX][curY+1];
					plansza[curX][curY+1] = NULL;
					delete plansza[curX][curY];
					plansza[curX][curY];
					plansza[curX][curY] = new Woda();
				}
			}
		break;
	}

}
