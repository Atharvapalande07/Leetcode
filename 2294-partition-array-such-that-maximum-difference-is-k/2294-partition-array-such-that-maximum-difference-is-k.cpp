class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        int pivot = n - 1, cmp = n - 1;
        sort(nums.begin(), nums.end());

        while (cmp >= 0) {
            if (nums[pivot] - nums[cmp] <= k) {
                cmp--;
            } else {
                pivot = cmp;
                res++;
            }
        }
        return res + 1;
    }
};