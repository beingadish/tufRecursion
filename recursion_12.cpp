#include<bits/stdc++.h>
using namespace std;

// TOPIC : Print all combinations of String/Array


// Leetcode 46 (Permutations)  Link --> https://leetcode.com/problems/permutations/

// APPROACH 1 (approach 2 on next program i.e recursion_13.cpp)


void permutations(vector<int> &arr, vector<int> &f, vector<int> &ds, vector<vector<int>> &ans){

    if(ds.size() == arr.size()){
        ans.push_back(ds);
        return;
    }

    for(int i = 0;i<arr.size();i++){
        if(!f[i]){
            ds.push_back(arr[i]);
            f[i] = 1;
            permutations(arr,f,ds,ans);
            f[i] = 0;
            ds.pop_back();
        }
    }
}


vector<vector<int>> solution(vector<int> &arr){
    vector<int>ds;
    vector<vector<int>> ans;
    vector<int> freq(arr.size(),0);
    permutations(arr,freq,ds,ans);
    return ans;
}



void inputArray(int n, vector<int> &array){

    cout << "Enter array elements : ";
    for(int i=0;i<n;i++) cin >> array[i];

} // For taking input of ARRAY



int main(){

    int n;
    cout << "Enter the size of Array : ";
    cin >> n;
    vector<int> lst(n);
    inputArray(n,lst);

    // Printing the Solution 

    cout << "[ ";
    for(auto i : solution(lst)){
        cout << "{ ";
        for(auto x : i){
            cout << x << " ";
        }
        cout << "}";
    }
    cout << " ]" << endl;
    return 0;
}