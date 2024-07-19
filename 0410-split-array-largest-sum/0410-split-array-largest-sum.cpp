class Solution {
public:
    pair<int, int> max_sum(vector<int>& nums, int max_num){
        int num_partitions = 1;
        int subarray_sum = 0;
        int maximum = INT_MIN;
        
        for (int i = 0; i < nums.size(); i++){
            if (subarray_sum + nums[i]<= max_num){
                subarray_sum += nums[i];
            }
            else {
                maximum = max(maximum, subarray_sum);
                num_partitions += 1;
                subarray_sum = nums[i];
            }
        }
        maximum = max(maximum, subarray_sum);
        pair<int, int> result;
        result.first = num_partitions;
        result.second = maximum;
        return result;
        
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int answer;
        
        while (low <= high){
            int mid = low + (high - low)/2;
            pair<int, int> result = max_sum(nums, mid);
            if (result.first > k) low = mid + 1;
            else {
                high = mid - 1;
                answer = result.second;
            }
            
        }
        return answer;
    }
};