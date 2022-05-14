// 子集
/*
题目：
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

示例 1：
输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

示例 2：
输入：nums = [0]
输出：[[],[0]]
*/

/*
以示例中nums = [1,2,3]为例把求子集抽象为树型结构：https://img-blog.csdnimg.cn/202011232041348.png
从图中红线部分，可以看出遍历这个树的时候，把所有节点都记录下来，就是要求的子集集合。
递归回溯步骤：
    递归取1，再取2，再取3                   递归到了叶子节点，把结果{1},{1,2},{1,2,3}加入结果集
    回溯3，{1,2}已存在，再回溯2，递归取3     递归到了叶子节点，把结果{1,3}加入结果集
    回溯1，递归取2，再取3                   递归到了叶子节点，把结果{2},{2,3}加入结果集
    回溯3，{2}已存在，再回溯2，递归取3       递归到了叶子节点，把结果{3} 加入结果集
*/
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    // 需要startIndex，因为结果集合不能重复 ({1,2}和{2,1}相同)，for要从startIndex开始，而不是从0开始
    void backtrack(vector<int>& nums, int startIndex) {
        result.push_back(path); // 收集子集，不用特意加空集进去，首次调用backtrack时path就是空
        // 终止条件：剩余集合为空的时候，就是叶子节点
        // startIndex大于数组长度，说明递归到了叶子节点
        if (startIndex >= nums.size()) {
            return;
        }
        // 其实可以不需要加终止条件，因为startIndex >= nums.size()，本层for循环本来也结束了。

        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(nums, i + 1); // 注意从i+1开始，元素不重复取
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }
};