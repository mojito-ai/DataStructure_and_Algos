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
    vector<long long> sumLevel;  // Vector to store sum of each level

    long long kthLargestLevelSum(TreeNode* root, int k) {
        //traversal(root, 0);
        bfs(root);

        // Sort sums in descending order to find the k-th largest
        sort(sumLevel.begin(), sumLevel.end(), greater<long long>());

        // If k is within bounds, return the k-th largest sum
        if (k <= sumLevel.size()) {
            return sumLevel[k-1];
        }

        return -1;  // Return an invalid value if k is out of bounds
    }

private: 

    void bfs(TreeNode *root) {
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            long long sum = 0;

            while (n--) {
                TreeNode *node = q.front(); 
                q.pop();

                sum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            sumLevel.push_back(sum);
        }
    }

    void traversal(TreeNode *root, int depth) {
        if (root == nullptr) return;

        // If the current depth exceeds the size of sumLevel, expand it
        if (depth >= sumLevel.size()) {
            sumLevel.push_back(0);
        }

        // Add the current node's value to the corresponding level sum
        sumLevel[depth] += root->val;

        // Recursively traverse left and right subtrees
        traversal(root->left, depth+1);
        traversal(root->right, depth+1);
    }
};