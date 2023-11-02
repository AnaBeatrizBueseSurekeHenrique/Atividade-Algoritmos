#include <iostream>
#include <climits>
#define N 2
using namespace std;
void maiorMenor(int v[], int w[], int n);
void colocarEmOrdem(int v[]);
void popular(int *v, int n);
void saida(int v[N]);
void inteiraFracionaria(double v[N], int w[N]);
int main(){
    int a[N], b[N], partInt[N] = {0};
    double c[N];
    cout << "Insira os valores do vetor a, para organizarmos depois: ";
    popular(a, N);
    cout << "Insira os valores do vetor b, para organizarmos depois: ";
    popular(b, N);
    maiorMenor(a, b, N);
    cout << "Valores menores: ";
    saida(a);
    cout << "Valores maiores: ";
    saida(b);
   cout << "Insira valores para serem divididos em sua parte intera e em sua parte fracionaria: ";
    for(int i = 0; i < N; i++){
        cin >> c[i];
    }
    inteiraFracionaria(c, partInt);
    cout << "Parte inteira: ";
    saida(partInt);
    cout << "Parte fracionaria: ";
    for(int i = 0; i < N; i++){
        cout << c[i] << " ";
    }
}
void popular(int *v, int n){
     for(int i = 0; i < n; i++){
        cin >> v[i];
    }
}
void saida(int v[N]){
    for(int i = 0; i < N; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
void colocarEmOrdem(int v[N]){
  int aux;
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            if(v[i] > v[j]){
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}  

void maiorMenor(int v[], int w[], int n){
    int auxMenor[n], auxMaior[n], qMaior, qMenor, i = n-1, j = n-1, k = n-1, l = 0;
    colocarEmOrdem(v);
    colocarEmOrdem(w);
    while(k >= 0){
        if(v[i] > w[j]){
            auxMaior[k] = v[i];
            i--;
        } else{
            auxMaior[k] = w[j];
            j--;
        }
        k--;
    }
    i = j = 0;
    while(l < n){
        if(v[i] < w[j]){
            auxMenor[l] = v[i];
            i++;
        } else{
            auxMenor[l] = w[j];
            j++;
        }
        l++;
    }
    for(int i = 0; i < n; i++){
        v[i] = auxMenor[i];
        w[i] = auxMaior[i]; 
    }
}
void inteiraFracionaria(double v[N], int w[N]){
    for(int i = 0; i < N; i++){
        w[i] = (int) v[i];
        v[i] -= w[i];
    }
}