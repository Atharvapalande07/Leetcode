class Solution {
public:
    long long f(vector<vector<int>> &fruits, long long i, long long j , vector<vector<long long>> &dp, long long moves,vector<vector<long long>> &dir) {
        //Considerable base case
        if(i==j and i==fruits.size()-1) return (moves==0) ? 0 : LLONG_MAX;
        //Not considerable
        if(i==j || moves==0) return LLONG_MAX; 
        if(dp[i][j]!=-1) return dp[i][j];
        long long ans = -1;

        //Running across all the directions
        for(int direc = 0 ; direc < dir.size() ; ++direc) {
            long long ni = i+dir[direc][0];  // new row
            long long nj = j+dir[direc][1];  // new col
            if(ni>=0 and ni<fruits.size() and nj>=0 and nj<fruits.size()) {
                long long val = f(fruits,ni,nj,dp,moves-1,dir);
                if(val!=LLONG_MAX){  // check if val==LLONG_MAX toh case was invalid
                    ans = max(ans,val);   // update the final answer
                }
            }
        }
        return dp[i][j] = (ans<0) ? LLONG_MAX : ans+fruits[i][j];
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        long long ans = 0;
        long long n = fruits.size();

        //STEP1 : Child1 moving diagonally
        for(int i = 0 ; i < n ; ++i) {
            ans+=fruits[i][i];
        }

        vector<vector<long long>> dp(n,vector<long long> (n,-1));
        vector<vector<long long>> dir = {{1,-1},{1,0},{1,1}};

        //STEP2 : checking for child2 at (0,n-1)
        long long a2 = f(fruits,0,n-1,dp,n-1,dir);

        dir = {{-1,1} , {0,1} , {1,1}};
        vector<vector<long long>> dp2(n,vector<long long> (n,-1));
        //STEP3 : checking for child3 at (n-1,0)
        long long a3 = f(fruits,n-1,0,dp2,n-1,dir);
        return ans+a2+a3;
    }
};