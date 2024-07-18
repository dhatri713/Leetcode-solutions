class Solution {
public:
    bool shipping_possible(vector<int>weights, int days, int ship_weight){
        int sum = 0;
        for (int i = 0; i < weights.size(); i++){
            while (i < weights.size() && (sum + weights[i]) <= ship_weight){
                sum += weights[i];
                i++;
            }
            days--;
            i--;
            sum = 0;
        }

        return (days >= 0);
    }

    int sum(vector<int> nums){
        int sum = 0;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        return sum;
    }

    int find_max(vector<int> nums){
        int max = INT_MIN;
        for (int i = 0; i < nums.size(); i++){
            if (max < nums[i]) max = nums[i];
        }
        return max;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = find_max(weights);
        int high = sum(weights);
        
        while (low <= high){
            int mid = low + (high - low)/2;
            if (shipping_possible(weights, days, mid))high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }
};