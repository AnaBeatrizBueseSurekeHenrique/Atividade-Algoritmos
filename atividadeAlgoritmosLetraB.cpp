#include <iostream>
#include <iomanip>
using namespace std;

string multiploQuatro(int numero){
    if(numero % 4 == 0){
        return " e multiplo de 4";
    } else{
        return " nao e multiplo de 4";
    }
}

string imparPar(int numero){
    if(numero % 2 == 0){
        return " e par";
    } else{
        return " nao e par";
    }
}

string somaEntre(int numero1, int numero2){
    int soma = 0, fim, inicio;
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
    return "A soma e igual a " + to_string(soma);
}

string volumeEsfera(int raio){
    double volume;
    volume = (4*3.14*(raio*raio*raio))/3;
    return "O volume da esfera e igual a " + to_string(volume);
}

string fatorial(int numero){
    long int fatorial = numero;
    for(int i = 2; i < numero; i++){
        fatorial = fatorial*i;
    }
    return "O fatorial deste numero e " + to_string(fatorial);
}

string potencia(int base, int expoente){
    long int potencia = 1;
    if(expoente != 0){
        for(int i = 1; i <= expoente; i++){
            potencia = potencia* base;
        }
    }
    return to_string(base) + "^" + to_string(expoente) + " = " + to_string(potencia);

}

int main(){
    int numero, numero2, expoente;
    float raio, volume;
    cout << "Insira um numero, para checarmos se e multiplo de 4: ";
    cin >> numero;
    cout << numero << multiploQuatro(numero) << endl;
    cout << "Insira um numero, para checarmos se e impar ou par: ";
    cin >> numero;
    cout << numero << imparPar(numero) << endl; 
    cout << "Insira dois numeros, para calcularmos a soma dos numeros entre eles, incluindo eles: ";
    cin >> numero >> numero2;
    cout << somaEntre(numero, numero2) << endl;
    cout << "Insira o valor do raio da esfera: ";
    cin >> raio;
    cout << volumeEsfera(raio) << endl;
    cout << "Insira um numero para calcularmos seu fatorial: ";
    cin >> numero;
    cout << fatorial(numero) << endl;
    cout << "Insira o valor da base ";
    cin >> numero;
    cout << "Insira o valor do expoente: ";
    cin >> expoente;
    cout << potencia(numero, expoente) << endl;
    return 0;
}