
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, r;

    cout << "Digite a quantidade de nos e a raiz: ";
    cin >> n >> r;

    vector<int> esquerda(n + 1);
    vector<int> direita(n + 1);

    cout << "\nDigite os filhos esquerdo e direito de cada no:\n";

    for (int i = 1; i <= n; i++) {
        cout << "No " << i << " (esquerdo direito): ";
        cin >> esquerda[i] >> direita[i];
    }

    // ARVORE VAZIA
    if (n == 0 || r == 0) {
        cout << "\nAltura e largura maxima: -1 0\n";
        return 0;
    }

    // BUSCA EM LARGURA
    queue<int> fila;
    fila.push(r);

    int altura = 0;
    int larguraMax = 0;

    while (!fila.empty()) {

        int tamanho = fila.size();

        // ATUALIZAR LARGURA MAXIMA
        if (tamanho > larguraMax) {
            larguraMax = tamanho;
        }

        // PERCORRER OS NOS DO NIVEL
        for (int i = 0; i < tamanho; i++) {

            int atual = fila.front();
            fila.pop();

            if (esquerda[atual] != 0) {
                fila.push(esquerda[atual]);
            }

            if (direita[atual] != 0) {
                fila.push(direita[atual]);
            }
        }

        altura++;
    }

    // RESULTADO
    cout << "\nAltura e largura maxima: ";
    cout << altura << " " << larguraMax << "\n";

    return 0;
}
