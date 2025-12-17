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
    int f(TreeNode*g_par,TreeNode*par,TreeNode*root){
        if(!root){
            return 0;
        }
        int node_val=0;
        if(g_par && g_par->val%2==0){
            node_val=root->val;
        }
        return f(par,root,root->left)+f(par,root,root->right)+node_val;
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        return f(NULL , NULL , root);
    }
};