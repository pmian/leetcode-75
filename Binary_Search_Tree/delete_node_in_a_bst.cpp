// https://leetcode.com/problems/delete-node-in-a-bst/description/?envType=study-plan-v2&envId=leetcode-75

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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // Base case: if tree is empty
        if (root == NULL)
        {
            return NULL;
        }

        // Recursively search for the node to delete
        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            // Node with key found - perform deletion

            // Case 1: No child or only one child
            if (root->left == NULL)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }

            // Case 2: Node with two children
            // Get the inorder successor (smallest in right subtree)
            TreeNode *temp = minValueNode(root->right);

            // Copy the inorder successor's value to this node
            root->val = temp->val;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }

private:
    TreeNode *minValueNode(TreeNode *node)
    {
        TreeNode *current = node;
        // Find the leftmost leaf
        while (current && current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }
};