#include <iostream>
using namespace std;
/*Modifique o programa anterior, 
incluindo o nome, série e nota de cada aluno 
(defina
uma struct com esses campos). Faça as alterações 
necessárias, a fim de que as
informações sejam preenchidas e calculada a média 
aritmética da turma*/
typedef struct{
    string nome;
    int serie;
    float nota;
} Aluno;

void lerNotas(int tamanho, float notas[]);
void lerNotas2(int tamanho, float *notas);
void media(int tamanho, float *pont);
void media2(int tamanho, float *pont);
void lerAluno(Aluno *alunos, int tamanho);
void mediaA(Aluno *alunos, int tamanho);
int main(){
    //A
    int n, *pont;
    cout << "Insira o valor do vetor: ";
    cin >> n;
    pont = new(nothrow) int[n];
    if (pont == nullptr){
        cout << "Falha de alocacao de memoria" << endl;
        return -1;
    }
    for(int i = 0; i < n; i++){
        pont[i] = i;
    }
    for(int i = 0; i < n; i++){
        cout << pont[i] << " ";
    }
    delete pont;
    pont = NULL;
    cout << endl;
    //B
    int *ponteiro;
    cout << "Insira o valor do vetor: ";
    cin >> n;
    ponteiro = new int[n];
    if (ponteiro == nullptr){
        cout << "Falha de alocacao de memoria" << endl;
        return -1;
    }
    for(int i = 0; i < n; i++){
        *(ponteiro+i) = i;
    }
    for(int i = 0; i < n; i++){
        cout << *(ponteiro+i) << " ";
    }
    delete ponteiro;
    ponteiro = NULL;
    cout << endl;
    // C
    int qalunos;
    cout << "Insira a quantidade de alunos: ";
    cin >> qalunos;
    float *pv = new float[qalunos];
    if (pv == nullptr){
        cout << "Falha de alocacao de memoria" << endl;
        return -1;
    }
    lerNotas(qalunos, pv);
    media(qalunos, pv);
    delete pv;
    pv = NULL;
    // D
    int alunos2;
    cout << "Insira a quantidade de alunos: ";
    cin >> alunos2;
    float *pv2 = new float[alunos2];
    if (pv2 == nullptr){
        cout << "Falha de alocacao de memoria" << endl;
        return -1;
    }
    lerNotas2(alunos2, pv2);
    media2(alunos2, pv2);
    delete pv2;
    pv2 = NULL;
    // E
    int quantidade;
    cout << "Insira a quantidade de alunos: ";
    cin >> quantidade;
    Aluno *ponte = new Aluno[quantidade];
    if (ponte == nullptr){
        cout << "Falha de alocacao de memoria" << endl;
        return -1;
    }
    lerAluno(ponte, quantidade);
    mediaA(ponte, quantidade);
}
void lerNotas(int tamanho, float notas[]){
    for(int i = 0; i < tamanho; i++){
        cin >> notas[i];
    }
}
void lerNotas2(int tamanho, float *notas){
    for(int i = 0; i < tamanho; i++){
        cin >> *(notas+i);
    }
}

void media(int tamanho, float pont[]){
    float soma = 0;
    for(int i = 0; i < tamanho; i++){
        soma += pont[i];
    }
    cout << "Media das notas: " << soma/tamanho << endl;
}
void media2(int tamanho, float *pont){
    float soma = 0;
    for(int i = 0; i < tamanho; i++){
        soma += *(pont+i);
    }
    cout << "Media das notas: " << soma/tamanho << endl;
}

void lerAluno(Aluno *alunos, int tamanho){
    for(int i = 0 ; i < tamanho; i++){
        cout << "Insira o nome: ";
        cin>> alunos[i].nome;
        cout << "Insira a serie: ";
        cin >> alunos[i].serie;
        cout << "Insira a nota: ";
        cin >> alunos[i].nota;
    }
}

void mediaA(Aluno *alunos, int tamanho){
    float soma = 0;
    for(int i = 0; i < tamanho; i++){
        soma += alunos[i].nota;
    }
    cout << "Media das notas: " << soma/tamanho << endl;
}