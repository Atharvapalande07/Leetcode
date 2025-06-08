class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }

        set<int> seenFrequencies;
        for (auto [key, value] : freq) {
            if (seenFrequencies.count(value)) {
                return false;
            }
            seenFrequencies.insert(value);
        }

        return true;
    }
};