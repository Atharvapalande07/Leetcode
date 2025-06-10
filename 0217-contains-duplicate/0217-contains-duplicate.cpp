class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numSet;
        for (int num : nums) {
            // If the number is already in the set, we found a duplicate
            if (numSet.find(num) != numSet.end()) {
                return true;
            }
            // Otherwise, add the number to the set
            numSet.insert(num);
        }
        return false;
    }
};