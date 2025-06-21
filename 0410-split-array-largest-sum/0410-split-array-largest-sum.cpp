class Solution {
public:
// Brute Force

    int countSubArray(int maxSum,vector<int>& nums,int k)
    {
        int subArrays=1,crSum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(crSum+nums[i]<=maxSum)
            {
                crSum+=nums[i];
            }else
            {
                crSum=nums[i];
                subArrays++;
            }
        }
        return subArrays;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size() , start=INT_MIN , end=0 , ans=-1;

        for(auto i:nums)
        {
            start=max(start,i);
            end+=i;
        }

      
        while(start<=end)
        {
            int mid=start+(end-start)/2;

            if(countSubArray(mid,nums,k)<=k)
            {
                ans=mid;
                end=mid-1;
            }else start=mid+1;
        }
        return ans;
    }
};