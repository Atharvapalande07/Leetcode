#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==1) return s;

        string rese="";// stores the max even length palindrome
        int left=0,right=n/2;

        while(left<=right){
            int mid=(left+right)/2;
            int len=2*mid;
            bool found=0;
            for(int i=0;i+len<=n;i++){
                int f=1;
                for(int j=0;j<len/2;j++){
                    if(s[i+j]!=s[i+len-1-j]) {f=0;break;}
                }
                if(f){
                    found=1;
                    rese=s.substr(i,len);
                    break;
                }
            }
            if(found) left=mid+1;
            else right=mid-1;
        }

        string reso=""; // stores the max odd length palindrome
        left=0,right=n/2;

        while(left<=right){
            int mid=(left+right)/2;
            int len=2*mid+1;
            bool found=0;
            for(int i=0;i+len<=n;i++){
                int f=1;
                for(int j=0;j<len/2;j++){
                    if(s[i+j]!=s[i+len-1-j]) {f=0;break;}
                }
                if(f){
                    found=1;
                    reso=s.substr(i,len);
                    break;
                }
            }
            if(found) left=mid+1;
            else right=mid-1;
        }

        return rese.size()>reso.size() ? rese : reso;
    }
};