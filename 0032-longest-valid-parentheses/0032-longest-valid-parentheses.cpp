class Solution {
public:
    int longestValidParentheses(string s) {
        map<char,char>mp;
        mp[')'] = '(';
        stack<pair<char,int>>st;
        int ans = 0;
        for(int i =0;i<s.length();i++){
            if(st.empty()){
                st.push({s[i],i});
            } else {
                bool yes = false;
                if(!st.empty() && st.top().first == mp[s[i]] ){
                    st.pop();
                    yes = true;
                } else {
                    st.push({s[i],i});
                }
                if(yes){
                    if(!st.empty()){
                        int idx = st.top().second;
                        ans = max(ans, i - idx);
                    } else {
                        ans = max(ans, i + 1);
                    }
                }
                
            }
        }
        if(st.empty()) return s.length();
        return ans;
    }
};