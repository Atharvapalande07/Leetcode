class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        int n = s.length();

        // Count frequency of each character
        for (int i = 0; i < n; i++) {
            freq[s[i]]++;
        }

        // Move map data to vector
        vector<pair<char, int>> freqVec(freq.begin(), freq.end());

        // Sort by frequency (highest first)
        sort(freqVec.begin(), freqVec.end(), [](pair<char, int>& a, pair<char, int>& b) {
            return a.second > b.second;
        });

        // Build the result string
        string result = "";
        for (auto& p : freqVec) {
            result += string(p.second, p.first);  // repeat the character
        }

        return result;
    }
};
