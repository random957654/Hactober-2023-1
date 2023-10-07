//to solve the n-queen problem using the the method of recursion and backtracking
#include<bits/stdc++.h>
using namespace std;
bool isSafe(int r,int c,vector<string>& board,int n){
    int row=r,col=c;
    //checking for the left upper diagonal
    while(r>=0 && c>=0){
        if(board[r][c]=='Q')
        return(false);
        r--;
        c--;
    }//end of while loop
    r=row;
    c=col;
    //checking for the left side
    while(c>=0){
       if(board[r][c]=='Q')
       return(false);
       c--;
    }//end of while loop
    r=row;
    c=col;
    //checking for the left lower diagonal
    while(r<n && c>=0){
        if(board[r][c]=='Q')
        return(false);
        r++;
        c--;
    }//end of while loop
    return(true);
}//end of fn.
void solve(int col,vector<vector<string>>& ans,vector<string>& board,int n){
    if(col==n){
        ans.push_back(board);
        return;
    }//end of if block
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            solve(col+1,ans,board,n);
            board[row][col]='.';
        }//end of if block
    }//end of for loop
}//end of fn.
int main()
{
    int n; //dimensions of the chessboard
    cout<<"Enter the number of rows/columns in the chessboard: ";
    cin>>n;
    vector<vector<string>> ans; //to store all the answers
    vector<string> board(n,string(n,'.')); //to store the status of the board
    solve(0,ans,board,n); //passing the column index, vector to store the solutions, vector for the board and dimensions
    if(!ans.size()){
        //if no solutions exist for given value of n
        cout<<"No Solutions obtained for n="<<n<<endl;
        cout<<n<<" Queens cannot be placed in a "<<n<<"x"<<n<<" chessboard such that they cannot attack each other."<<endl;
        return(0);
    }//end of if block
    //displaying all the possible solutions
    cout<<"The Solutions obtained are:"<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<"Solution #"<<i+1<<":"<<endl;
        for(int j=0;j<ans[0].size();j++)
        cout<<ans[i][j]<<endl;
        cout<<endl;
    }//end of for loop
    return(0);
}//end of main