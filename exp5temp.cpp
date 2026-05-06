#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Employee {
    int id;
    char name[20];
    float salary;
};

class FileHandler {
    const string fileName = "data.bin";
    Employee 

public:
    void add() {
        fstream out()
    }

    void display() {

    }

    void search(int id) {

    }

    void remove(int id) {
    }

};

int main() {
    FileHandler fh;
    int choice, id;

    while (true) {
        cout << "\n1.Add 2.Show 3.Search 4.Delete 5.Exit: ";
        cin >> choice;
        if (choice == 5) break;

        switch (choice) {
            case 1: fh.add(); break;
            case 2: fh.display(); break;
            case 3: cout << "ID: "; cin >> id; fh.search(id); break;
            case 4: cout << "ID: "; cin >> id; fh.remove(id); break;
        }
    }
    return 0;
}