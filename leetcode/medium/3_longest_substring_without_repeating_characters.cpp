/*
Problem Name: 3. Longest Substring Without Repeating Characters
Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Sliding Window Problem

        // Handle Edge Cases
        if (s.length() == 0) return 0;

        vector<int> count(256, 0);

        int first = 0, sec = 1;
        
        int ans = 1;
        count[s[0]]++;

        while(sec < s.length()){
            count[s[sec]]++;
            sec++;
            if (uniq_elements_arr(count)){
                ans = max(ans, sec-first);
            }else{
                while(uniq_elements_arr(count) == false){
                    count[s[first]]--;
                    first++;
                }
            }
        }

        return ans;
    }

    bool uniq_elements_arr(vector<int> &arr){
        for(int i:arr){
            if (i > 1) return false;
        }
        return true;
    }
};
