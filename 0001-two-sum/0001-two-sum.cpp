class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int , int> mp;

        for(int i=0 ;i<nums.size() ; i++){
            int moreneeded=target - nums[i];

            if(mp.find(moreneeded)  != mp.end()){
                return {mp[moreneeded] , i};
            }
            mp[nums[i]]=i;

        }
        return{-1,-1};
        
    }
};