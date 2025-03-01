// https://leetcode.com/problems/max-consecutive-ones-iii/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int left = 0;       // Left pointer of the window
        int max_length = 0; // Maximum length of the window
        int zero_count = 0; // Count of zeros in the current window

        for (int right = 0; right < nums.size(); right++)
        {
            if (nums[right] == 0)
            {
                zero_count++;
            }

            // If zero_count exceeds k, move the left pointer to the right
            while (zero_count > k)
            {
                if (nums[left] == 0)
                {
                    zero_count--;
                }
                left++;
            }

            // Update the maximum length of the window
            max_length = max(max_length, right - left + 1);
        }

        return max_length;
    }
};