class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
    for (int i = 0; i < asteroids.size(); i++) {
        bool destroyed = false;
        while (!st.empty() && st.back() > 0 && asteroids[i] < 0) {
            if (st.back() < abs(asteroids[i])) {
                st.pop_back();
            } else if (st.back() == abs(asteroids[i])) {
                st.pop_back();
                destroyed = true;
                break;
            } else {
                destroyed = true;
                break;
            }
        }
        if (!destroyed) {
            st.push_back(asteroids[i]);
        }
    }
    return st;
    }
};