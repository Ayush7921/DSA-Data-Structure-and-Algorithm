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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){return {};}
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>> ans ;

        ans.push_back({});
        int i =0;
        while(!q.empty()){

            TreeNode * temp = q.front();
            q.pop();
            if(temp==NULL){
                
                if(!q.empty()){
                    ans.push_back({});   // next level
                    i++;
                    q.push(NULL);
                }
            }
            else {
            ans[i].push_back(temp->val);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            
            }
        }

        return ans ;
    }
};