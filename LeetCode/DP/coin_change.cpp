/*
 * @Descripttion: 322. 零钱兑换
 * @Author: AruNi
 * @Date: 2022-06-02 21:17:09
 */

/*
题目：
给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
你可以认为每种硬币的数量是无限的。

示例 1：
输入：coins = [1, 2, 5], amount = 11
输出：3 
解释：11 = 5 + 5 + 1

示例 2：
输入：coins = [2], amount = 3
输出：-1
*/

/*
和 518.零钱兑换II 中兑换零钱不一样。
题目中说每种硬币的数量是无限的，可以看出是典型的完全背包问题。

DP五部曲：
    1. 确定dp数组和其下标含义
        dp[j]：凑足总额为j 所需硬币的最少个数为dp[j]。
    2. 确定递推公式
        dp[j]（考虑coins[i]）只有一个来源：dp[j - coins[i]]（没有考虑coins[i]）。
        凑足总额为j - coins[i]的最少个数为dp[j - coins[i]]，那么只需要加上一个钱币coins[i]，
        即dp[j - coins[i]] + 1就是dp[j]（考虑coins[i]）
        所以dp[j] 要取所有 dp[j - coins[i]] + 1 中最小的。
        递推公式：dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
    3. dp数组的初始化
        首先凑足总金额为0所需的硬币个数一定是0，那么dp[0]=0;
        其他下标对应的数值如何初始化？
        考虑到递推公式的特性，dp[j]必须初始化为一个最大的数，否则在取最小值时会被初始值影响。
        所以非0下标的元素值都应该是最大值。代码如下：
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
    4. 确定遍历顺序
        本题求钱币最小个数，那么钱币有顺序和没有顺序都可以，都不影响钱币的最小个数。
        所以本题并不强调集合是组合还是排列。
        如果求组合数就是外层for循环遍历物品，内层for遍历背包。
        如果求排列数就是外层for遍历背包，内层for循环遍历物品。
        在动态规划专题中求组合数是 518.零钱兑换II，求排列数是 377. 组合总和 Ⅳ。
        所以本题的两个for循环的关系是：
        外层for循环遍历物品，内层for遍历背包 或者 外层for遍历背包，内层for循环遍历物品都是可以的！
        本题钱币数量可以无限使用，那么是完全背包。所以遍历的内循环是正序
        综上所述，遍历顺序为：coins（物品）放在外循环，target（背包）在内循环。且内循环正序。
    5. 举例推导dp数组
        输入：coins=[1,2,5]，amount=5，dp数组：https://img-blog.csdnimg.cn/20210201111833906.jpg
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {        // 遍历物品
            for (int j = coins[i]; j <= amount; j++) {         // 遍历背包
                if (dp[j - coins[i]] != INT_MAX) {      // 如果dp[j - coins[i]]是初始值则跳过，没有必要选择
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);   
                }
            }
        }
        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};

// 遍历背包放在外循环，遍历物品放在内循环：
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {     // 遍历背包
            for (int j = 0; j < coins.size(); j++) {    // 遍历物品
                if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX ) {
                    dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
                }
            }
        }
        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};
