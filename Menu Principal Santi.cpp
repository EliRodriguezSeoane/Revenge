#include<iostream>
using namespace std;

int main(void){

    //MENÚ PRINCIPAL

    cout << "REVENGE" << endl;
    cout << "------------------" << endl;
    cout << "1 - JUGAR" << endl;
    cout << "2 - ESTADISTICAS" << endl;
    cout << "3 - CREDITOS" << endl;
    cout << "------------------" << endl;
    cout << "0 - SALIR" << endl;

    int MenuPrincipal;
    cout << "Ingrese la opcion que desee: ";
    cin >> MenuPrincipal;

    while (MenuPrincipal < 0 || MenuPrincipal > 3){
        cout << "La opcion ingresada es invalida. Por favor, pruebe otra vez" << endl;
        cin >> MenuPrincipal;
    }

    switch (MenuPrincipal){
        case 1:
            cout << "Jugar";
            break;
        case 2:
            cout << "Estadisticas";
            break;
        case 3:
            cout << "Creditos";
            break;
        case 0:
            cout << "Salir";
            break;
        default:
            break;
    }


	return 0;
}
