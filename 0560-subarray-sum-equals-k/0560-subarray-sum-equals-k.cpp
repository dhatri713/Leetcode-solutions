class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixes;
        prefixes[0] = 1;
        int sum = 0;
        int num_subarrays = 0;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int rem_sum = sum - k;
            num_subarrays += prefixes[rem_sum];
            prefixes[sum] += 1;
        }
        return num_subarrays;
    }
};