class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n =nums.size();
        unordered_map<int,int>mp;
        vector<int>arr;
        for(int i=0 ; i<n ; i++){
            arr.push_back(nums[i]);
        }

        sort(arr.begin() , arr.end());

        for(int i=n-1 ; i>=n-k ; i--){
            mp[arr[i]]++;

        }

        vector<int>ans;

        for(int i=0 ; i<n ; i++){
            if((mp.find(nums[i])) != mp.end()){
                ans.push_back(nums[i]);
                mp[nums[i]]--;
            }
            if(mp[nums[i]] == 0){
                mp.erase(nums[i]);
            }
        }
        return ans;
        
    }
};