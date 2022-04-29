/*
 * @Descripttion: 513. 找树左下角的值
 * @Author: AruNi
 * @Date: 2022-04-29 20:19:46
 */

/*
题目：
给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
假设二叉树中至少有一个节点。

示例 1:
输入: root = [2,1,3]
输出: 1

示例 2:
输入: [1,2,3,4,null,5,6,null,null,7]
输出: 7
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

// 本题使用层序遍历再合适不过了，比递归要好理解的多
// 只需要记录最后一行第一个节点的数值就可以了。
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        int result = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (i == 0) result = node->val;      // 记录最后一行第一个元素
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return result;
    }
};

// 递归法：
class Solution {
public:
    int maxLen = INT_MIN;   // 全局变量，记录整颗树的最大深度
    int maxleftValue;       // 全局变量，最大深度 最左节点的数值
    
    // leftLen：记录该子树的最大深度
    void traversal(TreeNode* root, int leftLen) {
        // 当遇到叶子节点的时候，就需要统计一下最大的深度了
        if (root->left == NULL && root->right == NULL) {
            if (leftLen > maxLen) {
                maxLen = leftLen;   // 更新最大深度
                maxleftValue = root->val;   // 最大深度最左边的数值
            }
            return ;
        }

        if (root->left) {        // 左
            leftLen++;      // 深度加一
            traversal(root->left, leftLen);
            leftLen--;      // 回溯，深度减一
        }
        if (root->right) {      // 右
            leftLen++;      // 深度加一
            traversal(root->right, leftLen);
            leftLen--;       // 回溯，深度减一
        }
        return ;
    }

    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return maxleftValue;
    }
};