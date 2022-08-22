// Multiple Recursion Calls -- Lecture 5

#include<bits/stdc++.h>
using namespace std;

// Program 1 (Fibonacci Number)

int fib(int n){
    if(n <= 1) return n;
    else return fib(n-1) + fib(n-2);
}

int main(){
    int N;
    cout << "ENTER the value of N : ";
    cin >> N;
    cout << "Fibonacci of " << N << " is : " << fib(N) << endl;
    return 0;
}