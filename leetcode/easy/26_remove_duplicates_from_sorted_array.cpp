/*
Problem Name: 26. Remove Duplicates from Sorted Array
Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==0){
            return 0;
        }
        
        int ans = 1;
        int val = nums[0], curr = 0;
        for (int i=1; i<nums.size(); i++){
            if (nums[i] != val){
                nums[curr+1] = nums[i];
                curr ++;
                val = nums[i];
                ans++;
            }
        }
        return ans;
    }
};
