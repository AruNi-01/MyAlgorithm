/*
 * @Descripttion: 515. 在每个树行中找最大值
 * @Author: AruNi
 * @Date: 2022-05-01 22:39:29
 */

/*
题目：
给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。

示例1：
输入: root = [1,3,2,5,3,null,9]
输出: [1,3,9]

示例2：
输入: root = [1,2,3]
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

// 思路：层次遍历，记录最大值即可
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        vector<int> result;
        while (!que.empty()) {
            int size = que.size();
            int max = INT_MIN;      // INT_MIN 是C++中的超级小的值
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                max = node->val > max ? node->val : max;    // 记录此层的最大值
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(max);
        }
        return result;
    }
};