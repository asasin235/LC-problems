class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1&&root2)
        {
            root1->val+=root2->val; //If both roots exist add their values
            root1->left=mergeTrees(root1->left,root2->left); //Add left child to root1 if root2 exists and root1 doesn't
            root1->right=mergeTrees(root1->right,root2->right);//Same for right child
        }
		//Don't do anything if root1 exists and root2 doesn't. Root1 NULL if both are NULL;

        else if(root2&&root1==NULL)
        {
            return root2;
        }
        return root1; //root1 is our solution tree
    }
};