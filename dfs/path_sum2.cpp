//https://leetcode.com/problems/path-sum-ii/description/
//

class Solution
{
  public:
    vector<vector<int>> all;

    void path(vector<int> p, TreeNode *root, int sum)
    {
        if (root == NULL)
            return;
        p.push_back(root->val);

        if (root->left == NULL && root->right == NULL)
        {
            int tmp = 0;
            for (auto v : p)
            {
                tmp += v;
            }

            if (tmp == sum)
            {
                all.push_back(p);
            }
        }

        path(p, root->left, sum);
        path(p, root->right, sum);
    }

    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<int> t;
        path(t, root, sum);
        return all;
    }
};


// dont copy vector to get all paths from root to leaf

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
    void dfs(vector<vector<int>> &res, vector<int> &cur, TreeNode *root, int sum)
    {
        if (!root)
            return;

        cur.push_back(root->val);

        //reach leaf
        if (root->left == NULL && root->right == NULL)
        {

            int tmp = 0;
            for (auto v : cur)
            {
                tmp += v;
            }

            if (tmp == sum)
            {
                res.push_back(cur);
            }
        }

        dfs(res, cur, root->left, sum);
        dfs(res, cur, root->right, sum);

        //dfs,backward
        cur.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(res, cur, root, sum);
        return res;
    }
};
