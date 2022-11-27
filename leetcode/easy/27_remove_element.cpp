/*
Problem Name: 27. Remove Element
Problem Link: https://leetcode.com/problems/remove-element/
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // j=nums.size()-1;
        int cnt=0;
        for(int i:nums){
            if(i==val) cnt++;
        }
        int i=0,j=0;
        while(i<nums.size()){
            if(nums[i]==val) {
                j = max(i+1,j+1);
                while(j<nums.size() and nums[j]==val) j++;
                if(j==nums.size()) break;
                swap(nums[i],nums[j]);
                // cout<<i<<" "<<j<<endl;
                i++;
            }
            else i++;
        }
        return nums.size()-cnt;
    }
};
