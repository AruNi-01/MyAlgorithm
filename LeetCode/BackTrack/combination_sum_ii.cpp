// 40. 组合总和 II

/*
题目：
给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用 一次 。

注意：解集不能包含重复的组合。 
 
示例 1:
输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

示例 2:
输入: candidates = [2,5,2,1,2], target = 5,
输出:
[
[1,2,2],
[5]
]
*/

/* 
重点在于去重，可以直接使用Set，但是由于Set是红黑树底层，其效率过低。
要在同一层去重，而不是同一树枝上去重，因为元素在同一个组合内是可以重复的，所以纵向元素可以重复
但两个组合不能重复，所以横向要去重（前提数组是有序）
去重逻辑：
    当for循环中i大于startIndex时，说明是回溯后进行横向遍历了，因为for循环走完后的i++了，而没有走
    backtrack递归中的i+1(startIndex的值)，此时判断当前元素是否和上一个元素一致，是则直接跳过此次递归
*/
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtrack(vector<int>& arr, int targetSum, int sum, int startIndex) {
        if (sum == targetSum) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < arr.size() && sum + arr[i] <= targetSum; i++) {
            // 对同一层使用过的元素去重
            if (i > startIndex && arr[i] == arr[i - 1]) {
                continue;
            }
            sum += arr[i];
            path.push_back(arr[i]);
            backtrack(arr, targetSum, sum, i + 1);  // 注意这里是i+1，每个元素只能用一次
            sum -= arr[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0);
        return result;
    }
};