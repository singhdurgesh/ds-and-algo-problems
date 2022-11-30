/*
Problem Name: 22. Generate Parentheses
Problem Link: https://leetcode.com/problems/generate-parentheses/
*/

class Solution {
public:
    unordered_map<int, vector<string> > mm;
    vector<string> generateParenthesis(int n) {
        if(mm.find(n) != mm.end()) return mm[n];
        
        set<string> s;        
        
        vector<string> ans, temp, temp2, temp3;
        if (n==1){
            ans.push_back("()");
            return ans;
        }
        
        temp = generateParenthesis(n-1);
        for(auto& it:temp){
            s.insert("()"+it);
            s.insert("(" + it + ")");
            s.insert(it + "()");
        }
        
        for(int i=2; i<n; i++){
            temp2 = generateParenthesis(i);
            temp3 = generateParenthesis(n-i);
            for(auto& it:temp2){
                for(auto& it2:temp3){
                    s.insert(it+it2);
                }
            }
        }

        for(auto& it:s){
            ans.push_back(it);
        }
        
        mm[n] = ans;
        return mm[n];
    }
};
