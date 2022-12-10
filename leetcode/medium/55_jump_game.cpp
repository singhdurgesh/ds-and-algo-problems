/*
Problem Name: 55. Jump Game
Problem Link: https://leetcode.com/problems/jump-game/
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr = nums[0];
        int i=0;
        while(i<=curr){
            if (i==nums.size()-1) return true;

            curr = max(curr, i+nums[i]);
            i++;
        }
        return false;
        
    }

    // TLE Implementation
    bool canJum(vector<int> &nums) {
      queue<int> q;
        vector<int> visited(nums.size(), 0);
        
        q.push(0);
        while(!q.empty()){
            int val = q.front();
            q.pop();
            if(val == nums.size()-1) return true;
            if(visited[val] != 0) continue;

            visited[val] = 1;

            if(val + nums[val] >= nums.size() -1) return true;
            for(int i=1; i<=nums[val]; i++){
                if (val + i < nums.size()) q.push(val + i);
            }
        }
        return false;
    }
};

