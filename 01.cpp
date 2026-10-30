#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "=== 01 Retrato de uma arvore ===" << endl;
    cout << "1. Digite a quantidade de nos (n): ";
    
    if (cin >> n) {
        vector<bool> is_parent(n + 1, false);
        int root = -1;

        cout << "2. Digite os " << n << " pais (separados por espaco): ";
        for (int i = 1; i <= n; ++i) {
            int p;
            cin >> p;
            
            if (p == 0) {
                root = i;
            } else {
                is_parent[p] = true;
            }
        }

        int leaves = 0;
        int internal_nodes = 0;

        for (int i = 1; i <= n; ++i) {
            if (is_parent[i]) {
                internal_nodes++;
            } else {
                leaves++;
            }
        }

        cout << "\n-> Resultado (Raiz | Qtd Folhas | Qtd Nos Internos):" << endl;
        cout << root << " " << leaves << " " << internal_nodes << endl;
    }
    
    return 0;
}