/*
 * @Descripttion: 双链表的实现
 * @Author: AruNi
 * @Date: 2022-03-20 17:37:13
 */
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

struct node
{
	int date;
	node* prev;
	node* next;
};

class doublelinks
{
public:
	doublelinks();
	~doublelinks();
public:
	int doublelink_insert(doublelinks* ptr, int position, int member);  //插入
	int doublelink_erase(doublelinks* ptr, int position);               //删除
	void doublelink_display(doublelinks* ptr, int num);                 //显示
	int doublelink_getlength(doublelinks* ptr);                         //得到长度
private:
	int length;
	node* root;
};


doublelinks::doublelinks()
{
	root = new node;
	root->prev = NULL;
	root->next = NULL;
	length = 0;
}
 
doublelinks::~doublelinks()
{
}

//插入
int doublelinks::doublelink_insert(doublelinks *ptr, int position, int member)
{
	node* nodeinsert = new node;
	nodeinsert->date = member;
	if (ptr->doublelink_getlength(ptr) == 0)
	{
		root->next = nodeinsert;
		nodeinsert->prev = nodeinsert;
		nodeinsert->next = nodeinsert;
		ptr->length++;
		return 0;
	}
	else
	{
		if (position == 0)
		{
			nodeinsert->prev = root->next->prev;
			nodeinsert->next = root->next;
			root->next->prev->next = nodeinsert;
			root->next->prev = nodeinsert;
			root->next = nodeinsert;
			ptr->length++;
			return 0;
		}
		else
		{
			node* current = root->next;
			for (int i = 0; i < position; i++)
			{
				current = current->next;
			}
			nodeinsert->next = current;
			nodeinsert->prev = current->prev;
			current->prev->next = nodeinsert;
			current->prev = nodeinsert;
			ptr->length++;
			return 0;
		}
	}
}


//删除
int doublelinks::doublelink_erase(doublelinks* ptr, int position) 
{
	if (ptr->doublelink_getlength(ptr) == 0)
	{
		cout << "LinkedList is Empty" << endl;
		return 0;
	}
	else
	{
		if (ptr->doublelink_getlength(ptr) == 1)
		{
			ptr->root->next = NULL;
			ptr->length--;
		}
		else
		{
			node* deletenode = root->next;
			for (int i = 0; i < position; i++)
			{
				deletenode = deletenode->next;
			}
			deletenode->prev->next = deletenode->next;
			deletenode->next->prev = deletenode->prev;
			delete deletenode;
			ptr->length--;
		}
	}
}

//获取长度
int doublelinks::doublelink_getlength(doublelinks* ptr)
{
	return ptr->length;
}

//根据传入的长度显示链表
void doublelinks::doublelink_display(doublelinks* ptr, int num)
{
	node* current = root->next;
	for (int i = 0; i < num; i++)
	{
		cout << current->date << " ";
		current = current->next;
	}
	cout << endl;
}

int main()
{
	doublelinks* doublelink_ptr = new doublelinks;
	for (int i = 0; i < 10; i++)
	{
		doublelink_ptr->doublelink_insert(doublelink_ptr, 0, i);
	}

    //循环输出链表
	doublelink_ptr->doublelink_display(doublelink_ptr, 20);

    //删除2位置的结点(从0开始)
	doublelink_ptr->doublelink_erase(doublelink_ptr, 2);

	doublelink_ptr->doublelink_display(doublelink_ptr, 20);

    system("pause");
	return 0;
}