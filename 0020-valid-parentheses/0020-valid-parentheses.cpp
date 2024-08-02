class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        unordered_map<char, char> mpp;
        mpp[')'] = '(';
        mpp['}'] = '{';
        mpp[']'] = '[';
        for (int i = 0; i < s.length(); i++){
            if(st.empty()) st.push(s[i]);
            else if (mpp[s[i]] == st.top()) st.pop();
            else st.push(s[i]);
        }

        return st.empty();
    }
};