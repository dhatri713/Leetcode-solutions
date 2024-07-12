class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> soln;
        int el1, el2, count1 = 0, count2 = 0;
        // because at max there can only be two majority elements
        
        for (int i = 0; i < nums.size(); i++){
            
            if (count1 == 0 && nums[i] != el2){
                el1 = nums[i];
                count1++;
            }
            else if (count2 == 0 && nums[i] != el1){
                el2 = nums[i];
                count2++;
            }
            else if (nums[i] == el1) count1++;
            else if (nums[i] == el2) count2++;
            
            // else if (count1 > floor(nums.size()/3)) soln.push_back(el1);
            // else if (count2 > floor(nums.size()/3)) soln.push_back(el2);
            
            else{
                count1--;
                count2--;
            }
        }
        
        // Reset counts for validation
        count1 = count2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == el1) {
                count1++;
            } else if (nums[i] == el2) {
                count2++;
            }
        }

        // Validate the candidates
        if (count1 > nums.size() / 3) soln.push_back(el1);
        if (count2 > nums.size() / 3) soln.push_back(el2);

        return soln;
    }
};