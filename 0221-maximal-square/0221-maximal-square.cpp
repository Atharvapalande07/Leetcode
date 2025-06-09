class Solution {
public:
    // function to handle each query in O(1) TC.
    int f(int row1, int col1, int row2, int col2, vector<vector<int>>& mat){
        int ans = mat[row2][col2];
        if(row1 > 0){ans -= mat[row1-1][col2];}
        if(col1 > 0){ans -= mat[row2][col1-1];}
        if(row1 > 0 && col1 > 0){ans += mat[row1-1][col1-1];}

        return ans;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        // find 2-D prefix sum matrix in 'int'
        vector<vector<int>> mat(n, vector<int> (m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i][j] = matrix[i][j] - '0';
            }
        }
        // find row-wise then col-wise prefix sum
        for(int i=0; i<n; i++){
            for(int j=1; j<m; j++){
                mat[i][j] = mat[i][j-1] + mat[i][j];
            }
        }
        for(int j=0; j<m; j++){
            for(int i=1; i<n; i++){
                mat[i][j] = mat[i-1][j] + mat[i][j];
            }
        }
        
        // largest square area with 1s only
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int k=0; k<=min(i,j); k++){
                    int row2 = i, col2 = j;
                    int row1 = i - k, col1 = j - k;
                    if(row1<0 || col1<0) break;

                    int sum = f(row1, col1, row2, col2, mat);
                    if(sum == (k+1)*(k+1)){
                        ans = max(ans, sum);
                    }
                }
            }
        }
        
        return ans;
    }
};