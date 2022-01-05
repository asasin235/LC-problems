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
    vector<vector<int>> possiblePath;
    void helper(TreeNode * root,vector<int> ans){
        if(!root)
            return ;
         ans.push_back(root->val);
        if(!root->left and !root->right){
           possiblePath.push_back(ans);
            return ;
        }
        helper(root->left,ans);
        helper(root->right,ans);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> ans;
        helper(root,ans);
        vector<vector<int>> answer;
        for(auto i :possiblePath){
            if(accumulate(i.begin(),i.end(),0)==targetSum)
                answer.push_back(i);
        }
        return answer;
        
    }
};