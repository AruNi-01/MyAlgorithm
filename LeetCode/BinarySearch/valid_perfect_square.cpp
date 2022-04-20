/*
 * @Descripttion: 367.有效的完全平方数
 * @Author: AruNi
 * @Date: 2022-03-20 18:16:55
 */

/*
题目：
给定一个 正整数 num ，编写一个函数，如果 num 是一个完全平方数，则返回 true ，否则返回 false 。
进阶：不要 使用任何内置的库函数，如  sqrt 。

示例 1：
输入：num = 16
输出：true

示例 2：
输入：num = 14
输出：false
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num <= 1) return true;
        int left = 0;
        int right = num;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if (num / mid > mid) {
                left = mid + 1;
            } else if (num / mid < mid) {
                right = mid - 1;
            } else {
                if (num % mid == 0) return true;
                //整数除法会损失精度(结果变小)，所以这里要用left=mid+1
                left = mid + 1;
            }
        }
        return false;
    }
};