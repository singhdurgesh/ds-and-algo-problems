/*
Problem Name: 29. Divide Two Integers
Problem Link: https://leetcode.com/problems/divide-two-integers/
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = -1;
        if (dividend > 0){
            sign = 0 - sign;
            dividend = 0 - dividend;
        }
        
        if (divisor > 0){
            sign = 0 - sign;
            divisor = 0 - divisor;
        }

        if (divisor == -1){
            if (sign == 1){
                return 0 - abs(dividend);
            }
            if (dividend == INT_MIN) return INT_MAX;
            return abs(dividend);
        }

        if (divisor < dividend) return 0;
        if (divisor == dividend) return 0-sign;
        if (divisor < dividend - divisor) return 0-sign;

        int val = divide(dividend, divisor + divisor);

        for(int i=0; i<abs(val); i++){
            dividend -= divisor + divisor;
        }

        int ans = divide(dividend, divisor);

        ans = abs(ans) + abs(val) + abs(val);
        return (sign == -1) ? ans : (0-ans);
    }
};
