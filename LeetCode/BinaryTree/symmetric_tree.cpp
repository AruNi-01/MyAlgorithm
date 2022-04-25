/*
 * @Descripttion: 101. 对称二叉树
 * @Author: AruNi
 * @Date: 2022-04-25 22:26:07
 */

/*
题目：
给你一个二叉树的根节点 root ， 检查它是否轴对称。

示例 1：
输入：root = [1,2,2,3,4,4,3]
输出：true

示例 2：
输入：root = [1,2,2,null,3,null,3]
输出：false
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
对于二叉树是否对称，要比较的是根节点的左子树与右子树是不是相互翻转的。所以在递归遍历的过程中，也是要同时遍历两棵树。
并且只能使用 “后序遍历”，因为要通过递归函数的返回值来判断两个子树的 内侧节点 和 外侧节点 是否相等。
准确说是一个树的遍历顺序是左右中，一个树的遍历顺序是右左中；所以并不是一个严格的 “后序遍历”。
*/

// 递归法：
class Solution {
public:
    bool compare(TreeNode* left, TreeNode* right) {
        // 左右节点只有一个为空，不对称
        if (left == NULL && right != NULL) return false;
        else if (left != NULL && right == NULL) return false;
        // 左右节点同时为空，对称
        else if (left == NULL && right == NULL) return true;
        // 左右节点都不为空，但值不相等，不对称
        else if (left->val != right->val) return false;

        // 此时就是左右节点都不为空，且数值相等的情况
        // 此时说明当前这层是对称的，做递归，做下一层的判断
        bool outside = compare(left->left, right->right);       // 外侧：左子树的左节点和右子树的右节点比较
        bool inside = compare(left->right, right->left);        // 内测：左子树的右节点和右子树的左节点比较
        bool isSame = outside && inside;          // 左子树的中节点和右子树的中节点
        return isSame;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return compare(root->left, root->right);
    }
};

// 迭代法：使用队列，本质是判断两个树是否是相互翻转的
// 通过队列来判断根节点的左子树和右子树的内侧和外侧是否相等
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        queue<TreeNode*> que;
        que.push(root->left);   // 左子树的头结点
        que.push(root->right);  // 右子树的头结点

        // 判断两个树是否相互翻转
        while (!que.empty()) {
            TreeNode* leftNode = que.front();
            que.pop();
            TreeNode* rightNode = que.front();
            que.pop();
            if (!leftNode && !rightNode) {  // 左右节点都为空，对称，比较下一层
                continue;
            }

            // 左右一个节点不为空，或都不为空但是数值不相等，不对称
            if ((!leftNode || !rightNode || (leftNode->val != rightNode->val))) {
                return false;
            }
            // 对称的添加节点到队列中
            que.push(leftNode->left);
            que.push(rightNode->right);
            que.push(leftNode->right);
            que.push(rightNode->left);
        }
        return true;
    }
};

// 迭代法：使用栈；  和使用队列一样，只是换成了栈:
// 迭代法，其实是把左右两个子树要比较的元素顺序放进一个容器，然后成对成对的取出来进行比较，那么其实使用栈也是可以的。
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        stack<TreeNode*> st;    // 这里改成了栈
        st.push(root->left);
        st.push(root->right);
        while (!st.empty()) {
            TreeNode* leftNode = st.top(); st.pop();
            TreeNode* rightNode = st.top(); st.pop();
            if (!leftNode && !rightNode) {
                continue;
            }
            if ((!leftNode || !rightNode || (leftNode->val != rightNode->val))) {
                return false;
            }
            st.push(leftNode->left);
            st.push(rightNode->right);
            st.push(leftNode->right);
            st.push(rightNode->left);
        }
        return true;
    }
};
