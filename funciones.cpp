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
    int MenuPrincipal;
    cout << "Ingrese la opcion que desee: ";
    cin >> MenuPrincipal;
    cout << endl;
    while (MenuPrincipal < 0 || MenuPrincipal > 3){
        cout << "La opcion ingresada es invalida. Por favor, pruebe otra vez" << endl;
        cin >> MenuPrincipal;
    } return MenuPrincipal;
}

int salida(){
    int salir;
    cout << "SALIR" << endl << endl;
    cout << "Esta seguro que desea salir del juego?" << endl;
    cout << "Presione 0 para salir y 1 para volver al Menu Principal: ";
    cin >> salir;
    while (salir != 0 && salir !=1){
        cout << "La opcion no es correcta, pruebe otra vez" << endl;
        cout << "Presione 0 para salir y 1 para permanecer en el juego" << endl;
        cin >> salir;
    } return salir;
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
    } cout << "Tirada para decidir Jugador 1: ";
    if (dadoA > dadoB){
        return 'A';
    } else{
        return 'B';
    }
}

void mostrarDatos(int rondaActual, int puntosJ1, int puntosJ2, int dadosStock1, int dadosStock2){
    string continuar;
    if (rondaActual == 0){
        cout << "Los resultados finales son: " << endl << endl;
    } else {
        cout << "Ronda actual: " << rondaActual << endl;
    } cout << "Puntaje jugador 1: " << puntosJ1 << endl;
    cout << "Puntaje jugador 2: " << puntosJ2 << endl;
    cout << "Dados Stock jugador 1: " << dadosStock1 << endl;
    cout << "Dados Stock jugador 2: " << dadosStock2 << endl << endl;
    cout << "Presione cualquier tecla para continuar: ";
    cin >> continuar;
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

bool chequeoDados(int v[], int cant, int elegido/*, bool eleccion*/){
    bool chequeo = false;
    for(int i=0; i<cant; i++){
        if(elegido==v[i]){
            chequeo = true;
            v[i] = 0;
            return true;
        }
    } if (!chequeo){
        cout << "El numero elegido no esta entre los dados tirados." << endl;
        return false;
    }
}

bool eleccionDados(int acuDado, int objetivo){
        if (acuDado == objetivo){
            return true;
        }
        else if (acuDado > objetivo){
            cout << endl << "--------------------------------------------------------" << endl;
            cout << endl << "La suma de los dados seleccionados supera al numero objetivo" << endl;
            return true;
        }
        return false;
}

int puntaje(int cant, int objetivo, int acuDado, int acuElegidos, int puntos){
    if (objetivo==acuDado && cant != 0){
        cout << "Jugada exitosa!" << endl;
        cout << "Pasan al siguiente jugador " << acuElegidos << " dados!" << endl << endl;
        puntos += objetivo * acuElegidos;
    } if (objetivo!=acuDado){
        cout << "Jugada no exitosa" << endl;
        cout << "Como penalizacion, recibira un dado de su rival" << endl;
        cout << endl << "--------------------------------------------------------" << endl << endl;
    } if (objetivo==acuDado && cant == 0){
        cout << "No tiene mas dados! Ha ganado la partida!!" << endl << endl;
        puntos += (objetivo * acuElegidos) + 10000;
    }
    return puntos;
}

void regresoMenu (){
    string salir;
    cout << "Presione cualquier tecla para volver al Menu Principal: ";
    cin >> salir;
    cout << endl << "Usted decidio volver al Menu Principal" << endl << endl;
}

void creditos (){
    cout << "CREDITOS" << endl << endl;
    cout << "Los integrantes del equipo son:" << endl;
    cout << "   - Giussani, Santiago           Numero de Legajo: 25.497" << endl;
    cout << "   - Rodriguez Seoane, Eliana     Numero de Legajo: 25.666" << endl << endl;
}
