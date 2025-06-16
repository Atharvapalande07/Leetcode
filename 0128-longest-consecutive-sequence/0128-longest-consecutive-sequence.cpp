class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count =1;
        int maxlen=INT_MIN;
        sort(nums.begin() , nums.end());
        if(nums.size() ==0) return 0;

        for(int i=1 ; i<nums.size() ; i++){
            if(nums[i] == nums[i-1]) continue;
            if(nums[i]-nums[i-1] == 1 ){
    
                count++;
            }
            else{
                maxlen=max(maxlen,count);
                count=1;
            }
        }
        maxlen=max(maxlen,count); 
        return maxlen;
        
    }
};