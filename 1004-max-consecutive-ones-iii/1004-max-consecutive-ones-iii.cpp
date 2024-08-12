class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int num_zeros = 0;
        int max_length = INT_MIN;
        
        int l = 0;
        int r = 0;
        
        while (r < nums.size()){
            if (nums[r] == 0) num_zeros += 1;
            if (num_zeros > k) {
                // while (num_zeros > k){
                //     if(nums[l] == 0){
                //         num_zeros -= 1;
                //     }
                //     l++;
                // }
                
                if (nums[l] == 0) num_zeros--;
                l++;
            }
            if (num_zeros <= k) max_length = max(max_length, r - l + 1);
            r++;
        }
        
        return max_length;
    }
};