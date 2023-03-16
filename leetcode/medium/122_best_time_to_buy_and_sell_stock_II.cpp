/*
Problem Name: Best Time to Buy and Sell Stock II
Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int buy = prices[0];
        for(int i=1; i<prices.size(); i++){
            if (prices[i] < buy){
                buy = prices[i];
            }else{
                ans += prices[i] - buy;
                buy = prices[i];
            }
        }
        return ans;
    }
};
