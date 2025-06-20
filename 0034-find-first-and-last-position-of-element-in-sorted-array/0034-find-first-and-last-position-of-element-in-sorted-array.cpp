class Solution {
public:
    int findLeftMost(vector<int> &nums , int target , int start , int end){
        int ans=-1;
        while(start <= end){
            int mid = start +(end - start)/2;
            if(nums[mid] == target){
                ans=mid;
                end=mid-1;
            }
            else if(nums[mid] < target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }

    int findRightMost(vector<int> &nums , int target , int start , int end){
        int ans=-1;
        while(start <= end){
            int mid = start +(end - start)/2;
            if(nums[mid] == target){
                ans=mid;
                start=mid+1;
            }
            else if(nums[mid] < target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int leftmost=findLeftMost(nums,target,0,n-1);
        int rightmost=findRightMost(nums,target ,0,n-1);


        return{leftmost , rightmost};
        
    }
};