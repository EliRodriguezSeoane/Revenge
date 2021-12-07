#include <iostream>

using namespace std;
int funcionDado(int inicio,int fin);

int funcionDado(int inicio, int fin) {
    return rand() % ( fin - inicio + 1) + inicio;
}

int main()
{   int dadoA, dadoB;
    dadoA = funcionDado(1,100);
    dadoB = funcionDado(1,100);
    while (dadoA == dadoB){
        dadoB = funcionDado(1,100);
    }
    int rondaActual = 1;
    int RONDAS = 1;
    int dado12A, dado12B;
    int numeroObjetivo;
    int dado;
    int i,j;
    int puntosJ1, puntosJ2;
    puntosJ1 = puntosJ2 = 0;

    /// Mostrar menu principal


    ///     Acceso a jugar
    ///         Pedir nombre de jugadores
                string jugadorA, jugadorB;
                cout << "Nombre del jugador: ";
                cin >> jugadorA;
                cout << "Nombre del jugador: ";
                cin >> jugadorB;
                cout << "--------------------------------------------------------" << endl << endl;

    ///         Iniciar juego
                string jugador1, jugador2;

    ///         Tirar dado para decidir jugador 1
                cout << "Tirada para decidir Jugador 1: ";
                if (dadoA > dadoB){
                    jugador1 = jugadorA;
                    jugador2 = jugadorB;
                    cout << "Gana " << jugadorA << " con " << dadoA << endl;
                } if (dadoB > dadoA){
                    jugador1 = jugadorB;
                    jugador2 = jugadorA;
                    cout << "Gana " << jugadorB << " con " << dadoB << endl;
                }
                int dadosStock1 = 6;
                int dadosStock2 = 6;

    ///         Quien es el jugador 1 y el 2 (Mostrar los dados de 100 para que vean quien gano el jugador 1)
                cout << "El jugador 1 es: " << jugador1 << endl;
                cout << "El jugador 2 es: " << jugador2 << endl << endl;
                cout << "--------------------------------------------------------" << endl << endl;



    ///         Rondas 5 o hasta que dados stock sean 0
                while (rondaActual != RONDAS + 1 || dadosStock1 != 0 || dadosStock2 != 0){
                    cout << "Juega el Jugador 1" << endl;


    ///             Mostrar numero de ronda actual
                    cout << "Ronda actual: " << rondaActual << endl;

    ///             Puntaje acumulado de ambos jugadores
                    cout << "Puntaje jugador 1: " << puntosJ1 << endl;
                    cout << "Puntaje jugador 2: " << puntosJ2 << endl;


    ///             Cantidad actual de dados stock de cada jugador
                    cout << "Dados Stock jugador 1: " << dadosStock1 << endl;
                    cout << "Dados Stock jugador 2: " << dadosStock2 << endl << endl;
                    cout << "--------------------------------------------------------" << endl << endl;

    ///         Jugada de ronda del jugador 1
    ///             Nombre del jugador que tira
                    cout << "Tira " << jugador1 << endl;
    ///             Tirada dados 12
                    dado12A = funcionDado(1,12);
                    dado12B = funcionDado(1,12);
    ///             Mostrar dados y suma de ellos
                    cout << "Los dados de 12 caras son: " << dado12A << " - " << dado12B << endl;
                    numeroObjetivo = dado12A + dado12B;
                    cout << "El numero objetivo es: " << numeroObjetivo << endl << endl;
                    cout << "--------------------------------------------------------" << endl << endl;

    ///             Tirada dados stock
                    int vDadosStock[dadosStock1];
                    cout << "Tirada de dados: " << endl;
    ///             Mostrar dados
                    for (i=0; i<dadosStock1; i++){
                        dado = funcionDado(1,6);
                        vDadosStock[i] = dado;
                        cout << vDadosStock[i] << " - ";
                    }
                    cout << endl << "--------------------------------------------------------" << endl << endl;
                    bool eleccion = false;
                    int dadoElegido, acuDado, acuElegidos;
                    acuDado = acuElegidos = 0;

    ///             Preguntar a jugador que dado selecciona o jugador pone 0 para terminar la ronda asi
                    while (!eleccion){

                        cout << "Elija los dados para llegar al numero objetivo: " << endl;
                        cin >> dadoElegido;
                        bool chequeado = false;

                        for(j=0; j<dadosStock1; j++){
                            if(dadoElegido==vDadosStock[j]){
                               acuDado+= dadoElegido;
                               chequeado = true;
                               }
                        }
                        if (!chequeado){
                            cout << "El numero elegido no esta entre los dados tirados." << endl;
                        }else { acuElegidos ++;
                        }


                        int termino1;
                        cout << "¿Termino de cargar los dados? (0 para si): " << endl;
                        cin >> termino1;

                        if(termino1==0){
                            eleccion = true;
                        }
                    }
                    cout << "--------------------------------------------------------" << endl << endl;
    ///             Sumar dados seleccionados y comparar con la suma objetivo
                    dadosStock1 = dadosStock1 - acuElegidos;
   ///             Acumular puntaje
                    if (numeroObjetivo==acuDado && dadosStock1 != 0){
                        cout << "Jugada exitosa!" << endl;
                        cout << "Pasan al siguiente jugador " << acuElegidos << " dados!" << endl;
                        puntosJ1 += numeroObjetivo * acuElegidos;
                    } if (numeroObjetivo!=acuDado){
                         cout << "Jugada no exitosa";
                    } if (numeroObjetivo==acuDado && dadosStock1 == 0){
                        cout << "No tiene mas dados! Ha ganado la partida!!" << endl << endl;
                        puntosJ1 += 10000;
                        }
                }
                cout << "--------------------------------------------------------" << endl << endl;

    ///         Jugada de ronda del jugador 2
            while (rondaActual != RONDAS + 1 || dadosStock1 != 0 || dadosStock2 != 0){
                    cout << "Juega el Jugador 2" << endl;


    ///             Mostrar numero de ronda actual
                    cout << "Ronda actual: " << rondaActual << endl;

    ///             Puntaje acumulado de ambos jugadores
                    cout << "Puntaje jugador 1: " << puntosJ1 << endl;
                    cout << "Puntaje jugador 2: " << puntosJ2 << endl;

    ///             Cantidad actual de dados stock de cada jugador
                    cout << "Dados Stock jugador 1: " << dadosStock1 << endl;
                    cout << "Dados Stock jugador 2: " << dadosStock2 << endl << endl;
                    cout << "--------------------------------------------------------" << endl << endl;

    ///         Jugada de ronda del jugador 1
    ///             Nombre del jugador que tira
                    cout << "Tira " << jugador2 << endl;
    ///             Tirada dados 12
                    dado12A = funcionDado(1,12);
                    dado12B = funcionDado(1,12);
    ///             Mostrar dados y suma de ellos
                    cout << "Los dados de 12 caras son: " << dado12A << " - " << dado12B << endl;
                    numeroObjetivo = dado12A + dado12B;
                    cout << "El numero objetivo es: " << numeroObjetivo << endl << endl;
                    cout << "--------------------------------------------------------" << endl << endl;

    ///             Tirada dados stock
                    int vDadosStock[dadosStock1];
                    cout << "Tirada de dados: " << endl;
    ///             Mostrar dados
                    for (i=0; i<dadosStock2; i++){
                        dado = funcionDado(1,6);
                        vDadosStock[i] = dado;
                        cout << vDadosStock[i] << " - ";
                    }
                    cout << endl << "--------------------------------------------------------" << endl << endl;
                    bool eleccion = false;
                    int dadoElegido, acuDado, acuElegidos;
                    acuDado = acuElegidos = 0;

    ///             Preguntar a jugador que dado selecciona o jugador pone 0 para terminar la ronda asi
                    while (!eleccion){

                        cout << "Elija los dados para llegar al numero objetivo: " << endl;
                        cin >> dadoElegido;
                        bool chequeado = false;

                        for(j=0; j<dadosStock1; j++){
                            if(dadoElegido==vDadosStock[j]){
                               acuDado+= dadoElegido;
                               chequeado = true;
                               }
                        }
                        if (!chequeado){
                            cout << "El numero elegido no esta entre los dados tirados." << endl;
                        }else { acuElegidos ++;
                        }

                        int termino2;
                        cout << "¿Termino de cargar los dados? (0 para si): " << endl;
                        cin >> termino2;

                        if(termino2==0){
                            eleccion = true;
                        }
                    }
                    cout << "--------------------------------------------------------" << endl << endl;
    ///             Sumar dados seleccionados y comparar con la suma objetivo
                    dadosStock1 = dadosStock1 - acuElegidos;
   ///             Acumular puntaje
                    if (numeroObjetivo==acuDado && dadosStock2 != 0){
                        cout << "Jugada exitosa!" << endl;
                        cout << "Pasan al siguiente jugador " << acuElegidos << " dados!" << endl;
                        puntosJ2 += numeroObjetivo * acuElegidos;
                    } if (numeroObjetivo!=acuDado){
                         cout << "Jugada no exitosa";
                    } if (numeroObjetivo==acuDado && dadosStock2 == 0){
                        cout << "No tiene mas dados! Ha ganado la partida!!" << endl << endl;
                        puntosJ2 += 10000;
                        }
                }
                cout << "--------------------------------------------------------" << endl << endl;

    ///     Acceso a estadisticas
    ///         Mostrar nombre del jugador que obtuvo el mayor puntaje y el puntaje

    ///     Acceso a creditos
    ///         Mostrar apellidos, nombre y legajos de los integrantes del equipo
    ///         Mostrar nombre del equipo

    return 0;
}
