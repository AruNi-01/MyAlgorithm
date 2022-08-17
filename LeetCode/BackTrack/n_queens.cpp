/*
 * @Descripttion: 51. N 皇后
 * @Author: AruNi
 * @Date: 2022-05-16 23:44:16
 */

/*
题目：
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例 1：
https://assets.leetcode.com/uploads/2020/11/13/queens.jpg
输入：n = 4
输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
解释：如上图所示，4 皇后问题存在两个不同的解法。

示例 2：
输入：n = 1
输出：[["Q"]]
*/

/*
思路：
    1.皇后们的约束条件：
        ·不能同行
        ·不能同列
        ·不能同斜线

    2.搜索皇后的位置，可以抽象为一棵树：
        用一个 3 * 3 的棋盘，将搜索过程抽象为一棵树，如图：https://img-blog.csdnimg.cn/20210130182532303.jpg
        从图中可以看出，二维矩阵中矩阵的高就是这棵树的高度，矩阵的宽就是树形结构中每一个节点的宽度。

    3.用皇后们的约束条件，来回溯搜索这棵树，只要搜索到了树的叶子节点，说明就找到了皇后们的合理位置了。
*/
class Solution {
private:
    vector<vector<string>> result;
    // n: 棋盘的大小；row: 记录当前遍历到棋盘的第几层了
    void backtrack(int n, int row, vector<string>& chessboard) {
        // 递归到棋盘最底层（叶子节点），就可以收集结果并返回了
        if (row == n) {
            result.push_back(chessboard);
            return;
        }

        // 递归深度就是row控制棋盘的行，每一层里for循环的col控制棋盘的列，一行一列，确定了放置皇后的位置。
        // 每次都是要从新的一行的起始位置开始搜，所以都是从0开始。
        for (int col = 0; col < n; col++) {
            if (isValid(row, col, chessboard, n)) {     // 验证合法就可以把皇后放进棋盘中
                chessboard[row][col] = 'Q';     // 放置皇后
                backtrack(n, row + 1, chessboard);      // row + 1；递归下一层
                chessboard[row][col] = '.';     // 回溯，撤销皇后
            }
        }
    }

    // 验证棋盘是否合法
    bool isValid(int row, int col, vector<string>& chessboard, int n) {
        // 因为在单层搜索的过程中，每一层递归，只会选for循环（也就是同一行）里的一个元素，所以不用对同行去重了。

        // 检查列(该位置的上方)是否有皇后
        for (int i = 0; i < row; i++) {
            if (chessboard[i][col] == 'Q') {
                return false;
            }
        }

        // 检查 45°角(该位置的左上斜线)是否有皇后
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }

        // 检查135°角(该位置的右上斜线)是否有皇后
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard(n, string(n, '.'));   // 先将棋盘全部置为空 '.'
        backtrack(n, 0, chessboard);
        return result;
    }
};