// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int n = candies.size();
        vector<bool> ans(n, false);
        int maxi = -1;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, candies[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if ((candies[i] + extraCandies) >= maxi)
                ans[i] = true;
        }
        return ans;
    }
};