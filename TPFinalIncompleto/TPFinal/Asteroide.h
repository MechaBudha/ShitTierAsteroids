#ifndef ASTEROIDE_H
#define ASTEROIDE_H

#include<iostream>
#include"../../Libreria/libreria.h"
#include"Nave.h"
#include "Definiciones.h"

using namespace std;
class Asteroide{
	int _x;
	int _y;
	// completar
public:
	Asteroide(int x, int y);
	~Asteroide();
	void dibujar();
	void borrar();
	void mover();
	void colision(Nave* nave);
	int getX(){ return _x;}
	int getY(){ return _y;}
	// completar
};
#endif