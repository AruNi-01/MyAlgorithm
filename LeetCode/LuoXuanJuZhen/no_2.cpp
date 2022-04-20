/*
 * @Descripttion: 54. 螺旋矩阵
 * @Author: AruNi
 * @Date: 2022-03-25 23:09:26
 */

/*
题目描述：
给你一个 m 行 n 列的矩阵 matrix ，请按照顺时针螺旋顺序 ，返回矩阵中的所有元素。
示例1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
1 2 3
4 5 6
7 8 9

示例2：
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
*/

/*思路：首先确定上下左右四条边的位置，然后while循环遍历上边，将所有元素结果加入res，然后
上边下移一位，如果上边没有大于下边，说明下面还有元素，接着遍历右边，将元素加入res；如果此
时上边大于下边，说明此时已经遍历完成了，直接break； 其实就是绕着矩阵的边依次填装元素！
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