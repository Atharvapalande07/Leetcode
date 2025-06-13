class Solution {
public:

    void helper(vector<int>& nums , int i , vector<int>&curr , vector<vector<int>>&ans){

        if(i == nums.size()){
            ans.push_back(curr);
            return;

        }


        curr.push_back(nums[i]);
        helper(nums,i+1 , curr , ans);

        curr.pop_back();

        int index =i+1;
        while(index < nums.size() && nums[index]==nums[index-1] ){
            index++;
        }


        helper(nums , index , curr ,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>>ans;

        sort(nums.begin() , nums.end());
        

        helper(nums ,0 , curr , ans);
        return ans;
        
    }
};