class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> seen;
        int maxVal = INT_MIN;
        int sum = 0;

        for (int num : nums) {
            if (num > 0 && seen.find(num) == seen.end()) {
                sum += num;
                seen.insert(num);
            }
            maxVal = max(maxVal, num);
        }

        // Ensure the maximum value is added (if it was missed)
        if (maxVal > 0 && seen.find(maxVal) == seen.end()) {
            sum += maxVal;
        }

        // If all elements were <= 0, return the max (least negative) element
        if (maxVal <= 0)
            return maxVal;

        return sum;
    }
};