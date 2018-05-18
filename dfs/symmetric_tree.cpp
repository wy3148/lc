// https: //leetcode.com/problems/symmetric-tree/description/
// two ways, recursive and iterative


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        if (root == NULL) return true;
        
        std:queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        
        //using queue is more like bfs in fact.
        while(!q.empty()){
            TreeNode* t1 = q.front(); q.pop();
            TreeNode* t2 = q.front(); q.pop();
            
            if (t1 == NULL && t2 == NULL) continue;
            
            if (t1 == NULL || t2 == NULL) return false;
            
            if (t1->val != t2->val ) return false;
            
            q.push(t1->left);
            q.push(t2->right);
            
            q.push(t1->right);
            q.push(t2->left);            
        }
        return true;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
    bool isEqual(TreeNode *left, TreeNode *right)
    {

        if (left == NULL && right == NULL)
            return true;

        if (left != NULL && right == NULL ||
            left == NULL && right != NULL)
            return false;

        if (left->val != right->val)
            return false;

        return isEqual(left->left, right->right) && isEqual(left->right, right->left);
    }

    bool isSymmetric(TreeNode *root)
    {

        if (!root)return true;
        
        return isEqual(root->left, root->right);
    }
};