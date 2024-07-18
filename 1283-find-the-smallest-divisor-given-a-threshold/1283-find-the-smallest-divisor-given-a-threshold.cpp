class Solution {
public:
    int sum(vector<int> nums, int divisor){
        double sum = 0;
        for (int i = 0; i < nums.size(); i++){
            sum += ceil(static_cast<double>(nums[i]) / divisor);
        }
        return sum;
    }

    int find_max(vector<int> nums){
        int max = INT_MIN;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > max) max = nums[i];
        }
        return max;
    }


    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = find_max(nums);
        int divisor;

        while(low <= high){
            int mid = low + (high - low)/2;
            int curr_sum = sum(nums, mid);
            if (curr_sum <= threshold) {
                divisor = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return divisor;
    }
};