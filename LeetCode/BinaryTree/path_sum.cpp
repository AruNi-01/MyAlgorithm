/*
 * @Descripttion: 112. 路径总和
 * @Author: AruNi
 * @Date: 2022-04-29 17:23:39
 */

/*
题目：
给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，
这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。
叶子节点是指没有子节点的节点。

示例 1：
输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
输出：true
解释：等于目标和的根节点到叶节点路径如上图所示。

示例 2：
输入：root = [1,2,3], targetSum = 5
输出：false
解释：树中存在两条根节点到叶子节点的路径：
(1 --> 2): 和为 3
(1 --> 3): 和为 4
不存在 sum = 5 的根节点到叶子节点的路径。

示例 3：
输入：root = [], targetSum = 0
输出：false
解释：由于树是空的，所以不存在根节点到叶子节点的路径。
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
不要去累加然后判断是否等于目标和，那么代码比较麻烦，可以用递减，
让计数器count初始为目标和，然后每次减去遍历路径节点上的数值。
如果最后count == 0，同时到了叶子节点的话，说明找到了目标和。
如果遍历到了叶子节点，count不为0，就是没找到。
涉及回溯：若此条路径不符合要撤回找另一条路径
*/
class Solution {
public:
    // 参数为根节点和计数器，满足条件就直接返回true
    bool traversal(TreeNode* cur, int count) {
        // 遇到叶子节点，并且计数为0，满足条件
        if (!cur->left && !cur->right && count == 0) return true;
        // 遇到叶子节点直接返回，寻找下一条路径
        if (!cur->left && !cur->right) return false;

        if (cur->left) {        // 左
            count -= cur->left->val;    // 下面递归，要处理左节点，更新计数器
            // 遇到叶子节点返回true，则说明满足条件，直接返回true
            if (traversal(cur->left, count)) return true;
            count += cur->left->val;    // 递归到最底层，不满足条件；回溯，撤回找另一条路径
        }
        if (cur->right) {       // 右
            count -= cur->right->val;
            if (traversal(cur->left, count)) return true;
            count += cur->left->val;
        }
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        return traversal(root, targetSum - root->val);
    }
};

// 简化
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        if (!root->left && !root->right && targetSum == root->val) return true;
        // 左右子树有一个满足条件即可；其中递归隐含了回溯，targetSum每次作为参数传进去，所以并没有正真的被改变
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};
