/*
Problem Name: 62. Unique Paths
Problem Link: https://leetcode.com/problems/unique-paths/
*/

// Solution 1: Recursive DP
class Solution {
public:
    vector<vector<int> > dp;
    int uniquePaths(int m, int n) {
        dp = vector<vector<int> > (101, vector<int> (101, -1));
        return uniquePathsCal(m, n);
    }

    int uniquePathsCal(int m, int n){
        if(dp[m][n]!=-1) return dp[m][n];

        if (m<1 || n<1) return 0;
        if(m==1 && n==1) return dp[m][n]=1;

        return dp[m][n] = uniquePathsCal(m-1, n) + uniquePathsCal(m, n-1);
    }
};

// Solution 2: Iterative DP
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[n][m];
        for (int i=0; i<n; i++) dp[i][0] = 1;
        for (int i=0; i<m; i++) dp[0][i] = 1;
        for (int i=1; i<n;i++){
            for (int j=1; j<m; j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};
