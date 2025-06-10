class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        
        for (int num : nums) {
            freq[num]++;
        }

        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;

        for (auto& [num, count] : freq) {
            q.push({count, num});
            if (q.size() > k) {
                q.pop();
            }
        }

        
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.top().second); 
            q.pop();
        }

        return result;
    }
};