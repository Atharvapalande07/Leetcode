class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;
        for(int i=0 ; i<nums.size() ; i++){
            int el=nums[i];
            int rem=target-el;
            
            if(mpp.find(rem) != mpp.end()){
                return{mpp[rem],i};
            }
            mpp[el]=i;
        }
        return{-1 ,-1};
        
    }
};