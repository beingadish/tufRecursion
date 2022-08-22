#include<bits/stdc++.h>
using namespace std;

// Leetcode 51 (N-Queens)  Link --> https://leetcode.com/problems/n-queens/

bool isQueenSafe(int col, int row, vector<string> &board, int n){

    // making duplicates so that we can restore the state of Row & Col later in the process 

    int dupliRow = row;
    int dupliCol = col;

    // For Upper Left Moves (TopLeft)

    while(row >= 0 && col >= 0){
        if(board[row--][col--] == 'Q') return false;
    }

    // restoring actual value of the Row & Col (that was modified by the upper while loop for checking purposes)
    row = dupliRow;
    col = dupliCol;

    // For Left Moves (Linear Left)

    while(col >=0){
        if(board[row][col--] == 'Q') return false;
    }


    // Restoring actual value of Row & Col
    row = dupliRow;
    col = dupliCol;

    // For Bottom Left Moves (BottomLeft)

    while(row < n && col >= 0){ 
        
        // board.size() used above is nothing but equal to the value of n(size of the board == size of the row == size of the col){    IT IS EQUIVALENT TO row <= n    }

        if(board[row++][col--] == 'Q') return false;
    }

    return true;


}


void solveNQueens1(int col,int n, vector<string> &board, vector<vector<string>> &ans){
    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row = 0;row<n;row++){
        if(isQueenSafe(col,row,board,n)){
            board[row][col] = 'Q';
            solveNQueens1(col+1,n,board,ans);
            board[row][col] = '.';
        }
    }
}

void solveNQueens2(int col,int n, vector<string> &board, vector<vector<string>> &ans, vector<int> &lr, vector<int> &ud, vector<int> &ld){

    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row = 0;row<n;row++){
        if(lr[row] == 0 && ld[row+col] == 0 && ud[n-1+col-row] == 0){
            board[row][col] = 'Q';
            lr[row] = 1;
            ld[row+col] = 1;
            ud[n-1+col-row] = 1;
            solveNQueens2(col+1,n,board,ans,lr,ud,ld);
            lr[row] = 0;
            ld[row+col] = 0;
            ud[n-1+col-row] = 0;
            board[row][col] = '.';
        }
    }
}



vector<vector<string>> solution1(int n){

    // Preparing the Board

    string s(n,'.'); // A clean complete Row of a Board
    vector<string> board;

    for(int i =0;i<n;i++) board.push_back(s);       // Fully Complete Clean Board

    
    vector<vector<string>> answer;
    solveNQueens1(0,n,board,answer);
    return answer;
}


vector<vector<string>> solution2(int n){

    // Preparing the Board

    string s(n,'.'); // A clean complete Row of a Board
    vector<string> board;

    for(int i =0;i<n;i++) board.push_back(s);       // Fully Complete Clean Board

    // preparing the hash arrays & initialising them with zeroes (0)

    vector<int> leftRow(n,0),lowerDiagonal(2*n -1,0),upperDiagonal(2*n-1,0);


    vector<vector<string>> answer;
    solveNQueens2(0,n,board,answer,leftRow,upperDiagonal,lowerDiagonal);
    return answer;
}


int main(){
    int n;
    cout << "Enter the Board Size : ";
    cin >> n;

    // Printing the Solution 

    // cout << "Using Solution 1 : " << endl << endl;

    // cout << "[ " << endl << endl;

    // for(auto i : solution1(n)){
    //     for(auto x : i){
    //         cout << x << " ";
    //         cout << endl;
    //     }
    //     cout << endl << endl;
    // }

    // cout << " ]" << endl;

    cout << "Using Solution 2 : " << endl << endl;

    cout << "[ " << endl << endl;

    for(auto i : solution2(n)){
        for(auto x : i){
            cout << x << " ";
            cout << endl;
        }
        cout << endl << endl;
    }

    cout << " ]" << endl;

    return 0;
}