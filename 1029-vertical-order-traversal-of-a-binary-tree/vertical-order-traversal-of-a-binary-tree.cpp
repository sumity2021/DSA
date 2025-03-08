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
    void f(TreeNode*root,int row,int col,map<int,vector<pair<int,int>>>&ans ){
        if(!root) return ;
        ans[col].push_back({row,root->val});
        f(root->left,row+1,col-1,ans);
        f(root->right,row+1,col+1,ans);

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>>m;
        f(root,0,0,m);
        vector<vector<int>>ans;
        for(auto [key,vec] : m){
            int n=vec.size();
            sort(vec.begin(),vec.end());
            vector<int>temp;
            for(auto x : vec){
                temp.push_back(x.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};