class Solution {
public:
    bool check(vector<int>& nums) {
        int count_drops = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > nums[(i + 1) % nums.size()]) count_drops ++;
        }
        return count_drops <= 1;
    }
};