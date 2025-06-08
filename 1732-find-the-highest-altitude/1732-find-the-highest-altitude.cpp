class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int height = 0;
        int res = 0;
        for (const int& net_gain : gain) {
            height += net_gain;
            res = std::max(res, height);
        }
        return res;
        
    }
};