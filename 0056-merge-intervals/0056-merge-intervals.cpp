class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> curr_interval = intervals[0];

        for (int i = 0; i < intervals.size(); i++){
            if (curr_interval[1] >= intervals[i][0]) {
                curr_interval[1] = max(curr_interval[1], intervals[i][1]);
            }
            else if (curr_interval[1] < intervals[i][0]){
                ans.push_back(curr_interval);
                curr_interval = intervals[i];
            }

            if (i == intervals.size() - 1) ans.push_back(curr_interval);
        }
        return ans;
    }
};