
#include <iostream>
#include <vector>
using namespace std;

struct No {
    int chave;
    No* esquerda;
    No* direita;

    No(int valor) {
        chave = valor;
        esquerda = nullptr;
        direita = nullptr;
    }
};

// Inserção na bst original
No* inserir(No* raiz, int valor) {

    if (raiz == nullptr) {
        return new No(valor);
    }

    if (valor < raiz->chave) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }
    else if (valor > raiz->chave) {
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;
}

// Calcula a altura da árvore
int altura(No* raiz) {

    if (raiz == nullptr) {
        return 0;
    }

    int altEsq = altura(raiz->esquerda);
    int altDir = altura(raiz->direita);

    return 1 + max(altEsq, altDir);
}

// Percurso em ordem para obter as chaves ordenadas
void emOrdem(No* raiz, vector<int>& chaves) {

    if (raiz == nullptr) {
        return;
    }

    emOrdem(raiz->esquerda, chaves);
    chaves.push_back(raiz->chave);
    emOrdem(raiz->direita, chaves);
}

// Constrói a árvore balanceada
No* construirBalanceada(vector<int>& chaves, int l, int r) {

    if (l > r) {
        return nullptr;
    }

    int meio = (l + r) / 2;

    No* raiz = new No(chaves[meio]);

    raiz->esquerda = construirBalanceada(chaves, l, meio - 1);
    raiz->direita = construirBalanceada(chaves, meio + 1, r);

    return raiz;
}

// Imprime a pré-ordem
void preOrdem(No* raiz) {

    if (raiz == nullptr) {
        return;
    }

    cout << raiz->chave << " ";
    preOrdem(raiz->esquerda);
    preOrdem(raiz->direita);
}

// Libera a memória
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
    cin >> n;

    No* original = nullptr;

    for (int i = 0; i < n; i++) {
        int valor;
        cin >> valor;
        original = inserir(original, valor);
    }

    // Altura da árvore original
    int alturaOriginal = altura(original);

    // Extrai as chaves em ordem crescente
    vector<int> chaves;
    emOrdem(original, chaves);

    // Constrói a nova árvore balanceada
    No* balanceada = construirBalanceada(chaves, 0, (int)chaves.size() - 1);

    // Primeira linha: pré-ordem
    preOrdem(balanceada);
    cout << endl;

    // Segunda linha: alturas
    cout << alturaOriginal << " " << altura(balanceada) << endl;

    liberar(original);
    liberar(balanceada);

    return 0;
}
