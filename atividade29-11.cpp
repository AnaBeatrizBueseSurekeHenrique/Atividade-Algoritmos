#include <iostream>
#include <climits>
using namespace std;
/*G. Usando aritmética de ponteiros, implemente:
3. Uma função que separe um vetor em dois, sendo um 
com os elementos pares e
outro com os ímpares.*/
//exercicio 1
void maiorMenor (int Vetor[], int tam,  int *num1, int *num2){
    int *p;
    p = Vetor;
    for(int i = 0; i < tam; i++){
        if(*(p+i) > *num2){
            *num2 = *(p+i);
        }
        if(*(p+i) < *num1){
            *num1 = *(p+i);
        }
    }
}
//exercicio 2
void juntar(int Va[], int tamA, int Vb[], int tamB){
    int Jun[tamA+tamB];
    int *p;
    p = Jun;
    for(int i = 0; i < tamA; i++){
        *(p+i) = Va[i];
    }
    for(int i = 0; i < tamB; i++){
        *(p+(i+tamA)) = Vb[i];
    }
    for(int i = 0; i < tamA+tamB; i++){
        cout << Jun[i] << " ";
    }
}

// exercicio 3
void parImpar(int Va[3], int Vb[3], int tamA, int tamB){
    int par = 0, impar = 0;
    for(int i = 0; i < tamA; i++){
        if(Va[i] % 2 == 0){
            par++;
        } else{
            impar++;
        }
    }
    for(int i = 0; i < tamB; i++){
        if(Vb[i] % 2 == 0){
            par++;
        } else{
            impar++;
        }
    }
    int Par[par], Impar[impar], k = 0, j = 0;
    int *p = Par, *pont = Impar;
    for(int i = 0; i < tamA; i++){
        if(Va[i] % 2 == 0){
            *(p+k) = Va[i];
            k++;
        } else{
            *(pont+j) = Va[i];
            j++;
        }
    }
    for(int i = 0; i < tamB; i++){
        if(Vb[i] % 2 == 0){
            *(p+k) = Vb[i];
            k++;
        } else{
            *(pont+j) = Vb[i];
            j++;
        }
    }
    cout << "Numeros impares: ";
    for(int i = 0; i < impar; i++){
        cout << Impar[i] << " ";
    }
    cout << endl << "Numeros pares: ";
    for(int i = 0; i < par; i++){
        cout << Par[i] << " ";
    }
}
int main() {
    int tamanho;
    cout << "Insira o tamanho do vetor: ";
    cin >> tamanho;
    int A[tamanho];
    cout << "Insira os valores do vetor: ";
    for(int i = 0; i < tamanho; i++){
        cin >> A[i];
    }
    int menor = INT_MAX, maior = INT_MIN;
    maiorMenor(A, tamanho, &menor, &maior);
    cout << "Maior = " << maior << " Menor = " << menor << endl;
    int tamanhoB, tamanhoC;
    cout << "Insira o tamanho do Vetor 1, que ira se juntar com o Vetor 2: ";
    cin >> tamanhoB;
    cout << "Insira o tamanho do Vetor 2: ";
    cin >> tamanhoC;
    int B[tamanhoB] = {4,5,6}, C[tamanhoC] = {1,2,3};
    cout << "Insira os valores do Vetor 1: ";
    for(int i = 0; i < tamanhoB; i++){
        cin >> B[i];
    }
    cout << "Insira os valores do Vetor 2: ";
    for(int i = 0; i < tamanhoC; i++){
        cin >> C[i];
    }
    juntar(B, tamanhoB, C, tamanhoC);
    cout << endl;
    int tam1, tam2;
    cout << "Insira o tamanho do vetor A: ";
    cin >> tam1;
    cout << "Insira o tamanho do vetor B: ";
    cin >> tam2;
    int V1[tam1], V2[tam2];
    cout << "Insira os valores do vetor A: ";
    for(int i = 0; i < tam1; i++){
        cin >> V1[i];
    }
    cout << "Insira os valores do vetor B: ";
    for(int i = 0; i < tam2; i++){
        cin >> V2[i];
    }
    parImpar(V1, V2, tam1, tam2);
    return 0;
}