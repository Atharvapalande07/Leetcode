class Solution {
public:

    int solve(vector<int>&dp ,int n){
        if(n < 0) return 0;
        if(n==0) return 1;

        if(dp[n] != -1) return dp[n];

        int one_step = solve(dp ,n-1);
        int two_step = solve(dp ,n-2);
        dp[n] = one_step + two_step;
        return dp[n];
    }
    
    int climbStairs(int n) {

        vector<int>dp(n+1 , -1);
        return solve(dp ,n);
        

        
        
    }
};