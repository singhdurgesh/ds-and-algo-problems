/*
Problem Name: Word Search
Problem Link: https://leetcode.com/problems/word-search/
My Solution: https://leetcode.com/problems/word-search/solutions/2896904/simple-and-elegent-cpp-solution/
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int> > visited(board.size(), vector<int>(board[0].size()));

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if (board[i][j]==word[0]){
                    if (check_word_from_board(board, word, 0, visited, i, j)){
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool check_word_from_board(vector<vector<char>> & board, string & word, int ind, vector<vector<int> > &visited, int x, int y){
        if (ind == word.length()) return true;
        if (x <  0 || y < 0 || x >= board.size() || y >= board[0].size()) return false;

        if (word[ind]!=board[x][y]) return false;
        if (visited[x][y] == 1) return false;
        visited[x][y] = 1;

        bool ans = false;
        ans |= check_word_from_board(board, word, ind+1, visited, x+1, y);
        ans |= check_word_from_board(board, word, ind+1, visited, x-1, y);
        ans |= check_word_from_board(board, word, ind+1, visited, x, y+1);
        ans |= check_word_from_board(board, word, ind+1, visited, x, y-1);

        visited[x][y] = 0;
        return ans;
    }
};
