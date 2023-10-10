#include<iostream>
#include <iomanip>
using namespace std;

int multiploQuatro(int numero){
    return numero%4;
}
int imparPar(int numero){
   return numero%2;
}
int somaEntre(int numero1, int numero2){
    int soma = 0, inicio, fim;
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
    return soma;
}
double volumeEsfera(int raio){
    double volume, raioCubo;
    raioCubo = raio*raio*raio;
    volume = (4*3.14*raioCubo)/3;
    return volume;
}
long int fatorial(int numero){
    long int fatorialCalculo = numero;
    for(int i = 2; i < numero; i++){
        fatorialCalculo = fatorialCalculo*i;
    }
    return fatorialCalculo;
}
long int potencia(int base, int expoente){
    long int calculoPotencia = 1;
    if(expoente != 0){
        for(int i = 1; i <= expoente; i++){
            calculoPotencia = calculoPotencia* base;
        }
    }
    return calculoPotencia;
}

int main(){
    int numero, numero2, razao, soma, fatorialCalculo, expoente;
    double raio, volume;
    long int calculoPotencia;
    cout << "Insira um numero, para checarmos se e multiplo de 4: ";
    cin >> numero;
    razao = multiploQuatro(numero);
    if(razao == 0){
        cout << numero << " e multiplo de 4" << endl;
    } else{
        cout << numero << " nao e multiplo de 4" << endl;
    }
    cout << "Insira um numero, para checarmos se e impar ou par: ";
    cin >> numero;
    razao = imparPar(numero);
    if(razao % 2 == 0){
        cout << numero << " e par" << endl;
    } else{
        cout << numero << " nao e par" << endl;
    }
    cout << "Insira dois numeros, para calcularmos a soma dos numeros entre eles, incluindo eles: ";
    cin >> numero >> numero2;
    soma = somaEntre(numero, numero2);
    cout << "A soma e igual a " << soma << endl;
    cout << "Insira o valor do raio da esfera: ";
    cin >> raio;
    volume = volumeEsfera(raio);
    cout << "O volume da esfera e igual a " << fixed << setprecision(3) << volume << endl;
    cout << "Insira um numero para calcularmos seu fatorial: ";
    cin >> numero;
    fatorialCalculo = fatorial(numero);
    cout << "O fatorial deste numero e " << fatorialCalculo << endl;
    cout << "Insira o valor da base ";
    cin >> numero;
    cout << "Insira o valor do expoente: ";
    cin >> expoente;
    calculoPotencia = potencia(numero, expoente);
    cout << numero << "^" << expoente << " = " << calculoPotencia << endl;

}