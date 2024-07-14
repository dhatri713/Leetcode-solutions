class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; // traverse thru first array
        int j = 0; // traverse thru second array

        while (i >= 0 && j < n){
            if (nums1[i] >= nums2[j]){
                int temp = nums1[i];
                nums1[i] = nums2[j];
                nums2[j] = temp;
                i--;
                j++;
                continue;
            }
            if (nums1[i] < nums2[j]) break;
        }

        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(), nums2.end());

        for (int i = m; i < (m + n); i++){
            nums1[i] = nums2[i - m];
        }
    }
};