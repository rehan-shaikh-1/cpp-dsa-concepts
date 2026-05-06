#include<iostream>
#include<limits>
using namespace std;
int main(){
int n = 0;

    while(n != 5){
        cout<<"\n1. lowda 1";
        cout<<"\n2. chi 2";
        cout<<"\n3. bochya 3";
        cout<<"\n4. gandu 4";
        cout<<"\nEnter your choice";
        cin>>n;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        switch(n){
        case 1: cout<<"\nCase 1";
            char a;
            cin>>a;
            break;
        case 2: cout<<"\nCase 2";
            break;
        case 3: cout<<"\nCase 3";
            break;
        case 4: cout<<"\nCase 4";
            break;
        }
    }

}