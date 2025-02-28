// https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int i = 0, j = 0, m = s.size(), n = t.size();
        while (i < m and j < n)
        {
            if (s[i] == t[j])
                i++, j++;
            else
                j++;
        }

        return i == m;
    }
};