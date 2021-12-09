#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <vector>
#include <string>

int funcionDado(int inicio, int fin);

char decisionJugador1();

void mostrarDatos(int rondaActual, int puntosJ1, int puntosJ2, int dadosStock1, int dadosStock2);

void numeroObjetivo(int objetivo);

void mostrarDados(int v[], int cant);

bool chequeoDados(int v[], int cant, int elegido);

bool eleccionDados();

void puntaje(int cant, int objetivo, int acuDado, int acuElegidos, int puntos);

#endif // FUNCIONES_H_INCLUDED
