class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int start = 0;
        int end = 0;
        int max_sum = INT_MIN;
        int curr_sum = 0;

        for (int i = 0; i < nums.size(); i++){
            curr_sum += nums[i];
            if (curr_sum > max_sum){
                max_sum = curr_sum;
                end++;
            }
            if (curr_sum < 0){
                curr_sum = 0;
                start++;;
                end = start;
            }
        }

        return max_sum;
    }
};