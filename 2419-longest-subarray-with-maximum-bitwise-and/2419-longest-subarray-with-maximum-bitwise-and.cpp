class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxval = *max_element(nums.begin() , nums.end());

        int count=0;
        int maxlen=1;

        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] == maxval){
                count++;
                maxlen=max(maxlen ,count);
            }
            else count=0;
        }
        return maxlen;
        
    }
};