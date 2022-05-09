// 108. 将有序数组转换为二叉搜索树

/*
题目：
给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。

高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。

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

// 递归思路：分割点为数组中间位置的节点
class Solution {
private:
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        // 定义的是左闭右闭的区间，所以当区间 left>right的时候，就是空节点，
        // 说明某条子树构建完了
        if (left > right) return NULL;
        // 分割点
        int mid = left + ((right - left) / 2);
        // 创建新节点，节点值为每次递归 nums数组中间位置的值
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = traversal(nums, left, mid - 1);    // 递归构建左子树
        root->right = traversal(nums, mid + 1, right);  // 递归构建右子树
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = traversal(nums, 0, nums.size() - 1);
        return root;
    }
};
