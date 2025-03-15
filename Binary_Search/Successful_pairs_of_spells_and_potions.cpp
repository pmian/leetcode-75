// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/submissions/1566694212/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        sort(potions.begin(), potions.end()); // Step 1: Sort potions array
        vector<int> result;

        for (int spell : spells)
        {
            long long required = (success + spell - 1) / spell; // Avoid floating point
            auto it = lower_bound(potions.begin(), potions.end(), required);
            result.push_back(potions.end() - it);
        }

        return result;
    }
};