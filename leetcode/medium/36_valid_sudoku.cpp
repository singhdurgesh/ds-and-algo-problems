/*
Problem Name: 36. Valid Sudoku
Problem Link: https://leetcode.com/problems/valid-sudoku/
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool valid = true;
        for(int i=0; i<9; i++){
            valid &= isValidSudokuLength(board, i);
            valid &= isValidSudokuBreadth(board, i);
            valid &= isValidSudokuBox(board, i);
        }
        return valid;
    }
    
    bool isValidSudokuLength(vector<vector<char>>& board, int ind){
        vector<int> v(9, 0);
        int val = -1;
        for(int i=0; i<9; i++){
            if (board[i][ind] == '.') continue;
            val = board[i][ind] -'1';
            v[val]++;
        }
        for(int i:v){
            if (i>1) return false;
        }
        return true;
    }
    
    bool isValidSudokuBreadth(vector<vector<char>>& board, int ind){
        vector<int> v(9, 0);
        int val;
        for(int i=0; i<9; i++){
            if (board[ind][i] == '.') continue;
            val = board[ind][i] -'1';
            v[val]++;
        }
        for(int i:v){
            if (i>1) return false;
        }
        return true;
    }

    bool isValidSudokuBox(vector<vector<char>>& board, int ind){
        int l = (3 * ind)%9;
        int r = ((3 * ind)/9) * 3;
        vector<int> v(9, 0);
        int val;
        for(int i=l; i<l+3; i++){
            for(int j=r; j<r+3; j++){
                if (board[i][j] == '.') continue;
                val = board[i][j] -'1';
                v[val]++;
            }
        }
        for(int i:v){
            if (i>1) return false;
        }
        return true;
    }
};
