/*
Problem Name: 49. Group Anagrams
Problem Link: https://leetcode.com/problems/group-anagrams/
*/

class Solution {
public:
    map<string, vector<string> > m;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for(string s:strs){
            m[get_key_for(s)].push_back(s);
        }
        
        vector<vector<string> > ans;
        for(auto it=m.begin(); it!=m.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
    
    string get_key_for(string& s){
        vector<int> v(26, 0);
        for(char c:s){
            v[c-'a']++;
        }
        string ans = "";
        for(int i:v){
            ans+=to_string(i) + "$";
        }
        return ans;
    }
};
