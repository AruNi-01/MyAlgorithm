/*
 * @Descripttion: 1143. 最长公共子序列
 * @Author: AruNi_Lu
 * @Date: 2022-06-10 15:22:11
 */

/*
题目：
给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。
一个字符串的 子序列 是指这样一个新的字符串：
    它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。

示例 1：
输入：text1 = "abcde", text2 = "ace" 
输出：3  
解释：最长公共子序列是 "ace" ，它的长度为 3 。

示例 2：
输入：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共子序列是 "abc" ，它的长度为 3 。

示例 3：
输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0 。
*/

/*
本题和 718. 最长重复子数组 区别在于这里不要求是连续的了，但要有相对顺序。
DP五部曲：
    1. 确定dp数组和其下标含义
        dp[i][j]：长度为[0,i-1]的字符串text1与长度为[0,j-1]的字符串text2的最长公共子序列为dp[i][j]。
        为什么要定义长度为[0, i - 1]的字符串text1，定义为长度为[0, i]的字符串text1不行么？
        这样定义是为了后面代码实现方便，如果非要定义为为长度为[0, i]的字符串text1也可以。
    2. 确定递推公式
        主要就是两大情况：
        如果text1[i - 1] 与 text2[j - 1]相同，那么找到了一个公共元素，所以dp[i][j] = dp[i - 1][j - 1] + 1;
        如果text1[i - 1] 与 text2[j - 1]不相同，那就看看text1[0, i - 2]与text2[0, j - 1]的最长公共子序列 
        和 text1[0, i - 1]与text2[0, j - 2]的最长公共子序列，取最大的。
        即：dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        代码如下：
        if (text1[i - 1] == text2[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    3. dp数组的初始化
        先看看dp[i][0]应该是多少呢？
        test1[0, i-1]和空串的最长公共子序列自然是0，所以dp[i][0] = 0;
        同理dp[0][j]也是0。
        其他下标都是随着递推公式逐步覆盖，初始为多少都可以，那么就统一初始为0。
    4. 确定遍历顺序
        从递推公式，可以看出，有三个方向可以推出dp[i][j]，如下：
        dp[i-1][j-1]    dp[i-1][j]
        dp[i][j-1]      dp[i][j]
        那么为了在递推的过程中，这三个方向都是经过计算的数值，所以要从前向后，从上到下来遍历这个矩阵。
    5. 举例推导dp数组
        以输入：text1 = "abcde", text2 = "ace" 为例，dp状态如图：https://img-blog.csdnimg.cn/20210210150215918.jpg
        最后红框dp[text1.size()][text2.size()]为最终结果
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};