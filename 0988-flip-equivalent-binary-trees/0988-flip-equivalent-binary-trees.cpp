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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {

        if (root1 == nullptr && root2 == nullptr) return true;
        else if (root1 != nullptr && root2 == nullptr) return false;
        else if (root1 == nullptr && root2 != nullptr) return false;

        // Intuition: Perform BFS on both simultaneously. 
        // Each layer should have the same value elements along with the same value parent
        queue<pair<TreeNode*, TreeNode*>> q1, q2;
        q1.push({root1, new TreeNode()}); 
        q2.push({root2, new TreeNode()});

        while(!q1.empty()) {
            int n = q1.size();

            if(!areQueuesEqual(q1, q2)){
                return false;
            }

            while(n--) {
                TreeNode* curr1 = q1.front().first;
                q1.pop();
                TreeNode* curr2 = q2.front().first;
                q2.pop();

                if (curr1->left) q1.push({curr1->left, curr1});
                if (curr1->right) q1.push({curr1->right, curr1});
                if (curr2->left) q2.push({curr2->left, curr2});
                if (curr2->right) q2.push({curr2->right, curr2});
            }
        }

        return true;
    }

    bool areQueuesEqual(queue<pair<TreeNode*, TreeNode*>>& q1, queue<pair<TreeNode*, TreeNode*>>& q2) {
        if (q1.size() != q2.size()) {
            return false;  // If sizes are different, they can't be equal
        }

        bool result = true;  // Track whether all elements are in the second queue
        set<pair<int, int>> elementsInQueue2;  // A set to store values of q2

        // Step 1: Insert elements of q2 into a set (and restore q2)
        int q2_size = q2.size();
        for (int i = 0; i < q2_size; i++) {
            pair<TreeNode*,TreeNode*> element = q2.front();
            elementsInQueue2.insert({element.first->val, element.second->val});
            q2.pop();        // Remove from front
            q2.push(element); // Add it back to the end
        }

        // Step 2: Check q1 elements against the set (and restore q1)
        int q1_size = q1.size();
        for (int i = 0; i < q1_size; i++) {
            pair<TreeNode*,TreeNode*> element = q1.front();
            if (elementsInQueue2.find({element.first->val, element.second->val}) == elementsInQueue2.end()) {
                result = false;  // Element from q1 not found in q2
            }
            q1.pop();        // Remove from front
            q1.push(element); // Add it back to the end
        }

        return result;
    }
};