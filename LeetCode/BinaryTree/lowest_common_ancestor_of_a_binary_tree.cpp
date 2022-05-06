// 236. 二叉树的最近公共祖先
/*
题目：
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，
满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

 

示例 1：
         3
       /   \
      5     1
     / \   / \
    6   2 0   8
       / \
      7   4
输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出：3
解释：节点 5 和节点 1 的最近公共祖先是节点 3 。

示例 2：
输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出：5
解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。

示例 3：
输入：root = [1,2], p = 1, q = 2
输出：1
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
思路：
    1.自底向上查找，这样就可以找到公共祖先了。二叉树回溯的过程就是从低到上。
    而后序遍历就是天然的回溯过程，最先处理的一定是叶子节点。
    2.本题函数有返回值，是因为回溯的过程需要递归函数的返回值做判断，但本题我们
    依然要遍历树的所有节点。
    因为在后序遍历中，如果想利用left和right做逻辑处理，不能立刻返回，而是要等left
    与right逻辑处理完之后才能返回。所以需要遍历整棵树。
    3.如果left 和 right都不为空，说明此时root就是最近公共节点。
    如果left为空，right不为空，就返回right，说明目标节点是通过right返回的，反之依然。
    如果left和right都为空，则返回left或者right都是可以的，也就是返回空。
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 递归终止条件：找到目标节点或节点为空就返回
        if (root == q || root == p || root == NULL) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);    // 左
        TreeNode* right = lowestCommonAncestor(root->right, p, q);    // 右

        // 如果左右子树都不为空，说明此节点位置就是最近公共祖先
        if (left != NULL && right != NULL) return root;

        // 思路3
        if (left == NULL && right != NULL) return right;
        else if (left != NULL && right == NULL) return left;
        else return NULL;
    }
};