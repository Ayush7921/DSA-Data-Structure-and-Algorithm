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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int , map<int , vector<int>>>mp;
        queue<pair<TreeNode * , pair<int, int>>> q;
        vector<vector<int> >ans ;
        
        if(root == NULL){
            return ans ;
        }
        
        q.push({root, {0,0}});
        
        
        while(!q.empty()){
            
            TreeNode * temp = q.front().first;
            int hd = q.front().second.first;
            int lvl = q.front().second.second;
            q.pop();
            
            mp[hd][lvl].push_back(temp->val);
            
            if(temp->left){
                q.push({temp->left,{hd-1,lvl+1}});
            }
            
            if(temp->right){
                q.push({temp->right,{hd+1,lvl+1}});
            }
        }
        
        for(auto &i : mp){

            vector<int> col;

            for(auto &j : i.second){
                sort(j.second.begin(), j.second.end());
                for(auto k : j.second){
                    col.push_back(k);
                }
            }
            ans.push_back(col);
        }
        
        return ans;
    }
};