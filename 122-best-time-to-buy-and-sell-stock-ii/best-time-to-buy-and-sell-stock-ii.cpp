class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        if (n==1) return 0;
        int profit = 0;
        int sum_pro = 0;
        int buy = prices[0];
        for (int i = 1; i<n-1; i++) {
            if (prices[i] < prices[i-1]) {
                buy = prices[i];
                continue;
            }
            else {
                profit = prices[i] - buy;
            }
            if (prices[i+1]<prices[i]) {
                sum_pro += profit;
                profit = 0;
            }
            else continue;
        }
        if (prices[n-1] > prices[n-2]) profit = prices[n-1] - buy;
        sum_pro += profit;
        return sum_pro;
    }
};