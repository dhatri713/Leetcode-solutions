class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0;
        int high = mat[0].size() - 1;
        vector<int> ans;
        
        while (low <= high){
            int mid = low + (high - low)/2;
            int prob_peak = INT_MIN;
            int row = -1;
            for(int i = 0; i < mat.size(); i++){
                if (mat[i][mid] >= prob_peak) {
                    prob_peak = mat[i][mid];
                    row = i;
                }
            }
            int left = ((mid - 1) >= 0) ? mat[row][mid - 1] : -1;
            int right = ((mid + 1) < mat[0].size()) ? mat[row][mid + 1] : -1;
            
            if (mat[row][mid] > left && mat[row][mid] > right){
                ans.push_back(row);
                ans.push_back(mid);
                return ans;
            }
            
            else if (mat[row][mid] < left) high = mid - 1;
            else low = mid + 1;
            
        }
        
        return ans;
    }
};