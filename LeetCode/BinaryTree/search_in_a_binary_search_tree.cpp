// 700. 二叉搜索树中的搜索

/*
题目：
给定二叉搜索树（BST）的根节点 root 和一个整数值 val。

你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null 。

示例 1:
输入：root = [4,2,7,1,3], val = 2
输出：[2,1,3]

Example 2:
输入：root = [4,2,7,1,3], val = 5
输出：[]
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
二叉搜索树是一个有序树：
    若它的左子树不空，则左子树上 所有结点 的值均小于它的根结点的值；
    若它的右子树不空，则右子树上 所有结点 的值均大于它的根结点的值；
    它的左、右子树也分别为二叉搜索树
*/

/*
递归：
因为二叉搜索树的节点是有序的，所以可以有方向的去搜索：
如果root->val > val，搜索左子树，如果root->val < val，就搜索右子树，
最后如果都没有搜索到，就返回NULL。
*/
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // 递归退出条件：查找到空节点或者找到了该节点，则返回对应的值
        if (root == NULL || root->val == val) return root;
        // 查找的值大于val值，搜索较小的左子树
        if (root->val > val) searchBST(root->left, val);

        if (root->val < val) searchBST(root->right, val);

        return NULL;
    }
};

/*
迭代法：
    因为二叉搜索树的特殊性，也就是节点的有序性，可以不使用辅助栈
    或者队列就可以写出迭代法。

例如要搜索元素为3的节点，我们不需要搜索其他节点，也不需要做回溯，查找的路径已经规划好了。
中间节点如果大于3就向左走，如果小于3就向右走，如图：
        4
       / \
      2   7
     / \
    1   3
*/
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != NULL) {
            if (root->val > val) root = root->left;
            else if (root->val < val) root = root->right;
            else return root;
        }
        return NULL;
    }
};
