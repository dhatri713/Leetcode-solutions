class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // better soln
        int n = matrix.size();
        int m = matrix[0].size();
        // vector<int> track_cols(m, 0);
        // vector<int> track_rows(n, 0);

        // for (int i = 0; i < n; i++){
        //     for (int j = 0; j < m; j++){
        //         if (matrix[i][j] == 0){
        //             track_cols[j] = -1;
        //             track_rows[i] = -1;
        //             continue;
        //         }
        //     }
        // }

        // for (int i = 0; i < n; i++){
        //     for (int j = 0; j < m; j++){
        //         if (track_cols[j] == -1 || track_rows[i] == -1){
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }

        // optimal soln
        int col0 = matrix[0][0];
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (matrix[i][j] == 0){
                    if (j == 0) col0 = 0;
                    else matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                if (matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if (matrix[0][0] == 0){
            for (int i = 0; i < m; i++){
                matrix[0][i] = 0;
            }
        }

        if (col0 == 0){
            for (int i = 0; i < n; i++){
                matrix[i][0] = 0;
            }
        }
    }
};