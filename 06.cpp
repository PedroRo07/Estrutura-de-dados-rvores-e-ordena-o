
#include <iostream>
using namespace std;

struct No {
    int valor;
    No* esquerda;
    No* direita;

    No(int v) {
        valor = v;
        esquerda = nullptr;
        direita = nullptr;
    }
};

// Insere um valor na BST
No* inserir(No* raiz, int valor) {
    if (raiz == nullptr) {
        return new No(valor);
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }
    else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;
}

// Encontra o sucessor em ordem
No* encontrarSucessor(No* no) {
    No* atual = no->direita;

    while (atual->esquerda != nullptr) {
        atual = atual->esquerda;
    }

    return atual;
}

// Remove um valor da BST
No* remover(No* raiz, int valor) {
    if (raiz == nullptr) {
        return nullptr;
    }

    if (valor < raiz->valor) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    }
    else if (valor > raiz->valor) {
        raiz->direita = remover(raiz->direita, valor);
    }
    else {
        // Caso 1: no sem filhos
        if (raiz->esquerda == nullptr &&
            raiz->direita == nullptr) {
            delete raiz;
            return nullptr;
        }

        // Caso 2: no com um filho
        if (raiz->esquerda == nullptr) {
            No* temp = raiz->direita;
            delete raiz;
            return temp;
        }

        if (raiz->direita == nullptr) {
            No* temp = raiz->esquerda;
            delete raiz;
            return temp;
        }

        // Caso 3: no com dois filhos
        No* sucessor = encontrarSucessor(raiz);

        raiz->valor = sucessor->valor;

        raiz->direita = remover(
            raiz->direita, sucessor->valor
        );
    }

    return raiz;
}

// Percurso em pre-ordem
void preOrdem(No* raiz) {
    if (raiz == nullptr) {
        return;
    }

    cout << raiz->valor << " ";

    preOrdem(raiz->esquerda);
    preOrdem(raiz->direita);
}

// Libera a memoria da arvore
void liberar(No* raiz) {
    if (raiz == nullptr) {
        return;
    }

    liberar(raiz->esquerda);
    liberar(raiz->direita);

    delete raiz;
}

int main() {
    int n;
    No* raiz = nullptr;

    // Quantidade de elementos
    cerr << "Informe a quantidade de valores da arvore: ";
    cin >> n;

    // Insercao dos valores
    cerr << "Insira " << n << " valores para construir a BST:\n";

    for (int i = 0; i < n; i++) {
        int valor;

        cerr << "Insira o valor " << i + 1 << ": ";
        cin >> valor;

        raiz = inserir(raiz, valor);
    }

    // Quantidade de remocoes
    int q;

    cerr << "\nQuantos valores deseja remover? ";
    cin >> q;

    // Remocao dos valores
    for (int i = 0; i < q; i++) {
        int valor;

        cerr << "Informe o valor " << i + 1
             << " que deseja remover: ";

        cin >> valor;

        raiz = remover(raiz, valor);
    }

    // Resultado final
    cout << "\nPercurso em pre-ordem:\n";

    preOrdem(raiz);

    cout << endl;

    liberar(raiz);

    return 0;
}
