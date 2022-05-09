/*
 * @Descripttion: 顺序栈的实现
 * @Author: AruNi
 * @Date: 2022-03-20 20:47:21
 */

#include<iostream>
using namespace std;
#define MaxSize 50
typedef int ElemType;

typedef struct {
    ElemType *base;  //栈底指针
    ElemType *top;   //栈顶指针，初始指向栈底。
    ElemType stackSize;  //容量
}orderStack;

//初始化
bool InitStack(orderStack *s) {
    s->base = new ElemType[MaxSize];
    if (!s->base) {
        exit(0);
    }
    s->top = s->base;
    s->stackSize = MaxSize;
    return true;
}

//入栈
bool Push(orderStack *s, ElemType e) {
    if (s->top - s->base == s->stackSize) {
        cout<<"error, stack is full"<<endl;
        return false;
    }
    *(s->top++) = e;    //压入元素，然后将栈顶指针上移，使栈顶指针空指
    return true;
}

//出栈
bool Pop(orderStack *s) {
    if (s->top == s->base) {
        cout<<"error, stack is null"<<endl;
        return false;
    }
    s->top--;       //栈顶指针下移一位，指向真正的元素
    ElemType elem;
    elem = *(s->top);
    cout<<"popStack Elem is : "<<elem<<endl;

}

//获取栈顶元素
bool GetTop(orderStack *s) {
    if (s->top == s->base) {
        cout<<"error, stack is null"<<endl;
        return false;
    }
    ElemType  elem = *(s->top - 1);
    cout<<"stack top elem is: "<<elem<<endl;
    return true;
}

//遍历栈
void PrintStack(orderStack *s) {
    for (auto i = s->base; i < s->top; i++) {
        cout<<*i<<" ";
    }
    cout<<endl;
}

int main() {
    orderStack stack;
    InitStack(&stack);
    Push(&stack, 1);
    Push(&stack, 2);
    Push(&stack, 3);
    PrintStack(&stack);

    Pop(&stack);
    PrintStack(&stack);

    GetTop(&stack);

    system("pause");
    return 0;
}
