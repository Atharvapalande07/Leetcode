class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // brute force try to make every single index as a starting point
        int n = fruits.size();
        if(n==1 || n==2)
        return n;
        // int ans = INT_MIN;
        // for (int i = 0; i < n-1; i++) {
        //     unordered_set<int> st;
        //     st.insert(fruits[i]);
        //     st.insert(fruits[i + 1]);
        //     int count = 2;
        //     for (int j = i + 2; j < n; j++) {
        //         int ele = fruits[j];
        //         if (st.size() == 1 || st.find(ele) != st.end()) {
        //             st.insert(ele);
        //             count++;
        //         } else
        //             break;
        //     }
        //     ans = max(ans, count);
        // }
        // return ans;

        // now using optimised O(N) sliding window two pointer approach

        int i = 0;
        int j = 0;
        int ans = INT_MIN;
        int count = 0;
        unordered_map<int,int> mp;
        while(i<n && j<n){
            mp[fruits[j]]++;
            while(mp.size() > 2){
                // shrink the window
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0)
                mp.erase(fruits[i]);
                i++;
                count--;
            }
            count++;
            // update the answer also
            ans = max(ans,count);
            j++;
        }
        return ans;
    }
};