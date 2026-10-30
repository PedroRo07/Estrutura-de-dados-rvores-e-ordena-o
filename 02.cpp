#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n, r;

    cout << "Digite a quantidade de nos e a raiz: ";
    cin >> n >> r;

    vector<int> esquerda(n + 1);
    vector<int> direita(n + 1);

    cout << "Digite os filhos esquerdo e direito de cada no:\n";

    for (int i = 1; i <= n; i++) {
        cout << "No " << i << " (esquerdo direito): ";
        cin >> esquerda[i] >> direita[i];
    }

    vector<int> pre, em, pos;

    // PRE-ORDEM
    stack<int> p;

    if (r != 0)
        p.push(r);

    while (!p.empty()) {
        int v = p.top();
        p.pop();

        pre.push_back(v);

        if (direita[v] != 0)
            p.push(direita[v]);

        if (esquerda[v] != 0)
            p.push(esquerda[v]);
    }

    // EM-ORDEM
    stack<int> s;
    int atual = r;

    while (atual != 0 || !s.empty()) {
        while (atual != 0) {
            s.push(atual);
            atual = esquerda[atual];
        }

        atual = s.top();
        s.pop();

        em.push_back(atual);
        atual = direita[atual];
    }

    // POS-ORDEM
    stack<int> s1, s2;

    if (r != 0)
        s1.push(r);

    while (!s1.empty()) {
        int v = s1.top();
        s1.pop();

        s2.push(v);

        if (esquerda[v] != 0)
            s1.push(esquerda[v]);

        if (direita[v] != 0)
            s1.push(direita[v]);
    }

    while (!s2.empty()) {
        pos.push_back(s2.top());
        s2.pop();
    }

    // RESULTADOS
    cout << "\nPRE-ORDEM: ";
    for (int i = 0; i < (int)pre.size(); i++) {
        if (i > 0) cout << " ";
        cout << pre[i];
    }

    cout << "\nEM-ORDEM: ";
    for (int i = 0; i < (int)em.size(); i++) {
        if (i > 0) cout << " ";
        cout << em[i];
    }

    cout << "\nPOS-ORDEM: ";
    for (int i = 0; i < (int)pos.size(); i++) {
        if (i > 0) cout << " ";
        cout << pos[i];
    }

    cout << "\n";

    return 0;
}
