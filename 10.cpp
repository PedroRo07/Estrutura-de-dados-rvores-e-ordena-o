#include <iostream>
#include <vector>

using namespace std;

long long intercala(vector<int>& v, vector<int>& aux, int esq, int meio, int dir) {
    int i = esq, j = meio + 1, k = esq;
    long long inv = 0;

    while (i <= meio && j <= dir) {
        if (v[i] <= v[j]) {
            aux[k++] = v[i++];
        } else {
            aux[k++] = v[j++];
            inv += (meio - i + 1);
        }
    }

    while (i <= meio) aux[k++] = v[i++];
    while (j <= dir) aux[k++] = v[j++];

    for (i = esq; i <= dir; i++) v[i] = aux[i];

    return inv;
}

long long merge_sort(vector<int>& v, vector<int>& aux, int esq, int dir) {
    long long inv = 0;
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;
        inv += merge_sort(v, aux, esq, meio);
        inv += merge_sort(v, aux, meio + 1, dir);
        inv += intercala(v, aux, esq, meio, dir);
    }
    return inv;
}

int main() {
    int n;
    
    cout << "n: ";
    if (!(cin >> n)) return 0;

    vector<int> v(n), aux(n);
    
    if (n > 0) cout << "elementos: ";
    for (int i = 0; i < n; i++) cin >> v[i];

    long long inv = merge_sort(v, aux, 0, n - 1);

    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << v[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n" << inv << "\n";

    return 0;
}
