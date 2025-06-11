class Solution {
    bool partition(int ind, int target,vector<int> &nums,vector<vector<int>>&dp){
        if(target == 0) return true;
        if(ind == 0) return nums[ind] == target;

        if(dp[ind][target] != -1) return dp[ind][target];
        bool pick = false;
        if(nums[ind] <= target){
            pick = partition(ind-1,target-nums[ind],nums,dp);
        }
        bool notpick = partition(ind-1,target,nums,dp);

        return dp[ind][target] =  pick|notpick;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        if(sum%2 == 1) return false;
        int target = sum/2;

        vector<vector<int>> dp(n, vector<int>(target+1,-1));
        return partition(nums.size()-1,target,nums,dp);
    }
};