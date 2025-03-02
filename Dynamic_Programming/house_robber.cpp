// https://leetcode.com/problems/house-robber/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        // dp[i] represents the maximum amount of money that can be robbed up to house i
        vector<int> dp(n, 0);

        // Base cases
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        // Fill the dp array
        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        // The last element in dp will have the maximum amount
        return dp[n - 1];
    }
};