class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int distinct=0,n=nums.size();
        //separate the distinct number in the array at the start
        for(int i=1;i<n;i++)
        {
            if(nums[distinct]!=nums[i])
            {   
                distinct++;
                nums[distinct]=nums[i];
            }
        }
        //n is a count of distinct numbers
        n=distinct+1;
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
             if((nums[i]>nums[i-1] && nums[i]>nums[i+1]) || (nums[i]<nums[i-1] && nums[i]<nums[i+1]))
             {
                ans++;
             }
        }
        return ans;
    }
};