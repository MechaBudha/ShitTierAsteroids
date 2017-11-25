#include "Juego.h"

Juego::Juego(){
}
Juego::~Juego(){
// completar
}
void Juego::init(){
	srand(time(0));
	_tecla=' ';
	_gameOver=false;
	_puntos=0;
	_resultado=false;
	_nave= new Nave(38,21,3,3);

	// completar
}
void Juego::draw(){
	if(!_gameOver){
		display();
		// completar	
	}
}
void Juego::update(){


	// completar


	if(_puntos==PUNTOS){
		_resultado=true;
		_gameOver=true;
	}
	if((_nave->getVidas()==0))	
		_gameOver=true;
	_nave->morir();
}
void Juego::input(){
	_tecla=' ';
	if(_tecla=getKey(false)){
		_nave->borrar();
		// completar
		}
	}
}
void Juego::play(){
	init();
	hideCursor();
	marco(1,2,80,24);
	display();
	_nave->dibujar();
	while(!gameOver()){
		input();
		update();
		draw();
		miliSleep(55);
	}
	result();
}
void Juego::result(){
	if(_gameOver){
		gotoxy(35,12);
		cout<<"Game Over";
	}
}
bool Juego::gameOver(){
	return _gameOver;
}
void Juego::display(){
	gotoxy(2,1);cout<<"Vidas "<<_nave->getVidas()<<" ";
	gotoxy(11,1);cout<<"Salud ";
	gotoxy(17,1);cout<<"        ";
	int c=_nave->getCorazones();
	for(int i=0;i<c;i++){
		gotoxy(17+i,1);
		cout<<(char)CORAZON;
	}
}