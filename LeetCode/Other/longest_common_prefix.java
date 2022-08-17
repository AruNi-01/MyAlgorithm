/*
 * @Descripttion: 14. 最长公共前缀
 * @Author: AruNi_Lu
 * @Date: 2022-06-21 22:02:42
 */

/*
题目：
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。

示例 1：
输入：strs = ["flower","flow","flight"]
输出："fl"

示例 2：
输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
*/

class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) return "";
        // 公共前缀比所有字符都短，先随便选一个
        String res = strs[0];
        for (String str : strs) {
            // 当遍历的字符串不是以公共前缀开始时，让公共前缀变短
            while (!str.startsWith(res)) {
                res = res.substring(0, res.length() - 1);
            }
        }
        return res;
    }
}