#include "Juego.h"

Juego::Juego(){
}
Juego::~Juego(){
	delete _nave;
	for (int i = 0; i < TOPE; i++){
		if (_vecAst[i]!= NULL){
			delete _vecAst[i];
			_vecAst[i] = NULL;
		}
	}
}
void Juego::init(){
	srand(time(0));
	_tecla=' ';
	_gameOver=false;
	_puntos=0;
	_resultado=false;
	_nave= new Nave(38,21,3,3);
	for(int i = 0; i < TOPE; i++){
		_vecAst[i] = NULL;
	}
	_vecAst[0] = new Asteroide(10,4);
	_vecAst[1] = new Asteroide(4,8);
	_vecAst[2] = new Asteroide(15,10);
}
void Juego::draw(){
	if(!_gameOver){
		display();
		for (int i = 0; i < TOPE; i++){
			if(_vecAst[i]!= NULL){
				_vecAst[i]->mover();
			}
		}
	}
}
void Juego::update(){
	draw();
	if(_tecla=getKey(true)){
		switch(_tecla){
		case KEY_UP:
			if(_nave->getY() >(MIN_FIL +2)){
				_nave->borrar();
				_nave->setY(_nave->getY()-1);
				_nave->dibujar();
			}
			break;
		case KEY_LEFT:
			if(_nave->getX()>(MIN_COL +1)){
				_nave->borrar();
				_nave->setX(_nave->getX()-1);
				_nave->dibujar();
			}
			break;
		case KEY_RIGHT:
			if((_nave->getX()+5)<(MAX_COL)){
				_nave->borrar();
				_nave->setX(_nave->getX()+1);
				_nave->dibujar();
			}
			break;
		case KEY_DOWN:
			if((_nave->getY()+3) <(MAX_FIL)){
				_nave->borrar();
				_nave->setY(_nave->getY()+1);
				_nave->dibujar();
			}
			break;
		case KEY_ESC:
			_gameOver = true;
			break;
		}
	}

	for(int i = 0; i<TOPE; i++){
		if(_vecAst[i] != NULL){
			_vecAst[i]->colision(_nave);
			_nave->morir();

		}
	}
	if(_puntos==PUNTOS){
		_resultado=true;
		_gameOver=true;
	}
	if((_nave->getVidas()==0)){
		_gameOver=true;
		_nave->morir();
	}
}
void Juego::input(){
	_tecla=' ';
	if(_tecla=getKey(false)){
		_nave->borrar();
		// completar
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
	gotoxy(55,1);
	cout<<"Asteroides:"<<Asteroide::getCantAsteroides()<<endl;
}