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
    Employee emp;

public:
    void add() {
        ofstream out(fileName, ios::binary | ios::app);
        cout << "Enter ID, Name, Salary: ";
        cin >> emp.id >> emp.name >> emp.salary;
        out.write((char*)&emp, sizeof(emp));
        cout << "Record Saved.\n";
    }

    void display() {
        ifstream in(fileName, ios::binary);
        while (in.read((char*)&emp, sizeof(emp))) {
            cout << emp.id << " | " << emp.name << " | " << emp.salary << endl;
        }
    }

    void search(int id) {
        ifstream in(fileName, ios::binary);
        while (in.read((char*)&emp, sizeof(emp))) {
            if (emp.id == id) {
                cout << "Found: " << emp.name << endl;
                return;
            }
        }
        cout << "Not Found.\n";
    }

    void remove(int id) {
        ifstream in(fileName, ios::binary);
        ofstream temp("temp.bin", ios::binary);
        bool found = false;

        while (in.read((char*)&emp, sizeof(emp))) {
            if (emp.id != id) temp.write((char*)&emp, sizeof(emp));
            else found = true;
        }
        
        in.close(); temp.close();
        std::remove(fileName.c_str());
        std::rename("temp.bin", fileName.c_str());
        cout << (found ? "Deleted.\n" : "Not found.\n");
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