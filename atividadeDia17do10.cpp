#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;
void menorSoma();
bool bissexto(int ano);
string numeroBinario(int numero);
int binario(int numero);
string senhaValida(string senha);
float juros(float dinheiro, float taxa, int anos);
void ordemCrescente();
int main(){ 
    int anos, numero;
    bool anoBissexto;
    string senha;
    float taxa, dinheiro;
    menorSoma();
    cout << "Insira o ano para verificarmos se ele e bissexto: ";
    cin >> anos;
    anoBissexto = bissexto(anos);
    if(anoBissexto == true){
        cout << "E bissexto" << endl;
    } else{
        cout << "Nao e bissexto" << endl;
    }
    cout << "Insira o numero que sera transformado em binario: ";
    cin >> numero;
    cout << numeroBinario(numero);
    cout << "Insira uma senha para validarmos: ";
    getline(cin, senha);
    cout << senhaValida(senha) << endl;
    cout << "Insira o valor que sera investido: ";
    cin >> dinheiro;
    cout << "Insira, em porcentagem, a taxa anual de juros: ";
    cin >> taxa;
    cout << "Insira o numero de anos do investimento: ";
    cin >> anos;
    cout << "O valor final sera: " << fixed << setprecision(2) << juros(dinheiro, taxa, anos) << endl;
    ordemCrescente();

    return 0;
}
void menorSoma(){
    int numero, soma = 0;
    cout << "Insira o numero: ";
    cin >> numero;
    for(int i = numero; i > 0; i--){
        soma += i;
    }
    cout << "Soma dos inteiros positivos menores ou iguais ao numero: " << soma << endl;
}
bool bissexto(int ano){
    if(ano % 4 == 0){
        if(ano % 100 != 0){
            return true;
        } else{
            return false;
        }
    } else{
        if(ano % 400 == 0){
            return true;
        } else{
            return false;
        }
    }
}
string numeroBinario(int numero){
    int divisao = INT_MAX;
    string binario = "", numeroBinario = "";
    while(divisao >= 2){
        divisao = numero/2;
        if(numero % 2 == 0){
            binario += "0";
        } else{
            binario += "1";
        }
        numero = divisao;
    }
    binario += to_string(numero);
    for(int i = binario.size() - 1; i >= 0; i--){
        numeroBinario += binario[i];
    }
    return numeroBinario;
}
string senhaValida(string senha){
    bool maiuscula = false, minuscula = false, numero = false;
    int letras = 0;
            while(senha[letras] != '\0'){
                if('0' <= senha[letras] <= '9' && numero == false){
                    numero = true;
                } else{
                    if('a' <= senha[letras] <= 'z' && minuscula == false){
                        minuscula = true;
                    } else{
                        if('A' <= senha[letras] <= 'Z' && maiuscula == false){
                            maiuscula = true;
                        }
                    }
                }
                letras++;
            }
    if(maiuscula == true && maiuscula == true && numero == true && letras >= 8){
        return "Senha valida";
    } else{
        return "Senha invalida";
    }

}
float juros(float dinheiro, float taxa, int anos){
    float potencia = 1;
    for(int i = 0; i < anos; i++){
        potencia = potencia * (1+(taxa/100));
    }
    return dinheiro + potencia;
}
void ordemCrescente(){
    int tamanho, aux, menor = INT_MAX, j = 0;
    cout << "Insira o tamanho do vetor: ";
    cin >> tamanho;
    cout << "Insira os valores do vetor: ";
    int V[tamanho];
    for(int i = 0; i < tamanho; i++){
        cin >> V[i];
    }
    for(int i = 0; i < tamanho; i++){
        for(int j = i; j < tamanho; j++){
            if(V[i] > V[j]){
                aux = V[i];
                V[i] = V[j];
                V[j] = aux;
            }
        }
    }
    for(int i = 0; i < tamanho; i++){
        cout << V[i];
    }
}