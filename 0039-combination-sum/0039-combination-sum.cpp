class Solution {
public:
    void generate(vector<int>& arr, int target, int i, int sum, vector<vector<int>>& ans, vector<int>& subseq){
        if (i >= arr.size()){
            if (sum == target) ans.push_back(subseq);
            return; // return to avoid further processing
        }

        // Pick the element
        if (sum <= target){
            sum += arr[i];
            subseq.push_back(arr[i]);
            generate(arr, target, i, sum, ans, subseq);
            sum -= arr[i];
            subseq.pop_back();
        }

        // Backtrack and try the next element
        generate(arr, target, i + 1, sum, ans, subseq);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subseq;
        generate(candidates, target, 0, 0, ans, subseq);
        return ans;
    }
};
