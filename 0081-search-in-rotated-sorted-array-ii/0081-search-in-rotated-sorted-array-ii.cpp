class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high){
            int mid = low + (high - low)/2;
            if (nums[mid] == target) return true;
            else if (nums[low] == nums[mid] && nums[mid]== nums[high]){
                low += 1;
                high -= 1;
                // trimming down the search space
            }
            else if (nums[mid] <= nums[high]){// right half is sorted
                if (target > nums[mid] && target <= nums[high]){
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            else {
                if (target >= nums[low] && target < nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
        }
        return false;
    }
};