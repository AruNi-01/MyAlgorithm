/*
 * @Descripttion: 343. 整数拆分
 * @Author: AruNi
 * @Date: 2022-05-27 21:37:12
 */


/*
题目：
给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
返回 你可以获得的最大乘积 。
2 <= n <= 58

示例 1:
输入: n = 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。

示例 2:
输入: n = 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
*/

/*
DP五部曲：
    1. 确定dp数组和其下标的含义
        dp[i]：拆分数字i，可以得到最大乘积为dp[i]
    2. 确定递推公式
        dp[i]最大乘积是怎么得到的呢？
        一个是 j*(i-j) 直接相乘
        一个是 j*dp[i-j]，相当于是拆分(i-j)
        j*(i - j) 是单纯的把整数拆分为两个数相乘，而j*dp[i - j]是拆分成两个以及两个以上的个数相乘
    3. dp的初始化
        
*/
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n ; i++) {
            for (int j = 1; j < i - 1; j++) {
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            }
        }
        return dp[n];
    }
};
