class Solution {
public:
    int roblinear(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prevprev = nums[0];                 // dp[0]
        int prev = max(nums[0], nums[1]);       // dp[1]

        for (int i = 2; i < n; i++) {
            int steal = nums[i] + prevprev;     // Rob current + dp[i-2]
            int skip = prev;                    // Skip current → dp[i-1]
            int temp = max(steal, skip);        // Best choice
            prevprev = prev;                    // Move window forward
            prev = temp;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> case1(nums.begin(), nums.end() - 1); // exclude last
        vector<int> case2(nums.begin() + 1, nums.end()); // exclude first

        return max(roblinear(case1), roblinear(case2));
    }
};
