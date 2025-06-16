class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int count=0;
        int sum=0;
        freq[0]=1;

        for(int i=0 ; i<nums.size() ; i++){
            sum+=nums[i];

            if(freq.find(sum-k) != freq.end()){
                count+=freq[sum-k];
                freq[sum]++;

            }
            else{
                freq[sum]++;
            }

        }
        return count;
        
    }
};