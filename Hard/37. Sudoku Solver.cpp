//Easy to Understand but gives TLE
class Solution {
public:

    bool subBox(vector<vector<char>>& board,int row, int col){
        set<char>st;
        for(int i=row;i<row+3;i++){
            for(int j=col;j<col+3;j++){
                if(board[i][j]=='.') continue;
                if(st.find(board[i][j])!=st.end()){
                    return false;
                }
                st.insert(board[i][j]);
            }
        
        }
        return true;

    }

    bool rowsFull(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            set<char>st;
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                if(st.find(board[i][j])!=st.end()){
                    return false;
                }
                st.insert(board[i][j]);
            }
        }
return true;
    }

    bool colsFull(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            set<char>st;
            for(int j=0;j<9;j++){
                if(board[j][i]=='.') continue;
                if(st.find(board[j][i])!=st.end()){
                    return false;
                }
                st.insert(board[j][i]);
            }
        }
return true;

    }

    bool isValid(vector<vector<char>>& board){
        if (!rowsFull(board)) return false;
        // check cols
        if (!colsFull(board)) return false;
        // check 3x3 boxes
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!subBox(board, i, j)) return false;
            }
        }
        return true;
    }

    bool backtrack(vector<vector<char>>& board,int row,int col){
        if(row==9) return true;
        if(col==9) return backtrack(board,row+1,0);
        if (board[row][col] != '.') return backtrack(board, row, col+1);

        for(char c='1';c<='9';c++){
            board[row][col]=c;
            if (isValid(board) && backtrack(board, row, col + 1)) {
                return true;
            }
            board[row][col]='.';
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }
};



//Optimal version
class Solution {
public:

    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int j=0;j<9;j++){
            if(board[row][j]==c) return false;
        }
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c) return false;
        }
        int startRow=(row/3)*3;
        int startCol=(col/3)*3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == c) return false;
            }
        }
        return true;

    }

    bool backtrack(vector<vector<char>>& board,int row,int col){
        if(row==9) return true;
        if(col==9) return backtrack(board,row+1,0);
        if (board[row][col] != '.') return backtrack(board, row, col+1);

        for(char c='1';c<='9';c++){
            if (isValid(board,row,col,c)) {
            board[row][col]=c;
            if (backtrack(board, row, col + 1)) return true;
        board[row][col] = '.';
    }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }
};