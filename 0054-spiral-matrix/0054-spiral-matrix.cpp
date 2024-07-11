class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> result;
        
        int left = 0;
        int right = m - 1;
        int top = 0;
        int bottom = n - 1;
        
        while(left<= right &&top<= bottom) {
            for (int i = left; i <= right; i++){
            result.push_back(matrix[top][i]);
            }
            top++;

            for (int i = top; i <= bottom; i++){
                result.push_back(matrix[i][right]);
            }
            right--;

            for (int i = right; i >= left; i--){
                if (top > bottom) break;
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
            for (int i = bottom; i >= top; i--){
                if (left > right) break;
                result.push_back(matrix[i][left]);
            }
            left++;
        }
        
        return result;
    }
    
};                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  