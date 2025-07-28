class Solution {
public:
   int maxi(vector<int> &nums, int i , vector<int> &dp){
    if(i==nums.size()){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }

    int take = nums[i]|maxi(nums,i+1,dp);
    int not_take =maxi(nums,i+1,dp);


    return dp[i]= max(take, not_take);
   }

int count(vector<int>& nums, int i, int curr_or, int target_or, vector<vector<int>> &dp2){
    if(i == nums.size()){
        return curr_or == target_or ? 1 : 0;
    }
    if(dp2[i][curr_or]!=-1){
        return dp2[i][curr_or];
    }
    

    // Include nums[i]
    int take = count(nums, i + 1, curr_or | nums[i], target_or,dp2);

    // Exclude nums[i]
    int not_take = count(nums, i + 1, curr_or, target_or,dp2);

    return dp2[i][curr_or]=take + not_take;
}



    int countMaxOrSubsets(vector<int>& nums) {
        // first we may go ahead and find the maximum possible xor 
        // then we go ahead and compute the possible subsets with the or
     // i think we can also dp it 
     vector<int> dp(nums.size()+1,-1);
     int maximum = maxi(nums,0,dp);

     vector<vector<int>> dp2(nums.size()+1,vector<int>(maximum+1,-1));
     return count(nums,0,0,maximum,dp2);

        
    }
};