class Solution
{
public:
    vector<vector<int>> dp; // DP table for memoization

    int helper(int i, bool isHold, vector<int> &prices, int fee)
    {
        // Base case: if we reach the end of the array, return 0
        if (i >= prices.size())
        {
            return 0;
        }

        // If the result is already computed, return it
        if (dp[i][isHold] != -1)
        {
            return dp[i][isHold];
        }

        int ans = 0;
        if (isHold)
        {
            // If holding the stock, decide whether to sell or skip
            int sell = prices[i] - fee + helper(i + 1, false, prices, fee); // Sell the stock
            int skip = helper(i + 1, true, prices, fee);                    // Skip and continue holding
            ans = max(sell, skip);
        }
        else
        {
            // If not holding the stock, decide whether to buy or skip
            int buy = -prices[i] + helper(i + 1, true, prices, fee); // Buy the stock
            int skip = helper(i + 1, false, prices, fee);            // Skip and continue without holding
            ans = max(buy, skip);
        }

        // Memoize the result
        dp[i][isHold] = ans;
        return ans;
    }

    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        // Initialize the DP table with -1
        dp.resize(n, vector<int>(2, -1));
        // Start with cash state (not holding any stock)
        return helper(0, false, prices, fee);
    }
};