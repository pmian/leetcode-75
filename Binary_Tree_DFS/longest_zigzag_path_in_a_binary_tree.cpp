// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/submissions/1564400960/?envType=study-plan-v2&envId=leetcode-75

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
    void helper(bool left, bool right, int curr, int &ans, TreeNode *root)
    {

        ans = max(ans, curr);

        if (root->left)
        {

            if (left)
            {
                helper(true, false, 1, ans, root->left);
            }
            else
            {
                helper(true, false, curr + 1, ans, root->left);
            }
        }

        if (root->right)
        {
            if (right)
            {
                helper(false, true, 1, ans, root->right);
            }
            else
            {
                helper(false, true, curr + 1, ans, root->right);
            }
        }
    }

    int longestZigZag(TreeNode *root)
    {
        int ans = 0;
        helper(false, false, 0, ans, root);
        return ans;
    }
};