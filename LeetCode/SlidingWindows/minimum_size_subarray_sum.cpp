/*
 * @Descripttion: 209. 长度最小的子数组
 * @Author: AruNi
 * @Date: 2022-03-21 00:22:49
 */

/*
题目：
给定一个含有 n 个正整数的数组和一个正整数 target 。
找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
 
示例 1：
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。

示例 2：
输入：target = 4, nums = [1,4,4]
输出：1

示例 3：
输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
*/


/*
滑动窗口法：先移动end，在判断区间内的数值和是否满足条件，若不满足end继续往后移，若满足则记录当前窗口的间距，然后移动start。直到end移动到数组尾部，即可找出满足条件的子串长度。
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //INT_MAX是个很大的数，如果想得到数组中最小值，可以先将minn设成INX_MAX,这样就不需要const int定义一个很大的数了
        int res = INT_MAX;
        int start = 0;
        int end = 0;
        int sum = 0;
        int subLength = 0;  //记录窗口长度(连续子串的间距)
        int flag = 1; //flag=1移动end，-1移动start
        while (end < nums.size()) {
            if (nums[end] >= target) return 1;

            if (flag == 1) {
                sum += nums[end];
            } else {
                sum -= nums[start - 1];     //此时start已经向前移动一位了，所有要减去他前一位的值
            }

            if (sum >= target) {
                subLength = end - start + 1;
                res = res > subLength? subLength: res;      //取最小窗口
                start++;      //移动start
                flag = -1;    //更新flag
            } else {
                end++;
                flag = 1;
            }
        }
        //如果res没有被赋值，说明没有满足条件的子串
        return res == INT_MAX? 0: res;
    }
};