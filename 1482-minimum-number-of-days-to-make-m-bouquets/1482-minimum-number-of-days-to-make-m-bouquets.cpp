class Solution {
public:
    int find_min(vector<int>& bloomDay){
        int min = INT_MAX;
        for (int i = 0; i < bloomDay.size(); i++){
            if (bloomDay[i] < min) min = bloomDay[i];
        }
        return min;
    }
    
    int find_max(vector<int>& bloomDay){
        int max = INT_MIN;
        for (int i = 0; i < bloomDay.size(); i++){
            if (bloomDay[i] > max) max = bloomDay[i];
        }
        return max;
    }
    
    bool is_bqt_possible(vector<int> v, int day, int m, int k){
        int num_bqts = 0;
        int cnt = 0;
        
        for (int i = 0; i < v.size(); i++){
            if (day >= v[i]) cnt++;
            else {
                num_bqts += (cnt/k);
                cnt = 0;
            }
        }
        num_bqts += (cnt/k);
        
        if (num_bqts >= m) return true;
        else return false;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = find_min(bloomDay);
        int high = find_max(bloomDay);
        int answer = -1;
        
        while (low <= high){
            int mid = low + (high - low)/2;
            if (is_bqt_possible(bloomDay, mid, m, k) ){
                answer = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return answer;
    }
};