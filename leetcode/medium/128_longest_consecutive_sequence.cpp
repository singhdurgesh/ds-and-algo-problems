/*
Problem Name: 128. Longest Consecutive Sequence
Problem Link: https://leetcode.com/problems/longest-consecutive-sequence/description/
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> v;
        for(int i:nums){
            v[i]++;
        }

        int curr=0, val = 0, ans = 0;

        for(auto it=v.begin(); it!=v.end(); it++){
            int num = it->first;
            if(val == 0){
                curr = num;
                val = 1;
            }else if(curr == num-1){
                curr = num;
                val++;
            }else{
                ans = max(ans, val);
                curr = num;
                val = 1;
            }
        }

        return max(ans, val);
    }
};
