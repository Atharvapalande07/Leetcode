class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size(),res=0;
   vector<int>vec(n,0);
   int r=n-1;
   int m=INT_MIN;
   while(r>=0){
    m=max(m,nums[r]);
    vec[r]=m;
    r--;
   }
  r=0;
  int l=0;
  while(l<n && r<n){
    while(l<r &&vec[r]<nums[l]) l++;
    res=max(res,r-l);
    r++;
  }
        return res;
    }
};