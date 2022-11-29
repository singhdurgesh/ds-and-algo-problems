/*
Problem Name: 5. Longest Palindromic Substring
Problem Link: https://leetcode.com/problems/longest-palindromic-substring/
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int ans = 1;
        int ans_f = 0, ans_l = 0;
        vector<int> vec;
        for(int i=0; i<s.length(); i++){
            vec = maxLengthPalindromeIndex(s,i);
            if (ans < vec[0]){
                ans_f = vec[1];
                ans_l = vec[2];
                ans = vec[0];
            }
        }

        for (int i=0; i<s.length()-1; i++){
            vec = maxLengthPalindromeTwoIndex(s,i, i+1);
            if (ans < vec[0]){
                ans_f = vec[1];
                ans_l = vec[2];
                ans = vec[0];
            }
        }
        
        return s.substr(ans_f, ans_l-ans_f+1);
    }
    
    vector<int> maxLengthPalindromeIndex(string &s, int ind){
        int ans = 1;
        int left = ind - 1;
        int right = ind + 1;
        while(left >= 0 && right < s.length()){
            if (s[left]!=s[right]){
                break;
            }
            ans+=2;
            left--;
            right++;
        }
        
        return vector_v(ans, left+1, right-1);
    }

    vector<int> maxLengthPalindromeTwoIndex(string &s, int first, int sec){
        int ans =0;
        while(first>=0 && sec <s.length()){
            if (s[first]!=s[sec]){
                break;
            }
            ans+=2;
            first--;
            sec++;
        }

        return vector_v(ans, first+1, sec-1);
    }
    
    vector<int> vector_v(int a, int b, int c){
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        return v;
    }
};
