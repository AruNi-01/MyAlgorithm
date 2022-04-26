/*
 * @Descripttion: 104. 二叉树的最大深度
 * @Author: AruNi
 * @Date: 2022-04-26 23:09:10
 */

/*
题目：
给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，
    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。
*/

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

/*
递归法：
可以使用前序（中左右），也可以使用后序遍历（左右中），使用前序求的就是深度，使用后序求的是高度。
而根节点的高度就是二叉树的最大深度，所以本题中可以通过后序求的根节点高度来求的二叉树最大深度。
*/
class Solution {
public:
    int getDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        return 1 + max(leftDepth, rightDepth);
    }

    int maxDepth(TreeNode* root) {
        return getDepth(root);
    }
};

// 递归法：前序遍历；这才是真正求深度的逻辑
class Solution {
public:
    int result;     // 定义一个全局变量，存放最后的深度
    void getDepth(TreeNode* node, int depth) {
        // 将当前深度和原来记录的最大深度作比较，取最大值
        result = depth > result ? depth : result;       // 中

        // 左右节点都为空，直接返回
        if (node->left == NULL && node->right == NULL) return ;

        if (node->left) {       // 左
            depth++;
            getDepth(node->left, depth);
            // 回溯，递归到最底层后，结束了最后一层的递归方法，要往回走到上一层，深度要-1
            depth--;
        }
        if (node->right) {      // 右
            depth++;
            getDepth(node->right, depth);
            depth--;        //回溯
        }
        return ;
    }

    int maxDepth(TreeNode* root) {
        result = 0;
        if (root == NULL) return result;
        getDepth(root, 1);  // 头结点的深度为 1
        return result;
    }
};

/*
迭代法：
使用迭代法的话，使用层序遍历是最为合适的，因为最大的深度就是二叉树的层数，和层序遍历的方式极其吻合。
在二叉树中，一层一层的来遍历二叉树，记录一下遍历的层数就是二叉树的深度。
所以这道题的迭代法就是一道模板题，可以使用二叉树层序遍历的模板来解决的。
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int depth = 0;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            depth++;    // 记录深度
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return depth;
    }
};