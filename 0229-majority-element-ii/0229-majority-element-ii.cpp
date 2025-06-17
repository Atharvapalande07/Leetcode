class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int , int> freq;
        int n = nums.size();
        vector<int> result;

        for(int i=0 ; i<n ; i++){
            int num=nums[i];

            if(freq.find(num) != freq.end()){
                freq[num]=freq[num]+1;
            }
            else{
                freq[num]=1;
            }   

        }

        for(auto it=freq.begin() ; it != freq.end() ; it++){
            if(it->second > n/3){
                result.push_back(it-> first);
            }

        }
        return result;
        
    }
};