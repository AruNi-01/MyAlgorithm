/*
 * @Descripttion: 122. 买卖股票的最佳时机 II
 * @Author: AruNi_Lu
 * @Date: 2022-06-05 15:23:43
 */

/*
题目：
给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。
你也可以先购买，然后在 同一天 出售。返回 你能获得的 最大 利润 。

示例 1：
输入：prices = [7,1,5,3,6,4]
输出：7
解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3 。
     总利润为 4 + 3 = 7 。

示例 2：
输入：prices = [1,2,3,4,5]
输出：4
解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
     总利润为 4 。

示例 3：
输入：prices = [7,6,4,3,1]
输出：0
解释：在这种情况下, 交易无法获得正利润，所以不参与交易可以获得最大利润，最大利润为 0 。
*/

/*
此题在贪心专题中使用贪心算法解决过了，这次使用DP来分析一下。
本题和 121. 买卖股票的最佳时机 的唯一区别本题股票可以买卖多次了（注意只有一只股票，所以再次购买前要出售掉之前的股票）
在动规五部曲中，这个区别主要是体现在递推公式上，其他都和 121. 买卖股票的最佳时机 一样。
所以重点分析一下递推公式。
回顾一下dp数组的含义：
    ·dp[i][0] 表示第i天持有股票所得现金。
    ·dp[i][1] 表示第i天不持有股票所得最多现金

如果第i天持有股票即dp[i][0]， 那么可以由两个状态推出来：
    ·第i-1天就持有股票，那么就保持现状，所得现金就是昨天持有股票的所得现金，即：dp[i-1][0]
    ·第i天买入股票，所得现金就是 昨天不持有股票的所得现金 减去 今天的股票价格，即：dp[i-1][1]-prices[i]
注意这里和 121. 买卖股票的最佳时机 唯一不同的地方，就是dp[i][0]的时候，第i天买入股票的情况。
在 121. 买卖股票的最佳时机 中，因为股票全程只能买卖一次，所以如果买入股票，
那么第i天持有股票即dp[i][0]一定就是 -prices[i]。
而本题，因为股票可以买卖多次，所以当第i天买入股票的时候，所持有的现金可能有之前买卖过的利润。
也就是说所得现金会有正数。
那么第i天持有股票即dp[i][0]，如果是第i天买入股票，所得现金就是
昨天不持有股票的所得现金 减去 今天的股票价格 即：dp[i - 1][1] - prices[i]。

再来看看如果第i天不持有股票即dp[i][1]的情况，依然可以由两个状态推出来：
    ·第i-1天就不持有股票，那么就保持现状，所得现金就是昨天不持有股票的所得现金 即：dp[i - 1][1]
    ·第i天卖出股票，所得现金就是按照今天股票佳价格卖出后所得现金即：prices[i] + dp[i - 1][0]
注意这里和 121. 买卖股票的最佳时机 就是一样的逻辑，卖出股票收获利润（可能是负值）天经地义！

其他和 121.买卖股票的最佳时机相同。
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int result = 0;
        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < len; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);     // 与121题不同之处
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
        }
        return dp[len - 1][1];
    }
};