class Solution {
public:
    void helper(vector<int>& candidates, int target ,int index, vector<int> &curr , vector<vector<int>>&ans){
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        for(int i=index; i<candidates.size() ; i++ ){
            if( i > index && candidates[i] == candidates[i-1]) continue;

            if(candidates[i] > target) break;

            curr.push_back(candidates[i]);
            helper(candidates , target-candidates[i] , i+1 ,curr , ans);
            curr.pop_back();

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;

        helper( candidates , target , 0 , curr , ans);
        return ans;
        
    }
};