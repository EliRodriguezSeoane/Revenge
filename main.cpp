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
    int RONDAS = 2;
    int dado12A, dado12B;
    int numeroObjetivo;
    int dado;
    /// Mostrar menu principal


    ///     Acceso a jugar
    ///         Pedir nombre de jugadores
                string jugadorA, jugadorB;
                cout << "Nombre del jugador: ";
                cin >> jugadorA;
                cout << "Nombre del jugador: ";
                cin >> jugadorB;

    ///         Iniciar juego
                string jugador1, jugador2;

    ///         Tirar dado para decidir jugador 1
                if (dadoA > dadoB){
                    jugador1 = jugadorA;
                    jugador2 = jugadorB;
                } if (dadoB > dadoA){
                    jugador1 = jugadorB;
                    jugador2 = jugadorA;
                }
                int dadosStock1 = 6;
                int dadosStock2 = 6;
    ///         Quien es el jugador 1 y el 2
                cout << "El jugador 1 es: " << jugador1 << endl;
                cout << "El jugador 2 es: " << jugador2 << endl;

                int puntosJ1, puntosJ2;
                puntosJ1 = 0;
                puntosJ2 = 0;

    ///         Rondas 5 o hasta que dados stock sean 0
                while (rondaActual != RONDAS + 1 || dadosStock1 == 0 || dadosStock2 == 0 ){
                    cout << "Entro al while" << endl;


    ///             Mostrar numero de ronda actual
                    cout << "Ronda actual: " << rondaActual << endl;

    ///             Puntaje acumulado de ambos jugadores
                    cout << "Puntaje jugador 1: " << puntosJ1 << endl;
                    cout << "Puntaje jugador 2: " << puntosJ2 << endl;

    ///             Cantidad actual de dados stock de cada jugador
                    cout << "Dados Stock jugador 1: " << dadosStock1 << endl;
                    cout << "Dados Stock jugador 2: " << dadosStock2 << endl;

    ///         Jugada de ronda del jugador 1
    ///             Nombre del jugador que tira
                    cout << "Tira " << jugador1 << endl;
    ///             Tirada dados 12
                    dado12A = funcionDado(1,12);
                    dado12B = funcionDado(1,12);
    ///             Mostrar dados y suma de ellos
                    cout << "Los dados de 12 caras son: " << dado12A << " - " << dado12B << endl;
                    numeroObjetivo = dado12A + dado12B;

    ///             Tirada dados stock
                    for (i=0, i<dadosStock1, i++){
                        dado = funcionDado(1,6);
                        cout << dado << " ";
                    }
    ///             Mostrar dados
    ///             Preguntar a jugador que dado selecciona o jugador pone 0 para terminar la ronda asi
    ///             Sumar dados seleccionados y comparar con la suma objetivo
    ///                 Si iguales tirada exitosa
    ///                     Mostrar que fue exitosa, dados elegidos y suma, cuantos dados pasan al otro jugador
    ///                 Si ronda no exitosa
    ///                     Mostrar que no fue exitosa, cuantos dados recibe del otro jugador
    ///                 Si tirada exitosa quedando sin dados stock
    ///                     Mostrar que gano la partida y finaliza el juego
    ///             Acumular puntaje
    ///         Jugada de ronda del jugador 2


                    rondaActual ++;
                }

    ///     Acceso a estadisticas
    ///         Mostrar nombre del jugador que obtuvo el mayor puntaje y el puntaje

    ///     Acceso a creditos
    ///         Mostrar apellidos, nombre y legajos de los integrantes del equipo
    ///         Mostrar nombre del equipo

    return 0;
}
