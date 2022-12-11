/*
Problem Name: 73. Set Matrix Zeroes
Problem Link: https://leetcode.com/problems/set-matrix-zeroes/
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int > r,c;
        int n =matrix.size();
        int m = matrix[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    r.insert(i);
                    c.insert(j);
                }
            }
        }

        for(auto i:r){
            for(int j=0; j<m; j++){
                matrix[i][j] = 0;
            }
        }

        for(auto j:c){
            for(int i=0; i<n; i++){
                matrix[i][j] = 0;
            }
        }
    }
};
