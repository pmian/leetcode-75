// https://leetcode.com/problems/combination-sum-iii/submissions/1562711706/?envType=study-plan-v2&envId=leetcode-75

class Solution
{
public:
    void findCombinations(int k, int n, int start, vector<int> &path, vector<vector<int>> &result)
    {
        if (k == 0 && n == 0)
        {
            result.push_back(path);
            return;
        }
        if (k == 0 || n <= 0)
            return;

        for (int i = start; i <= 9; ++i)
        {
            path.push_back(i);
            findCombinations(k - 1, n - i, i + 1, path, result);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> result;
        vector<int> path;
        findCombinations(k, n, 1, path, result);
        return result;
    }
};