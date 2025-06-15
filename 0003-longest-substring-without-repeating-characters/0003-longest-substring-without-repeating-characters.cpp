class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);  // store last index of each character
        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            // If character seen and is inside current window
            if (hash[s[right]] >= left) {
                left = hash[s[right]] + 1;  // move left past the last duplicate
            }

            hash[s[right]] = right;  // update last seen index
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
