/*
Problem Name: 33. Search in Rotated Sorted Array
Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search_sorted_array(nums, target, 0, nums.size()-1);
    }
    
    int search_sorted_array(vector<int>& nums, int target, int start, int end){
        if (start > end) return -1;

        int mid = (start+end)/2;
        if (nums[mid]==target) return mid;

        if (nums[start] <= nums[mid] && nums[mid] > target && nums[start] <= target){
            return search_sorted_array(nums, target, start, mid-1);
        }

        if (nums[end] >= nums[mid] && nums[mid] < target && nums[end] >= target){
            return search_sorted_array(nums, target, mid+1, end);
        }

        if (nums[start] <= nums[mid]){
            return search_sorted_array(nums, target, mid+1, end);
        }

        return search_sorted_array(nums, target, start, mid-1);
    }
};
