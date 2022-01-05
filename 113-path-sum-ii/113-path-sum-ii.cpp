class Solution {
public:
    
    void findPath(TreeNode *root, int sum, int target , vector<vector<int>> &res, vector<int> &temp){
        
        if(!root) return;
        
        temp.push_back(root->val);
        sum += root->val;
        
        if(root->left==NULL and root->right==NULL and target==sum){
            res.push_back(temp);
        }
        
        findPath(root->left,sum,target,res,temp);
        findPath(root->right,sum,target,res,temp);
        
        temp.pop_back();
        sum -= root->val;
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        
        vector<vector<int>>res;
        vector<int>temp;
        findPath(root,0,target,res,temp);
        return res;
    }
};