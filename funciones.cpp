#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int funcionDado(int inicio, int fin) {
    return rand() % ( fin - inicio + 1) + inicio;
}
char decisionJugador1(){
    int dadoA, dadoB;
    dadoA = funcionDado(1,100);
    dadoB = funcionDado(1,100);
    while (dadoA == dadoB){
        dadoB = funcionDado(1,100);
    }
    cout << "Tirada para decidir Jugador 1: ";
    if (dadoA > dadoB){
        return 'A';
    } else{
        return 'B';
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
