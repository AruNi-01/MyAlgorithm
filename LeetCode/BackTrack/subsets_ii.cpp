// 90. 子集 II

/*
题目：
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

示例 1：
输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]

示例 2：
输入：nums = [0]
输出：[[],[0]]
*/

/*
此题和 40.组合总和II中去重的逻辑相同，都是树层去重，树枝不用去重，可以重复取，如{1,2,2}
去重逻辑：
    当for循环中i大于startIndex时，说明是回溯后进行横向遍历了，因为for循环走完后的i++了，而没有走
    backtrack递归中的i+1(startIndex的值)，此时判断当前元素是否和上一个元素一致，是则直接跳过此次递归
*/
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtrack(vector<int>& nums, int startIndex) {
        result.push_back(path);
        if (startIndex >= nums.size()) {
            return;
        }

        for (int i = startIndex; i < nums.size(); i++) {
            // 对同一层使用过的元素去重
            if (i > startIndex && nums[i] == nums[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return result;
    }
};