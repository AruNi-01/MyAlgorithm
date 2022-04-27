/*
 * @Descripttion: 222. 完全二叉树的节点个数
 * @Author: AruNi
 * @Date: 2022-04-27 21:52:25
 */
/*
题目：
给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，
并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2^h 个节点。

示例 1：
输入：root = [1,2,3,4,5,6]
输出：6

示例 2：
输入：root = []
输出：0

示例 3：
输入：root = [1]
输出：1
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

// 递归法：和求二叉树的深度差不多
class Solution {
public:
    int getNodeNum(TreeNode* cur) {
        if (cur == NULL) return 0;
        int leftNum = getNodeNum(cur->left);        // 左
        int rightNum = getNodeNum(cur->right);      // 右
        int treeNum = leftNum + rightNum + 1;       // 中
        return treeNum;
    }
    int countNodes(TreeNode* root) {
        return getNodeNum(root);
    }
};

//简化后：
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        // 返回左右子树的节点数量，再加上1个根节点
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// 迭代法：层次遍历，遍历的时候记录节点的个数即可
class Solution {
public:
    int countNodes(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        int result = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                result++;       // 记录节点的数量
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return result;
    }
};

/* 上面的方法都是按照二叉树来做的，下面是按照完全二叉树来思考：
完全二叉树只有两种情况，情况一：就是满二叉树，情况二：最后一层叶子节点没有满
    如图：https://img-blog.csdnimg.cn/20201124092543662.png    https://img-blog.csdnimg.cn/20201124092634138.png
    对于情况一：可以直接用 2^树深度 - 1 来计算，-1是因为根节点只有一个节点
    对于情况二：分别递归左孩子，和右孩子，递归 到某一深度一定会有左孩子或者
    右孩子为满二叉树，然后依然可以按照情况1的公式来计算左孩子和右孩子的节点数。
    最后将左右孩子的节点树相加再加上1个根节点数即可！！！
*/
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int leftHeight = 0, rightHeight = 0;        // 初始值为0是为了下面求2^树深度 - 1的指数方便
        while (left) {      // 求左子树深度
            left = left->left;
            leftHeight++;
        }
        while (right) {     // 求右子树深度
            right = right->right;
            rightHeight++;
        }
        // 满二叉树的情况
        if (leftHeight == rightHeight) {
            return (2 << leftHeight) - 1;       // 2 << 1 相当于2^2，所以leftHeight初始值为0
        }
        // 最后一层叶子节点没有满，递归，直到找到满二叉树的情况，计算出左右孩子的节点数，最后加上1个根节点
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};