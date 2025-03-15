// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+'; // Mark entrance as visited

        int steps = 0;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // Right, Down, Left, Up

        while (!q.empty())
        {
            int size = q.size();
            steps++; // Increase step count for this BFS level

            for (int i = 0; i < size; i++)
            {
                auto [r, c] = q.front();
                q.pop();

                // Try moving in all 4 directions
                for (auto &dir : directions)
                {
                    int nr = r + dir[0], nc = c + dir[1];

                    // Check if the move is valid
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && maze[nr][nc] == '.')
                    {
                        // Check if this is an exit (border cell, not the entrance)
                        if (nr == 0 || nr == m - 1 || nc == 0 || nc == n - 1)
                        {
                            return steps;
                        }

                        // Mark as visited and add to queue
                        maze[nr][nc] = '+';
                        q.push({nr, nc});
                    }
                }
            }
        }

        return -1; // No exit found
    }
};