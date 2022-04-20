/*
 * @Descripttion: 剑指 Offer 29. 顺时针打印矩阵（与54题相同）
 * @Author: AruNi
 * @Date: 2022-03-26 00:09:08
 */

/*
题目：
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]

示例 2：
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //当矩阵为空或者 矩阵不为空，但含有一行为空的vector<int>时，
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }

        vector<int> res;
        //计算出矩阵几行几列
        int m = matrix.size(), n = matrix[0].size();
        //确定上下左右四条边的位置
        int up = 0, down = m - 1, left = 0, right = n - 1;
        while (true) {
            //上边从左到右遍历元素
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[up][i]);
            }
            if (++up > down) break;     //上边下移一位，判断是否大于下边的位置

            //右边从上到下遍历元素
            for (int i = up; i <= down; i++) {
                res.push_back(matrix[i][right]);
            }
            if (--right < left) break;      //右边左移一位，判断是否小于左边的位置

            //下边从右到左遍历元素
            for (int i = right; i >= left; i--) {
                res.push_back(matrix[down][i]);
            }
            if (--down < up) break;         //下边上移一位，判断是否小于上边位置

            //左边从下到上遍历元素
            for (int i = down; i >= up; i--) {
                res.push_back(matrix[i][left]);
            }
            if (++left > right) break;      //左边右移一位，判断是否大于右边位置
        }
        return res;
    }
};
