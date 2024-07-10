class Solution {
public:
    int binary_search(vector<pair<int, int>>nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        // int mid = left + (right - left)/2;
        while (left <= right){
            int mid = left + (right - left)/2;
            if (nums[mid].first == target) return mid;
            if (nums[mid].first > target) right = mid - 1;
            else left = mid + 1;

        }
        return -1;
    }
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     vector<int> indices(2);
    //     sort(nums.begin(), nums.end()); // nlogn
    //     for (int i = 0; i < nums.size(); i++){ //nlogn
    //         int x = target - nums[i];
    //         if (binary_search(nums, x) != -1){
    //             int j = binary_search(nums, x);
    //             indices[0] = i;
    //             indices[1] = j;
    //             return indices;
    //         }
    //     }
    //     return indices;
    // }

    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;
        vector<int> indices(2);
        for (int i = 0; i < nums.size(); i++){
            int x = target - nums[i];
            if (mpp.find(x) != mpp.end()){
                indices[0] = mpp[x];
                indices[1] = i;
                return indices;            
            }
            mpp[nums[i]] = i;
        }
        return indices;
    }
    // vector<int> twoSum(vector<int>& nums, int target){
    //     vector<pair<int, int>> pairs(nums.size());
    //     vector<int> indices(2);
    //     for(int i = 0; i < nums.size(); i++){
    //         pairs[i].first = nums[i];
    //         pairs[i].second = i;
    //     }

    //     sort(pairs.begin(), pairs.end());

    //     for (int i = 0; i < nums.size(); i++){ //nlogn
    //         int x = target - pairs[i].first;
    //         if (binary_search(pairs, x) != -1){
    //             int j = binary_search(pairs, x);
    //             indices[0] = pairs[i].second;
    //             indices[1] = pairs[j].second;
    //             return indices;
    //         }
    //     }
    // //     return indices;
    // };
};