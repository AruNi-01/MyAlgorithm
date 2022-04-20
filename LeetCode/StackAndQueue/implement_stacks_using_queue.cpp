/*
 * @Descripttion: 225. 用队列实现栈
 * @Author: AruNi
 * @Date: 2022-04-04 22:27:53
 */

/*
题目：
请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
实现 MyStack 类：
    void push(int x) 将元素 x 压入栈顶。
    int pop() 移除并返回栈顶元素。
    int top() 返回栈顶元素。
    boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
注意：
    你只能使用队列的基本操作 —— 也就是 push to back、peek/pop from front、size 和 is empty 这些操作。
    你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
示例：
输入：
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
输出：
[null, null, null, 2, 2, false]

解释：
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // 返回 2
myStack.pop(); // 返回 2
myStack.empty(); // 返回 False
*/

//思路：一个队列在模拟栈弹出元素的时候只要将队列头部的元素（除了最后一个元素外） 重新添加到队列尾部，此时在去弹出元素就是栈的顺序了
class MyQueue {
public:
    queue<int> que;

    MyStack() {
        
    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        int size = que.size();
        size--;
        //将队列头部元素(除了最后一个) 重写添加到队列尾部
        while (size--) {
            que.push(que.front()); 
            que.pop();
        }
        int res = que.front();  //此时弹出的元素顺序就是栈的顺序了
        que.pop();
        return res;
    }
    
    int top() {
        return que.back();
    }
    
    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */