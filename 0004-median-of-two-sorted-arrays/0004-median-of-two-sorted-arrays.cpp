class Solution {
public:
vector<int>mergeSort(vector<int>&nums1,vector<int>&nums2){
    int i=0;
    int j=0;
    vector<int>ans;
    int a=nums1.size();
    int b=nums2.size();
    while(i<a&&j<b){
        if(nums1[i]>nums2[j]){
            ans.push_back(nums2[j]);
            j++;
        }
        else{
            ans.push_back(nums1[i]);
            i++;
        }

    }
    while(i<a){
          ans.push_back(nums1[i]);
            i++;
    }
     while(j<b){
          ans.push_back(nums2[j]);
            j++;
    }
    return ans;
}
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        ans=mergeSort(nums1,nums2);
        int n=ans.size();
        if(n%2!=0){
            return (ans[n/2]);
        }
        else{
            return (ans[n/2]+ans[(n/2)-1])/2.0;
        }
    }
};