class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        sort(nums.begin() , nums.end());

        if(nums.empty()) return 0;

        int currstrk=1;
        int longest=1;

        for(int i=1 ; i<nums.size() ; i++){
            if(nums[i] == nums[i-1]){
                continue;
            }

            if(nums[i]==nums[i-1]+1){
                currstrk++;
            }
            else{
                longest=max(longest , currstrk);
                currstrk=1;
            }
        }
        return max(longest , currstrk);

        
    }
};