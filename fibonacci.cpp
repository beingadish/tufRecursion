#include <bits/stdc++.h>
using namespace std;

#define ulli unsigned long long int

ulli fib(int num){
    if(num <= 1) return num;
    else return fib(num-1) + fib(num-2);
}

int main(){
    int n;
    cin >> n;
    for(int i =0;i<=n;i++) cout << "Fib " << i << " : " << fib(i) << endl;
    return 0;
}
