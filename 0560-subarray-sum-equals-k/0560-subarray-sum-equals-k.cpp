class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int count=0;
        int sum=0;
        freq[0]=1;

        for(int i=0 ; i<nums.size() ; i++){
            sum+=nums[i];
            int rem = sum-k;

            if(freq.find(rem) != freq.end()){
                count+=freq[rem];
                freq[sum]++;

            }
            else{
                freq[sum]++;
            }

        }
        return count;
        
    }
};