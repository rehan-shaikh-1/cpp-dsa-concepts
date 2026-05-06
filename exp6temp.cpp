#include <iostream>
using namespace std;

#define BSIZE 5

struct Client {
    long int telephoneNo;
    string name;
};

class TelephoneDirectory {
private:
    Client LPHashTable[BSIZE];
    Client QPHashTable[BSIZE];

public:
    TelephoneDirectory();

    void insertRecordLP();
    void displayRecordsLP();
    void searchRecordLP(long int);

    void insertRecordQP();
    void displayRecordsQP();
    void searchRecordQP(long int);
};

// ================== Constructor ==================
TelephoneDirectory::TelephoneDirectory() {

}

void TelephoneDirectory::insertRecordLP() {

}

void TelephoneDirectory::searchRecordLP(long int telephoneNo) {

}

void TelephoneDirectory::displayRecordsLP() {

}

// ================== Quadratic Probing ==================
void TelephoneDirectory::insertRecordQP() {

}

void TelephoneDirectory::searchRecordQP(long int telephoneNo) {

}

void TelephoneDirectory::displayRecordsQP() {

}

// ================== Main Function ==================
int main() {
    TelephoneDirectory t;
    int choice, subChoice;
    long int telephoneNo;

    do {
        cout << "\n\n===== TELEPHONE DIRECTORY =====";
        cout << "\n1. Insert Record";
        cout << "\n2. Display Records";
        cout << "\n3. Search Record";
        cout << "\n4. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\n1. Linear Probing\n2. Quadratic Probing";
            cout << "\nChoose Method: ";
            cin >> subChoice;

            if (subChoice == 1)
                t.insertRecordLP();
            else
                t.insertRecordQP();
            break;

        case 2:
            cout << "\n1. Linear Probing\n2. Quadratic Probing";
            cout << "\nChoose Method: ";
            cin >> subChoice;

            if (subChoice == 1)
                t.displayRecordsLP();
            else
                t.displayRecordsQP();
            break;

        case 3:
            cout << "\nEnter Telephone Number to Search: ";
            cin >> telephoneNo;

            cout << "\n1. Linear Probing\n2. Quadratic Probing";
            cout << "\nChoose Method: ";
            cin >> subChoice;

            if (subChoice == 1)
                t.searchRecordLP(telephoneNo);
            else
                t.searchRecordQP(telephoneNo);
            break;

        case 4:
            cout << "\nExiting Program...";
            break;

        default:
            cout << "\nInvalid Choice!";
        }

    } while (choice != 4);

    return 0;
}