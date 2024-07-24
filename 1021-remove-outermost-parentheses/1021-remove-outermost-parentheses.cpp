class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;
        string ans = "";
        for (int i = 0; i < s.length(); i++){
            if (st.empty()) st.push(s[i]);
            else if (!st.empty() && s[i] == ')'){
                st.pop();
                if (!st.empty()) ans += s[i];
            }
            else {
                st.push(s[i]);
                ans += s[i];
            }
        }
        return ans;
    }
};