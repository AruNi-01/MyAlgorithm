/*
 * @Descripttion: 509. 斐波那契数
 * @Author: AruNi
 * @Date: 2022-05-25 13:57:47
 */

/*
题目：
斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，
后面的每一项数字都是前面两项数字的和。也就是：
F(0) = 0，F(1) = 1
F(n) = F(n - 1) + F(n - 2)，其中 n > 1
给定 n ，请计算 F(n) 。

示例 1：
输入：n = 2
输出：1
解释：F(2) = F(1) + F(0) = 1 + 0 = 1

示例 2：
输入：n = 3
输出：2
解释：F(3) = F(2) + F(1) = 1 + 1 = 2

示例 3：
输入：n = 4
输出：3
解释：F(4) = F(3) + F(2) = 2 + 1 = 3
*/

/*
DP 五部曲：
    1. 确定dp数组和其下标的含义
        dp[i]：第 i 个数的斐波那契数值是 dp[i]
    2. 确定递推公式
        状态转移方程：dp[i] = dp[i - 1] + dp[i - 2]
    3. dp数组如何初始化
        dp[0] = 0;  dp[1] = 1;
    4. 确定遍历顺序
        从递推公式 dp[i] = dp[i - 1] + dp[i - 2]; 可以看出，dp[i] 是依赖 dp[i - 1] 和 dp[i - 2]，
        那么遍历顺序一定是从前往后的。
    5. 举例推导dp数组
        按照递推公式 dp[i] = dp[i - 1] + dp[i - 2]，推导当N为10的时候，dp数组应该是如下的数列：
        0 1 1 2 3 5 8 13 21 34 55

如果代码写出来，发现结果不对，就把dp数组打印出来看看和我们推导的数列是不是一致的。
*/
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
// 时间复杂度：O(n); 空间复杂度：O(n)

// 可以只维护2个数值，不需要记录整个序列，这样可以节约一些空间内存
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int dp[2];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};
// 时间复杂度：O(n); 空间复杂度：O(1)

// 递归法
class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        return fib(n - 1) + fib(n - 2);
    }
};
//时间复杂度：O(2^n); 空间复杂度：O(n)
