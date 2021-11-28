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
    cout << "Dado A :" << dadoA << endl;
    cout << "Dado B :" << dadoB;

    /// Mostrar menu principal
    ///     Acceso a jugar
    ///         Pedir nombre de jugadores
    ///         Iniciar juego
    ///         Tirar dado para decidir jugador 1
    ///         Mostrar
    ///             Quien es el jugador 1 y el 2
    ///             Comenzar ronda
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
    ///         Repetir rondas hasta 5 por jugador o hasta que alguno no tenga dados stock

    ///     Acceso a estadisticas
    ///         Mostrar nombre del jugador que obtuvo el mayor puntaje y el puntaje

    ///     Acceso a creditos
    ///         Mostrar apellidos, nombre y legajos de los integrantes del equipo
    ///         Mostrar nombre del equipo

    return 0;
}
