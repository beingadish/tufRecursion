#include<bits/stdc++.h>
using namespace std;

void printName(string name , int n){
    if(n == 0) return;
    cout << name << endl;
    printName(name,n-1);
}

void OtoN(int i,int n){
    if(i>n) return;
    else{
        cout << i << endl;
        OtoN(i+1,n);
    }
}

void NtoO(int n){
    if(n>0){
        cout << n << endl;
        NtoO(n-1);
    }else return;
}

void oneToNB(int n){
    if(n > 1) oneToNB(n-1);
    cout << n << endl;
} // Using Backtracking

void nToOneB(int n){
    if(n == 0) return;
    cout << n << endl;
    nToOneB(n-1);
    //noneToNB(n);
} // Using Backtracking

int main(){

// Program 1 (name n time)
    // int count;
    // string name;
    // cout << "ENTER NAME : ";
    // cin >> name;
    // cout << "ENTER TIMES : ";
    // cin >> count;
    // printName(name,count);

// Program 2 (print 1 to n)
    // int m;
    // cin >> m;
    // OtoN(1,m);

// Program 3 (print n to 1)
    // int b;
    // cin >> b;
    // NtoO(b);

// Program 4 (print 1 to n using backtracking)
    // int num;
    // cin >> num;
    // oneToN(num);

// Program 5 (print n to 1 using backtracking)
    // int num;
    // cin >> num;
    // nToOneB(num);

    return 0;
}