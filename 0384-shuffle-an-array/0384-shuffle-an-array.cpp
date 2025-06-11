class Solution {
public:
    vector<int>v1,v2,v3;
    Solution(vector<int>& nums) {
        v1=nums;
        v3=v1;
    }
    
    vector<int> reset() {
        return v1;
    }
    
    vector<int> shuffle() {
        v2=v1;
        int j=0;
       for(int i=0;i<v2.size();i++){
          swap(v2[i],v2[rand()%v2.size()]);
       }
        return v2;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */