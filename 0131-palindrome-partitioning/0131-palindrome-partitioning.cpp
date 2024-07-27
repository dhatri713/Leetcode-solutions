class Solution {
public:
    void generate(string s, vector<vector<string>>& ans, vector<string>& path, int index){
        if (index == s.length()){
            ans.push_back(path);
            return;
        }
        
        for (int i = index; i < s.length(); i++){
            if (is_palindrome(s.substr(index, i - index + 1))) {
                path.push_back(s.substr(index, i - index + 1));
                generate(s, ans, path, i+ 1);
                path.pop_back();
            }
        }
    }
    
    bool is_palindrome(string s){
        int start = 0;
        int end = s.length() - 1;
        
        while (start <= end){
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        generate(s, ans, path, 0);
        return ans;
    }
};