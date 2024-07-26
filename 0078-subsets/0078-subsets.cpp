class Solution {
public:
    void generate(int i, vector<int> nums, vector<vector<int>>& subsets, vector<int>& subset){
        if (i >= nums.size()){
            subsets.push_back(subset);
            return;
        }
        
        // decision to include nums[i]
        subset.push_back(nums[i]);
        generate(i + 1, nums, subsets, subset);
        
        // decision to not include nums[i]
        subset.pop_back();
        generate(i + 1, nums, subsets, subset);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        generate(0, nums, ans, subset);
        return ans;
    }
};