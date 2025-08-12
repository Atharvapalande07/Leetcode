class Solution {
public:
    int dp[301][301];
    int mod = 1e9 + 7 ;
    int fun(int n , int x , int num){
        if(n == 0){
            return 1;
        }
        if(n < 0 || num > 300 || num > n){
            return 0 ;
        }

        if(dp[n][num] != -1){
            return dp[n][num];
        }
        long long newN = 1 ;
        int i = 0 ;
        while(i<x && newN <= n){
            newN *= num ;
            i++;
        }
        if(newN > n){
            return dp[n][num] = 0 ;
        }
        return dp[n][num] = (fun(n - newN , x , num+1)%mod + fun(n , x , num + 1)%mod)%mod;
    }
    int numberOfWays(int n, int x) {
        memset(dp , -1 , sizeof(dp));
        return fun(n , x , 1);
    }
};