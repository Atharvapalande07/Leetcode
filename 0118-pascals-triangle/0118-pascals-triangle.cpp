class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        vector<vector<int>> result;
        

        for(int i=0 ; i<n ; i++){
            vector<int>temp(i+1,1);
            

            for(int j=1 ; j<i ; j++){
               temp[j]=result[i-1][j]+result[i-1][j-1];
            }
            result.push_back(temp);
        }
        return result;
       
        
    }
};