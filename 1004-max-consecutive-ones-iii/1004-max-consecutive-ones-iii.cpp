class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0 , right=0;
        int zerocount=0;
        int maxlen=0;

        while(right < nums.size()){
            if(nums[right] ==0) zerocount++;

            while(zerocount > k){
                if(nums[left] ==0){
                    zerocount--;
                }
                left++;
            }
            maxlen=max(maxlen , right-left+1);
            right++;
        }
        return maxlen;
        
    }
};