/*
Problem Name: 56. Merge Intervals
Problem Link: https://leetcode.com/problems/merge-intervals/
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int> > ans;

        ans.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            merge_two_intervals(ans[ans.size()-1], intervals[i], ans);
        }
        
        return ans;
    }

    void merge_two_intervals(vector<int> &a, vector<int> &b, vector<vector<int> >& ans){
        if (a[1] < b[0]){
            ans.push_back(b);
        }else{
            ans[ans.size()-1][0] = min(a[0], b[0]);
            ans[ans.size()-1][1] = max(a[1], b[1]);
        }
    }
};
