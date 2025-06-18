class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n =grid.size();
        vector<int> ans(n*n+1,0);
        int repeating;
        int missing;

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                ans[grid[i][j]]++;

            }
        }
        for(int i=1 ; i<n*n+1 ; i++){
            if(ans[i] == 2){
                repeating=i;
        
            }
            else if(ans[i] ==0){
                missing=i;            }
        }
        return {repeating , missing};
        
    }
};