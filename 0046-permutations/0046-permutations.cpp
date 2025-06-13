class Solution {
public:
    unordered_set<int> s;

    void helper(vector<int> &nums , vector<int>&temp , vector<vector<int>>&ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0 ; i<nums.size() ; i++){
            if(s.find(nums[i]) == s.end()){
                temp.push_back(nums[i]);
                s.insert(nums[i]);

                helper(nums , temp , ans);
                temp.pop_back();
                s.erase(nums[i]);
            }

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;

        vector<int> temp;

        helper(nums , temp ,ans);
        return ans;
        
    }
};