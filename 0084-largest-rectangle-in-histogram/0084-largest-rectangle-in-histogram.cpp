class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(0);
        int max_area = INT_MIN;
        int nse, pse, curr_area, curr_height;
        
        for (int i = 1; i < heights.size(); i++){
            while (!st.empty() && i < heights.size() && heights[st.top()] < heights[i]){
                st.push(i);
                i++;
            }
            
            while (i < heights.size() && !st.empty() && heights[st.top()] > heights[i]) {
                nse = i;
                curr_height = heights[st.top()];
                st.pop();
                pse = st.empty() ? -1 : st.top();
                curr_area = curr_height * (nse - pse - 1);
                max_area = max(max_area, curr_area);
            }
            
            if (i != heights.size()) st.push(i);
        }
        
        nse = heights.size();
        while (!st.empty()){
            curr_height = heights[st.top()];
            st.pop();
            pse = st.empty() ? -1 : st.top();
            curr_area = curr_height * (nse - pse - 1);
            max_area = max(max_area, curr_area);
        }
        
        return max_area;
    }
};