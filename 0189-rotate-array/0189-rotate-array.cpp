class Solution {
public:
    void reverse(vector<int>& nums, int l, int r){
        while (l <= r){
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            l++;
            r--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        // OPTIMAL SOLN TIME WISE

        // k = k % nums.size();
        // vector<int> temp(k);
        // for (int i = (nums.size() - k); i < nums.size(); i++){
        //     temp[i - (nums.size() - k)] = nums[i];
        // }
        // for (int i = (nums.size() - k - 1); i >= 0; i--){
        //     nums[i + k] = nums[i];
        // }
        // for (int i  = 0; i < k; i++){
        //     nums[i] = temp[i];
        // }

        // OPTIMAL SOLUTION space wise
        k = k % nums.size();
        reverse(nums, 0, (nums.size() - k - 1));
        reverse(nums, nums.size() - k, nums.size() - 1);
        reverse(nums, 0 , nums.size() -1);
    }
};