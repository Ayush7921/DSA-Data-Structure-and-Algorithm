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
    pair<int , int> dia(TreeNode * root){

        if(root==NULL){
            return {0,0};
        }
        
        pair<int , int> left = dia(root->left);
        pair<int , int > right = dia (root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second +1;

        pair<int, int> p;
        p.first = max(op1,max(op2,op3));
        p.second = max(left.second , right.second) + 1 ;

        return p;


    }
    int diameterOfBinaryTree(TreeNode* root) {
        return dia(root).first -1;
    }
};