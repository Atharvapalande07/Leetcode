class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // we can do for all 4 as max length is 4 
        int n =digits.size();
        vector<vector<char>> keys={{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};

            vector<string> ans;
        if(n==1){
            // get the digit 
            int d =(digits[0]-'0')-2;
            // thats the idex of that om keys vector
            for(int i=0;i<keys[d].size();i++){
                string s="";
                s+=keys[d][i];
                ans.push_back(s);
            }
        }
        if(n==2){
            // we have to run 2 nested loops 
            int f=(digits[0]-'0')-2;
            int se=(digits[1]-'0')-2;
            for(int i=0;i<keys[f].size();i++){
                 
                for(int j=0;j<keys[se].size();j++){
                    string s="";
                    s+=keys[f][i];
                    s+=keys[se][j];
                    ans.push_back(s);
                }
            }
        }
        if(n==3){
        // we have to run 3 loops 
        int f=(digits[0]-'0')-2;
        int se =(digits[1]-'0')-2;
        int t=(digits[2]-'0')-2;

        for(int i=0;i<keys[f].size();i++){
                 
                for(int j=0;j<keys[se].size();j++){
                    
                    for(int k=0;k<keys[t].size();k++){
                         string s="";
                        s+=keys[f][i];
                        s+=keys[se][j];
                        s+=keys[t][k];
                        
                        ans.push_back(s);
                    }
                }
            }
        
        }
        if(n==4){
        int f=(digits[0]-'0')-2;
        int se=(digits[1]-'0')-2;
        int t=(digits[2]-'0')-2;
        int d=(digits[3]-'0')-2; // 4th ka index acc to number 

        for(int i=0;i<keys[f].size();i++){
                 
                for(int j=0;j<keys[se].size();j++){
                    
                    for(int k=0;k<keys[t].size();k++){
                        
                        for(int l=0;l<keys[d].size();l++){
                            string s="";
                            s+=keys[f][i];
                            s+=keys[se][j];
                            s+=keys[t][k];
                            s+=keys[d][l];
                            ans.push_back(s);
                        }
                    }
                }
            }
        
        
        }
        return ans;
    }
};