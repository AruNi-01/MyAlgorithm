/*
 * @Descripttion: 199. 二叉树的右视图
 * @Author: AruNi
 * @Date: 2022-05-01 21:45:40
 */

/*
题目：
给定一个二叉树的 根节点 root，想象自己站在它的右侧，
按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例 1:
    1
   / \
  2   3
   \   \
    5   4
输入: [1,2,3,null,5,null,4]
输出: [1,3,4]

示例 2:
输入: [1,null,3]
输出: [1,3]
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

// 思路：层序遍历的时候，判断是否遍历到单层的最后面的元素，
//      如果是，就放进result数组中，随后返回result就可以了。
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        vector<int> result;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (i == (size - 1)) result.push_back(node->val); // 将每一层的最后元素放入result数组中
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return result;
    }
};