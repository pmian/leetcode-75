// https://leetcode.com/problems/daily-temperatures/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> s;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!s.empty() and temperatures[i] > temperatures[s.top()])
            {
                int prev = s.top();
                s.pop();
                ans[prev] = i - prev;
            }
            s.push(i);
        }
        return ans;
    }
};