class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n =nums.size();
        set<int> seen;
        int i=0;
        int j=0;
        int sum=0;
        int maxsum=0;

        while(j<n){
            if(seen.find(nums[j]) == seen.end()){
                seen.insert(nums[j]);
                sum+=nums[j];
                maxsum=max(maxsum , sum);
                j++;
            }
            else{
                seen.erase(nums[i]);
                sum-=nums[i];
                i++;
            }
        }
        return maxsum;
        
    }
};