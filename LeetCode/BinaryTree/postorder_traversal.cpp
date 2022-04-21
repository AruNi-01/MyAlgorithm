/*
 * @Descripttion: 145. 二叉树的后序遍历
 * @Author: AruNi
 * @Date: 2022-04-09 23:37:39
 */

/*
题目：
给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。

示例 1：

输入：root = [1,null,2,3]
输出：[3,2,1]

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

// 递归法：
class Solution {
public:

    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        traversal(cur->left, vec);      // 左
        traversal(cur->right, vec);     // 右
        vec.push_back(cur->val);        // 根
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};

// 迭代法：
/*
后序遍历 —— 左-右-根
前序遍历 —— 根-左-右  调换左右 ==》 根-右-左  反转 ==》 左-右-根 == 后续遍历
是不是太妙啦！！！只需要改变以下前序遍历的左右顺序，再反转res数组即可。
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if (root == NULL) return res;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node->val);   // 根
            // 相对于前序遍历，只需要改变以下入栈顺序即是后续遍历
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

/*
迭代法的前中后序遍历统一写法：
*/
class Solution{
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();      // 每次都让node指向栈顶元素
            if (node != NULL) {
                st.pop();     // 将该结点弹出，避免重复操作；下面再将右中左结点添加到栈中
                st.push(node);      // 添加中节点
                st.push(NULL);      // 中节点访问过，但是还没有处理，加入空节点作为标记

                if (node->right) st.push(node->right);      // 添加右节点
                if (node->left) st.push(node->left);    // 添加左节点
            } else {        // 只有遇到空节点时，才将下一个节点放入结果集
                st.pop();           // 将空节点弹出
                node = st.top();        //重新取出栈中元素
                st.pop();
                res.push_back(node->val);       // 加入到结果集
            }
        }
        return res;
    }
};