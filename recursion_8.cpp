#include<bits/stdc++.h>
using namespace std;

// Leetcode 39 (Combination Sum) SDE Sheet Question

void combiSum(int index, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans){
    if(index == arr.size()){
        if(target == 0)
            ans.push_back(ds);
        return;
    }

    // For picking the element if less than target 

    if(arr[index] <= target){
        ds.push_back(arr[index]);
        combiSum(index,target-arr[index],arr,ds,ans);
        ds.pop_back();
    }

    // For not picking the same element

    combiSum(index+1,target,arr,ds,ans);
}

vector<vector<int>> solution(vector<int> candidates, int target){
    vector<int>ds;
    vector<vector<int>> ans;
    combiSum(0,target,candidates,ds,ans);
    return ans;
}

void inputArray(int n, vector<int> &array){
    cout << "Enter array elements : ";
    for(int i=0;i<n;i++) cin >> array[i];
} // For taking input of ARRAY

int main(){
    int c,target;
    cout << "Enter the number of Candidates : ";
    cin >> c;
    vector<int> candidates(c);
    inputArray(c,candidates);
    cout << "Enter Target Value : ";
    cin >> target;

    // Printing the Solution 

    for(auto i : solution(candidates, target)){
        cout << "{ ";
        for(auto x : i){
            cout << x << " ";
        }
        cout << "}"<< endl;
    }

    return 0;
}