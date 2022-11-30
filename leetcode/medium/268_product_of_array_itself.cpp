/*
Problem Name: 268. Missing Number
Problem Link: https://leetcode.com/problems/missing-number/
*/

/*
Solution 1
Time Complexity: O(N)
Space Complexity: O(N)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left, right(nums.size());
        int ans = 1;
        for(int i:nums){
            ans*=i;
            left.push_back(ans);
        }

        ans = 1;
        
        for(int i=nums.size()-1; i>0; i--){
            ans *= nums[i];
            right[i] = ans;
        }

        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            if(i==0){
                result.push_back(right[i+1]);
            }else if(i==nums.size() - 1){
                result.push_back(left[i-1]);
            }else{
                result.push_back(left[i-1] * right[i+1]);
            }
        }

        return result;
    }
};

/*
Solution 2
Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int val = 1, val2 = 1;
        for(int i=0; i<nums.size()-1; i++){
            val*=nums[i];
            ans[i+1] = val;
        }

        val = 1;
        for(int i=nums.size()-1; i>=1; i--){
            val *= nums[i];

            ans[i-1] *= val;
        }
        
        return ans;
    }
};
