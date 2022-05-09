/*
 * @Descripttion: 链栈的实现
 * @Author: AruNi
 * @Date: 2022-03-20 21:39:12
 */
#include<iostream>
using namespace std;
typedef int ElemType;

struct Node{
    ElemType data;
    struct Node *next;
};

//初始化
void InitStack(Node *stk) {
    stk = new Node;     //创建头结点
    stk->next = NULL;
}

//入栈
void Push(Node *stk, ElemType e) {
    Node *p = new Node;     //新创建一个结点给当前入栈元素
    //采用头插法 入栈
    p->data = e;
    p->next = stk ->next;   //使新结点的next指向栈顶的next，即栈顶第一个结点位置
    stk->next = p;      //再将栈顶的next指向新结点

}

//出栈
bool Pop(Node *stk) {
    if (stk->next == NULL) {
        cout<<"error, stack is null"<<endl;
        return false;
    }
    Node *p = stk->next;    //新节点指向栈顶第一个元素的位置
    ElemType e = p->data;
    cout<<"pop stack elem is: "<<e<<endl;
    stk->next = p->next;    //删除栈顶第一个元素位置的结点
    delete[] p;
    return true;
}

//获取栈顶元素
ElemType GetTop(Node *stk) {
    return (stk->next->data);
}

//遍历栈
void PrintStack(Node *stk) {
    Node *p = stk->next;
    while (p != NULL) {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}


int main() {
    Node stack;
    InitStack(&stack);
    Push(&stack, 1);
    Push(&stack, 2);
    Push(&stack, 3);
    ElemType e = GetTop(&stack);
    cout<<"stack top elem is: "<<e<<endl;
    //PrintStack(&stack);

    Pop(&stack);
    ElemType e2 = GetTop(&stack);
    cout<<"stack top elem is: "<<e2<<endl;

    //PrintStack(&stack);
    system("pause");
    return 0;
}