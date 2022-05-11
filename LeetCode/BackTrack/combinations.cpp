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

/* 剪枝优化：回溯法虽然是暴力搜索，但也有时候可以有点剪枝优化一下的。
   示例：
        n=4，k=3，当path.size()=1时，还需要2个数能组成组合，startIndex=1,2,3都可以，但是4不行。
        所以，可以剪枝的地方就在递归中每一层的for循环所选择的起始位置。
        如果for循环选择的起始位置之后的元素个数 已经不足 我们需要的元素个数了，那么就没有必要搜索了。
    for 循环中条件优化过程：
        1.已经选择了的元素个数：path.size();
        2.还需要的元素个数：k - path.size();
        3.i的上限为: n - (k - path.size()) + 1;  +1 是因为startIndex自身也算一个数

    解析：
    [_ _ _ _]：假设n为4，现在还需要2个数，那么，n - 2 = 2 此时对应第2个'_'的位置，
               再+1对应第3个'_'的位置，此时的下一个位置能组合的数只有它自己1个，就不满足k=2了
*/

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
        // 剪枝优化：n=4，k=2，path.size()=0，startIndex可以为1/2/3，但不能为4
        // 所以 i <= n - (k - path.size()) + 1
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
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
