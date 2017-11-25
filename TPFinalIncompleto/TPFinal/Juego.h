#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../Libreria/libreria.h"
#include"Nave.h"
#include "Asteroide.h"
#include "Definiciones.h"
#define MIN_FIL 1
#define MIN_COL 1
#define MAX_FIL 24
#define MAX_COL 80
using namespace std;

class Juego{
	int _tecla;
	bool _gameOver;
	int _puntos;
	bool _resultado;
	Nave* _nave;
	Asteroide* _vecAst[TOPE];
public:
	Juego();
	~Juego();
	void init();
	bool gameOver();
	void play();
	void input();
	void update();
	void draw();
	void result();
	void display();
};
#endif