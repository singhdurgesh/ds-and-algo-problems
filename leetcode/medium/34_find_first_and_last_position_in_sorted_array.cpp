/*
Problem Name: 34. Find First and Last Position in Sorted Array
Problem Link: https://leetcode.com/problems/find-first-and-last-position-in-sorted-array/
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = searchRangeLeft(nums, target, 0, nums.size()-1);
        int r = searchRangeRight(nums, target, 0, nums.size()-1);
        return vector<int>{l, r};
    }
    
    int searchRangeLeft(vector<int> &nums, int target, int start, int end){
        if (start > end) return -1;
        if (start==end){
            if (nums[start]==target){
                return start;
            }else{
                return -1;
            }
        }
        
        if (end-start == 1){
            if (nums[start]==nums[end]){
                if (nums[start]==target){
                    return start;
                }else{
                    return -1;
                }
            }else{
                if(nums[start]==target){
                    return start;
                }else if(nums[end]==target){
                    return end;
                }
                return -1;
            }
        }
        
        int mid = (start + end)/2;
        
        if (nums[mid] >= target){
            return searchRangeLeft(nums, target, start, mid);
        }
        return searchRangeLeft(nums, target, mid+1, end);
    }

    int searchRangeRight(vector<int> &nums, int target, int start, int end){
        if (start > end) return -1;
        if (start==end){
            if (nums[start]==target){
                return start;
            }else{
                return -1;
            }
        }
        
        if (end-start == 1){
            if (nums[start]==nums[end]){
                if (nums[start]==target){
                    return end;
                }else{
                    return -1;
                }
            }else{
                if(nums[start]==target){
                    return start;
                }else if(nums[end]==target){
                    return end;
                }
                return -1;
            }
        }

        int mid = (start + end)/2;

        if (nums[mid] <= target){
            return searchRangeRight(nums, target, mid,end);
        }
        return searchRangeRight(nums, target, start, mid-1);
    }
};
