/*
 * @Descripttion: 63. 不同路径 II
 * @Author: AruNi
 * @Date: 2022-05-26 17:04:49
 */


/*
题目：
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。
现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
网格中的障碍物和空位置分别用 1 和 0 来表示。

示例 1：
输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
输出：2
解释：3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右

示例 2：
输入：obstacleGrid = [[0,1],[0,0]]
输出：1
*/

/*
思路和 62. 不同路径一样，只是多了障碍，只需要在障碍的位置保持初始值0就行了
DP五部曲：
    1. 确定dp数组和其下标的含义
        dp[i][j]：从（0，0）出发，到（i，j）位置有dp[i][j]种不同的路径。
    2. 确定递推公式
        递推公式和62.不同路径一样，dp[i][j] = dp[i - 1][j] + dp[i][j - 1]。
        但这里需要注意一点，因为有了障碍，(i, j)如果就是障碍的话应该就保持初始状态（初始状态为0）。
        所以代码如下：
        if (obstacleGrid[i][j] == 0) { // 当(i, j)没有障碍的时候，再推导dp[i][j]
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    3. dp数组的初始化
        如果(i, 0) 这条边有了障碍之后，障碍之后（包括障碍）都是走不到的位置了，
        所以障碍之后的dp[i][0]应该还是初始值0。下标(0, j)的初始化情况同理。
        所以初始化代码如下：
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
        注意代码里for循环的终止条件，一旦遇到obstacleGrid[i][0] == 1的情况就停止
        dp[i][0]的赋值1的操作，dp[0][j]同理。
    4. 确定遍历顺序
        从递归公式dp[i][j] = dp[i - 1][j] + dp[i][j - 1] 中可以看出，一定是从左到右一层一层
        遍历，这样保证推导dp[i][j]的时候，dp[i - 1][j] 和 dp[i][j - 1]一定是有数值。
        但注意遇到有障碍的位置continue跳过。
    5. 举例递推dp数组
        用示例1举例：https://img-blog.csdnimg.cn/20210104114548983.png
        对应的dp table 如图：https://img-blog.csdnimg.cn/20210104114610256.png
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // 给上边和左边赋值，一旦遇到有障碍的位置(obstacleGrid位置为1的)就退出循环，停止赋值
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // 遇到障碍直接跳过，不递推，让其位置的dp值为0
                if (obstacleGrid[i][j] == 1) continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};