// https://leetcode.com/problems/unique-paths/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // long long res = 1;
        // int N = m + n - 2;  // Total moves
        // int R = min(m - 1, n - 1);  // Choose the smaller one
        // for (int i = 1; i <= R; i++) {
        //     res = res * (N - i + 1) / i;
        // }
        // return (int)res;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        auto possible = [m, n](int i, int j)
        {
            return (i >= 0 and j >= 0 and i < m and j < n);
        };

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!i and !j)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    if (possible(i, j - 1))
                    {
                        dp[i][j] += dp[i][j - 1];
                    }
                    if (possible(i - 1, j))
                    {
                        dp[i][j] += dp[i - 1][j];
                    }
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};