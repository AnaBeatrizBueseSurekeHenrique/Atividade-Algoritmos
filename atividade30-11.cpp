#include <iostream>
#include "exercicio7.cpp"


using namespace std;

static int varEstatica;
int global;
extern void trocarVal();
void incrementar(){
    varEstatica++;
    cout << varEstatica << endl;
}
void incrementarRegis(){
    register int regis;
    regis++;
    cout << "Valor:" << regis;
}
int main(){
    // exercicio 1
    int numero = 11, n2 = 13;
    int *pont1, *pont2;
    pont1 = &numero;
    pont1++;
    pont1--;
    cout << "Exercicio 1: " << pont1 << endl;
    //exercicio 2
    pont1 + 2;
    cout << "Exercicio 2: " << pont1 << endl;
    // exercicio 3
    cout << "Exercicio 3: ";
    pont1 - 2;
    cout << pont1 << endl;
    //exercicio 4
    pont2 = &n2;
    cout << "Exercicio 4: nao e possivel fazer operacoes entre ponteiros" << endl;
    //exercicio 5
    cout << "Exercicio 5: ";
    if(*pont1 > *pont2){
        cout << "Conteudo do Pont1 maior" << endl;
    } else{
        cout << "Conteudo do Pont2 maior" << endl;
    }
    //exercicio 6
    cout << "Exericico 6: ";
    incrementar();
    incrementar();
    incrementar();
    incrementar();
    cout << "Valor final: " << varEstatica << endl;
    //exercicio 7
    cout << "Exercicio 7: ";
    trocarVal();
    cout << global << endl;
    //exercico 8
    cout << "Exercicio 8: ";
    incrementarRegis();
    incrementarRegis();
    incrementarRegis();
    incrementarRegis();
    incrementarRegis();
    //exercio 9
    cout << endl << "Exercicio 9: ";
    int v[4] = {0,1,2,3};
    int *p;
    p = v;
    for(int i = 0; i < 4; i++){
        cout << *(p+i) << " ";
    }
    // exercicio 10:
    cout << endl << "Exercicio 10: ";
    if(pont1 > pont2){
        cout << numero << " esta em um endereco mais alto";
    } else{
        cout << n2 << " esta em um endereco mais alto";
    }
    }