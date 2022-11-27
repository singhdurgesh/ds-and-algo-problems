/*
Problem Name: 283. Move Zeroes
Problem Link: https://leetcode.com/problems/move-zeroes/
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 0){
            return;
        }
        
        int slow = 0, fast = 0;
        while (fast < nums.size()){
            if (nums[fast] != 0){
                nums[slow] = nums[fast];
                slow++;
            }
            
            fast++;
        }
        
        while (slow < nums.size()){
            nums[slow] = 0;
            slow++;
        }
    }
};
