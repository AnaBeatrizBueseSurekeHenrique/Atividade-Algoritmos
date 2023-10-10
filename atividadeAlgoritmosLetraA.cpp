#include <iostream>
#include <iomanip>
using namespace std;

void multiploQuatro(){
    int numero;
    cout << "Insira um numero, para checarmos se e multiplo de 4: ";
    cin >> numero;
    if(numero % 4 == 0){
        cout << numero << " e multiplo de 4" << endl;
    } else{
        cout << numero << " nao e multiplo de 4" << endl;
    }
}

void imparPar(){
    int numero;
    cout << "Insira um numero, para checarmos se e impar ou par: ";
    cin >> numero;
    if(numero % 2 == 0){
        cout << numero << " e par" << endl;
    } else{
        cout << numero << " nao e par" << endl;
    }
}

void somaEntre(){
    int numero1, numero2, soma = 0, inicio, fim;
    cout << "Insira dois numeros, para calcularmos a soma dos numeros entre eles, incluindo eles: ";
    cin >> numero1 >> numero2;
    if(numero2 > numero1){
        inicio = numero1;
        fim = numero2;
    } else{
        inicio =  numero2;
        fim = numero1;
    }
    for(int j = inicio; j <= fim; j++){
        soma += j;
    }
    cout << "A soma e igual a " << soma << endl;
}

void volumeEsfera(){
    float raio, volume;
    cout << "Insira o valor do raio da esfera: ";
    cin >> raio;
    volume = (4*3.14*(raio*raio*raio))/3;
    cout << "O volume da esfera e igual a " << fixed << setprecision(3) << volume << endl;
}

void fatorial(){
    long int numero, fatorial;
    cout << "Insira um numero para calcularmos seu fatorial: ";
    cin >> numero;
    fatorial = numero;
    for(int i = 2; i < numero; i++){
        fatorial = fatorial*i;
    }
    cout << "O fatorial deste numero e " << fatorial << endl;
}

void potencia(){
    long int base, expoente, potencia = 1;
    cout << "Insira o valor da base ";
    cin >> base;
    cout << "Insira o valor do expoente: ";
    cin >> expoente;
    if(expoente != 0){
        for(int i = 1; i <= expoente; i++){
            potencia = potencia* base;
        }
    }
    cout << base << "^" << expoente << " = " << potencia << endl;

}

int main(){
    multiploQuatro();
    imparPar();
    somaEntre();
    volumeEsfera();
    fatorial();
    potencia();
    return 0;
}