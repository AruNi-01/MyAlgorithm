/*
 * @Descripttion: 47. 全排列 II
 * @Author: AruNi
 * @Date: 2022-05-16 23:12:00
 */

/* 
题目：
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

示例 1：
输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]

示例 2：
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

/*
和 46.全排列 的区别在与给定一个可包含重复数字的序列，要返回所有不重复的全排列。
这里又涉及到去重了，还是对同一层去重。去重逻辑：
    因为used数据初始化全部为false，在同一树枝递归时，used[i]会被逐个置为true，当回溯时，
    used[i]会被置回false，进行树层的遍历，所以used[i-1]=false且nums[i] == nums[i - 1]，
    就说明同一层使用过。
*/
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtrack(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // used[i - 1] == true，说明同一树枝nums[i - 1]使用过
            // used[i - 1] == false，说明同一树层nums[i - 1]使用过
            // 如果同一树层nums[i - 1]使用过则直接跳过
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }

            if (used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                backtrack(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());     // 去重要先排序
        vector<bool> used(nums.size(), false);
        backtrack(nums, used);
        return result;
    }
};

// 也可以使用set去重，和 491. 递增子序列 一样。
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking (vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        unordered_set<int> uset; // 控制某一节点下的同一层元素不能重复
        for (int i = 0; i < nums.size(); i++) {
            if (uset.find(nums[i]) != uset.end()) {
                continue;
            }
            if (used[i] == false) {
                uset.insert(nums[i]); // 记录元素
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end()); // 排序
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};
