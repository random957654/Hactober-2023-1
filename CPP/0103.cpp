class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        stack<TreeNode*> currentLevel;
        stack<TreeNode*> nextLevel;
        bool leftToRight = true;
        currentLevel.push(root);

        while (!currentLevel.empty()) {
            vector<int> levelValues;
            while (!currentLevel.empty()) {
                TreeNode* node = currentLevel.top();
                currentLevel.pop();
                levelValues.push_back(node->val);

                if (leftToRight) {
                    if (node->left) nextLevel.push(node->left);
                    if (node->right) nextLevel.push(node->right);
                } else {
                    if (node->right) nextLevel.push(node->right);
                    if (node->left) nextLevel.push(node->left);
                }
            }

            result.push_back(levelValues);
            swap(currentLevel, nextLevel);
            leftToRight = !leftToRight;
        }

        return result;
    }
};
