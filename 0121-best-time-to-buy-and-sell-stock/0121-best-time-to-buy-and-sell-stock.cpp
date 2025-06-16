class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();

        int maxprofit=INT_MIN;
        int maxright=prices[n-1];

        for(int i=prices.size()-2  ; i>=0 ; i--){
            if(prices[i] > maxright){
                maxright = prices[i];

            }
            maxprofit=max(maxprofit , maxright-prices[i]);

            

        }
        if(maxprofit < 0) return 0;
        return maxprofit;

        
    }
};