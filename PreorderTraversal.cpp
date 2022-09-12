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
    vector<int> preorderTraversal(TreeNode* root) {
        // Preorder: root, left, right
        // Perhaps use a stack, every time you reach new node you add to array,
        // go left first, then right
        vector<int> order;
        stack<TreeNode*> deku;
        if (!root) return order;
        
        TreeNode* visited = root;
        TreeNode* current = root;
        order.push_back(root->val);
        deku.push(current);
        
        while(!deku.empty()){
            cout << current->val << endl;
            if (current->left && current->left != visited && current->right != visited){
                visited = current;
                current = current->left;
                deku.push(current);
                order.push_back(current->val);
            }
            else if ((current->left == visited || !(current->left)) 
                     && (current->right && current->right != visited)){
                visited = current;
                current = current->right;
                deku.push(current);
                order.push_back(current->val);
            }
            else {
                visited = current;
                deku.pop();
                if (!deku.empty()) current = deku.top();
            }
        }
        return order;
        
        /* More optimized and baller solution:
        
        class Solution {
        public:
            vector<int> preorderTraversal(TreeNode* root) {
                vector<int> res;
                stack<TreeNode*> stk;
                while (root) {
                    res.push_back(root->val);
                    if (root->right) stk.push(root->right);
                    if (root->left) stk.push(root->left);
                    if (stk.empty()) break;
                    root = stk.top();
                    stk.pop();
                }
                return res;
            }
        };
        
        */
    }
};