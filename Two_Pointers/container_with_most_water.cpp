// https://leetcode.com/problems/container-with-most-water/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1;
        int ans = 0;

        while (l < r)
        {
            int h = min(height[l], height[r]);
            int w = r - l;

            ans = max(ans, w * h);
            if (height[l] > height[r])
                r--;
            else
                l++;
        }

        return ans;
    }
};