class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<int> st;
        int n=nums.size();
        int left=0;
        unordered_map<int,int> mpp;
        for(int i=0;i<indexDiff;i++){
            st.insert(nums[i]);
            mpp[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            if(i>indexDiff){
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0) 
                {
                    mpp.erase(nums[left]);
                    st.erase(nums[left]);
                }
                left++;
            }
            if(i+indexDiff<n){
                st.insert(nums[i+indexDiff]);
                mpp[nums[i+indexDiff]]++;
            }
            mpp[nums[i]]--;
            if(mpp[nums[i]]==0)
            st.erase(nums[i]);
            auto it=st.lower_bound(nums[i]);
            if(it!=st.end() && abs(nums[i]-*it)<=valueDiff) return true;
            st.insert(nums[i]);
            mpp[nums[i]]++;
        }
        return false;
    }
};