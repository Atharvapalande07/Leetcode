class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> sub;
        int ind = 1;
        sf(ans,sub,k , n, ind);
        return ans;
    }
    void sf(vector<vector<int>> &ans, vector<int> &sub, int k , int n , int ind){
        if(n == 0 && sub.size() == k){
            ans.push_back(sub);
            return;
        }

        for(int i = ind ;i<10;i++){
            if(sub.size() <= k-1 && n >= i ){
                sub.push_back(i);
                n -= i;
                sf(ans,sub, k  , n  , i+1);
                sub.pop_back();
                n+=i;
            }
            else if(n <i || sub.size() >= k){
                return;
            }
        }

    }
};