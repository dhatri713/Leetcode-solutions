class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nge(nums.size(), -1);
        int n = nums.size();
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; i--){
            while (!st.empty() && nums[i % n] >= st.top()) st.pop();
            if (i < n) nge[i] = st.empty() ? -1 : st.top();
            st.push(nums[i % n]);
        }
        
        return nge;
    }
};