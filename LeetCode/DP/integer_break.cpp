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
        dp[i]最大乘积是怎么得到的呢？其实可以从1遍历j，然后有两种渠道得到dp[i]：
        一个是 j*(i-j) 直接相乘
        一个是 j*dp[i-j]，相当于是拆分(i-j)，复用上一层拆分的结果。
        j*(i - j) 是单纯的把整数拆分为两个数相乘，而j*dp[i - j]是拆分成两个以及两个以上的个数相乘
        j怎么就不拆分呢？ j是从1开始遍历，拆分j的情况，在遍历j的过程中其实都计算过了。
        那么从1遍历j，比较(i - j) * j和dp[i - j] * j 取最大的。 
        递推公式：dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
        那么在取最大值的时候，为什么还要比较dp[i]呢？
        因为在递推公式推导的过程中，每改变一次j，就是不同的拆分情况，每次都要计算dp[i]取最大值。
    3. dp的初始化
        严格从dp[i]的定义来说，dp[0] dp[1] 就不应该初始化，也就是没有意义的数值。
        拆分0和拆分1的最大乘积是多少？这是无解的。
        所以只初始化dp[2]=1，从dp[i]的定义来说，拆分数字2，得到的最大乘积是1，这是没有异议的。
    4. 确定遍历顺序
        确定遍历顺序，先来看看递归公式：dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
        dp[i] 是依靠 dp[i - j]的状态，所以遍历i一定是从前向后遍历，先有dp[i - j]再有dp[i]。
        枚举j的时候，是从1开始的。i是从3开始，这样dp[i - j]就是dp[2]正好可以通过我们初始化的数值求出来。
        所以遍历顺序为：
        for (int i = 3; i <=n; i++) {
            for (int j = 1; j < i - 1; j++) {
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            }
        }
    5. 举例推导dp数组
        当n为10时，dp数组中的数值：https://img-blog.csdnimg.cn/20210104173021581.png
        
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
