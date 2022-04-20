/*
 * @Descripttion: 144. 二叉树的前序遍历
 * @Author: AruNi
 * @Date: 2022-04-09 23:36:17
 */

/*
题目：
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

示例 1：
输入：root = [1,null,2,3]
输出：[1,2,3]
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

// 递归法
class Solution {
public:

    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        vec.push_back(cur->val);    // 根   
        traversal(cur->left, vec);       // 左
        traversal(cur->right, vec);       // 右
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};

/* 
迭代法：利用栈，前序遍历是中左右，每次先处理的是中间节点;
那么先将根节点放入栈中，然后将右孩子加入栈，再加入左孩子。这样出栈的时候才是中左右的顺序
注意判断空结点不入栈！！！
**画图理解**
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if (root == NULL) return res;
        // 先将root根结点压入栈
        st.push(root);
        // 防止操作空栈
        while (!st.empty()) {
            TreeNode* node = st.top();      // 根
            st.pop();   // node指向根结点后，就将其压出栈
            res.push_back(node->val);
            if (node->right) st.push(node->right);      // 若右结点不为空，则入栈
            if (node->left) st.push(node->left);        // 若左节点不为空，则入栈
        }
        return res;
    }
};
