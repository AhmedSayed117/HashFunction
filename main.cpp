#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Hash{
    int size;
    list<string> *LinkedList;
    int hashFun(string);
public:
    Hash(int);
    void insert(string);
    void print();
};

Hash::Hash(int s) {
    this->size=s;
    LinkedList = new list<string>[s];
}

int Hash::hashFun(string str){
    int i=0;int sum=0;
    for(int k=0;k<str.length();k++){ // case insensitively
        if(str[k]>= 'A' && str[k]<= 'Z'){
            str[k]+=32;
        }
    }

    while (i<str.size()){
        sum+=(str[i] - 'a');
        i++;
    }
    return (sum%15);
}

void Hash::insert(string str){
    int index = hashFun(str);
    LinkedList[index].push_back(str);
}

void Hash::print(){
    for (int i = 0; i < this->size; i++) {
        cout << i;
        for (auto links : LinkedList[i])
            cout << " --> " << links;
        cout << endl;
    }
}

int main() {
    int size;
    cout<<"Size pf String = ";
    cin>>size;
    Hash H(size);
    for(int i =0;i<size;i++){
        string str;
        cin>>str;
        H.insert(str);
    }
    H.print();
    return 0;
}