// 701. 二叉搜索树中的插入操作

/*
题目：
给定二叉搜索树（BST）的根节点 root 和要插入树中的值 value ，将值插入二叉搜索树。 
返回插入后二叉搜索树的根节点。 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。

注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 
你可以返回 任意有效的结果 。
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

// 二叉搜索树的中序遍历就是一个有序序列，所以插入不是在队头，也不是在队尾，
// 而是先搜索值的位置，比根小往左，反之往右。
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // 遇到空节点就插入，返回该插入的节点
        if (root == NULL) {
            TreeNode* node = new TreeNode(val);
            return node;
        }

        // 二叉搜索树是有方向的，根据当前节点值与目标值作比较
        if (root->val > val) {
            // 不需要遍历整颗树，所以需要用root->left接收递归的结果，插入后就层层返回
            root->left = insertIntoBST(root->left, val);
        }
        if (root->val < val) {
            root->right = insertIntoBST(root->right, val);
        }
        // 向上层返回已经完成插入操作的结点
        return root;
    }
};

// 递归函数不用返回值也可以，找到插入的节点位置，直接让其父节点指向插入节点，结束递归。
class Solution {
private:
    TreeNode* parent;
    void traversal(TreeNode* cur, int val) {
        if (cur == NULL) {
            TreeNode* node = new TreeNode(val);
            // 若目标值大于父节点值，则插入父节点右边
            if (val > parent->val) parent->right = node;
            else parent->left = node;
            return;
        }
        // 记录下一次递归节点的父节点
        parent = cur;
        if (cur->val > val) traversal(cur->left, val);
        if (cur->val < val) traversal(cur->right, val);
        return;
    }

public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        parent = new TreeNode(0);
        if (root == NULL) {
            root = new TreeNode(val);
        }
        traversal(root, val);
        return root;
    }
};

// 迭代法：在迭代法遍历的过程中，需要记录一下当前遍历的节点的父节点，这样才能做插入节点的操作。
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        TreeNode* cur = root;
        TreeNode* parent = root;    // 需要记录上一个节点，否则无法赋值新节点
        // 循环找到空节点
        while (cur != NULL) {
            parent = cur;
            if (cur->val > val) cur = cur->left;
            else cur = cur->right;
        }
        // 此时找到了空节点，进行插入操作
        TreeNode* node = new TreeNode(val);
        if (val < parent->val) parent->left = node;
        else parent->right = node;
        return root;
    }
};
