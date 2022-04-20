/*
 * @Descripttion: 69.x的平方根 
 * @Author: AruNi
 * @Date: 2022-03-20 18:15:14
 */

/*
题目：
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。

示例 1：
输入：x = 4
输出：2

示例 2：
输入：x = 8
输出：2
解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
*/

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int min = 0, max = x;
        while (min <= max) {
            int mid = min + (max - min) / 2;
            if (x/mid < mid) {
                max = mid - 1;
            } else if(x/mid > mid){
                min = mid + 1;
            } else {
                return mid;
            }
        }
        return max;
    }
};