class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int count=0;

        for(int i=0 ; i<nums.size() ; i++){
            int target= k - nums[i];

            if(freq[target]>0){
                freq[target]--;
                count++;

            }
            else{
                freq[nums[i]]++;
            }
        }
        return count;
        
    }
};