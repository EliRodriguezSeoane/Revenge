#include <iostream>

using namespace std;
int funcionDadoInicio(int inicio,int fin);

int funcionDadoInicio(int inicio, int fin) {
    return rand() % ( fin - inicio + 1) + inicio;
}
int main()
{   int dadoA, dadoB;
    dadoA = funcionDadoInicio(1,100);
    dadoB = funcionDadoInicio(1,100);
    while (dadoA == dadoB){
        dadoB = funcionDadoInicio(1,100);
    }
    int rondaActual = 1;
    int RONDAS = 5;
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

    ///         Rondas 5 o hasta que dados stock sean 0
                while (rondaActual != RONDAS + 1 || dadosStock1 == 0 || dadosStock2 == 0 ){
                    cout << "Entro al while" << endl;
                    cout << dadosStock1;

    ///             Quien es el jugador 1 y el 2

    ///             Mostrar numero de ronda actual

    ///             Nombre del jugador que tira

    ///             Puntaje acumulado de ambos jugadores

    ///             Cantidad actual de dados stock de cada jugador

    ///         Jugada de ronda del jugador 1
    ///             Tirada dados 12
    ///             Mostrar dados y suma de ellos
    ///             Tirada dados stock
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
