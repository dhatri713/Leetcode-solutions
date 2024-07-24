class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int j = 0;
        string result = "";
        
        while (j < s.length()){
            while (i < s.length() && s[i] == ' ') i++;
            if (i >= s.length()) break;
            j = i + 1;
            while (j < s.length() && s[j] != ' ') j++;

            string w = s.substr(i, j - i);
            if (result == "") result += w;
            else result = w + " " + result;
            
            i = j;
        }
        
        return result;
    }
};