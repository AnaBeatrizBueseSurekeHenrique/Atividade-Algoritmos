#include <iostream>
using namespace std;

//II. Implemente uma função recursiva para somar os elementos de um vetor.
float somar (float *v, int n, float soma){
    if(n <= 0){
        soma = v[0];
        return soma;
    } else{
        soma += v[n] + somar(v, n-1, soma);
       return soma;
    }
}

int main(){
    int n;
    cout << "Insira o tamanho do vetor: ";
    cin >> n;
    float v[n], soma = 0;
    cout << "Insira os valores do vetor: ";
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    n -= 1;
    cout << "A soma dos valores do vetor e: " << somar(v, n, soma) << endl;
}
