class Solution {
public:
    int lower_bound(vector<int> v, int x){
    int low = 0;
    int high = v.size() - 1;
    int curr_floor_ind = v.size();

    // while (low <= high){
    //     int mid = low + (high - low)/2;
    //     if (v[mid] == x) {
    //         return mid;
    //     }
    //     else if(v[mid] < x){
    //         low = mid + 1;
    //         curr_floor_ind = max(mid, curr_floor_ind);            }
    //     else {
    //         high = mid - 1;
    //     }
    // }
    // return curr_floor_ind + 1;
        
    // better way to write this
        
    while (low <= high){
        int mid = low + (high - low)/2;
        if (v[mid] >= x){
            curr_floor_ind = mid;
            
            // look for small index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
        return curr_floor_ind;
}
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums, target);
    }
};