// https://leetcode.com/problems/unique-number-of-occurrences/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> dp, freq;

        for (int i : arr)
        {
            dp[i]++;
        }

        for (auto [f, s] : dp)
        {
            freq[s]++;
        }

        for (auto [f, s] : freq)
        {
            if (s > 1)
                return false;
        }
        return true;
    }
};