/*
============================================================
Program Name : Telephone Directory using Hashing
Developer    : Rehan Shaikh
Date         : 05-05-2026
Description  :
This program implements a telephone directory using hash tables.
It uses two collision handling techniques:
1. Linear Probing
2. Quadratic Probing

Operations:
- Insert Record
- Display Records
- Search Record

Hash Function:
h(key) = key % table_size

Comparison is made based on number of probes.
============================================================
*/

#include <iostream>
using namespace std;

#define BSIZE 5

// ================== Client Structure ==================
struct Client {
    long int telephoneNo;
    string name;
};

// ================== Class Definition ==================
class TelephoneDirectory {
private:
    Client LPHashTable[BSIZE];
    Client QPHashTable[BSIZE];

public:
    TelephoneDirectory();

    // Linear Probing
    void insertRecordLP();
    void displayRecordsLP();
    void searchRecordLP(long int);

    // Quadratic Probing
    void insertRecordQP();
    void displayRecordsQP();
    void searchRecordQP(long int);
};

// ================== Constructor ==================
TelephoneDirectory::TelephoneDirectory() {
    for (int i = 0; i < BSIZE; i++) {
        LPHashTable[i].telephoneNo = -1;
        QPHashTable[i].telephoneNo = -1;
    }
}

// ================== Linear Probing ==================
void TelephoneDirectory::insertRecordLP() {
    Client temp;

    cout << "\nEnter Telephone Number: ";
    cin >> temp.telephoneNo;

    cout << "Enter Name: ";
    cin >> temp.name;

    int hi = temp.telephoneNo % BSIZE;

    if (LPHashTable[hi].telephoneNo == -1) {
        LPHashTable[hi] = temp;
    } else {
        int i = (hi + 1) % BSIZE;

        while (i != hi) {
            if (LPHashTable[i].telephoneNo == -1) {
                LPHashTable[i] = temp;
                return;
            }
            i = (i + 1) % BSIZE;
        }

        cout << "\nHash Table Full!";
    }
}

void TelephoneDirectory::searchRecordLP(long int telephoneNo) {
    int hi = telephoneNo % BSIZE;
    int noc = 0;

    if (LPHashTable[hi].telephoneNo == telephoneNo) {
        cout << "\nRecord found after 1 comparison!";
        return;
    }

    int i = (hi + 1) % BSIZE;

    while (i != hi) {
        noc++;

        if (LPHashTable[i].telephoneNo == telephoneNo) {
            cout << "\nRecord found after " << noc + 1 << " comparisons!";
            return;
        }

        i = (i + 1) % BSIZE;
    }

    cout << "\nRecord NOT found after " << noc + 1 << " comparisons!";
}

void TelephoneDirectory::displayRecordsLP() {
    cout << "\n\n--- Linear Probing Table ---";
    cout << "\nIndex\tTelephone\tName";

    for (int i = 0; i < BSIZE; i++) {
        cout << "\n" << i << "\t" << LPHashTable[i].telephoneNo
             << "\t\t" << LPHashTable[i].name;
    }
}

// ================== Quadratic Probing ==================
void TelephoneDirectory::insertRecordQP() {
    Client temp;

    cout << "\nEnter Telephone Number: ";
    cin >> temp.telephoneNo;

    cout << "Enter Name: ";
    cin >> temp.name;

    int hi = temp.telephoneNo % BSIZE;

    for (int i = 0; i < BSIZE; i++) {
        int newHI = (hi + i * i) % BSIZE;

        if (QPHashTable[newHI].telephoneNo == -1) {
            QPHashTable[newHI] = temp;
            return;
        }
    }

    cout << "\nHash Table Full!";
}

void TelephoneDirectory::searchRecordQP(long int telephoneNo) {
    int hi = telephoneNo % BSIZE;
    int noc = 0;

    for (int i = 0; i < BSIZE; i++) {
        int newHI = (hi + i * i) % BSIZE;
        noc++;

        if (QPHashTable[newHI].telephoneNo == telephoneNo) {
            cout << "\nRecord found after " << noc << " comparisons!";
            return;
        }
    }

    cout << "\nRecord NOT found after " << noc << " comparisons!";
}

void TelephoneDirectory::displayRecordsQP() {
    cout << "\n\n--- Quadratic Probing Table ---";
    cout << "\nIndex\tTelephone\tName";

    for (int i = 0; i < BSIZE; i++) {
        cout << "\n" << i << "\t" << QPHashTable[i].telephoneNo
             << "\t\t" << QPHashTable[i].name;
    }
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