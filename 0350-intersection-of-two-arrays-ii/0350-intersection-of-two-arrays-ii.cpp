class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> freq;
        for(int ele:nums1){
            freq[ele]++;
        }
        for(int ele:nums2){
            if(freq[ele]>0){
                res.push_back(ele);
                freq[ele]--;
            }
        }
        return res;
    }
};