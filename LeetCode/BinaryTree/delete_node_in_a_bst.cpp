// 450. 删除二叉搜索树中的节点

/*
题目：
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，
并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：
    首先找到需要删除的节点；
    如果找到了，删除它。
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
二叉搜索树中删除节点的情况：
    第1种情况：没找到删除的节点，遍历到空节点直接返回了
找到删除的节点:
    第2种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
    第3种情况：删除节点的左孩子为空，右孩子不为空，删除节点，右孩子补位，返回右孩子为根节点
    第4种情况：删除节点的右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
    第5种情况：左右孩子节点都不为空，则将删除节点的左子树头结点放到删除节点的右子树的最左面
               节点的左孩子上，返回 删除节点的右子树头结点，作为为新的根节点。
    第5种情况动画（要删除节点7）：https://tva1.sinaimg.cn/large/008eGmZEly1gnbj3k596mg30dq0aigyz.gif
*/
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return root;  // 第1种情况
        if (root->val == key) {
            // 第2种情况
            if (root->left == NULL && root->right == NULL) {
                return NULL;
            }
            // 第3种情况
            else if (root->left == NULL) {
                auto retNode = root->right;
                return retNode;
            }
            // 第4种情况
            else if (root->right == NULL) {
                auto retNode = root->left;
                return retNode;
            }
            // 第5种情况
            else {
                TreeNode* cur = root->right;
                // 找右子树最左面的节点
                while (cur->left != NULL) {
                    cur = cur->left;
                }
                cur->left = root->left; // 把要删除的节点（root）左子树放在cur的左孩子的位置
                TreeNode* tmp = root;   // 把root节点保存一下，下面来删除
                root = root->right;     // 返回旧root的右孩子作为新root
                return root;
            }
        }

        if (root->val > key) root->left = deleteNode(root->left, key);
        if (root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};
