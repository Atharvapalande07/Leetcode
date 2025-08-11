class Solution {
public:

    int roblinear(vector<int>&nums){
        int n = nums.size();
        vector<int>dp(n+1 , 0);
        dp[0]=0;
        dp[1]=nums[0];
        
        for(int i=2 ; i<=n ; i++){
            int steal = nums[i-1]+ dp[i-2];
            int skip = dp[i-1];
            dp[i]=max(steal , skip);
        }
        return dp[n];
    }
    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n == 1) return nums[0];
        if( n == 2) return max(nums[0] , nums[1]);

        vector<int> case1(nums.begin() , nums.end()-1);
        vector<int> case2(nums.begin()+1 , nums.end());

        return max(roblinear(case1) , roblinear(case2));
        
    }
};