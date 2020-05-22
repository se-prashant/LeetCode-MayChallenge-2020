//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3335/
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
    int ans = -1;
    int count = 0;
public:
    void findElement(TreeNode* root,int k){ 
        if(ans!=-1)
            return;
        if(root==NULL)
            return;
        if(root->left){
          findElement(root->left,k);    
            
        }
        count++;
        if(count==k){
          ans = root->val; 
        }
        if(root->right)
        {   
          findElement(root->right,k);
           
        }     
    }
    
    int kthSmallest(TreeNode* root, int k) {
        findElement(root,k);
        return(ans);
    }
};
