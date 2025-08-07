class Solution {
public:

    int solve(vector<int>&dp , int n){
        if( n <=1 ) return n;

        if(dp[n] != -1) return dp[n];
        return dp[n] = solve(dp ,n-1) + solve(dp ,n-2);
    }
    int fib(int n) {
        if(n <= 1) return n;

        vector<int>dp(n+1 , -1);
        solve(dp ,n);
        return solve(dp ,n);
        
    }
};