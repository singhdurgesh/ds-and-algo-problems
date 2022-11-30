/*
Problem Name: 11. Container With Most Water
Problem Link: https://leetcode.com/problems/container-with-most-water/
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, last = height.size() - 1;
        
        int ans = 0;
        while(start < last){
            ans = max(ans, (last-start) * min(height[last], height[start]));
            if (height[start]<height[last]){
                start++;
            }else{
                last--;
            }
        }

        return ans;
    }
};
