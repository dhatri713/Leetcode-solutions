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

//     // method 2

//     for (int right = 0; right < nums.size(); right++){
//         if (nums[right] != 0){
//             nums[left] = nums[right];
//             left++;
//         }
//     }

//     for (int i = left; i < nums.size(); i++){
//         nums[i] = 0;
//     }
        
        // method 3
        // find the first zero
        
        int j = -1;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                j = i;
                break;
            }
        }
        
        if (j == -1) return;
        
        for (int i = j + 1; i < nums.size(); i++){
            if (nums[i] != 0){
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                j++;
            }
        }

    }
};