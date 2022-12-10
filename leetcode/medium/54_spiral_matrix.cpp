/*
Problem Name: 54. Spiral Matrix
Problem Link: https://leetcode.com/problems/spiral-matrix/
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l=0, r=matrix[0].size()-1;
        int t=0, d=matrix.size()-1;
        int i=0, j=0, dir = 0;
        int count = 0, total = (r+1)*(d+1);
        vector<int> ans;

        while(count < total){
            ans.push_back(matrix[i][j]);
            if(dir==0){
                j++;
                if (j>r){
                    t++;
                    i = t;
                    j = r;
                    dir = 1;
                }
            }else if(dir==1){
                i++;
                if(i>d){
                    r--;
                    i = d;
                    j = r;
                    dir = 2;
                }
            }else if(dir == 2){
                j--;
                if(j<l){
                    d--;
                    i=d;
                    j=l;
                    dir=3;
                }
            }else{
                i--;
                if(i<t){
                    l++;
                    i=t;
                    j=l;
                    dir = 0;
                }
            }
            count++;
        }

        return ans;
        
    }
};
