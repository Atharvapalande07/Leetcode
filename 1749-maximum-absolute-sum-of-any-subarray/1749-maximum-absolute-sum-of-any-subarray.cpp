class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, maxPos = 0, maxNeg = 0;
        for(int i = 0, n = nums.size(); i < n; ++i){
            int num = nums[i];
            maxPos = max(num , maxPos + num);
            maxNeg = min(num , maxNeg + num);
            maxSum = max(maxSum , max(maxPos , -maxNeg));
        }
        return maxSum;
    }
};