class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.size();
        int g=(n+k-1)/k;
        vector<string>str(g);
        for(int i=0;i<g;i++){
            string grp;;
            for(int j=0;j<k;j++){
                int index=i*k+j;
                if(index<n){
                    grp+=s[index];
                }else{
                    grp+=fill;
                }
            }
            str[i]=grp;
        }
        return str;
    }
};