/*
Problem Name: 412. Fizz Buzz
Problem Link: https://leetcode.com/problems/fizz-buzz/
*/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i=0; i<n; i++){
            ans.push_back(answers(i+1));
        }
        return ans;
    }
    
    string answers(int n){
        if (n%3==0 && n%5==0){
            return "FizzBuzz";
        }else if(n%3==0){
            return "Fizz";
        }else if(n%5==0){
            return "Buzz";
        }
        return to_string(n);
    }
};
