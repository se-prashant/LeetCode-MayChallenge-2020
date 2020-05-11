//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3322/

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
    bool equalDepth(TreeNode* root, int x, int y){
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        int start =-1;
        int end = -1;
        bool notAccess = false;
        bool flag1= true;
        bool flag2 = true;
        bool flag = false;
        while(q.empty()==false){
            int c = q.size();
            count++;
            for(int i=0;i<c;i++){
                TreeNode *cur = q.front();
                q.pop();
                if(cur->val==x){
                    start = count;
                }
                if(cur->val==y)
                    end = count;
                if(notAccess == false && start!=-1 && end!=-1){
                    if(start!=end)
                       flag1 = false;
                    notAccess = true;
                }
                if(cur->left){
                    if(cur->left->val==x || cur->left->val==y)
                        flag = true;
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                    if(flag==true){     
                        if(cur->right->val==x || cur->right->val==y)
                          flag2 = false;
                    }else
                        flag = false;
                    
                }
                flag = false;
            }
        }
        //cout<<start<<" "<<end<<" "<<flag1<<" "<<flag2; 
        return flag1&&flag2;
    }
  
    bool isCousins(TreeNode* root, int x, int y) {
        if(equalDepth(root,x,y)){   
            return true;
        }
        return false;
    }
};
