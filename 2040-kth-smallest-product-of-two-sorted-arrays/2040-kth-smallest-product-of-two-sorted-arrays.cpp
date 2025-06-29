class Solution {
public:
    long long findCountSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long midProduct){
    long long productCount = 0;
    int n = nums2.size();

    for(int i=0; i<nums1.size(); i++){

        if(nums1[i] >= 0){
            int low = 0;
            int high = n - 1;
            int m = -1; // Initialize to -1, meaning no valid products found on the right side

            while(low <= high){
                int mid = low + (high - low) / 2;
                long long product = 1LL * nums1[i] * nums2[mid];

                if(product <= midProduct){
                    m = mid; // This is the largest index where product is less than or equal to midProduct
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            if(m != -1){
                productCount += (m + 1); // All products with nums2[0] to nums2[m] are valid
            }
        }
        else{
            // Product will be negative and right hand side will containt smaller products and left hands side larger products
            int low = 0;
            int high = n - 1;
            int m = n; // Initialize to n, meaning no valid products found on the right side

            while(low <= high){
                int mid = low + (high - low) / 2;
                long long product = 1LL * nums1[i] * nums2[mid];

                if(product <= midProduct){
                    m = mid; // This is the largest index where product is less than or equal to midProduct
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            if(m != n){
                productCount += (n - m); // All products with nums2[m] to nums2[n-1] are valid
            }
        }
    }
    return productCount;
}

long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
    long long result = 0;
    long long low = -1e10; // Minimum possible product
    long long high = 1e10; // Maximum possible product

    while(low <= high){
        long long midProduct = low + (high - low) / 2;

        // Check if this is kth smallest product or not
        long long countSmallest = findCountSmallestProduct(nums1, nums2, midProduct);

        if(countSmallest >= k){
            result = midProduct;
            high = midProduct - 1;
        }
        else{
            low = midProduct + 1;
        }
    }
    return result;
}
};