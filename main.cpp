#include <iostream>
#include <cstdlib>
#include <ctime>

#include "funciones.h"
using namespace std;

int main(){
    int rondaActual = 1;
    const int RONDAS = 5;

    int objetivo, puntosJ1, puntosJ2;
    objetivo = puntosJ1 = puntosJ2 = 0;
    string jugadorA, jugadorB;
    string jugador1, jugador2;
    char ganador;
    int dadosStock1, dadosStock2;
    dadosStock1 = dadosStock2 = 6;
    int acuDado, acuElegidos, dadoElegido;
    bool eleccion, chequeo;
    srand(time(NULL));


    /// Mostrar menu principal


    ///     Acceso a jugar
                cout << "Nombre del jugador: ";
                cin >> jugadorA;
                cout << "Nombre del jugador: ";
                cin >> jugadorB;
                cout << "--------------------------------------------------------" << endl << endl;
                ganador = decisionJugador1();
                if (ganador=='A'){
                    cout << "Gana " << jugadorA << endl;
                    jugador1 = jugadorA;
                    jugador2 = jugadorB;
                } else {
                    cout << "Gana " << jugadorB << endl;
                    jugador1 = jugadorB;
                    jugador2 = jugadorA;
                }

                cout << "El jugador 1 es: " << jugador1 << endl;
                cout << "El jugador 2 es: " << jugador2 << endl << endl;
                cout << "--------------------------------------------------------" << endl << endl;

    ///         Rondas 5 o hasta que dados stock sean 0
                while (rondaActual != RONDAS + 1 || dadosStock1 != 0 || dadosStock2 != 0){
                    mostrarDatos(rondaActual, puntosJ1, puntosJ2, dadosStock1, dadosStock2);
                    cout << "--------------------------------------------------------" << endl << endl;
    ///         Jugada de ronda del jugador 1
                    cout << "Juega el jugador 1: " << jugador1 << endl;
                    numeroObjetivo(objetivo);
                    cout << "--------------------------------------------------------" << endl << endl;
                    int vDadosStock1[dadosStock1];
                    cout << "Tirada de dados: " << endl;
                    mostrarDados(vDadosStock1, dadosStock1);
                    cout << endl << "--------------------------------------------------------" << endl << endl;
    ///             Preguntar a jugador que dado selecciona o jugador pone 0 para terminar la ronda asi
                    acuDado = acuElegidos = dadoElegido = 0;
                    eleccion = chequeo = false;

                    while (!eleccion){
                        cout << "Elija los dados para llegar al numero objetivo: ";
                        cin >> dadoElegido;

                        chequeo = chequeoDados(vDadosStock1, dadosStock1, dadoElegido);
                        eleccion = eleccionDados();
                        if (chequeo){
                            acuElegidos++;
                            acuDado+= dadoElegido;
                        }
                    }
                    cout << "--------------------------------------------------------" << endl << endl;
    ///             Sumar dados seleccionados y comparar con la suma objetivo
                    dadosStock1 = dadosStock1 - acuElegidos;
                    puntaje(dadosStock1, objetivo, acuDado, acuElegidos, puntosJ1);
                    cout << "--------------------------------------------------------" << endl << endl;
                    mostrarDatos(rondaActual, puntosJ1, puntosJ2, dadosStock1, dadosStock2);
                    cout << "--------------------------------------------------------" << endl << endl;

    ///         Jugada de ronda del jugador 2
                    cout << "Juega el jugador 2: " << jugador2 << endl;
                    numeroObjetivo(objetivo);
                    cout << "--------------------------------------------------------" << endl << endl;
                    int vDadosStock2[dadosStock2];
                    cout << "Tirada de dados: " << endl;
                    mostrarDados(vDadosStock2, dadosStock2);
                    cout << endl << "--------------------------------------------------------" << endl << endl;
    ///             Preguntar a jugador que dado selecciona o jugador pone 0 para terminar la ronda asi
                    acuDado = acuElegidos = dadoElegido = 0;
                    eleccion = chequeo = false;

                    while (!eleccion){
                        cout << "Elija los dados para llegar al numero objetivo: " << endl;
                        cin >> dadoElegido;

                        chequeo = chequeoDados(vDadosStock2, dadosStock2, dadoElegido);
                        eleccion = eleccionDados();
                        if (chequeo){
                            acuElegidos++;
                            acuDado+= dadoElegido;
                        }
                    }
                    cout << "--------------------------------------------------------" << endl << endl;
    ///             Sumar dados seleccionados y comparar con la suma objetivo
                    dadosStock2 = dadosStock2 - acuElegidos;
                    puntaje(dadosStock2, objetivo, acuDado, acuElegidos, puntosJ2);
                    rondaActual++;
                }

    ///     Acceso a estadisticas
    ///         Mostrar nombre del jugador que obtuvo el mayor puntaje y el puntaje

    ///     Acceso a creditos
    ///         Mostrar apellidos, nombre y legajos de los integrantes del equipo
    ///         Mostrar nombre del equipo

    return 0;
}
