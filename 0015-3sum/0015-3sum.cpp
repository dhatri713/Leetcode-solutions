class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // better solution - time limit exceeded

        // set<vector<int>> ans;
        // for (int i = 0; i < nums.size(); i++){
        //     set<int> hashset;
        //     for (int j = i + 1; j < nums.size(); j++){
        //         int rem_sum = -(nums[i] + nums[j]);
        //         if (hashset.find(rem_sum) != hashset.end()){
        //             vector<int> temp = {nums[i], nums[j], rem_sum};
        //             sort(temp.begin(), temp.end());
        //             ans.insert(temp);
        //         }
        //         hashset.insert(nums[j]);
        //     }
        // }
        // vector<vector<int>> ans2(ans.begin(), ans.end());
        // return ans2;

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i = 0;;
        while(i < nums.size() - 2){

            int j = i + 1;
            int k = nums.size() - 1;

            while(j < k){
                int curr_sum = nums[i] + nums[j] + nums[k];
                if (curr_sum < 0){
                    j++;
                }

                else if(curr_sum > 0){
                    k--;
                }

                else {//curr_sum = 0
                    int curr_j = nums[j];
                    int curr_k = nums[k];

                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);

                    while (curr_j == nums[j] && j < k) j++;
                    while (curr_k == nums[k] && j < k) k--;
                }
            }

            int curr_i = nums[i];
            while (curr_i == nums[i] && i < nums.size() - 2){
                //cout << "still in loop, i:" << i << endl;
                i++;
            }
        }

        return ans;
    }
};