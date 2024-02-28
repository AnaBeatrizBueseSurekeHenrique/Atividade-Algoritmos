#include <iostream>
#include <math.h>
using namespace std;


int soma(int v, int n){
    int soma = 0;
    for(int i = 0; i < n; i++){
        soma += v[i];
    }
}

int media(int v, int n){
    return soma(v, n) / n;
}
int minimo(int v, int n){
    int menor = v[0];
    for(int i = 1; i < n; i++){
        if(v[i] < menor){
            menor = v[i]
        }
    }
}

int maximo(int v, int n){
    int maior = v[0];
    for(int i = 1, i < n; i++){
        if(v[i] > maior){
            maior = v[i];
        }
    }
}
int distancia(int x1, int y1, int x2, int y2){
    return sqrt(pow((x1-x2),2) + pow((y1-y2),2));
}

int calculoscomplexos(int multiplicado, int multiplicando){
    for(int i = 0; i < multiplicando; i++){
        multiplicado += multiplicado;
    }
    return multiplicado;
}

int fatorial(int numero){
    int c;
    for(int i = 0; i < numero; i++){
        numero*1;
    }
    //a causa do erro é o fato de i começar em zero;
}
float area_circulo(float raio){
    float pi = 3.14;
    return pi*pow(raio,2);
}

float volume_circulo(float raio){
    int pi = 3.14;
    return (4.0/3.0)*pi*(pow(3,raio));
}
void(int v, int n){
    string conta;
    cin >> conta;
    switch(conta){
        case soma:
        soma(v, n)
        break;
        case fatorial:
            fatorial(soma(v,n));
    }
}
