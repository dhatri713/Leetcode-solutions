class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX; // Division by zero
        if (dividend == divisor) return 1;
        
        int sign = 1;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) sign = -1;
        long long n = labs(dividend);
        long long d = labs(divisor);
        
        long long ans = 0;
        long long cnt = 0;
        while (n >= d){
            cnt = 0;
            while (n >= (d * (1LL * 1 << (cnt + 1)))){
                cnt++;
            }
            ans += 1 << cnt;
            n -= (d * (1LL * 1 << cnt));
        }
        cout << cnt;
        if (cnt == 31 && sign == 1) return INT_MAX;
        if (cnt == 31 && sign == -1) return INT_MIN;
        ans *= sign;
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;

        return static_cast<int>(ans);
    }
};