#include <iostream>
using namespace std;

struct Node {
    string key, meaning;
    int height;
    Node *left, *right;

    Node(string k, string m) {
        key = k;
        meaning = m;
        height = 1;
        left = right = nullptr;
    }
};

class AVL {
    Node* root = nullptr;

    int getHeight(Node* n) {
        return n ? n->height : 0;
    }

    int getBalance(Node* n) {
        return n ? getHeight(n->left) - getHeight(n->right) : 0;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    Node* insert(Node* node, string key, string meaning) {
        if (!node)
            return new Node(key, meaning);

        if (key < node->key)
            node->left = insert(node->left, key, meaning);
        else if (key > node->key)
            node->right = insert(node->right, key, meaning);
        else
            return node; // duplicate not allowed

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        // Rotations
        if (balance > 1 && key < node->left->key)
            return rightRotate(node); // LL

        if (balance < -1 && key > node->right->key)
            return leftRotate(node); // RR

        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left); // LR
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right); // RL
            return leftRotate(node);
        }

        return node;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->key << " : " << node->meaning << endl;
        inorder(node->right);
    }

    void search(Node* node, string key) {
        int count = 0;
        while (node) {
            count++;
            if (key == node->key) {
                cout << "Found in " << count << " comparisons\n";
                return;
            }
            node = (key < node->key) ? node->left : node->right;
        }
        cout << "Not found\n";
    }

public:
    void insert(string key, string meaning) {
        root = insert(root, key, meaning);
    }

    void display() {
        inorder(root);
    }

    void search(string key) {
        search(root, key);
    }
};

int main() {
    AVL dict;
    int ch;
    string key, meaning;

    do {
        cout << "\n1. Add\n2. Display\n3. Search\n4. Exit\nChoice: ";
        cin >> ch;
        cin.ignore();

        switch (ch) {
        case 1:
            cout << "Enter key: ";
            getline(cin, key);
            cout << "Enter meaning: ";
            getline(cin, meaning);
            dict.insert(key, meaning);
            break;

        case 2:
            dict.display();
            break;

        case 3:
            cout << "Enter key: ";
            getline(cin, key);
            dict.search(key);
            break;
        }
    } while (ch != 4);

    return 0;
}