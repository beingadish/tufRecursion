#include<bits/stdc++.h>
using namespace std;

// Leetcode 90 (Subset Sums II)  Link --> https://leetcode.com/problems/subsets-ii/

void subsetSumsII(int index, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans){

    ans.push_back(ds);
    for(int i = index;i<arr.size();i++){
        if(i != index && arr[i] == arr[i-1]) continue;
        ds.push_back(arr[i]);
        subsetSumsII(i+1,arr,ds,ans);
        ds.pop_back();
    }

}

vector<vector<int>> solution(vector<int> &arr){
    vector<int>ds;
    vector<vector<int>> ans;
    subsetSumsII(0,arr,ds,ans);
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
    sort(lst.begin(),lst.end());  // Must sort the given array so as to maintain its continuity of same elements together (i.e: CONTIGUOUS)

    // Printing the Solution 

    for(auto i : solution(lst)){
        cout << "{ ";
        for(auto x : i){
            cout << x << " ";
        }
        cout << "}"<< endl;
    }
    return 0;
}