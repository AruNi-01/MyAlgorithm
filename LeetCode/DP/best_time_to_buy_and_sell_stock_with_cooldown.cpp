/*
 * @Descripttion: 309. 最佳买卖股票时机含冷冻期
 * @Author: AruNi_Lu
 * @Date: 2022-06-07 16:19:04
 */


/*
题目：
给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​
设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
    卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:
输入: prices = [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]

示例 2:
输入: prices = [1]
输出: 0
*/

/*
相对于 122.买卖股票的最佳时机II，本题加上了一个冷冻期
在 122.买卖股票的最佳时机II 中有两个状态，持有股票后的最多现金，和不持有股票的最多现金。

DP五部曲，分析如下：

    1. 确定dp数组以及下标的含义
        dp[i][j]，第i天状态为j，所剩的最多现金为dp[i][j]。
        其实本题难点在于出现冷冻期之后，状态其实是比较复杂度，例如今天买入股票、今天卖出股票、今天是冷冻期，都是不能操作股票的。 
        具体可以区分出如下四个状态：
            ·状态一：买入股票状态（今天买入股票，或者是之前就买入了股票然后没有操作）
            卖出股票状态，这里就有两种卖出股票状态：
                ·状态二：两天前就卖出了股票，度过了冷冻期，一直没操作，今天保持卖出股票状态
                ·状态三：今天卖出了股票
            ·状态四：今天为冷冻期状态，但冷冻期状态不可持续，只有一天！
        j的状态为：
            0：状态一
            1：状态二
            2：状态三
            3：状态四
        注意这里的每一个状态，例如状态一，是买入股票状态并不是说今天已经就买入股票，而是说保存买入股票的状态即：
        可能是前几天买入的，之后一直没操作，所以保持买入股票的状态。
    2. 确定递推公式
        a) 达到买入股票状态（状态一）即：dp[i][0]，有两个具体操作：
            操作一：前一天就是持有股票状态（状态一），dp[i][0] = dp[i - 1][0]
            操作二：今天买入了，有两种情况：
                前一天是冷冻期（状态四），dp[i - 1][3] - prices[i]
                前一天是保持卖出股票状态（状态二），dp[i - 1][1] - prices[i]
        所以操作二取最大值，即：max(dp[i - 1][3], dp[i - 1][1]) - prices[i]
        那么dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3], dp[i - 1][1]) - prices[i]);

        b) 达到保持卖出股票状态（状态二）即：dp[i][1]，有两个具体操作：
            操作一：前一天就是状态二
            操作二：前一天是冷冻期（状态四）
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);

        c) 达到今天就卖出股票状态（状态三），即：dp[i][2] ，只有一个操作：
            操作一：昨天一定是买入股票状态（状态一），今天卖出
        即：dp[i][2] = dp[i - 1][0] + prices[i];

        d) 达到冷冻期状态（状态四），即：dp[i][3]，只有一个操作：
            操作一：昨天卖出了股票（状态三）
        dp[i][3] = dp[i - 1][2];

        综上分析，递推代码如下：
        dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3], dp[i - 1][1]) - prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
        dp[i][2] = dp[i - 1][0] + prices[i];
        dp[i][3] = dp[i - 1][2];

    3. dp数组如何初始化
        这里主要讨论一下第0天如何初始化。
        如果是持有股票状态（状态一）那么：dp[0][0] = -prices[0]，买入股票所剩现金为负数。
        保持卖出股票状态（状态二），第0天没有卖出dp[0][1]初始化为0就行，
        今天卖出了股票（状态三），同样dp[0][2]初始化为0，因为最少收益就是0，绝不会是负数。
        同理dp[0][3]也初始为0。
    4. 确定遍历顺序
        从递归公式上可以看出，dp[i] 依赖于 dp[i-1]，所以是从前向后遍历。
    5. 举例推导dp数组
        以 [1,2,3,0,2] 为例，dp数组如图：https://img-blog.csdnimg.cn/2021032317451040.png
        最后结果是取 状态二，状态三，和状态四的最大值，不少同学会把状态四忘了，状态四是冷冻期，最后一天如果是冷冻期也可能是最大值。
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3], dp[i - 1][1]) - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            dp[i][3] = dp[i - 1][2];
        }
        return max({dp[prices.size() - 1][1], dp[prices.size() - 1][2], dp[prices.size() - 1][3]});
    }
};