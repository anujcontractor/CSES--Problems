#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;

void solve(int col, vector<vector<string> >& ans, vector<string>& board, vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row=0; row<n; row++){
            if(board[row][col] == '.' && leftRow[row] == 0 && upperDiagonal[n-1 + col - row] == 0 && lowerDiagonal[row+col] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                upperDiagonal[n-1 + col - row] = 1;
                lowerDiagonal[row+col] = 1;
                solve(col+1, ans, board, leftRow, upperDiagonal, lowerDiagonal, n);
                board[row][col] = '.';
                leftRow[row] = 0;
                upperDiagonal[n-1 + col - row] = 0;
                lowerDiagonal[row+col] = 0;
            }
        }
    }

int32_t main(){

    vector<string> board(8);

    for(int i=0; i<8; i++){
        string s;
        for(int j=0; j<8; j++){
            char c;
            cin>>c;
            s.push_back(c);
        }
        board[i] = s;
    }
    vector<vector<string> > ans;
    vector<int> prev(8,0), leftD(15,0), rightD(15,0);
    solve(0, ans, board, prev, leftD, rightD, 8);
    cout<< ans.size();


  return 0;
}