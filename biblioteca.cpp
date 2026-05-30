#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
#include <locale.h>

using namespace std;

#define N 2

struct Livro{
    int codigo;
    string titulo;
    string autor;
    int qTotal;
    int qDisponivel;
};

Livro cadastrarLivro() {
    Livro y;
    cout << "\nCódigo: ";
    cin >> y.codigo;

    cout << "Título: ";
    cin.ignore();
    getline(cin, y.titulo);

    cout << "Autor: ";
    getline(cin, y.autor);

    cout << "Quantidade total de exemplares: ";
    cin >> y.qTotal;

    cout << "Quantidade disponível de exemplares: ";
    cin >> y.qDisponivel;

    return y;
}

void emprestimo(Livro livros[]) {
    int c, quant;
    bool existe = false;

    cout << "\nCódigo do livro: ";
    cin >> c;
    cout << "\nQuantidade: ";
    cin >> quant;

    for(int i = 0; i < N; i++) {
        if(livros[i].codigo == c) {
            existe = true;
            if(livros[i].qDisponivel >= quant) {
                livros[i].qDisponivel -= quant;
                cout << endl << "Empréstimo realizado com sucesso." << endl;
            } else {
                cout << endl << "Não há " << quant << " exemplares disponíveis para empréstimo." << endl;
            }
        }
    }
    if(!existe) {
        cout << endl << "Código inválido: o livro não existe na biblioteca." << endl;
    }

}

void devolucao(Livro livros[]) {
    int c, quant;
    bool existe = false;

    cout << "\nCódigo do livro: ";
    cin >> c;
    cout << "\nQuantidade: ";
    cin >> quant;

    for(int i = 0; i < N; i++) {
        if(livros[i].codigo == c) {
            existe = true;
            int maxdevolver = livros[i].qTotal - livros[i].qDisponivel;
            if(quant <= maxdevolver) {
                livros[i].qDisponivel += quant;
                cout << endl << "Devolução realizada com sucesso." << endl;
            } else {
                cout << endl << "Quantidade incompatível. Não foram emprestados " << quant << " exemplares." << endl;
            }
        }
    }
    if(!existe) {
        cout << endl << "Código inválido: o livro não existe na biblioteca." << endl;
    }
}

void consultarLivro(Livro livros[]) {
    int cod;
    bool existe = false;

    cout << "\nCódigo para consulta: ";
    cin >> cod;

    for(int i = 0; i < N; i++) {
        if(livros[i].codigo == cod) {
            existe = true;
            cout << "\nTítulo: " << livros[i].titulo << endl
                 << "Código: " << livros[i].codigo << endl
                 << "Autor: " << livros[i].autor << endl
                 << "Quantidade total de exemplares: " << livros[i].qTotal << endl
                 << "Quantidade total disponível: " << livros[i].qDisponivel << endl;
        }
    }
    if(!existe) {
        cout << endl << "Código inválido: o livro não existe na biblioteca." << endl;
    }
}

void listarLivros(Livro livros[]) {
    for(int i = 0; i < N; i++) {
        cout << endl << "Livro " << i+1 << endl;
        cout << "\nTítulo: " << livros[i].titulo << endl
                 << "Código: " << livros[i].codigo << endl
                 << "Autor: " << livros[i].autor << endl
                 << "Quantidade total de exemplares: " << livros[i].qTotal << endl
                 << "Quantidade total disponível: " << livros[i].qDisponivel << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    Livro livros[N];
    int opcao;

    cout << endl << string(50, '-') << endl;
    cout << "CADASTRO DE LIVROS" << endl;

    for(int i = 0; i < N; i++) {
        cout << endl << "Livro " << i+1 << endl;
        livros[i] = cadastrarLivro();
        cout << endl;
    }
    
    cin.ignore();
    cout << endl;

    while(true) {
        cout << endl << string(50, '-') << endl;
        cout << "MENU" << endl;
        cout << "1. Realizar empréstimo de livro" << endl;
        cout << "2. Realizar devolução de livro" << endl;
        cout << "3. Consultar dados de um livro" << endl;
        cout << "4. Listar todos os livros" << endl;
        cout << "5. Encerrar o programa" << endl;
        cout << "Digite a opção: ";
        cin >> opcao;

        cin.ignore();
        cout << endl;

        switch (opcao) {
            case 1:
                emprestimo(livros);
                break;
            case 2:
                devolucao(livros);
                break;
            case 3:
                consultarLivro(livros);
                break;
            case 4:
                listarLivros(livros);
                break;
            case 5: // Encerra o programa
                return 0;
            default:
                cout << "Erro: opção invalida!" << endl;
        }
    }
}