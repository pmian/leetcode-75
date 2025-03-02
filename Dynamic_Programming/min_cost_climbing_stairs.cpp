// https://leetcode.com/problems/min-cost-climbing-stairs/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();

        // Base cases
        if (n == 0)
            return 0;
        if (n == 1)
            return cost[0];

        // Initialize dp array
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];

        // Fill dp array
        for (int i = 2; i < n; ++i)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        // The minimum cost to reach the top is the minimum of the last two steps
        return min(dp[n - 1], dp[n - 2]);
    }
};