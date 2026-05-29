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


int main() {
    Aluno a;

    cout << "Digite o nome do aluno: ";
    getline(cin, a.p.nome);

    cout << "Digite o CPF do aluno: ";
    getline(cin, a.p.cpf);

    cout << "Digite o número de matrícula do aluno: ";
    getline(cin, a.matricula);

    cout << "Digite o curso do aluno: ";
    getline(cin, a.curso);
}