#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Data {
    int dia, mes, ano;
};

struct Aluno {
    Pessoa p;
    string curso;
    string matricula;
};

struct Pessoa {
    string nome;
    string cpf;
    Data data_nasc;
};

Aluno ler_aluno() {
    Aluno fulano;

    cout << "Digite o nome do aluno: ";
    getline(cin, fulano.p.nome);

    cout << "Digite o CPF do aluno: ";
    getline(cin, fulano.p.cpf);

    cout << "Digite o número de matrícula do aluno: ";
    getline(cin, fulano.matricula);

    cout << "Digite o curso do aluno: ";
    getline(cin, fulano.curso);
}

int main() {
    Aluno a;

}