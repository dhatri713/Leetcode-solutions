class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0;
        for (int i = 0; i < k; i++){
            lsum += cardPoints[i];
        }
        
        int max_sum = lsum;
        int rindex = cardPoints.size() - 1;
        int rsum = 0;
        int lindex = k - 1;
        for (int i = k - 1; i >= 0; i--){
            rsum += cardPoints[rindex];
            lsum -= cardPoints[i];
            max_sum = max(max_sum, rsum + lsum);
            rindex --;
        }
        return max_sum;
    }
};