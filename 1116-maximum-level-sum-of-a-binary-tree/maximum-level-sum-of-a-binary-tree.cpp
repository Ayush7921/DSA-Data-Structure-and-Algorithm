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
            //Time: O(n) (each node is visited exactly once)Space: O(w), where w is the maximum width of the tree. Worst case: O(n)
        queue<TreeNode*> q;
        q.push(root);

        int level = 1;
        int answer = 1;
        int maxSum = INT_MIN;

        while (!q.empty()) {
            int size = q.size();
            int levelSum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                levelSum += curr->val;

                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }

            if (levelSum > maxSum) {
                maxSum = levelSum;
                answer = level;
            }

            level++;
        }

        return answer;
    }
};