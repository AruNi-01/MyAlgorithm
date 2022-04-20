/*
 * @Descripttion: 904. 水果成篮
 * @Author: AruNi
 * @Date: 2022-03-22 16:04:09
 */

/*
题目：
你正在探访一家农场，农场从左到右种植了一排果树。这些树用一个整数数组fruits表示，其中 fruits[i] 是第 i棵树上的水果种类 。
你想要尽可能多地收集水果。然而，农场的主人设定了一些严格的规矩，你必须按照要求采摘水果：
    你只有 两个 篮子，并且每个篮子只能装 单一类型 的水果。每个篮子能够装的水果总量没有限制。
    你可以选择任意一棵树开始采摘，你必须从 每棵 树（包括开始采摘的树）上 恰好摘一个水果 。采摘的水果应当符合篮子中的水果类型。每采摘一次，你将会向右移动到下一棵树，并继续采摘。
    一旦你走到某棵树前，但水果不符合篮子的水果类型，那么就必须停止采摘。
给你一个整数数组 fruits ，返回你可以收集的水果的最大数目。

 

示例 1：
输入：fruits = [1,2,1]
输出：3
解释：可以采摘全部 3 棵树。

示例 2：
输入：fruits = [0,1,2,2]
输出：3
解释：可以采摘 [1,2,2] 这三棵树。
如果从第一棵树开始采摘，则只能采摘 [0,1] 这两棵树。

示例 3：
输入：fruits = [1,2,3,2,2]
输出：4
解释：可以采摘 [2,3,2,2] 这四棵树。
如果从第一棵树开始采摘，则只能采摘 [1,2] 这两棵树。

示例 4：
输入：fruits = [3,3,3,1,2,1,1,2,3,3,4]
输出：5
解释：可以采摘 [1,2,1,1,2] 这五棵树。
*/

//滑动窗口法：先指定两个篮子的水果类型，人后快指针先移动，当出现第三类水果时应该直接把慢指针放到快指针的前一步，再慢慢回退找齐所有同类，这样才能保证连续
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int right = 0;
        int basketOne = fruits[left];        //篮子一号
        int basketTwo = fruits[right];          //篮子二号
        int res = 0;
        while(right < fruits.size()) {
            if (fruits[right] == basketOne || fruits[right] == basketTwo) {     //当快指针指向属于篮子种类的水果
                res = max(res, right + 1 - left);       //更新长度
                right++;
            } else {
                left = right - 1;       //出现第三类水果，将慢指针移动到快指针前一个位置，保证只有两类水果
                basketOne = fruits[left];       //更新一号篮子水果的种类

                //再将慢指针回退，当慢指针的前一个位置刚好不等于一号篮子水果的种类的时候，退出循环
                while (left >= 1 && fruits[left - 1] == basketOne) {    //left>=1是防止后面的[left-1]溢出
                    left--;
                }

                basketTwo = fruits[right];      //更新二号篮子水果的种类
                res = max(res, right + 1 - left);        //重新更新长度
            }
        }
        return res;
    }
};