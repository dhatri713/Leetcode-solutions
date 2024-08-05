class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> nse(vector<int>& nums){
        vector<int> nse_vec(nums.size());
        int n = nums.size();
        stack<int> st;
        for (int i = n - 1; i >= 0; i--){
            while (!st.empty() && nums[i] <= nums[st.top()]) st.pop();
            nse_vec[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        
        return nse_vec;
    }
    
    vector<int> psee(vector<int>& nums){
        vector<int> psee_vec(nums.size(), -1);
        int n = nums.size();
        stack<int> st;
        for (int i = 0; i < n; i++){
            while (!st.empty() && nums[i] < nums[st.top()]) st.pop();
            psee_vec[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        
        return psee_vec;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        int total = 0;
        vector<int> nse_vec = nse(arr);
        vector<int> psee_vec = psee(arr);
        for (int i = 0; i < arr.size(); i++){
            int left = i - psee_vec[i];
            int right = nse_vec[i] - i;
            
            total = (total + (long long)arr[i] * left * right * 1LL % MOD) % MOD;
        }
        return total;
    }
};