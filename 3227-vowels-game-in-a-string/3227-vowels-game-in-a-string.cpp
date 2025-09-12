class Solution {
public:
    bool doesAliceWin(string s) {
        int len=0;
        for(char ch:s){
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
               len++;
            }
        }
        return len>0;
    }
};