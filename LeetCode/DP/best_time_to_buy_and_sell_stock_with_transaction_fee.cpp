/*
 * @Descripttion: 714. 买卖股票的最佳时机含手续费
 * @Author: AruNi_Lu
 * @Date: 2022-06-07 16:21:16
 */

/*
题目：
给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。
你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
返回获得利润的最大值。
注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。

示例 1：
输入：prices = [1, 3, 2, 8, 4, 9], fee = 2
输出：8
解释：能够达到的最大利润:  
在此处买入 prices[0] = 1
在此处卖出 prices[3] = 8
在此处买入 prices[4] = 4
在此处卖出 prices[5] = 9
总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8

示例 2：
输入：prices = [1,3,7,5,10,3], fee = 3
输出：6
*/

/*
本题和 121. 买卖股票的最佳时机II 一样，只是多了手续费，只需要在DP的递推公式中，买入的时候把手续费考虑进去就行了。
下面直接给出dp的定义和递推公式：
dp[i][0]：第i天持有股票所拥有的现金
dp[i][1]：第i天不持有股票所拥有的现金

dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);   // 手续费应该在卖出的时候付，保证一次交易付一次
*/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i][0] - prices[i]);
            // 手续费应该在卖出的时候付，保证一次交易付一次
            dp[i][1] = max(dp[i - 1][1], dp[i][1] + prices[i] - fee);
        }
        return dp[prices.size() - 1][1];
    }
};