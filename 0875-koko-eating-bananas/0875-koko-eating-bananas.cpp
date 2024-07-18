#include <bits/stdc++.h>
class Solution {
public:
    int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}
    bool koko_can_finish(vector<int>& piles, int h, int k){
        int total_hrs = 0;
        if (k == 0) return false;
        for (int i = 0; i < piles.size(); i++){
            total_hrs += ceil((double)piles[i]/k);
            // cout << total_hrs << endl;
        }
        return (total_hrs <= h);
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        //sort(piles.begin(), piles.end());
        int low = 0;
        int high = findMax(piles);
        int k;
        
        while (low <= high){
            int mid = low + (high - low)/2;
            if (koko_can_finish(piles, h, mid)){
                k = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return k;
    }
};