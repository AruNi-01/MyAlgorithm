// 39. 组合总和

/*
题目：
给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中
可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。

candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

对于给定的输入，保证和为 target 的不同组合数少于 150 个。

示例 1：
输入：candidates = [2,3,6,7], target = 7
输出：[[2,2,3],[7]]
解释：
2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
7 也是一个候选， 7 = 7 。
仅有这两种组合。

示例 2：
输入: candidates = [2,3,5], target = 8
输出: [[2,2,2,2],[2,3,3],[3,5]]

示例 3：
输入: candidates = [2], target = 1
输出: []
*/

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    // sum：已经收集的元素的总和
    // startIndex：下一层for循环搜索的起始位置
    void backtrack(vector<int>& arr, int targetSum, int sum, int startIndex) { 
        // 判断已收集的总和是否等于目标和
        if (sum == targetSum) {
            result.push_back(path);
            return;
        }

        // 剪枝优化：如果sum加上当前遍历的数组值大于目标和，就不必继续遍历了（前提是排序好的数组）
        for (int i = startIndex; i < arr.size() && sum + arr[i] <= targetSum; i++) {
            sum += arr[i];
            path.push_back(arr[i]);
            backtrack(arr, targetSum, sum, i);
            sum -= arr[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // 剪枝优化需要排序
        backtrack(candidates, target, 0, 0);
        return result;
    }
};