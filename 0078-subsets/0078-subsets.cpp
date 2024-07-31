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
        // vector<vector<int>> ans;
        // vector<int> subset;
        // generate(0, nums, ans, subset);
        // return ans;
        
        int num_subsets = 1 << nums.size();
        vector<vector<int>> ans;
        
        for (int i = 0; i < num_subsets; i++){
            vector<int> subset;
            for (int j = 0; j < nums.size(); j++){
                if ((i & (1 << j)) != 0) subset.push_back(nums[j]);
            }
            ans.push_back(subset);
        }
        return ans;
    }
};