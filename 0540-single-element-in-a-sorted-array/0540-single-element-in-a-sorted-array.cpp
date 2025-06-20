class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;
        int ans=0;

        for(int i=0 ; i<nums.size() ; i++){
            int num = nums[i];
            if(freq.find(num) != freq.end()){
                freq[num]++;
            }
            else{
                freq[num]=1;

            }
            
        }
        for(auto it = freq.begin() ; it != freq.end() ; it++ ){
            if(it->second == 1){
                ans= it->first;
            }

        }
        return ans;
        
    }
};