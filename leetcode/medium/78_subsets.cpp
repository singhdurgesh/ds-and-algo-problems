/*
Problem Name: 78. Subsets
Problem Link: https://leetcode.com/problems/subsets/
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int> > ss;
        vector<int> v;
        vector<int> curr;
        for(int i=0; i<nums.size(); i++){
            subsetFill(nums,i+1, ss, curr);
            curr.push_back(nums[i]);
            subsetFill(nums,i+1,ss,curr);
            curr.pop_back();
        }

        vector<vector<int> > ans;
        for(auto v:ss){
            ans.push_back(v);
        }
        return ans;
    }

    void subsetFill(vector<int>& nums, int ind, set<vector<int> > &ss, vector<int> &curr){
        if (ind==nums.size()) {
            ss.insert(curr);
            return;
        }

        for(int i=ind; i<nums.size(); i++){
            subsetFill(nums, i+1, ss, curr);
            curr.push_back(nums[i]);
            subsetFill(nums, i+1, ss, curr);
            curr.pop_back();
        }
    }
};
