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
    void helper(TreeNode * root,string num,vector<string> & numbers){
        if(!root)
            return ;
        num.push_back((root->val)+'0');
        if(!root->left and !root->right){
            numbers.push_back(num);
            return ;
        }
        helper(root->left,num,numbers);
        helper(root->right,num,numbers);
        
    }
    int sumNumbers(TreeNode* root) {
        string num;
        vector<string> numbers;
        helper(root,num,numbers);
        int sum=0;
        for(string number : numbers){
            int n=stoi(number);
            sum+=n;
            
        }
        return sum;
    }
};