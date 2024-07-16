#include <bits/stdc++.h>
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int min_val = INT_MAX;

        while (low <= high){
            int mid = low + (high - low)/2;
            if (nums[mid] <= nums[high]){//right half is sorted
                min_val = min(nums[mid], min_val);
                high = mid - 1;
            }
            else {// left half is sorted
                min_val = min(nums[low], min_val);
                low = mid + 1;
            }
        }
        return min_val;
    }
};