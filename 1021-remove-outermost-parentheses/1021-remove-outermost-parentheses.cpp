class Solution {
public:
    string removeOuterParentheses(string s) {
        // stack<int> st;
        // string ans = "";
        // for (int i = 0; i < s.length(); i++){
        //     if (st.empty()) st.push(s[i]);
        //     else if (!st.empty() && s[i] == ')'){
        //         st.pop();
        //         if (!st.empty()) ans += s[i];
        //     }
        //     else {
        //         st.push(s[i]);
        //         ans += s[i];
        //     }
        // }
        // return ans;
        
        string ans = "";
        int counter = 0;
        for (int i = 0; i < s.length(); i++){
            if (counter == 0 and s[i] == '(') counter += 1;
            else if (counter == 1 && s[i] == ')') counter -= 1;
            else if (counter != 0 && s[i] == '('){
                counter += 1;
                ans += '(';
            }
            else if (counter != 0 && s[i] == ')'){
                counter -= 1;
                ans += ')';
            }
        }
        return ans;
    }
};