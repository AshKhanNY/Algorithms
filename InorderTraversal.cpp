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
    vector<int> inorderTraversal(TreeNode* root) {
        // Premise is to continue to go left until you cannot, then
        // take the root value and proceed right
        vector<int> order;
        stack<TreeNode*> deku;
        TreeNode* temp;
        
        while (root || !deku.empty()){
            while (root){
                deku.push(root);
                root = root->left;
            }
            temp = deku.top();
            deku.pop();
            order.push_back(temp->val);
            if (temp->right) root = temp->right;
        }
        return order;
    }
};