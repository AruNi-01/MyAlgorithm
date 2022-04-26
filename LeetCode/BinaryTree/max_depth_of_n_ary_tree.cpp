/*
 * @Descripttion: 559. N 叉树的最大深度
 * @Author: AruNi
 * @Date: 2022-04-26 23:38:52
 */

/*
题目：
给定一个 N 叉树，找到其最大深度。
最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
N 叉树输入按层序遍历序列化表示，每组子节点由空值分隔（请参见示例）。

示例 1：
输入：root = [1,null,3,2,4,null,5,6]        null表示此层已完或上一节点无儿子
输出：3

示例 2：
输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
输出：5
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// 递归法：思路是和二叉树思路一样的，只是需要循环遍历每一个子节点，子节点是一个数组
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == 0 ) return 0;
        int depth = 0;
        for (int i = 0; i < root->children.size(); i++) {
            // 递归出每个子节点的深度
            int childDepth = maxDepth(root->children[i]);
            // 取深度最大的值
            depth = max(depth, childDepth);
        }
        return depth + 1;   // 每遍历完一层，深度就 +1
    }
};

// 迭代法：层序遍历
class Solution {
public:
    int maxDepth(Node* root) {
        queue<Node*> que;
        if (root != NULL) que.push(root);
        int depth = 0;
        while (!que.empty()) {
            int size = que.size();
            depth++;
            for (int i = 0; i < size; i++) {
                Node* node = que.front();
                que.pop();
                // 遍历出该节点的所有子节点，不为空就加入到队列中
                for (int j = 0; j < node->children.size(); j++) {
                    if (node->children[j]) {
                        que.push(node->children[j]);
                    }
                }
            }
        }
        return depth;
    }
};