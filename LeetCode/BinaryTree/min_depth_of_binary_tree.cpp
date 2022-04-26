/*
 * @Descripttion: 111. 二叉树的最小深度
 * @Author: AruNi
 * @Date: 2022-04-26 23:57:56
 */
/*
题目：
给定一个二叉树，找出其最小深度。
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
说明：叶子节点是指没有子节点的节点。

示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：2

示例 2：
输入：root = [2,null,3,null,4,null,5,null,6]
输出：5
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
遍历顺序上依然是后序遍历（因为要比较递归返回之后的结果），但在处理中间节点的逻辑上，最大深度很容易理解，最小深度可有一个误区：
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。注意是叶子节点。左右孩子都为空的节点才是叶子节点！
/*

/*
递归法：
不能像求最大深度那样 int depth = 1 + min(leftDepth, rightDepth); 这样会忽略另一边不为空的情况。
正确的逻辑应该是：
如果左子树为空，右子树不为空，说明最小深度是 1 + 右子树的深度。
反之，右子树为空，左子树不为空，最小深度是 1 + 左子树的深度。 
最后如果左右子树都不为空，返回左右子树深度最小值 + 1 。
*/
class Solution {
public:
    int getDepth(TreeNode* node) {
        if (node == NULL) return 0;
        int leftDepth = getDepth(node->left);           // 左
        int rightDepth = getDepth(node->right);         // 右
                                                        // 中
        // 当一个左子树为空，右不为空，这时并不是最低点
        if (node->left == NULL && node->right != NULL) { 
            return 1 + rightDepth;
        }   
        // 当一个右子树为空，左不为空，这时并不是最低点
        if (node->left != NULL && node->right == NULL) { 
            return 1 + leftDepth;
        }
        int result = 1 + min(leftDepth, rightDepth);
        return result;
    }

    int minDepth(TreeNode* root) {
        return getDepth(root);
    }
};

// 迭代法：层序遍历。
// 需要注意的是，只有当左右孩子都为空的时候，才说明遍历的最低点了。如果其中一个孩子为空则不是最低点
class Solution {
public:

    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int depth = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int size = que.size();
            depth++;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                if (!node->left && !node->right) {  // 当左右孩子都为空的时候，说明是最低点的一层了，就马上退出循环
                    return depth;
                }
            }
        }
        // 若循环都走完了，则说明这颗二叉树的深度就是最小深度
        return depth;
    }
};
