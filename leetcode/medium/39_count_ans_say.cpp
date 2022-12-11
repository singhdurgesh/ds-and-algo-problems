/*
Problem Name: 39. Count and Say
Problem Link: https://leetcode.com/problems/count-and-say/
*/

class Solution {
public:
    string countAndSay(int n) {
        if (n==1) return "1";
        
        string ans_1 = countAndSay(n-1);
        string ans = "";
        char current = ans_1[0];
        int count = 1;
        for(int i=1; i<ans_1.length(); i++){
            if(current == ans_1[i]){
                count++;
            }else{
                ans += make_string(count, current);
                current = ans_1[i];
                count = 1;
            }
        }
        
        ans += make_string(count, ans_1[ans_1.length()-1]);
        return ans;
    }

    string make_string(int count, char c){
        string ans = "";
        ans += to_string(count);
        ans.push_back(c);
        return ans;
    }
};
