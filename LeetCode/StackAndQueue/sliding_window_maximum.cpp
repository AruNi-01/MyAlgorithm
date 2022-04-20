/*
 * @Descripttion: 239. 滑动窗口最大值
 * @Author: AruNi
 * @Date: 2022-04-06 22:24:45
 */

/*
题目：给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组
的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
返回 滑动窗口中的最大值 。

示例 1：
输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

示例 2：
输入：nums = [1], k = 1
输出：[1]
*/

/*
单调队列：队列中只保存单调递增或递减的数，例如一个递增的单调队列，当插入一个比队列尾部小的数时，允许其插入
        当插入一个比队列尾部大的数时，则需要将原队列中所有小于该数的数移除，再插入。保证队列一定是递增的！
        最大元素就在队列的头部(前端)

          后端(尾部)              前端(头部)
          ————————————————————————————————
    push->            递增的数             ->pop
          ————————————————————————————————
*/
class Solution {
private:
    //自定义单调队列，从大到小
    class MyQueue {
    public:
        deque<int> que;
        //每次pop的时候，比较当前要弹出的数值是否等于队列出口(前端)元素的数值，相等则弹出
        //因为队列出口放的是最大值，如果队列的最大值已经不在窗口内了，则需要将该最大值移除
        void pop(int value) {
            if (!que.empty() && value == que.front()) {
                que.pop_front();
            }
        }

        //如果push的数值大于入口(后端)元素的数值，则将队列后端的数值弹出，直到push的数值<=队列入口元素的值
        //这样就保持了队列里的数值是单调递增的了
        void push(int value) {
            while (!que.empty() && value > que.back()) {
                que.pop_back();
            }
            que.push_back(value);
        }

        //查询当前队列里的最大值，其实就是队列的前端的值
        int front() {
            return que.front();
        }
    };

public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> res;
        //先将前k个元素放进队列
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        res.push_back(que.front());       //记录前k个元素的最大值

        //从第k+1个元素开始就要进行移除和添加了
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]);       //滑动窗口移除最前面的元素
            que.push(nums[i]);      //滑动窗口添加一个新元素
            res.push_back(que.front());     //每移动一格就记录窗口的最大值
        }
        return res;
    }
};