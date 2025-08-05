class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> freq;
        int n = fruits.size();

        int i = 0;
        int maxlen = 0;

        for (int j = 0; j < n; j++) {
            freq[fruits[j]]++;

            while (freq.size() > 2) {
                freq[fruits[i]]--;

                if (freq[fruits[i]] == 0) {
                    freq.erase(fruits[i]);
                }
                i++;
            }
            maxlen = max(maxlen, j - i + 1);
        }
        return maxlen;
    }
};