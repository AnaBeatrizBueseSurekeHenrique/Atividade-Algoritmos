#include <iostream>

using namespace std;

extern int global;

void trocarVal(){
    global = 81;
    cout << "Novo valor = ";
}