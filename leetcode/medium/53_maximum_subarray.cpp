/*
Problem Name: 53. Maximum Subarray
Problem Link: https://leetcode.com/problems/maximum-subarray/
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0, ans = INT_MIN;

        for(int i:nums){
            curr += i;
            ans = max(ans, curr);
            if(curr < 0){
                curr = 0;
            }
        }
        return ans;
    }
};
