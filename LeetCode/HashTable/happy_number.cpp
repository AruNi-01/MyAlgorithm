/*
 * @Descripttion: 202. 快乐数
 * @Author: AruNi
 * @Date: 2022-03-31 14:48:08
 */

/*
题目：
编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」 定义为：
    对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
    然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
    如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

示例 1：
输入：n = 19
输出：true
解释：
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1

示例 2：
输入：n = 2
输出：false
*/

//题目中说了会无限循环，那么也就是说求和的过程中，sum会重复出现
//哈希法：判断这个sum是否重复出现，如果重复了就是return false，否则一直找到sum为1为止。
//取到该数每一位上的数值，可以每次只取个位，然后再将该数➗10，循环到n<=0
class Solution {
public:

    //求该数每一位上的数值平方之和
    int  getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);     //个位数平方
            n /= 10;        //更新个位数
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> set;     //用unordered_set来储存所以sum集合，便于判断sum是否重复出现
        while (true) {
            int sum = getSum(n);
            if (sum == 1) {
                return true;
            }

            //如果这个sum曾经出现过，说明已经陷入了无限循环了，立刻return false
            if (set.find(sum) != set.end()) {
                return false;
            } else {
                set.insert(sum);        //这个sum未出现过，存进set集合中
            }
            n = sum;    //更新n的值
        }
    }
};