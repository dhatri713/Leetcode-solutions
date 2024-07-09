class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n = nums.size();
        // int original_sum = n * (n + 1)/2;
        // int arr_sum = 0;
        
        // for (int i = 0; i < nums.size(); i++){
        //     arr_sum += nums[i];
        // }
        
        // return original_sum - arr_sum;

        // using XOR
        int xor1 = 0;//xor of array elements
        int xor2 = 0;
        for (int i = 0; i < nums.size(); i++){
            xor1 = xor1 ^ nums[i];
            xor2 = xor2 ^ (i + 1);
        }

        return xor1 ^ xor2;
    }
};