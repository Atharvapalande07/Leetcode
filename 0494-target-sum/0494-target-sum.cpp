class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int,int>dp;
        dp[0]=1;
        for(auto x:nums){
            unordered_map<int,int>nextdp;
            for(auto [sum,count]:dp){
                nextdp[sum+x]+=count;
                nextdp[sum-x]+=count;
            }
            dp=move(nextdp);
        }
        return dp[target];
    }
};