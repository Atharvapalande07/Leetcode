class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0) return false;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            
            if(mp.find(nums[i])!=mp.end() && i-mp[nums[i]]<=k){
                return true;
            }
            mp[nums[i]]=i;
        }
        return false;
    }
};