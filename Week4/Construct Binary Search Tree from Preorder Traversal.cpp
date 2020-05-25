//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3339/
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
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int size = pre.size();
           stack<TreeNode*> stk;
           TreeNode* root = new TreeNode( pre[0] );
           stk.push(root);
           int i;
           TreeNode* temp;
           for ( i = 1; i < size; ++i ) {
              temp = NULL;
              while ( !stk.empty() && pre[i] > stk.top()->val ) {
                 temp = stk.top();
                 stk.pop();
              }
              if ( temp != NULL) {
                 temp->right = new TreeNode( pre[i] );
                 stk.push(temp->right);
              } else {
                 TreeNode* peek_node = stk.top();
                 peek_node->left = new TreeNode( pre[i] );
                 stk.push(stk.top()->left);
              }
           }
            return root;

        
    }
};
