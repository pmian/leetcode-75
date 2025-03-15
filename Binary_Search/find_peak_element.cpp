// https://leetcode.com/problems/find-peak-element/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int i = 0, j = nums.size() - 1;
        int ans = -1;
        while (i <= j)
        {
            int m = (i + j) / 2;
            bool left = false;
            bool right = false;

            m == 0 ? left = true : left = (nums[m] > nums[m - 1]);
            m == (nums.size() - 1) ? right = true : right = (nums[m] > nums[m + 1]);

            if (!left)
            {
                j = m - 1;
            }
            else if (!right)
            {
                i = m + 1;
            }
            else
            {
                ans = m;
                break;
            }
        }
        return ans;
    }
};