/*
 * @Descripttion: 707. 设计链表
 * @Author: AruNi
 * @Date: 2022-03-27 22:24:50
 */

/*
题目：
设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 
是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。

在链表类中实现这些功能：
    get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
    addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
    addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
    addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加
                           到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
    deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。

示例：
MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
linkedList.get(1);            //返回2
linkedList.deleteAtIndex(1);  //现在链表是1-> 3
linkedList.get(1);            //返回3
*/

class MyLinkedList {
public:

    //定义链表
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode (int val): val(val), next(nullptr) {}
    };

    //构造函数，初始化链表
    MyLinkedList() {
        _dummyHead = new LinkedNode(0);     //虚拟头结点，不存放数据
        _size = 0;
    }
    
    //获取第index个节点位置的值；index从0开始，第0个结点就是头结点
    int get(int index) {
        if (index < 0 || index > (_size - 1)) return -1;
        LinkedNode* cur = _dummyHead->next;
        
        while(index--) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    //头插法
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;   //新结点的next指向头结点的next
        _dummyHead->next = newNode;     //头结点的next指向新结点，_dummyHead依旧是头结点
        _size++;
    }
    
    //尾插法
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }
    
    //在第index个位置的节点之前插入一个新节点
    void addAtIndex(int index, int val) {
        //当index大于链表长度，直接返回空
        if (index > _size) return;
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        //此时cur的位置刚好在index前一个，因为_dummyHead为虚拟节点
        newNode->next = cur->next;      //新节点的next指向cur的next(index位置的节点)
        cur->next = newNode;        //index位置的前一个结点指向新节点
        _size++;
    }
    
    //删除第index个位置的节点
    void deleteAtIndex(int index) {
        if (index < 0 || index > (_size - 1)) return;
        LinkedNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }

        //此时cur的位置在index前一个，因为_dummyHead为虚拟节点
        LinkedNode* temp = cur->next;       //temp指向要删除的结点
        cur->next = cur->next->next;        //将index位置的前一个结点的next指向index位置的下一个结点，就删除了index位置的结点
        delete temp;
        _size--;
    }

private:
    int _size;
    LinkedNode* _dummyHead;

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */