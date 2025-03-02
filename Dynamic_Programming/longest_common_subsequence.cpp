// https://leetcode.com/problems/longest-common-subsequence/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size(); // Length of text1
        int n = text2.size(); // Length of text2

        // Create a DP table of size (m+1) x (n+1)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    // If characters match, add 1 to the LCS of the remaining strings
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    // Otherwise, take the maximum of LCS by excluding one character from text1 or text2
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // The result is in dp[m][n]
        return dp[m][n];
    }
};