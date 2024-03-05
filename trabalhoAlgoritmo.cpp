#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cassert>
#define esquerda 75
#define direita 77
#define enter 13
#define cima 72
#define baixo 80

using namespace std;

typedef struct{
    float prova1;
    float prova2;
    float prova3;
    float atividades;
    float trabalhos;
    float media;
} Notas;

typedef struct {
    string nome;
    Notas nota;
} Materias;

typedef struct{
    int ano;
    char letra;
} Turma;

typedef struct{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    string nome;
    Materias notasMaterias[20];
    int faltas;
    int presencas;
    string ocorrencias;
    Data nascimento;
    Data matricula;
    string alergias;
    string doencas;
} Aluno;

typedef struct {
    int quantidade;
    Turma serie;
    Aluno alunos[100];
} TurmaGeral;

int movimentacao(int tecla, int *posicao, int altura);
void troca(Aluno *a, Aluno *b);
void bubblesort (Aluno v[], int n);
int verificarTurma(char *letra, int *numero, int numeroturma, TurmaGeral *turma);
int busca_sequencial(string x, TurmaGeral *v, int numeroturma, int *j);
float mediacalculo(float n1, float n2, float n3, float n4, float n5);
void testeMediacalculo();
int main(){
    testeMediacalculo();
    bool noMenu = true, cadastroTurma = false, cadastros = false, cadastroAluno = false, primeiraVez = true, funcionando = true, procurar = false;
    int posicao = 1, tecla = 0, numeroTurmas, numeroMaterias, i = -1, j, serie, numero, l = -1;
    char letra;
    string tela[10][2], seta[10], nome, nomeAluno;
    TurmaGeral *escola;
    while(funcionando == true){
        while(noMenu == true){
            for(int i = 0; i < 6; i++){
                for(int j = 0; j < 2; j++){
                    tela[i][j] = " ";
                }
                seta[i] = " ";
            }
            tela[0][0] = "Cadastrar turma";
            tela[1][0] = "Ver cadastros";
            tela[2][0] = "Cadastrar alunos";
            tela[3][0] = "Procurar alunos";
            tela[5][0] = "Sair";
            if(posicao == 4){
                if(tecla == cima){
                    posicao--;
                } else{
                    if(tecla == baixo){
                        posicao++;
                    }
                }
            }
            seta[posicao] = "<";
            for(int i = 0; i < 6; i++){
                for(int j = 0; j < 2; j++){
                    cout << tela[i][j];
                }
                cout << seta[i];
                cout << endl;
            }
            tecla = getch();
            if(tecla != enter){
            movimentacao(tecla, &posicao, 6);
            } else{
                noMenu = false;
                switch(posicao){
                    case 0:
                        cadastroTurma = true;
                        break;
                    case 1:
                        cadastros = true;
                        break;
                    case 2:
                        cadastroAluno = true;
                        break;
                    case 3:
                        procurar = true;
                        break;
                    default:
                        funcionando = false;
                        break;
                }
            }
            system("cls");
        }
        while(cadastroTurma == true){
            if(primeiraVez == true){
                cout << "Insira o nome da escola: ";
                getline(cin, nome);
                cout << "Insira a quantidade de turmas: ";
                cin >> numeroTurmas;
                escola = new(nothrow) TurmaGeral[numeroTurmas];
                if (escola == nullptr){
                    cout << "Falha de alocacao de memoria" << endl;
                    return -1;
                }
                cout << "Insira as materias fornecidas pela escola, escreva 'N' para parar ";
                escola[0].alunos[0].notasMaterias[0].nome = " ";
                while(i < 20 && escola[0].alunos[0].notasMaterias[i].nome != "N" && escola[0].alunos[0].notasMaterias[i].nome != "n"){
                    i++;
                    cin >> escola[0].alunos[0].notasMaterias[i].nome;
                    l++;
                }
                if(escola[0].alunos[0].notasMaterias[i].nome == "n" || escola[0].alunos[0].notasMaterias[i].nome == "N"){
                    escola[0].alunos[0].notasMaterias[i].nome = " ";
                }
                if(i >= 19){
                    cout << "Numero maximo de materias atingido.";
                }
                primeiraVez = false;
            }
            cout << endl;
            i = 0;
            while(i < numeroTurmas){
                cout << "Insira a serie da turma: ";
                cin >> escola[i].serie.ano;
                cout << "Insira a letra da turma: ";
                cin >> escola[i].serie.letra;
                i++;
            }
            cout << "Deseja cadastrar os alunos? S/N ";
            cin >> letra;
            if(letra == 'n' || letra == 'N'){
                noMenu = true;
            } else{
                cadastroAluno = true;
            }            
            cadastroTurma = false;
            system("cls");
        }
        while(cadastroAluno == true){
            if(primeiraVez == true){
                cout << "Cadastre uma turma antes de vir aqui! Aperte qualquer tecla para voltar ao menu. ";
                tecla = getch();
                cadastroAluno = false;
                noMenu = true;
                system("cls");
            } else{
                i = 0;
                j = verificarTurma(&letra, &serie, numeroTurmas, escola);
                cout << "Insira a quantidade alunos nesta turma: ";
                cin >> numero;
                if(numero > 100){
                    cout << "Numero maximo de alunos excedido, por favor, insira outro numero menor que 100. ";
                    cin >> numero;
                }
                escola[j].quantidade = numero;
                while(i < numero){    
                    cout << "Insira o nome do aluno: ";
                    cin.ignore();
                    getline(cin, escola[j].alunos[i].nome);
                    
                    cout << "Insira a data de nascimento do aluno, com espaco entre o dia mes e ano: ";
                    cin >> escola[j].alunos[i].nascimento.dia >>  escola[j].alunos[i].nascimento.mes >> escola[j].alunos[i].nascimento.ano;
                    
                    cout << "Insira a data em que foi realizada a matricula: ";
                    cin >> escola[j].alunos[i].matricula.dia >>  escola[j].alunos[i].matricula.mes >> escola[j].alunos[i].matricula.ano;
                    
                    cout << "Insira a quantidade de faltas do aluno: ";
                    cin >> escola[j].alunos[i].faltas;
                    cin.ignore();
                    
                    cout << "Insira as alergias, caso tiver. Caso nao houver, escreva N/A: ";
                    getline(cin, escola[j].alunos[i].alergias);
                    
                    cout << "Insira as doencas do aluno. Caso nao houver, escreva N/A: ";
                    getline(cin, escola[j].alunos[i].doencas);
                    
                    cout << "Insira as ocorrencias que este aluno posssui, caso nao houver, escreva N/A: ";
                    getline(cin, escola[j].alunos[i].ocorrencias);
                    
                    int k = 0;
                    while(k < l){
                        escola[j].alunos[i].notasMaterias[k].nome = escola[0].alunos[0].notasMaterias[k].nome;
                        cout << "Insira a nota da prova 1 da materia " << escola[0].alunos[0].notasMaterias[k].nome << ": ";
                        cin >> escola[j].alunos[i].notasMaterias[k].nota.prova1;
                        
                        cout << "Insira a nota da prova 2 da materia:  ";
                        cin >> escola[j].alunos[i].notasMaterias[k].nota.prova2;
                        
                        cout << "Insira a nota da prova 3 da materia: ";
                        cin >> escola[j].alunos[i].notasMaterias[k].nota.prova3;
                        
                        cout << "Insira a nota das atividades realizadas da materia: ";
                        cin >> escola[j].alunos[i].notasMaterias[k].nota.atividades;
                        
                        cout << "Insira a nota dos trabalhos realizados da materia: ";
                        cin >> escola[j].alunos[i].notasMaterias[k].nota.trabalhos;
                        
                        escola[j].alunos[i].notasMaterias[k].nota.media = mediacalculo(escola[j].alunos[i].notasMaterias[k].nota.prova1, escola[j].alunos[i].notasMaterias[k].nota.prova2, escola[j].alunos[i].notasMaterias[k].nota.prova3, escola[j].alunos[i].notasMaterias[k].nota.atividades, escola[j].alunos[i].notasMaterias[k].nota.trabalhos);       
                        k++;
                    }
                    system("cls");
                i++;
                }
                bubblesort(escola[j].alunos, numero);
                cout << "Deseja cadastrar outra turma? S/N" << endl;
                cin >> letra;
                if(letra == 'S' || letra == 's'){
                        cadastroAluno = true;
                } else{
                        cadastroAluno = false;
                        noMenu = true;
                }
                system("cls");
            }
        }
        i = 0;
        while(cadastros == true){
            if(primeiraVez == true){
                cout << "Faca cadastros antes de vir aqui! Aperte em qualquer tecla para retornar: ";
                tecla = getch();
                cadastros = false;
                noMenu = true; 
                system("cls");
            } else{
                j = 0;
                if(escola[i].alunos[0].nome.empty() == true){
                    cout << "A turma nao foi cadastrada! Pressione qualquer tecla! " << endl;
                    tecla = getch();
                    if(numeroTurmas == 1){
                        cadastros = false;
                        noMenu = true;
                        system("cls");
                        break;
                    }
                }
                while(j < escola[i].quantidade){
                    int k = 0;
                    if(escola[i].alunos[0].nome.empty() == true){
                        cout << "A turma nao foi cadastrada! Pressione qualquer tecla para voltar ou ir ate a proxima turma! " << endl;
                        tecla = getch();
                        if(numeroTurmas == 0){
                            cadastros = false;
                            noMenu = true;
                        }
                        break;
                    } else{
                        int k = 0;
                        
                        cout << nome << setw(30) << escola[i].serie.ano << " " << escola[i].serie.letra; 
                        cout << endl <<"Nome" << setw(30) << "Nascimento" << setw(30) << "Matricula" << endl;
                        cout << escola[i].alunos[j].nome << setw(20) << escola[i].alunos[j].nascimento.dia << "/"<< escola[i].alunos[j].nascimento.mes << "/" << escola[i].alunos[j].nascimento.ano << setw(30) << escola[i].alunos[j].matricula.dia << "/" << escola[i].alunos[j].matricula.mes << "/" << escola[i].alunos[j].matricula.ano << endl;
                        cout << "Faltas" << setw(30) << "Alergias" << setw(30) << "Doencas" << setw(30) << "Ocorrencias" << endl;
                        cout << escola[i].alunos[j].faltas << setw(30) << escola[i].alunos[j].alergias << setw(30) << escola[i].alunos[j].doencas << setw(30) << escola[i].alunos[j].ocorrencias << endl;
                        cout << "Notas" << endl;
                        
                        while(k < l){
                             cout << escola[i].alunos[j].notasMaterias[k].nota.media << " " << escola[i].alunos[j].notasMaterias[k].nome << " " << endl;
                             k++;
                        }
                        k = 0;
                        
                        j++;
                        cout << endl;
                    }
                }
                if(i < numeroTurmas){
                    if(i == 0 && numeroTurmas == 1){
                        cout << "Aperte qualquer tecla para voltar ao menu!" << endl;
                        tecla = getch();
                        cadastros = false;
                        noMenu = true;
                    } else{ 
                        if(i == 0){
                            cout << "Ver proxima turma? S/N" << endl;
                            cin >> letra;
                            if(letra == 'S' || letra == 's'){
                                    i++;
                            } else{
                                cadastros = false;
                                noMenu = true;
                            } 
                        } else{
                            if(i < numeroTurmas - 1){
                                cout << "Sair (0) Ver pagina anterior (1) Ver proxima pagina (2)" << endl;
                                cin >> letra;
                                if(letra == '1'){
                                    i--;
                                } else{
                                    if(letra == '2'){
                                        i++;
                                    } else{
                                    cadastros = false;
                                    noMenu = true;
                                    }
                                }
                            } else{
                                cout << "Ver turma anterior? S/N" << endl;
                                cin >> letra;
                                if(letra == 'S' || letra == 's'){
                                    i--;
                                } else{
                                    cadastros = false;
                                    noMenu = true;
                                } 
                            }
                        }
                    } 
                }
                system("cls");
            }
        } 
        while(procurar == true){
            int j = 0;
            if(primeiraVez == true){
                cout << "Cadastre alunos antes de procurar! Aperte qualquer tecla para voltar pro menu! " << endl;
                tecla = getch();
                procurar = false;
                noMenu = true;
                system("cls");
            } else{
                cout << "Insira o aluno a ser procurado: ";
                cin >> nomeAluno;
                i = busca_sequencial(nomeAluno, escola, numeroTurmas, &j);
                if(i == -1){
                    cout << "Aluno nao cadastrado! Aperte outra tecla para voltar ao menu.";
                    tecla = getch();
                    procurar = false;
                    noMenu = true;
                } else{
                    cout << nome << setw(30) << escola[i].serie.ano << setw(30) << escola[i].serie.letra << endl;
                    cout << "Nome" << setw(30) << "Nascimento" << setw(30) << "Matricula" << endl;
                    cout << escola[i].alunos[j].nome << setw(20) << escola[i].alunos[j].nascimento.dia << "/"<< escola[i].alunos[j].nascimento.mes << "/" << escola[i].alunos[j].nascimento.ano << setw(30) << escola[i].alunos[j].matricula.dia << "/" << escola[i].alunos[j].matricula.mes << "/" << escola[i].alunos[j].matricula.ano << endl;
                    cout << "Faltas" << setw(30) << "Alergias" << setw(30) << "Doencas" << setw(30) << "Ocorrencias" << endl;
                    cout << escola[i].alunos[j].faltas << setw(30) << escola[i].alunos[j].alergias << setw(20) << escola[i].alunos[j].doencas << setw(20) << escola[i].alunos[j].ocorrencias << endl;
                    cout << "Notas" << endl << endl;
                    int k = 0;
                    while(k < l){
                        cout << escola[i].alunos[j].notasMaterias[k].nota.media << setw(30) << escola[i].alunos[j].notasMaterias[k].nome << endl;
                        k++;
                    }
                }
                cout << endl << "Deseja procurar outros alunos? S/N: ";
                cin >> letra;
                if(letra == 'n' || letra == 'N'){
                    procurar = false;
                    noMenu = true;
                }
            }
            system("cls");    
        }
    }

    delete escola;
    escola = NULL;
    return 0;
}

void troca(Aluno *a, Aluno *b){
    float aux;
    int aux2;
    int i = 0;
    string c;
    
    c = a->nome;
    a->nome = b->nome;
    b->nome = c;
    while(a->notasMaterias[i].nome != " " && i < 20){
        aux = a->notasMaterias[i].nota.prova1;
        a->notasMaterias[i].nota.prova1 = b->notasMaterias[i].nota.prova1;
        aux = b->notasMaterias[i].nota.prova1;

        aux = a->notasMaterias[i].nota.prova2;
        a->notasMaterias[i].nota.prova2 = b->notasMaterias[i].nota.prova2;
        aux = b->notasMaterias[i].nota.prova2;

        aux = a->notasMaterias[i].nota.prova3;
        a->notasMaterias[i].nota.prova1 = b->notasMaterias[i].nota.prova3;
        aux = b->notasMaterias[i].nota.prova3;

        aux = a->notasMaterias[i].nota.atividades;
        a->notasMaterias[i].nota.atividades = b->notasMaterias[i].nota.atividades;
        aux = b->notasMaterias[i].nota.atividades;

        aux = a->notasMaterias[i].nota.trabalhos;
        a->notasMaterias[i].nota.trabalhos = b->notasMaterias[i].nota.trabalhos;
        aux = b->notasMaterias[i].nota.trabalhos;

        aux = a->notasMaterias[i].nota.media;
        a->notasMaterias[i].nota.media = b->notasMaterias[i].nota.media;
        b->notasMaterias[i].nota.media = aux;
        i++;
    }
    aux2 = a->faltas;
    a->faltas = b->faltas;
    b->faltas = aux2;

    c = a->ocorrencias;
    a->ocorrencias = b->ocorrencias;
    b-> ocorrencias = c;

    aux2 = a->matricula.dia;
    a->matricula.dia = b->matricula.dia;
    b->matricula.dia = aux2;
    aux2 = a->matricula.mes;
    a->matricula.mes = b->matricula.mes;
    b->matricula.mes = aux2;

    aux2 = a->matricula.ano;
    a->matricula.ano = b->matricula.ano;
    b->matricula.ano = aux2;

    aux2 = a->nascimento.dia;
    a->nascimento.dia = b->nascimento.dia;
    b->nascimento.dia = aux2;

    aux2 = a->nascimento.mes;
    a->nascimento.mes = b->nascimento.mes;
    b->nascimento.mes = aux2;

    aux2 = a->nascimento.ano;
    a->nascimento.ano = b->nascimento.ano;
    b->nascimento.ano = aux2;

    c = a->alergias;
    a->alergias = b->alergias;
    b->alergias = c;

    c = a->doencas;
    a->doencas = b->doencas;
    b->doencas = c;
    
}
void bubblesort (Aluno v[], int n){
    int i, j, menor;
    for (i = n - 1; i > 0; i--){
        for (j = 0; j < i; j++){
            if (tolower(v[j].nome[0]) > tolower(v[j+1].nome[0])){
                troca (&v[j], &v[j+1]);
            } else{
                if(tolower(v[j].nome[0] == tolower(v[j+1].nome[0]))){
                    int k = 0;
                    if(v[j+1].nome.size() < v[j].nome.size()){
                        menor = v[j+1].nome.size();
                    } else{
                        menor = v[j].nome.size();
                    }
                    while(tolower(v[j].nome[k] == tolower(v[j+1].nome[k] && k < menor))){
                        k++;
                    }
                    if(v[j].nome[k] > v[j+1].nome[k]){
                        troca(&v[j], &v[j+1]);
                    }
                }
            }
        }
    }
}

int movimentacao(int tecla, int *posicao, int altura){
    switch(tecla){
        case cima:
            if(*posicao > 0)
            (*posicao)--;
            break;
        case baixo:
            if(*posicao < altura - 1){
                (*posicao)++;
            }
            break;
        }
    return (*posicao);
}

int verificarTurma(char *letra, int *numero, int numeroturma, TurmaGeral *turma){
    int j = 0;
    cout << "Insira a serie da turma cujos alunos serão cadastrados: ";
    cin >> *numero;
    cout << "Insira a letra da turma: ";
    cin >> *letra;
    while(((turma[j].serie.letra != *letra) || (turma[j].serie.ano != *numero)) && j < numeroturma){
        j++;
    }
    if(j >= numeroturma){
        cout << "Turma invalida, escreva uma turma valida: " << endl;
        verificarTurma(letra,numero, numeroturma, turma);
    }
    return j;
}

int busca_sequencial(string x, TurmaGeral *v, int numeroturma, int *j) {
    for(int i = 0; i < numeroturma; i++){
        *j = 0;
        while((v[i].alunos[*j].nome.empty() == false)){
            if(v[i].alunos[*j].nome == x){
                return i;
            }
            (*j)++;
        }
    }
 return -1;
}

float mediacalculo(float n1, float n2, float n3, float n4, float n5){
    return (n1+n2+n3+n4+n5)/5;
}

void testeMediacalculo(){
    assert(mediacalculo(5, 5, 5, 5, 5) == 5);
    assert(mediacalculo(7, 7, 7, 7, 7) == 7);
}
