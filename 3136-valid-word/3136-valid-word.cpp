class Solution {
public:
    bool isValid(string word) {
        if(word.length() < 3) return false;

        bool isvowel=false;
        bool isconsonent=false;

        for(auto ch : word ){
            if(!isalnum(ch)) return false;

            if(isalpha(ch)){
                int lower=tolower(ch);

                if(lower == 'a' ||lower == 'e' || lower == 'i' ||lower == 'o' ||lower == 'u'){
                    isvowel=true;
                }
                else{
                    isconsonent=true;
                }
            }
        }
        return isvowel && isconsonent;
        
    }
};