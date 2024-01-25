#include <iostream>

using namespace std;
// A
int soma(int n, int *somar){
    if(n <= 1){
        return 1;
    } else{
        return n + soma(n - 1, somar);    
    }
}

// B
double potenciaCalculo(int n, int potencia){
    if(potencia <= 0){
        return 1;
    } else{
        return n * potenciaCalculo(n, potencia-1);
    }
}
//4

int mult( int m, int n){
    if(n <= 1){
        return m;
    } else{
        return m + mult(m, n-1);
    }    
}
// 1
int func (int n) {
    int soma = 0;
    for(int i = 1; i <= n; i++){
        soma += i;
    } 
    return soma;
}
int main(){
    int n, somar = 0, potencia, m;
    cout << "Insira o numero para calcularmos a soma dos inteiros anteriores a ele e o proprio numero: ";
    cin >> n;
    cout << soma(n, &somar);
    cout << endl << "Insira o numero para para calcularmos a potencia: ";
    cin >> n;
    cout << "Insira a potencia: ";
    cin >> potencia;
    cout << potenciaCalculo(n, potencia);
    cout << endl << "Insira dois numeros para calcularmos a multiplicacao de m por n: ";
    cin >> n >> m;
    cout << mult(m, n);
    cout << "Insira o numero para calcularmos a soma dos inteiros anteriores a ele e o proprio numero: ";
    cin >> n;
    cout << endl << func(n);
}

