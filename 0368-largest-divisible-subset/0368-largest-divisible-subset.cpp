class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), hash(n);
        int maxi = 1, lastIdx = 0;
        for(int idx=0; idx<n; idx++){
			hash[idx] = idx;
            for(int prev=0; prev<idx; prev++){
                if(nums[idx] % nums[prev] == 0 && 1+dp[prev] > dp[idx]){
                    dp[idx] = 1 + dp[prev];
					hash[idx] = prev;
                }
            }
            if(dp[idx] > maxi){
				maxi = dp[idx];
				lastIdx = idx;
			}
        }
		vector<int> ans(maxi, 0);
		ans[0] = nums[lastIdx];
		int idx = 1;
		while(hash[lastIdx] != lastIdx){
			lastIdx = hash[lastIdx];
			ans[idx++] = nums[lastIdx];
		}
		reverse(ans.begin(), ans.end());
		return ans;
    }
};