#include<bits/stdc++.h>
using namespace std;

void printOne(int n){
    cout << 1 << endl;
    printOne(n-1);
} // No Base Condition (i.e => Infinite Loop)

void printOneNew(int n){
    if(n > 0) cout << 1 << endl;
    printOneNew(n-1);
} // With Base Condition

int main(){

    int nn;
    cin >> nn;
    // printOne(nn);
    printOneNew(nn);
    return 0;
}