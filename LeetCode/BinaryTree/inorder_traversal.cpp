/*
 * @Descripttion: 94. 二叉树的中序遍历
 * @Author: AruNi
 * @Date: 2022-04-09 23:44:30
 */

/*
题目：
给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。

示例 1：
输入：root = [1,null,2,3]
输出：[1,3,2]
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
        vec.push_back(cur->val);        // 根
        traversal(cur->right, vec);     // 右
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};

// 迭代法：
/*
中序遍历是左中右，先访问的是二叉树顶部的节点，然后一层一层向下访问，直到到达树左面的最底部，
再开始处理节点（也就是在把节点的数值放进res数组中），这就造成了处理顺序和访问顺序是不一致的。
那么在使用迭代法写中序遍历，就需要借用指针的遍历来帮助访问节点，栈则用来处理节点上的元素。
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        TreeNode* cur = root;
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) {      // 指针用来访问结点，访问到最底层
                st.push(cur);    // 将访问的结点入栈
                cur = cur->left;      // 左
            } else {
                cur = st.top();     // 从栈里弹出来的数据，就是要处理的数据(放入res数组中的数据)
                st.pop();
                res.push_back(cur->val);     // 根
                cur = cur->right;       // 右
            }
        }
        return res;
    }
};

/*
迭代法的前中后序遍历统一写法：
*/
class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();      // 每次都让node指向栈顶元素
            if (node != NULL) {
                st.pop();     // 将该结点弹出，避免重复操作；下面再将右中左结点添加到栈中
                if (node->right) st.push(node->right);      // 添加右节点

                st.push(node);      // 添加中节点
                st.push(NULL);      // 中节点访问过，但是还没有处理，加入空节点作为标记

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