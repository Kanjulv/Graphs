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
class Solution {
public:

    void leafSimilarHelper(TreeNode* root, vector<int> &leafNodes)
    {
        if(root == NULL)
        {
            return;
        }

        if(root->left == NULL && root->right == NULL)
        {
            leafNodes.push_back(root->val);
            return;
        }

        leafSimilarHelper(root->left, leafNodes);
        leafSimilarHelper(root->right, leafNodes);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        vector<int> root1leaves;
        vector<int> root2leaves;

        leafSimilarHelper(root1, root1leaves);
        leafSimilarHelper(root2, root2leaves);

            if(root1leaves.size() != root2leaves.size())
            {
                return false;
            }

            for (int i = 0; i < root1leaves.size(); ++i) {
                if (root1leaves[i] != root2leaves[i]) {
                return false;
            }
            }
            return true;
            }
            };