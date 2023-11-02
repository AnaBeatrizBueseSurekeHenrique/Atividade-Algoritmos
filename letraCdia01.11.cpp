/*C. Implemente funções (e suas chamadas no main()), de acordo com as três formas
de passagem de vetores por parâmetro, que cumpram as seguintes funcionalidades:
1. Retorne o maior dentre os valores armazenados em um vetor de inteiros.
2. Retorne a média dos elementos de um vetor de inteiros.
3. Retorne o número de elementos positivos armazenados em um vetor de inteiros.
4. Insira n valores em um vetor e apresente-o na função main() (n deve ser fornecido
como parâmetro.)
5. Encontre o maior e o menor número em um vetor de inteiros e os apresente na
função main() (é necessária a passagem de parâmetros por referência).*/
#include <iostream>
#include <climits>
#define N 5
using namespace std;
void popularV(int v[], int n);
int maior(int v[], int n);
float media(int v[N]);
int positivos(int *v, int n);
void maiorMenor(int *v, int n, int *maiorN, int *menorN);
int main(){
    int Vetor[N], maiorN = INT_MIN, menor = INT_MAX;
    popularV(Vetor, N);
    cout << "Maior numero = " << maior(Vetor, N) << endl;
    cout << "Media = " << media(Vetor) << endl;
    cout << "Numero de positivos = " << positivos(Vetor, N) << endl;
    maiorMenor(Vetor, N, &maiorN, &menor);
    cout << "Maior n = " << maiorN << ", menor n = " << menor;
    return 0;
}

void popularV(int v[], int n){
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
}

int maior(int v[], int n){
    int maiorN = INT_MIN;
    for(int i = 0; i < n; i++){
        if(v[i] > maiorN){
            maiorN = v[i];
        }
    }
    return maiorN;
}

float media(int v[N]){
    float media;
    int soma = 0;
    for(int i = 0; i < N; i++){
        soma += v[i];
    }
    return soma/N;
}
int positivos(int *v, int n){
    int posit = 0;
    for(int i = 0; i < n; i++){
        if(v[i] >= 0){
            posit++;
        }
    }
    return posit;
}
void maiorMenor(int *v, int n, int* maiorN, int* menorN){
    for(int i = 0; i < n; i++){
        if(v[i] > *maiorN){
            *maiorN = v[i];
        } 
        if(*menorN > v[i]){
            *menorN = v[i];
        }
        
    }
}
