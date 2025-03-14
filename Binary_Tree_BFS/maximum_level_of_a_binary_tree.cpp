// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75

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
    void helper(TreeNode *root, int level, map<int, int> &m)
    {
        if (!root)
            return;

        if (m.find(level) == m.end())
            m[level] = root->val;
        else
            m[level] += root->val;

        helper(root->left, level + 1, m);
        helper(root->right, level + 1, m);
    }

    int maxLevelSum(TreeNode *root)
    {
        map<int, int> m;
        helper(root, 1, m);
        int curr = INT_MIN;
        int index = -1;

        for (auto [f, s] : m)
        {
            if (s > curr)
            {
                curr = s;
                index = f;
            }
        }
        return index;
    }
};