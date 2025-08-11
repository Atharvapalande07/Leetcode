class Solution {
public:
    int M = 1e9 + 7;

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power, ans;

        // Extract powers of 2 from binary representation of n
        for (int i = 0; i <= 31; i++) {
            if ((n >> i) & 1) {
                power.push_back(1 << i);
            }
        }

        // Process each query
        for (const auto& it : queries) {
            int st = it[0];
            int ed = it[1];
            long long prd = 1;
            for (int i = st; i <= ed; i++) {
                prd = (prd * power[i]) % M;
            }
            ans.push_back((int)prd);
        }

        return ans;
    }
};