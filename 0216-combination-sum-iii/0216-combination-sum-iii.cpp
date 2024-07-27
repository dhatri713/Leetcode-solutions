class Solution {
public:
    
    void generate(int i, int sum, int target, vector<vector<int>>& ans, vector<int>& subset, vector<int> nums, int k){
        if (subset.size() > k || sum > target) return; // prune invalid paths

        if (subset.size() == k) {
            if (sum == target) ans.push_back(subset);
            return;
        }

        if (i >= nums.size()) return; // ensure i is within the bounds

        
        subset.push_back(nums[i]);
        sum += nums[i];
        generate(i + 1, sum, target, ans, subset, nums, k);
        sum -= nums[i];
        subset.pop_back();
        generate(i + 1, sum, target, ans, subset, nums, k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> subset;
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        generate(0, 0, n, ans, subset, nums, k);
        return ans;
    }
};