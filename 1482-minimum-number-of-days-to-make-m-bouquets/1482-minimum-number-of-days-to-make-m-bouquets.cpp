class Solution {
public:
    // Check if it is possible to make m bouquets in "day" days
    bool Possible(vector<int>& bloomDay, int day, int m, int k) {
        int count = 0;
        int TotalBouq = 0;

        for(int i = 0; i < bloomDay.size(); i++) {
            if(bloomDay[i] <= day) {
                count++;
                if(count == k) {
                    TotalBouq++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        return TotalBouq >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowers = 1LL * m * k;
        if(bloomDay.size() < totalFlowers) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(Possible(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
