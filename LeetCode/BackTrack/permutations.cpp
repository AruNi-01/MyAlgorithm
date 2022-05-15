/*
 * @Descripttion: 46. 全排列
 * @Author: AruNi
 * @Date: 2022-05-15 22:45:02
 */

/*
题目：
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

示例 1：
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

示例 2：
输入：nums = [0,1]
输出：[[0,1],[1,0]]

示例 3：
输入：nums = [1]
输出：[[1]]
*/

/*
思路：
    首先排列是有序的，也就是说 [1,2] 和 [2,1] 是两个集合，这和之前分析的子集以及组合所不同的地方。
    递归函数参数：
        可以看出元素1在[1,2]中已经使用过了，但是在[2,1]中还要在使用一次1，所以处理排列问题就不用使用startIndex了，每次递归都要从0开始。
        但排列问题需要一个used数组，标记已经选择的元素。已选择的元素下标位置的used为true，例如在{1,2,3}中取了元素{1},
        则used: {true,false,false}，下一层递归遍历的时候，遇到user[i]=true的就直接跳过。
    递归终止条件：
        叶子节点的地方，就是收割结果的地方。当收集元素的数组path的大小达到和nums数组一样大的时候，
        说明找到了一个全排列，也表示到达了叶子节点。
    单层搜索逻辑：
        排列问题，每次都要从头开始搜索，例如元素1在[1,2]中已经使用过了，但是在[2,1]中还要再使用一次1。
        而used数组，其实就是记录此时path里都有哪些元素使用了，一个排列里一个元素只能使用一次。
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

        // 每次都从i=0开始，因为元素要重复使用
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) continue;      // path里已经收录的元素，直接跳过
            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);  // 先将used数组全置为false
        backtrack(nums, used);
        return result;
    }
};