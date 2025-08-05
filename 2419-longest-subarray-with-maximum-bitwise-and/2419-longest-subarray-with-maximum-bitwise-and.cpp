class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxval=*max_element(nums.begin() , nums.end());
         int count=0;
         int maxcount=1;
       

        for(int i=0 ; i<n ; i++){
            
            if(nums[i] == maxval){
                count++;
                maxcount=max(maxcount , count);

            }
            else{
                count=0;
            }


        }
        return maxcount;

        
    }
};