/*
 * @Descripttion: 1049. 最后一块石头的重量 II
 * @Author: AruNi
 * @Date: 2022-05-30 21:42:36
 */


/*
题目：
有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。
每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
    如果 x == y，那么两块石头都会被完全粉碎；
    如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。

示例 1：
输入：stones = [2,7,4,1,8,1]
输出：1
解释：
组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。

示例 2：
输入：stones = [31,26,33,21,40]
输出：5
*/

/*
思路：
本题其实就是尽量让石头分成重量相同的两堆，相撞之后剩下的石头最小，这样就化解成01背包问题了。
是不是感觉和416. 分割等和子集非常像了。
本题物品的重量为store[i]，物品的价值也为store[i]。
对应着01背包里的物品重量weight[i]和 物品价值value[i]。

dp五部曲：
    1. 确定dp数组和其下标的含义
        dp[j]表示容量（重量）为j的背包，最多可以背重量为dp[i]的石头
    2. 确定递推公式
        01背包的递推公式为：dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        本题则是：dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
    3. dp数组的初始化
        既然 dp[j]中的j表示容量，那么最大容量（重量）是多少呢，就是所有石头的重量和。
        因为提示中给出1 <= stones.length <= 30，1 <= stones[i] <= 1000，所以最大重量就是30 * 1000 。
        而我们要求的target其实只是最大重量的一半，所以dp数组开到15000大小就可以了。
        当然也可以把石头遍历一遍，计算出石头总重量 然后除2，得到dp数组的大小。
        为了方便就直接用15000了。
        接下来就是如何初始化dp[j]呢，因为重量都不会是负数，所以dp[j]都初始化为0就可以了，
        这样在递归公式dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);中dp[j]才不
        会初始值所覆盖。
        代码为：vector<int> dp(15001, 0);
    4. 确定遍历顺序
        如果使用一维dp数组，物品遍历的for循环放在外层，遍历背包的for循环放在内层，且内层for循环倒序遍历！
        代码如下：
        for (int i = 0; i < stones.size(); i++) {   // 遍历石头
            for (int j = target; i >= stones[i]; j--) {     // 遍历背包
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
    5. 举例推导dp数组
        举例，输入：[2,4,1,1]，此时target = (2+4+1+1)/2 = 4，dp数组状态图：https://img-blog.csdnimg.cn/20210121115805904.jpg
        最后dp[target]里是容量为target的背包所能背的最大重量。

    那么分成两堆石头，一堆石头的总重量是dp[target]，另一堆就是sum - dp[target]。
    在计算target的时候，target = sum / 2 因为是向下取整，所以sum - dp[target] 一定是大于等于dp[target]的。
    那么相撞之后剩下的最小石头重量就是 (sum - dp[target]) - dp[target]。
*/      
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<int> dp(15001, 0);
        int sum = 0;
        // 先计算出全部石头的重量，后续计算要用
        for (int i = 0; i < stones.size(); i++) sum += stones[i];
        // 要尽量让石头分成重量相同的两堆
        int target = sum / 2;
        for (int i = 0; i < stones.size(); i++) {
            for (int j = target; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        // 因为target = sum / 2; 是向下取整，所以sum-dp[target]这堆石头 <= dp[target]这堆石头的
        // 用大的一堆石头减小的一堆石头，得到剩下的石头重量
        return (sum - dp[target]) - dp[target];
    }
};