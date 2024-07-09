class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int original_sum = n * (n + 1)/2;
        int arr_sum = 0;
        
        for (int i = 0; i < nums.size(); i++){
            arr_sum += nums[i];
        }
        
        return original_sum - arr_sum;
    }
};