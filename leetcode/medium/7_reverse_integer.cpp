/*
Problem Name: 7. Reverse Integer
Problem Link: https://leetcode.com/problems/reverse-integer/
*/

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Integer.
// Memory Usage: 5.8 MB, less than 75.90% of C++ online submissions for Reverse Integer.

class Solution {
public:
    int reverse(int x) {
        int ans = 0, ind = 0, sign = (x < 0) ? -1 : 1, val = abs(x);
        
        int len = 0;
        while(val){
            len++;
            val/=10;
        }
        
        val = abs(x);
        while(val){
            if(ans!=0 && INT_MAX/ans < 10) return 0;

            ans = ans*10 + val%10;

            ind++;
            val/=10;
            if (ans < 0) return 0;
        }

        return ans * sign;
    }
};
