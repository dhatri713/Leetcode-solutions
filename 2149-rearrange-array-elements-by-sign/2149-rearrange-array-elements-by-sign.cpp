class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // brute force
        
        // vector<int> positives;
        // vector<int> negatives;

        // for (int i = 0; i < nums.size(); i++){
        //     if (nums[i] < 0) negatives.push_back(nums[i]);
        //     else positives.push_back(nums[i]);
        // }

        // for(int i = 0; i < nums.size(); i++){
        //     if(i % 2 == 0) nums[i] = positives[i / 2];
        //     else nums[i] = negatives[i/2];
        // }

        // optimal

        vector<int> result(nums.size(), 0);
        int p_index = 0;
        int n_index = 1;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] >= 0) {
                result[p_index] = nums[i];
                p_index += 2;
            }
            if (nums[i] < 0) {
                result[n_index] = nums[i];
                n_index += 2;
            }
        }

        return result;
    }
};