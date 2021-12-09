#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int funcionDado(int inicio, int fin) {
    return rand() % ( fin - inicio + 1) + inicio;
}
string decisionJugador1(string jugadorA, string jugadorB){
    int dadoA, dadoB;
    dadoA = funcionDado(1,100);
    dadoB = funcionDado(1,100);
    while (dadoA == dadoB){
        dadoB = funcionDado(1,100);
    }
    cout << "Tirada para decidir Jugador 1: ";
    if (dadoA > dadoB){
        cout << "Gana " << jugadorA << " con " << dadoA << endl;
        return jugadorA;
    } else{
        cout << "Gana " << jugadorB << " con " << dadoB << endl;
        return jugadorB;
    }
}

void mostrarDatos(int rondaActual, int puntosJ1, int puntosJ2, int dadosStock1, int dadosStock2){
    cout << "Ronda actual: " << rondaActual << endl;

    cout << "Puntaje jugador 1: " << puntosJ1 << endl;
    cout << "Puntaje jugador 2: " << puntosJ2 << endl;

    cout << "Dados Stock jugador 1: " << dadosStock1 << endl;
    cout << "Dados Stock jugador 2: " << dadosStock2 << endl << endl;
}
void numeroObjetivo(int objetivo){
    int dado12A, dado12B;
    dado12A = funcionDado(1,12);
    dado12B = funcionDado(1,12);
    cout << "Los dados de 12 caras son: " << dado12A << " - " << dado12B << endl;
    objetivo = dado12A + dado12B;
    cout << "El numero objetivo es: " << objetivo << endl << endl;
}
void mostrarDados(int v[], int cant){
    int dado, uno=1;
    for (int i=0; i<cant; i++){
        dado = funcionDado(uno,cant);
        v[i] = dado;
        cout << v[i] << " - ";
    }
}

bool chequeoDados(int v[], int cant, int elegido){
    bool chequeo = false;
    for(int i=0; i<cant; i++){
       if(elegido==v[i]){
          chequeo = true;
          return true;
       }
     }

    if (!chequeo){
      cout << "El numero elegido no esta entre los dados tirados." << endl;
      return false;
    }
}

bool eleccionDados(){
        int termino;
        cout << "Termino de cargar los dados? (0 para si, 1 para no): ";
        cin >> termino;

       switch(termino){
        case 0:
            return true;
            break;
        case 1:
            return false;
            break;
        }
}

void puntaje(int cant, int objetivo, int acuDado, int acuElegidos, int puntos){
    if (objetivo==acuDado && cant != 0){
        cout << "Jugada exitosa!" << endl;
        cout << "Pasan al siguiente jugador " << acuElegidos << " dados!" << endl;
        puntos += objetivo * acuElegidos;
    } if (objetivo!=acuDado){
        cout << "Jugada no exitosa";
    } if (objetivo==acuDado && cant == 0){
        cout << "No tiene mas dados! Ha ganado la partida!!" << endl << endl;
        puntos += 10000;
    }
}

int main(){
    int rondaActual = 1;
    const int RONDAS = 5;

    int objetivo, puntosJ1, puntosJ2;
    objetivo = puntosJ1 = puntosJ2 = 0;
    string jugadorA, jugadorB;
    string jugador1, jugador2;
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
                jugador1 = decisionJugador1(jugadorA, jugadorB);
                if (jugador1==jugadorA){
                    jugador2 = jugadorB;
                } else {
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
