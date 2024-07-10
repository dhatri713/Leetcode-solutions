class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int buy_price = prices[0];

        for (int i = 1; i < prices.size(); i++){
            int curr_profit = prices[i] - buy_price;
            max_profit = max(curr_profit, max_profit);
            buy_price = min(prices[i], buy_price);
        }

        return max_profit;
    }
};