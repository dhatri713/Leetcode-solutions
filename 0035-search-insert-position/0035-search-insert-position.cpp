class Solution {
public:
    int lower_bound(vector<int> v, int x){
    int low = 0;
    int high = v.size() - 1;
    int curr_floor_ind = -1;

    while (low <= high){
        int mid = low + (high - low)/2;
        if (v[mid] == x) {
            return mid;
        }
        else if(v[mid] < x){
            low = mid + 1;
            curr_floor_ind = max(mid, curr_floor_ind);            }
        else {
            high = mid - 1;
        }
    }
    return curr_floor_ind + 1;
}
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums, target);
    }
};