#include <iostream>
#include <cctype>

using namespace std;
int multiplicarValor(int a, int b);
int multiplicarReferencia(int* a, int* b);
int porvalor10 (int a);
int porreferencia10 (int* a);
int porValorMenos5 (int b);
int porReferenciaMenos5 (int* b);
void inverterReferencia(int *ponteiro);
string maiusculo(string* palavra, int tamanho, char V[]);
int main(){
    cout << "exercicio 1" << endl;
    int a, b, M[10], *pont[10], tamanho;
    string palavra;
    cin >> a >> b;
    cout << multiplicarValor(a, b) << endl;
    cout << "exercicio 2" << endl;
    cout << multiplicarReferencia(&a, &b) << endl;
    cout << "exercicio 3" << endl;
    cout << porvalor10(a) << endl;
    cout << "exercicio 4" << endl;
    cout << porreferencia10(&a) << endl;
    cout << "exercicio 5" << endl;
    cout << porValorMenos5(b) << endl;
   cout << "exercicio 6" << endl;
    cout << porReferenciaMenos5(&b) << endl;
    cout << "exercicio 7" << endl;
    for(int j = 0; j < 10; j++){
       pont[j] = &M[j];
    }
    inverterReferencia(*pont);
    for(int i = 0; i < 10; i++){
        cout << M[i] << endl;
    }
    cout << "exercicio 8" << endl;
    cin >> palavra;
    tamanho = palavra.size();
    char V[tamanho];
    int i = 0;
    while(i < tamanho){
        V[i] = palavra[i];
        i++;
    }
    maiusculo(&palavra,tamanho, V);
    cout << palavra;
   
}

int multiplicarValor(int a, int b){
    return a*b;
}
int multiplicarReferencia(int *a, int *b){
    int multiplicar;
    multiplicar = *a * *b;
    return multiplicar;
}
int porvalor10(int a){
    a += 10;
    return a;
}
int porreferencia10(int* a){
    *a += 10;
    return *a;
}
int porValorMenos5(int b){
    b -= 5;
    return b;
}
int porReferenciaMenos5(int* b){
    *b -= 5;
    return *b;
} 

void inverterReferencia(int* ponteiro){
    int V[10], A[10], k =0;
    for(int i = 0; i < 10; i++){
        V[i] = i+1;
    }
    for(int j = 9; j >= 0; j--){
        A[k] = V[j];
        k++;
    }
    for(int i = 0; i < 10; i++){
        ponteiro[i] = A[i];
    }
}
string maiusculo(string* palavra, int tamanho, char V[]){
    *palavra = "";
    for(int i = 0; i < tamanho; i++){
        *palavra += toupper(V[i]);
    }
    return *palavra;
}