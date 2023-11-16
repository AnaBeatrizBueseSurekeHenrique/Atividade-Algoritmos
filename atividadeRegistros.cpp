#include <iostream>
using namespace std;
typedef struct{
    string nome;
    int idade;
    float nota;
}Aluno;

typedef struct{
    Aluno estudante;
}Curso;
int main(){
    Aluno aluno1, sala[3], *ponteiro;
    Curso estudante1;
    //exercicio 1
    cout << "Insira o nome: ";
    cin >> aluno1.nome;
    cout << "Insira a idade: ";
    cin >> aluno1.idade;
    cout << "Insira a nota: ";
    cin >> aluno1.nota;
    cout << "Nome: " << aluno1.nome << endl << "Idade: " << aluno1.idade << endl << "Nota: " << aluno1.nota << endl;
    //exercicio 2:
    for(int i = 0; i < 3; i++){
         cout << "Insira o nome: ";
        cin >> sala[i].nome;
        cout << "Insira a idade: ";
        cin >> sala[i].idade;
        cout << "Insira a nota: ";
        cin >> sala[i].nota;
    }
    for(int i = 0; i < 3; i++){
        cout << "Nome: " << sala[i].nome << endl << "Idade: " << sala[i].idade << endl << "Nota: " << sala[i].nota << endl;;
    }
    //exercicio 3
    ponteiro = &aluno1;
    cout << "Insira o nome: ";
    cin >> ponteiro->nome;
    cout << "Insira a idade: ";
    cin >> ponteiro->idade;
    cout << "Insira a nota: ";
    cin >> ponteiro->nota;
    cout << "Nome: " << aluno1.nome << endl << "Idade: " << aluno1.idade << endl << "Nota: " << aluno1.nota << endl;;
    ///exercicio 4
    cout << "Insira o nome";
    cin >> estudante1.estudante.nome;
    cout << "Insira a idade: ";
    cin >> estudante1.estudante.idade;
    cout << "Insira a nota: ";
    cin >> estudante1.estudante.nota;
    cout << "Nome: " << estudante1.estudante.nome << endl << "Idade: " << estudante1.estudante.idade << endl << "Nota: " << estudante1.estudante.nota << endl;;
    return 0;
}
