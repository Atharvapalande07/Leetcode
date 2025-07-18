class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;

        int n =s.length();

        for(int i=0 ; i<n ; i++){
            mp[s[i]]=i;
        }

        vector<int> result;
        int start =0, e=0;

        for(int i=0 ; i<n ; i++){
            e=max(e,mp[s[i]]);

            if(i==e){
                result.push_back(e-start+1);
                start=i+1;
            }
            
        }
        return result;

        


        
    }
};