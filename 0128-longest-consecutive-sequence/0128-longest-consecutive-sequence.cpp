class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> el(nums.begin(), nums.end());
        int longest = 0;

        for (int num : el) {
            // only start counting if it's the beginning of a sequence
            if (el.find(num - 1) == el.end()) {
                int curr = num;
                int cnt = 1;

                while (el.find(curr + 1) != el.end()) {
                    curr++;
                    cnt++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};