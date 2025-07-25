class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int>unique_nums;
        int maxi = INT_MIN;
        for(int num : nums){
            if(num >= 0)
              unique_nums.insert(num);
            if(num > maxi) maxi = num;
        }
        if(maxi < 0) return maxi;
        return accumulate(unique_nums.begin(), unique_nums.end(), 0);
    }
};