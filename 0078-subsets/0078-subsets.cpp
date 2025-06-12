class Solution {
public:
    void solve(int i,int n,vector<vector<int>>&ans,vector<int>&temp,vector<int>& nums){
        // base cond
        if(i==n){
            ans.push_back(temp);
            return;
        }
        // if we take 
        temp.push_back(nums[i]);
        solve(i+1,n,ans,temp,nums);
        temp.pop_back();

        // if we dont take
         solve(i+1,n,ans,temp,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int i=0;
        int n=nums.size();

        solve(i,n,ans,temp,nums);

        return ans;
    }
};