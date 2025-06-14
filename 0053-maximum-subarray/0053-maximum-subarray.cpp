class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i=0 , j=0;
        int currsum=0;
        int MaxSum=INT_MIN;

        while(j<nums.size()){
            currsum+=nums[j];
            MaxSum=max(MaxSum,currsum);

            while(currsum <0 && i<=j){
                currsum-=nums[i];
                i++;
            }
            j++;
        }
        return MaxSum;
        
    }
};