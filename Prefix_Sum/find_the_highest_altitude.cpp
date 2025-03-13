// https://leetcode.com/problems/find-the-highest-altitude/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int ans = 0, curr = 0;
        for (int i : gain)
        {
            curr += i;
            ans = max(ans, curr);
        }
        return ans;
    }
};