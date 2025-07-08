/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
 
  int height(Node* root){
      if(root == NULL) return 0;
      
      int l = height(root->left);
      int r = height(root->right);
      
      return max(l , r) + 1;
      
  }


bool checkUtil(Node* root, int level, int heightTree){
    if(root == NULL) return true;
    
    if(!root->left && !root->right) {
        if (level == heightTree - 1){
            return true;
        }
        else{
            return false;
        }
    }
    
    return checkUtil(root->left, level+1, heightTree) && checkUtil(root->right, level+1, heightTree);

}
    bool check(Node *root) {
        int heightTree = height(root);
        return checkUtil(root, 0, heightTree);
    }
};