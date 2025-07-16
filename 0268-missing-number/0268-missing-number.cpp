class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();

        long long totalSum = (long long)n * (n + 1) / 2; // sum of numbers from 0 to n

        int currSum = 0;
        for (int i = 0; i < n; i++) {
            currSum += nums[i];
        }

        return totalSum - currSum; // missing number
    }
};