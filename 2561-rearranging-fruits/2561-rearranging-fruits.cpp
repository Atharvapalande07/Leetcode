class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> freq;
        int n = basket1.size();

        for (int i = 0; i < n; ++i) {
            freq[basket1[i]]++;
            freq[basket2[i]]--;
        }

        vector<int> surplus;
        int mini = INT_MAX;

        for (auto &[val, count] : freq) {
            if (count % 2 != 0) return -1;
            for (int i = 0; i < abs(count) / 2; ++i) {
                surplus.push_back(val);
            }
            mini = min(mini, val);
        }

        sort(surplus.begin(), surplus.end());

        long long cost = 0;
        int k = surplus.size() / 2;

        for (int i = 0; i < k; ++i) {
            cost += min((long long)surplus[i], 2LL * mini);
        }

        return cost;
    }
};