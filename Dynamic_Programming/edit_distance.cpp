// https://leetcode.com/problems/edit-distance/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    int helper(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
    {
        if (i < 0)
            return j + 1; // Insert remaining j+1 chars
        if (j < 0)
            return i + 1; // Delete remaining i+1 chars

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j])
            return dp[i][j] = helper(i - 1, j - 1, word1, word2, dp); // Move diagonally (no edit)

        return dp[i][j] = 1 + min(helper(i - 1, j - 1, word1, word2, dp),   // Replace
                                  min(helper(i - 1, j, word1, word2, dp),   // Delete
                                      helper(i, j - 1, word1, word2, dp))); // Insert
    }

    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1)); // Fix indexing
        return helper(m - 1, n - 1, word1, word2, dp);
    }
};
