#include<iostream>
using namespace std;

int funcionDadoInicio(int inicio, int fin) {
    return rand() % ( fin - inicio + 1) + inicio;
}
