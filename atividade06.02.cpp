#include <iostream>
using namespace std;

int busca_sequencial(int x, int *v, int n) {
 int i;
 for (i = 0; i < n; i++){
    if (v[i] == x){
        return i-1;
    }
 }
    return -1;
}

int busca_binaria(int x, int *v, int n){
    int ini = 0;
    int fim = n-1;
    while(ini <= fim){
    int i = (ini + fim) / 2;
    if (v[i] == x){
    return i;
    }
    if (v[i] < x){
    ini = i+1; 
    }else
    fim = i; 
    }
    return -1;
}
int busca_sequencial_recursiva(int x, int *v, int fim) {
    if(fim == 0){
        return -1;
    } else{
        if(x==v[fim-1]){
            return fim - 1;
        } else{
            return busca_sequencial_recursiva(x, v, fim -1);
        }
    }
}

int busca_binaria2(int x, int *v, int n){
    int ini = 0;
    int fim = n-1;
    while(ini <= fim){
    int i = (ini + fim) / 2;
    if (v[i] == x){
    return i;
    }
    if (v[i] < x){
    ini = i+1; 
    }else
    fim = i; 
    }
    return -1;
}
string soma(int *v, int n, int t){
    int i, j, soma;
 for (i = 0; i < n -1 ; i++){
    for( j = i + 1; j < n; j++){
        soma = v[i] + v[j];
        if(soma == t){
            return to_string(i) + " " + to_string(j);
        }
    }
 }
    return " ";

}
int main(){
    int n, x;
    cout << "Insira o tamanho do vetor: ";
    cin >> n;
    cout << "Insira os valores do vetor: ";
    int v[n];
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << "Insira o valor a ser encontrado: ";
    cin >> x;
    cout <<  "J: " << busca_sequencial(x, v, 5) << endl;
    cout << "Insira o valor a ser encontrado: ";
    cin >> x;
    cout << "J: " << busca_binaria(x, v, 5) << endl;
     cout << "Insira o valor a ser encontrado: ";
    cin >> x;
    cout << "Posicao:" << busca_sequencial_recursiva(x, v, 5) << endl;
     cout << "Insira o valor a ser encontrado: ";
    cin >> x;
    cout << "J: " << busca_binaria2(x, v, 5) << endl;
     cout << "Insira a soma a ser encontrada: ";
    cin >> x;
    cout << soma(v, 5, x);
    
}
