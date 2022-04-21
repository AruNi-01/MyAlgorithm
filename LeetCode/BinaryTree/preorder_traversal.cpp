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

/*
迭代法的前中后序遍历统一写法：
将访问的节点放入栈中，把要处理的节点也放入栈中但是要做标记。
如何标记呢，就是要处理的节点放入栈之后，紧接着放入一个空指针作为标记。 
这种方法也可以叫做标记法；过程有些抽象，一定要画图理解！
图解：https://tva1.sinaimg.cn/large/008eGmZEly1gnbmq3btubg30em09ue82.gif
*/
class Solution{
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();      // 每次都让node指向栈顶元素
            if (node != NULL) {
                st.pop();     // 将该结点弹出，避免重复操作；下面再将右中左结点添加到栈中
                if (node->right) st.push(node->right);      // 添加右节点
                if (node->left) st.push(node->left);        // 添加左节点
                st.push(node);      // 添加中节点
                st.push(NULL);      // 中节点访问过，但是还没有处理，加入空节点作为标记

                
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