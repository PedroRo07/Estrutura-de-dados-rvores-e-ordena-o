#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    
    cout << "Digite o tamanho do vetor (n): ";
    if (!(cin >> n)) {
        return 0;
    }
    vector<int> arr(n);
    
if (n > 0) {
        cout << "Digite os " << n << " elementos separados por espaco: ";
    }
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int comparisons = 0;
    int swaps = 0;

    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        
        for (int j = i + 1; j < n; ++j) {
            comparisons++; 
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            swaps++;
        }
    }

    cout << "\nSaida esperada:\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
    
    cout << comparisons << " " << swaps << "\n";

    return 0;
}
