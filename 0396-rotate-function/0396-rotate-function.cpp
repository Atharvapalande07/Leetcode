class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0,temp=0,n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            temp+=i*nums[i];
        }
        int ans=temp;
        for(int i=0;i<n;i++){
            temp=temp+sum-nums[n-1-i]*n;
            ans=max(ans,temp);
        }
        return ans;

    }
};