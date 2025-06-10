class Solution {
private:
    int profit(int ind,int buy,vector<int>&prices,vector<vector<int>>&dp,int fee){
         if(ind>=prices.size())return 0;
         if(dp[ind][buy]!=-1)return dp[ind][buy];
         if(buy){
            return dp[ind][buy]=max(-prices[ind]+profit(ind+1,0,prices,dp,fee),
                       profit(ind+1,1,prices,dp,fee));
         }else{
            return dp[ind][buy] = max(-fee+prices[ind]+profit(ind+1,1,prices,dp,fee),
                       profit(ind+1,0,prices,dp,fee));
         }
    }   
public:
    int maxProfit(vector<int>& Arr, int fee) {
        int n=Arr.size();
        vector<long> ahead(2, 0);
        vector<long> cur(2, 0);
        ahead[0] = ahead[1] = 0;
        long profit;
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy == 0) profit = max(0 + ahead[0], -Arr[ind] + ahead[1]);
                if (buy == 1) profit = max(0 + ahead[1], Arr[ind] -fee +ahead[0]);
                cur[buy] = profit;
            }

            ahead = cur; 
        }
        return cur[0];
    }
};