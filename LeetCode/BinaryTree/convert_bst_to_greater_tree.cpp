// 538. 把二叉搜索树转换为累加树

/*
题目：
给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），
使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。
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

/*思路：
    把这颗二叉搜索树看成是有序的数组，累加树就是从后往前累加，例如[2,5,13] --> [2+5+13,5+13,13+0]

    再把思维转到二叉搜索树上面来：
        从树中可以看出累加的顺序是右中左，所以我们需要反中序遍历这个二叉树，然后顺序累加就可以了。
*/
class Solution {
private:
    int pre;    // 记录前一个结点的数值
    void traversal(TreeNode* cur) {     // 反中序遍历（右中左）
        if (cur == NULL) return;
        traversal(cur->right);  // 右
        cur->val += pre;    // 中，当前节点值等于当前节点值+前一个结点值
        pre = cur->val;
        traversal(cur->left);   // 左
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        pre = 0;
        traversal(root);
        return root;
    }
};