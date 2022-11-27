/*
Problem Name: 14. Longest Common Prefix
Problem: https://leetcode.com/problems/longest-common-prefix/
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        int ind = 0;
        while (true){
            char c = strs[0][ind];
            bool check = true;
            for(int i=0; i<strs.size(); i++){
                if (strs[i].size() < ind + 1){
                    check = false;
                    break;
                }
                if (strs[i][ind] != c){
                    check = false;
                    break;
                }
            }
            
            if (check == false){
                break;
            }
            s.push_back(c);
            ind ++;
        }
        
        return s;
        
        
    }
};
