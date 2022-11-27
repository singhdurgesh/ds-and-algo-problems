/*
Problem Name: 13. Roman to Integer
Problem: https://leetcode.com/problems/roman-to-integer/
*/

class Solution {
public:
    int romanToInt(string s) {
        int curr = 0;
        int ans = 0;
        map<char, int> m;
        m = mapped_roman_data();
        
        if (s.length()==0){
            return 0;
        }
        
        curr = m[s[0]];
        for(int i = 1; i<s.length(); i++){
            if(m[s[i]]==m[s[i-1]]){
                curr += m[s[i]];
            }
            else if(m[s[i]] > m[s[i-1]]){
                curr = m[s[i]] - curr;
                ans += curr;
                curr = 0;
            }else{
                ans += curr;
                curr = m[s[i]];
            }
        }
        ans += curr;
        return ans;
        
    }
    
    map<char, int> mapped_roman_data(){
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        return m;
    }
};
