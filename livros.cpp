/*
Após o usuário cadastrar 5 livros em um vetor de livros, 
o programa deve mostrar o livro mais caro, calcular a 
média de preços e listar apenas os livros com mais de 300 páginas
*/
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;
const int q = 5;

struct Livro {
    string titulo;
    string autor;
    int paginas;
    float preco;
};

Livro cadastrarLivro() {
    Livro l;
    cout << "Título do livro: ";
    cin.ignore();
    getline(cin, l.titulo);
    cout << "Nome do autor: ";
    cin.ignore();
    getline(cin, l.autor);
    cout << "Quantidade de páginas: ";
    cin >> l.paginas;
    cout << "Preço: R$";
    cin >> l.preco;
    
    return l;
}

Livro maisCaro(Livro livros[], int quantos) {
    Livro x = livros[0];
    for(int i = 1; i < quantos; i++) {
        if(x.preco < livros[i].preco) {
            x = livros[i];        
        }
    }
    return x;
}

float mediaPrecos(Livro livros[], int quantos) {
    float soma = 0.0;
    for(int i = 0; i < quantos; i++) {
        soma += livros[i].preco;
    }

    return (soma/(float)quantos);
}

void trezentasPag(Livro livros[], int quantos) {
    bool existe = false;
    cout << "Livros com +300 páginas: " << endl;
    for(int i = 0; i < quantos; i++) {
        if(livros[i].paginas > 300) {
            cout << endl << "Título: " << livros[i].titulo 
                << endl << "Autor: " << livros[i].autor
                << endl << "Páginas: " << livros[i].paginas
                << endl << "Preço: R$" << setprecision(2) << livros[i].preco << endl;
            existe = true;
        }
    }
    if(!existe)
        cout << "\nNão foram encontrados livros com +300 páginas." << endl;
}

int main() {
    Livro livros[q];
    Livro mc;

    for(int i = 0; i < q; i++) {
        cout << "\nLivro " << i+1 << endl;
        livros[i] = cadastrarLivro();
        cout << string(50, '_');
    }

    cout << string(50, '_');
    trezentasPag(livros, q);
    cout << string(50, '_');

    mc = maisCaro(livros, q);
    cout << endl << "O livro mais caro é: " << mc.titulo 
         << endl << "Autor: " << mc.autor
         << endl << "Páginas: " << mc.paginas
         << endl << "Preço: R$" << setprecision(2) << mc.preco;

    cout << "\nMédia: "
}