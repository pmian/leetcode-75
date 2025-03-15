// https://leetcode.com/problems/kth-largest-element-in-an-array/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i : nums)
        {
            pq.push(i);
            if (pq.size() > k)
                pq.pop();
        }

        return pq.top();
    }
};