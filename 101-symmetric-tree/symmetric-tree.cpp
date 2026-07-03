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
    bool ans(TreeNode * t1 , TreeNode * t2 ){
        if(t1==NULL || t2 == NULL){
            return (t1==t2);
        }

        return t1->val == t2->val &&
        ans(t1->left , t2->right) &&
        ans (t1->right, t2->left);
    }
    bool isSymmetric(TreeNode* root) {

        TreeNode * t1 = root ;
        TreeNode * t2 = root ;

        return ans(t1,t2);
        
    }
};