/*
Problem Name: Longest String Chain
Problem URL: https://leetcode.com/problems/longest-string-chain/
*/

bool comp(const string & a, const string & b){
    return a.length() < b.length();
}
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<int> ans(words.size());
        sort(words.begin(), words.end(), &comp);

        ans[0] = 1;

        for(int i=1; i<words.size(); i++){
            for(int j=0; j<i; j++){
                if ((words[i].length() - words[j].length() == 1) && is_predecessor_of(words[j], words[i])){
                    if (ans[i] < ans[j]){
                        ans[i] = ans[j];
                    }
                }
            }
            ans[i]+=1;
        }

        int result = 0;
        for(auto v:ans){
            result = max(v, result);
        }
        return result;
    }

    bool is_predecessor_of(string &first, string &second){
        int i=0, j=0, skips = 0;

        while(i<first.length() && j<second.length()){
            if (first[i]!=second[j]){
                j++;
                skips++;
                if(skips > 1) return false;
            }
            else{
                i++;
                j++;
            }
        }

        if(i==first.length() && j==second.length() && skips == 1) return true;
        if(i==first.length() && j==second.length()-1 && skips == 0) return true;
        return false;
    }
};
