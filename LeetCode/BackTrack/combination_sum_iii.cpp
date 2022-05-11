// 216. 组合总和 III

/*
题目：
找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
    只使用数字1到9
    每个数字 最多使用一次 
返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。

示例 1:
输入: k = 3, n = 7
输出: [[1,2,4]]
解释:
1 + 2 + 4 = 7
没有其他符合的组合了。

示例 2:
输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]
解释:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
没有其他符合的组合了。

示例 3:
输入: k = 4, n = 1
输出: []
解释: 不存在有效的组合。
在[1,9]范围内使用4个不同的数字，我们可以得到的最小和是1+2+3+4 = 10，因为10 > 1，没有有效的组合。
*/

/*
回溯法：
    本题k相当于了树的深度，9（因为整个集合就是9个数）就是树的宽度。
    例如 k = 2，n = 4的话，就是在集合[1,2,3,4,5,6,7,8,9]中求 k（个数） = 2, n（和） = 4的组合。
*/
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    /* 参数说明：
        k：题目中要求k个数的集合。
        targetSum：目标和，也就是题目中的n。
        sum：已经收集的元素的总和，也就是path里元素的总和。
        startIndex：下一层for循环搜索的起始位置。 */
    void backtrack(int k, int targetSum, int sum, int startIndex) {
        // 当path里的元素个数等于k时，说明已经到达限制了，终止
        if (path.size() == k) {
            // 若已收集元素的总和等于目标和，满足条件，存入result
            if (sum == targetSum) result.push_back(path);
            return; // 不满足条件 直接返回
        }

        // 题中已经限制了集合固定的数1-9
        for (int i = startIndex; i <= 9; i++) {
            sum += i;
            path.push_back(i);
            backtrack(k, targetSum, sum, i + 1);    // 递归下一层时：i + 1 调整startIndex
            sum -= i;   // 回溯
            path.pop_back();    // 回溯
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k, n, 0, 1);
        return result;
    }
};

/*
剪枝优化：
    已收集元素总和（path中的元素总和）如果已经大于n了，那么往后遍历就没有意义了，直接剪掉。
    剪枝的地方一定是在递归终止的地方剪。
    和题 77. 组合一样，for循环也可以剪枝优化。
*/
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    /* 参数说明：
        k：题目中要求k个数的集合。
        targetSum：目标和，也就是题目中的n。
        sum：已经收集的元素的总和，也就是path里元素的总和。
        startIndex：下一层for循环搜索的起始位置。 */
    void backtrack(int k, int targetSum, int sum, int startIndex) {

        // 剪枝优化：已收集元素总和（path中的元素总和）如果已经大于n了，可以剪掉
        if (sum > targetSum) return;

        // 当path里的元素个数等于k时，说明已经到达限制了，终止
        if (path.size() == k) {
            // 若已收集元素的总和等于目标和，满足条件，存入result
            if (sum == targetSum) result.push_back(path);
            return; // 不满足条件 直接返回
        }

        // 题中已经限制了集合固定的数1-9
        // 剪枝优化
        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++) {
            sum += i;
            path.push_back(i);
            backtrack(k, targetSum, sum, i + 1);    // 递归下一层时：i + 1 调整startIndex
            sum -= i;   // 回溯
            path.pop_back();    // 回溯
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k, n, 0, 1);
        return result;
    }
};
