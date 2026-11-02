
#include <iostream>
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

// Inserir um código na BST
No* inserir(No* raiz, int x) {

    if (raiz == nullptr) {
        return new No(x);
    }

    if (x < raiz->chave) {
        raiz->esquerda = inserir(raiz->esquerda, x);
    }
    else if (x > raiz->chave) {
        raiz->direita = inserir(raiz->direita, x);
    }

    return raiz;
}

// Buscar um código na BST
bool buscar(No* raiz, int x) {

    if (raiz == nullptr) {
        return false;
    }

    if (x == raiz->chave) {
        return true;
    }

    if (x < raiz->chave) {
        return buscar(raiz->esquerda, x);
    }

    return buscar(raiz->direita, x);
}

// Encontrar o menor nó de uma subárvore
No* menorNo(No* raiz) {

    while (raiz != nullptr && raiz->esquerda != nullptr) {
        raiz = raiz->esquerda;
    }

    return raiz;
}

// Remover um código da BST
No* remover(No* raiz, int x) {

    if (raiz == nullptr) {
        return nullptr;
    }

    if (x < raiz->chave) {
        raiz->esquerda = remover(raiz->esquerda, x);
    }
    else if (x > raiz->chave) {
        raiz->direita = remover(raiz->direita, x);
    }
    else {

        // Nó sem filho esquerdo
        if (raiz->esquerda == nullptr) {
            No* temp = raiz->direita;
            delete raiz;
            return temp;
        }

        // Nó sem filho direito
        if (raiz->direita == nullptr) {
            No* temp = raiz->esquerda;
            delete raiz;
            return temp;
        }

        // Nó com dois filhos: usa o sucessor
        No* sucessor = menorNo(raiz->direita);

        raiz->chave = sucessor->chave;

        raiz->direita = remover(raiz->direita, sucessor->chave);
    }

    return raiz;
}

// Consulta por faixa [a, b]
void consultarFaixa(No* raiz, int a, int b, bool& encontrou) {

    if (raiz == nullptr) {
        return;
    }

    // Visita a esquerda somente se puder ter valores >= a
    if (raiz->chave > a) {
        consultarFaixa(raiz->esquerda, a, b, encontrou);
    }

    // Imprime se estiver dentro do intervalo
    if (raiz->chave >= a && raiz->chave <= b) {

        if (encontrou) {
            cout << " ";
        }

        cout << raiz->chave;
        encontrou = true;
    }

    // Visita a direita somente se puder ter valores <= b
    if (raiz->chave < b) {
        consultarFaixa(raiz->direita, a, b, encontrou);
    }
}

// Liberar memória
void liberar(No* raiz) {

    if (raiz == nullptr) {
        return;
    }

    liberar(raiz->esquerda);
    liberar(raiz->direita);

    delete raiz;
}

int main() {

    No* raiz = nullptr;

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {

        char comando;
        cin >> comando;

        if (comando == 'I') {

            int x;
            cin >> x;

            raiz = inserir(raiz, x);
        }

        else if (comando == 'R') {

            int x;
            cin >> x;

            raiz = remover(raiz, x);
        }

        else if (comando == 'B') {

            int x;
            cin >> x;

            if (buscar(raiz, x)) {
                cout << "SIM" << endl;
            }
            else {
                cout << "NAO" << endl;
            }
        }

        else if (comando == 'F') {

            int a, b;
            cin >> a >> b;

            bool encontrou = false;

            consultarFaixa(raiz, a, b, encontrou);

            if (!encontrou) {
                cout << "VAZIA";
            }

            cout << endl;
        }
    }

    liberar(raiz);

    return 0;
}
