/*
Problem Name: Pow(x, n)
Problem Link: https://leetcode.com/problems/powx-n/
*/

class Solution {
public:
    double myPow(double x, int n) {
        if (n==0) return 1;
        if (n==1) return x;
        if (n==-1) return 1/x;
        
        double val = myPow(x, n/2);
        if(abs(n)%2 ==0){
            return val * val;
        }

        return ((n > 0) ? x : 1/x) * val * val;
    }
};
