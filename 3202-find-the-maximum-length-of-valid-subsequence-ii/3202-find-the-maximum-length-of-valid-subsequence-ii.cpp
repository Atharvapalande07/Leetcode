class Solution {
public:
    static int maximumLength(vector<int>& nums, int k) {
        short ans = 0;
        vector<short> dp(k);  // dp[mod] = length of subseq ending with num % k == mod

        for (int targetMod = 0; targetMod < k; ++targetMod) {
            dp.assign(k, 0); // reset for each mod
            for (int x : nums) {
                int mod = x % k;
                int required = (targetMod + k - mod) % k;
                dp[mod] = max(dp[mod], (short)(dp[required] + 1));
                ans = max(ans, dp[mod]);
            }
        }

        return ans;
    }
};