#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){

    // creation
    unordered_map<string,int> m;

    // insertion

    //1
    pair<string, int> p = make_pair("babbar",3);
    m.insert(p);


    //2
    pair<string, int> pair2("love",6);
    m.insert(pair2);

    //3
    m["mera"] = 1;

    //what will happen?
    m["mera"] = 2; //Ans: -> Update the valules


    //searching
    cout<<m["love"]<<endl;
    cout<<m["mera"]<<endl;
    cout<<m.at("babbar")<<endl;
    cout<<m["unknown_key"]<<endl;
    cout<<m.at("unknown_key")<<endl;

    //size
    cout<<"Size:"<<m.size()<<endl;

    //to check the presence
    cout<<m.count("bro")<<endl;
    cout<<m.count("love")<<endl;

    //erase
    m.erase("love");
    cout<<"Size:"<<m.size()<<endl;

    //for print all data
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    unordered_map<string, int> :: iterator it = m.begin();

    while(it!=m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }


    //diffrence between map and unordered map is that the order is preserved

    /*
    Hash Function -
        1. Hash Code    Rehan(string) -> 2323(int)
        2. Camparision function -> 23(0-99)

    Collision
        1. Open Hashing (Put at sam place in array uisng linked list and placed head at that poistion)
        2. Closed Addresing (Choose next location usng linear or qudratic probing techniques)
            a.Linear Probing [ f(i) = i ]
            b.Quadratic Probing [ f(i) = i^2 ]
    */
    return 0;
}