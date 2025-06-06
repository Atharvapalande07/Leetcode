class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1)    return "";
        int a=gcd(str1.size(),str2.size());
        // string ans="";
        // for(int i=0;i<a;i++){
        //     ans+=str1[i];
        // }
        // return ans;
        
        return str1.substr(0,a);
    }
};