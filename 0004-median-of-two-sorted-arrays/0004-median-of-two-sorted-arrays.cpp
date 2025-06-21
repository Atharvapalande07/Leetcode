class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int total = n + m;

        int i=0;
        int j=0;
        int cnt=0;
        int curr =0;
        int prev = 0;

        while( cnt <= total/2){
            prev = curr;

            if(i<n && (j>= m || nums1[i] < nums2[j] )){
                curr =  nums1[i];
                i++;
            }else{
                curr = nums2[j];
                j++;
            }

            cnt ++;



        }
        if(total % 2 == 0){
            return (prev + curr) / 2.0;
        }else{
            return curr;
        }


        
    }
};