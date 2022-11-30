/*
Problem Name: 8. String to Integer (atoi)
Problem Link: https://leetcode.com/problems/string-to-integer-atoi/
*/

class Solution {
public:
    int myAtoi(string s) {
        int i=0, sign = 1;
        long long ans = 0;
        
        while(i<s.length() && s[i]==' '){
            i++;
        }
        
        if (i==s.length()) return 0;
        
        if (s[i]=='-' || s[i]=='+'){
            if (s[i]=='-'){
                sign=-1;
            }
            i++;
        }

        while(i<s.length()){
            if(s[i] <= '9' && s[i] >= '0'){
                ans = ans*10 + s[i]-'0';
                if(sign < 0){
                    if (ans - 1 > INT_MAX) return INT_MIN;
                }else{
                    if (ans > INT_MAX) return INT_MAX;
                }
            }else{
                break;
            }
            i++;
        }

        return ans*sign;
    }
};
