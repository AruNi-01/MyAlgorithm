/*
 * @Descripttion: 
 * @Author: AruNi
 * @Date: 2022-04-27 21:20:12
 */

/*
题目：
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:
给定二叉树 [3,9,20,null,null,15,7]
返回 true 。

示例 2:
给定二叉树 [1,2,2,3,3,null,null,4,4]
返回 false 
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
首先弄清楚深度和高度：
    · 二叉树节点的深度：指从根节点到该节点的最长简单路径边的条数。
    · 二叉树节点的高度：指从该节点到叶子节点的最长简单路径边的条数。
    因为求深度可以从上到下去查 所以需要前序遍历（中左右），而高度只能从下到上去查，所以只能后序遍历（左右中）

本题递归解法：
    分别求出其左右子树的高度，然后如果差值小于等于1，则返回当前二叉树的高度，否则则返回-1，表示已经不是二叉平衡树了。
*/
class Solution {
public:
    // 返回-1表示该节点已经不是平衡二叉树了，否则返回值是该节点树的高度
    int getHeight(TreeNode* node) {
        // 递归过程遇到空节点返回0，表示该节点树的高度为0
        if (node == NULL) return 0;

        // 开始递归判断每个节点的左右子树是否满足平衡二叉树
        int leftHeight = getHeight(node->left);     // 左
        if (leftHeight == -1) return -1;        // 说明左子树已经不是平衡二叉树了
        int rightHeight = getHeight(node->right);   // 右
        if (rightHeight == -1) return -1;       // 同上

        // 左右两边高度差大于1，不是平衡二叉树; 否则返回该节点的树的最大高度
        return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        return getHeight(root) == -1 ? false : true;
    }
};