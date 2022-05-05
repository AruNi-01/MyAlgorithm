// 530. 二叉搜索树的最小绝对差

/*
题目：
给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。

差值是一个正数，其数值等于两值之差的绝对值。

 

示例 1：
        4
       / \
      2   6
     / \
    1   3
输入：root = [4,2,6,1,3]
输出：1

示例 2：
输入：root = [1,0,48,null,null,12,49]
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

/*思路：二叉搜索树采用中序遍历，其实就是一个有序数组。问题就简化为了在一个有序数组上求
       两个数最小差值。把二叉搜索树转换成有序数组，然后遍历一遍数组，就统计出来最小差值了。
*/
// 递归
class Solution {
private:
    vector<int> vec;
    void traversal(TreeNode* root) {
        if (root == NULL) return;
        traversal(root->left);
        vec.push_back(root->val);   // 将二叉搜索树转换为有序数组
        traversal(root->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        if (vec.size() < 2) return 0;
        int result = INT_MAX;
        for (int i = 1; i < vec.size(); i++) {
            result = min(result, vec[i] - vec[i - 1]);
        }
        return result;
    }
};

// 上面是把二叉搜索树转化为有序数组了，其实在二叉搜素树中序遍历的过程中，
// 我们就可以直接计算了。需要用一个pre节点记录一下cur节点的前一个节点。
class Solution {
private:
    int result = INT_MAX;
    TreeNode* pre;
    void traversal(TreeNode* cur) {
        if (cur == NULL) return;
        traversal(cur->left);   // 左
        if (pre != NULL) {
            result = min(result, cur->val - pre->val);  // 中
        }
        pre = cur;  // 记录前一个结点
        traversal(cur->right);  // 右
    }
public:
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return result;
    }
};

// 迭代法
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        int result = INT_MAX;
        while (cur != NULL || !st.empty())
        {
            if (cur != NULL) {  // 指针来访问结点，访问到最底层
                st.push(cur);
                cur = cur->left;    // 左
            } else {
                cur = st.top();
                st.pop();
                if (pre != NULL) {  // 中
                    result = min(result, cur->val - pre->val);
                }
                pre = cur;
                cur = cur->right;   // 右
            }
        }
        return result;
    }
};