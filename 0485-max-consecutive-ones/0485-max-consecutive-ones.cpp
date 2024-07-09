class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count = 0;
        int curr_count = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                if (curr_count > max_count) max_count = curr_count;
                curr_count = 0;
                continue;
            }
            curr_count ++;
        }
        if (curr_count > max_count)return curr_count;
        else return max_count;

        // for (int i = 0; i < nums.size(); i++){
        //     if (nums[i] == 1){
        //         curr_count ++;
        //         max_count = max(curr_count, max_count);
        //     }
        //     else {
        //         curr_count = 0;
        //     }
        // }

        // return max_count;
    }
};