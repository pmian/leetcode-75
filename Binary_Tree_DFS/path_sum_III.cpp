// https://leetcode.com/problems/path-sum-iii/description/?envType=study-plan-v2&envId=leetcode-75

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
    int pathSum(TreeNode *root, int targetSum)
    {
        unordered_map<long long, int> prefixSumCount;
        prefixSumCount[0] = 1; // Base case: A sum of zero before starting
        return dfs(root, 0, targetSum, prefixSumCount);
    }

private:
    int dfs(TreeNode *node, long long currentSum, int targetSum, unordered_map<long long, int> &prefixSumCount)
    {
        if (!node)
            return 0;

        currentSum += node->val;
        int count = prefixSumCount[currentSum - targetSum]; // Check if there's a valid prefix sum

        prefixSumCount[currentSum]++; // Store the current sum

        count += dfs(node->left, currentSum, targetSum, prefixSumCount);
        count += dfs(node->right, currentSum, targetSum, prefixSumCount);

        prefixSumCount[currentSum]--; // Remove current sum before returning (backtracking)

        return count;
    }
};