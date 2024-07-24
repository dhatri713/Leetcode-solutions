class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
         s += s;
        char start_char = goal[0];
        cout << s << endl;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == start_char){
                string rotated = s.substr(i, goal.length());
                cout << rotated << endl;
                if (rotated != goal)continue;
                else return true;
            }
        }
        
        return false;
    }
};