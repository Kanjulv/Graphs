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

pair<bool, int> helper(TreeNode* root)
{
    if(root == NULL) return {true, 0};

    pair<bool, int> leftHeight = helper(root->left);
    pair<bool, int> rightHeight = helper(root->right);

    bool isleft = leftHeight.first;
    bool isRight = rightHeight.first;

    int leftH = leftHeight.second;
    int rightH = rightHeight.second;
    int diff = abs(leftH - rightH);

    bool check = false;

    if(isleft && isRight && diff <= 1)
    {
        check = true;
    }

    return{check, (1 + max(leftH , rightH))};
}

    bool isBalanced(TreeNode* root) {
      pair<bool, int> ans =  helper(root);
      return ans.first;
    }
};