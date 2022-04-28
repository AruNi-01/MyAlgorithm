/*
 * @Descripttion: 257. 二叉树的所有路径
 * @Author: AruNi
 * @Date: 2022-04-28 22:18:45
 */

/*
题目：
给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
叶子节点 是指没有子节点的节点。
 
示例 1：
    1
   / \
  2   3
   \
    5
输入：root = [1,2,3,null,5]
输出：["1->2->5","1->3"]

示例 2：
输入：root = [1]
输出：["1"]
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
从根节点到叶子的路径，所以需要前序遍历，这样才方便让父节点指向孩子节点，找到对应的路径。
在这道题目中将第一次涉及到回溯，因为我们要把路径记录下来，需要回溯来回退一一个路径在进入另一个路径。
回溯过程：https://img-blog.csdnimg.cn/20210204151702443.png
*/
class Solution {
public:
    // 传入根节点，记录每一条路径的path，和存放结果集的result
    void traversal(TreeNode* cur, vector<int>& path, vector<string>& result) {
        // 前序遍历，需要先处理中间节点，中间节点就是我们要记录路径上的节点，先放进path中
        path.push_back(cur->val);

        // 当cur不为空(下面递归时候判断即可)，其左右孩子都为空的时候，就找到叶子节点，开始结束的处理逻辑（将路径放入result里）
        if (cur->left == NULL && cur->right == NULL) {
            string sPath;
            // 将path里记录的路径转为string格式，最后一个节点单独处理，因为最后一个节点不用在后面加上 "->" 
            // 那么为什么使用了vector 结构来记录路径呢？ 
            // 因为在下面处理单层递归逻辑的时候，要做回溯，使用vector方便来做回溯
            for (int i = 0; i < path.size() - 1; i++) {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);      // 记录最后一个节点（叶子节点）
            result.push_back(sPath);    // 收集一个路径
            return;
        }

        // 回溯和递归是一一对应的，有一个递归，就要有一个回溯
        // 当下一个节点不是空节点时，递归遍历下一个节点
        if (cur->left) {
            traversal(cur->left, path, result);
            path.pop_back();     // 回溯
        }
        if (cur->right) {
            traversal(cur->right, path, result);
            path.pop_back();    // 回溯
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        if (root == NULL) return result;
        traversal(root, path, result);
        return result;
    }
};

// 迭代法：可以使用前序遍历的迭代方式来模拟遍历路径的过程，
// 除了模拟递归需要一个栈，同时还需要一个栈来存放对应的遍历路径。
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        stack<TreeNode*> treeSt;    // 保存树的遍历节点
        stack<string> pathSt;       // 保存遍历路径的节点
        vector<string> result;      // 保存最终路径集合
        if (root == NULL) return result;
        treeSt.push(root);
        pathSt.push(to_string(root->val));
        while (!treeSt.empty()) {
            TreeNode* node = treeSt.top(); treeSt.pop(); // 取出节点 中
            string path = pathSt.top(); pathSt.pop();    // 取出该节点对应的路径
            if (node->left == NULL && node->right == NULL) {    // 遇到叶子节点，将该叶子节点对应的整条路径加入到结果集中
                result.push_back(path);
            }
            if (node->right) {      // 右
                treeSt.push(node->right);
                pathSt.push(path + "->" + to_string(node->right->val));
            }
            if (node->left) {       // 左
                treeSt.push(node->left);
                pathSt.push(path + "->" + to_string(node->left->val));
            }
        }
        return result;
    }
};
