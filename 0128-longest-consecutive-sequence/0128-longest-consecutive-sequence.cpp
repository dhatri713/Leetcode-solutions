class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // better solution
        int max_length = 0;
        int last_smaller = INT_MIN;
        int curr_length = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++){
            if (last_smaller == nums[i] - 1){
                curr_length++;
                max_length = max(curr_length, max_length);
                last_smaller = nums[i];
            }

            else if (last_smaller == nums[i]){
                continue;
            }

            else {
                last_smaller = nums[i];
                curr_length = 1;
                max_length = max(max_length, curr_length);
            }
        }

        return max_length;

        // optimal

        // int max_length = 0;
        // int curr_length = 0;

        // unordered_set<int> s;
        // for (int i = 0; i < nums.size(); i++){
        //     s.insert(nums[i]);
        // }

        // for (int i = 0; i < nums.size(); i++){
        //     if (s.find(nums[i] - 1) == s.end()){
        //         int x = nums[i];
        //         curr_length = 1;
        //         while (s.find(x + 1) != s.end()){
        //             x++;
        //             curr_length++;
        //         }
        //         max_length = max(max_length, curr_length);
        //     }

        //     else{
        //         curr_length = 0;
        //         continue;
        //         // curr_length = 0;
        //     }
        // }
        // return max_length;
    }
};