// https://leetcode.com/problems/evaluate-division/submissions/1572212319/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    // DFS function to find the path value from `start` to `end`
    double dfs(string start, string end, unordered_set<string> &visited)
    {
        // If the start variable is not in the graph, return -1
        if (graph.find(start) == graph.end())
            return -1.0;

        // If the start and end are the same, return 1.0
        if (start == end)
            return 1.0;

        visited.insert(start); // Mark as visited

        for (auto &neighbor : graph[start])
        {
            string nextNode = neighbor.first;
            double weight = neighbor.second;

            if (visited.find(nextNode) == visited.end())
            {
                double product = dfs(nextNode, end, visited);
                if (product != -1.0)
                    return product * weight;
            }
        }
        return -1.0;
    }

    // Function to calculate equations
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        // Step 1: Build the Graph
        for (int i = 0; i < equations.size(); i++)
        {
            string A = equations[i][0], B = equations[i][1];
            double value = values[i];

            graph[A].push_back({B, value});       // A → B with weight `value`
            graph[B].push_back({A, 1.0 / value}); // B → A with weight `1 / value`
        }

        // Step 2: Process Queries
        vector<double> results;
        for (auto &query : queries)
        {
            string C = query[0], D = query[1];
            unordered_set<string> visited;

            if (graph.find(C) == graph.end() || graph.find(D) == graph.end())
            {
                results.push_back(-1.0); // If C or D is missing, return -1
            }
            else
            {
                results.push_back(dfs(C, D, visited));
            }
        }
        return results;
    }
};