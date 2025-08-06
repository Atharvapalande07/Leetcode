class Solution {
public:

    void helper(vector<int>&nums , int i , vector<int>&curr ,vector<vector<int>>&result){

        if( i >= nums.size()){
            result.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        helper(nums , i+1 , curr , result);
        curr.pop_back();

        int indx=i+1;
        while(indx < nums.size() && nums[indx] == nums[indx-1]) indx++;
        helper(nums , indx , curr , result);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> result;
        vector<int>curr;
        helper(nums,0,curr,result);
        return result;
        
    }
};