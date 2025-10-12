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
    int f(TreeNode* root,int maxi){
        if(!root){
            return 0;
        }
        int ans=0;
        if(root->val>=maxi){
            maxi=root->val;
            ans++;
        }
        return ans+f(root->left,maxi)+f(root->right,maxi);
    }
public:
    int goodNodes(TreeNode* root) {
        return f(root,root->val);
    }
};