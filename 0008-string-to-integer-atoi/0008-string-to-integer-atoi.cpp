class Solution {
public:
    int myAtoi(string s) {
       int i = 0;
       while (i < s.length() && s[i] == ' ')i++;
       if (i == s.length()) return 0;
        int sign = 1;
       if (s[i] == '-') {
           sign = -1;
           i++;
       }
        else if (s[i] == '+') {
           i++;
       }
        
        while (i < s.length() && s[i] == '0')i++;
        if (i == s.length()) return 0;
        int j = i;
        while (j < s.length() && (48 <= (int)s[j] &&  (int)s[j] <= 57)){
            j++;
        }
        int len = j - i;
        int ans = 0;
        while (len > 0){
            if (!(48 <= (int)s[i] &&  (int)s[i] <= 57))break;
            int int_val = s[i] - '0';
            if ((ans + (int_val * pow(10, len-1) ))* sign >= INT_MAX) return INT_MAX;
            if ((ans + (int_val * pow(10, len-1) )) * sign <= INT_MIN) return INT_MIN;
            ans += (int_val * pow(10, len-1));
            len -= 1;
            i++;
        }
        return ans * sign;
    }
};