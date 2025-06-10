class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mpp1;
        
        // Store elements of nums1 in the map
        for (auto num : nums1) {
            if (mpp1.find(num) == mpp1.end()) {
                mpp1[num] = 0;
            }
        }

        // Check if elements of nums2 exist in the map
        for (auto num : nums2) {
            if (mpp1.find(num) != mpp1.end()) {
                mpp1[num]++;
            }
        }

        // Collect elements that exist in both arrays
        vector<int> intersection;
        for (auto it : mpp1) {
            if (it.second >= 1) {
                intersection.push_back(it.first);
            }
        }

        return intersection;
    }
};