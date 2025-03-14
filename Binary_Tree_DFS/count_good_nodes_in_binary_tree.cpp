// https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75

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
    int helper(int num, TreeNode *root)
    {
        if (!root)
            return 0;
        int ans = 0;

        if (root->val >= num)
        {
            ans += 1;
            num = root->val;
        }

        ans += helper(num, root->left);
        ans += helper(num, root->right);

        return ans;
    }

    int goodNodes(TreeNode *root)
    {
        int ans = helper(INT_MIN, root);
        return ans;
    }
};