/*
Problem Name: 350. Intersection of Two Arrays II
Problem Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m;
        for(int i: nums1){
            m[i]++;
        }
        vector<int> ans;
        for(int i:nums2){
            if(m.find(i)!=m.end()){
                if(m[i]>0){
                    ans.push_back(i);
                    m[i]--;
                }
            }
        }
        return ans;
    }
};
