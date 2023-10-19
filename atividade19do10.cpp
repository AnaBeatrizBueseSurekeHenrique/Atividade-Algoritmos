#include <iostream>

using namespace std;

int main(){
    float numero1, numero2;
    float *fP;
    numero1 = 7.3;
    fP = &numero1;
    cout << "Valor atribuido a fP = " << *fP << endl;
    numero2 = *fP;
    cout << "Valor de numero2 = " << numero2 << endl;
    cout << "Enedereco de numero1 = " << &numero1 << endl;
    cout << "Endereco armazenado em fP = " << fP;
    return 0;
}