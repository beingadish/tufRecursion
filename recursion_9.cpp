#include<bits/stdc++.h>
using namespace std;

// Leetcode 40 (Combination Sum II)


void combiSum2(int index, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans){
    if(target == 0){
        ans.push_back(ds);
        return;
    }

    for(int i = index;i<arr.size();i++){

        if(i > index && arr[i] == arr[i-1]) continue; // if we are at the starting index then we'll allow the duplicate puckup but if any other condition becomes true then we'll skip that array element so not to pickup the duplicate elements 

        if(arr[i] > target) break; // if the particular iterated element is greater than the target then why we should include it in the data structure

        ds.push_back(arr[i]); // push the element and then check again
        combiSum2(i+1,target-arr[i],arr,ds,ans);
        ds.pop_back(); // after checking pop back the element 
    }
}

vector<vector<int>> solution(vector<int> candidates, int target){
    vector<int>ds;
    vector<vector<int>> ans;
    combiSum2(0,target,candidates,ds,ans);
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

    // Sorting the Candidates Array --> So as to return the answers in Lexicographical Order
    sort(candidates.begin(),candidates.end());

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