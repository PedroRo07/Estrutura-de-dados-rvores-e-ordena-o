/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

mt19937 gerador(42); // Semente fixa para os testes

void quickSort(vector<int>& v, int inicio, int fim) {

    while (inicio < fim) {

        // Escolhe um pivô aleatório
        uniform_int_distribution<int> dist(inicio, fim);
        int pivo = v[dist(gerador)];

        int menor = inicio;
        int atual = inicio;
        int maior = fim;

        // Partição em três regiões
        while (atual <= maior) {

            if (v[atual] < pivo) {
                swap(v[menor], v[atual]);
                menor++;
                atual++;
            }
            else if (v[atual] > pivo) {
                swap(v[atual], v[maior]);
                maior--;
            }
            else {
                atual++;
            }
        }

        // Processa primeiro a menor região
        if (menor - inicio < fim - maior) {

            quickSort(v, inicio, menor - 1);
            inicio = maior + 1;

        } else {

            quickSort(v, maior + 1, fim);
            fim = menor - 1;

        }
    }
}

int main() {

    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    if (n > 0) {
        quickSort(v, 0, n - 1);
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << v[i];
    }

    cout << endl;

    return 0;
}
