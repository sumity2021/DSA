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
class FindElements {
    unordered_set<int>m;
public:
    void dfs(unordered_set<int>&m , TreeNode*root,int x){
        if(!root){
            return;
        }
        root->val=x;
        m.insert(x);
        dfs(m,root->left,2*x+1);
        dfs(m,root->right,2*x+2);
    }
    FindElements(TreeNode* root) {
        dfs(m,root,0);
    }
    
    bool find(int target) {
        return m.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */