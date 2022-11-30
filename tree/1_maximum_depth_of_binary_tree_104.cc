#include "binary_tree.h"

class Solution1 {
public:
    int depth = 0, res = 0;

    int maxDepth(TreeNode* root) {
        traverse(root);
        return res;
    }

    void traverse(TreeNode* root) {
        if (nullptr == root) return;

        ++depth;
        if (nullptr == root->left && nullptr == root->right) {
            res = max(res, depth);
        }
        if (root->left) traverse(root->left);
        if (root->right) traverse(root->right);
        --depth;
        return;
    }
};

class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if (nullptr == root) return 0;
        int res = max(maxDepth(root->left), maxDepth(root->right)) + 1;
        return res;
    }
};

class Solution3 {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> que;
        que.push(root);
        int ans = 0;
        while (!que.empty()) {
            int sz = que.size();
            while (sz > 0) {
                TreeNode *cur = que.front();
                que.pop();
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
                --sz;
            }
            ++ans;
        }
        return ans;
    }
};
