// 77. 组合

/*
题目：
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
你可以按 任何顺序 返回答案。

示例 1：
输入：n = 4, k = 2
输出：
[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]

示例 2：
输入：n = 1, k = 1
输出：[[1]]
*/

// 回溯法：每找到一个符合条件的组合，就回溯撤销一个数值再去寻找下一个符合条件的组合
class Solution {
private:
    vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path;   // 存放某个符合条件的结果
    // startIndex用来记录本层递归的中，集合从哪里开始遍历
    void backtracking(int n, int k, int startIndex) {
        // path的size等于k，说明满足条件了，将结果存放到result中
        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        // for循环每次从startIndex开始遍历，然后用path保存取到的节点i
        for (int i = startIndex; i <= n; i++) {
            path.push_back(i);  // 处理结点
            backtracking(n, k, i + 1);  // 递归，不断增加path中的数，直到满足条件
            path.pop_back();    // 回溯，将此满足条件的数值撤回，继续寻找下一数值
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);  // 组合起始值从1开始
        return result;
    }
};