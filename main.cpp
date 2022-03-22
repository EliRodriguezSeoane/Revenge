#include <iostream>
#include <cstdlib>
#include <ctime>
#include "funciones.h"
using namespace std;

int main(){
    string jugadorMax;                  //Aparece en jugar y en estadísticas. Se tiene que mantener su valor en Menú Principal
    int puntosMax = 0;                  //Aparece en jugar y en estadísticas. Se tiene que mantener su valor en Menú Principal
    const int JUGADORES = 2;
    const int RONDAS = 5;
    srand(time(NULL));

    while (true){
        int MenuPrincipal;
        MenuPrincipal = menu();

        if (MenuPrincipal == 0){
            int salir;
            salir = salida();
            if (salir == 0){
                cout << endl << "Usted decidio salir del juego" << endl;
                return 0;
            } else {
                cout << endl << "Usted decidio continuar en el juego" << endl << endl;
            }
        }

        else if (MenuPrincipal == 1){
            cout << "-----" << endl << "JUGAR" << endl << "-----" << endl;

            string jugadorA, jugadorB, jugador1, jugador2;
            cout << endl << "Nombre del jugador: ";
            cin >> jugadorA;
            cout << "Nombre del jugador: ";
            cin >> jugadorB;
            cout << endl << "--------------------------------------------------------" << endl << endl;
            char ganador = decisionJugador1();

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

            int rondaActual = 1;
            int dadosStock1, dadosStock2;
            dadosStock1 = dadosStock2 = 6;
            int puntosJ1, puntosJ2;
            puntosJ1 = puntosJ2 = 0;

        /// Rondas 5 o hasta que dados stock sean 0
            while (rondaActual <= RONDAS && dadosStock1 != 0 && dadosStock2 != 0){
                for(int i=0; i<JUGADORES; i++){
                    mostrarDatos(rondaActual, puntosJ1, puntosJ2, dadosStock1, dadosStock2);
                    cout << "--------------------------------------------------------" << endl << endl;

        /// Jugada de ronda del jugador 1
                    cout << "Juega el jugador " << i+1 << ": ";
                    if(i+1==1){
                        cout << jugador1 << endl << endl;
                    } else{
                        cout << jugador2 << endl << endl;
                    }
                    int objetivo;
                    objetivo = numeroObjetivo(objetivo);
                    cout << "--------------------------------------------------------" << endl << endl;
                    int vDadosStock1[dadosStock1];
                    int vDadosStock2[dadosStock2];
                    cout << "Tirada de dados: " << endl << endl;
                    if(i+1==1){
                        mostrarDados(vDadosStock1, dadosStock1);
                    } else{
                        mostrarDados(vDadosStock2, dadosStock2);
                    }
                    cout << endl << endl << "--------------------------------------------------------" << endl << endl;

        /// Preguntar a jugador que dado selecciona o jugador pone 0 para terminar la ronda asi
                    int acuDado, acuElegidos, dadoElegido, dadoElegidoAnterior;
                    acuDado = acuElegidos = dadoElegido = dadoElegidoAnterior = 0;

                    bool eleccion, chequeo, primer_dado, bono;
                    eleccion = chequeo = primer_dado = bono = false;

                    while (!eleccion){
                        cout << "Elija los dados para llegar al numero objetivo: ";
                        cin >> dadoElegido;

                        if(i+1==1){
                            chequeo = chequeoDados(vDadosStock1, dadosStock1, dadoElegido);
                        } else{
                            chequeo = chequeoDados(vDadosStock2, dadosStock2, dadoElegido);
                        }

                        if (!chequeo){
                            cout << "Desea terminar la tirada? (Presione 0 para terminar la jugada): ";
                            int fin_jugada;
                            cin >> fin_jugada;
                            if (fin_jugada == 0){
                            eleccion = true;
                            }
                        }

                        if (dadoElegido != 0){
                            if (chequeo){
                                acuElegidos++;
                                acuDado += dadoElegido;
                                if(!primer_dado){
                                    dadoElegidoAnterior = dadoElegido;
                                    primer_dado = true;
                                } else{if(dadoElegido==dadoElegidoAnterior){
                                        bono = true;}else{
                                        bono = false;}
                                }
                            }
                        }

                        if (!eleccion){
                            eleccion = eleccionDados(acuDado, objetivo);
                        }
                    }
                    cout << endl << "--------------------------------------------------------" << endl << endl;

        /// Sumar dados seleccionados y comparar con la suma objetivo
                    if (objetivo == acuDado){
                        if (i+1==1){
                            dadosStock1 = dadosStock1 - acuElegidos;
                            dadosStock2 = dadosStock2 + acuElegidos;
                        }
                        else{
                            dadosStock2 = dadosStock2 - acuElegidos;
                            dadosStock1 = dadosStock1 + acuElegidos;
                        }
                    }
                    else{
                        if(i+1==1){
                            if (dadoElegido > 0){
                                dadosStock1 += 1;
                                dadosStock2 -= 1;
                            }
                        }
                        else {
                            if (dadoElegido > 0){
                                dadosStock2 += 1;
                                dadosStock1 -= 1;
                            }
                        }
                    }

                    if(i+1==1){
                        puntosJ1 = puntaje(dadosStock1, objetivo, acuDado, acuElegidos, puntosJ1, bono);
                    } else{
                        puntosJ2 = puntaje(dadosStock2, objetivo, acuDado, acuElegidos, puntosJ2, bono);
                    }

                    if (objetivo == acuDado){
                        cout << "La cantidad de dados elegida fue de " << acuElegidos << " dados, y la suma total " << endl;
                        cout << "de los dados fue de " << acuDado << ", por lo que el puntaje total, que se obtiene " << endl;
                        cout << "de la multiplicacion de estos valores, sera de " << acuElegidos * acuDado << " puntos." << endl << endl;
                        cout << "--------------------------------------------------------" << endl << endl;
                        if(bono){
                            cout << "Al haber elegido los dados con caras iguales gana un bono que dobla el puntaje recibido!" << endl;
                            cout << "Le queda entonces el puntaje de: " << (acuElegidos * acuDado) * 2 << endl;
                        }
                    }
                    if (dadosStock2 == 0 || dadosStock1 == 0){
                        i = 2;
                    }
                }
                rondaActual++;
            }

            cout << "***--------------------------------------------------***" << endl << endl;

            //Final. Anuncio del ganador y carga de puntaje maximo.
            cout << "Los puntajes finales de la partida son: " << endl;
            if (puntosJ1 > puntosJ2){
                cout << "El ganador es el Jugador 1: " << jugador1 << " con " << puntosJ1 << " puntos." << endl << endl;
                if (puntosJ1 > puntosMax){
                    puntosMax = puntosJ1;
                    jugadorMax = jugador1;
                }
            }
            else if (puntosJ1 == puntosJ2){
                cout << "La partida termino empatada en " << puntosJ1 << " puntos." << endl << endl;
            }
            else {
                cout << "El ganador es el Jugador 2: " << jugador2 << " con " << puntosJ2 << " puntos." << endl << endl;
                if (puntosJ2 > puntosMax){
                    puntosMax = puntosJ2;
                    jugadorMax = jugador2;
                }
            }
        }

        else if (MenuPrincipal == 2){
            cout << "ESTADISTICAS" << endl << endl;
            if (puntosMax == 0){
                cout << "No hay registro de partidas jugadas" << endl << endl;
            } else{
                cout << "El puntaje maximo obtenido le pertenece al jugador " << jugadorMax << " y es de " << puntosMax << endl << endl;
            } regresoMenu();
        }

        else if (MenuPrincipal == 3){
            creditos();
            regresoMenu();
        }
    }
    return 0;
}
