//Similar to N-Queens just change one line
class Solution {
public:
    void solve(int &ans,vector<string> &board,int row, vector<int> &cols,int n,vector<int> &leftd,vector<int> &rightd){

        if(row==n)
        {
            ans++;
            return;
        }

        for(int col=0;col<n;col++)
        {
            if(cols[col]==0 && leftd[n-1-row+col]==0 && rightd[col+row]==0)
            {
                cols[col]=1;
                leftd[n-1-row+col]=1;
                rightd[col+row]=1;
                board[row][col]='Q';
                solve(ans,board,row+1,cols,n,leftd,rightd);
                board[row][col]='.';
                cols[col]=0;
                leftd[n-1-row+col]=0;
                rightd[col+row]=0;

            }
        }
    }

    int totalNQueens(int n) {
        
       int ans=0;

        //vector<string> board(n, string(n, '.')); 
        vector<string> board(n);

        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        board[i].push_back('.');

        vector<int> cols(n,0);

        vector<int> leftd(2*n-1,0);
        vector<int> rightd(2*n-1,0);

        solve(ans,board,0,cols,n,leftd,rightd);
        return ans;
    }
};