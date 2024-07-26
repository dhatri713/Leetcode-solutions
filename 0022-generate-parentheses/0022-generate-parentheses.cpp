class Solution {
public:
    void generate(int num_open, int num_close, string prefix, vector<string>& arr){
        if (num_close == 0 && num_open == 0){
            arr.push_back(prefix);
            return;
        }
        
        if (num_open > 0) {
            generate(num_open - 1, num_close, prefix + '(', arr);
        }
        if (num_close > 0 && num_close > num_open) {
            generate(num_open, num_close - 1, prefix + ')', arr);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(n, n, "", ans);
        return ans;
    }
};