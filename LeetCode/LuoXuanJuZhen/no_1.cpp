/*
 * @Descripttion: 59. 螺旋矩阵 II
 * @Author: AruNi
 * @Date: 2022-03-25 22:36:45
 */

/*
题目：
给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix
示例 1：
输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]
1 2 3
8 9 4
7 6 5

示例 2：
输入：n = 1
输出：[[1]]

*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));      //定义二维数组存放结果
        int startx = 0, starty = 0;     //循环的起始位置
        int loop = n / 2;       //圈循环的次数，例如n=3，需要循环一圈(1-n平方)；矩阵中间需要单独处理
        int mid = n / 2;        //矩阵中间位置
        int count = 1;      //给矩阵赋值
        int offset = 1;     //每一圈循环需要控制每一条边遍历的长度，循环完一圈后每条边都要-2；第一次循环只用-1
        int x, y;
        while (loop--) {
            x = startx;
            y = starty;

            //四个for模拟循环一圈（左闭右开）
            //上行从左到右
            for (y = starty; y < starty + n - offset; y++) {
                res[startx][y] = count++;
            }
            //右列从上到下
            for (x = startx; x < startx + n - offset; x++) {
                res[x][y] = count++;
            }
            //下行从右到左
            for (; y > starty; y--) {
                res[x][y] = count++;
            }
            //左列从下到上
            for (; x > startx; x--) {
                res[x][y] = count++;
            }

            //第二圈开始的时候，起始位置要各自加1
            startx++;
            starty++;

            //控制每一圈里每条边遍历的长度，循环完一圈后每条边都要-2
            offset += 2;

        }

        //如果n为奇数，单独给中间位置赋值
        if (n % 2) {
            res[mid][mid] = count;
        }
    
        return res;
    }
}