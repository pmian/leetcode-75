// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int left = 0;       // Left pointer of the window
        int max_length = 0; // Maximum length of the subarray
        int zero_count = 0; // Count of zeros in the current window

        for (int right = 0; right < nums.size(); ++right)
        {
            if (nums[right] == 0)
            {
                zero_count++;
            }

            // If there are more than one zero, move the left pointer
            while (zero_count > 1)
            {
                if (nums[left] == 0)
                {
                    zero_count--;
                }
                left++;
            }

            // Calculate the length of the current window
            max_length = max(max_length, right - left);
        }

        // If the entire array is 1's, we need to delete one element
        if (max_length == nums.size())
        {
            return max_length - 1;
        }

        return max_length;
    }
};