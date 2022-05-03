// 98. 验证二叉搜索树

/*
题目：
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：
    节点的左子树只包含 小于 当前节点的数。
    节点的右子树只包含 大于 当前节点的数。
    所有左子树和右子树自身必须也是二叉搜索树。
 
示例 1：
        2
       / \
      1   3
输入：root = [2,1,3]
输出：true

示例 2：
        5
       / \
      1   4
         / \
        3   6
输入：root = [5,1,4,null,null,3,6]
输出：false
解释：根节点的值是 5 ，但是右子节点的值是 4 。
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
思路：
    要知道中序遍历下，输出的二叉搜索树节点的数值是有序序列。
    有了这个特性，验证二叉搜索树，就相当于变成了判断一个序列是不是递增的了。
*/
// 将中序遍历的结果放入数组中，再判断数组是否是升序的
class Solution {
private:
    vector<int> vec;
    void traversal(TreeNode* root) {
        if (root == NULL) return;
        traversal(root->left);
        vec.push_back(root->val);
        traversal(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        traversal(root);
        for (int i = 1; i < vec.size(); i++) {
            // 注意：使用 <=，搜索树中不能有相同元素
            if (vec[i] <= vec[i - 1]) return false;
        }
        return true;
    }
};

// 不使用数组，直接递归时判断：
class Solution {
public:
    TreeNode* pre = NULL;   // 用来记录前一个节点
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        bool left = isValidBST(root->left);

        // 前一个结点值大于等于当前节点值，说明已经不是严格升序了
        if (pre != NULL && pre->val >= root->val) return false;
        pre = root;     // 记录前一个节点

        bool right = isValidBST(root->right);
        return left && right;
    }
};

// 迭代法：
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL; // 记录前一个节点
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) {
                st.push(cur);
                cur = cur->left;                // 左
            } else {
                cur = st.top();                 // 中
                st.pop();
                if (pre != NULL && cur->val <= pre->val)
                return false;
                pre = cur; //保存前一个访问的结点

                cur = cur->right;               // 右
            }
        }
        return true;
    }
};
