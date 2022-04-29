/*
 * @Descripttion: 404. 左叶子之和
 * @Author: AruNi
 * @Date: 2022-04-29 19:13:25
 */

/*
题目：
给定二叉树的根节点 root ，返回所有左叶子之和。

示例 1：
输入: root = [3,9,20,null,null,15,7] 
输出: 24 
解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

示例 2:
输入: root = [1]
输出: 0
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
注意：判断左叶子，不是二叉树左侧节点，所以不要上来想着层序遍历。
左叶子的定义：如果左节点不为空，且左节点没有左右孩子，那么这个节点的左节点就是左叶子。
判断当前节点是不是左叶子是无法判断的，必须要通过节点的父节点来判断其左孩子是不是左叶子。
如果该节点的左节点不为空，该节点的左节点的左节点为空，该节点的左节点的右节点为空，则找到了一个左叶子(即该节点的左节点)
*/
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        int leftValue = sumOfLeftLeaves(root->left);    // 左
        int rightValue = sumOfLeftLeaves(root->right);  // 右
                                                        // 中
        int midValue = 0;

        // 当遇到左叶子节点的时候，记录数值，然后通过递归求取左子树左叶子之和，
        // 和 右子树左叶子之和，相加便是整个树的左叶子之和
        if (root->left && !root->left->left && !root->left->right) {
            midValue = root->left->val;
        }
        int sum = midValue + leftValue + rightValue;

        return sum;
    }
};

// 迭代法：
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode*> st;
        if (root == NULL) return 0;
        st.push(root);
        int result = 0;
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            // 遇到左叶子节点，记录值
            if (node->left != NULL && node->left->left == NULL && node->left->right == NULL) {
                result += node->left->val;
            }
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }
        return result;
    }
};
