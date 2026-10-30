
#include <iostream>
#include <algorithm>
#include <cmath>
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

// Insere um valor na arvore
No* inserir(No* raiz, int valor) {
    if (valor == 0) {
        return nullptr;
    }

    if (raiz == nullptr) {
        raiz = new No(valor);
    }

    return raiz;
}

// Calcula a altura e verifica o balanceamento
int verificarBalanceamento(No* raiz, int& maiorDesequilibrio) {
    if (raiz == nullptr) {
        return 0;
    }

    int alturaEsquerda =
        verificarBalanceamento(raiz->esquerda, maiorDesequilibrio);

    int alturaDireita =
        verificarBalanceamento(raiz->direita, maiorDesequilibrio);

    int diferenca = abs(alturaEsquerda - alturaDireita);

    maiorDesequilibrio = max(maiorDesequilibrio, diferenca);

    return 1 + max(alturaEsquerda, alturaDireita);
}

int main() {
    int n;

    cout << "Insira a quantidade de nos da arvore: ";
    cin >> n;

    No* raiz = nullptr;

    if (n == 0) {
        cout << "SIM" << endl;
        cout << "0" << endl;
        return 0;
    }

    cout << "Insira os valores dos nos:" << endl;

    // Esta estrutura considera os nos na ordem de uma arvore
    // representada por indices: raiz, filho esquerdo e filho direito.

    int* valores = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Insira o valor do no " << i + 1 << ": ";
        cin >> valores[i];
    }

    // Montagem da arvore binaria
    No** nos = new No*[n];

    for (int i = 0; i < n; i++) {
        if (valores[i] == 0) {
            nos[i] = nullptr;
        } else {
            nos[i] = new No(valores[i]);
        }
    }

    raiz = nos[0];

    for (int i = 0; i < n; i++) {
        if (nos[i] != nullptr) {
            int esquerdo = 2 * i + 1;
            int direito = 2 * i + 2;

            if (esquerdo < n)
                nos[i]->esquerda = nos[esquerdo];

            if (direito < n)
                nos[i]->direita = nos[direito];
        }
    }

    int maiorDesequilibrio = 0;

    verificarBalanceamento(raiz, maiorDesequilibrio);

    if (maiorDesequilibrio <= 1) {
        cout << "SIM" << endl;
    } else {
        cout << "NAO" << endl;
    }

    cout << maiorDesequilibrio << endl;

    delete[] valores;
    delete[] nos;

    return 0;
}
