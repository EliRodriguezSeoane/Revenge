#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <vector>
#include <string.h>

int menu();

int salida();

int funcionDado(int inicio, int fin);

char decisionJugador1();

void mostrarDatos(int rondaActual, int puntosJ1, int puntosJ2, int dadosStock1, int dadosStock2);

int numeroObjetivo(int objetivo);

void mostrarDados(int v[], int cant);

bool chequeoDados(int v[], int cant, int elegido/*, bool eleccion*/);

bool eleccionDados(int acuDado, int objetivo);

int puntaje(int cant, int objetivo, int acuDado, int acuElegidos, int puntos, bool bono);

void regresoMenu ();

void creditos ();

#endif
