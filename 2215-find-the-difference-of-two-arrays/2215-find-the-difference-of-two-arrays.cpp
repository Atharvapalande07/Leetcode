class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> set1(2001), set2(2001);
        for (int num : nums1) set1[num + 1000] = true;
        for (int num : nums2) set2[num + 1000] = true;
        return {CleanSet(set1, set2), CleanSet(set2, set1)};
    }
private:
    vector<int> CleanSet(vector<bool>& set1, vector<bool>& set2)
    {
        vector<int> lst;
        for (int i = 0; i < 2001; i++)
            if (set1[i] && !set2[i]) lst.push_back(i - 1000);
        return lst;
    }
};