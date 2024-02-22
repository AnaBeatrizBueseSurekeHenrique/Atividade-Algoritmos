#include <iostream>
#include <math.h>

using namespace std;

//1. Codigo antes do extract method 
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
//codigo depois.

int resto(int numero){
    return numero % 4;
}

string saida(int resto, int numero){
    if(resto == 0){
        return to_string(numero) + " e multiplo de 4";
    } else{
        return to_string(numero) + " nao e multiplo de 4";
    }
}

void multiplo(){
    int numero;
    cout << "Insira um numero, para checarmos se e multiplo de 4: ";
    cin >> numero;
    cout << saida(resto(numero), numero);
}
// Exercicio correto
float descontoErrado(float p, float d){
    float t = p / 100;
    float s = d * t;
    return d - s;
}
float descontoCorreto(float taxa, float preco){
    float descontoPorcento = taxa/100;
    float descontoReal = preco*descontoPorcento;
    return preco-descontoReal;
}
//Exercicio 5
string checarTemperatura(float temperatura){
    if(temperatura > 100){
        return "Muito quente!";
    }
    if(temperatura > 70){
        return "Clima agradavel";
    }
    if(temperatura > 50){
        return "Fresco";
    }
    return "Muito frio!";
}

int main(){
    multiplo();
    //Exercicio 2
    double capital, taxa, tempo; // p = principal, r = rate, t = time
    capital = 1000.0;
    taxa = 0.05;
    tempo = 2.0;
    double montante = capital * pow(1 + taxa, tempo);
    cout << "O montante é: " << montante << endl;
    // Exercicio 4
    int pi = 3.14159;
    double radius, area = pi * radius * radius; // Use uma constante para P
    

}