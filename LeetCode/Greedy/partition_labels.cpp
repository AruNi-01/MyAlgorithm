/*
 * @Descripttion: 763. 划分字母区间
 * @Author: AruNi
 * @Date: 2022-05-22 17:54:18
 */

/*
题目：
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，
同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。

示例：
输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
*/

/*
思路：
    同一字母最多出现在一个片段中，就是把同一个字母的都圈在同一个区间里。
    在遍历的过程中相当于是要找每一个字母的边界，如果找到之前遍历过的所有字母的最远边界，
    说明这个边界就是分割点了。此时前面出现过所有字母，最远也就到这个边界了。
步骤：
    统计每一个字符最后出现的位置
    从头遍历字符，并更新字符的最远出现下标，如果找到字符最远出现位置下标和当前下标相等了，则找到了分割点
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[27] = {0}; // i为字符，hash[i]为字符出现的最后位置
        for (int i = 0; i < s.size(); i++) { // 统计每一个字符最后出现的位置
            hash[s[i] - 'a'] = i;
        }
        vector<int> result;
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); i++) {
            right = max(right, hash[s[i] - 'a']); // 找到字符出现的最远边界
            if (i == right) {
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return result;
    }
};