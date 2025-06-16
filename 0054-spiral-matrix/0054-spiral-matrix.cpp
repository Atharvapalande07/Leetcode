class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        int row = matrix.size();
        int col = matrix[0].size();

        int top= 0;
        int bottom=row-1;
        int left=0; 
        int right=col-1; 

        /*
        dir 0 = left To right
        dir 1 = top To bottom
        dir 2 = right To left
        dir 3 = bottom To top
        */

        int dir=0;
        
        
        while(top <= bottom && left<= right){
            if(dir == 0){
                for(int i=left ; i<= right ; i++){
                    result.push_back(matrix[top][i]);
                
                }
                top++;
            }
            if(dir==1){
                for(int i= top ; i<=bottom ; i++){
                    result.push_back(matrix[i][right]);
                }
                right--;
            }

            if(dir==2){
                for(int i= right ; i>=left ; i--){
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(dir==3){
                for(int i= bottom ; i>=top; i--){
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
            dir++;
            if(dir == 4){
                dir =0;
            }
        }
        return result;
        
    }
};