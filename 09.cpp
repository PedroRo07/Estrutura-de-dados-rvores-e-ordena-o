#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Registro {
    string id;
    int nota;
};
int main() {
    int n;  
    cout << "Digite a quantidade de registros (n): ";
    if (!(cin >> n)) {
        return 0;
    }
    vector<Registro> arr(n);
  
    if (n > 0) {
        cout << "\nDigite o identificador e a nota de cada registro:\n";
        cout << "(Exemplo: A 7)\n";
    }    
    for (int i = 0; i < n; ++i) {
        cout << "Registro " << i + 1 << ": ";
        cin >> arr[i].id >> arr[i].nota;
    }

    long long deslocamentos = 0;

    for (int i = 1; i < n; ++i) {
        Registro chave = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].nota > chave.nota) {
            arr[j + 1] = arr[j];
            deslocamentos++;
            j--;
        } 
        arr[j + 1] = chave;
    } 
    cout << "\nResultado\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i].id << " " << arr[i].nota << "\n";
    } 
    cout << "DESLOCAMENTOS " << deslocamentos << "\n";
    return 0;
}
