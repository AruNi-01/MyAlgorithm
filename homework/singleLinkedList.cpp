/*
 * @Descripttion: 单链表的实现
 * @Author: AruNi
 * @Date: 2022-03-20 17:04:25
 */
#include<iostream>
using namespace std;
struct Linked
{
    //结构体的成员变量
    int data;
    Linked* next;
};

Linked* Create()
{
    //创建并返回一个新链表
     Linked *newNode=new Linked;
     newNode->next = NULL;
     return newNode;
}

void InsertAfter(Linked* node, int data)
{
    //在指定节点后插入一个新节点，内容由 data参数指定
    Linked* p1 = node;       		//p1指向头表头
    Linked* p2 = Create();		    //p2指向新建结点
    p2->data = data;
    p1->next = p2;
    p2->next = NULL;
}

void DeleteAfter(Linked* node)
{
    //删除此节点之后的一个节点
    Linked* p1 = node;           //p1为要删除节点的前一个节点
    Linked* p2 = node->next;     //p2为要删除的节点
    p1->next = p2->next;
    delete p2;
}

Linked* GetByIndex(Linked* head, int index)
{
    //返回指定索引处的节点
    Linked* p1 = head->next; 
    int i = 0;
    while (i != index)
    {
        p1 = p1->next;
        i++;
    }
    return p1;
}

void PrintAll(Linked* head)
{
    //按格式打印此链表中所有节点的成员变量
    Linked* p = head->next;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}
int main()
{

    //创建链表
	Linked* lk = Create();
    //插入结点
	InsertAfter(lk, 1);
    //GetByIndex(lk, 0)返回的是第1个位置的结点
	InsertAfter(GetByIndex(lk, 0), 3);
	InsertAfter(GetByIndex(lk, 1), 5);
    PrintAll(lk);

    cout<<endl;
    //删除结点
	DeleteAfter(GetByIndex(lk, 0));     //删除第1个位置的结点(值为3)
	PrintAll(lk);

    system("pause");
	return 0;
}