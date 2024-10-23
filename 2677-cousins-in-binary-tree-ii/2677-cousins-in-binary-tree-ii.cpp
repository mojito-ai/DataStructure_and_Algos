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
    TreeNode* replaceValueInTree(TreeNode* root) {

        if(!root) return root;

        queue<TreeNode*> q;
        q.push(root);
        vector<int> levelSums;

        // Intution: Sum of cousins = Sum of level - Sum of siblings
        // BFS: Calculating Level Sum of the nodes in the level
        while(!q.empty()) {
            int levelSum = 0;
            int n = q.size();
            
            while (n--) {
                TreeNode* curr = q.front();
                q.pop();

                levelSum += curr->val;
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            levelSums.push_back(levelSum);
        }

        // Second BFS: Update each node's value to sum of its cousins
        q.push(root);
        int levelIndex = 1; // Because we are calculating for one layer down.
        root->val = 0;  // Root has no cousins

        while(!q.empty()) {
            int n = q.size();
            
            while (n--) {
                TreeNode* curr = q.front();
                q.pop();

                int siblingSum = (curr->left ? curr->left->val : 0) + (curr->right ? curr->right->val : 0);

                if (curr->left) {
                    curr->left->val = levelSums[levelIndex] - siblingSum;
                    q.push(curr->left);
                }

                if (curr->right) {
                    curr->right->val = levelSums[levelIndex] - siblingSum;
                    q.push(curr->right);
                }
            }

            levelIndex++;
        }

        return root;
    }

    TreeNode* replaceValueInTreeBruteForce(TreeNode* root) {
        unordered_map<TreeNode*, int> hashmapChildSum; // parent node, sum
        unordered_map<TreeNode*, TreeNode*> hashmapParent; // child node, parent node
        queue<TreeNode*> q;
        q.push(root);
        root->val = 0;

        // Intution: Sum of cousins = Sum of level - Sum of siblings
        while(!q.empty()) {
            int n = q.size(); 

            // bfs
            while (n--) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left != nullptr) {
                    q.push(curr->left);
                    hashmapParent[curr->left] = curr;
                    hashmapChildSum[curr]+=curr->left->val;
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                    hashmapParent[curr->right] = curr;
                    hashmapChildSum[curr]+=curr->right->val;
                }
            }

            queue<TreeNode*> q_copy = q;

            n = q.size();
            while (n--) {
                unordered_set<TreeNode*> visited;
                TreeNode* curr = q.front();
                curr->val = 0;

                int x = q_copy.size();
                while (x--) {
                    TreeNode *frontElement = q_copy.front();
                    if (visited.find(hashmapParent[frontElement]) == visited.end() && hashmapParent[curr] != hashmapParent[frontElement]) {
                        curr->val += hashmapChildSum[hashmapParent[frontElement]];
                        visited.insert(hashmapParent[frontElement]);
                    }
                    q_copy.pop();
                    q_copy.push(frontElement);
                }
                q.pop(); // Remove it
                q.push(curr);  // Add it back at the end of the queue
            }
        }
        return root;
    }
};