/*
 * @Descripttion: 232. 用栈实现队列
 * @Author: AruNi
 * @Date: 2022-04-04 22:27:53
 */

/*
题目：
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
实现 MyQueue 类：
    void push(int x) 将元素 x 推到队列的末尾
    int pop() 从队列的开头移除并返回元素
    int peek() 返回队列开头的元素
    boolean empty() 如果队列为空，返回 true ；否则，返回 false
说明：
    你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
    你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。

示例 1：
输入：
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
输出：
[null, null, null, 1, 1, false]
解释：
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
*/

class MyQueue {
public:
    //定义一个入栈，一个出栈
    stack<int> stIn;
    stack<int> stOut;
    
    MyQueue() {
    }
    
    void push(int x) {
        stIn.push(x); 
    }
    
    int pop() {
        //当出栈为空时，需要将所有入栈里的数导入出栈里
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());     //入栈的栈顶元素在出栈的栈尾，这样才满足队列的先进先出
                stIn.pop();
            }
        }
        int res = stOut.top();
        stOut.pop();
        return res;
    }
    
    int peek() {
        int res = this->pop();      //直接使用已有的pop函数
        stOut.push(res); 
        return res;
    }
    
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */