class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map <char, int> mpp;
        int l = 0, r = 0;
        int max_length = 0;
        int n = s.length();
        while (r < s.length()){
            if (mpp.find(s[r]) != mpp.end()) {
                if (l <= mpp[s[r]]) l = mpp[s[r]] + 1;
            }
            
            mpp[s[r]] = r;
            max_length = max(max_length, r - l + 1);
            cout << l << " " << r << " " << max_length << endl;
            r++;
            //cout << r << endl;
        }
        
        return max_length;
    }
};