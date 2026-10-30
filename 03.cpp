#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (root == nullptr) return new Node(val);
    if (val < root->val) root->left = insert(root->left, val);
    else if (val > root->val) root->right = insert(root->right, val);
    return root;
}

void inOrder(Node* root, bool& first) {
    if (root == nullptr) return;
    inOrder(root->left, first);
    if (!first) cout << " ";
    cout << root->val;
    first = false;
    inOrder(root->right, first);
}

int main() {
    int n;
    cout << "=== Construcao de uma BST ===" << endl;
    cout << "Digite a quantidade de chaves que deseja inserir: ";
    if (cin >> n) {
        Node* root = nullptr;
        if (n > 0) {
            cout << "Digite as " << n << " chaves separadas por espaco ou Enter: ";
            for (int i = 0; i < n; ++i) {
                int val;
                cin >> val;
                root = insert(root, val);
            }
        }
        cout << "\nResultado (Percurso em Ordem Crescente):" << endl;
        bool first = true;
        inOrder(root, first);
        cout << endl;
    }
    return 0;
}