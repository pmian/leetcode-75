// https://leetcode.com/problems/move-zeroes/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j])
            {
                nums[i] = nums[j];
                i++;
            }
        }
        for (; i < n; i++)
            nums[i] = 0;
    }
};