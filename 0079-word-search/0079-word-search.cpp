class Solution {
public:
    bool word_search(int i, int j, int index, vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int m, int n){
        if (index == word.length()){
            return true;
        }
        
        if (i < 0 || i >= m || j < 0 || j >= n || word[index] != board[i][j] || visited[i][j]) return false;
        
        visited[i][j] = true;
        
        if (word_search(i, j + 1, index + 1, board, word, visited, m, n) ||
           word_search(i, j - 1, index + 1, board, word, visited, m, n) ||
           word_search(i + 1, j, index + 1, board, word, visited, m, n) ||
           word_search(i - 1, j, index + 1, board, word, visited, m, n)) return true;
        
        visited[i][j] = false;
        
        return false;
        
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (word[0] == board[i][j] && word_search(i, j, 0, board, word, visited, m, n)) return true;
            }
        }
        
        return false;
    }
};