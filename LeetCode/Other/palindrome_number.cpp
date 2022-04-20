/*
 * @Descripttion: 9. 回文数
 * @Author: AruNi
 * @Date: 2022-04-03 23:59:06
 */

/*
题目：
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1：
输入：x = 121
输出：true

示例 2：
输入：x = -121
输出：false
解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

示例 3：
输入：x = 10
输出：false
解释：从右向左读, 为 01 。因此它不是一个回文数
*/

//Solution 1：利用字符串
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        reverse(s.begin(), s.end());
        return s==to_string(x);
    }
};

//Solution 2：利用数学方法，直接将整数进行反转
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        long res = 0;
        int y = x;
        //把x倒置表示成res，比较二者是否相同
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return (int)res == y? true: false;
    }
};