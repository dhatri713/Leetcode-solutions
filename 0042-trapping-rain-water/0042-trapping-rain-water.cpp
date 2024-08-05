class Solution {
public:
    int trap(vector<int>& height) {
//         //approach 1
//         vector<int> prefix(height.size(), 0);
//         vector<int> suffix(height.size(), 0);
//         int volume = 0;
        
//         prefix[0] = height[0];
//         for (int i = 1; i < height.size(); i++){
//             prefix[i] = max(prefix[i - 1], height[i]);
//         }
        
//         suffix[height.size() - 1] = height[height.size() - 1];
//         for (int i = height.size() - 2; i >= 0; i--){
//             suffix[i] = max(suffix[i + 1], height[i]);
//         }
        
//         for (int i = 0; i < height.size(); i++){
//             if (height[i] < prefix[i] && height[i] < suffix[i]){
//                 volume += (min(prefix[i], suffix[i]) - height[i]);
//             }
//         }
        
//         return volume;
        
        // approach 2
        int n = height.size();
        int lm = 0;
        int rm = 0;
        int l = 0;
        int r = n - 1;
        int vol = 0;
        
        while (l < r){
            if (height[l] < height[r]){
                if (lm > height[l]) vol += (lm - height[l]);
                else lm = height[l];
                l++;
            }
            else {
                if (rm > height[r]) vol += (rm - height[r]);
                else rm = height[r];
                r--;
            }
        }
        
        return vol;
    }
};