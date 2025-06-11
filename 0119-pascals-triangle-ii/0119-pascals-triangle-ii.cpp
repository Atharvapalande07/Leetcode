class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<int> prev;
        for(int i=0;i<=numRows;i++){
            vector<int>current(i+1,1);
            for(int j=1;j<i;j++){
                current[j]=prev[j]+prev[j-1];
            }
            prev=current;
        }
        return prev;
    }
};