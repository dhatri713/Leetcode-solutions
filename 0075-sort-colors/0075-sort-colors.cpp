class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        for (int i = 0; i < nums.size(); i++){
            if (nums[mid] == 0){
                int temp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = temp;
                mid++;
                low++;
            }

            else if(nums[mid] == 1) mid++;
            else {
                int temp = nums[mid];
                nums[mid] = nums[high];
                nums[high] = temp;
                high--;
            }
        }
    }
};