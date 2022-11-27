/*
Problem Name: 118. Pascal's Triangle
Problem Link: https://leetcode.com/problems/pascals-triangle/
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > v;
        vector<int> temp;
        temp.push_back(1);
        v.push_back(temp);
        for(int i=1;i<=numRows-1; i++){
            vector<int> ans;
            ans.push_back(1);
            for(int j=0; j < temp.size(); j++){
                if (j==temp.size()-1){
                    break;
                }
                ans.push_back(temp[j]+temp[j+1]);
            }
            ans.push_back(1);
            v.push_back(ans);
            temp = ans;
        }
        return v;
    }
};
