// https://leetcode.com/problems/maximum-average-subarray-i/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        double ans = INT_MIN;
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            nums[i] += nums[i - 1];
        }
        ans = 1.000000 * nums[k - 1];
        // for(int i: nums)    cout<<i<<" "; cout<<endl;
        for (int i = k; i < n; i++)
        {
            // cout<<ans<<" ";
            ans = max(ans, 0.000000 + nums[i] - nums[i - k]);
        }
        // cout<<ans;
        ans = 1.000000 * (ans) / k;
        return ans;
    }
};