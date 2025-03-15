// https://leetcode.com/problems/rotting-oranges/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Count fresh oranges and add rotten ones to queue
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }

        if (fresh == 0)
            return 0;

        int time = 0;
        while (!q.empty())
        {
            int size = q.size();
            time++;
            for (int k = 0; k < size; k++)
            {
                auto [i, j] = q.front();
                q.pop();

                for (auto &dir : dirs)
                {
                    int x = i + dir[0];
                    int y = j + dir[1];

                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1)
                    {
                        grid[x][y] = 2; // Mark as rotten
                        fresh--;
                        q.push({x, y});
                    }
                }
            }
        }

        return fresh == 0 ? time - 1 : -1;
    }
};