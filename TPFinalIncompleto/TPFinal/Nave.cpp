#include "Nave.h"

Nave::Nave(int x,int y,int vidas,int corazones){
	_x=x;
	_y=y;
	_vidas=vidas;
	_corazones=corazones;
}
Nave::~Nave(){
}
void Nave::dibujar(){
	borrar();
	gotoxy(_x,_y); 
	cout<<"  "<<(char)30;
	gotoxy(_x,_y+1);
	cout<<" "<<(char)40<<(char)206<<(char)41;
	gotoxy(_x,_y+2);
	cout<<(char)30<<(char)190<<" "<<(char)212<<(char)30;
}
void Nave::borrar(){
	gotoxy(_x,_y);  cout<<"     ";
	gotoxy(_x,_y+1);cout<<"     ";
	gotoxy(_x,_y+2);cout<<"     ";
}
void Nave::mover(){
}
void Nave::morir(){
	if(_corazones==0){
		borrar();
		gotoxy(_x,_y);  cout<<"  ** ";
		gotoxy(_x,_y+1);cout<<" ****";
		gotoxy(_x,_y+2);cout<<"  ** ";
		miliSleep(100);
		borrar();
		gotoxy(_x,_y);  cout<<"* * *";
		gotoxy(_x,_y+1);cout<<" *** ";
		gotoxy(_x,_y+2);cout<<"* * *";
		miliSleep(50);
		borrar();
		_vidas--;
		_corazones=3;
	}
}