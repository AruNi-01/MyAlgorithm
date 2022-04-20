/*
 * @Descripttion: 347. 前 K 个高频元素
 * @Author: AruNi
 * @Date: 2022-04-06 23:54:01
 */

/*
题目：
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

示例 1:
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]

示例 2:
输入: nums = [1], k = 1
输出: [1]
*/

/*
思路：
首先统计元素出现的频率，这一类的问题可以使用map来进行统计。
然后是对频率进行排序，这里可以使用一种容器适配器就是优先级队列
优先队列：其实就是一个堆，因为优先级队列对外接口只是从队头取元素，从队尾添加元素，
         再无其他取元素的方式，看起来就是一个队列。

堆：
大顶堆（堆头是最大元素），小顶堆（堆头是最小元素），不想自己实现堆，可以直接用priority_queue（优先级队列）
，底层实现都是一样的，从小到大排就是小顶堆，从大到小排就是大顶堆。
这道题使用小顶堆，因为要统计最大前k个元素，只有小顶堆每次将最小的元素从顶部弹出，最后小顶堆里积累的才是前k个最大元素

关于优先队列的前置知识：
定义：priority_queue<Type, Container, Functional>
     Type 就是数据类型，Container 就是容器类型（Container必须是用数组实现的容器，比如vector,deque等等，
     但不能用 list。STL里面默认用的是vector），Functional 就是比较的方式，当需要用自定义的数据类型时才
     需要传入这三个参数，使用基本数据类型时，只需要传入数据类型，默认是大顶堆
*/
class Solution {
public:

    // 优先队列 -- 小顶堆
    class MyComparison {
    public:
        // 重载方法，因为优先队列默认是从小到大排序的，我们pair的key为元素，value为频率
        bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) {
            // 按频率降序
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 统计元素出现的频率
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // 按频率对元素排序
        // 定义一个小顶堆(优先队列)，大小为k；至于为什么这样定义看前面的优先队列知识
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyComparison> pri_que;

        // 用固定大小为k的小顶堆，扫描所有频率的数值
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            // 若堆的size大于k，则将队列顶部频率最小的元素弹出，保证堆的size一直为k
            if (pri_que.size() > k) {
                pri_que.pop();
            }
        }

        // 找出了前k个高频的元素；因为是小顶堆，所以最大的元素在最下面，倒叙输出到数组
        vector<int> res(k);
        for (int i = k - 1; i >= 0; i--) {
            res[i] = pri_que.top().first;   //取堆顶元素的key(元素值)
            pri_que.pop();
        }
        return res;
    }
};