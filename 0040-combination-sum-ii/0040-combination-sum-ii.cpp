class Solution {
public:
//     void generate(int i, vector<int> nums, set<vector<int>>& subsets, vector<int>& subset, int sum, int target){
//         if (i >= nums.size()){
//             if (sum == target) {
//                 sort(subset.begin(), subset.end());
//                 subsets.insert(subset);
//             }
//             return;
//         }
        
//         // decision to include nums[i]
//         sum += nums[i];
//         subset.push_back(nums[i]);
//         generate(i + 1, nums, subsets, subset, sum, target);
        
//         // decision to not include nums[i]
//         sum -= nums[i];
//         subset.pop_back();
//         generate(i + 1, nums, subsets, subset, sum, target);
//     }
    
    void generate(int ind, int sum, int target, vector<vector<int>>& ans, vector<int>& subset, vector<int> nums){
        // our recursive call is inside a for loop so the base is there only
        if (sum == target){
            ans.push_back(subset);
            return;
        }
        
        for (int i = ind; i < nums.size(); i++){
            if (i > ind && nums[i] == nums[i - 1]) continue;
            if (sum > target) break;
            if (nums[i] > target) break;
            
            subset.push_back(nums[i]);
            sum += nums[i];
            generate(i + 1, sum, target, ans, subset, nums);
            sum -= nums[i];
            subset.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        generate(0, 0, target, ans, subset, candidates);
        return ans;
    }
};