#include<iostream>
#include<stack>
#include<string>
using namespace std;

// Node structure with keyword and meaning
class Node {
    public:
        string word;
        string meaning;
        Node* left;
        Node* right;

    Node(string word, string meaning) {
        this->word = word;
        this->meaning = meaning;
        this->left = NULL;
        this->right = NULL;
    }
};

class Dictionary {
    public:
        Node* root;

        Dictionary() {
            root = NULL;
        }

        // i. Adding new keywords (Iterative approach as per your style)
        void addNode(string word, string meaning) {
            Node* newNode = new Node(word, meaning);
            if (root == NULL) {
                root = newNode;
                return;
            }

            Node* temp = root;
            while (true) {
                if (word == temp->word) {
                    cout << "Keyword already exists!" << endl;
                    delete newNode;
                    return;
                }
                if (word < temp->word) {
                    if (temp->left == NULL) {
                        temp->left = newNode;
                        break;
                    }
                    temp = temp->left;
                } else {
                    if (temp->right == NULL) {
                        temp->right = newNode;
                        break;
                    }
                    temp = temp->right;
                }
            }
        }

        // iii. Updating values of an entry
        void update(string word, string newMeaning) {
            Node* temp = root;
            while (temp != NULL) {
                if (temp->word == word) {
                    temp->meaning = newMeaning;
                    cout << "Meaning updated successfully!" << endl;
                    return;
                }
                temp = (word < temp->word) ? temp->left : temp->right;
            }
            cout << "Keyword not found!" << endl;
        }

        // iv. Display sorted (Ascending - InOrder)
        void displayAscending(Node* root) {
            if (root == NULL) return;
            displayAscending(root->left);
            cout << root->word << " : " << root->meaning << endl;
            displayAscending(root->right);
        }

        // iv. Display sorted (Descending - Reverse InOrder)
        void displayDescending(Node* root) {
            if (root == NULL) return;
            displayDescending(root->right);
            cout << root->word << " : " << root->meaning << endl;
            displayDescending(root->left);
        }

        // v. Find max comparisons required (Height of Tree)
        int maxComparisons(Node* root) {
            if (root == NULL) return 0;
            int leftHeight = maxComparisons(root->left);
            int rightHeight = maxComparisons(root->right);
            return max(leftHeight, rightHeight) + 1;
        }

        // ii. Deleting keyword (Recursive Helper)
        Node* deleteNode(Node* root, string key) {
            if (root == NULL) return root;

            if (key < root->word)
                root->left = deleteNode(root->left, key);
            else if (key > root->word)
                root->right = deleteNode(root->right, key);
            else {
                // Node with one or no child
                if (root->left == NULL) {
                    Node* temp = root->right;
                    delete root;
                    return temp;
                } else if (root->right == NULL) {
                    Node* temp = root->left;
                    delete root;
                    return temp;
                }

                // Node with two children: Get inorder successor
                Node* temp = root->right;
                while (temp->left != NULL) temp = temp->left;

                root->word = temp->word;
                root->meaning = temp->meaning;
                root->right = deleteNode(root->right, temp->word);
            }
            return root;
        }
};



int main() {
    Dictionary dict;
    int choice;
    string w, m;

    while (true) {
        cout << "\n1.Add 2.Delete 3.Update 4.Display(Asc) 5.Display(Desc) 6.Max Comparisons 7.Exit\nChoice: ";
        cin >> choice;
        if (choice == 7) break;

        switch (choice) {
            case 1:
                cout << "Enter Word & Meaning: ";
                cin >> w >> m;
                dict.addNode(w, m);
                break;
            case 2:
                cout << "Enter Word to delete: ";
                cin >> w;
                dict.root = dict.deleteNode(dict.root, w);
                break;
            case 3:
                cout << "Enter Word & New Meaning: ";
                cin >> w >> m;
                dict.update(w, m);
                break;
            case 4:
                dict.displayAscending(dict.root);
                break;
            case 5:
                dict.displayDescending(dict.root);
                break;
            case 6:
                cout << "Max comparisons needed: " << dict.maxComparisons(dict.root) << endl;
                break;
        }
    }
    return 0;
}