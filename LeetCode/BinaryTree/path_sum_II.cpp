/*
 * @Descripttion: 113. 路径总和 II
 * @Author: AruNi
 * @Date: 2022-04-29 18:48:11
 */

/*
题目：
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 
从根节点到叶子节点 路径总和等于给定目标和的路径。
叶子节点 是指没有子节点的节点。

示例 1：
输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：[[5,4,11,2],[5,8,4,5]]

示例 2：
输入：root = [1,2,3], targetSum = 5
输出：[]

示例 3：
输入：root = [1,2], targetSum = 0
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

// 与path_sum差不多，只是需要记录多条满足条件的路径，在回溯的时候除了count计数器要回溯，path路径也要回溯
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;   // 记录单个路径的节点

    // 要遍历整个树，不需要返回值
    void traversal(TreeNode* cur, int count) {
        // 遇到了叶子节点且找到了和为sum的路径
        if (!cur->left && !cur->right && count == 0) {
            result.push_back(path);
            return ;
        }

        if (!cur->left && !cur->right) return ;     // 遇到叶子节点而没有满足条件，直接返回

        if (cur->left) {   // 左 （空节点不遍历）
            path.push_back(cur->left->val); // 将该节点放入路径
            count -= cur->left->val;
            traversal(cur->left, count);    // 递归
            count += cur->left->val;        // 回溯
            path.pop_back();       // 路径也要回溯
        }
        if (cur->right) {   // 右 （空节点不遍历）
            path.push_back(cur->right->val);
            count -= cur->right->val;
            traversal(cur->right, count);   // 递归
            count += cur->right->val;       // 回溯
            path.pop_back();                // 回溯
        }
        return ;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return result;
        path.push_back(root->val);      // 把根节点放入路径
        traversal(root, targetSum - root->val);
        return result;
    }
};