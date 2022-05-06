// 501. 二叉搜索树中的众数

/*
题目：
给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。

如果树中有不止一个众数，可以按 任意顺序 返回。

假定 BST 满足如下定义：

    结点左子树中所含节点的值 小于等于 当前节点的值
    结点右子树中所含节点的值 大于等于 当前节点的值
    左子树和右子树都是二叉搜索树

 

示例 1：
  1
   \
    2
   /
  2
输入：root = [1,null,2,2]
输出：[2]

示例 2：
输入：root = [0]
输出：[0]
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
思路：二叉搜索树的中序遍历是有序的，只需要在中序遍历时，找出频率最高的结点即可。

只需要遍历一遍二叉搜索树的方法：
如果 频率count 等于 maxCount（最大频率），把这个元素加入到结果集中，但是这样
有一个问题，万一这个maxCount此时还不是真正最大频率呢？ 此时就要在频率count 
大于 maxCount的时候，不仅要更新maxCount，而且要清空结果集。
这样只需要遍历一遍二叉搜索树，就求出了众数的集合
*/

class Solution {
private:
    int maxCount;   // 最大频率
    int count;  // 统计频率
    TreeNode* pre;
    vector<int> result;
    void searchBST(TreeNode* cur) {
        if (cur == NULL) return;
        searchBST(cur->left);  // 左

        if (pre == NULL) {  // 第1个节点
            count = 1;
        } else if (pre->val == cur->val) {  // 与前一个结点数值相同
            count++;
        } else {
            count = 1;  // 与前一个结点数值不同，count要置为1
        }

        pre = cur;  // 更新前一个结点

        if (count == maxCount) {    // 如果count和最大频率值相等，就放进result中
            result.push_back(cur->val);
        }

        if (count > maxCount) {     // 如果计数大于最大频率值，更新最大频率，并且清空result
            maxCount = count;
            result.clear();     // 很关键！！
            result.push_back(cur->val);
        }

        searchBST(cur->right);     // 右
        return;
    }
public:
    vector<int> findMode(TreeNode* root) {
        count = 0;
        maxCount = 0;
        TreeNode* pre = NULL;   // 根节点的pre为NULL
        searchBST(root);
        return result;
    }
};

// 迭代法：只要把中序遍历转成迭代，中间结点的处理逻辑一样
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        int maxCount = 0;
        int count = 0;
        vector<int> result;
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) {
                st.push(cur);
                cur = cur->left;    // 左
            } else {
                cur = st.top();
                st.pop();

                if (pre == NULL) {
                    count = 1;
                } else if (pre->val == cur->val) {
                    count++;
                } else {
                    count = 1;
                }

                if (count == maxCount) {
                    result.push_back(cur->val);
                }

                if (count > maxCount) {
                    maxCount = count;
                    result.clear();
                    result.push_back(cur->val);
                }

                pre = cur;
                cur = cur->right;   // 右
            }
        }
        return result;
    }
};