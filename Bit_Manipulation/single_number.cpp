// https://leetcode.com/problems/single-number/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int i : nums)
        {
            ans ^= i;
        }
        return ans;
    }
};