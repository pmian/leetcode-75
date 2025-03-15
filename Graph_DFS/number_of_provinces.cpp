// https://leetcode.com/problems/number-of-provinces/description/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    //     void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int city) {
    //     visited[city] = true;  // Mark the city as visited

    //     for (int j = 0; j < isConnected.size(); j++) {
    //         if (isConnected[city][j] == 1 && !visited[j]) {
    //             dfs(isConnected, visited, j);  // Visit all connected cities
    //         }
    //     }
    // }

    // int findCircleNum(vector<vector<int>>& isConnected) {
    //     int n = isConnected.size();
    //     vector<bool> visited(n, false);
    //     int provinces = 0;

    //     for (int i = 0; i < n; i++) {
    //         if (!visited[i]) {
    //             dfs(isConnected, visited, i);  // Start a new DFS for each unvisited city
    //             provinces++;  // This DFS call represents one province
    //         }
    //     }

    //     return provinces;
    // }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty())
                {
                    int city = q.front();
                    q.pop();

                    for (int j = 0; j < n; j++)
                    {
                        if (isConnected[city][j] == 1 && !visited[j])
                        {
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                }

                provinces++; // Each BFS traversal covers one province
            }
        }

        return provinces;
    }
};