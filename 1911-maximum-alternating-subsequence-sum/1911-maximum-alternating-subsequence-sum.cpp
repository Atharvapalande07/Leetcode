class Solution {
public:
    long long dp[100005][2]; // dp[idx][flag]

    long long solve(vector<int>& nums, int idx, bool flag) {
        if (idx >= nums.size()) return 0;

        if (dp[idx][flag] != -1) return dp[idx][flag];

        long long skip = solve(nums, idx + 1, flag);

        long long val = nums[idx];


        if (flag == false) val = -val;

        long long take = val + solve(nums, idx + 1, !flag);

        return dp[idx][flag] = max(skip, take);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, true);
    }
};
