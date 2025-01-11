class Solution {
public:
    // bool isSafe(vector<string> &board,int n,int row,int col){
    //     for (int tempr=row-1;tempr>=0;tempr--){
    //         if (board[tempr][col]=='Q') return false;
    //     }

    //     int tempr=row-1,tempc=col-1;
    //     while(tempr>=0 && tempc>=0){
    //         if (board[tempr][tempc]=='Q') return false;
    //         tempr--;
    //         tempc--;
    //     }

    //     tempr=row-1,tempc=col+1;
    //     while(tempr>=0 && tempc<n){
    //         if (board[tempr][tempc]=='Q') return false;
    //         tempr--;
    //         tempc++;
    //     }

    //     return true;
    // }

    // void helper(vector<vector<string>> &ans,vector<string> &board,int n,int row, int nQ){
    //     if (nQ==0){
    //         ans.push_back(board);
    //         return;
    //     }
    //     for (int col=0;col<n;col++){
    //         if (isSafe(board,n,row,col)){
    //             board[row][col]='Q';
    //             helper(ans,board,n,row+1,nQ-1);
    //             board[row][col]='.';
    //         }
    //     }
    // }
    // vector<vector<string>> solveNQueens(int n) {
    //     vector < vector < string >> ans;
    //     vector < string > board(n);
    //     string s(n, '.');
    //     for (int i = 0; i < n; i++) {
    //         board[i] = s;
    //     }
    //     helper(ans,board,n,0,n);
    //     return ans;
    // }



    void back(vector<vector<string>> &ans,vector<string> &curr,int n,vector<int> &leftRow, vector<int> &upperDiagonal,vector<int> &lowerDiagonal,int col){
        if (col == n){
            ans.push_back(curr);
            return;
        }
        for (int row = 0;row<n;row++){
            if (leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+col-row]==0){
                curr[row][col] = 'Q';
                leftRow[row]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[n-1+col-row]=1;
                back(ans,curr,n,leftRow,upperDiagonal,lowerDiagonal,col+1);
                curr[row][col] = '.';
                leftRow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1+col-row]=0;
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> curr(n);
        string s(n,'.');
        for (int i=0;i<n;i++) curr[i]=s;
        vector<int> leftRow(n,0), upperDiagonal(2*n-1,0), lowerDiagonal(2*n-1,0);
        back(ans,curr,n,leftRow,upperDiagonal,lowerDiagonal,0);
        return ans;
    }
};