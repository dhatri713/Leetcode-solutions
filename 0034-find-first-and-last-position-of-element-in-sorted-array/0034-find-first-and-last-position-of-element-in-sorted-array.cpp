class Solution {
public:
    int first_position(vector<int> nums, int target){
        int ans = -1;
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right){
            int mid = left + (right - left)/2;
            if (nums[mid] == target){
                ans = mid;
                right = mid - 1; // continue checking in the left half
            }
            else if (nums[mid] > target){
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
    
int last_position(vector<int> nums, int target){
    int ans = -1;
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right){
        int mid = left + (right - left)/2;
        if (nums[mid] == target){
            ans = mid;
            left = mid + 1; // continue checking in the righr half
        }
        else if (nums[mid] > target){
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return ans;
}
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(first_position(nums, target));
        ans.push_back(last_position(nums, target));
        return ans;
    }
};