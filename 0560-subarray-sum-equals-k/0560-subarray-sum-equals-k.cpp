class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixsum;
        int n = nums.size();
        int currsum=0;
        int count=0;

        prefixsum[0]=1;
        for(int i=0 ; i<n ; i++){
            currsum+=nums[i];
            int rem = currsum - k;


            if(prefixsum.find(rem) !=prefixsum.end()){
                count+=prefixsum[rem];


            }
            prefixsum[currsum]++;
        }
        return count;


        
    }
};