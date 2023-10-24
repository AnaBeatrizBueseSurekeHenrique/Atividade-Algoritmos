#include <iostream>

using namespace std;

int dobrar(int* p);
int vogal(string palavra);
void inverter();

int main(){
    string palavra;
    //exercicio 1;
    int a = 1, b = 2, *pontA, *pontB, c;
    pontA = &a;
    pontB = &b;
    c = a;
    *pontA = *pontB;
    *pontB = c;
    cout << "As variaveis invertidas: " << a << " e " << b << endl;
    //exercicio 2;
    int V[8], *ponteiro[8];
    for(int i = 0; i < 8; i++){
        V[i] = i+ 1;
    }
    for(int i = 0; i < 8; i++){
        ponteiro[i] = &V[i];
    }
    for(int i = 0; i < 8; i++){
        cout << *ponteiro[i] << " ";
    } 
    cout << endl;
    //exercicio 3
    int inteiro, *pont;
    cout << "Insira um valor inteiro, para dobrarmos: ";
    cin >> inteiro;
    pont = &inteiro;
    dobrar(pont);
    cout << "O valor dobrado da variavel =" << *pont << endl;
    // exercicio 4;
    cout << "Insira uma palavra para calcularmos o numero de suas vogais: ";
    cin >> palavra;
    cout << vogal(palavra) << endl;
    //exercicio 5;
    cout << "Insira uma palavra para invertermos: ";
    inverter();
    return 0;
}

int dobrar(int* p){
    *p = *p * 2;
    return *p;
}
int vogal(string palavra){
    int *numero, vogal = 0, i = 0;
    numero = &vogal;
    while(palavra[i] != '\0'){
        switch(palavra[i]){
            case 'a':
                vogal++;
                break;
            case 'e':
                vogal++;
                break;
            case 'i':
                vogal++;
                break;
            case 'o':
                vogal++;
                break;
            case 'u':
                vogal++;
                break;
        }
        i++;
    }
    return *numero;
}

void inverter(){
    string palavra;
    int j = 0, letras, k = 0;
    cin >> palavra;
    while(palavra[j] != '\0'){
        j++;
    } 
    char vPalavra[j], *pont[j];
   for(int i = 0; i < j; i++){
    vPalavra[i] = palavra[i];
   }
   for(int i = j - 1; i >= 0; i--){
    pont[k] = &vPalavra[i];
    k++;
   }
   for(int i = 0; i < j; i++){
    cout << *pont[i];
   }
}