class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int breakpoint = -1;
        for (int i = 0; i < nums.size() - 1; i++){
            if (nums[i] < nums[i + 1]){
                breakpoint = i;
            }
        }
        if (breakpoint == -1){
            sort(nums.begin(), nums.end());
            return;
        }

        int next_max;
        // int curr_max;
        int next_max_ind;
        // for (int i = breakpoint + 1; i < nums.size(); i++){
        //     if (nums[i] >= nums[breakpoint]){
        //         curr_max = nums[i];
        //         next_max = min(next_max, curr_max);
        //         next_max_ind = i;
        //     }
        // }

        // int temp = nums[breakpoint + 1];
        // nums[breakpoint + 1] = nums[next_max_ind];
        // nums[next_max_ind] = temp;

        // sort(nums.begin() + breakpoint + 2, nums.end());

        sort(nums.begin() + breakpoint + 1, nums.end());

        for (int i = breakpoint + 1; i < nums.size(); i++){
            if (nums[i] > nums[breakpoint]){
                next_max = nums[i];
                next_max_ind = i;
                break;
            }
        }

        int temp = nums[breakpoint];
        nums[breakpoint] = nums[next_max_ind];
        nums[next_max_ind] = temp;

        sort(nums.begin() + breakpoint + 1, nums.end());
    }
};