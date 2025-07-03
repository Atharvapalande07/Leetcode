class Solution {
public:
    char kthCharacter(int k) {
       string word="a";
       while (word.size()<k){
        string s;
        for(int i=0; i<word.size(); i++){
            s+=(word[i]+1);
        }
        word+=s;
       }
       return word[k-1];
    }
};