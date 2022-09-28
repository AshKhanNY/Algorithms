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
    vector<int> postorderTraversal(TreeNode* root) {
        // Postorder traversal goes left->right->root
        vector<int> res;
        stack<TreeNode*> deku;
        TreeNode* temp;
        TreeNode* prev;
        
        while (root || !deku.empty()){
            while (root){
                deku.push(root);
                root = root->left;
            }
            temp = deku.top();
            if (temp->right && temp->right != prev) root = temp->right;
            if (!root){
                prev = temp;
                res.push_back(temp->val);
                deku.pop();
            }
        }
        
        return res;
    }
};