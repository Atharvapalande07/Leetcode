class Solution {
public:
    string minWindow(string s, string t) {
        int l=0;
        int r=0;
        int mini=1e9;
        int count=0;
        int idx=-1;
        map<char,int>hash;
        for(int i=0;i<t.length();i++)
            {
                hash[t[i]]++;
            }
        while(r<s.length())
        {
            if(hash[s[r]]>0)
            {
                count++;
            }
            hash[s[r]]--;
            
            while(count==t.length())
            {
                if(r-l+1<mini)
                {
                    mini=r-l+1;
                    idx=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0)
                {
                    count--;
                }
                l++;
            }
            r=r+1;
        }
        if(mini==1e9)
        {
            return "";
        }
        string ans;
        for(int i=idx;i<mini+idx;i++)
        {
            ans+=s[i];
        }
        return ans;
    }
};