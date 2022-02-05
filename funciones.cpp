#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int menu(){
        cout << "REVENGE" << endl;
        cout << "------------------" << endl;
        cout << "1 - JUGAR" << endl;
        cout << "2 - ESTADISTICAS" << endl;
        cout << "3 - CREDITOS" << endl;
        cout << "------------------" << endl;
        cout << "0 - SALIR" << endl << endl;
        int opcion;
        cout << "Ingrese la opcion que desee: ";
        cin >> opcion;
        cout << endl;

        return opcion;
    }

int creditos (){
    cout << "CREDITOS" << endl << endl;
    cout << "Los integrantes del equipo son:" << endl;
    cout << "   - Giussani, Santiago           Numero de Legajo: " << endl;
    cout << "   - Rodriguez Seoane, Eliana     Numero de Legajo: 25.666" << endl << endl;

    int volver;
    cout << "Presione 1 si desea volver al Menu Principal: ";
    cin >> volver;
    return volver;
}

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

int numeroObjetivo(int objetivo){
    int dado12A, dado12B;
    dado12A = funcionDado(1,12);
    dado12B = funcionDado(1,12);
    cout << "Los dados de 12 caras son: " << dado12A << " - " << dado12B << endl;
    objetivo = dado12A + dado12B;
    cout << "El numero objetivo es: " << objetivo << endl << endl;
    return objetivo;
}

void mostrarDados(int v[], int cant){
    int dado, uno=1, seis=6;
    for (int i=0; i<cant; i++){
        dado = funcionDado(uno,seis);
        v[i] = dado;
        cout << v[i] << " - ";
    }
}

bool chequeoDados(int v[], int cant, int elegido){
    bool chequeo = false;
    if (elegido==0){return false;}
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

int puntaje(int cant, int objetivo, int acuDado, int acuElegidos, int puntos){
    if (objetivo==acuDado && cant != 0){
        cout << "Jugada exitosa!" << endl;
        puntos += objetivo * acuElegidos;
        cout << "Puntos: " << objetivo << " x " << acuElegidos << endl;
        cout << "Pasan al siguiente jugador " << acuElegidos << " dados!" << endl;
    } if (objetivo!=acuDado){
        cout << "Jugada no exitosa";
    } if (objetivo==acuDado && cant == 0){
        cout << "No tiene mas dados! Ha ganado la partida!!" << endl;
        cout << "Gana automaticamente 10.000 puntos!" << endl << endl;
        puntos += 10000;
    }
    return puntos;
}
