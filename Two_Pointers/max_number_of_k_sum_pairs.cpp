// https://leetcode.com/problems/max-number-of-k-sum-pairs/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;
        int operations = 0;

        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum == k)
            {
                operations++;
                left++;
                right--;
            }
            else if (sum < k)
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return operations;
    }
};