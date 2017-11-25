#include"Asteroide.h"
#include "definiciones.h"
int Asteroide::_cantAsteroides=0; // definición del atributo estático

// contamos cuando se crea un objeto
Asteroide::Asteroide(int x,int y){
	_x=x;
	_y=y;
	_cantAsteroides++;
}
Asteroide::~Asteroide(){
	if(_cantAsteroides>0){
		_cantAsteroides--;
	}
}
int Asteroide::getCantAsteroides(){
	return _cantAsteroides;
}
void Asteroide::dibujar(){
	gotoxy(_x,_y);
	cout<<(char)ASTEROIDE;
}
void Asteroide::borrar(){
	gotoxy(_x,_y);
	cout<<" ";
}
void Asteroide::mover(){
	borrar();
	borrar();
	if (_y >= (MAX_Y -1)){
		_y = MIN_Y;
		_x = rand()%MAX_X-1;
		if(_x < 2){
			_x = 2;
		}
	} else{
		_y++;
	}
	dibujar();
}
void Asteroide::colision(Nave* nave){
	if(_x>=nave->getX() && _x<nave->getX()+ANCHO_NAVE &&
		_y>=nave->getY() && _y>=nave->getY()+2){
			nave->corazones();	
			_x=rand()%MAX_X-1;	
			if(_x<3)_x=4;
			_y=MIN_Y;
	}
}