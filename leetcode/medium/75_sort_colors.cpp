/*
Problem Name: 75. Sort Colors
Problem Link: https://leetcode.com/problems/sort-colors/
*/

// Solution 1: Using Counting Sort
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> v(3, 0);
        for(int i:nums){
            v[i]++;
        }
        
        for(int i=0; i<v[0]; i++){
            nums[i] = 0;
        }
        
        for(int i=v[0]; i<v[1]+v[0]; i++){
            nums[i] = 1;
        }

        for(int i=v[1]+v[0]; i<v[2]+v[0]+v[1]; i++){
            nums[i] = 2;
        }
    }
};

// Solution 2: Using Insertion Sort
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 1, blue = 2;
        int curr_r = 0, curr_b = nums.size() - 1, curr = 0;
        
        while(curr_b >=0 && curr < nums.size()){
            if(nums[curr]==blue && curr < curr_b){
                while(curr_b >=0 && nums[curr_b] == 2){
                    curr_b--;
                }
                
                if(curr_b < 0 || curr >= curr_b) break;
                
                int temp = nums[curr_b];
                nums[curr_b] = blue;
                curr_b--;
                nums[curr] = temp;
            }else{
                curr++;
            }
        }
        
        curr = nums.size()-1;
        while(curr_r < nums.size() && curr >=0 ){
            if (nums[curr]==red && curr > curr_r){
                while(curr_r <nums.size() && nums[curr_r] == red){
                    curr_r++;
                }

                if(curr_r >= nums.size() || curr <= curr_r) break;

                int temp = nums[curr_r];
                nums[curr_r] = red;
                curr_r++;
                nums[curr] = temp;
            }else{
                curr--;
            }
        }
    }
};
