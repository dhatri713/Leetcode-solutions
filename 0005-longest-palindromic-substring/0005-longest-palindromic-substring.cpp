class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = 0;
        string result = "";
        
        for (int i = 0; i < s.length(); i++){
            //odd length
            int l = i, r = i;
            while (l >= 0 && r < s.length() && s[l] == s[r]){
                int curr_len = r - l + 1;
                if (curr_len > max_len){
                    max_len = curr_len;
                    result = s.substr(l, r - l + 1);
                }
                l -= 1;
                r += 1;
            }
            
            //even length
            l = i;
            r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]){
                int curr_len = r - l + 1;
                if (curr_len > max_len){
                    max_len = curr_len;
                    result = s.substr(l, r - l + 1);
                }
                l -= 1;
                r += 1;
            }
        }
        
        return result;
    }
};