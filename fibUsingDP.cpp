#include <bits/stdc++.h>
using namespace std;

#define ulli unsigned long long int

ulli dp[1000];


ulli fib(int num){
    if(num <= 1) return dp[num] = num;
    else{
        if(dp[num] != -1) return dp[num];
        else return dp[num] = fib(num-1) + fib(num-2);
    }
}

int main(){
    memset(dp, -1,1000);
    int n;
    cin >> n;
    for(int i =0;i<=n;i++) cout << "Fib " << i << " : " << fib(i) << endl;
    return 0;
}
