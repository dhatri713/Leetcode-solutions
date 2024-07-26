class Solution {
public:
    double myPow(double x, int n) {
          if (n == 0) return 1.0;
    if (n == 1) return x;
    if (n == -1) return 1 / x;

    if (n == INT_MIN) {
        x = 1 / x;
        n = INT_MAX;
        return myPow(x, n) * x;
    }

    double half = myPow(x, n / 2);
    double result = half * half;

    if (n % 2 != 0) {
        if (n > 0) result *= x;
        else result /= x;
    }

    return result;
    }
};