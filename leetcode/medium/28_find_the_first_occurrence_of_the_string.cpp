/*
Problem Name: 28. Find the first occurance of the string
Problem Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int count = 0;
        for(int i=0; i<haystack.length(); i++){
            count = 0;
            for(int j=0; j<needle.length(); j++){
                if(needle[j]!=haystack[i+j]){
                    break;
                }
                count++;
            }
            if (needle.length()==count){
                return i;
            }
        }
        return -1;
    }
};
