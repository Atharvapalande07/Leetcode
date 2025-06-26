class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return;  // Edge case: nothing to permute

        int index = -1;

        // Step 1: Find the first decreasing element from the right
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                index = i - 1;
                break;
            }
        }

        // Step 2: Find the next greater element on the right and swap
        if (index != -1) {
            for (int j = n - 1; j > index; j--) {
                if (nums[j] > nums[index]) {
                    swap(nums[j], nums[index]);
                    break;
                }
            }
        }

        // Step 3: Reverse the suffix
        reverse(nums.begin() + index + 1, nums.end());
    }
};
