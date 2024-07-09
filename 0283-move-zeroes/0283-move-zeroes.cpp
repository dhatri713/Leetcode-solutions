class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int left = 0; // pos to place the non zero element
    //   int right = 0;
        
    //   // move left to a zero position and move right to a non zero position
    //   while(right < nums.size()){
    //     while(nums[left] != 0){
    //         left++;
    //         right++;
    //     }
    //     while(right <= left || nums[right] == 0) right++;
    //     int temp = nums[left];
    //     nums[left] = nums[right];
    //     nums[right] = temp;
    //     left++;
    //     right++;
    //   }

    // method 2

    for (int right = 0; right < nums.size(); right++){
        if (nums[right] != 0){
            nums[left] = nums[right];
            left++;
        }
    }

    for (int i = left; i < nums.size(); i++){
        nums[i] = 0;
    }

    }
};