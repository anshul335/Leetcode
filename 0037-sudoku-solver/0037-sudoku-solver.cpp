class Solution {
public:
    bool checkRow (vector<vector<char>> & word , int row ,char num){
        for (int i =0;i<9;i++){
            if (word[row][i] ==num) return false;
        }
        return true;
    }
    bool checkCol (vector<vector<char>> & word , int col ,char num){
        for (int i =0;i<9;i++){
            if (word[i][col] ==num) return false;
        }
        return true;
    }
    bool checkBox (vector<vector<char>> & word ,int row, int col ,char num){
        int startRow = (row/3 ) * 3;
        int startCol = (col/3) * 3;
        for (int i =startRow;i<startRow + 3;i++){
            for (int j = startCol ;j < startCol + 3; j++) {
                if (word[i][j] == num) return false;
            }
        }
        return true;
    }
    bool check (vector<vector<char>> & word ,int row, int col ,char num){
        if (checkRow(word, row, num) == false) return false;
        if (checkCol(word, col, num) == false) return false;
        if (checkBox(word, row,col, num) == false) return false;
        return true;
    }
    int find(vector<vector<char>> & board , int i , int j){
        if (i == 9) return 1;
        if (j == 9) return find(board, i+1,0);
        if (board[i][j] != '.') return find(board, i, j+1);
        for (int num = 1 ;num<10;num++){
            if (check(board, i , j, num + '0')){
                board[i][j] = num + '0';
                if (find(board, i, j+1)) return 1;
                board[i][j] = '.';
            }
        }
        return 0;
    }
    void solveSudoku(vector<vector<char>>& board) {
        find(board, 0, 0);
    }
};