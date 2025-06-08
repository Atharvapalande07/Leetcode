class Solution {
public: 
    void helper(int index , vector<int>& nums , vector<int> current , vector<vector<int>> &ans){
        if(index >= nums.size()){
            ans.push_back(current);
            return;
        }

        current.push_back(nums[index]);

        helper(index+1 , nums , current , ans);

        current.pop_back();
        helper(index+1 , nums ,current , ans);
    }


    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>>ans;
        vector<int>current;

        helper(0,nums,current,ans);
        return ans;
        
    }
};