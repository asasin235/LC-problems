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
    vector<string> res;
	void solve(TreeNode *root,string cur){
		if(!root) return;
		cur+=to_string(root->val);
		if(!root->left and !root->right){
			res.push_back(cur);
			return;
		}
		cur+="->";
		solve(root->left,cur);
		solve(root->right,cur);
		return;
	}
	vector<string> binaryTreePaths(TreeNode* root) {
		string cur;
		solve(root,cur);
		return res;
	}
};