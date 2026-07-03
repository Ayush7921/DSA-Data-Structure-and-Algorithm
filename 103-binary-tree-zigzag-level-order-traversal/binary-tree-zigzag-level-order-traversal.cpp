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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){return {};}
        queue<TreeNode * > q;
        q.push(root);

        int i = 0;
        vector<vector<int>> ans;
    

        while(!q.empty()){
            int n = q.size();
            vector<int> level ;

            for(int i =0 ; i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                level.push_back(temp->val);

                if(temp->left ){q.push(temp->left);}
                if(temp->right){q.push(temp->right);}

            }
            if(i%2!=0){
                reverse(level.begin(), level.end());
            }

            ans.push_back(level);
            i++;

        }
         return ans ;
    }
};