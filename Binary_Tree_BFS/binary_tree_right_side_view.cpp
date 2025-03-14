// https://leetcode.com/problems/binary-tree-right-side-view/description/?envType=study-plan-v2&envId=leetcode-75

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
    void helper(TreeNode *root, int d, vector<int> &ans)
    {
        if (!root)
            return;
        if (d == ans.size())
            ans.push_back(root->val);
        helper(root->right, d + 1, ans);
        helper(root->left, d + 1, ans);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        helper(root, 0, ans);
        return ans;
    }
};