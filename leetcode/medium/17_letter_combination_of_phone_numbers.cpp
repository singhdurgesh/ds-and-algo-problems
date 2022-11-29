/*
Problem Name: 17. Letter Combinations of a Phone Number
Problem Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, vector<char> > m = char_mapping();
        
        vector<string> ans;
        for(char c:digits){
            ans = update_string(ans, c, m);
        }
        return ans;
    }
    
    vector<string> update_string(vector<string> &arr, char c, map<char, vector<char> > &m){
        string temp = "";
        vector<string> ans;
        if (arr.size()==0){
            for(int i=0; i<m[c].size(); i++){
                temp = "";
                temp.push_back(m[c][i]);
                ans.push_back(temp);
            }
            
            return ans;
        }
        
        for(int i=0; i<arr.size(); i++){
            for(int j=0; j<m[c].size(); j++){
                ans.push_back(arr[i] + m[c][j]);
            }
        }
        return ans;
    }

    map<char, vector<char> > char_mapping(){
        map<char, vector<char> > m;
        m['2'] = {'a', 'b', 'c'};
        m['3'] = {'d', 'e', 'f'};
        m['4'] = {'g', 'h', 'i'};
        m['5'] = {'j', 'k', 'l'};
        m['6'] = {'m', 'n', 'o'};
        m['7'] = {'p', 'q', 'r', 's'};
        m['8'] = {'t', 'u', 'v'};
        m['9'] = {'w', 'x', 'y', 'z'};
        return m;
    }
};
