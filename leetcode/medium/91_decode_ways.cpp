/*
Problem Name: 91. Decode Ways
Problem URL: https://leetcode.com/problems/decode-ways/
*/

class Solution {
public:
    int numDecodings(string s) {
        vector<int> result(s.length(), -1);
        return numDecodingsAns(s, 0, result);
    }

    int numDecodingsAns(string &s, int ind, vector<int> &result){
        if (ind > s.length()) return 0;
        if (ind == s.length()) return 1;

        if (result[ind]!=-1) return result[ind];

        int ans = 0;
        string str = "";
        str.push_back(s[ind]);
        int x,y;
        x = stoi(str);
        if(x > 0 && x <= 26){
            ans += numDecodingsAns(s, ind+1, result);
            if(ind < s.length()-1){
                str.push_back(s[ind+1]);
                y = stoi(str);
                if (y > 0 && y <= 26){
                    ans += numDecodingsAns(s, ind+2, result);
                }
            }
        }

        return result[ind] = ans;
    }
};
