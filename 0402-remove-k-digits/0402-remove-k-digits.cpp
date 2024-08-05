class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.length()) return "0"; // If k equals the length of num, return "0"
    
    stack<char> st;
    
    for (char digit : num) {
        // While the stack is not empty, k > 0, and the current digit is less than the top of the stack
        while (!st.empty() && k > 0 && st.top() > digit) {
            st.pop();
            k--;
        }
        st.push(digit); // Push the current digit onto the stack
    }
    
    // Remove the remaining k digits from the end
    while (k > 0) {
        st.pop();
        k--;
    }
    
    // Construct the resulting number
    string ans = "";
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    
    reverse(ans.begin(), ans.end());
    
    // Remove leading zeros
    int start = 0;
    while (start < ans.size() && ans[start] == '0') {
        start++;
    }
    
    // If all digits are removed, return "0"
    if (start == ans.size()) return "0";
    
    return ans.substr(start);
    }
};