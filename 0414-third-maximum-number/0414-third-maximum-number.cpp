class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long int three=LONG_MIN,sec=LONG_MIN,first=LONG_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==three || nums[i]==sec || nums[i]==first)
            continue;
            if(nums[i]>three){
                three = nums[i];
                if(three>sec) swap(three,sec);
                if(sec>first) swap(sec,first);
            }
        }
        return three==LONG_MIN? first: three;
        
    }
};