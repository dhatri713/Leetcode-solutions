class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // better solution

        // map<int, int> mpp;
        // for (int i = 0; i < nums.size(); i++){
        //     mpp[(nums[i])]++;
        //     if(mpp[nums[i]] > nums.size()/2){
        //         return nums[i];
        //     }
        // }
        // return -1;

        // optimal solution
        
        int count = 0;
        int majority;
        for (int i = 0; i < nums.size(); i++){
            if (count == 0){
                majority = nums[i];
            }

            if (nums[i] == majority){
                count++;
            } 
            else count--;
        }
        
        if (count >= 1) return majority;
        return -1;
    }
};