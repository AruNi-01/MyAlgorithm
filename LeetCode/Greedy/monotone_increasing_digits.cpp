/*
 * @Descripttion: 738. 单调递增的数字
 * @Author: AruNi
 * @Date: 2022-05-23 23:20:24
 */

/*
题目：
当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。
给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增 。

示例 1:
输入: n = 10
输出: 9

示例 2:
输入: n = 1234
输出: 1234

示例 3:
输入: n = 332
输出: 299
*/

/*
题目要求小于等于N的最大单调递增的整数，那么拿一个两位的数字来举例。
例如：98，一旦出现strNum[i - 1] > strNum[i]的情况（非单调递增），首先想让strNum[i - 1]--，
然后strNum[i]给为9，这样这个整数就是89，即小于98的最大的单调递增整数。

贪心算法：
    局部最优：遇到strNum[i - 1] > strNum[i]的情况，让strNum[i - 1]--，然后strNum[i]给为9，
             可以保证这两位变成最大单调递增整数。
    全局最优：得到小于等于N的最大单调递增的整数。
遍历顺序：
    从前向后遍历会改变已经遍历过的结果，举个例子，数字：332，从前向后遍历的话，那么就把332变成了329，
    此时2又小于了第一位的3了，真正的结果应该是299。
    那么从后向前遍历，就可以重复利用上次比较得出的结果了，从后向前遍历332的数值变化为：332 -> 329 -> 299
*/
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string strNum = to_string(n);
        // flag用来标记赋值 9 从哪里开始
        int flag = strNum.size();
        for (int i = strNum.size() - 1; i > 0; i--) {
            if (strNum[i - 1] > strNum[i]) {
                flag = i;   // 只要出现了非递增的情况，就要记录赋值 9 的位置
                strNum[i - 1]--;
            }
        }
        // 从flag开始都赋值为 9
        for (int i = flag; i < strNum.size(); i++) {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
};
