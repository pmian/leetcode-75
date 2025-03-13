// https://leetcode.com/problems/find-pivot-index/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> left(n), right(n);
        left[0] = nums[0];
        right[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++)
            left[i] = left[i - 1] + nums[i];
        for (int i = n - 2; i >= 0; i--)
            right[i] = right[i + 1] + nums[i];

        for (int i = 0; i < n; i++)
        {
            int l, r;
            if (i == 0)
            {
                l = 0;
            }
            else
            {
                l = left[i - 1];
            }

            if (i == n - 1)
            {
                r = 0;
            }
            else
            {
                r = right[i + 1];
            }
            if (l == r)
                return i;
        }

        return -1;
    }
};