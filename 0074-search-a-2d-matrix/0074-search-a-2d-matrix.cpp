class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // find column in binary search and find row in binary search
        
        // finding row in bs will be the first step
        int row_low = 0;
        int row_high = matrix.size() - 1;
        int ans_row = -1; //traverse row
        int j = matrix[0].size() - 1; //traverse column
        
        while (row_low <= row_high){
            int row_mid = row_low + (row_high - row_low)/2;
            if (matrix[row_mid][j] >= target && target >= matrix[row_mid][0]) {
                ans_row = row_mid;
                break;
            }
            else if (target > matrix[row_mid][j]) row_low = row_mid + 1;
            else row_high = row_mid - 1;
        }
        
        if (ans_row == -1) return false;
        
        // finding col in bs
        int col_low = 0;
        int col_high = matrix[0].size() - 1;
        int ans_col = -1;
        
        while (col_low <= col_high){
            int col_mid = col_low + (col_high - col_low)/2;
            if (matrix[ans_row][col_mid] == target) return true;
            else if (matrix[ans_row][col_mid] < target) col_low = col_mid + 1;
            else col_high = col_mid - 1;
        }
        
        return false;
    }
};