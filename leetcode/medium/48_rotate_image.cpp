/*
Problem Name: 48. Rotate Image
Problem Link: https://leetcode.com/problems/rotate-image/
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        rotate_matrix(matrix, 0, matrix.size());
    }
    
    void rotate_matrix(vector<vector<int> > &matrix, int start, int end){
        if (end - start < 2 ) return;
        
        int n = end;
        for(int j=start; j<n-1; j++){
            int temp = matrix[start][j];
            matrix[start][j] = matrix[start + n-j-1][start];
            matrix[start + n-j-1][start] = matrix[n-1][start + n-j-1];
            matrix[n-1][start + n-j-1] = matrix[j][n-1];
            matrix[j][n-1] = temp;
        }

        rotate_matrix(matrix, start + 1, end - 1);
    }
};
