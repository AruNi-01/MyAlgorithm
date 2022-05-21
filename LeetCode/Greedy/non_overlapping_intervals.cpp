/*
 * @Descripttion: 435. 无重叠区间
 * @Author: AruNi
 * @Date: 2022-05-21 21:54:18
 */

/*
题目：
给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。
返回 需要移除区间的最小数量，使剩余区间互不重叠 。

示例 1:
输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。

示例 2:
输入: intervals = [ [1,2], [1,2], [1,2] ]
输出: 2
解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。

示例 3:
输入: intervals = [ [1,2], [2,3] ]
输出: 0
解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
*/

/*
贪心算法：
    局部最优：按照起点排序，选择结尾最短的，后面才可能连接更多的区间（如果两个区间有重叠，应该保留结尾小的） 
    全局最优：选取到了最多的非交叉区间
*/
class Solution {
private:
    // 按照区间start位置排序
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int ans = 0;
        int end = intervals[0][1];      // 先距离第一个区间的end
        for (int i = 1; i < intervals.size(); i++) {
            // 发生重叠了，保留end最小的
            if (intervals[i][0] < end) {
                ans++;
                end = min(intervals[i][1], end);
            } else {    // 没有发生重叠，直接更新end的值就行了
                end = intervals[i][1];
            }
        }
        return ans;
    }
};