// 617. 合并二叉树

/*
题目：
给你两棵二叉树： root1 和 root2 。

想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。
你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的
值相加作为合并后节点的新值；否则，不为 null 的节点将直接作为新二叉树的节点。

返回合并后的二叉树。

注意: 合并过程必须从两个树的根节点开始。
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL) return root2;    // 若root1为空，则合并后为root2
        if (root2 == NULL) return root1;    // 同上
        TreeNode* node = new TreeNode(0);
        node->val = root1->val + root2->val;       // 中
        // 递归构建左子树
        node->left = mergeTrees(root1->left, root2->left);  // 左
        // 递归构建右子树
        node->right = mergeTrees(root1->right, root2->right);   // 右
        return node;
    }
};

// 迭代法：层次遍历
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL) return t2;
        if (t2 == NULL) return t1;
        queue<TreeNode*> que;
        que.push(t1);
        que.push(t2);
        while (!que.empty()) {
            TreeNode* node1 = que.front();
            que.pop();
            TreeNode* node2 = que.front();
            que.pop();
            // 此时两节点一定不为空，val值相加
            node1->val += node2->val;

            // 若两树的左节点都不为空，加入队列
            if (node1->left && node2->left) {
                que.push(node1->left);
                que.push(node2->left);
            }

            // 若两树的右节点都不为空，加入队列
            if (node1->right && node2->right) {
                que.push(node1->right);
                que.push(node2->right);
            }

            // 若t1左节点为空，t2不为空，直接赋值
            if (!node1->left && node2->left) {
                node1->left = node2->left;
            }

            // 若t1右节点为空，t2不为空，直接赋值
            if (!node1->right && node2->right) {
                node1->right = node2->right;
            }

            // t1不为空，t2为空的情况不用考虑，因为这里复用了t1
        }
        return t1;
    }
};