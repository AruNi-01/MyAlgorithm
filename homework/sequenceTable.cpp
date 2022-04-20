/*
 * @Descripttion: 顺序表的实现
 * @Author: AruNi
 * @Date: 2022-03-20 12:24:02
 */
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

typedef int ElemType;       //存储的数据类型抽象为int(也可是其他)
struct sequenceTable
{
    ElemType *list;
    int length;
    int MaxSize;
};

//初始化
void InitTable(struct sequenceTable *L, int maxSize) {
    if (maxSize < 0) {
        cout<<"初始化长度须大于0"<<endl;
        exit(0);
    }
    L->MaxSize = maxSize;
    L->list = new ElemType[maxSize];
    L->length = 0;
}

//清空顺序表
void ClearTable(struct sequenceTable *L) {
    if (L->list != NULL) {
        delete[] L->list;
        L->list = 0;
        L->length = 0;
        L->MaxSize = 0;
    }
}

//判断顺序表是否为空
bool IsEmpty(struct sequenceTable *L) {
    return L->length == 0? true: false;
}

//顺序表扩容
void AddCapacity(struct sequenceTable *L) {
    ElemType *p = new ElemType[(L->MaxSize) * 2];   //扩大为原来的2倍
    L->list = p;
    L->MaxSize = 2 * L->MaxSize;
    cout<<"储存空间成功扩大2倍"<<endl;
}

//向表头插入元素
void InsertToHead(struct sequenceTable *L, ElemType e) {
    //判断储存空间是否已满
    if(L->length == L->MaxSize) {
        cout<<"储存空间已满，扩容中···"<<endl;
        AddCapacity(L);
    }

    //先将所有元素往后移
    for (int i = L->length - 1; i >= 0; i--) {
        L->list[i + 1] = L->list[i];
    }
    L->list[0] = e;
    L->length++;
}

//向表尾插入元素
void InsertToTail(struct sequenceTable *L, ElemType e) {
    //判断储存空间是否已满
    if(L->length == L->MaxSize) {
        cout<<"储存空间已满，扩容中···"<<endl;
        AddCapacity(L);
    }

    L->list[L->length++] = e;
}

//向第n个位置插入元素
void InsertByIndex(struct sequenceTable *L, ElemType e, int n) {
    //判断储存空间是否已满
    if(L->length == L->MaxSize) {
        cout<<"储存空间已满，扩容中···"<<endl;
        AddCapacity(L);
    }

    //遍历到要插入的位置
    for (int i = L->length - 1; i >= n - 1; i--) {
        L->list[i + 1] = L->list[i];        //将i位置后的所有元素往后移
    }
    L->list[n - 1] = e;
    L->length++;
}

//删除表头元素，返回被删除的值
ElemType DeleteHead(struct sequenceTable *L) {
    if (L->length == 0) {
        cout<<"线性表为空，无法删除"<<endl;
        exit(0);
    }
    //先记录需要删除的元素，方便最后返回
    ElemType e = L->list[0];
    for(int i = 0; i < L->length; i++) {
        L->list[i] = L->list[i + 1];
    }
    L->length--;
    return e;
}

//删除表尾元素，返回被删除的值
ElemType DeleteTail(struct sequenceTable *L) {
    if (L->length == 0) {
        cout<<"线性表为空，无法删除"<<endl;
        exit(0);
    }
    ElemType e = L->list[L->length - 1];
    for (int i = 0; i < L->length - 1; i++) {
        L->list[i] = L->list[i];
    }
    L->length--;
    return e;
}

//删除第n个元素，返回被删除的值
ElemType DeleteByIndex(struct sequenceTable *L, int n) {
    if (n < 1 || n > L->length) {           //输入的位置不合法报异常
		cout << "输入的下标不合法" << endl;
        exit(0);
    }
    ElemType e = L->list[n - 1];
    for (int i = n - 1; i < L->length; i++) {      //从n位置开始，将后面的元素往前移
        L->list[i] = L->list[i + 1];
    }
    L->length--;
    return e;
}

//删除值为e的第一个元素，返回其下标(从1开始)
int DeleteByValue(struct sequenceTable *L, ElemType e) {
    int indexOfValue;
    //先找出值为e的下标
    for (indexOfValue = 0; indexOfValue < L->length; indexOfValue++) {
        if (L->list[indexOfValue] == e) break;
    }
    //再将该位置后的元素向前移
    for (int index = indexOfValue; index < L->length; index++) {
        L->list[index] = L->list[index + 1];
    }
    L->length--;
    return ++indexOfValue;
}

//将第n个元素的值修改为e，修改成功返回1；否则返回0
int UpdateElemByIndex(struct sequenceTable *L, ElemType e, int n) {
    if (n < 1 || n > L->length) {
        return 0;
    }
    L->list[n - 1] = e;
    return 1;
}

//查找第n个位置的值
int GetElemByIndex(struct sequenceTable *L, int n) {
    if (n < 0 || n > L->MaxSize) {
        cout<<"查找的位置不合法"<<endl;
        exit(0);
    }
    return L->list[n - 1];
}

//查找值为e的元素并返回其下标(找不到返回-1)
int GetIndexByElem(struct sequenceTable *L, ElemType e) {
    for (int i = 0; i < L->length; i++) {
        if (L->list[i] == e) {
            return ++i;
        }
    }
    return -1;
}

//遍历顺序表
void PrintTable(struct sequenceTable *L) {
    for (int i = 0; i < L->length; i++) {
        cout<<L->list[i]<<"\t";
    }
    cout<<endl;
}



int main() {
    struct sequenceTable table;
    //初始化
    InitTable(&table, 10);

    //插入操作：
    InsertToHead(&table, 1);
    InsertByIndex(&table, 3, 2);
    InsertToTail(&table, 5);
    PrintTable(&table);


    //删除操作：
    // DeleteHead(&table);

    // ElemType e = DeleteByIndex(&table, 1);
    // cout<<"Deleted Elem: "<<e<<endl;

    // int index = DeleteByValue(&table, 5);
    // cout<<"Deleted Index: "<<index<<endl;
    // DeleteTail(&table);
    // PrintTable(&table);

    //修改操作：
    // UpdateElemByIndex(&table, 2, 2);
    // PrintTable(&table);

    //查找操作：
    cout<<GetElemByIndex(&table, 2)<<endl;
    cout<<GetIndexByElem(&table, 5)<<endl;

    system("pause");
    return 0;
}