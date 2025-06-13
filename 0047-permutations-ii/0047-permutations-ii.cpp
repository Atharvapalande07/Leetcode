class Solution {
public:
    void helper(vector<int>&nums , vector<int>&temp , vector<vector<int>> &ans , unordered_map<int,int>&mp){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for( auto & [num , count] : mp){
            if(count ==0){
                continue;
            }
            temp.push_back(num);
            mp[num]--;
            helper(nums , temp , ans ,mp);
            temp.pop_back();
            mp[num]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0 ; i<nums.size() ; i++){
            int num=nums[i];

            if(mp.find(num)!= mp.end()){
                mp[num]++;
            }
            else{
                mp[num]=1;
            }

        }

        vector<int> temp;
        vector<vector<int>> ans;

        helper(nums , temp ,ans , mp );
        return ans;
        
    }
};