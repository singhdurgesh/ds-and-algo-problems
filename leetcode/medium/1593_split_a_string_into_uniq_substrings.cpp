/*
Problem Name: 1593. Split a String Into the Max Number of Unique Substrings
Problem Link: https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/
*/

// Solution 1: Backtracking
// Language: C++
class Solution {
public:
    int ans = 1;
    int maxUniqueSplit(string s) {
        ans = 1;
        string temp = "";
        vector<string> vec;
        for(int i=0; i<s.length(); i++){
            temp.push_back(s[i]);
            vec.push_back(temp);
            solve(s, 1, i+1, vec);
            vec.pop_back();
            
        }
        return ans;
    }

    void solve(string &origin, int count, int ind, vector<string> &vec){
        if (ind == origin.length()){
            ans = max(ans, count);
            // for(string s:vec){
            //     cout<<s<<" ";
            // }
            // cout<<endl;
            return;
        }

        string temp = "";
        for(int i=ind; i<origin.length(); i++){
            temp.push_back(origin[i]);
            if (!check_presence_of_str(vec, temp)){
                vec.push_back(temp);
                solve(origin, count+1, i+1, vec);
                vec.pop_back();
            }
        }
    }

    int check_presence_of_str(vector<string> &vec, string str){
        for(string s:vec){
            if (s==str) return true;
        }
        return false;
    }
};
