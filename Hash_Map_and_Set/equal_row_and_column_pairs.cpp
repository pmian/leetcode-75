// https://leetcode.com/problems/equal-row-and-column-pairs/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int ans = 0;
        int n = grid.size();
        map<vector<int>, int> m;
        for (int j = 0; j < n; j++)
        {
            vector<int> v;
            for (int i = 0; i < n; i++)
            {
                v.push_back(grid[i][j]);
            }
            m[v]++;
        }

        for (int i = 0; i < n; i++)
        {
            vector<int> v;
            for (int j = 0; j < n; j++)
            {
                v.push_back(grid[i][j]);
            }
            ans += m[v];
        }
        return ans;
    }
};