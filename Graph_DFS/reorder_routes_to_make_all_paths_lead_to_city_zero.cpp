// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        unordered_map<int, vector<int>> graph;
        unordered_set<string> directedEdges;

        // Build the graph and store directed edges
        for (auto &conn : connections)
        {
            int u = conn[0], v = conn[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            directedEdges.insert(to_string(u) + "," + to_string(v)); // Mark the edge direction
        }

        int changes = 0;
        vector<bool> visited(n, false);

        // DFS traversal
        function<void(int)> dfs = [&](int node)
        {
            visited[node] = true;
            for (int neighbor : graph[node])
            {
                if (!visited[neighbor])
                {
                    // Check if we need to reverse the edge
                    if (directedEdges.count(to_string(node) + "," + to_string(neighbor)))
                    {
                        changes++;
                    }
                    dfs(neighbor);
                }
            }
        };

        dfs(0);
        return changes;
    }
};