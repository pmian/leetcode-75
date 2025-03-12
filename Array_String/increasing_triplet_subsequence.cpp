// https://leetcode.com/problems/increasing-triplet-subsequence/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int first = INT_MAX, second = INT_MAX;

        for (int num : nums)
        {
            if (num <= first)
            {
                first = num; // Update smallest element
            }
            else if (num <= second)
            {
                second = num; // Update second smallest element
            }
            else
            {
                return true; // Found third element forming an increasing triplet
            }
        }
        return false;
    }
};