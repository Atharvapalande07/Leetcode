class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n =arr.size();
        unordered_map<int,int> freq;
        vector<int>ans;

        for(int i=0 ; i<n ; i++){
            int val=arr[i];
            freq[val]++;
        }

        for(auto it=freq.begin() ; it != freq.end() ; it++ ){
            if(it->second == it->first){
                ans.push_back(it->first);
            }
        }
        if (ans.size() == 0) {
            return -1;
        }

        return *max_element(ans.begin(), ans.end());


        
    }
};