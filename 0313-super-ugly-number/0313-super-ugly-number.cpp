class Solution {
public:
    long long find_min(vector<int> &primes , vector<long long> & check , vector<long long> & dp){
        long long ans = INT_MAX;
        for(int i = 0 ;i < check.size() ; i ++){
            long long x = (long long)dp[check[i]] * primes[i];
            ans = min( ans , x );
        }
        return ans;
    }
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        sort(primes.begin() , primes.end());

        vector<long long> check(primes.size() , 0) , dp(n );
        dp[0] = 1;
        for(int i = 1 ; i < n ; i ++){
            dp[i] = find_min(primes , check , dp);

            for(int j = 0 ; j < primes.size(); j ++){
                if(dp[i] == dp[check[j]] * primes[j]) check[j] ++;
            }
        }
        return dp[n-1];
    }
};