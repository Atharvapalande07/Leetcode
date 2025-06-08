class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] < arr[i + 1]) {
                sum += (arr[i + 1] - arr[i]);
            }
        }
        return sum;
    }
};