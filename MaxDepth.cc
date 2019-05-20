/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * 
 */
class Solution {
public:
    int maxDepth(struct TreeNode* root){
        if(!root)
          return 0;
        else{
            int l,r;
            l = maxDepth(root->left); // this.left
            r = maxDepth(root->right); // this.right
            return 1+(l>r?l:r);
        }
    }
};
