// https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> answer(n, 1);

        // Compute left product (prefix product)
        int left = 1;
        for (int i = 0; i < n; i++)
        {
            answer[i] = left;
            left *= nums[i];
        }

        // Compute right product (suffix product) and update answer
        int right = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            answer[i] *= right;
            right *= nums[i];
        }

        return answer;
    }
};