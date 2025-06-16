class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(int i=0 ; i< nums.size() ; i++){

            if(freq.find(nums[i]) != freq.end()){
                freq[nums[i]]++;
            }
            else{
                freq[nums[i]]=1;
            }
        }

        for(auto it = freq.begin() ; it!= freq.end() ; it++){
            if(it->second > nums.size()/2){
                return it->first;
            }
        }
        return -1;
        
        
        
    }
};