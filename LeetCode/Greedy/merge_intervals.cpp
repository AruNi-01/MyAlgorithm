/*
 * @Descripttion: 56. 合并区间
 * @Author: AruNi
 * @Date: 2022-05-23 22:51:48
 */

/*
题目：
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

示例 1：
输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6]

示例 2：
输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间
*/

/*
贪心算法：
    按照左边界排序，排序之后:
    局部最优：每次合并都取最大的右边界，这样就可以合并更多的区间了
    整体最优：合并所有重叠的区间

判断重复：intervals[i]的左边界在intervals[i - 1]左边界和右边界的范围内，那么一定有重复
模拟合并：用合并区间后左边界和右边界，作为一个新的区间，加入到result数组里就可以了。
         如果没有合并就把原区间加入到result数组。
*/
class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }      

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.size() == 0) return result;
        sort(intervals.begin(), intervals.end(), cmp);

        result.push_back(intervals[0]);     // 先将第一个区间添加进结果集
        for (int i = 1; i < intervals.size(); i++) {
            // 若该区间的左边界小于等于前一个区间的右边界，说明有重复，合并区间
            if (result.back()[1] >= intervals[i][0]) {
                // 只需要将前一个区间的右边界更新为这两个区间的右边界的最大值即可
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                // 没有重复，直接将该区间添加进result
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};