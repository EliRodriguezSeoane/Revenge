#include <iostream>
#include <cstdlib>
#include <ctime>

#include "funciones.h"
using namespace std;

int main(){
    int rondaActual = 1;
    const int RONDAS = 2;

    int objetivo, puntosJ1, puntosJ2, puntosMax, dadosStock1, dadosStock2, acuDado, acuElegidos, dadoElegido, menuEleccion, volver;
    objetivo = puntosJ1 = puntosJ2 = puntosMax = 0;
    dadosStock1 = dadosStock2 = 6;
    string jugadorA, jugadorB, jugador1, jugador2, jugadorMax;
    char ganador;
    bool eleccion, chequeo;

    srand(time(NULL));

    menuEleccion = menu();

    if (menuEleccion==0){return 0;}
    if (menuEleccion==1){/// Acceso a jugar
        cout << "Nombre del jugador: ";
        cin >> jugadorA;
        cout << "Nombre del jugador: ";
        cin >> jugadorB;
        cout << "--------------------------------------------------------" << endl << endl;
        ganador = decisionJugador1();

        if (ganador=='A'){
            cout << "Gana " << jugadorA << endl;
            jugador1 = jugadorA;
            jugador2 = jugadorB;}
        else {cout << "Gana " << jugadorB << endl;
            jugador1 = jugadorB;
            jugador2 = jugadorA;}

        cout << "El jugador 1 es: " << jugador1 << endl;
        cout << "El jugador 2 es: " << jugador2 << endl << endl;
        cout << "--------------------------------------------------------" << endl << endl;

        /// Rondas 5 o hasta que dados stock sean 0
        while (rondaActual <= RONDAS && dadosStock1 != 0 && dadosStock2 != 0){
            mostrarDatos(rondaActual, puntosJ1, puntosJ2, dadosStock1, dadosStock2);
            cout << "--------------------------------------------------------" << endl << endl;

        /// Jugada de ronda del jugador 1
            cout << "Juega el jugador 1: " << jugador1 << endl;
            int objetivo;
            objetivo = numeroObjetivo(objetivo);
            cout << "--------------------------------------------------------" << endl << endl;
            int vDadosStock1[dadosStock1];
            cout << "Tirada de dados: " << endl;
            mostrarDados(vDadosStock1, dadosStock1);
            cout << endl << "--------------------------------------------------------" << endl << endl;

        /// Preguntar a jugador que dado selecciona o jugador pone 0 para terminar la ronda asi
            acuDado = acuElegidos = dadoElegido = 0;
            eleccion = chequeo = false;

            while (!eleccion){cout << "Elija los dados para llegar al numero objetivo, para terminar de cargar ponga 0: ";
                cin >> dadoElegido;
                chequeo = chequeoDados(vDadosStock1, dadosStock1, dadoElegido);
                eleccion = eleccionDados();

                if (chequeo){
                    acuElegidos++;
                    acuDado += dadoElegido;
                }
            }

                cout << "--------------------------------------------------------" << endl << endl;

        /// Sumar dados seleccionados y comparar con la suma objetivo
                if (objetivo == acuDado){
                    dadosStock1 = dadosStock1 - acuElegidos;
                    dadosStock2 = dadosStock2 + acuElegidos;}
                else if (dadosStock2 > 1){
                    dadosStock1 += 1;
                    dadosStock2 -= 1;}

                puntosJ1 = puntaje(dadosStock1, objetivo, acuDado, acuElegidos, puntosJ1);
                cout << "--------------------------------------------------------" << endl << endl;
                mostrarDatos(rondaActual, puntosJ1, puntosJ2, dadosStock1, dadosStock2);
                cout << "--------------------------------------------------------" << endl << endl;

        /// Jugada de ronda del jugador 2
                cout << "Juega el jugador 2: " << jugador2 << endl;
                objetivo = numeroObjetivo(objetivo);
                cout << "--------------------------------------------------------" << endl << endl;
                int vDadosStock2[dadosStock2];
                cout << "Tirada de dados: " << endl;
                mostrarDados(vDadosStock2, dadosStock2);
                cout << endl << "--------------------------------------------------------" << endl << endl;

        /// Preguntar a jugador que dado selecciona o jugador pone 0 para terminar la ronda asi
                acuDado = acuElegidos = dadoElegido = 0;
                eleccion = chequeo = false;

                while (!eleccion){
                    cout << "Elija los dados para llegar al numero objetivo: " << endl;
                    cin >> dadoElegido;

                    chequeo = chequeoDados(vDadosStock2, dadosStock2, dadoElegido);
                    eleccion = eleccionDados();

                    if (chequeo){
                        acuElegidos++;
                        acuDado += dadoElegido;
                    }
                }

                cout << "--------------------------------------------------------" << endl << endl;

        /// Sumar dados seleccionados y comparar con la suma objetivo

                    if (objetivo == acuDado){
                        dadosStock2 = dadosStock2 - acuElegidos;
                        dadosStock1 = dadosStock1 + acuElegidos;}
                    else if (dadosStock1 > 1){
                        dadosStock2 += 1;
                        dadosStock1 -= 1;}

                    puntosJ2 = puntaje(dadosStock2, objetivo, acuDado, acuElegidos, puntosJ2);
                    cout << "--------------------------------------------------------" << endl << endl;

                    rondaActual++;
                }

        //Final. Anuncio del ganador y carga de puntaje maximo.
        if (puntosJ1 == puntosJ2){cout << "La partida termino empatada en " << puntosJ1 << " puntos." << endl << endl;}
        if (puntosJ1 > puntosJ2){
            cout << "El ganador es el Jugador 1: " << jugador1 << " con " << puntosJ1 << " puntos." << endl << endl;
            if (puntosJ1 > puntosMax){
                puntosMax = puntosJ1;
                jugadorMax = jugador1;}}
        else {cout << "El ganador es el Jugador 2: " << jugador2 << " con " << puntosJ2 << " puntos." << endl << endl;
            if (puntosJ2 > puntosMax){
                puntosMax = puntosJ2;
                jugadorMax = jugador2;}}}

        if (menuEleccion==2){
        cout << "ESTADISTICAS" << endl << endl;
        if (puntosMax == 0){cout << "No hay registro de partidas jugadas" << endl << endl;}
        else{cout << "El puntaje maximo obtenido le pertenece al jugador " << jugadorMax << " y es de " << puntosMax << endl << endl;}

        cout << "Presione 1 si desea volver al Menu Principal: ";
        cin >> volver;}

        if (menuEleccion==3){volver = creditos();}
    return 0;}
