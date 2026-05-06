#include<iostream>
#include<stack>
#include<string>
using namespace std;

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

        void addNode(string word, string meaning) {


        }

        void update(string word, string newMeaning) {

        }

  
        void displayAscending(Node* root) {

        }

    
        void displayDescending(Node* root) {

        }

    
        int maxComparisons(Node* root) {

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