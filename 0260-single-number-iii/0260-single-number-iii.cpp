class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long int check = 0;
        for(int i = 0; i<nums.size(); i++){
            check ^= nums[i];
        }
        long long int xorr = (check&(check-1))^check;
        int a = 0; int b = 0;
        for(int i =0; i<nums.size(); i++){
            if(xorr&nums[i]) a^=nums[i];
            else b ^= nums[i];
        }
        return {a,b};
    }
};