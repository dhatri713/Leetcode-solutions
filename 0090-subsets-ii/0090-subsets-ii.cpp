class Solution {
public:
    void generate(int ind, vector<vector<int>>& ans, vector<int>& subset, vector<int> nums){
        // our recursive call is inside a for loop so the base is there only
        ans.push_back(subset);
        
        for (int i = ind; i < nums.size(); i++){
            if (i > ind && nums[i] == nums[i - 1]) continue;
            subset.push_back(nums[i]);
            generate(i + 1, ans, subset, nums);
            subset.pop_back();
            //generate(i + 1, ans, subset, nums);
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        generate(0, ans, subset, nums);
        return ans;
    }
};