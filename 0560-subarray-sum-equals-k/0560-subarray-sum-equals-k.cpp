class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n =nums.size();
        int prefixsum=0;

        unordered_map<int,int> mp;
        mp[0]=1;
        int count=0;

        for(int i=0 ; i<n ; i++){
            prefixsum+=nums[i];
            int rem = prefixsum-k;

            if(mp.find(rem) != mp.end()){
                count+=mp[rem];
                mp[prefixsum]++;
            }
            else{
                mp[prefixsum]++;
                
            }
        }
        return count;



        
    }
};