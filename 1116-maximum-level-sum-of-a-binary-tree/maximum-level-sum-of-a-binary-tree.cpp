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
    int maxLevelSum(TreeNode* root) {

        int level = 1 ;
        int sum = INT_MIN ;
        int l =0 ;

        queue<TreeNode *> q ;
        q.push(root);

        while(!q.empty()){
;
            int s = 0 ;
            int n = q.size();

            for(int i = 0 ; i<n ; i++){
                TreeNode * temp = q.front();
                q.pop();
                s+=(temp->val);

                if(temp->left){
                    q.push(temp->left);
                }

                if(temp->right){
                    q.push(temp->right);
                }
            }
            l+=1;
            if(s>sum){
                sum=s;
                level = l;
            }
            
        }

        return level;
        
    }
};