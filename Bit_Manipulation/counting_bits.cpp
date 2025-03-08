// https://leetcode.com/problems/counting-bits/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1, 0); // Initialize the answer array with 0s

        for (int i = 1; i <= n; ++i)
        {
            // ans[i] = ans[i / 2] + (i % 2)
            ans[i] = ans[i >> 1] + (i & 1);
        }

        return ans;
    }
};